#include <stdio.h>
#include <stdlib.h>

int count = 0;

void print(int* a, int n){
	for(int i = 0; i < n; i++){
		printf("%d ", *(a+i));
	}
	printf("\n");
}

int rearrange (int* a, int n){
	int i = 1, j = n-1;
	int p = *(a);
	printf("%d\n",p);
	print(a,n);
	while(i<j){
		if(*(a+i)<p){
			i++;
		}
		if(*(a+j)>p){
			j--;
		}
		if(*(a+i)< p && *(a+j) > p){
			int temp = *(a+i);
			*(a+i) = *(a+j);
			*(a+j) = temp;
		}
	}
	if(j==1){
		return j;
	}
	int temp = *(a);
	*(a) = *(a+j);
	*(a+j) = temp;
	return j;
}

int* quick_sort(int* a, int n){	
	if(n==1){
		return a;
	}
	int p =	rearrange(a,n);
	print(a,n);
	printf("%d\n",p);
	quick_sort(a, p);
	quick_sort(a+p, n-p);
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
