#include <stdio.h>

int main(void) {
	long a[2][2][3] = { { {1,2,3},{4,5,6} }, { {7,8,9},{10,11,12} } };
	//int a[3] = {1,2,3};
	printf("%d\n", a[0]);
	long (*p)[3] = a[0][0];
	printf("%d\n", p);
	for (int i = 0; i < 3; i++) {
		printf("%d\n", &p[i][0]);
		printf("%d\n", p[0][i]);
	}
	system("pause");
}