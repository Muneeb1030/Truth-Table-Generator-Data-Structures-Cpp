#include "StackClass.h"

//------>> Constructor
//This function will generate a stack array of user provided size and
//Also Initialize the Top from -1
Stack::Stack(int Size)
{
StackSize = Size;
StackArray = new int[StackSize];
Top = -1;
}
/////////////////////////////
//------>> Is Full
//This function will Check whether the Stack is full or not
bool Stack::IsFull()
{
	return Top == StackSize - 1;//since array index starts from 0
}
/////////////////////////////
//------>> Push
//This function will insert the provided value in the stack
bool Stack::Push(int InputValue)
{
	if (!IsFull())//Until there exist space in the stack
	{
		Top++;//move to next index
		StackArray[Top] = InputValue;//Insert value
		return true;
	}
	else//if stack is full
	{
		return false;
	}
}
/////////////////////////////
//------>> Is Empty
//This function will Check whether the Stack is Empty or not
bool Stack::IsEmpty()
{
	if (Top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/////////////////////////////
//------>> POP Function
//This function will remove the value at top of stack and
//return it to the user
int Stack::POP()
{
	int TobeReturned;
	if (!IsEmpty())
	{
		//the variable is passed by reference, So, the value is reflevted in main
		TobeReturned = StackArray[Top];//get the value and move backward
		Top--;//move to Previous index
		return TobeReturned;
	}
	else
	{
		return 0;
	}
}
/////////////////////////////
//------>> TOP Function
//This function will remove the value at top of stack and
//return it to the user
int Stack::TopValue()
{
	if (!IsEmpty())
	{
		//the variable is passed by reference, So, the value is reflevted in main
		return StackArray[Top];//get the value
	}
	else
	{
		return false;
	}
}
/////////////////////////////
//------>> Precedence Assigned Function
//This function will return the precedence of the operator 
//provided
int Stack::PrecedenceAssigned(char ElementRead)
{
	if (ElementRead == '|')
	{
		return 1;              //Precedence of OR is 1
	}
	else if (ElementRead == '^')
	{
		return 2;            //Precedence of AND is 2
	}
	else if (ElementRead == '~')
	{
		return 3;            //Precedence of NOT is 3
	}
	else if (ElementRead == '(')
	{
		return 4;            //Precedence of Parenthesis is 4
	}
	else
	{
		return 0;
	}
}
/////////////////////////////
//------>> Precedence Function
//This function will return the precedence of the operator 
//provided
bool Stack::Precedence(char TopofStack, char ElementRead)
{
	if (TopofStack == '(')
	{
		return false;
	}
	else if (PrecedenceAssigned(TopofStack) < PrecedenceAssigned(ElementRead))
	{
		return false;
	}
	else
	{
		return true;
	}
}
/////////////////////////////
//------>> Infix to Postfix Function
//This function will convert the given infix to a postfix expression
void Stack::ToPostfix(string& Expression)
{
	Stack OperatorHolder(StackSize);
	string PostfixExpression = "\0";
	char ElementPoped = '\0';
	for (int i = 0; i < Expression.length(); i++)
	{
		if (isalpha(Expression[i]) || isdigit(Expression[i]))
		{
			PostfixExpression.append(1, Expression[i]);
		}
		else
		{
			while (!OperatorHolder.IsEmpty() && Precedence(OperatorHolder.TopValue(), Expression[i]))
			{
				ElementPoped = OperatorHolder.POP();
				PostfixExpression.append(1, ElementPoped);
			}
			if (Expression[i] != ')')
			{
				OperatorHolder.Push(Expression[i]);
			}
			else
			{
				ElementPoped = OperatorHolder.POP();
			}
		}
	}
	while (!OperatorHolder.IsEmpty())
	{
		ElementPoped = OperatorHolder.POP();
		PostfixExpression.append(1, ElementPoped);
	}
	Expression = PostfixExpression;
}
/////////////////////////////
//------>> Destructor
//This function will delete the array allocated for stack
//and also make top -1 incase if destructor is called by user
Stack::~Stack()
{
	delete[]StackArray;
	StackArray = nullptr;
	Top = -1;
}