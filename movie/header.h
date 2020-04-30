#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <cstddef>

#define Nil NULL
#define first(A) (A).first
#define next(A) (A)->next
#define info(A) (A)->info
#define last(A) (A).last
#define nextM(A) (A)->nextM
#define nextR(A) (A)->nextR
#define Ulasan(A) (A)->Ulasan


using namespace std;

struct info_M{
    string id;
    string judul;
    string sutradara;
    string tahun;
    int jumUlasan;
};

struct info_R{
    string nama;
    string password;
    int id;
};

typedef struct movie *adrM;
typedef struct ulasan *adrU;
typedef struct reviewer *adrR;

struct movie {
    info_M info;
    adrM next;
};

struct reviewer{
    info_R info;
    adrR next;
};

struct ulasan{
    adrM nextM;
    adrR nextR;
    adrU next;
    string Ulasan;
};

struct list_M {
    adrM first;
    adrM last;
};

struct list_U {
    adrU first;
    adrU last;
};

struct list_R {
    adrR first;
    adrR last;
};

// AREA DARI STRUKTUR PEMBUATAN MULTI LIST DAN FUNGSI YANG DIBUTUHKAN
void createListM(list_M &L);
void createListR(list_R &L);
void createListUlasan(list_U &L);

adrM createMovie(info_M X);
adrR createReviewer(info_R X);
adrU createUlasan(adrM X, adrR Y,int jumlah);

void insertFirst_Movie(list_M &L, adrM P);
void insertFirst_Reviewer(list_R &L, adrR P);
void insertFirst_Ulasan(list_U &L, adrU P);

void insertLast_Movie(list_M &L, adrM P);
void insertLast_Reviewer(list_R &L, adrR P);
void insertLast_Ulasan(list_U &L, adrU P);

void deleteFirst_Movie(list_M &L, adrM &P);
void deleteFirst_Reviewer(list_R &L, adrR &P);
void deleteFirst_Ulasan(list_U &L, adrU &P);

void deleteLast_Movie(list_M &L, adrM &P);
void deleteLast_Reviewer(list_R &L, adrR &P);
void deleteLast_Ulasan(list_U &L, adrU &P);

void delete_Movie(list_M &L, adrM &X);
void delete_Reviewer(list_R &L, adrR &X);
void delete_Ulasan(list_U &L, adrU &X);

adrM findElm_Movie(list_M L, info_M X); //X adalah id dari movie
adrR findElm_Reviewer(list_R L, info_R X); // X adalah id dari Reviwer dimana id adalah username
adrU findelm_UlasanFrom_Movie(list_U L, adrM X);
adrU findelm_UlasanFrom_Reviewer(list_U L, adrR X);
adrU findelm_UlasanFrom_Movie_Reviewer(list_U L, adrM X, adrR Y);




// INI AREA DARI FUNGSIONALITAS TUBESNYA
void addmovie (list_M &A);
void printdatafilm(list_M A);
void menuUpdateMovie(list_M &L,adrM P);

#endif // HEADER_H_INCLUDED
