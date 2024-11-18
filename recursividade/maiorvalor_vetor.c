#include <stdio.h>
#define TAM_VETOR 1

int main() {

}

int maior_valor(int v[], int n) {
    if(n = 1)
    {
        return v[0];
    }
    int resp = maior_valor(v, n-1);
    if(v[n-1] > resp)
    {
        return v[n-1];
    }
    return resp;
}