#include"header.h"

void createListM(list_M &L){
    first(L) = NULL;
    last(L) = NULL;
}

void createListUlasan(list_U &L){
    first(L) = NULL;
    last(L) = NULL;
}

void createListR(list_R &L){
    first(L) = NULL;
    last(L) = NULL;
}

adrM createMovie(info_M X){
    adrM A;

    A = new movie;
    /*info(A).id = id;
    info(A).judul = judul;
    info(A).sutradara = sutradara;
    info(A).tahun = tahun;*/ //NOTE : ini bisa langsung di rangkum ajah
    info(A) = X;
    next(A) = NULL;

    return A;
}

adrR createReviewer(info_R X){
    adrR A;

    A = new reviewer;
    /*info(A).nama = nama;
    info(A).password = password;
    info(A).id = id;
    next(A) = NULL;*/
    info(A) = X;

    return A;
}


adrU createUlasan(adrM X, adrR Y, string text)
{
    adrU P = new ulasan;
    nextM(P) = X;
    nextR(P) = Y;
    Ulasan(P) = text;
    next(P) = NULL;
    return P;
}


void insertFirst_Movie(list_M &L, adrM P)
{
    if (first(L) != NULL)
    {
        next(P) = first(L);
        first(L) = P;
    }
    else
    {
        first(L) = P;
        last(L) =P;
    }
}

void insertFirst_Reviewer(list_R &L, adrR P)
{
    if (first(L) != NULL)
    {
        next(P) = first(L);
        first(L) = P;
    }
    else
    {
        first(L) = P;
        last(L) =P;
    }
}

void insertFirst_Ulasan(list_U &L, adrU P)
{
    if (first(L) != NULL)
    {
        next(P) = first(L);
        first(L) = P;
    }
    else
    {
        first(L) = P;
        last(L) =P;
    }
}

void insertLast_Movie(list_M &L, adrM P)
{
    if(first(L)!= NULL && last(L) != NULL)
    {
        next(last(L)) = P;
        last(L) = P;
    }
    else
    {
        insertFirst_Movie(L,P);
    }
}

void insertLast_Reviewer(list_R &L, adrR P)
{


    if (first(L) != NULL)
    {
        next(last(L)) = P;
        last(L) = P;
    }
    else
    {
        insertFirst_Reviewer(L,P);
    }
}

void insertLast_Ulasan(list_U &L, adrU P)
{


    if (first(L) != NULL)
    {
        next(last(L)) = P;
        last(L) = P;
    }
    else
    {
        insertFirst_Ulasan(L,P);
    }
}

void deleteFirst_Movie(list_M &L, adrM &P)
{
    if(first(L)!=NULL && last(L) != NULL)
    {
        P = first(L);

        if(first(L) == last(L))
        {
            first(L)= NULL;
            last(L) = NULL;
        }
        else
        {
            first(L) = next(first(L));
            next(P) = NULL;
        }
    }
    else
    {
        cout<<"LIST FILM KOSONG"<<endl;
    }
}

void deleteFirst_Reviewer(list_R &L, adrR &P)
{
    if (first(L) != NULL)
    {
        P = first(L);

        if(next(first(L)) == NULL || first(L)==last(L))
        {
            first(L) = NULL;
            last(L) = NULL;
        }
        else
        {
            first(L) = next(first(L));
            next(P) = NULL;
        }
    }
    else
    {
        cout<<"LIST Reviewer KOSONG"<<endl;
    }
}

void deleteFirst_Ulasan(list_U &L, adrU &P)
{
    if (first(L) != NULL)
    {
        P = first(L);

        if(next(first(L)) == NULL || first(L)==last(L))
        {
            first(L) = NULL;
            last(L) = NULL;
        }
        else
        {
            first(L) = next(first(L));
            next(P) = NULL;
        }
    }
    else
    {
        cout<<"LIST Ulasan KOSONG"<<endl;
    }
}

void deleteLast_Movie(list_M &L, adrM &P)
{
    adrM Q = first(L);
    if(first(L)!= NULL && last(L) != NULL)
    {
        if(first(L)==last(L))
        {
            deleteFirst_Movie(L,P);
        }
        else
        {
            while(next(Q) != last(L))
            {
                Q = next(Q);
            }
            P = last(L);
            last(L) = Q;
            next(last(L))=NULL;
        }
    }
    else
    {
        cout<<"LIST PERUSAHAAN KOSONG"<<endl;
    }
}

void deleteLast_Reviewer(list_R &L, adrR &P)
{
    adrR Q = first(L);

    if(first(L) != NULL)
    {
        if(next(first(L)) == NULL)
            deleteFirst_Reviewer(L,P);
        else
        {
            while(next(Q) != last(L))
            {
                Q = next(Q);
            }
            P = last(L);
            last(L) = Q;
            next(last(L))=NULL;
        }
    }
    else
    {
        cout<<"LIST PRODUK KOSONG"<<endl;
    }
}

void deleteLast_Ulasan(list_U &L, adrU &P)
{
    adrU Q = first(L);

    if(first(L)!= NULL)
    {
        if(next(first(L)) == NULL)
            deleteFirst_Ulasan(L,P);
        else
        {
            while(next(Q) != last(L))
            {
                Q = next(Q);
            }
            P = last(L);
            last(L) = Q;
            next(last(L))=NULL;
        }
    }
}

void delete_Movie(list_M &L, adrM &X)
{

    adrM Q = first(L);
    if(first(L) != NULL && last(L) != NULL)
    {
        if(X == first(L))
        {
            deleteFirst_Movie(L,X);
        }
        else if(X == last(L))
        {
            deleteLast_Movie(L,X);
        }
        else
        {
            while(next(Q) != X)
            {
                Q = next(Q);
            }
            next(Q) = next(X);
            next(X) = NULL;
        }
    }
    else
    {
        cout<<"LIST COMPANY KOSONG"<<endl;
    }
}

void delete_Reviewer(list_R &L, adrR &X)
{
    adrR Q = first(L);

    if(X == first(L))
    {
        deleteFirst_Reviewer(L,X);
    }
    else if(next(X)==NULL)
    {
        deleteLast_Reviewer(L,X);
    }
    else
    {
        while(next(Q) != X)
        {
            Q = next(Q);
        }
        next(Q) = next(X);
        next(X) = NULL;
    }
}

void delete_Ulasan(list_U &L, adrU &X)
{
    adrU Q = first(L);

    if (X == first(L))
    {
        deleteFirst_Ulasan(L,X);
    }
    else if(next(X) == NULL)
    {
        deleteLast_Ulasan(L,X);
    }
    else
    {
        while(next(Q) != X)
        {
            Q = next(Q);
        }
        next(Q) = next(X);
        next(X) = NULL;
    }
}



adrM findElm_Movie(list_M L, info_M X)
{
    adrM P;
    P = first(L);
    while(P!= NULL)
    {
        if(info(P).judul == X.judul)
            return P;
        else
            P = next(P);
    }
    return NULL;
}

adrR findElm_Reviewer(list_R L, info_R X)
{
    adrR P;
    P = first(L);
    while(P!= NULL)
    {
        if(info(P).nama == X.nama)
            return P;
        else
            P = next(P);
    }
    return NULL;
}

adrU findelm_UlasanFrom_Movie(list_U L, adrM X)
{
    adrU P;
    P = first(L);
    while(P!= NULL)
    {
        if(nextM(P) == X)
            return P;
        else
            P = next(P);
    }
    return NULL;
}

adrU findelm_UlasanFrom_Reviewer(list_U L, adrR X)
{
    adrU P;
    P = first(L);
    while(P!= NULL)
    {
        if(nextR(P) == X)
            return P;
        else
            P = next(P);
    }
    return NULL;
}

adrU findelm_UlasanFrom_Movie_Reviewer(list_U L, adrM X, adrR Y)
{
    adrU P;
    P = first(L);
    while(P!= NULL)
    {
        if((nextM(P) == X) && (nextR(P) == Y))
            return P;
        else
            P = next(P);
    }
    return NULL;
}













