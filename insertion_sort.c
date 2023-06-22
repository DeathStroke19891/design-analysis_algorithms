#include <stdio.h>
#include <stdlib.h>

int count = 0;

void insertion_sort(int *a, int n) {
  for (int i = 1; i < n; i++) {
    int key = *(a + i);
    int j = i - 1;
    while (j >= 0 && *(a + j) > key) {
      count++;
      *(a + j + 1) = *(a + j);
      j--;
    }
    *(a + j + 1) = key;
  }
  return;
}

int main() {
  int n = 0;
  printf("Enter the no of elements in the array:");
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) {
    printf("Enter the %dth element into the array:", i);
    scanf("%d", a + i);
  }
  insertion_sort(a, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  printf("Asymptotic analysis:%d\n", count);
  return 0;
}
