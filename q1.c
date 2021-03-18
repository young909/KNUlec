#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int bin_search(int* arr, int a, int b) {
	if (a <= b) {
		int mid = (a + b) / 2;
		if (arr[mid] == mid)
			return mid;
		else if (arr[mid] > mid)
			return bin_search(arr, a, mid - 1);
		else
			return bin_search(arr, mid + 1, b);
	}
	return 0;
}

int main(void)
{
	int tc;
	scanf("%d", &tc);

	while (tc--) {
		int n;
		int a = 0;
		scanf("%d", &n);
		int* arr = (int*)malloc(n * sizeof(int));
		for (int i = 0; i < n; i++) {
			int input; scanf("%d", &input);
			if (input < 0)
				a++;
			else
				arr[i] = input;
		}
		int ans = bin_search(arr, a, n - 1);

		if (ans)
			printf("%d\n", ans);
		else
			printf("NONE\n");
	}

	return 0;
}