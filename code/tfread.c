/*
 * tfread.c
 *
 *  Created on: 21/04/2016
 *      Author: yong.li
 */


/* utility to read text file */



#include "tfread.h"

#define MAXLEN 40
#define BUFFERSIZE 8192
#define FILE_OPENING_ERROR 1


typedef enum { FALSE, TRUE } Boolean;

long int count_file_words(const char *fname);
Boolean duplicatewordcheck( const char *fname);


int main ()
{

  long int wordcount=0L;

  wordcount=count_file_words(Wordfile);

  printf ("number of words: %ld  in the file", wordcount);

  return 0;

}



long int count_file_words( const char *fname )
{
   FILE *fptr;
   char word[MAXLEN];
   long int noofword=0L;
   if (!(fptr=fopen(fname, "r")))
    {
       printf( "Cannot open Wordfile!" );
          exit( FILE_OPENING_ERROR );
      }
       else
           {
     if( setvbuf( fptr, NULL, _IOFBF, BUFFERSIZE * 2 ) )
         exit ( FILE_OPENING_ERROR );  /*Extra buffering.*/
        }

     while (fgets(word, MAXLEN, fptr)!=NULL){
            noofword++;
          }

       printf( "Number of words: %ld \n", noofword );
     fclose(fptr);
      return (noofword);
}
