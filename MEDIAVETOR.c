#include<stdio.h>
int main(){
int N, i, qtde = 0;
long int valores[10000];
float media = 0;
scanf("%d", &N);
for(i = 0; i < N; i++){
    scanf("%li", &valores[i]);
    media += valores[i];
}
for(i = 0; i < N; i++){
  if( (media/N) <  valores[i] ){
    printf("%li ", valores[i]);
    qtde++;
   }

}
if(qtde == 0){
    printf("0\n");
}
return 0;
}