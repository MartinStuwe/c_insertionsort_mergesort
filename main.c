#include <stdio.h>
#include <math.h>

void insertionsort(int *A, int size)
{
  for(int i = 1; i < size; i++)
  {
      int key = A[i];
      int j = i -1;
      while(j >= 0 && A[j] > key)
      {
	A[j + 1] = A[j];
	j = j - 1;
      }
      A[j + 1] = key;
  }
}

void merge(int *A, int p, int q, int r)
{
  int length_left = q - p + 1;
  int length_right = r - q;
  int L[length_left];
  int R[length_right];

  for(int i = 0; i < length_left; i++)
    {
      L[i] = A[p + i];
    }
  for(int j = 0; j < length_right; j++)
    {
      R[j] = A[q + j + 1];
    }
  int i = 0;
  int j = 0;
  int k = p;

  while(i < length_left && j < length_right)
    {
      if(L[i] <= R[j])
	{
	  A[k] = L[i];
	  i = i + 1;
	}
      else
	{
	  A[k] = R[j];
	  j = j + 1;
	}
      k = k + 1;
    }

  while(i < length_left)
    {
      A[k] = L[i];
      i = i + 1;
      k = k + 1;
    }
  while(j < length_right)
    {
      A[k] = R[j];
      j = j + 1;
      k = k + 1;
    }
}

void mergesort(int *A, int p, int r)
{
  if(p >= r)
    {
      return;
    }
  int q = floor((p + r) / 2);
  mergesort(A, p, q);
  mergesort(A, q + 1, r);

  merge(A, p, q, r);
}

int main(void)
{
  int A[4] = {4, 3, 2, 1};
  insertionsort(A, 4);
  for(int i = 0; i < 4; i++)
    printf("%d", A[i]);

  printf("\n");
  int B[4] = {4, 3, 2, 1};
  mergesort(B, 0, 3);
  for(int i = 0; i < 4; i++)
    printf("%d", B[i]);
  
}
