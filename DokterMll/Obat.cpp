//
//  Obat.cpp
//  DokterMll
//
//  Created by Melyna Nura on 09/06/23.
//

#include "Obat.hpp"

void createObatList(listObat &L){
    first(L)=nil;
}
adrObat newElementObat(infoObat data){
    adrObat O = new elementObat;
    info(O) = data;
    next(O) = nil;
    
    return O;
}
void addToLastO(listObat &L, adrObat T){
    if(first(L)==nil){
            first(L) = T;
    }else{
            adrObat Q;
            Q = first(L);
            while(next(Q)!=nil){
                Q = next(Q);
            }
            next(Q) = T;
        }
}
void showObat(listObat L){
    adrObat T;
        T = first(L);
        infoObat data;

        if(T==nil){
            cout<<"Tidak Ada Data"<<endl;
        }else{
            int i = 1;
            cout<<"--- Data Obat ---"<<endl;
            while(T!=nil){
                data = info(T);
                cout<<endl;
                cout<<"Data obat ke-"<<i<<endl;
                cout<< "Merk: "<<data.merk<<endl;
                cout<< "Kategori: "<<data.kategori<<endl;
                cout<< "Kode: "<<data.kode<<endl;
                i++;
                T = next(T);
            }
        }
}
adrObat findElmObat (listObat L, int kode){
    adrObat pObat;
        pObat = first(L);
        while (pObat!=nil) {
            if(info(pObat).kode==kode){
                return pObat;
                break;
            }
            pObat=next(pObat);
        }
        return  nil;
}
infoObat addMainObat(infoObat &dataObat){
    cout<<"Merk: ";
    cin>>dataObat.merk;
    cout<<"Kategori: ";
    cin>>dataObat.kategori;
    cout<<"Kode: ";
    cin>>dataObat.kode;
    
    return dataObat;
}
