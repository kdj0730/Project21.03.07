#include <stdio.h>

int add(int a, int b) {
	return a + b;
};

int(*mul(int c, int d))(int, int) {
	printf("%d\n",c * d);
	return add;
}

int main(void) {
	int(*f)(int, int) = add;
	//int(*f2)((int, int)(int,int)) = mul;
	printf("%d\n", f(3, 6));
	printf("%d\n", mul(3, 6)(3,6));
	system("pause");
}