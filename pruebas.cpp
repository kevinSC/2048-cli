#include <iostream>

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
int main(int argc, char const *argv[]) {
	int arrays[4] = {2,2,0,2};
	apilar(false, arrays);
	merge(false, arrays);
	
	for (int i = 0; i < 4; i++)
		std::cout << arrays[i] << " ";
	return 0;
}
