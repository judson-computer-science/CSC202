// example2.c
//
// author: Patrick Stephen
//
// description:
// this program will tokenize a pre-defined string and
// compare each token with a value that is supplied by
// the user.
//
// returns  0: when a match was found
// returns -1: when a match was not found

#include <stdio.h>
#include <string.h>

// return values and buffer size
#define BUFF_SIZE 30
#define RV_SUCCESS 0
#define RV_FAILURE -1

// function prototype
void get_search_str(char *);

int main() {
	
	char string_buff[BUFF_SIZE] = "key-value-testing-test";
	char string_buff_cp[BUFF_SIZE];
	char search_string[BUFF_SIZE];
	char * next_token;
	char output_buff[2 * BUFF_SIZE];

	// make a copy of the buffer before tokenizing
	strcpy(string_buff_cp, string_buff);

	// pass by copy of the address
	get_search_str(search_string);
	printf("Searching for [%s]\n", search_string);

	// tokenize the string
	next_token = strtok(string_buff, "-\n");

	while(next_token != NULL) {

		printf("Next token is: %s\n", next_token);

		// compare the token against the input
		if(strcmp(next_token, search_string) == 0) {

			// we found the match so we are done
			printf("Match!\n\n");
			return(RV_SUCCESS);
		} else {

			// no match, keep looking
			printf("No Match!\n\n");
		}

		// get the next token (if it exists)
		next_token = strtok(NULL, "-\n");
	}

	// prepare the output string
	sprintf(output_buff, "No match found in %s\n", string_buff_cp);
	printf("%s", output_buff);

	// if we make it this far we did not find a match
	return(RV_FAILURE);
}

// prompt the user for input and return it
void get_search_str(char * user_input) {
	
	printf("What string would you like to search for?: ");
	
	scanf("%s", user_input);

	printf("\n\n");
}