/* file : Doublylist.cpp */
/* Implementasi ADT Doubly Linked List */
#include "Doublylist.h"

void createList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

bool isEmpty(List L) {
    return L.First == Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

/* ================= INSERT ================= */
void insertFirst(List &L, address P) {
    if (isEmpty(L)) {
        L.First = P;
        L.Last = P;
    } else {
        P->next = L.First;
        L.First->prev = P;
        L.First = P;
    }
}

void insertLast(List &L, address P) {
    if (isEmpty(L)) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

/* I.S. Prec elemen di L, P sudah dialokasi
   F.S. P disisipkan setelah Prec */
void insertAfter(List &L, address Prec, address P) {
    if (Prec == Nil) return;
    if (Prec == L.Last) {
        insertLast(L, P);
    } else {
        P->next = Prec->next;
        P->prev = Prec;
        Prec->next->prev = P;
        Prec->next = P;
    }
}

/* I.S. Succ elemen di L, P sudah dialokasi
   F.S. P disisipkan sebelum Succ */
void insertBefore(List &L, address Succ, address P) {
    if (Succ == Nil) return;
    if (Succ == L.First) {
        insertFirst(L, P);
    } else {
        P->prev = Succ->prev;
        P->next = Succ;
        Succ->prev->next = P;
        Succ->prev = P;
    }
}

/* ================= DELETE ================= */
void deleteFirst(List &L, address &P) {
    P = L.First;
    if (P == Nil) return;
    if (L.First == L.Last) {
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.First = L.First->next;
        L.First->prev = Nil;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    P = L.Last;
    if (P == Nil) return;
    if (L.First == L.Last) {
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.Last = L.Last->prev;
        L.Last->next = Nil;
        P->prev = Nil;
    }
}

/* I.S. Prec dan Prec->next bukan Nil
   F.S. P = elemen setelah Prec, P terlepas dari list */
void deleteAfter(address Prec, address &P) {
    P = Prec->next;
    if (P == Nil) return;
    Prec->next = P->next;
    if (P->next != Nil) {
        P->next->prev = Prec;
    }
    P->next = Nil;
    P->prev = Nil;
}

/* I.S. Succ dan Succ->prev bukan Nil
   F.S. P = elemen sebelum Succ, P terlepas dari list */
void deleteBefore(address Succ, address &P) {
    P = Succ->prev;
    if (P == Nil) return;
    Succ->prev = P->prev;
    if (P->prev != Nil) {
        P->prev->next = Succ;
    }
    P->next = Nil;
    P->prev = Nil;
}

/* ============== SEARCH & VIEW ============== */
address findElm(List L, infotype x) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

/* Ditampilkan dari Last ke First (iterasi mundur via prev),
   sesuai contoh output modul (Gambar 6-23 dan 6-25) */
void printInfo(List L) {
    address P = L.Last;
    while (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}