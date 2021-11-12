#include <stdio.h>

int add(int a, int b) {
	return a + b;
}

int main() {
	int first, sec;

	// scan vars
	printf("Add a number:\n");
	scanf("%d", &first);

	printf("Add a number:\n");
	scanf("%d", &sec);

	int sol = add(first, sec);

	// out
	printf("Sol: %d\n", sol);

	return 0;

}
