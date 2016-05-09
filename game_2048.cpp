#include <iostream>
#include <cstdlib>
#include <time.h>
class Grilla {
 public:
    Grilla() {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                matriz[i][j] = 0;
        generarN();
        generarN();
    }
    bool change(int (*m)[4]) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                if (matriz[i][j] != m[i][j])
                    return false;
            }
        return true;
    }
    void get_matriz(int (*m)[4]) {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
               m[i][j] = matriz[i][j];
    }

    void mover(int movimiento) {
        bool generar = false;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; j++)
                oldm[i][j] = matriz[i][j];
        switch (movimiento) {
            case 4:
                for (int i = 0; i < 4; i++) {
                    int line[4];
                    for (int j = 0; j < 4; j++)
                        line[j] = matriz[i][j];
                    apilar(true, line);
                    merge(true, line);
                    apilar(true, line);
                    for (int j = 0; j < 4; j++)
                        matriz[i][j] = line[j];
                }
                break;
            case 6:
                for (int i = 0; i < 4; i++) {
                    int line[4];
                    for (int j = 0; j < 4; j++)
                        line[j] = matriz[i][j];
                    apilar(false, line);
                    merge(false, line);
                    apilar(false, line);
                    for (int j = 0; j < 4; j++)
                        matriz[i][j] = line[j];
                }
                break;
            case 8:
                for (int i = 0; i < 4; i++) {
                    int line[4];
                    for (int j = 0; j < 4; j++)
                        line[j] = matriz[j][i];
                    apilar(true, line);
                    merge(true, line);
                    apilar(true, line);
                    for (int j = 0; j < 4; j++)
                        matriz[j][i] = line[j];
                }
                break;
            case 2:
                for (int i = 0; i < 4; i++) {
                    int line[4];
                    for (int j = 0; j < 4; j++)
                        line[j] = matriz[j][i];
                    apilar(false, line);
                    merge(false, line);
                    apilar(false, line);
                    for (int j = 0; j < 4; j++)
                        matriz[j][i] = line[j];
                }
                break;
        }
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; j++){
                if(oldm[i][j] != matriz[i][j]) {
                    generar = true;
                    break; 
                }
            }
            if (generar)
                break;
        }
        if (generar)
            generarN();
    }
    bool get_end() { return endi;}
 private:
    int matriz[4][4];
    int oldm[4][4];
    bool endi = false;

    void merge(bool direction, int *p) {
        if (direction) {
            for (int i = 0, c = 1; i < 4; i++, c++) {
                if (p[i] != 0) {
                    if(p[c] == p[i]) {
                        p[i] = (p[i])*2;
                        p[c] = 0;
                    }
                }
            }
        } else {
            for (int i = 3, c = 2; i >= 0; i--, c--) {
                if (p[i] != 0) {
                    if (p[c] == p[i]) {
                        p[i] = (p[i])*2;
                        p[c] = 0;
                    }
                }
            }
        }
    }

    void generarN() {
        srand(time(NULL));
        int i, j, N;
        int final = 0;
        bool vacio = false, genero = false;
        while (vacio == false) {
            i = rand() % 4;
            j = rand() % 4;
            if (matriz[i][j]==0) {
                while(genero == false) {
                    N = 2 + rand() % (5 - 2);
                    if (N % 2 == 0) {
                        matriz[i][j] = N;
                        genero = true;
                        break;
                    }
                }
                vacio = true;
                break;
            }
            final++;
            if (final == 200){
                endi = true;
                break;
            }
        }
    }

    void apilar(bool direccion, int (*p)) {
        if (direccion) {
            for (int i = 0, c = 0; i < 4; i++) {
                if (p[i] != 0) {
                    p[c] = p[i];
                    if (c != i)
                        p[i] = 0;
                    c++;
                }
            }
        } else {
            for (int i = 4, c = 4; i > -1; i--) {
                if (p[i] != 0) {
                    p[c] = p[i];
                    if (c != i)
                        p[i] = 0;
                    c--;
                }
            }
        }
    }
};
int main(int argc, char const *argv[]) {
    int movimiento;
    int matriz[4][4];
    int M[4][4];
    Grilla game;
    game.get_matriz(matriz);
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            M[i][j] = 0;

    while(true) {
        std::system("clear");
        for (int i = 0; i < 4; ++i){
            for (int j = 0; j < 4; ++j)
                std::cout << matriz[i][j] << " ";
            std::cout << std::endl;
        }
        std::cout << "por favor muevete con el cuadro numerico del pc: ";
        std::cin >> movimiento;
        game.mover(movimiento);
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                M[i][j] = matriz[i][j];
        game.get_matriz(matriz);
        if (game.get_end()) {
            std::cout << "el juego ha terminado";
            break;
        }
    }
    return 0;
}
