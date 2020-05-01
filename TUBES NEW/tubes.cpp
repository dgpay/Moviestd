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

    cout<<"Id film    : "<<endl;
    cin>>X.id;
    cout<<"Judul      : "<<endl;
    cin>>X.judul;
    cout<<"Sutradara  : "<<endl;
    cin>>X.sutradara;
    cout<<"Tahun      : "<<endl;
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
    int i = 1;

    if(first(L)!=NULL){
        while(P!=NULL){
            cout<<"----------"<<i<<"---------"<<endl;
            cout<<"Id film    : "<<info(P).id<<endl;
            cout<<"Judul      : "<<info(P).judul<<endl;
            cout<<"Sutradara  : "<<info(P).sutradara<<endl;
            cout<<"Tahun      : "<<info(P).tahun<<endl;
            cout<<"--------------------"<<endl;
        i++;
        P=next(P);
        }
    }else{
        cout<<"kosong filnya"<<endl;
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
            cout<<"1. Id film     "<<endl;
            cout<<"2. Judul       "<<endl;
            cout<<"3. Sutradara   "<<endl;
            cout<<"4. Tahun       "<<endl;
            cout<<"5. Kembali     "<<endl;
            cout<<"pilih : ";cin>>i;
            switch(i){
            case 1 :
                cout<<"masukan id baru:";cout<<endl;
                cin>>X.id;
                info(P).id = X.id;
                break;
            case 2 :
                cout<<"masukan Judul baru:";cout<<endl;
                cin>>X.judul;
                info(P).judul = X.judul;
                break;
            case 3 :
                cout<<"masukan Sutradara baru:";cout<<endl;
                cin>>X.sutradara;
                info(P).sutradara = X.sutradara;
            case 4 :
                cout<<"masukan tahun yang baru:";cout<<endl;
                cin>>X.tahun;
                info(P).tahun = X.tahun;
            case 5 :
                break;

        }
}

void DeleteMovie(list_M &L){
    info_M U;
    cout<<"masukan judul film: ";cout<<endl;
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
    if(P!=NULL){
        while(P!=NULL){
        cout<<"--------------------"<<endl;
        cout<<"Id Reviewer    : "<<info(P).id<<endl;cout<<endl;
        cout<<"Nama Reviwer   : "<<info(P).nama<<endl;cout<<endl;
        cout<<"--------------------"<<endl;
        P=next(P);
        }
    }else{
        cout<<"belum ada reviewer yang mendaftar"<<endl;
    }
}

void DeleteReviewer(list_R &L){
    info_R U;
    cout<<"masukan nama reviewer: ";cout<<endl;
    cin>> U.nama;
    adrR X = findElm_Reviewer(L,U);
    if(X != NULL){
        delete_Reviewer(L,X);
    }else{
        cout<<" Film belum terdaftar ";
    }
}

void ViewDetilUlasanDariFilm(list_M L,list_U L1){
    adrM M = first(L);
if(M!=NULL){

    while(M!=NULL){
        adrU U = first(L1);
        cout<<"Judul         : "<<info(M).judul<<endl;
        while(U!=NULL){
            if(nextM(U)==M){
                cout<<"---------------------------------------------"<<endl;
                cout<<"Nama Reviewer : "<<info(nextR(U)).nama<<endl;
                cout<<"ulasan        : "<<Ulasan(U)<<endl;

            }
            U=next(U);
        }
        cout<<"=================================================="<<endl;
        M=next(M);
    }

}else{
    cout<<"masih kosong euy"<<endl;
}
}

void ViewDetilUlasanDariReviewer(list_R L,list_U L1){
    adrR R = first(L);
if(R!=NULL){
     while(R!=NULL){
        adrU U = first(L1);
        cout<<"Nama Reviwer     : "<<info(R).nama<<endl;
        while(U!=NULL){
            if(nextR(U)==R){
                cout<<"---------------------------------------------"<<endl;
                cout<<"Judul Film    : "<<info(nextM(U)).judul<<endl;
                cout<<"ulasan        : "<<Ulasan(U)<<endl;

            }
            U=next(U);
        }
        cout<<"=================================================="<<endl;
        R=next(R);
    }

}else{
    cout<<"KOSONG"<<endl;
}
}
//fungsionalitas login Reviwerr

void inputUlasan(list_M &L1,list_U &L,adrR R){
    info_M X;
    string text;
    cout<<" masukan judul film : ";
    cin>>X.judul;cout<<endl;
    cout<<endl;
    adrU P = first(L);
    adrM Z= findElm_Movie(L1,X);
    if(Z!= NULL){
        while(P!=NULL){
            if(info(nextM(P)).judul == X.judul && nextR(P)==R ){
                char J;

                cout<<" reviewer hanya dapat 1 kali mengulas film.Mau lakukan update?(Y/N)";
                cin>>J;
                cout<<endl;
                if(J=='Y'){
                cout<<" masukan ulasan :";
                cin>>text;
                cout<<endl;
                Ulasan(P)=text;
                cout<<"update selesai."<<endl;
                }
            }else{
                cout<<" masukan ulasan :";
                cin>>text;
                cout<<endl;
                adrU Q = createUlasan(Z,R,text);
                insertFirst_Ulasan(L,Q);
                info(Z).jumUlasan=info(Z).jumUlasan+1;
            }
        }
    }

}

void deleteUlasanFilmTertentu(list_U L,list_M L1,adrR R){
    info_M U;
    cout<<"masukan judul film: ";
    cin>> U.judul;
    cout<<endl;
    adrM X = findElm_Movie(L1,U);

    if(X != NULL){
        adrU Y = findelm_UlasanFrom_Movie_Reviewer(L,X,R);
        if(Y!=NULL){
            deleteFirst_Ulasan(L,Y);
        }else{
            cout<<"Belum di ulas kali bro film nya";
        }
    }else{
        cout<<" Film belum terdaftar ";
    }


}

void viewFilmYgDiulas(list_U L, adrR R){
    adrU P = first(L);
    cout<<"Daftar film yang pernah diulas : ";
    int i=0;
    while(P!=NULL){
        if(R == nextR(P)){
            cout<<i++<<". "<<info(nextM(P)).judul;cout<<endl;
            cout<<"ulasan : "<<Ulasan(P);cout<<endl;
        }
        P=next(P);
    }
}

void viewFilmBlmDiulas(list_U L,list_M L1, adrR R){

    adrM Q =first(L1);
    cout<<"Daftar film yang belum diulas : ";cout<<endl;
    int i=0;
    while(Q!=NULL){
        adrU P = first(L);
        while(P!=NULL){

            if(Q == nextM(P) && R != nextR(P)){
                cout<<i++<<". "<<info(nextM(P)).judul;cout<<endl;
            }
            P=next(P);
        }
        Q=next(Q);
    }
}
void UpdateAkunReviewer(list_R &L,adrR P)
{
   info_R X;

   int i;

            cout<<"1. Nama       ";cout<<endl;
            cout<<"2. Password  ";cout<<endl;
            cout<<"3. back ";cout<<endl;
            cout<<"silahkan masukan judul film : ";
            cin>>i;
            cout<<endl;
            switch(i){
            case 1 :
                cout<<"masukan nama baru:";
                cin>>X.nama;
                info(P).nama = X.nama;
                break;
            case 2 :
                cout<<"masukan Password baru:";
                cin>>X.password;
                info(P).password = X.password;
                break;
            case 3 :
                break;

        }
}

//fungsionalitas login non Reviewer

int jumlahReviewer(list_R L){
    int i=0;
    adrR P = first(L);
    while(P!=NULL){
        i++;
        P=next(P);
    }
    return i;
}

void SignUp(list_R &L){
    cout<<"-----------------------------------------------"<<endl;
    cout<<"                SIGN UP REVIEWER               "<<endl;
    cout<<"-----------------------------------------------"<<endl;
    cout<<endl;
    adrR P;
    info_R X;
    cout<<"Id Username otomatis "<<endl;
    X.id = jumlahReviewer(L)+1;
    cout<<"Nama      : ";
    cin>>X.nama;
    cout<<endl;
    cout<<"Password  : ";
    cin>>X.password;
    cout<<endl;
    P = findElm_Reviewer(L,X);
    if(P!=NULL){
        cout<<"nama sudah terdaftar";
    }else{
        adrR Q = createReviewer(X);
        insertLast_Reviewer(L,Q);
        cout<<"akun berhasil terdaftar";
    }
}
int cariMaksimum(list_M L)
{
    int nMax = 0;
    adrM c = first(L);

    while(c != NULL)
    {
        if(info(c).jumUlasan > nMax)
            nMax = info(c).jumUlasan;
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

        while(nMax > -1)
        {
            P = first(L);

            while(P != NULL)
            {

                if(info(P).jumUlasan == nMax)
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
                            cout<<"Reviewer : "<<info(nextR(Q)).nama<<endl;
                            cout<<"Ulasan   : "<<Ulasan(Q)<<endl;
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



