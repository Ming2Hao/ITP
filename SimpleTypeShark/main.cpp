#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <vector>

using namespace std;

void arena(string tampil[],string &jawaban,bool &salah,string &jawabansementara,int menit1,int menit2,int detik1,int detik2,bool tampilkanhiu[],int hiux[],int hiuy[],bool showsoal[],int temptimer){
    cout<<"time "<<menit1<<menit2<<":"<<detik1<<detik2<<endl;
    if(temptimer==15){
        showsoal[0]=true;
        tampilkanhiu[0]=true;
    }
    if(temptimer==30){
        showsoal[1]=true;
        tampilkanhiu[1]=true;
    }
    if(temptimer==45){
        showsoal[2]=true;
        tampilkanhiu[2]=true;
    }
    if(temptimer==60){
        showsoal[3]=true;
        tampilkanhiu[3]=true;
    }
    if(temptimer==75){
        showsoal[4]=true;
        tampilkanhiu[4]=true;
    }
    for(int i=1;i<=7;i++){
        for(int j=1;j<=22;j++){
            if(i==1||i==7||j==1||j==22){
                cout<<"*";
            }
            else if(j==3){
                cout<<"|";
            }
            else if(tampilkanhiu[0]==true&&i==hiuy[0]&&j==hiux[0]){
                cout<<"1";
            }
            else if(tampilkanhiu[1]==true&&i==hiuy[1]&&j==hiux[1]){
                cout<<"2";
            }
            else if(tampilkanhiu[2]==true&&i==hiuy[2]&&j==hiux[2]){
                cout<<"3";
            }
            else if(tampilkanhiu[3]==true&&i==hiuy[3]&&j==hiux[3]){
                cout<<"4";
            }
            else if(tampilkanhiu[4]==true&&i==hiuy[4]&&j==hiux[4]){
                cout<<"5";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    if(salah==true){
        cout<<"Tidak ada kata yang cocok!!!"<<endl;
    }
    if(showsoal[0]==true){
        cout<<"1. "<<tampil[0]<<endl;
    }
    else{
        cout<<"1. -"<<endl;
    }
    if(showsoal[1]==true){
        cout<<"2. "<<tampil[1]<<endl;
    }
    else{
        cout<<"2. -"<<endl;
    }
    if(showsoal[2]==true){
        cout<<"3. "<<tampil[2]<<endl;
    }
    else{
        cout<<"3. -"<<endl;
    }
    if(showsoal[3]==true){
        cout<<"4. "<<tampil[3]<<endl;
    }
    else{
        cout<<"4. -"<<endl;
    }
    if(showsoal[4]==true){
        cout<<"5. "<<tampil[4]<<endl;
    }
    else{
        cout<<"5. -"<<endl;
    }
    cout<<"Jawaban : ";
    cout<<jawabansementara;
    if (kbhit()){
        char tombol=getch();
        if(tombol==13){
            jawaban=jawabansementara;
            while(jawabansementara.length()!=0){
                jawabansementara.pop_back();
            }
        }
        else if(tombol==8){
            if(jawabansementara.length()!=0){
                jawabansementara.pop_back();
            }
        }
        else{
            jawabansementara=jawabansementara+tombol;
        }
    }
}

void randomawal(int soal[]){
    soal[0]=rand()%11;
    soal[1]=rand()%10+11;
    soal[2]=rand()%10+21;
    soal[3]=rand()%10+31;
    soal[4]=rand()%9+41;
}

void hiuawal(int hiuy[]){
    hiuy[0]=rand()%5+2;
    hiuy[1]=rand()%5+2;
    hiuy[2]=rand()%5+2;
    hiuy[3]=rand()%5+2;
    hiuy[4]=rand()%5+2;
    while(hiuy[0]==hiuy[1]){
        hiuy[1]=rand()%5+2;
    }
    while(hiuy[2]==hiuy[0]||hiuy[2]==hiuy[1]){
        hiuy[2]=rand()%5+2;
    }
    while(hiuy[3]==hiuy[0]||hiuy[3]==hiuy[1]||hiuy[3]==hiuy[2]){
        hiuy[3]=rand()%5+2;
    }
    while(hiuy[4]==hiuy[0]||hiuy[4]==hiuy[1]||hiuy[4]==hiuy[2]||hiuy[4]==hiuy[3]){
        hiuy[4]=rand()%5+2;
    }
}
void kunci(string jawaban,string tampil[],string katakata[],bool &salah,int temptimer,int pencetenter[],bool tampilkanhiu[],int hiux[],int hiuy[],bool showsoal[],int cds){
    for(int i=0;i<=4;i++){
        if(jawaban==tampil[i]){
            if(i==0){
                pencetenter[i]=temptimer+(15-cds);
                tampil[i]="-";
                tampilkanhiu[i]=false;
                showsoal[i]=false;
            }
            else if(i==1){
                pencetenter[i]=temptimer+(15-cds);
                tampil[i]="-";
                tampilkanhiu[i]=false;
                showsoal[i]=false;
            }
            else if(i==2){
                pencetenter[i]=temptimer+(15-cds);
                tampil[i]="-";
                tampilkanhiu[i]=false;
                showsoal[i]=false;
            }
            else if(i==3){
                pencetenter[i]=temptimer+(15-cds);
                tampil[i]="-";
                tampilkanhiu[i]=false;
                showsoal[i]=false;
            }
            else if(i==4){
                pencetenter[i]=temptimer+(15-cds);
                tampil[i]="-";
                tampilkanhiu[i]=false;
                showsoal[i]=false;
            }
            else{
                salah=true;
            }
        }
        if(temptimer==pencetenter[i]){
            string sebelumnya;
            if(i==0){
                hiux[i]=21;
                hiuy[i]=rand()%5+2;
                tampilkanhiu[i]=true;
                showsoal[i]=true;
                salah=false;
                sebelumnya=tampil[i];
                tampil[i]=katakata[rand()%11];
                while(sebelumnya==tampil[i]){
                    tampil[i]=katakata[rand()%11];
                }
            }
            else if(i==1){
                hiux[i]=21;
                hiuy[i]=rand()%5+2;
                tampilkanhiu[i]=true;
                showsoal[i]=true;
                salah=false;
                sebelumnya=tampil[i];
                tampil[i]=katakata[rand()%10+11];
                while(sebelumnya==tampil[i]){
                    tampil[i]=katakata[rand()%10+11];
                }
            }
            else if(i==2){
                hiux[i]=21;
                hiuy[i]=rand()%5+2;
                tampilkanhiu[i]=true;
                showsoal[i]=true;
                salah=false;
                sebelumnya=tampil[i];
                tampil[i]=katakata[rand()%10+21];
                while(sebelumnya==tampil[i]){
                    tampil[i]=katakata[rand()%10+21];
                }
            }
            else if(i==3){
                hiux[i]=21;
                hiuy[i]=rand()%5+2;
                tampilkanhiu[i]=true;
                showsoal[i]=true;
                salah=false;
                sebelumnya=tampil[i];
                tampil[i]=katakata[rand()%10+31];
                while(sebelumnya==tampil[i]){
                    tampil[i]=katakata[rand()%10+31];
                }
            }
            else if(i==4){
                hiux[i]=21;
                hiuy[i]=rand()%5+2;
                tampilkanhiu[i]=true;
                showsoal[i]=true;
                salah=false;
                sebelumnya=tampil[i];
                tampil[i]=katakata[rand()%9+41];
                while(sebelumnya==tampil[i]){
                    tampil[i]=katakata[rand()%9+41];
                }
            }
        }
    }
}
int main()
{
    srand(time(NULL));
    string katakata[50]={"yes","no","signal","patient","black","white","purple","yellow","orange","bag",
                "mouse","keyboard","love","you","fire","one","desire","two","three","four",
                "five","six","seven","eight","nine","ten","eleven","twelve","chair","table",
                "desk","trash","can","bin","water","van","big","small","old","young",
                "good","bee","dog","cat","mouse","ant","fly","high","low","window"};
    int soal[5];
    string jawaban;
    string jawabansementara;
    bool salah=false;
    randomawal(soal);
    //
    string tampil[5]={katakata[soal[0]],katakata[soal[1]],katakata[soal[2]],katakata[soal[3]],katakata[soal[4]]};
    bool keluar=false;
    while(keluar==false){
        int menu;
        cout<<"Welcome To Typershark"<<endl;
        cout<<"====================="<<endl;
        cout<<"1. Play"<<endl;
        cout<<"2. Highscore"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<">>";
        cin>>menu;
        system("cls");

        if(menu==1){
            bool tampilkanhiu[5]={false,false,false,false,false};
            int hiux[5]={21,21,21,21,21};
            int hiuy[5];
            hiuawal(hiuy);
            int pencetenter[5]={0,0,0,0,0};
            bool showsoal[5]={false,false,false,false,false};
            bool bermain=true;
            string nama;
            string jawabansebelumnya;
            int timer=0;
            int temptimer=0;
            int menit=0;
            int menit1=0;
            int menit2=0;
            int detik=0;
            int detik1=0;
            int detik2=0;
            int jalan=0;
            int cds=0;
            cout<<"Enter your name : ";
            cin>>nama;
            for(int i=1;i<=3;i++){
                cout<<i<<"..";
                for(int j=1;j<=10;j++){
                    Sleep(100);
                }
            }
            system("cls");
            while(bermain==true){

                string jawaban;
                Sleep(100);
                temptimer++;
                arena(tampil,jawaban,salah,jawabansementara,menit1,menit2,detik1,detik2,tampilkanhiu,hiux,hiuy,showsoal,temptimer);
                kunci(jawaban,tampil,katakata,salah,temptimer,pencetenter,tampilkanhiu,hiux,hiuy,showsoal,cds);
                if(temptimer%10-jalan==0){
                    for(int i=0;i<=4;i++){
                        if(tampilkanhiu[i]==true){
                            hiux[i]=hiux[i]-1;
                        }
                    }
                }
                if (temptimer%100==0){
                    jalan++;
                    if(jalan>=9){
                        jalan=9;
                    }
                }
                if(temptimer%100==0){
                    cds++;
                    if(cds>=14){
                        cds=14;
                    }
                }
                if (temptimer%10==0){
                    timer++;
                    menit=timer/60;
                    detik=timer%60;
                    detik1=detik/10;
                    detik2=detik%10;
                    menit1=menit/10;
                    menit2=menit%10;
                }
                if(hiux[0]==3||hiux[1]==3||hiux[2]==3||hiux[3]==3||hiux[4]==3){
                    cout<<endl<<"GAME OVER!"<<endl;
                    system("pause");
                    bermain=false;
                }
                system("cls");
            }
        }
        else if(menu==2){

        }
        else if(menu==3){
            keluar=true;
        }
    }
    return 0;
}
