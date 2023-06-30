#include <stdio.h>
#include <string.h>


int pertenceL(int n, char w[], int length){

  int aux[3] = {0, 0, 0};


  for(int i = 0;i<length;i++){

    switch (w[i]) {
      case '0':
        aux[0]++;
      break;

      case '1':
        aux[1]++;
      break;

      case '2':
        aux[2]++;
      break;

    }
 }//for

 if(aux[0] == aux[1] && aux[1] == aux[2]){
   printf("%s pertence a L\n",w);
   return 1;
 }else{
   printf("%s não pertence a L\n",w);
   return 0;
 }
}

int main() {

//Sessão 1
  int p = 0;
  int length;
  int top = 0;

  printf("L = {0^n 1^n 2^n | n >= 0}\n");

 while(p <= 0){
  printf("Insira o valor de p:");
  scanf("%i",&p);
  }

  length = 3*p;


  char word[length];
  word[length] = '\0';

  for(int i = 0;i<length;i++){
    if(i>=0 && i<length/3){
      word[top] = '0';
      top++;
    }else if (i>=length/3 && i<(2*length)/3) {
      word[top] = '1';
     top++;
   }else{
     word[top] = '2';
    top++;
   }
  }

//n = p

int sizeu = 1;//tamanho de u

char u[sizeu];
u[sizeu] = '\0';

for(int i = 0;i<sizeu;i++){
  u[i] = word[i];//preenchimento de u
}
int sizev;
if(p == 1){
  sizev = 1;
}else{
sizev = p - sizeu;//tamanho de v
}
char v[sizev];

v[sizev] = '\0';

for(int i = 0;i<sizev;i++){
  v[i] = word[i+sizeu];//preenchimento de v
}

int sizew = length - sizev;//tamanho de w
char w[sizew];
w[sizew] = '\0';

for(int i = 0;i<sizew;i++){
    w[i] = word[i+sizeu+sizev];//preenchimento de w
  }


//Sessão 2
  printf("\nLema do bombeamento:\n");
  printf("P = %i\n",p);
  printf("W = %s\n",word);
  printf("u = %s\nv = %s\nw = %s\n\n",u,v,w);

  printf("---------------------------------------------------------\n\n");

  printf("Toda linguagem regular deve cumprir os 3 requisitos:\n");
  printf("1) |uv| <= %i\n",p);
  printf("2) |v| >= 1\n");
  printf("3) Para todo i>= 0, uv^iw deve pertencer a L\n\n");

int verify[3];
//primeira iteração
printf("Bombeando:\nuv^iw\n");

printf("i = 0");

char i0[sizeu];

for(int i = 0;i<=sizeu;i++){
  i0[i] = u[i];
}
strcat(i0,w);

printf("\nW = %s\n",i0);
int size0 = sizeu + sizew;
verify[0]= pertenceL(p,i0,size0);

//segunda iteração
printf("\ni = 1");

char i1[sizeu];

for(int i = 0;i<=sizeu;i++){
  i1[i] = u[i];
}

strcat(i1,v);
strcat(i1,w);

printf("\nW = %s\n",i1);
int size1 = sizeu + sizew + sizev;

verify [1]= pertenceL(p,i1,size1);

//terceira iteração
printf("\ni = 2");

char i2[sizeu];

for(int i = 0;i<=sizeu;i++){
  i2[i] = u[i];
}

strcat(i2,v);
strcat(i2,v);
strcat(i2,w);

printf("\nW = %s\n",i2);
int size2 = sizeu + sizew + 2*sizev;

verify[2]= pertenceL(p,i2,size2);

printf("\n---------------------------------------------------------\n");
//Sessão 3

int soma = 0;

for(int i=0;i<3;i++){
  soma += verify[i];
}

  if(soma == 3){
    printf("A linguagem é regular");
  }else{
    printf("\nA linguagem nao e regular\n\n");
  }

    return 0;
}
