//
//  DokterPasien.cpp
//  DokterMll
//
//  Created by Melyna Nura on 09/06/23.
//

#include "DokterPasien.hpp"

//DokterPasien
void createDocList(listDokterPasien &L){
    first(L) = nil;
}
adrDokter newElementDoc(infoDokter data){
    adrDokter D = new elementDokter;
        info(D) = data;
        next(D) = nil;
        createRelasi(child(D));

        return D;
}
void addToLastD(listDokterPasien &L, adrDokter T){
    if(first(L)==nil){
            first(L) = T;
        }else{
            adrDokter Q;
            Q = first(L);
            while(next(Q)!=nil){
                Q = next(Q);
            }
            next(Q) = T;
        }
}
void showDoc(listDokterPasien L){
    adrDokter C;
        C = first(L);
        infoDokter data;

        if(C==nil){
            cout<<"Tidak Ada Data"<<endl;
        }else{
            cout<<endl;
            int i = 1;
            cout<<"--- Data Dokter Pasien ----"<<endl;
            while(C!=nil){
                cout<<endl;
                cout<<"Data kota ke-"<<i<<endl;
                data = info(C);
                cout<< "Nama Dokter: "<<data.namaDokter<<endl;
                cout<< "Spesialis: "<<data.spesialis<<endl;
                cout<< "Nama Pasien: "<<data.namaPasien<<endl;
                C = next(C);
                i++;
            }
        }
}
adrRelasi findElmChild (listRelasi L, adrObat rel){
    adrRelasi pRel;
            pRel = first(L);
            while (pRel!=nil) {
                if(info(pRel)== rel){
                    return pRel;
                    break;
                }
                pRel=next(pRel);
            }
            return  nil;
}

adrDokter findElmDoc (listDokterPasien L, double antri){
    adrDokter pDokter;
       pDokter = first(L);
       while (pDokter!=nil) {
           if(info(pDokter).noAntrian == antri){
               return pDokter;
               break;
           }
           pDokter=next(pDokter);
       }
       return  nil;
};

int cekElementFirst(listDokterPasien LD){
    int i =0;
        adrRelasi Prel = first(child(first(LD)));
        while(Prel!=nil){
            i++;
            Prel = next(Prel);
        }
        return i;
};

infoDokter addMainDoc(infoDokter &dataDokter){
    /*{untuk memudahkan saat melakukan inputan di main program dan mengembalikan nya }*/
    cout<<"Nama Dokter: ";
    cin>>dataDokter.namaDokter;
    cout<<"Spesailis: ";
    cin>>dataDokter.spesialis;
    cout<<"No Antrian: ";
    cin>>dataDokter.noAntrian;
    cout<<"Harga Tarif: ";
    cin>>dataDokter.tarif;
    cout<<"Nama pasien: ";
    cin>>dataDokter.namaPasien;
    cout<<endl;

    return dataDokter;
};

//Relasi
void createRelasi(listRelasi &L){
    first(L) = nil;
};

adrRelasi newElemenRelasi(adrObat data){
    /*{Membuat element relasi baru yang berisi address turis sesuai parameter}*/
       adrRelasi R = new elementRelasi;
       info(R) = data;
       next(R) = nil;

       return R;
};

void addToLastR(listRelasi &L, adrRelasi R){
    /*{IS. Terdefinisi sebuah List Relasi(L)kosong dan pointer R berisi alamat elementRelasi
           FS. R ditambakan di list sebagai elemen terakhir }*/
        if(first(L)==nil){
            first(L) = R;
        }else{
            adrRelasi Q;
            Q = first(L);
            while(next(Q)!=nil){
                Q = next(Q);
            }
            next(Q) = R;
        }
};


//fitur
int countObat(listDokterPasien L, string namaPasien);
void ShowAllData(listDokterPasien Ldoc);
void FindMaxData(listDokterPasien Ldoc);
void FindMinData(listDokterPasien Ldoc);
void addResep(string &namaDokter,int &namaPasien, string &merkObat, int &kodeObat);
void showObatPasien(listDokterPasien Ldoc, listObat LObat, int kode);
void patientWithMostMedicine(listDokterPasien Ldoc, listObat LObat);
void patientWithLeastMedicine(listDokterPasien Ldoc, listObat LTour);
void deleteObat(listDokterPasien &Ldoc, listObat &LObat, string namaPasien, int kodeObat);
void deleteDokerPasien(listDokterPasien &L,string namaPasien);
