/*
 * Program: gpw.c
 * Purpose: generate a password 
 * Author:  Jan Hartstra
 * Version: 0.1
 * Compile: gcc -o gpw gpw.c gen.c -I.
 * Usage:   ./gpw 
 */

#include <stdio.h>
#include <string.h>  /* provided strcpy() */
#include <stdlib.h>  /* provides funtions rand() and srand() */
#include <ctype.h>
#include <time.h>    /* provides time() used to specify different seed dependent on the system time */
#include <unistd.h>  /* provides getopt() */
#include "gen.h"

/* define the character sets to be used in the password(s) */
const char ALPHALOWER[] = "abcdefghijklmnopqrstuvwxyz";
const char ALPHAUPPER[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char NUMBER[]     = "0123456789";
const char SPECIAL[]    = "!@#$%*=+?~";
const int MAXCHARSETLENGTH = 72;  /* strlen(ALPHALOWER) + ... + strlen(SPECIAL) */

/* prototype(s) of functions defined beyond the main function */
void put (char str[], int len);
int cindex (char str[], char c);
void usage(void);

int main(int argc, char *argv[]) { 
   /* Declare and initialize */
   int pwLength = 13;              // Password length, 13 by default
   int seed = time(NULL);          // Seed for random generator, by default taken from system time
   char pool[MAXCHARSETLENGTH];    // Pool of characters from which to choose from for the password
   char pool_specifier[] = "LUNS"; // String specifying the character subsets from to choose from
   int number = 1;                 // Number of passwords, 1 by default

   /* process the command line arguments using the getopt() function from the unistd library */
   int option;
   while ((option = getopt(argc, argv, "hl:s:n:p:")) != -1) {
      switch (option) {
         case 'h' :
            usage();
            exit(0);
            break;
         case 'l' : 
            pwLength = atoi(optarg);
            break;
         case 's' :
            seed = atoi(optarg);
            break;
         case 'n' :
            number = atoi(optarg);
            break;
         case 'p' :
            strcpy(pool_specifier, optarg);
            break;
         default :
            fprintf(stderr, "option not recognized: %c\n", optopt);
            break;
      }
   }

   /* initialize the pseudo random generator */
   srand(seed);

   /* Create the character pool from which to choose the characters from */
   // printf("pool specifier = %s\n", pool_specifier);
   if (cindex(pool_specifier,'L')>=0)
      strcpy(pool,ALPHALOWER);
   if (cindex(pool_specifier,'U')>=0)
      strcat(pool,ALPHAUPPER);
   if (cindex(pool_specifier,'N')>=0)
      strcat(pool,NUMBER);
   if (cindex(pool_specifier,'S')>=0)
      strcat(pool,SPECIAL);

   for (int i=0; i < number; i++) {
      /* use the generate() function defined in gen.c */
      char *pw = generate(pwLength, pool);
      puts(pw); /* write password to stdout */
      free(pw); /* free memory allocated by the calloc() call in the generate function */ 
   }

   return 0;
} 

/* function to return the first position of character in a string, -1 if the character does not occur */
int cindex (char str[], char c)
{
   int i;
   for (i = 0; str[i] != '\0'; i++) {
      if (str[i] == c)
         return i;
   }
   return -1;
}

/* function to explain the use of the program */
void usage(void) 
{
   printf("Usage: gpw [OPTION] ...\n"); 
   printf("Generate a random password and write it to the standard output.\n\n");
   printf("Options:\n");
   printf("   -h           display this help and exit\n");
   printf("   -l <length>  specify password length (default = 13)\n");
   printf("   -s <seed>    specify seed (by default taken from system time)\n");
   printf("   -n <number>  specify number of passwords to be generated (default = 1)\n");
   printf("   -p \"LUNS\"    specify character to be included:\n");
   printf("                L= include lowercase characters [a..z]\n");
   printf("                U= include uppercase characters [A..Z]\n");
   printf("                N= include numbers [0..9]\n");
   printf("                S= include symbols [!@#$\%*+?~]\n\n");
   printf("Examples:\n");
   printf("$ ./gpw\n");
   printf("$ ./gpw > passwd.txt\n");
   printf("$ ./gpw -l 16 -s 888 -p LUN\n");
}
