#include <stdio.h>
#define QTD_ALUNOS 5
int notas[QTD_ALUNOS];
int main() {
    for(int i = 0; i <QTD_ALUNOS; i++) {
        printf("Digite a %d nota:",i+1);
        scanf("%lf",&notas[i]);
    }
    for(int i = 0; i < QTD_ALUNOS; i++) {
        printf("%da note = %.lf\n", i + 1,notas[1]);        
    }
    
}
   