#include <stdio.h>
#include <stdlib.h>

int count = 0;

int *merge(int *b, int *c, int n) {
  int i = 0, j = 0, k = 0;
  int a[n];
  while (i < n / 2 && j < (n - n / 2)) {
    count++;
    if (*(b + i) < *(c + j)) {
      *(a + k) = *(b + i);
      i++;
    } else {
      *(a + k) = *(c + j);
      j++;
    }
    k++;
  }

  if (i == (n / 2)) {
    while (j < (n - n / 2)) {
      *(a + k) = *(c + j);
      j++;
      k++;
    }
  } else {
    while (i < (n / 2)) {
      *(a + k) = *(b + i);
      i++;
      k++;
    }
  }

  for (int i = 0; i < n; i++) {
    *(b + i) = a[i];
  }

  return b;
}

int *merge_sort(int *a, int n) {
  if (n == 1) {
    return a;
  }
  count++;
  int m = n / 2;
  int *b = merge_sort(a, m);
  int *c = merge_sort(a + m, n - m);
  a = merge(b, c, n);
  return a;
}

void bin_search(int *a, int n, int s) {
  if (n == 0) {
    printf("Element not found\n");
    return;
  }
  count++;
  int m = n / 2;
  if (*(a + m) > s) {
    if (n / 2 == 1 && m == 1) {
      printf("Element not found\n");
      return;
    }
    bin_search(a, n / 2, s);
  } else if (*(a + m) < s) {
    if ((n - n / 2) == 1 && m == 1) {
      printf("Element not found\n");
      return;
    }
    bin_search(a + m, n - n / 2, s);
  } else
    printf("The element has been found\n");
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

  int *b = merge_sort(a, n);
  printf("Asymptotic analysis: %d\n", count);

  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  int s;
  count = 0;

  printf("Enter the element to be searched in the array:");
  scanf("%d", &s);

  bin_search(a, n, s);

  printf("Asymptotic analysis: %d\n", count);

  return 0;
}
