// example3.c
//
// author:  Patrick Stephen
//
// This function demonstrates the definition and use of structures.
// It also shows how memory can be allocated and then used as the
// memory address at which a structure can live.  Manipulation of 
// the structure's fields is performed using the structure directly
// as well as a pointer to the structure.

#include <stdio.h>   // for standar I/O operations
#include <string.h>  // for working with strings
#include <stdlib.h>  // for working with memory

#define BUFF_SIZE 30
#define RV_SUCCESS 0
#define RV_FAILURE -1

// NOTE: structure values cannot be initialized here
struct String
{
	int length;  // used to hold the length of the string in buff
	char buff[BUFF_SIZE];
};

// function prototypes
void set_struct_values(struct String * string_ptr);

int main() {

	char buff_in[BUFF_SIZE] = "new string value";

	// this is how we declare the structure and initialize its values
	struct String string1 = 
		{ sizeof("initial string val"), "initial string val" };

	// if you just want to declare a structure without initialization, you can
	struct String string2;

	printf("string1.length is %d, string1.buff is [%s]\n", 
		string1.length, string1.buff);

	// copy the new buffer value into the structure's buffer
	// and determine the length of the string
	strcpy(string1.buff, buff_in);
	string1.length = strlen(string1.buff);

	printf("string1.length is %d, string1.buff is [%s]\n", 
		string1.length, string1.buff);

	// we must pass the address of the structure since the function
	// takes a structure pointer (AKA: a strucutre's address)
	set_struct_values(&string1);

	printf("string1.length is %d, string1.buff is [%s]\n", 
		string1.length, string1.buff);


	// ----------------------------------------------------------
	// now let's do this again using dynamically allocated memory
	// ----------------------------------------------------------

	// first we declare a pointer to a structure
	struct String * string_ptr;

	// now let's allocate memory dynamically and point to it with the
	// pointer.  We are requesting enough memory for an entire
	// String structure.
	string_ptr = (struct String *) malloc(sizeof(struct String));

	// if we were not able to allocate the memory, end with failure
	if(string_ptr == NULL) {
		return(RV_FAILURE);
	}

	// it's a good practice to initialize the entire block of
	// memory to all 0s
	memset(string_ptr, 0, sizeof(struct String));

	// now copy the block of memory at the address pointed to
	// by buff_in to the address pointed to by string_ptr->buff.
	// The total bytes copied is the integer that results from
	// calling sizeof(buff_in), which is BUFF_SIZE.
	memcpy(string_ptr->buff, buff_in, sizeof(buff_in));
	string_ptr->length = strlen(string_ptr->buff);

	printf("string_ptr->length is %d, string_ptr->buff is [%s]\n", 
		string_ptr->length, string_ptr->buff);

	// notice the difference between the parameter passed in this call
	// versus the parameter passed in the first call (when we were not
	// dealing with a structure pointer)? 
	set_struct_values(string_ptr);

	printf("string_ptr->length is %d, string_ptr->buff is [%s]\n", 
		string_ptr->length, string_ptr->buff);

	// now free the memory that was allocated dynamically (never forget this)
	free(string_ptr);

	return(RV_SUCCESS);
}

// this function copies the input into the structure's buffer
// and sets the length field based on the length of the string.
//
// NOTE: that the arrow notation is used since we are dealing
// with a pointer to the structure, not the structure itself
void set_struct_values(struct String * string_ptr) {

	char input[BUFF_SIZE];

	// get the input from the user
	printf("Enter a String up to %d characters\n", BUFF_SIZE);
	scanf("%s", input);

	// copy the input into the buffer and determine the length
	strcpy(string_ptr->buff, input);
	string_ptr->length = strlen(string_ptr->buff);
}
