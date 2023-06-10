//
//  DokterPasien.hpp
//  DokterMll
//
//  Created by Melyna Nura on 09/06/23.
//

#ifndef DokterPasien_hpp
#define DokterPasien_hpp

#include <stdio.h>

#include <iostream>
using namespace std;
#include "Obat.hpp"

#define first(L) ((L).first)
#define next(P) P->next
#define info(P) P->info
#define child(P) P->child
#define nil NULL

struct DokterPasien{
    string namaDokter;
    string spesialis;
    int noAntrian;
    double tarif;
    string namaPasien;
};

typedef DokterPasien infoDokter;
typedef struct elementDokter *adrDokter;
typedef struct elementRelasi *adrRelasi;

struct listRelasi{
     adrRelasi first;
};

struct listDokterPasien{
     adrDokter first;
};

struct elementDokter{
    infoDokter info;
    listRelasi child;
    adrDokter next;
};

struct elementRelasi{
    adrRelasi next;
    adrObat info;
};

//DokterPasien
void createDocList(listDokterPasien &L);
adrDokter newElementDoc(infoDokter data);
void addToLastD(listDokterPasien &L, adrDokter T);
void showDoc(listDokterPasien L);
adrRelasi findElmChild (listRelasi L, adrObat rel);
adrDokter findElmDoc (listDokterPasien L, double antri);
int cekElementFirst(listDokterPasien LD);
infoDokter addMainDoc(infoDokter &dataDokter);

//Relasi
void createRelasi(listRelasi &L);
adrRelasi newElemenRelasi(adrObat data);
void addToLastR(listRelasi &L, adrRelasi R);

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

//menu
int selectMenu();
void helpPanduan();

#endif /* DokterPasien_hpp */
