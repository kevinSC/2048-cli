#include <iostream>
#include <cstdlib>
#include<time.h>

using namespace std;
class juego{
private:

public:
int m[4][4], (*p)[4];
juego(){
  for (int i=0;i<4;i++)
      for(int j=0;j<4;j++)
          m[i][j]=0;
 }
void generarN(int m[4][4]){
    srand(time(NULL));
    int i,j,N;
    bool vacio=false, genero=false;
    while(vacio==false){
        i=rand()%4;
        j=rand()%4;
        if(m[i][j]==0){
            while(genero==false){

                N=2+rand()%(5-2);
                if (N%2==0){
                    m[i][j]=N;
                    genero=true;
                    break;
                }

            }
            vacio=true;
            break;
        }
    }

}
void apilar(bool direccion, int (*p)) {
    for (int i = 0, c = 0; i < 4; i++) {
        if (p[i] != 0) {
            p[c] = p[i];
            p[i] = 0;
            c++;
        }
    }
}
void mover(int m[4][4]){
    char mo;
    int caso,n;
    bool acabar=false;
    cout<<"se mueve con las teclas W,A,S,D"<<endl;
    while(acabar==false){
        cin>>mo;
        if(mo==87 || mo==117){
            caso=1;
        }
        else if(mo==83 || mo==115){
            caso=2;
        }
        else if (mo==68 || mo==100){
            caso=3;
        }
        else if (mo==65 || mo==97){
            caso=4;
        }
        else{
            cout<<"tecla no valida"<<endl;
        }
        switch(caso){
        case 1:
            for(int i=0; i < 4; i++) {
                m[][]
            }
        }
    }


}

void imprimir(int m[4][4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(m[i][j]==0){
                cout<<"_";
            }
            else{
                cout<<m[i][j];
            }
        }
        cout<<endl;
    }
}


};
main(){

}