#include "brain.h"

using namespace std;

int main()
{
    List L;
    listobat O;
    createlistobat(O);
    createlist(L);
    infoobat obat;
    infopasien pasien;
    string x;
    string nama;
    string penyakit;
    int stop=-1;
    address_baris P;
    address_kolom Q;
    address_kolom Z;
    cout<<"===================================="<<endl;
    cout<<"Tugas besar Obat VS Pasien"<<endl;
    cout<<"Nama     Luqman Haries (1301180072)"<<endl;
    cout<<"Nama     Annisa Fajri Hayati (1301180023)"<<endl;
    cout<<"===================================="<<endl;
    system("PAUSE");
    system("CLS");
    //----------------------//
    DaftarObat(O);
    //----------------------//
    while(stop!=100){
        cout<<"===========MENU==========="<<endl;
        cout<<"0.Print Pasien dan Obat"<<endl;
        cout<<"1.Pasien"<<endl;
        cout<<"2.Obat Baru"<<endl;
        cout<<"3.Tambah Obat untuk pasien"<<endl;
        cout<<"4.Hapus Pasien"<<endl;
        cout<<"5.Tampilkan Pasien dengan daftar obatnya"<<endl;
        cout<<"6.Obat yang Populer digunakan"<<endl;
        cout<<"7.Tampilkan Pasien yang menggunakan lebih dari 3 obat"<<endl;
        cout<<"8.Daftar Obat"<<endl;
        cout<<"100.EXIT"<<endl;

        cin>>stop;
        system("CLS");
        if(stop==0){
            printPasienObat(L);
            system("PAUSE");
        };
        if(stop==1){
            cout<<"PASIEN"<<endl;
            cout<<"Nama = ";
            cin>>nama;
            printPenyakit(O);
            cout<<"Sakit = ";
            cin>>penyakit;
            system("CLS");
            P=findpasien(L,nama);
            Z=findJenisObat(O,penyakit);
            if((P==NULL)&&(Z!=NULL)){
                cout<<"Menampilkan Menu Obat"<<endl;
                printObat(O,penyakit);
                cout<<"Masukkan Nama Obat = ";
                cin>>x;
                Q=findobat(O,x);
                if(Q!=NULL){
                    obat.obat=info(Q).obat;
                    obat.jenis=info(Q).jenis;
                    pasien.nama=nama;
                    pasien.sakit=penyakit;
                    addFirstBaris(pasien,L);
                    addFirstKolom(obat,L);
                    cout<<"Berhasil ditambahkan!"<<endl;
                    system("PAUSE");
                }else{
                    cout<<"Mohon maaf Obat tidak ditemukan"<<endl;
                    system("PAUSE");
                };
            }else if(Z==NULL){
                cout<<"Jenis obat untuk penyakit "<<penyakit<<" belum ada"<<endl;
                system("PAUSE");
            }else{
                cout<<"Nama Pasien = "<<info(P).nama<<" Sudah terdaftar"<<endl;
                cout<<"Apakah ingin menambahkan Obat?? <y/n> "<<endl;
                char y;
                cin>>y;
                if(y=='y'){
                    cout<<"Menampilkan Menu Obat"<<endl;
                    printObat(O,penyakit);
                    cout<<"Masukkan Nama Obat = ";
                    cin>>obat.obat;
                    Q=findobat(O,obat.obat);
                    if(Q!=NULL && !sudahPunya(L,obat.obat,P)){
                        obat.obat=info(Q).obat;
                        obat.jenis=info(Q).jenis;
                        addTKolom(nama,Q,L);
                        cout<<"Berhasil ditambahkan!"<<endl;
                        system("PAUSE");
                    }else{
                        cout<<"Nama obat tidak ditemukan atau obat sudah terdaftar dipasien"<<endl;
                        system("PAUSE");
                    };
                };
            };
        };

        if(stop==2){
            DaftarObat(O);
            //printObat(O,penyakit);
            system("PAUSE");
        };

        if(stop==3){
            cout<<"Cari nama ";
            cin>>nama;
            P=findpasien(L,nama);
            if(P!=NULL){
                cout<<"Nama Pasien = "<<info(P).nama<<" Sudah terdaftar"<<endl;
                cout<<"Apakah ingin menambahkan Obat?? <y/n> "<<endl;
                char y;
                cin>>y;
                if(y=='y'){
                    cout<<"Menampilkan Menu Obat"<<endl;
                    printObat(O,"NULL");
                    cout<<"Masukkan Nama Obat = ";
                    cin>>obat.obat;
                    Q=findobat(O,obat.obat);
                    if(Q!=NULL && !sudahPunya(L,obat.obat,P)){
                        obat.obat=info(Q).obat;
                        obat.jenis=info(Q).jenis;
                        addTKolom(nama,Q,L);
                        cout<<"Berhasil ditambahkan!"<<endl;
                    }else{
                        cout<<"Nama obat tidak ditemukan atau nama obat sudah terdaftar dipasien"<<endl;
                    };
                };
            }else{
                cout<<"NAMA TIDAK DITEMUKAN"<<endl;
            };
            system("PAUSE");
        }

        if(stop==4){
            if(first(L)!=NULL){
                cout<<"HAPUS PASIEN"<<endl;
                cout<<"Nama = ";
                cin>>nama;
                P=findpasien(L,nama);
                CekPosisiDel(L,P);
                if(P!=NULL){
                    cout<<"PASIEN dengan nama "<<nama<<" Berhasil di HAPUS!"<<endl;
                }
            }else{
                cout<<"LIST KOSONG"<<endl;
            }
            system("PAUSE");
        }

        if(stop==5){
            cout<<"Cari Pasien"<<endl;
            cout<<"Nama = ";
            cin>>nama;
            system("CLS");
            P=findpasien(L,nama);
            ShowSatuPasien(L,P);
            system("PAUSE");
        }

        if(stop==6){
            if(first(L)!=NULL){
                coutObatBanyak(L,O);
            }else{
                cout<<"LIST KOSONG"<<endl;
            }

            system("PAUSE");
        };

        if(stop==7){
            if(first(L)!=NULL){
                printObat3(L);
                cout<<endl;
            }else{
                cout<<"LIST KOSONG"<<endl;
            }
            system("PAUSE");
        }

        if(stop==8){
            printObat(O,"NULL");
            system("PAUSE");
        };



        system("CLS");
        //me-reset
        P=NULL;
        Q=NULL;
        }//END WHILE




/*
    x="mortin";
    Q=findobat(O,x);
    pasien.nama="Budi";
    pasien.sakit="12";
    addFirstBaris(pasien,L);
    addFirstKolom(obat,pasien.nama,L);

    obat.obat="suju";
    pasien.nama="Jono";
    pasien.sakit="12";
    addFirstBaris(pasien,L);
    addFirstKolom(obat,pasien.nama,L);

    obat.obat="Bodrex";
    pasien.nama="Kolang";
    pasien.sakit="90";
    addFirstBaris(pasien,L);
    addFirstKolom(obat,pasien.nama,L);
    printPasienObat(L);
*/

}
