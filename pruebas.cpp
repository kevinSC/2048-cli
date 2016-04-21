#include <iostream>

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
		for (int i = 4, c = 4; i > -1; i--) {
	        if (p[i] != 0) {
	            p[c] = p[i];
	            p[i] = 0;
	            c--;
	        }
		}
 	}
 }
int main(int argc, char const *argv[]) {
	int arrays[4] = {0,4,2,0};
	apilar(false, arrays);
	for (int i = 0; i < 4; i++)
		std::cout << arrays[i] << " ";
	return 0;
}
