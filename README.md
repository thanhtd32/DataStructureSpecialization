# DataStructureSpecialization

##  과제  1  

## (Assignment 1)


1. 수식에 있는 괄호의 번호를 출력하는 프로그램을 작성하라.  왼쪽  괄호가  나올  때마다  괄호 번호는  하나씩  증가한다.  오른쪽  괄호가  나오면  매칭되는  왼쪽  괄호  번호를  출력한다.

(Write a program that prints the number of parentheses in an expression.  Each occurrence of the left parenthesis increases the parenthesis number by one.  When a right parenthesis appears, the matching left parenthesis number is printed.).

Expression:  ((())(()))

The number of parentheses:  1  2  3  3  2  4  5  5  4  1

Expression:  ((((()

The number of parentheses:  1  2  3  4  5  5

# run main function of ParenthesisQueue.c, we have the results:

### Test case 1:

Expression: ((())(()))

The  number  of  parentheses:1  2  3  3  2  4  5  5  4  1  

### Test case 2:

Expression: ((((()

The  number  of  parentheses:1  2  3  4  5  5

### Test case 3:

Expression: ((((()))))

The  number  of  parentheses:1  2  3  4  5  5  4  3  2  1

### Test case 4:

Expression: (((((()()(((()

The  number  of  parentheses:1  2  3  4  5  6  6  7  7  8  9  10  11  11

### Test case 5:

Expression: ()()()

The  number  of  parentheses:1  1  2  2  3  3

### Test case 6

Expression: ))))((()))

This expression is not valid

### Test case 7:

Expression: ((()())(()()))

The  number  of  parentheses:1  2  3  3  4  4  2  5  6  6  7  7  5  1

### Test case 8:

Expression: ((()())()(())())

The  number  of  parentheses:1  2  3  3  4  4  2  5  5  6  7  7  6  8  8  1

### Test case 9: 

Expression: ()()())))

This expression is not valid

### Test case 10:

Expression: []{}([])

This expression is not valid
