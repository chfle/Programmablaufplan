#include <stdio.h>

int main() {
	int age;

	// enter age
	scanf("%d", &age);

	if (age >= 18) {
		printf("Adult\n");
	} else {
		printf("Minor\n");
	}

	return 0;
}
