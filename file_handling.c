#include <stdio.h>

FILE * file_pointer; // file_pointer can be anything, it is to denote the file

//FILE OPENING  

// file_pointer = fopen(" filename ", "opening_mode");

//FILE OPENING MODES

// "rb", "wb", "ab", "rb+", "r+b", "wb+", "w+b", "ab+", "a+b"

//FILE CLOSING

//fclose(file_pointer);

// Writing in file

// fputc() : Writes a single character to a file.
// fputs(): Writes a string to a file.
// fprintf(): Writes a formatted string (data) to a file.

// ch is a single character holder
// sub is multiple strings inside {} separated by comma {"",""}
// a is a array with mulitple sub

//sytnax:  fputc(ch, file_pointer);
//sytnax:  fputs(sub, file_pointer);
//sytnax:  fprintf(file_pointer, the line to print just like printf, eg- "%d",a )

// Reading from file

// fgetc(): Reads a single character from a file.
// fgets(): Reads a string from a file.
// fscanf(): Reads a formatted string from a file.

//syntax:  int fgetc(FILE * fp);
//syntax:  char *fgets(char *str, int n, FILE *stream);
//syntax:  int fscanf(FILE *stream, const char *format, ...);