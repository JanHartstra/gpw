/*
 * Program: gen.c
 * Purpose: provide function to generate a password 
 * Author:  Jan Hartstra
 * Version: 0.1
*/

#include <string.h>   // provides strlen()
#include <stdlib.h>   // provides calloc() and rand()
#include "gen.h"

/*
 * function to generate a password 
 * length = length of the password
 * charSet = set (array) of characters from which to choose from 
 */
char *generate(int length, char charSet[]) {
  int i, r;
  int charSetLen = strlen(charSet); // number of characters in the specified character set
  char *password = calloc(length, sizeof(char));  // allocate memory from the heap

  for (i = 0; i < length; i++) {
    r = rand() % charSetLen; // Return random number between 0 and number of characters -1
    password[i] = charSet[r];
  }
  return password; // Note that the function cannot return a local string variable, therefor the calloc function was used here.
} 
