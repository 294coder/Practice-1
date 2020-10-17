#include "paixu.h"

//void bubble(int n[]) {
//
//}
void p_insert(int n[]) {
	int i = 1;
	int j = i - 1;
	int temp;
	int temp1;
	for (;i < NUM;i++) {
		for (;j < i;j++) {
			if (n[j] < n[i]) {
				temp1 = i - 1;
				temp = n[i];
				while (temp1 >= j) {
					n[temp1 + 1] = n[temp1];
					temp1--;
				}
				n[j] = temp;
				break;
			}
		}
		print(n);
		j = 0;
	}
}
void print(int n[]) {
	for (int i = 0;i < NUM;i++) {
		printf_s("%d ", n[i]);
	}
	printf_s("\n");
}

