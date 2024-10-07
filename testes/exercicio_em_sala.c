#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIMITE 100

void solicitartexto(char frase[LIMITE]);
void palindromecheck(char frase[LIMITE]);


int main () {
    char frase[LIMITE];
    solicitartexto(frase);
    palindromecheck(frase);
}

void solicitartexto(char frase[LIMITE]) {
    printf("digite algo de 1-99 caracteres: ");
    fgets(frase,LIMITE,stdin);
    printf("Voce digitou: %s",frase);
}

void palindromecheck(char frase[LIMITE]) {
int start = 0;
int end = strlen(frase) - 1;
if(frase[end] == '\n') {
    end--;
}
while(start < end) {
    if(frase[start] == ' ') {
        start++;
        continue;
    }
    if(frase[end] == ' ') {
        end--;
        continue;
    }
    char charstart = toupper(frase[start]);
    char charend = toupper(frase[end]);

    if(charstart != charend) {
        printf("A palavra não é um palindromo");
        return;
    }

    start++;
    end--;
}
printf("A palavra é um palindromo");
}