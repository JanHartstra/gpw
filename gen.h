/*
 * Program: gen.h
 * Purpose: provide function to generate a password 
 * Author:  Jan Hartstra
 * Version: 0.1
 */

#ifndef GEN_H
#define GEN_H     

/* Define the different character sets a password may contain */
/* Cannot be done is this way: declared and defined? */
/*
const char ALPHALOWER[] = "abcdefghijklmnopqrstuvwxyz";
const char ALPHAUPPER[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char NUMBER[]     = "0123456789";
const char SPECIAL[]    = "!@#$%*=+?~";
*/

// const int MAXCHARSETLENGTH = 72; /* strlen(ALPHALOWER) + strlen(ALPHAUPPER) + strlen(NUMBER] + strlen [SPECIAL] */

/* prototype(s) of function(s) declared in gen.c */ 
/*extern*/ char *generate(int length, char charSet[]);

#endif
