// C code to convert infix to postfix expression
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "node_structure.h"
#define MAX_EXPR_SIZE 100
 
// Function to return precedence of operators
int precedence(char operator)
{
    switch (operator) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}
 
// Function to check if the scanned character
// is an operator
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/'
            || ch == '^');
}

 
// Main functio to convert infix expression
// to postfix expression
char* infixToPostfix(char* infix)
{
    int i, j;
    int len = strlen(infix);
    char* postfix = (char*)malloc(sizeof(char) * (len + 2));
    char stack[MAX_EXPR_SIZE];
    int top = -1;
 
    for (i = 0, j = 0; i < len; i++) {
        if (infix[i] == ' ' || infix[i] == '\t')
            continue;
       
        // If the scanned character is operand
        // add it to the postfix expression
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
       
        // if the scanned character is '('
        // push it in the stack
        else if (infix[i] == '(') {
            stack[++top] = infix[i];
        }
       
        // if the scanned character is ')'
        // pop the stack and add it to the
        // output string until empty or '(' found
        else if (infix[i] == ')') {
            while (top > -1 && stack[top] != '(')
                postfix[j++] = stack[top--];
            if (top > -1 && stack[top] != '(')
                return "Invalid Expression";
            else
                top--;
        }
       
        // If the scanned character is an operator
        // push it in the stack
        else if (isOperator(infix[i])) {
	       	postfix[j++] = ' ';
            while (top > -1
                   && precedence(stack[top])
                          >= precedence(infix[i]))
                postfix[j++] = stack[top--];
            stack[++top] = infix[i];
        }
    }
 
    // Pop all remaining elements from the stack
    while (top > -1) {
        if (stack[top] == '(') {
            return "Invalid Expression";
        }
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
    return postfix;
}

list evaluate(char opr, list a, list b)
{
	list result = NULL;
	
	switch(opr)
	{
		case '+': result = addList(&a, &b);
			  break;
		case '-': result = subtractList(&a, &b);
			  break;
		case '*': result = multiplyList(a, b);
			  break;
		case '/': result = divideList(&a, &b);
			  break;
		default : printf("Invalid expression\n");
	}
	return result;
}

void generateANumbersFromString(char *postfix)
{
	int len = strlen(postfix);
	
	stack st;
	init_stack(&st);
	
	
	
	list num = NULL;
	
	for(int i = 0; i< len; i++)
	{
		if(isalnum(postfix[i])){
			append(&num, postfix[i] - '0');
				
		}
		else if(postfix[i] == ' ' || !isalnum(postfix[i]))
		{

			if(num)
				push_stack(&st, num);
			num = NULL;
			
		}
		if(isOperator(postfix[i]) && !isEmpty(st))
		{
			list b = pop_stack(&st);
			list a = pop_stack(&st);
				
			list res = evaluate(postfix[i],a,b);	
			
			push_stack(&st, res);
		}		
		
	}	
	
	list result = pop_stack(&st);
	printf("= ");
	display(result);
	printf("\n");	
}

int main()
{   printf("bc 1.07.1 \nCopyright 1991 - 1994, 1997, 1998, 2000, 2004, 2006, 2008, 2012-2017 Free Software Foundation, Inc.\nThis is free software with ABSOLUTELY NO WARRANTY.\nFor detail type warranty\n\n");
    printf("Enter e to exit\n\n");
    char input[100];
    
    while(1)
    {
   	fgets(input, 100, stdin); 
	
	if(input[0] == 'e')
		break;	
   	 // Function call
    	char* postfix = infixToPostfix(input);	
    
    	generateANumbersFromString(postfix);
    
    	//free(postfix);
    }
    
    return 0;
}
