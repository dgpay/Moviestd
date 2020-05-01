#include"header.h"
#include <stdio.h>
#include<conio.h>

//MENU MENU MENU MENU

void MenuLoginAdmin(list_M L,list_R L1,list_U L2){
    string admin = "admin";
    string password ="123";

    string adm,pass;

    cout<<"masukan username admin : "<<endl; cin>>adm;
    cout<<"masukan password admin : "<<endl; cin>>pass;
    system("cls");
    if(admin == adm && password==pass){
            int i=0;
            info_M X;

        do{
            system("cls");
            cout<<"-------------------------------------"<<endl;
            cout<<"          ADMIN LOGIN MENU           "<<endl;
            cout<<"-------------------------------------"<<endl;
            cout<<"1. Insert last data film    "<<endl;
            cout<<"2. View data film       "<<endl;
            cout<<"3. Update data film  "<<endl;
            cout<<"4. Delete data film       "<<endl;
            cout<<"5. View data reviewer"<<endl;
            cout<<"6. Delete data reviewer    "<<endl;
            cout<<"7. View total dan detail ulasan untuk setiap film   "<<endl;
            cout<<"8. View total dan detail ulasan dari setiap reviewer"<<endl;
            cout<<"9. LOGOUT : "<<endl;
            cout<<"Pilih : "; cin>>i;
            switch(i){
            case 1 :
                addmovie(L);
                break;
            case 2 :
                printMovie(L);
                break;
            case 3 :
                updateMovie(L);
                break;
            case 4 :
                DeleteMovie(L);
                break;
            case 5 :
                printReviewer(L1);
                break;
            case 6 :
                DeleteReviewer(L1);
                break;
            case 7 :
                ViewDetilUlasanDariFilm(L,L2);
                break;
            case 8 :
                ViewDetilUlasanDariReviewer(L1,L2);
                break;
            default :
                cout<<"admin logout";
            }
        getch();
        }while(i!=9);

    }

}

adrR cekAkunReviewer(list_R L1,info_R X){
    adrR R =first(L1);
    while(R!=NULL){
        if(info(R).nama!=X.nama &&info(R).password!=X.password)
            return R;
        else{
        R=next(R);
        }
    }


        return NULL;

}
void MenuLoginReviewer(list_M L,list_R L1,list_U L2){
    info_R X;
    cout<<"masukan username : "<<endl; cin>>X.nama;
    cout<<"masukan password  : "<<endl; cin>>X.password;
    adrR R =cekAkunReviewer(L1,X);

    system("cls");
    if(R!=NULL){
        int i=0;
        while(i!=6){
            info_M X;

            cout<<"-------------------------------------"<<endl;
            cout<<"          REVIEWER LOGIN MENU           "<<endl;
            cout<<"-------------------------------------"<<endl;
            cout<<"1. Input ulasan utk film tertentu (Insert first) "<<endl;
            cout<<"2. Hapus ulasan untuk film tertentu       "<<endl;
            cout<<"3. Menampilkan daftar film yang pernah diulas beserta ulasannya  "<<endl;
            cout<<"4. Menampilkan daftar film yang belum diulas      "<<endl;
            cout<<"5. Update akun (data reviewer) yang sedang login"<<endl;
            cout<<"6. LOGOUT    "<<endl;
            cout<<"Pilih : "; cin>>i;
            switch(i){
            case 1 :
                inputUlasan(L,L2,R);
                break;
            case 2 :
                deleteUlasanFilmTertentu(L2,L,R);
                break;
            case 3 :
                viewFilmYgDiulas(L2, R);
                break;
            case 4 :
                viewFilmBlmDiulas(L2,L,R);
                break;
            case 5 :
                UpdateAkunReviewer(L1,R);
                break;
            case 6 :
                break;
            }
            system("cls");

        }

    }else{
        cout<<"tidak ada akun terdaftar";
    }
getch();

}

void MenuUtama(list_M L,list_R L1,list_U L2){
            int i=0;
            while(i!=6){

            cout<<"-------------------------------------"<<endl;
            cout<<"          KUY NGULAS FILM            "<<endl;
            cout<<"-------------------------------------"<<endl;
            cout<<"1. Login Admin "<<endl;
            cout<<"2. Login Reviewer     "<<endl;
            cout<<"3. Sign Up Reviewer  "<<endl;
            cout<<"4. View semua film beserta ulasannya, terurut berdasarkan jumlah ulasan      "<<endl;
            cout<<"5. BYE"<<endl;
            cout<<"Pilih : "; cin>>i;
            switch(i){
            case 1 :
                MenuLoginAdmin(L,L1, L2);
                break;
            case 2 :
                MenuLoginReviewer(L,L1, L2);
                break;
            case 3 :
                SignUp(L1);
                break;
            case 4 :
                PrintFilmByJumUlasan(L,L2);
                break;
            case 5 :
                break;
            }
            system("cls");
             getch();
            }
}
