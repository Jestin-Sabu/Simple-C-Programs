//Program to perform matrix operation using dynamically allocated 2D array
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void read(int **m , int n)                              //read values from stdin
{
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    scanf("%d", &m[i][j]);
  }
}

void addition(int **m1, int **m2, int **result, int n)              //perform matrix addition
{
  printf("Enter the values for Matrix I\n");
  read(m1, n);
  printf("Enter the values for Matrix II\n");
  read(m2, n);
  for(int i = 0; i < n; i++)
  {
    for( int j = 0; j < n; j++)
      result[i][j] = m1[i][j] + m2[i][j];
  }
}

void multiplication(int **m1, int **m2, int **result, int n)      //perform matrix multiplication
{
  printf("Enter the values for Matrix I\n");
  read(m1, n);
  printf("Enter the values for Matrix II\n");
  read(m2, n);
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      result[i][j] = 0;
      for(int k = 0; k < n; k++)
        result[i][j] += m1[i][k] * m2[k][j];
    }
  }
}

void transpose(int **m, int **result, int n)                //finds the transpose of the matrix
{
  printf("Enter the values for the matrix\n");
  read(m, n);
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
      result[i][j] = m[j][i];
  }
}

void print(int **m, int n)
{
  printf("\nRESULT\n");
  printf("^^^^^^\n");
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
      printf("%d ", m[i][j]);
    printf("\n");
  }
}

int** create_matrix(int n)                             //creates a new matrix of required size
{
  int **m = malloc(n*sizeof(*m));
  if(m == NULL)
  {
    fprintf(stderr," Failed to allocate memory");
    exit(1);
  }
  for(int i = 0;i < n; i++)
    m[i] = malloc(n*sizeof(*m[i]));
  return m;
}

void free_matrix(int **m, int n)                      //deallocates memory
{
  for(int i = 0; i < n; i++)
    free(m[i]);
  free(m);
}

int main(void)
{
  int n, ch, flag = 1;
  int **m1, **m2, **result;
  while(flag)
  {
    printf("Enter the matrix dimension : ");
    scanf("%d",&n);
    m1 = create_matrix(n);
    m2 = create_matrix(n);
    result = create_matrix(n);
    printf("\n\nMATRIX OPERATIONS\n");
    printf("^^^^^^^^^^^^^^^^^\n\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Multipication\n");
    printf("3. Matrix Transpose\n");
    printf("4. Exit\n");
    printf("   Enter your Choice: ");
    scanf("%d", &ch);
    printf("\n");
    switch (ch)
    {
      case 1: addition(m1, m2, result,  n);
              print(result, n);
              break;
      case 2: multiplication(m1, m2, result, n);
              print(result, n);
              break;
      case 3: transpose(m1, result, n);
              print(result, n);
              break;
      case 4: flag = 0;
              break;
      default:  printf("Wrong Choice !!! \n");
                break;
    }
    free_matrix(m1, n);
    free_matrix(m2, n);
  }
  return 0;
}
