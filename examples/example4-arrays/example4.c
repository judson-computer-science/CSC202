
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFF_SIZE 30
#define MAX_STRING_LENGTH 20
#define NUM_STRINGS 5

struct String {
	int length;
	char buff[BUFF_SIZE];	
};

void set_struct_values(struct String *, char *);

int main() {
	
	int i;
	char strings[NUM_STRINGS][MAX_STRING_LENGTH] = {"testing", "hello", "good-bye", "CSC202", "is fun!!"};
	struct String * struct_array[NUM_STRINGS];

	for(i = 0; i < NUM_STRINGS; i++) {
		struct_array[i] = (struct String *) malloc(sizeof(struct String));
		memset(struct_array[i], 0, sizeof(struct String));

		set_struct_values(struct_array[i], strings[i]);

		printf("The length of element [%s] is %d\n", struct_array[i]->buff, struct_array[i]->length);
	}


	return(0);
}

void set_struct_values(struct String * string_ptr, char * input) {

	// copy the input into the buffer and determine the length
	strcpy(string_ptr->buff, input);
	string_ptr->length = strlen(string_ptr->buff);
}