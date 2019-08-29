#include <stdio.h>

// declare the function prototype
void print_it();


int main() {

  // there are no strings in c
  char it_works[20];
  char it_works_init[20] = "still works\n";

  // call the function
  print_it();

  // populate the string
  sprintf(it_works, "%s", "it works\n");
  printf("%s", it_works);
  printf("%s", it_works_init);

  return(0);

}

void print_it() {

  // try entering a string that is longer than this
  char file_name[15];

  printf("Enter a file name: ");

  // get the user input from STDIN
  scanf("%s", file_name);
  printf("%s\n", file_name);

}
