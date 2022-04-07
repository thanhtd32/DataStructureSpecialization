/*
Author: TRAN DUY THANH (thanhtd@uel.edu.vn)
Student code: 20207144
Professor:Kil-Woong Jang (jangkw@kmou.ac.kr)
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//define MAX_SIZE 1000 for queue
#define MAX_SIZE 1000

/*
The Element structure is used to store the left and right parentheses
value: Save left parentheses or right parentheses in the expression
index: The position of left parentheses or right parentheses in the expression
closed: indicates whether the pair parentheses is in the correct position
*/ 
typedef struct
{
    char value;
    int index;
    int closed;
}Element;

/* Queue structure for storing expressions
 * Each data is an Element structure
 */
typedef struct 
{  
    int front;
    int rear;
    Element *data[MAX_SIZE];
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
void enqueue(Queue *q, Element *item)
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
Element* dequeue(Queue *q)
{
    if (is_empty(q)) {
        printf("The queue is empty.");
        return NULL;
    }
    Element *item = q->data[++(q->front)];
    return item;
}
/*
The parentheses_print function is used to print the number of parentheses in an expression
for example:
if the expression is ((())(()))
then the result: 1  2  3  3  2  4  5  5  4  1
if the expression is ((((()
then the result: 1  2  3  4  5  5
if the expression is ((()())(()()))
then the result: 1  2  3  3  4  4  2  5  6  6  7  7  5  1
*/
void parentheses_print(Queue *q)
{
    while (!is_empty(q))
    {
        Element *item=dequeue(q);
        printf("%d  ", item->index);
    }    
    printf("\n");
}
/*
the parse_expression function is used to compile the expression input
into the Elements structure object with the correct value and position in the expression
then elements are placed in the queue.
if expression is valid the result is 1, otherwise result is 0
*/
int parse_expression(Queue *q, char* expression)
{
    //get the length of the string expression
    int len=strlen(expression);
    int index=0;
    int isValidExpression=1;
	for (int i = 0; i < len; i++)
	{
        //check the expression is not valid Parenthesis
        if(expression[i] !='(' && expression[i]!=')')
        {
            isValidExpression=0;
            //break the loop if the expression is not valid Parenthesis
            break;
        }
        //allocate memory for item Element:
        Element *item=(Element *)malloc(sizeof(Element));
        //assign the prenthesis for element
        item->value=expression[i];
        //tag the closed =0 it means this pair-Parenthesis is not counted
        item->closed=0;
        if(expression[i]=='(')
        {
            //set the index for the left Parenthesis
            index++;
            item->index=index;         
            //set the expresion is valid 
            isValidExpression=1;              
        }
        else if(expression[i]==')')
        {
            //set the index of the current ) is not valid
            isValidExpression=0;
            //loop to find the exactly the index for the right Parenthesis
            for (int j = q->rear; j >=0; j--)
            {
                Element *prev_item=q->data[j];
                if(prev_item->value=='(' && prev_item->closed==0)
                {
                    //the index of the right parenthesis is exactly of left parenthesis
                    item->index=prev_item->index;
                    //tag the closed =1, it means this pair-Parenthesis is counted
                    prev_item->closed=1;
                    //set the index of the current ) is valid
                    isValidExpression=1;
                    //break the loop                    
                    break;
                }
            }            
        }
        //if the expression is not valid then we break the function
        if(isValidExpression==0)
            break;
        //enqueue the item into Queue q object
		enqueue(q,item);
	}	
    return isValidExpression;
}
int main(int argc, char const *argv[])
{
    //I create 10 expressions to test
    char * expressions[] = { 
            "((())(()))" ,
            "((((()",
            "((((()))))",
            "(((((()()(((()",
            "()()()", 
            "))))((()))", //not valid expression
            "((()())(()()))",
            "((()())()(())())", 
            "()()())))",//not valid expression 
            "[]{}([])",//not valid expression 
    };
    //get the length of the array expressions:
    int n=(sizeof((expressions)) / sizeof(expressions[0]));
    for(int i=0;i<n;i++)
    {
        Queue *q=(Queue *)malloc(sizeof(Queue));
        init_queue(q);
        //get the expression at i-th:
        char *expression = expressions[i];
        //call the parse_expression function
        int ret=parse_expression(q,expression);
        printf("Expression: %s\n",expression);
        if(ret==1)
        {
            printf("The  number  of  parentheses:");
            parentheses_print(q);
        }
        else
        {
            printf("This expression is not valid\n");
        }
        free(q);
    }    
    return 0;
}
