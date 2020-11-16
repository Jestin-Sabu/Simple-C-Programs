//C program to perform polynomial addition
#include<stdio.h>
#include<malloc.h>


void read(int* e, int n){
  for(int i=n-1; i>=0; i--){
    printf("Enter the coefficient of x^%d : ", i);
    scanf("%d", &e[i]);
  }
}

int* add(int* e1, int* e2, int m, int n, int o){
  int* r = malloc(o*sizeof(r));
  for(int i=0; i<o; i++)
    r[i] = (i<m?e1[i]:0) + (i<n?e2[i]:0);
  return r;
}

void print(int* e, int n, char* poly){
  printf("\n%s : ", poly);
  for(int i = n; i>=0; i--)
    if(e[i] != 0){
      printf("%dx^%d",e[i], i);
      if(i != 0)
        printf(" + ");
    }
}

int main(void){
  int m, n, o;
  printf("Enter the highest degree in polynomial 1: ");
  scanf("%d", &m);
  printf("Enter the highest degree in polynomial 2: ");
  scanf("%d", &n);
  o = ++m>++n?m:n;
  int* e1 = malloc(m*sizeof(e1));
  int* e2 = malloc(n*sizeof(e2));
  printf("Polynomial 1\n");
  read(e1, m);
  printf("Polynomial 2\n");
  read(e2, n);
  int* r = add(e1, e2, m, n, o);
  print(e1, m, "P1");
  print(e2, n, "P2");
  print(r,o, "P1+P2");
  free(e1);
  free(e2);
  free(r);
  return 0;
}
