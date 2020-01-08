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

int main(int argc, char *argv[]) { 
  int i, returnValue;
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

  const char ALPHALOWER[] = "abcdefghijklmnopqrstuvwxyz";
  const char ALPHAUPPER[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const char NUMBER[]     = "0123456789";
  const char SPECIAL[]    = "!@#$%*=+?~";
  int pwLength = 13;
  const int MAXPWLENGTH = 200;
  char pw[MAXPWLENGTH];
  char pool[72]; // 26+26+10+10
  int seed = time(NULL);
  int r;

  srand(seed); // Initalize the random number generator.
  strcpy(pool,ALPHALOWER);
  strcat(pool,ALPHAUPPER);
  strcat(pool,NUMBER);
  strcat(pool,SPECIAL);
  int l = strlen(pool);
   printf("Pool = %s; length = %i\n", pool, l);

  for (i = 0; i < pwLength; i = i + 1) {
    r = rand() % l; // Return random number between 0 and 25?
    // printf("i = %i ; r = %i -> %c\n", i, r, pool[r]);
    pw[i] = pool[r];
  }

  for (i = 0; i < pwLength; i = i + 1) {
    printf("%c", pw[i]);
  }
  printf("\n"); 

  // printf("%s\n", pw);
  // printf("%s", pw);
  return returnValue;
} 


