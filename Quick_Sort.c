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
// partition method
int partition(int list[], int left, int right){
    int pivot, temp;
    int low,high;
    low = left; 
    high = right+1;
    pivot = list[left]; 
    do { 
        do
            low++;
        while(low<=right &&list[low]<pivot); 
        do
            high--;
        while(high>=left && list[high]>pivot);
        if(low<high) 
            SWAP(list[low], list[high], temp); 
    } while(low<high);
    SWAP(list[left], list[high], temp); 
    return high;
}
//quick sort method
void quick_sort(int list[], int left, int right){
    if (left<right){
        int q = partition(list, left, right);
        quick_sort(list, left, q - 1);
        quick_sort(list, q + 1, right);
    }
}
//test case
int main(void){
    int n = 8;
    int list[]={67, 90, 57, 25, 84, 32, 73, 54};
    quick_sort(list,0, n-1);
    for (int i = 0; i<n; i++)
        printf("%d ", list[i]);
    return 0;
}