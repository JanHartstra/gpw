/*
Program: gen.c
Purpose: provide function to generate a password 
Author:  Jan Hartstra
Version: 0.1
*/

#include <string.h>
#include <stdlib.h>

char *generate(int length, char charSet[]) {
  int i, r;
  // char password[length];
  int charSetLen = strlen(charSet);
  char *password = calloc(length, sizeof(char));  // allocate memory from the heap

  for (i = 0; i < length; i = i + 1) {
    r = rand() % charSetLen; // Return random number between 0 and 25?
    // printf("i = %i ; r = %i -> %c\n", i, r, pool[r]);
    password[i] = charSet[r];
  }
  return(password); // Note that the function cannot return a local string variable, therefor the calloc function was used here.
} 
