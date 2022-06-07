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
int sorted[MAX_SIZE]; 
// merge method
void merge(int list[], int left, int mid, int right)
{
    // i is the index into the sorted left list
    // j is the index into the sorted right list
    // k is the index into the list to be sorted
    int i, j, k, l;
    i=left; j=mid+1; k=left;
    // Merge split sorted list
    while(i<=mid && j<=right)
    {
        if(list[i]<=list[j]) 
            sorted[k++] = list[i++];
        else 
            sorted[k++] = list[j++];
    }
    if(i>mid)  // Batch copy of remaining records
        for(l=j; l<=right; l++)
            sorted[k++] = list[l];
    else  // Batch copy of remaining records
        for(l=i; l<=mid; l++)
            sorted[k++] = list[l];
    // Copy the list of the array sorted[] to the array list[]
    for(l=left; l<=right; l++)
        list[l] = sorted[l];
}
//merge sort method
void merge_sort(int list[], int left, int right)
{
    int mid;
    if(left<right)
    {
        mid = (left+right)/2; // evenly split the list
        merge_sort(list, left, mid); // sort partial list
        merge_sort(list, mid+1, right);//sort partial list
        merge(list, left, mid, right); // Merger
    }
}
//test case
int main(void)
{
    int n = 8;
    int list[]={67, 90, 57, 25, 84, 32, 73, 54};
    //call merge sort method
    merge_sort(list, 0, n-1); 
    for (int i = 0; i<n; i++)
        printf("%d ", list[i]);
    printf("\n");
    return 0;
}