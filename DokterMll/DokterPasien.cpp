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
            next(last(L))=T;
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
                cout<<"Data ke-"<<i<<endl;
                data = info(C);
                cout<< "Nama Dokter: "<<data.namaDokter<<endl;
                cout<< "Spesialis: "<<data.spesialis<<endl;
                cout<< "Nama Pasien: "<<data.namaPasien<<endl;
                cout<< "Nomor Antrian: "<<data.noAntrian<<endl;
                cout<< "Tarif: "<<data.tarif<<endl;
                C = next(C);
                i++;
            }
        }
}
adrRelasi findElmChild (listRelasi L, adrObat rel){
    adrRelasi pRel;
    pRel = first(L);
    if(info(pRel) == rel){
    return pRel;
    }
    pRel = next(pRel);
    while (pRel!=first(L)) {
        if(info(pRel) == rel){
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
        if(first(L) != nil){
            adrRelasi Q;
            Q = first(L);
            while(next(Q)!=first(L)){
                Q = next(Q);
            }
            next(Q) = R;
            next(R) = first(L);
            
        }else{
            first(L) = R;
            next(R)=R;
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
        if (pRel!=nil){
            countObat = 1;
        }
        while(next(pRel)!=first(lr)){
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
            cout<<"---------- Data Pasien "<<info(pDoc).namaPasien<<" ----------"<<endl;
            cout<<"Nama Dokter: "<<info(pDoc).namaDokter<<endl;
            cout<<"Spesialis: "<<info(pDoc).spesialis<<endl;
            cout<<"Nama Pasien: "<<info(pDoc).namaPasien<<endl;
            cout<<"Nomor Antrian: "<<info(pDoc).noAntrian<<endl;
            cout<<"Tarif: "<<info(pDoc).tarif<<endl;
            adrRelasi pObat = first(child(pDoc));
            if (pObat==nil){
                cout<<"Belum Ada Data Obat"<<endl<<endl;
            }else{
                cout<<endl<<"--- Obat ke 1 ---"<<endl;
                cout<<"Merk: "<<info(info(pObat)).merk<<endl;
                cout<<"Kategori: "<<info(info(pObat)).kategori<<endl;
                cout<<"Kode Obat: "<<info(info(pObat)).kode<<endl;
                pObat=next(pObat);
                int j = 2;
                while(pObat!=first(child(pDoc))){
                    cout<<endl<<"--- Obat ke "<<j<<" ---"<<endl;
                    cout<<"Merk: "<<info(info(pObat)).merk<<endl;
                    cout<<"Kategori: "<<info(info(pObat)).kategori<<endl;
                    cout<<"Kode Obat: "<<info(info(pObat)).kode<<endl;
                    
                    pObat = next(pObat);
                    j++;
                }
            }
            pDoc = next(pDoc);
        }
    }
}
void addResep(string &namaPasien, int &antri, string &merkObat, int &kodeObat){
    cout<<"Nama Pasien: ";
    cin>>namaPasien;
    cout<<"No Antri: ";
    cin>>antri;
    cout<<"Merk Obat: ";
    cin>>merkObat;
    cout<<"Kode Obat: ";
    cin>>kodeObat;
    cout<<endl;
}
void showObatPasien(listDokterPasien Ldoc, listObat LObat, int kodeObat){
    adrObat cekObat = findElmObat(LObat, kodeObat);
    adrDokter pDokter = first(Ldoc);
    adrRelasi cekRel = nil;
    cout<<endl<<"--- Daftar Pasien Pembeli Obat "<<info(cekObat).merk<<" ---"<<endl;
    while(pDokter!=nil){
         cekRel = findElmChild(child(pDokter), cekObat);
         if (cekRel!=nil){
             cout<<info(pDokter).namaPasien<<endl;
         }else{
             cout<<"belum ada pembeli"<<endl;
         }
         pDokter = next(pDokter);
     }
}
void bestSellingMedicine(listDokterPasien Ldoc, listObat LObat){
    adrDokter pDokter;
    adrRelasi pRel;
    adrObat pKeep = nil;
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
           pKeep = pObat;
       }else if (maxVal==num){
           dupmax = dupmax +", "+ info(pObat).merk;
       }
       pObat = next(pObat);
   }
   cout<<"Obat yang paling sering dibeli adalah "<<info(pKeep).merk<<dupmax<<" sebanyak "<<maxVal<<endl;
};
void leastSellingMedicine(listDokterPasien Ldoc, listObat LObat){
    adrDokter pDokter;
    adrRelasi pRel;
    adrObat pKeep = nil;
    adrObat pObat = first(LObat);
    string dupmin = "";
    int minVal = 1000;
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
           pKeep = pObat;
       }else if (minVal==num){
           dupmin = dupmin +", "+ info(pObat).merk;
       }
       pObat = next(pObat);
   }
   cout<<"Obat yang paling jarang dibeli adalah "<<info(pKeep).merk<<dupmin<<" sebanyak "<<minVal<<endl;
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
        cout << "-------- APLIKASI DATA DOKTER PASIEN DAN OBAT --------" << endl<<endl;
        cout << "1.  Menambah data dokter pasien" << endl;
        cout << "2.  Menambah data obat" << endl;
        cout << "3.  Menambah data resep" << endl;
        cout << "4.  Menghapus data" << endl;
        cout << "5.  Menampilkan data" << endl;
        cout << "6.  Menampilkan data obat yang paling banyak dibeli pasien" << endl;
        cout << "7.  Menampilkan data obat yang paling sedikit dibeli pasien" << endl;
        cout << "8.  Menampilkan jumlah obat yang dibeli pasien" << endl;
        cout << "9.  Mencari data dokter pasien dan obat" << endl;
        cout << "0.  Exit" << endl<<endl;
        cout <<"Masukan berupa angka 0-10"<<endl;
        cout << "----------------------"<<endl;
        cout << "Masukkan pilihan: ";
        int input = 0;
        cin >> input;
        return input;
};
