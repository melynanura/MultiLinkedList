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
    last(L) = nil;
}
adrDokter newElementDoc(infoDokter data){
    adrDokter D = new elementDokter;
        info(D) = data;
        next(D) = nil;
        prev(D) = nil;
        createRelasi(child(D));

        return D;
}
void addToLastD(listDokterPasien &L, adrDokter T){
    if(first(L)==nil){
            first(L) = T;
            last(L) = T;
        }else{
            prev(T)=last(L);
            last(L)= T;
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
            while (next(pRel)!=first(L)) {
                if(info(pRel)== rel){
                    return pRel;
                    break;
                }
                pRel=next(pRel);
            }
            return  nil;
}

adrDokter findElmDoc (listDokterPasien L, int antri){
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
       adrRelasi R = new elementRelasi;
       info(R) = data;
       next(R) = nil;

       return R;
};

void addToLastR(listRelasi &L, adrRelasi R){
        if(first(L)==nil){
            first(L) = R;
            next(first(L))=first(L);
        }else{
            adrRelasi Q;
            Q = first(L);
            while(next(Q)!=nil){
                Q = next(Q);
            }
            next(Q) = R;
            next(R) = first(L);
        }
};


//fitur
int countObat(listDokterPasien L, int antri){
    adrDokter Pdoc;

        Pdoc = findElmDoc(L, antri);
        listRelasi lr = child(Pdoc);

        adrRelasi pRel;
        int countObat = 0;
        pRel = first(lr);
        while(pRel!=nil){
            countObat++;
            pRel=next(pRel);
        }
        return countObat;
}
void ShowAllData(listDokterPasien Ldoc){
    adrDokter pDoc = first(Ldoc);

        if (pDoc==nil){
            cout<<"Tidak Ada Data"<<endl;
        }else{
            while(pDoc!=nil){
                cout<<endl;
                cout<<"---------- Obat Pasien "<<info(pDoc).namaPasien<<" ----------"<<endl;
                cout<<"Dokter: "<<info(pDoc).namaDokter<<endl;
                cout<<"Spesialis: "<<info(pDoc).spesialis<<endl;
                cout<<"Antrian: "<<info(pDoc).noAntrian<<endl;
                cout<<"Tarif: "<<info(pDoc).tarif<<endl;
                adrRelasi pObat = first(child(pDoc));
                if (pObat!=nil){
                    cout<<"Belum Ada Pengunjung"<<endl<<endl;
                }
                int j = 1;
                while(pTour!=nil){
                    cout<<endl<<"--- Turis "<<j<<" ---"<<endl;
                    cout<<"Nama: "<<info(info(pTour)).name<<endl;
                    cout<<"Kode: "<<info(info(pTour)).kode<<endl;
                    cout<<"Status: "<<info(info(pTour)).status<<endl;
                    cout<<"Gender: "<<info(info(pTour)).gender<<endl;
                    pTour = next(pTour);
                    j++;
                }
                pCity = next(pCity);
            }
        }
}
void FindMaxData(listDokterPasien Ldoc);
void FindMinData(listDokterPasien Ldoc);
void addResep(string &namaDokter,int &namaPasien, string &merkObat, int &kodeObat);
void showObatPasien(listDokterPasien Ldoc, listObat LObat, int kode);
void patientWithMostMedicine(listDokterPasien Ldoc, listObat LObat);
void patientWithLeastMedicine(listDokterPasien Ldoc, listObat LTour);
void deleteObat(listDokterPasien &Ldoc, listObat &LObat, string namaPasien, int kodeObat);
void deleteDokerPasien(listDokterPasien &L,string namaPasien);
