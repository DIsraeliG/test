#include <stdio.h>

int add(int, int);
int sub(int, int);
int mul(int, int);
int div(int, int);

int main(){
	printf("add(3, 4) = %d\n", add(3, 4));
	printf("sub(3, 4) = %d\n", sub(3, 4));
	printf("mul(3, 4) = %d\n", mul(3, 4));
	printf("div(3, 4) = %d\n", div(3, 4));

	return 0;
}
