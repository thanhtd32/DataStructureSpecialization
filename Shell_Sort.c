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
// Insertion sort elements separated by gap
// Sorting ranges from first to last
void inc_insertion_sort(int list[], int first, int last, int gap){
    int i, j, key;
    for(i=first+gap; i<=last; i=i+gap) {
        key = list[i];
        for(j=i-gap; j>=first && key<list[j];j=j-gap)
            list[j+gap]=list[j];
        list[j+gap]=key;
    }
}
//shell sort method
// n = size
void shell_sort( int list[], int n ){
    int i, gap;
    for( gap=n/2; gap>0; gap = gap/2 ) {
        if( (gap%2) == 0 ) 
            gap++;
        for(i=0;i<gap;i++) // The number of sublists is gap
            inc_insertion_sort (list, i, n-1, gap);
    }
}
//test case
int main(void){
    int n = 8;
    int list[]={67, 90, 57, 25, 84, 32, 73, 54};
    //call shell sort method
    shell_sort(list, n); 
    for (int i = 0; i<n; i++)
        printf("%d ", list[i]);
    printf("\n");
    return 0;
}