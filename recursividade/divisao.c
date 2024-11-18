#include <stdio.h>

int divisao(int a, int b);

int main() {
int a = 6;
int b = 2;
divisao(a,b);
}


int divisao(int a, int b) {
     if(a < b)
     {
        return 0;
     }
    return divisao(a-b,b) + 1;
}