/*
Program: gen.h
Purpose: provide function to generate a password 
Author:  Jan Hartstra
Version: 0.1
*/

#ifndef GEN     
#define GEN     

const char ALPHALOWER[] = "abcdefghijklmnopqrstuvwxyz";
const char ALPHAUPPER[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char NUMBER[]     = "0123456789";
const char SPECIAL[]    = "!@#$%*=+?~";
const int MAXCHARSETLENGTH = 72;

extern char *generate(int length, char charSet[]);

#endif
