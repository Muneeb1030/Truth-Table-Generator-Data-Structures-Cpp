
//Header Files for the inclusion of Respective libraries
#include"StackClass.h"

/////////////////////////////
//------>> Is Operator
//This function will Check whether the Element Read from
//stack is an operator or not
bool IsOperator(char ElementRead)
{
	if (ElementRead == '^' || ElementRead == '|' || ElementRead == '~'
		|| ElementRead == '(' || ElementRead == ')')
	{
		return true;
	}
	else
	{
		return false;
	}
}
/////////////////////////////
//------>> postfix evaluation
//This function will Solve the given postfix expression
int PostfixEvaluation(string PostfixGiven)
{
	// Create a stack of capacity equal to expression size
	Stack stack(PostfixGiven.length());
	//Checking for Each Character in String
	for (int i = 0; i < PostfixGiven.length(); i++)
	{
		if (isdigit(PostfixGiven[i]))
		{
			int Value = 0;
			Value = (int)(PostfixGiven[i] - '0');
			stack.Push(Value);
		}
		else
		{
			if (PostfixGiven[i] == '~')
			{
				int val1 = stack.POP();
				if (val1 == 1)
				{
					stack.Push(0);
				}
				else
				{
					stack.Push(1);
				}
			}
			else
			{
				int Result = 0;
				int val1 = stack.POP();
				int val2 = stack.POP();
				switch (PostfixGiven[i])
				{
				case '^':
					stack.Push(val1 * val2);
					break;
				case '|':
					Result = val1 + val2;
					if (Result >= 2)
					{
						stack.Push(1);
					}
					else
					{
						stack.Push(Result);
					}
					break;
				}
			}
		}
	}
	return stack.TopValue();
}
/////////////////////////////
//------>> Display Function
//This function will show the table on console
void Display(string Operands, int**& Array, int Rows, int Columns)
{
	system("COLOR 6F");
	cout << "\n\t\t\t\"Truth Table\"\n"
		<< "\t-------------------------------------------\n\t";
	for (int i = 0; i < Columns - 1; i++)
	{
		cout << "|  " << Operands[i] << "  ";
	}
	cout << "| Result |\n\t ";
	for (int k = 0; k < Columns; k++)
	{
		cout << "-------";
	}
	cout << "\n\t";
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			if (j == Columns - 1)
			{
				cout << "|    " << Array[i][j] << "   ";
			}
			else
			{
				cout << "|  " << Array[i][j] << "  ";
			}
		}
		cout << "|" << "\n\t ";
		for (int k = 0; k < Columns; k++)
		{
			cout << "-------";
		}
		cout << "\n\t";
	}
}
/////////////////////////////
//------>> Input function
//This function will take input, check its validity & generate a 
//table with binary combinations
void TruthTableGenerator()
{
	string InputString = "\0", UniqueOperand = "\0";
	cout << "\n\t----------------<< Input >>----------------\n"
		<< "\n\tPlease Enter the Expression\n\n\t";
	getline(cin, InputString);
	cout << "\t-------------------------------------------";
	//for (int i = 0;i < InputString.length();i++)//Converting string to Upper case.
	//{
	//	InputString[i] = toupper(InputString[i]);
	//}
	///////////////////////////////
	bool validate = true;//Checking Whether the Input is Correct
	////////////////////////////////
	for (int i = 0; i < InputString.length(); i++)
	{
		if (!IsOperator(InputString[i]) && !isalpha(InputString[i]))
		{
			validate = false;
			break;
		}
	}
	if (!validate)
	{
		system("COLOR 4f");
		cout << "\n\t----------------<< Attention >>----------------\n"
			<< "\n\tProvided Expression is \"Invalid\"\n"
			<< "\n\t-------------------------------------------\n";
	}
	else
	{
		////////////////////
		bool check;
		////////////////////
		for (int i = 0; i < InputString.length(); i++)
		{
			if (!IsOperator(InputString[i]))//not assuming space
			{
				check = false;// if same character come again
				for (int j = 0; j < UniqueOperand.length(); j++)
				{
					if (InputString[i] == UniqueOperand[j])
					{
						check = true;
						break;
					}
				}
				if (!check)
				{
					UniqueOperand += InputString[i];
				}
			}
		}
		///////////////////////////////////////////////////////////////////
		int Rows = pow(2, UniqueOperand.length());//number of rows of table
		int Columns = UniqueOperand.length() + 1;//number of columns of table
		//+1 means a column for result in the array, Along with initialization
		int** Table = new int* [Rows];
		for (int i = 0; i < Rows; i++)
		{
			Table[i] = new int[Columns];
			for (int j = 0; j < Columns; j++)
			{
				Table[i][j] = 0;
			}
		}
		///////////////////////////////////////////
		//Generatiing Binary of Each Number
		int Binaryof = 0;
		for (int i = 0; i < Rows; i++)
		{
			Binaryof = i;
			for (int j = Columns - 2; j >= 0 && Binaryof != 0; j--)
			{
				//contineuos division of number provided
				Table[i][j] = Binaryof % 2;
				Binaryof /= 2;
			}
		}
		/////////////////////////////////////
		Stack StackCreated(InputString.length());
		StackCreated.ToPostfix(InputString);//by reference string is passed
		////////////////////////////////////
		string Expression = "\0";//making combination of values
		/////////////////////////////
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < InputString.length(); j++)//postfix expression
			{
				for (int k = 0; k < UniqueOperand.length(); k++)
				{
					if (InputString[j] == UniqueOperand[k] || IsOperator(InputString[j]))
					{
						if (IsOperator(InputString[j]))
						{
							Expression += InputString[j];
							break;
						}
						else
						{
							Expression += to_string(Table[i][k]);
							break;
						}
					}
				}
			}
			Table[i][Columns - 1] = PostfixEvaluation(Expression);//saving the result
			Expression = "\0";
		}
		Display(UniqueOperand, Table, Rows, Columns);
		/////////////////////////////////
		for (int i = 0; i < Rows; i++)
		{
			delete[] Table[i];
		}
		delete[] Table;
		Table = nullptr;
	}
}
//////////////////////////////////////////////////

int main()
{
	bool MenuBreak = false;
	int Option;
	do
	{
		system("COLOR 3F");
		cout << "\n\tPlease Select an Option from Following!"
			<< "\n\tPress 1 ===>> Truth Table"
			<< "\n\tPress 2 ===>> Exit"
			<< "\n\n\tSelect Option = ";
		cin >> Option;
		while (cin.fail())
		{
			system("COLOR 4F");
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n\n\tSelect Option = ";
			cin >> Option;
		}
		system("cls");
		system("COLOR 5F");
		switch (Option)
		{
		case 1:
			cin.ignore();
			TruthTableGenerator();
			cout << "\n\n\t";
			system("pause");
			system("cls");
			break;
		case 2:
			MenuBreak = true;
			break;
		default:
			cout << "\n\tPlease Select a Valid Option!\n\tTry Again!\n";
			break;
		}
	} while (!MenuBreak);

	system("pause>0");
	return 0;
}
