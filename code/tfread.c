/*
 * tfread.c
 *
 *  Created on: 21/04/2016
 *      Author: yong.li
 */


/* utility to read text file */



#include "tfread.h"
#define NUL '\0'
#define NOARGS 1
#define MAXLEN 40
#define BUFFERSIZE 8192
#define FILE_OPENING_ERROR 1
#define CONDITION_NOT_MEET 2

typedef enum { FALSE, TRUE } Boolean;

long int count_file_words(const char *fname);
void chop( char *string );

int main (int argc, char **argv)
{
	 char letterset[ MAXLEN ];




	 if( argc == NOARGS )
	 	    {
	 	    puts("Enter 16 char to test ... ");
	 	    fgets( letterset, MAXLEN, stdin );
	             chop( letterset );
	             if (strlen(letterset)<16){
	            	 printf("condition not meet");
	            	 exit (CONDITION_NOT_MEET);
	             }
	            for (int i=0; i<16; i++){
	            	printf("%c", letterset[i]);
	            }
	 	    }
	 	 else
	 	    strcpy( letterset, *( argv + 1 ) );



		 return (0);

}

void findword( char *lset, char *filename )
{

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

void chop( char *string )
{
   register int length;

      length = strlen( string );
      length--; /* Adjust for zero-base indexing. */

      *( string + length ) = NUL;

      return;
}



