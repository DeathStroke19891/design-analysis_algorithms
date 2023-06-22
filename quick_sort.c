#include <stdio.h>
#include <stdlib.h>

int count = 0;

int rearrange (int* a, int n){
  int i = 1, j = n-1;
  int p = *(a);
  while(i<=j){  
    while(*(a+i)<p && i < n){
      count++;
      i++;
    }
    while(*(a+j)>p && j > -1){
      count++;
      j--;
    }
    if(i<j){
      int temp = *(a+i);
      *(a+i) = *(a+j);
      *(a+j) = temp;
    }
  }
  int temp = *(a);
  *(a) = *(a+j);
  *(a+j) = temp;
  return j;
}

int* quick_sort(int* a, int n){
  if(n==0){
    return a;
  }
  int p = rearrange(a,n);
  count++;
  quick_sort(a, p);
  quick_sort(a+p+1, n-p-1);
  return a;
}

int main() {
  int n;
  printf("Enter the number of elements in the array:");
  scanf("%d", &n);
  int a[n];

  for (int i = 0; i < n; i++) {
    printf("Enter the %d element into the array:", i);
    scanf("%d", &a[i]);
  }

  int *b = quick_sort(a, n);
  printf("Asymptotic analysis: %d\n", count);

  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
