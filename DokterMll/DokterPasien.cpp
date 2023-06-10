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
            next(R)=first(L);
        }else{
            adrRelasi Q;
            Q = first(L);
            while(next(Q)!=first(L)){
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
                while(next(pObat)!=first(child(pDoc))){
                    cout<<endl<<"--- Obat "<<j<<" ---"<<endl;
                    cout<<"Merk: "<<info(info(pObat)).merk<<endl;
                    cout<<"Kategori: "<<info(info(pObat)).kategori<<endl;
                    cout<<"Kode: "<<info(info(pObat)).kode<<endl;
                    pObat = next(pObat);
                    j++;
                }
                pDoc = next(pDoc);
            }
        }
}
void FindMaxData(listDokterPasien Ldoc){
    adrDokter pDoc = first(Ldoc);
        adrDokter vMax=nil;
        string dupvMax="";
        int maxVal = 0;
        int i;

        while(pDoc!=nil){
            i=0;
            adrRelasi pObat = first(child(pDoc));
            while(next(pObat)!=first(child(pDoc))){
                i++;
                pObat = next(pObat);
            }
            if (maxVal<i){
                maxVal = i;
                vMax = pDoc;
            }else if (maxVal==i){
                dupvMax = dupvMax +", "+ info(pDoc).namaPasien;
            }
            pDoc = next(pDoc);
        }
            cout<<"Pasien dengan jumlah obat terbanyak adalah "<<info(vMax).namaPasien<<dupvMax<<endl<<"dengan jumlah obat sebanyak "<<maxVal<<" buah"<<endl;
}
void FindMinData(listDokterPasien Ldoc){
    adrDokter pDoc = first(Ldoc);
        adrDokter vMin=nil;
        string dupvMin="";
        int minVal = 0;
        int i;

        while(pDoc!=nil){
            i=0;
            adrRelasi pObat = first(child(pDoc));
            while(next(pObat)!=first(child(pDoc))){
                i++;
                pObat = next(pObat);
            }
            if (minVal>i){
                minVal = i;
                vMin = pDoc;
            }else if (minVal==i){
                dupvMin = dupvMin +", "+ info(pDoc).namaPasien;
            }
            pDoc = next(pDoc);
        }
            cout<<"Pasien dengan jumlah obat paling sedikit adalah "<<info(vMin).namaPasien<<dupvMin<<endl<<"dengan jumlah obat sebanyak "<<minVal<<" buah"<<endl;
}
void addResep(string &namaDokter,int &namaPasien, string &merkObat, int &kodeObat){
    cout<<"Nama Dokter: ";
    cin>>namaDokter;
    cout<<"Nama Pasien: ";
    cin>>namaPasien;
    cout<<"Merk Obat: ";
    cin>>merkObat;
    cout<<"Kode Obat: ";
    cin>>kodeObat;
    cout<<endl;
}
void showObatPasien(listDokterPasien Ldoc, listObat LObat, int antri){
    adrObat cekObat = findElmObat(LObat, antri);
    adrDokter pDokter = first(Ldoc);
    adrRelasi cekRel = nil;
    cout<<endl<<"--- Daftar Obat Pasien "<<info(cekObat).merk<<" ---"<<endl;
    while(pDokter!=nil){
         cekRel = findElmChild(child(pDokter), cekObat);
         if (cekRel!=nil){
             cout<<info(pDokter).namaPasien<<endl;
         }
         pDokter = next(pDokter);
     }
}
void patientWithMostMedicine(listDokterPasien Ldoc, listObat LObat){
    adrDokter pDokter;
    adrRelasi pRel;
    adrDokter pKeep = nil;
    adrObat pObat = first(LObat);
    string dupmax = "";
    int maxVal = 0;
    int num;

    while(pObat!=nil){
       num = 0;
       pDokter = first(Ldoc);
       while (pDokter!=nil) {
           pRel = findElmChild(child(pDokter), pObat);
           if(pRel!=nil){
               num++;
           }
           pDokter = next(pDokter);
       }
       if(maxVal < num){
           maxVal = num;
           pKeep = pDokter;
       }else if (maxVal==num){
           dupmax = dupmax +", "+ info(pDokter).namaPasien;
       }
       pObat = next(pObat);
   }
   cout<<"Pasien yang paling banyak mebeli obat adalah "<<info(pKeep).namaPasien<<"sebanyak "<<maxVal<<endl;
};
void patientWithLeastMedicine(listDokterPasien Ldoc, listObat LObat){
    adrDokter pDokter;
    adrRelasi pRel;
    adrDokter pKeep = nil;
    adrObat pObat = first(LObat);
    string dupmin = "";
    int minVal = 0;
    int num;

    while(pObat!=nil){
       num = 0;
       pDokter = first(Ldoc);
       while (pDokter!=nil) {
           pRel = findElmChild(child(pDokter), pObat);
           if(pRel!=nil){
               num++;
           }
           pDokter = next(pDokter);
       }
       if(minVal > num){
           minVal = num;
           pKeep = pDokter;
       }else if (minVal==num){
           dupmin = dupmin +", "+ info(pDokter).namaPasien;
       }
       pObat = next(pObat);
   }
   cout<<"Pasien yang paling sedikit mebeli obat adalah "<<info(pKeep).namaPasien<<"sebanyak "<<minVal<<endl;
}
void deleteObat(listDokterPasien &Ldoc, listObat &LObat, int antri, int kodeObat){
    adrDokter delDoc = findElmDoc(Ldoc, antri);
    adrObat delObat = findElmObat(LObat, kodeObat);
    adrRelasi delRel = findElmChild(child(delDoc),delObat);
    adrRelasi pDel= first(child(delDoc));

    if(delRel == pDel){
        first(child(delDoc))=next(delRel);
        next(delRel)=nil;
    }else if (delRel != pDel && delRel != nil){
        while (next(pDel)!=delRel) {
            pDel = next(pDel);
        }
        next(pDel) = next(delRel);
        next(delRel) = nil;
    }
    cout<<"Data Berhasil di hapus"<<endl;
}
void deleteDokerPasien(listDokterPasien &L,int antri){
    adrDokter P = findElmDoc(L, antri);
    adrDokter prec = first(L);

    if (P==first(L)){
        first(L)=next(P);
        next(P)=nil;
    }else{
        while (next(prec)!=P){
            prec = next(prec);
        }
        next(prec)=next(P);
        next(P)=nil;
    }
    cout<<"Data berhasil dihapus"<<endl;
}

int selectMenu(){
    /*{menampilkan daftar fitur yang tersedia pada program}*/
        cout << "-------- APLIKASI DATA KOTA WISATA JAWA BARAT --------" << endl<<endl;
        cout << "1.  Menambah data dokter pasien" << endl;
        cout << "2.  Menambah data obat" << endl;
        cout << "3.  Menambah data perjalan" << endl;
        cout << "4.  Menghapus data" << endl;
        cout << "5.  Menampilkan data" << endl;
        cout << "6.  Menampilkan data paling banyak" << endl;
        cout << "7.  Menampilkan data paling sedikit" << endl;
        cout << "8.  Menampilkan jumlah turis yang mengunjungi suatu kota wisata" << endl;
        cout << "9.  Mencari data turis atau kota" << endl;
        cout << "10. Bantuan" << endl;
        cout << "0.  Exit" << endl<<endl;
        cout <<"Masukan berupa angka 0-10"<<endl;
        cout << "----------------------"<<endl;
        cout << "Masukkan pilihan: ";
        int input = 0;
        cin >> input;
        return input;
};
