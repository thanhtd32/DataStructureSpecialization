/*
Author: TRAN DUY THANH (thanhtd@uel.edu.vn)
Student code: 20207144
Professor:Kil-Woong Jang (jangkw@kmou.ac.kr)
*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
// insertion method
void insertion_sort(int list[], int n) 
{ 
    int i, j, key;
    for(i=1; i<n; i++)
    {
        key = list[i];
        for(j=i-1; j>=0 && list[j]>key; j--) 
            list[j+1] = list[j];  // move the record right
        list[j+1] = key;
    }
}
//test case
int main(void)
{
    int n = 8;
    int list[]={67, 90, 57, 25, 84, 32, 73, 54};
    //call insertion_sort method
    insertion_sort(list, n); 
    for (int i = 0; i<n; i++)
        printf("%d ", list[i]);
    printf("\n");
    return 0;
}
