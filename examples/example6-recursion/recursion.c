#include <stdio.h>

#define MAX_VALUE 5

int increment(int);

int main() {

	int start_value = 0;
	int new_value = 0;

	new_value = increment(start_value);

	printf("the final value is %d\n", new_value); // new value is 5

	return(0);
}

int increment(int value) {

	printf("value is %d\n", value);

	if(value < MAX_VALUE) {
		return increment(value + 1);
	} else {
		return value;
	}

}