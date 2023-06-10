//
//  main.cpp
//  DokterMll
//
//  Created by Melyna Nura on 09/06/23.
//

#include <iostream>
#include "DokterPasien.hpp"
#include "Obat.hpp"

int main() {
    listDokterPasien LDokterPasien;
    listObat LObat;

    adrDokter adrD;
    adrObat adrO;
    adrRelasi adrR;

    infoDokter dataDokterPasien;
    infoObat dataObat;
    int number;
    int i;
    char kembali;

    int pilihan;
//    int kodeC,kodeT;
//    string tampil,hapus;
//    string namaKota, namaTourist;
    
    createObatList(LObat);
    createDocList(LDokterPasien);
    //data bawaan Dokter Pasien
    dataDokterPasien.namaDokter = "Dr. Rahmat Irianto";
    dataDokterPasien.spesialis = "Kulit dan Kelamin";
    dataDokterPasien.noAntrian = 1;
    dataDokterPasien.tarif = 50000;
    adrD = newElementDoc(dataDokterPasien);
    addToLastD(LDokterPasien, adrD);

    dataDokterPasien.namaDokter = "Dr. Riana Putri";
    dataDokterPasien.spesialis = "Kandungan";
    dataDokterPasien.noAntrian = 2;
    dataDokterPasien.tarif = 100000;
    adrD = newElementDoc(dataDokterPasien);
    addToLastD(LDokterPasien, adrD);
    
    //data bawaan obat
    dataObat.merk = "Miconazole";
    dataObat.kategori = "salep";
    dataObat.kode = 001;
    adrO = newElementObat(dataObat);
    addToLastO(LObat, adrO);
    
    dataObat.merk = "Biocalci-72";
    dataObat.kategori = "obat resep";
    dataObat.kode = 002;
    adrO = newElementObat(dataObat);
    addToLastO(LObat, adrO);
    
    //data relasi
    adrD = findElmDoc(LDokterPasien, 1);
    adrO = findElmObat(LObat, 001);
    adrR = newElemenRelasi(adrO);
    addToLastR(child(adrD),adrR);
    
    adrD = findElmDoc(LDokterPasien, 2);
    adrO = findElmObat(LObat, 002);
    adrR = newElemenRelasi(adrO);
    addToLastR(child(adrD),adrR);
    
    cout<<"pilihan : ";
    cin>>pilihan;

    while (pilihan != 0){
        switch (pilihan){
            case 1:{
                i =1;
                cout<<"Input jumlah data dokter dan pasien: ";
                cin>> number;
                cout<<endl;

                while(i<=number){
                    cout<<"Input jumlah data dokter dan pasien:-"<<i<<endl;
                    addMainDoc(dataDokterPasien);
                    adrD = newElementDoc(dataDokterPasien);
                    addToLastD(LDokterPasien, adrD);
                    i++;
                }
                break;
            }
//            case 2:{
//
//                }
//                break;
//            }
//            case 3:{
//
//                }
//                break;
//            }
//            case 4:{
//
//                }
//                break;
//            }
//            case 5:{
//
//                }
//                break;
//            }
//            case 6:{
//
//                break;
//            }
//            case 7:{
//
//                break;
//            }
//            case 8:{
//
//                break;
//            }
//            case 9:{
//
//                break;
//            }
            default:{
                cout<<"Masukan berupa angka 0-9"<<endl;
                break;
            }
            }
            cout << endl<< "Kembali ke menu utama? (Y/N): ";
            cin >> kembali;

            if (kembali == 'Y' || kembali == 'y'){
                cout << endl;
                pilihan = selectMenu();
            }
            else if (kembali == 'N' || kembali == 'n'){
                pilihan = 0;
            }
            else{
                cout << endl<< "Kembali ke menu utama? (Y/N): ";
                cin >> kembali;
            }
        }
        cout << endl<< "ANDA TELAH KELUAR DARI PROGRAM"<<endl;
                    
    return 0;
}
