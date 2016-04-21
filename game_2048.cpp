#include <iostream>
#include <cstdlib>
#include <time.h>
class Grilla {
 public:
    Grilla() {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                matriz[i][j] = 0;
    }

    void generarN(){
        srand(time(NULL));
        int i,j,N;
        bool vacio=false, genero=false;
        while (vacio==false) {
            i=rand()%4;
            j=rand()%4;
            if(matriz[i][j]==0){
                while(genero==false) {
                    N=2+rand()%(5-2);
                    if (N%2==0){
                        matriz[i][j]=N;
                        genero=true;
                        break;
                    }
                }
                vacio=true;
                break;
            }
        }
    }
    void get_matriz(int (*m)[4]) {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
               m[i][j] = matriz[i][j];
    }
    void apilar(bool direccion, int (*p)) {
        if (direccion) {
            for (int i = 0, c = 0; i < 4; i++) {
                if (p[i] != 0) {
                    p[c] = p[i];
                    p[i] = 0;
                    c++;
                }
            }
        } else {
            for (int i = 4, c = 4; i < 4; i--) {
                if (p[i] != 0) {
                    p[c] = p[i];
                    p[i] = 0;
                    c--;
                }
            }
        }
    }

    void mover() {
        char mo;
        int caso,n;
        bool acabar=false;
        std::cout<<"se mueve con las teclas W,A,S,D"<<std::endl;
        while (acabar==false) {
            std::cin>>mo;
            if(mo==87 || mo==117)
            else if(mo==83 || mo==115)
                caso=2;
            else if (mo==68 || mo==100)
                caso=3;
            else if (mo==65 || mo==97){
                for (int i = 0; i < 4; ++i) {
                    char linea[4];
                    for (int j = 0; j < 4; ++j) {
                        li
                    }
                }
            }
        
            else
                std::cout<<"tecla no valida"<<std::endl;
    }


}
 private:
    int matriz[4][4];
};
int main(int argc, char const *argv[]) {
    int matriz[4][4];
    Grilla game;
    game.generarN();
    game.generarN();
    game.generarN();
    game.generarN();
    game.generarN();
    game.generarN();
    game.get_matriz(matriz);
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j)
            std::cout << matriz[i][j] << " ";
        std::cout << std::endl;
    }
    return 0;
}
