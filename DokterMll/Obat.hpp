//
//  Obat.hpp
//  DokterMll
//
//  Created by Melyna Nura on 09/06/23.
//

#ifndef Obat_hpp
#define Obat_hpp

#include <stdio.h>

#include <iostream>
using namespace std;

#define first(L) ((L).first)
#define next(P) P->next
#define info(P) P->info
#define nil NULL

struct Obat{
    string merk;
    string kategori;
    int kode;
};

typedef Obat infoObat;

typedef struct elementObat *adrObat;

struct elementObat{
    infoObat info;
    adrObat next;
};

struct listObat{
     adrObat first;
};

void createObatList(listObat &L);
adrObat newElementObat(infoObat data);
void addToLastO(listObat &L, adrObat T);
void showObat(listObat L);
adrObat findElmObat (listObat L, int kode);
infoObat addMainObat(infoObat &dataObat);
void showInfoObat (listObat L);

#endif /* Obat_hpp */
