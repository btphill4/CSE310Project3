/** 
 * Author: Brandon Phillips
 * Function: gets the next input of the command lines and returns it to the main
 * S stops
 * C n creates heap of size n
 * R reads from HEAPinput.txt first integer n, then the following integers
 *   dynamically allocating memory for an ELEMENT, sets it to key and pointer
 *   heap->Elements[j] points to this element
 * P prints the heap to console(same format as HEAPinput.txt)
 * W writes the heap to HEAPoutput.txt
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Util.h"
#include "Heap.h"
using namespace std;


int nextWord (char *word)
{
    char c;
    int i, r_value;

    //printf ("BGN nextWord\n");

    r_value = 0;
    c = getchar();

    //when reading a space, tab or enter, it keeps reading for char
    while(c == ' ' || c == '\t' || c == '\n')
    {
        c = getchar();
    }

    //checks to see if it is an alphabet letter
    while(!isalpha(c))
    {
        c = getchar();
        if(c == EOF)
        {
            return 0;
        }
    }

    //once it's inside of the word
    i = 0;
    //reads the chars letter by letter until it reads the whole word
    while(c != EOF)
    {   //breaks the loop if there is a space, enter, tab
        if (c == ' ' || c == '\t' || c == '\n')
        {
            break;
        }
        else if(!isalpha(c))
        {
            break;
        }
        r_value = 1;
        word[i] = c;
        i++;
        c = getchar();
    }
    word[i] = '\0';

    return r_value;

    //printf("END nextWord\n");
    //r_value is 1 for success
    //r_value is 0 for fail

    
}
