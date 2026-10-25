/* file : main.cpp */
/* Driver ADT Doubly Linked List - Modul 6 Latihan 1, 2, 3 */
#include "Doublylist.h"

const int JUMLAH_INPUT = 4;

int main() {
    List L;
    infotype x;
    address P;
    createList(L);

    /* ===== Latihan 1 : input data + insertLast ===== */
    for (int i = 0; i < JUMLAH_INPUT; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        if (findElm(L, x) != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            P = alokasi(x);
            insertLast(L, P);
        }
        cout << endl;
    }

    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);
    cout << endl;

    /* ===== Latihan 2 : findElm ===== */
    cout << "Masukkan Nomor Polisi yang dicari  : ";
    cin >> x.nopol;
    cout << endl;

    P = findElm(L, x);
    if (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data dengan nomor polisi " << x.nopol << " tidak ditemukan." << endl;
    }
    cout << endl;

    /* ===== Latihan 3 : hapus berdasarkan nopol ===== */
    cout << "Masukkan Nomor Polisi yang akan dihapus  : ";
    cin >> x.nopol;

    P = findElm(L, x);
    if (P == Nil) {
        cout << "Data dengan nomor polisi " << x.nopol << " tidak ditemukan." << endl;
    } else {
        address D;
        if (P == L.First) {
            deleteFirst(L, D);
        } else if (P == L.Last) {
            deleteLast(L, D);
        } else {
            deleteAfter(P->prev, D);
        }
        dealokasi(D);
        cout << "Data dengan nomor polisi " << x.nopol << " berhasil dihapus." << endl;
    }

    cout << endl << "DATA LIST 1" << endl << endl;
    printInfo(L);

    /* bersihkan memori */
    while (!isEmpty(L)) {
        deleteFirst(L, P);
        dealokasi(P);
    }

    return 0;
}