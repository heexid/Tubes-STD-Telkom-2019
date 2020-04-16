#ifndef BRAIN_H_INCLUDED
#define BRAIN_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) ((L).first)
#define col(P) (P)->col
using namespace std;

//ADT
struct infopasien{
    string nama;
    string sakit;
};
struct infoobat{
    string obat;
    string jenis;
};
typedef struct eklm *address_kolom;
typedef struct eklm{
    infoobat info;
    address_kolom next;
}ekolom;
typedef struct ebrs *address_baris;
typedef struct ebrs{
    infopasien info;
    ekolom *col;
    address_baris next;
}ebaris;
struct List{
    address_baris first;
};
struct listobat{
    address_kolom first;
};

address_baris AdrBaris(infopasien x);
address_kolom AdrKolom(infoobat x);
void createlist(List &L);
void createlistobat(listobat &L);
void DaftarObat(listobat &L);
void printObat(listobat L,string x);
void printPenyakit(listobat L);
address_kolom findobat(listobat L,string x);
address_baris findpasien(List L,string x);
address_kolom findJenisObat(listobat L,string x);

void addFirstBaris(infopasien pasien, List &L);
void addFirstKolom(infoobat obat,List &L);
void printPasienObat(List L);

void addTKolom(string pasien,address_kolom Q,List &L);
bool sudahPunya(List L,string obat,address_baris P);

//Procedure DELETE
void CekPosisiDel(List &L,address_baris P);
void DelFirst(List &L);
void DelLast(List &L);
void DelTengah(List &L,string x);

void ShowSatuPasien(List L,address_baris P);
void coutObatBanyak(List L,listobat O);
void printObat3(List L);
#endif // BRAIN_H_INCLUDED
