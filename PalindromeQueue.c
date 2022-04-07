/*
Author: TRAN DUY THANH (thanhtd@uel.edu.vn)
Student code: 20207144
Professor:Kil-Woong Jang (jangkw@kmou.ac.kr)
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_SIZE 1000

//create char element type
typedef char element;
/* Queue structure for storing string
 * Each data is a char element
 */
typedef struct 
{  
    int front;
    int rear;
    element data[MAX_SIZE];
} Queue;

/*
The init_queue function is used to initialize the queue
by giving rear =-1 and front=-1
*/
void init_queue(Queue *q)
{
    q->rear = -1;
    q->front = -1;
}

/*
The is_full function checks whether the queue is full or not
if the queue is full, the function returns 1, not full it will returns 0
*/
int is_full(Queue *q)
{
    if (q->rear == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}
/*
The is_empty function checks if the queue is empty
if the queue is empty then the function returns 1
If not empty, the function returns 0
*/
int is_empty(Queue *q)
{
    if (q->front == q->rear)
        return 1;
    else
        return 0;
}
/*
The enqueue function to put an Element in the queue
If queue is full then error message
*/
void enqueue(Queue *q, element item)
{
    if (is_full(q)) 
    {
        printf("The queue is full");
        return;
    }
    q->data[++(q->rear)] = item;
}
/*
dequeue function is used to get an element out of the queue
if queue is empty then error message
*/
element dequeue(Queue *q)
{
    if (is_empty(q)) {
        printf("The queue is empty.");
        return -1;
    }
    element item = q->data[++(q->front)];
    return item;
}

/*
the enqueue_all function use to add from first to last of the string 
into the queue
*/
void enqueue_all(Queue *q, char* str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		enqueue(q,str[i]);
	}	
}
/*
the enqueue_all function use to add from last to first of the string 
into the queue
*/
void enqueue_all_reverse(Queue *q, char* str)
{
	for (int i =strlen(str)-1;i>=0; i--)
	{
		enqueue(q,str[i]);
	}
}
/*
The palindrome function uses to check the string is palindrome or not
it returns 1 if the string is palinrome, otherwise is 0
*/
int palindrome(Queue *q1,Queue *q2)
{
	while (!is_empty(q1) || !is_empty(q2))
	{
		if (dequeue(q1)!=dequeue(q2))
		{
			return 0;
		}
	}
	return 1;
}
int main(void)
{
    //I create some strings to test
    char * words[] = { 
            "eye" ,
            "madam",
            "radar",
            "redivider",
            "civic", 
            "racecar", 
            "hello",//not palindrome
            "reviver", 
            "thank",//not palindrome
            "kayak",
    };
    //get the length of the array words:
    int n=(sizeof((words)) / sizeof(words[0]));
    for(int i=0;i<n;i++)
    {
        //get the word at i-th:
        char *word = words[i];
        //create q1 Queue object
        Queue *q1=(Queue *)malloc(sizeof(Queue));
        init_queue(q1);
        //create q2 Queue object
        Queue *q2=(Queue *)malloc(sizeof(Queue));
        init_queue(q2);
        //call enqueue_all for q1
        enqueue_all(q1,word);
        //call enqueue_all_reverse for q2
        enqueue_all_reverse(q2,word);
        //call palindrome function to check if the word is palindrome or not
        if (palindrome(q1,q2)==1)
        {
            printf("[%s] is a palindrome word.\n",word);
        }
        else
        {
            printf("[%s] is NOT a palindrome word.\n",word);
        }
        free(q1);
        free(q2);
    }
    
    return 0;
}