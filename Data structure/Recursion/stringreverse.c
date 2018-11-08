#include <stdio.h>
#include <string.h>

void reverse(char arr[], int Start,int Last)
{
    if( Start < Last )
    {
        //swap
        char temp = arr[Start];
        arr[Start] = arr[Last];
        arr[Last] = temp;

        reverse(arr, Start+1, Last-1);
    }
}

void main()
{
    char ch[] = {"A quick brown fox jumps over a lazy dog"};

    reverse(ch, 0, strlen(ch)-1);
    puts(ch);
}
