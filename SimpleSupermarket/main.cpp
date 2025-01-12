#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void savinguser(int saldo,vector<int> user_cart,vector<int> jumlah_cart,string username){
    ofstream fileuser(username + ".txt");
    if(fileuser.is_open()){
        fileuser<<saldo;
        if(user_cart.size()==0){

        }
        else{
            for(int i=0;i<=user_cart.size()-1;i++){
                if(i==0){
                    fileuser<<endl;
                }
                fileuser<<user_cart[i]<<endl;
                fileuser<<jumlah_cart[i];
                if(i != user_cart.size() - 1) fileuser<< endl;
            }
            fileuser.close();
        }
    }
}
int main()
{
    bool jalan=true;
    bool loggedin=false;
    string useradmin="admin";
    string passadmin="admin";
    vector<string> user;
    vector<string> pass;
    vector<string> nama_barang;
    vector<int> harga_barang;
    bool loginadmin=false;
    bool loginuser=false;
    bool userbaru=true;
    string kuncipass;
    string username;
    string password;
    vector<int> user_cart;
    vector<int>jumlah_cart;
    int notake=1;
    ifstream nomornotaload("nonota.txt");
    if(nomornotaload.is_open()){
        string tempnotastring;
        getline(nomornotaload,tempnotastring);
        stringstream (tempnotastring) >> notake;
        nomornotaload.close();
    }
    ifstream loadingakun("user.txt");
    if(loadingakun.is_open()){
        while(!loadingakun.eof()){
            string tempuser;
            string temppass;
            getline(loadingakun,tempuser);
            user.push_back(tempuser);

            getline(loadingakun,temppass);
            pass.push_back(temppass);
        }
        loadingakun.close();
    }
    nama_barang.clear();
    harga_barang.clear();
    ifstream loadingbarang("listbarang.txt");
    if(loadingbarang.is_open()){
        while(!loadingbarang.eof()){
            string tempnama;
            string temphargastring;
            int tempharga;
            getline(loadingbarang,tempnama);
            nama_barang.push_back(tempnama);

            getline(loadingbarang,temphargastring);
            stringstream (temphargastring) >> tempharga;
            harga_barang.push_back(tempharga);
        }
        loadingbarang.close();
    }
    while(jalan==true){
        while(loggedin==false){
            cout<<"welcome to IndoNovember"<<endl;
            cout<<"Username : ";
            cin>>username;
            if(username==useradmin){
                kuncipass=passadmin;
                cout<<"password : ";
                cin>>password;
                if(password==kuncipass){
                    loginadmin=true;
                    loggedin=true;
                }
                else{
                    cout<<"password salah"<<endl;
                }
            }
            else if(username=="-1"){
                cout<<"password : ";
                cin>>password;
                if(password=="-1"){
                    loggedin=true;
                    jalan=false;
                }
            }
            else if(user.size()==0){
                user.push_back(username);
                cout<<"password : ";
                cin>>password;
                pass.push_back(password);
                ofstream fileuser(username + ".txt");
                fileuser.close();
                ofstream fileuserpass("user.txt");
                if(fileuserpass.is_open()){
                    for(int i=0;i<=user.size()-1;i++){
                        fileuserpass<<user[i]<<endl;
                        fileuserpass<<pass[i];
                        if(i != user_cart.size() - 1) fileuserpass<< endl;
                    }
                    fileuserpass.close();
                }
            }
            else{
                userbaru=true;
                for(int i=0;i<=user.size()-1;i++){
                    if(username==user[i]){
                        userbaru=false;
                        kuncipass=pass[i];
                        i=user.size();
                    }
                }
                if(userbaru==true){
                    user.push_back(username);
                    cout<<"password : ";
                    cin>>password;
                    pass.push_back(password);
                    ofstream fileuser(username + ".txt");
                    fileuser.close();
                    ofstream fileuserpass("user.txt");
                    if(fileuserpass.is_open()){
                        for(int i=0;i<=user.size()-1;i++){
                            fileuserpass<<user[i]<<endl;
                            fileuserpass<<pass[i];
                            if(i != user_cart.size() - 1) fileuserpass<< endl;
                        }
                        fileuserpass.close();
                    }
                }
                else{
                    cout<<"password : ";
                    cin>>password;
                    if(password==kuncipass){
                        loginuser=true;
                        loggedin=true;
                    }
                    else{
                        cout<<"password anda salah"<<endl;
                    }
                }
            }
        }
        if(loginuser==true){
            int saldo=0;
            nama_barang.clear();
            harga_barang.clear();
            ifstream loadingbarang("listbarang.txt");
            if(loadingbarang.is_open()){
                while(!loadingbarang.eof()){
                    string tempnama;
                    string temphargastring;
                    int tempharga;
                    getline(loadingbarang,tempnama);
                    nama_barang.push_back(tempnama);

                    getline(loadingbarang,temphargastring);
                    stringstream (temphargastring) >> tempharga;
                    harga_barang.push_back(tempharga);
                }
                loadingbarang.close();
            }
            user_cart.clear();
            jumlah_cart.clear();
            ifstream loadinguser(username+".txt");
            if(loadinguser.is_open()){
                string tempsaldostring;
                getline(loadinguser,tempsaldostring);
                stringstream tempsaldointeger(tempsaldostring);
                tempsaldointeger>>saldo;
                while(!loadinguser.eof()){
                    string tempnamastring;
                    string tempjumlahstring;
                    int tempnama;
                    int tempjumlah;
                    getline(loadinguser,tempnamastring);
                    stringstream tempnamainteger(tempnamastring);
                    tempnamainteger>>tempnama;
                    user_cart.push_back(tempnama);

                    getline(loadinguser,tempjumlahstring);
                    stringstream tempjumlahinteger(tempjumlahstring);
                    tempjumlahinteger>>tempjumlah;
                    jumlah_cart.push_back(tempjumlah);
                }
                loadinguser.close();
            }
//            saldo=saldouser;
            int inputan_user;
            int beli_barang;
            int jumlah_barang;
            cout<<"welcome, "<<username<<endl;
            cout<<"saldo : "<<saldo<<endl;
            cout<<"1. Beli Barang"<<endl;
            cout<<"2. Cart"<<endl;
            cout<<"3. Bayar"<<endl;
            cout<<"4. Topup"<<endl;
            cout<<"0. Exit"<<endl;
            cout<<">>";
            cin>>inputan_user;
            if(inputan_user==1){
                cout<<"======================="<<endl;
                cout<<"DAFTAR BARANG"<<endl;
                cout<<"======================="<<endl;
                if(nama_barang.size()==0){

                }
                else{
                    for(int i=0;i<=nama_barang.size()-1;i++){
                        cout<<i+1<<". "<<nama_barang[i]<<" - "<<harga_barang[i]<<endl;
                    }
                    cout<<"barang apa yang akan dibeli?"<<endl;
                    cout<<">>";
                    cin>>beli_barang;
                    cout<<"jumlah barang : ";
                    cin>>jumlah_barang;
                    user_cart.push_back(beli_barang);
                    jumlah_cart.push_back(jumlah_barang);
                    savinguser(saldo,user_cart,jumlah_cart,username);
                }
            }
            else if(inputan_user==2){
//                for(int i=0;i<=nama_barang.size()-1;i++){
//                    cout<<nama_barang[i]<<" ";
//                    cout<<endl<<harga_barang[i]<<" ";
//                }
                int menucart;
                cout<<"======================="<<endl;
                cout<<username<<"'s cart"<<endl;
                cout<<"======================="<<endl;
                if(user_cart.size()==0){

                }
                else{
                    int total=0;
                    for(int i=0;i<=user_cart.size()-1;i++){
                        cout<<i+1<<". "<<nama_barang[user_cart[i]-1]<<" - "<<jumlah_cart[i]<<" - "<<harga_barang[user_cart[i]-1]*jumlah_cart[i]<<endl;
                        total=total+harga_barang[user_cart[i]-1]*jumlah_cart[i];
                    }
                    cout<<"total : "<<total<<endl;
                    cout<<"======================="<<endl;
                    cout<<"1. Remove"<<endl;
                    cout<<"0. Exit"<<endl;
                    cout<<">>";
                    cin>>menucart;
                    if(menucart==1){
                        int deletcart;
                        cout<<"barang apa yang mau di remove?"<<endl;
                        cout<<">>";
                        cin>>deletcart;
                        if(deletcart==0){

                        }
                        else{
                            user_cart.erase(user_cart.begin()+deletcart-1);
                            jumlah_cart.erase(jumlah_cart.begin()+deletcart-1);
                            savinguser(saldo,user_cart,jumlah_cart,username);
                        }
                    }
                    else if(menucart==0){

                    }
                }
            }
            else if(inputan_user==3){
                int total=0;
                for(int i=0;i<=user_cart.size()-1;i++){
                    total=total+harga_barang[user_cart[i]-1]*jumlah_cart[i];
                }
                if(saldo>=total){
                    if(notake<10){
                        stringstream notakestring;
                        notakestring << notake;
                        string notakestringjadi = notakestring.str();
                        ofstream bukanota("NOTA0"+notakestringjadi+".txt");
                        if(bukanota.is_open()){
                            bukanota<<"=============================="<<endl;
                            bukanota<<"            NOTA0"<<notake<<endl;
                            bukanota<<"=============================="<<endl;
                            bukanota<<"Pembeli : "<<username<<endl;
                            bukanota<<"=============================="<<endl;
                            for(int i=0;i<=user_cart.size()-1;i++){
                                bukanota<<i+1<<". "<<nama_barang[user_cart[i]-1]<<" x "<<jumlah_cart[i]<<" buah = "<<harga_barang[user_cart[i]-1]*jumlah_cart[i]<<endl;
                            }
                            bukanota<<"=============================="<<endl;
                            bukanota<<"Total Pembayaran = Rp"<<total;
                            bukanota.close();
                        }
                    }
                    else{
                        stringstream notakestring;
                        notakestring << notake;
                        string notakestringjadi = notakestring.str();
                        ofstream bukanota("NOTA"+notakestringjadi+".txt");
                        if(bukanota.is_open()){
                            bukanota<<"=============================="<<endl;
                            bukanota<<"            NOTA"<<notake<<endl;
                            bukanota<<"=============================="<<endl;
                            bukanota<<"Pembeli : "<<username<<endl;
                            bukanota<<"=============================="<<endl;
                            for(int i=0;i<=user_cart.size()-1;i++){
                                bukanota<<i+1<<". "<<nama_barang[user_cart[i]-1]<<" x "<<jumlah_cart[i]<<" buah = "<<harga_barang[user_cart[i]-1]*jumlah_cart[i]<<endl;
                            }
                            bukanota<<"=============================="<<endl;
                            bukanota<<"Total Pembayaran = Rp"<<total;
                            bukanota.close();
                        }
                    }
                    notake++;
                    ofstream nomornota("nonota.txt");
                    if(nomornota.is_open()){
                        nomornota<<notake;
                        nomornota.close();
                    }
                    saldo=saldo-total;
                    user_cart.clear();
                    jumlah_cart.clear();
                    savinguser(saldo,user_cart,jumlah_cart,username);
                }
                else{
                    cout<<"saldo tidak cukup";
                }
            }
            else if(inputan_user==4){
                saldo=saldo+10000;
                savinguser(saldo,user_cart,jumlah_cart,username);
            }
            else if(inputan_user==0){
                loginuser=false;
                loggedin=false;
            }
        }
        else if(loginadmin==true){
            int inputan;
            cout<<"Welcome, Admin"<<endl;
            cout<<"1. Add barang"<<endl;
            cout<<"2. Edit Barang"<<endl;
            cout<<"3. Delete barang"<<endl;
            cout<<"4. Exit"<<endl;
            cout<<">>";
            cin>>inputan;
            if(inputan==1){
                string nambar;
                int habar;
                cout<<"nama barang : ";
                cin>>nambar;
                cout<<"harga barang : ";
                cin>>habar;
                nama_barang.push_back(nambar);
                harga_barang.push_back(habar);
                ofstream listbarang("listbarang.txt");
                if(listbarang.is_open()){
                    for(int i=0;i<=nama_barang.size()-1;i++){
                        listbarang<<nama_barang[i]<<endl;
                        listbarang<<harga_barang[i];
                        if(i != nama_barang.size() - 1) listbarang<< endl;
                    }
                    listbarang.close();
                }
            }
            else if(inputan==2){
                int edit;
                string edit_nama;
                int edit_harga;
                for(int i=0;i<=nama_barang.size()-1;i++){
                    cout<<i+1<<". "<<nama_barang[i]<<" - "<<harga_barang[i]<<endl;
                }
                cout<<"0. Exit"<<endl;
                cout<<"Barang apa yang mau diedit?"<<endl;
                cout<<">>";
                cin>>edit;
                if(edit==0){

                }
                else{
                    cout<<"nama barang baru : ";
                    cin>>edit_nama;
                    cout<<"harga barang baru : ";
                    cin>>edit_harga;
                    nama_barang[edit-1]=edit_nama;
                    harga_barang[edit-1]=edit_harga;
                    ofstream listbarang("listbarang.txt");
                    if(listbarang.is_open()){
                        for(int i=0;i<=nama_barang.size()-1;i++){
                            listbarang<<nama_barang[i]<<endl;
                            listbarang<<harga_barang[i];
                            if(i != nama_barang.size() - 1) listbarang<< endl;
                        }
                        listbarang.close();
                    }
                }
            }
            else if(inputan==3){
                int delet;
                for(int i=0;i<=nama_barang.size()-1;i++){
                    cout<<i+1<<". "<<nama_barang[i]<<" - "<<harga_barang[i]<<endl;
                }
                cout<<"0. Exit"<<endl;
                cout<<"Barang apa yang mau didelete?"<<endl;
                cout<<">>";
                cin>>delet;
                if(delet==0){

                }
                else{
                    nama_barang.erase(nama_barang.begin()+delet-1);
                    harga_barang.erase(harga_barang.begin()+delet-1);
                    ofstream listbarang("listbarang.txt");
                    if(listbarang.is_open()){
                        for(int i=0;i<=nama_barang.size()-1;i++){
                            listbarang<<nama_barang[i]<<endl;
                            listbarang<<harga_barang[i];
                            if(i != nama_barang.size() - 1) listbarang<< endl;
                        }
                        listbarang.close();
                    }
                }
            }
            else if(inputan==4){
                loginadmin=false;
                loggedin=false;
            }
        }
    }
    return 0;
}

