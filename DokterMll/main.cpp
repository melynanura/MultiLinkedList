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
    int kodeObat, antri;
    string tampil,hapus;
    string namaPasien, merekObat;
    
    createObatList(LObat);
    createDocList(LDokterPasien);
    //data bawaan Dokter Pasien
    dataDokterPasien.namaDokter = "Dr. Rahmat Irianto";
    dataDokterPasien.spesialis = "Kulit dan Kelamin";
    dataDokterPasien.namaPasien = "Kurniadi";
    dataDokterPasien.noAntrian = 1;
    dataDokterPasien.tarif = 50000;
    adrD = newElementDoc(dataDokterPasien);
    addToLastD(LDokterPasien, adrD);

    dataDokterPasien.namaDokter = "Dr. Riana Putri";
    dataDokterPasien.spesialis = "Kandungan";
    dataDokterPasien.namaPasien = "Syarifah";
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
    
    pilihan = selectMenu();

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
            case 2:{
                i=1;
                cout<<"input jumlah data obat: ";
                cin>> number;
                cout<<endl;

                while(i<=number){
                    cout<<"Data Obat ke-"<<i<<endl;
                    addMainObat(dataObat);
                    adrO = newElementObat(dataObat);
                    addToLastO(LObat, adrO);
                    i++;
                }
                break;
            }
            case 3:{
                i=1;
                cout<<"Input jumlah data resep: ";
                cin>> number;
                cout<<endl;
                while(i<=number){
                    cout<<"Data Resep ke-"<<i<<endl;
                    addResep(namaPasien, antri, merekObat, kodeObat);
                    adrD = findElmDoc(LDokterPasien, antri);
                    adrO = findElmObat(LObat, kodeObat);
                    adrR = newElemenRelasi(adrO);
                    addToLastR(child(adrD),adrR );
                    i++;
                }
                break;
            }
            case 4:{
                cout<<"Menghapus Data pada:"<<endl;
                cout<<"a. Hapus Data Dokter Pasien"<<endl;
                cout<<"b. Hapus Data Obat pada Pasien Tertentu"<<endl;
                cout<<"Masukan Pilihan: ";
                cin>>hapus;
                cout<<endl;
                if (hapus == "a" || hapus == "A"){
                    cout<<"Masukkan data dokter pasien yang ingin dihapus : "<<endl;
                    cout<<"Nama Pasien: ";
                    cin>>namaPasien;
                    cout<<"Nomor Antrian : ";
                    cin>>antri;
                    deleteDokerPasien(LDokterPasien, antri);
                }else if(hapus == "b" || hapus == "B"){
                    cout<<"Masukkan data obat yang ingin dihapus pada pasien tertentu"<<endl;
                    cout<<"Nama Pasien: ";
                    cin>>namaPasien;
                    cout<<"Nomor Antrian: ";
                    cin>>antri;
                    cout<<"Merk Obat: ";
                    cin>>merekObat;
                    cout<<"Kode Obat : ";
                    cin>>kodeObat;
                    deleteObat(LDokterPasien, LObat, antri, kodeObat);
                }
                break;
            }
            case 5:{
                cout<<"Tampilkan Data Pada: "<<endl;
                cout<<"a. Menampilkan Data Pasien Dokter dengan obatnya"<<endl;
                cout<<"b. Menampilkan Data Obat"<<endl;
                cout<<"c. Menampilkan Data Dokter Pasien"<<endl;
                cout<<"d. Menampilkan Daftar Pembelian Obat"<<endl<<endl;
                cout<<"Masukan Pilihan: ";
                cin>>tampil;
                cout<<endl;

                if(tampil == "a" || tampil == "A"){
                    ShowAllData(LDokterPasien);
                }else if (tampil == "b" || tampil == "B"){
                    showObat(LObat);
                }else if (tampil == "c" || tampil == "C"){
                    showDoc(LDokterPasien);
                }else if(tampil == "d" || tampil == "D"){
                    showInfoObat(LObat);
                    cout<<endl;
                    cout<<"Masukan Merk Obat: ";
                    cin>>merekObat;
                    cout<<"Masukan Kode Obat: ";
                    cin>>kodeObat;
                    showObatPasien(LDokterPasien, LObat, kodeObat);
                }
                break;
            }
            case 6:{
                
                    bestSellingMedicine(LDokterPasien, LObat);
                
                break;
            }
            case 7:{
                
                    leastSellingMedicine(LDokterPasien, LObat);
                break;
            }
            case 8:{
                cout<<"Masukan Nama Pasien: ";
                cin>>namaPasien;
                cout<<"Masukan Nomor Antrian: ";
                cin>>antri;
                cout<<"Terdapat "<<countObat(LDokterPasien, antri)<<" jenis obat yang dibeli pasien "<<namaPasien<<endl;
                break;
            }
            case 9:{
                adrD = nil;
                adrO = nil;
                cout<<"Tampilkan pencarian pada: "<<endl;
                cout<<"a. Dokter Pasien"<<endl;
                cout<<"b. Obat "<<endl;
                cout<<"Masukan Pilihan: ";
                cin>>tampil;
                cout<<endl;
                if (tampil == "a" || tampil == "A"){
                    cout<<"Masukan Nama Pasien: ";
                    cin>>namaPasien;
                    cout<<"Masukan Nomor Antrian: ";
                    cin>>antri;
                    adrD = findElmDoc(LDokterPasien, antri);
                }else if (tampil == "b" || tampil == "B"){
                    cout<<"Masukan Merk Obat: ";
                    cin>> merekObat;
                    cout<<"Masukan Kode Obat: ";
                    cin>>kodeObat;
                    adrO = findElmObat(LObat, kodeObat);
                }
                if (adrD!=nil){
                    cout<<endl<<"--- Data Ditemukan ---"<<endl<<endl;
                    cout<< "Nama Dokter: "<<info(adrD).namaDokter<<endl;
                    cout<< "Spesialis: "<<info(adrD).spesialis<<endl;
                    cout<< "Nama Pasien: "<<info(adrD).namaPasien<<endl;
                    cout<< "Nomor Antrian: "<<info(adrD).noAntrian<<endl;
                    cout<< "Tarif: "<<info(adrD).tarif<<endl;
                }else if (adrO!=nil){
                    cout<<endl<<"--- Data Ditemukan ---"<<endl<<endl;
                    cout<< "Merk Obat: "<<info(adrO).merk<<endl;
                    cout<< "Kategori: "<<info(adrO).kategori<<endl;
                    cout<< "Kode Obat: "<<info(adrO).kode<<endl;
                }else{
                    cout<<"Data Tidak Ditemukan"<<endl;
                }
                break;
            }

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
