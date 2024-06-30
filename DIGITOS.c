#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void increment(char* s);

int main(){
  int N;
  scanf("%d", &N);

  char sequence[1005];
  char auxiliar[1005];
  char number_actual[1005];

  for (size_t i = 0; i < N; i++)
    scanf(" %c", &sequence[i]);

  sequence[N] = '\0';

  for(int t=1;t<=N;t++){
    int position = 0;
    int achieve = 1;

    strncpy(auxiliar,sequence,t);
    auxiliar[t] = '\0';

    strcpy(number_actual,auxiliar);

    while( position < N )
    {
      if(position + strlen(number_actual) - 1 >= N)
        { achieve=0; break; }

      for(int i = position; i< position + strlen(number_actual); i++)
        if( sequence[i] != number_actual[i-position] )
          { achieve=0; break; }

      if(!achieve)break;

      position += strlen(number_actual);
      increment(number_actual);
    }
    if(achieve)
      { printf("%s\n", auxiliar); return 0; }
  }
}


void increment(char* s){
  int carry = 1;
  int digit;
  for(int i = strlen(s)-1; i>=0; i--)
  {
    digit = (s[i] - '0') + carry;
    carry = 0;
    if(digit>=10)
      { carry=1;digit-=10; }
    s[i] = '0' + digit;
  }
  if(carry)
  {
    for(int i = strlen(s); i > 0; i--)
      s[i] = s[i - 1];
    s[0] = '1';
  }
}
