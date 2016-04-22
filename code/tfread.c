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

Boolean word_match(char *s_grid, char *s_dict);
void findword( char **lset, char *filename );
char sort_result[16][5];
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


        /*  for (int i=0; i<16;i++){
        	  for (int y=0; y<4; y++){
        		  sort_result[i][y]='/0';
        	  }

          }*/

	        	    for(int i=0; i<4; i++) {

	        	        for(int j=0; j<4; j++) {

	        	        	 sort_result[i][j]=letterset[i * 4 + j];

	        	            sort_result[15 -i][j]=letterset[ 15 - i*4 -j];

	        	          sort_result[i + 4][j]=letterset[ i + j * 4 ];

	        	        		sort_result[i + 8][j]=letterset[ 15 - i - j*4];


	        	        }

	        	    }
	        	    for (int i=0; i<16; i++){
	        	    	printf("%s \n", sort_result[i]);
	        	    }
	 	    }
	 	 else
	 	    strcpy( letterset, *( argv + 1 ) );

       findword(sort_result,Wordfile);


		 return (0);

}




void findword( char **lset, char *filename )
{
	 FILE *fptr;
	   char word[MAXLEN];

	   if (!(fptr=fopen(filename, "r")))
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
               for (int i=0;i<16;i++){
            	  if(word_match(*lset,word)){

            		  printf( "%s", word );
            	  }
               }
	          }

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

Boolean word_match(char *s_grid, char *s_dict) {

   if (strlen(s_dict) <= 2) {

       return 0;

   }

   int is_match = 0;

   if (strlen(s_dict) > strlen(s_grid)) {

      is_match = (strstr(s_dict, s_grid) == NULL ) ? 0 : 1;

   }

   else {

      is_match = (strstr(s_grid, s_dict) == NULL ) ? 0 : 1;

   }

   return is_match;

}




