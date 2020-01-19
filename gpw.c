/*
Program: gpw.c
Purpose: generate a password 
Author:  Jan Hartstra
Version: 0.1
Compile: gcc -o gpw gpw.c
Usage:   ./gpw 
         ./gpw > passwd.txt

To implement: 
  command line arguments
  -s <>, --seed=<>  : randomseed
  -l <>, --length=<> : length of the password
  -a,    --set=aAns
  -A,
  -n,
  -s, 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> // if seed dependend in time


const char ALPHALOWER[] = "abcdefghijklmnopqrstuvwxyz";
const char ALPHAUPPER[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char NUMBER[]     = "0123456789";
const char SPECIAL[]    = "!@#$%*=+?~";
const int MAXCHARSETLENGTH = 72;
const int MAXPWLENGTH   = 200;

char *generate(int length, char char_set[]);
void put (char str[], int len);

int main(int argc, char *argv[]) { 
  // Declare and initialize 
  int i;
  int returnValue = 0;
  int pwLength = 13; // Password length, default 13.
  int seed = time(NULL); // Seed for random generator, default taken from system time.

  if( argc >= 2 ) {
    // printf("The arguments supplied are:\n");
    for(i = 1; i < argc; i++) {
        printf("%s\t", argv[i]);
    }
    returnValue=0;
  }
  else {
      // printf("argument list is empty.\n");
      returnValue=0;
  }

  srand(seed); // Initalize the random number generator.

  char pool[MAXCHARSETLENGTH]; 
  strcpy(pool,ALPHALOWER);
  strcat(pool,ALPHAUPPER);
  strcat(pool,NUMBER);
  strcat(pool,SPECIAL);

  // printf("%s\n", generate(pwLength, pool));

  char *pw=generate(pwLength, pool);
  put(pw, pwLength);

  return returnValue;
} 

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
  return(password);
}

void put (char str[], int len) {
  int i;

  for (i = 0; i < len; i = i + 1) {
    printf("%c", str[i]);
  }
  printf("\n"); 
}
