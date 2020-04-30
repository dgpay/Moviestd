#include"header.h"
#include <stdio.h>

//fungsionalitas login Admin
void addmovie(list_M &L)
{
    adrM P;
    info_M X;


    cout<<"-----------------------------------------------"<<endl;
    cout<<"                  MENAMBAH MOVIE                "<<endl;
    cout<<"-----------------------------------------------"<<endl;
    cout<<endl;

    cout<<"Id film    : ";
    cin>>X.id;
    cout<<"Judul      : ";
    cin>>X.judul;
    cout<<"Sutradara  : ";
    cin>>X.sutradara;
    cout<<"Tahun      : ";
    cin>>X.tahun;
    X.jumUlasan=0;

    P = findElm_Movie(L,X);

    if(P != NULL)
    {
        cout<<"Movie sudah ada silahkan masuk ke menu update movie"<<endl;
    }

    else
    {
        P = createMovie(X);
        insertLast_Movie(L,P);
    }
}

void printMovie(list_M L)
{
    adrM P=first(L);
    while(P!=NULL){
    cout<<"--------------------"<<endl;
    cout<<"Id film    : "<<info(P).id<<endl;
    cout<<"Judul      : "<<info(P).judul<<endl;
    cout<<"Sutradara  : "<<info(P).sutradara<<endl;
    cout<<"Tahun      : "<<info(P).tahun<<endl;
    cout<<"--------------------"<<endl;
    P=next(P);
    }
}


void updateMovie(list_M &L)
{
   adrM P = first(L);
   info_M X;
   cout<<"silahkan masukan judul film : ";
   cin>>X.judul;
   P=findElm_Movie(L,X);
   if(P!=NULL){
            menuUpdateMovie(L,P);
   }else{
    cout<<" Film belum terdaftar ";
   }
}

void menuUpdateMovie(list_M &L,adrM P){
    int i;
    info_M X;
            cout<<"1. Id film     ";
            cout<<"2. Judul       ";
            cout<<"3. Sutradara   ";
            cout<<"4. Tahun       ";
            cout<<"5. Kembali     ";
            cout<<"silahkan masukan judul film : ";
            switch(i){
            case 1 :
                cout<<"masukan id baru:";
                cin>>X.id;
                info(P).id = X.id;
                break;
            case 2 :
                cout<<"masukan Judul baru:";
                cin>>X.judul;
                info(P).judul = X.judul;
                break;
            case 3 :
                cout<<"masukan Sutradara baru:";
                cin>>X.sutradara;
                info(P).sutradara = X.sutradara;
            case 4 :
                cout<<"masukan tahun yang baru:";
                cin>>X.tahun;
                info(P).tahun = X.tahun;
            case 5 :
                break;

        }
}

void DeleteMovie(list_M &L){
    info_M U;
    cout<<"masukan judul film: ";
    cin>> U.judul;
    adrM X = findElm_Movie(L,U);
    if(X != NULL){
        delete_Movie(L,X);
    }else{
        cout<<" Film belum terdaftar ";
    }
}

void printReviewer(list_R L){
    adrR P=first(L);
    info_R q;
    while(P!=NULL){
    cout<<"--------------------"<<endl;
    cout<<"Id Reviewer    : "<<info(P).id<<endl;
    cout<<"Nama Reviwer   : "<<info(P).nama<<endl;
    cout<<"--------------------"<<endl;
    P=next(P);
    }
}

void DeleteReviewer(list_R &L){
    info_R U;
    cout<<"masukan nama reviewer: ";
    cin>> U.nama;
    adrM X = findElm_Reviewer(L,U);
    if(X != NULL){
        delete_Reviewer(L,X);
    }else{
        cout<<" Film belum terdaftar ";
    }
}

//fungsionalitas login Reviwerr


//fungsionalitas login non Reviewer

int jumlahReviewer(list_R L){
    int i=0;
    adrR P = first(L);
    while(P!=NULL){
        i++;
        P=next(P);
    }
}

void SignUp(list_R &L){
    cout<<"-----------------------------------------------"<<endl;
    cout<<"                SIGN UP REVIEWER               "<<endl;
    cout<<"-----------------------------------------------"<<endl;
    cout<<endl;
    adrR P;
    info_R X;
    cout<<"Id Username otomatis ";
    X.id = jumlahReviewer(L)+1;
    cout<<"Nama      : ";
    cin>>X.nama;
    cout<<"Password  : ";
    cin>>X.password;
    P = findElm_Reviewer(L,X);
    if(P!=NULL){
        cout<<"nama sudah terdaftar";
    }else{
        adrR Q = createReviewer(X);
        insertLast_Reviewer(L,Q);
        cout<<"akun berhasil terdaftar";
    }
}
int cariMaksimum(List_M L)
{
    int nMax = 0;
    adrM c = first(L);

    while(c != NULL)
    {
        if(info(c).jump > nMax)
            nMax = info(c).jump;
        c = next(c);
    }
    return nMax;
}

void PrintFilmByJumUlasan(list_M L, list_U L1){
    adrM P;
    int nTOP = 1;
    int nMax = cariMaksimum(L); //CARI NILAI MAKSIMUM

    system("cls");
    cout<<"-----------------------------------------------"<<endl;
    cout<<"   TAMPILKAN FILM BERDASARKAN JUMLAH ULASAN    "<<endl;
    cout<<"-----------------------------------------------"<<endl;

    if(first(L)!= NULL)
    {
        //JIKA PEURAHAAN ADA,
        while(nMax > -1)
        {
            P = first(L);

            while(P != NULL)
            {
                //SELAMA PERUSAHAAN MASIH ADA,
                if(info(P).jump == nMax)
                {

                    cout<<"FILM Ke - "<<nTOP<<" : "<<endl;
                    cout<<"Id film    : "<<info(P).id<<endl;
                    cout<<"Judul      : "<<info(P).judul<<endl;
                    cout<<"Sutradara  : "<<info(P).sutradara<<endl;
                    cout<<"Tahun      : "<<info(P).tahun<<endl;
                    cout<<"-----------------------------------------------"<<endl;
                    adrU Q = first(L1);
                    while(Q!=NULL){
                        if(nextM(Q)==P){
                            cout<<Ulasan(Q)<<endl;
                            cout<<"................................................"<<endl;
                        }
                        Q=next(Q);
                    }
                    nTOP++;
                }
                    cout<<"==============================================="<<endl;
                    cout<<""<<endl;
                    cout<<""<<endl;
                P = next(P);
            }
            nMax--;
        }
    }
    else
    {
        cout<<"List Film Kosong"<<endl;
    }

}
