// Just testing out some stuff :)

//Play code to load an array with 5 names from user input

#include <stdio.h>
#include <string.h>
//because of how C stores character strings as separate letters in array...
//see website http://stackoverflow.com/questions/1088622/how-do-i-create-an-array-of-strings-in-c
//, do the following...as in the example below
//This will allocate two consecutive arrays of 14 chars each,
// after which the content of the static strings will be copied into them.
//So, basically they're storing each string in a separate array - each letter in one position
//I will test this further down in the program...
//char a[2][14];
//strcpy(a[0], "blah");
//strcpy(a[1], "hmm")

//allows for 5 names of 15 characters each to be entered; ie. 5 arrays
char name_array[5][15];

char name[15];

int count = 0;

int main(void)
{
printf("\nProgram to enter 5 first names into an array and then print them out\n");

for(count=0; count<5; count++)
{
    printf("\n\nPlease enter a first name and hit enter:\n");
    //fgets is better than scanf because I can't seem to do this (scanf) without it
    //continually reading characters from the same line. It keeps going in the loop and picking
    //off chunks of characters (tested with 5), and doesn't seem to recognize any type of delimiter
    // - doesn't recognize carriage control, spaces, or comma
    //scanf("%s",&name);
    fgets(name, sizeof(name), stdin);
    //fflush used to get rid of the rest of the input line after the user has entered the appropriate number
    //of characters requested for first name. Set at 15 for now but test it with 5 if you need to
    fflush(stdin);

    printf("In [%d] of the array = %s",count,name);
    //name_array[count]=name;
    //printf("\n%s",name);
    //printf("\nTest loop #: %d",count);
    //
    //strcpy is used to get the entered data into the array
    //It might be a good idea to look up exactly what strcpy does...
    //use website http://www.cplusplus.com/reference/cstring/strcpy/
    strcpy(name_array[count], name);
}
printf("\n\n");

for(count =0; count<5; count++)
{
       printf("\nName at position %d is: %s",count,name_array[count]);
}

printf("\n\n");
return 0;

}

// strcpy example from http://www.cplusplus.com/reference/cstring/strcpy/
/*#include <stdio.h>
#include <string.h>

int main ()
{
  char str1[]="Sample string";
  char str2[40];
  char str3[40];
  strcpy (str2,str1);
  strcpy (str3,"copy successful");
  printf ("str1: %s\nstr2: %s\nstr3: %s\n",str1,str2,str3);
  return 0;
}

//Output should be:
//
//str1: Sample string
//str2: Sample string
//str3: copy successful
 */
