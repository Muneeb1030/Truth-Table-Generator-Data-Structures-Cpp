#pragma once
//Header Files for the inclusion of Respective libraries
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
//------------<< Stack Class >>-----------------
//This class will have all the functionality required
//to be performed by the program
class Stack
{
private:
	/////////////////////////////
	//----->> This Varable will beusd to create a dynamic array
	int* StackArray;
	//----->> This variable will be used to get and maintain szie of stack
	int StackSize;
	//---->> To use only one end of array.....The basic logic behind stack
	int Top;
public:
	/////////////////////////////
	//------>> Constructor
	Stack(int Size);
	/////////////////////////////
	//------>> Is Full
	bool IsFull();
	/////////////////////////////
	//------>> Push
	bool Push(int InputValue);
	/////////////////////////////
	//------>> Is Empty
	bool IsEmpty();
	/////////////////////////////
	//------>> POP Function
	int POP();
	/////////////////////////////
	//------>> TOP Function;
	int TopValue();
	/////////////////////////////
	//------>> Precedence Assigned Function
	int PrecedenceAssigned(char ElementRead);
	/////////////////////////////
	//------>> Precedence Function
	bool Precedence(char TopofStack, char ElementRead);
	/////////////////////////////
	//------>> Infix to Postfix Function
	void ToPostfix(string& Expression);
	/////////////////////////////
	//------>> Destructor
	~Stack();
};