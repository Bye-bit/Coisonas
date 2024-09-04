#include <stdio.h>

int main(){
  double QTD[10];

  for (int a = 0; a < 10; ++a){
    printf("Digite os valores:");
    scanf("%lf", &QTD[a]);
    
    for (int b=0;b<=a;++b){
          
      if(QTD[a]<QTD[b]){
        double x = QTD[b];
        QTD[b]=QTD[a];
        QTD[a]=x;
      }
    }
  }
  for(int g; g != 10; g++){
    printf("%f\n",QTD[g]);
  }
  return 0;
}