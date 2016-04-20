#include <iostream>
#include <cstdlib>
class Cuadro {
 public:
    Cuadro() {
        
    }
    ~Cuadro();
    void mover(int direction) {

    }
 private:
    int posX = 0;
    int posY = 0;
    int value = 0;
};
int main(int argc, char const *argv[]) {
    int matrix[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            matrix[i][j] = 0;
    Cuadro **cuadrado = new Cuadro* [0];
    cuadrado[0] = new Cuadro(1);
    cuadrado[1] = new Cuadro(1);
    cuadrado[2] = new Cuadro(1);
    cuadrado[3] = new Cuadro(1);
    std::cout << cuadrado[3]->posX;

    return 0;
}
