/* file : Doublylist.h */
/* ADT Doubly Linked List dengan representasi fisik pointer */
/* infotype : kendaraan (nopol, warna, thnBuat) */
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <iostream>
#include <string>
using namespace std;
#define Nil NULL

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

typedef struct ElmList *address;
struct ElmList {
    infotype info;
    address next;
    address prev;
};

/* List kosong jika L.First = Nil dan L.Last = Nil */
struct List {
    address First;
    address Last;
};

/* ===== Primitif dasar ===== */
void createList(List &L);
bool isEmpty(List L);
address alokasi(infotype x);
void dealokasi(address &P);

/* ===== Insert ===== */
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L, address Prec, address P);
void insertBefore(List &L, address Succ, address P);

/* ===== Delete ===== */
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);
void deleteBefore(address Succ, address &P);

/* ===== Search & View ===== */
address findElm(List L, infotype x);
void printInfo(List L);

#endif