/*
Author: TRAN DUY THANH (thanhtd@uel.edu.vn)
Student code: 20207144
Professor:Kil-Woong Jang (jangkw@kmou.ac.kr)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ELEMENT 200
//define the element datatype 
typedef struct {
    int key;
}element;

//define Heaptype
typedef struct 
{
    //declare an array heap to store the elements
    element heap[MAX_ELEMENT];
    //size of heap, it is automatic changing when the heap changes element
    int heap_size;
}HeapType;

//the function use to create a pointer of HeapTyep
//and allocate the memory for this pointer
HeapType *create()
{
    return (HeapType*)malloc(sizeof(HeapType));
}
//This function use to initialize the heap size
//the default heap size is 0
void init(HeapType *h)
{
    h->heap_size=0;
}
//function use to check the heap is full or not
int isFull(HeapType *h)
{
    if(h->heap_size==MAX_ELEMENT-1)
        return 1;
    return 0;
}
//this function use to swap two variable
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/*
this function use to insert a min heap
HeapType *h: a pointer of heap
element item: an element to insert a min heap
*/
void insert_min_heap(HeapType *h,element item)
{
    if(isFull(h)==1)
    {
        printf("The min Heap is full!");
        return;
    }
    int i;
    i=++(h->heap_size);
    while ((i!=1) && (item.key< h->heap[i/2].key))
    {
        h->heap[i]=h->heap[i/2];
        i/=2;
    }
    h->heap[i]=item;
}
/*
this function use to extract the top element of the heap
it is used for the remove function
*/
element extract(HeapType *h)
{
    element root = h->heap[1];
    h->heap[1] = h->heap[h->heap_size];
    h->heap_size=h->heap_size-1;
    return root;
}
/*
this function is used to heapify after remove an element
*/
void heapify(HeapType *h,int i)
{
    int l = i*2;
    int r = (i*2)+1;
    int s = i;
    if(l<=h->heap_size && h->heap[l].key< h->heap[i].key)
        s = l;
    if(r<=h->heap_size && h->heap[r].key< h->heap[s].key)
        s = r;
    //if s and i is different, they are swapped and then heapify the mean heap
    if(s!=i)
    {
        swap(&h->heap[i].key,&h->heap[s].key);
        heapify(h,s);
    }
}
/*
This function use to check if i index is valid or not
it is used for the remove element
*/
int isValidIndex(HeapType *h,int i)
{
    if(h==NULL|| i<1 || i >h->heap_size)
    {
        return 0;
    }
    return 1;
}
/*
This function use to remove an  arbitrary  index  from  the  min  heap
HeapType *h: the min heap
int i: the index will be removed from the min heap
*/
int removeIdex(HeapType *h,int i)
{
    //check i is valid index to remove or not
    if(isValidIndex(h,i)==0)
        return 0;
    h->heap[i].key = INT_MIN;
    while(i!=1 && h->heap[i/2].key>h->heap[i].key)
    {
        swap(&h->heap[i/2].key,&h->heap[i].key);
        i = i/2;
    }
    extract(h);
    heapify(h,1);
    return 1;
}
/*
This function use to find the index of the element in the min heap
HeapType *h : mean heap
element e: element to find the index
return -1 if the function can not find the element
return the index if the function found the element
*/
int findIndex(HeapType *h,element e)
{
    int index=-1;
    for(int j=1;j<=h->heap_size;j++)
    {
        if(h->heap[j].key==e.key)
        {
          index=j;
          break;      
        }
    }
    return index;
}
/*
This function use to remove an  arbitrary  index  from  the  min  heap
HeapType *h: the min heap
int i: the index will be removed from the min heap
*/
int removeElement(HeapType *h,element e)
{
    int i=findIndex(h,e);
    if(i==-1)
        return 0;
    h->heap[i].key = INT_MIN;
    while(i!=1 && h->heap[i/2].key>h->heap[i].key)
    {
        swap(&h->heap[i/2].key,&h->heap[i].key);
        i = i/2;
    }
    extract(h);
    heapify(h,1);
    return 1;
}
/*
This function use to print all data in heap
*/
void print_min_heap(HeapType *h)
{
    for(int j=1;j<=h->heap_size;j++)
    {
        printf("%d ", h->heap[j].key);
        printf("\t");
    }
    printf("\n");
}
/*
Thí function use to find the width to print element
*/
int pow2i(int x) {
    int w = 1;
    while (x--) 
    {
        w *= 2;
    }
    return w;
}
/*
This function use to write the min heap like a tree
*/
void display_min_heap_tree(HeapType *h) {
    printf("\n");
    int ldigits = 0;
    int heap_depth = 0;
    int pos = 0;
    int depth = 0;
    for (int i = 1; i <=h->heap_size; ++i) 
    {
        if (h->heap[i].key != -1) 
        {
            int len = snprintf(NULL, 0, "%d", h->heap[i].key);
            if (ldigits < len) 
            {
                ldigits = len;
            }
        }        
        if (pos == 0) 
        {
            heap_depth++;
            pos = pow2i(depth++);
        }
        pos--;      
    }
    pos = 0;
    depth = 0;
    int offset = 3;
    int max_width = pow2i(heap_depth) * (ldigits + offset);
    for (int i = 1; i <=h->heap_size; ++i) 
    {
        bool first = pos == 0;
        if (first) 
        {
            pos = pow2i(depth);
            depth++;
        }
        int count = pow2i(depth);
        int chunk = max_width / count;
        int width = chunk + (first ? -chunk/2 : 0);
        int spaces = width - ldigits;

        printf("%*s", spaces, "");
        if (h->heap[i].key <0) 
        {
            printf("%*s", ldigits, "-");
        } 
        else 
        {
            printf("%*d", ldigits, h->heap[i].key);
        }
        if (pos == 1) {
            printf("\n");
        }
        pos--;
    }
    printf("\n");
}

/*
this is a main function
use the min heap
*/
int main(int argc, char const *argv[])
{
    element arr[15]={20,30,3,15,8,2,4,1,5,18,12,10,17,19,22};
    
    HeapType *h=create();
    init(h);
    for (int i = 0; i < 15; i++)
    {
        insert_min_heap(h,arr[i]);      
    }    
    while (1)
    {
        char c;
        printf("View Min Heap(h)\nDelete Index(i)\nDelete Value(v)\nExit(e)\nYou choose:");
        scanf("%c",&c);
        getchar();
        switch (c)
        {
            case 'h'://print all min heap
                {
                    display_min_heap_tree(h);
                }
                break;
            case 'i'://delete element by index
                {
                   int index;
                   printf("Enter index to delete:");
                   scanf("%d",&index);
                   getchar();
                   int ret=removeIdex(h,index);
                   if(ret==1)
                    {
                        printf("delete index %d is successful\n",index);
                        display_min_heap_tree(h);
                    }
                    else
                    {
                        printf("Not found the index %d to delete\n",index);
                    }
                }
                break;
            case 'v'://delete element by value
                {
                   int value;
                   printf("Enter value to delete:");
                   scanf("%d",&value);
                   getchar();
                   element e={value};
                   int ret=removeElement(h,e);
                   if(ret==1)
                    {
                        printf("delete value %d is successful\n",value);
                        display_min_heap_tree(h);
                    }
                    else
                    {
                        printf("Not found the value %d to delete\n",value);
                    }
                }
                break;          
            case 'e'://exit application
                printf("Thank you for your using this software!\n");
                exit(0);
                break;
            break;
            default://notify the error when input choosing is not matching
                printf("Please enter [v,i,a,e]\n");
                break;
        }
    }    
    return 0;
}