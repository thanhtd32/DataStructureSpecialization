# DataStructureSpecialization

##  과제  1  

## (Assignment 1)


## Exercise 1. 

수식에 있는 괄호의 번호를 출력하는 프로그램을 작성하라.  왼쪽  괄호가  나올  때마다  괄호 번호는  하나씩  증가한다.  오른쪽  괄호가  나오면  매칭되는  왼쪽  괄호  번호를  출력한다.

(Write a program that prints the number of parentheses in an expression.  Each occurrence of the left parenthesis increases the parenthesis number by one.  When a right parenthesis appears, the matching left parenthesis number is printed.).

Expression:  ((())(()))

The number of parentheses:  1  2  3  3  2  4  5  5  4  1

Expression:  ((((()

The number of parentheses:  1  2  3  4  5  5

# run main function of ParenthesisQueue.c, we have the results:

### Test case 1:

1.Expression: ((())(()))

The  number  of  parentheses:1  2  3  3  2  4  5  5  4  1  

### Test case 2:

2.Expression: ((((()

The  number  of  parentheses:1  2  3  4  5  5

### Test case 3:

3.Expression: ((((()))))

The  number  of  parentheses:1  2  3  4  5  5  4  3  2  1

### Test case 4:

4.Expression: (((((()()(((()

The  number  of  parentheses:1  2  3  4  5  6  6  7  7  8  9  10  11  11

### Test case 5:

5.Expression: ()()()

The  number  of  parentheses:1  1  2  2  3  3

### Test case 6

6.Expression: ))))((()))

This expression is not valid

### Test case 7:

7.Expression: ((()())(()()))

The  number  of  parentheses:1  2  3  3  4  4  2  5  6  6  7  7  5  1

### Test case 8:

8.Expression: ((()())()(())())

The  number  of  parentheses:1  2  3  3  4  4  2  5  5  6  7  7  6  8  8  1

### Test case 9: 

9.Expression: ()()())))

This expression is not valid

### Test case 10:

10.Expression: []{}([])

This expression is not valid

## Exercise 2

회문(palindrome)이란 앞뒤 어느 쪽에서 읽어도 같은 말, 구, 문 등을 의미한다.  예를  들면  “eye”,  “madam”,  “radar”  등이다.  여기서  물론  구두점이나  스페이스,  대소문자  등은  무시하여야  한다.  덱을  이용하여  주어진  문자열이  회문인지  아닌지를  결정하는  프로그램을  작성하라. 

(A palindrome means a word, phrase, or sentence that is the same whether read from either front or back.  For example, “eye”, “madam”, “radar”, etc.  Here, of course, punctuation, spaces, and capital letters should be ignored.  Write a program that uses a deque to determine whether a given string is a palindrome or not.)

# run main function of ParenthesisQueue.c, we have the results:

1.[eye] is a palindrome word.
2.[madam] is a palindrome word.
3.[radar] is a palindrome word.
4.[School] is NOT a palindrome word.
5.[Draw, O coward!] is a palindrome word.
6.[Did Hannah see bees? Hannah did.] is a palindrome word.
7.[redivider] is a palindrome word.
8.[Cigar? Toss it in a can. It is so tragic.] is a palindrome word.
9.[Dammit, I'm mad!] is a palindrome word.
10.[civic] is a palindrome word.
11.[Won't lovers revolt now?] is a palindrome word.
12.[racecar] is a palindrome word.
13.[Borrow or rob?] is a palindrome word.
14.[hello] is NOT a palindrome word.
15.[reviver] is a palindrome word.
16.[thank] is NOT a palindrome word.
17.[kayak] is a palindrome word.
18.[Don't nod.] is a palindrome word.
19.[Evil olive.] is a palindrome word.
20.[Amore, Roma.] is a palindrome word.
21.[Yo, banana boy!] is a palindrome word.
22.[I did, did I?] is a palindrome word.
23.[Anne, I vote more cars race Rome to Vienna.] is a palindrome word.
24.[Ed, I saw Harpo Marx ram Oprah W. aside.] is a palindrome word.
25.[Doc, note I dissent: a fast never prevents a fatness. I diet on cod.] is a palindrome word.
26.[Dennis, Nell, Edna, Leon, Nedra, Anita, Rolf, Nora, Alice, Carol, Leo, Jane, Reed, Dena, Dale, Basil, Rae, Penny, Lana, Dave, Denny, Lena, Ida, Bernadette, Ben, Raay, Lila, Nina, Jo, Ira, Mara, Sara, Mario, Jan, Ina, Lily, Arne, Bette, Dan, Reba, Diane, Lynn, Ed, Eva, Dana, Lynne, Pearl, Isabel, Ada, Ned, Dee, Rena, Joel, Lora,C Cecil, Aaron, Flora, Tina, Arden, Noel, and Ellen sinned.] is a palindrome word.
