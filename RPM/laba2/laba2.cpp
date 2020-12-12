#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{	
	string input;
	cout << "Выражение: ";
	getline(cin, input);

	stack<int> operands;
	stack<int> stack_of_numbers;

	for (int i = 0; i < input.size(); ++i)
	{
		if ((int) input[i] >= 48 && (int) input[i] <= 57)
		{
			stack_of_numbers.push(((int) input[i]) - 48);
		}			

		else if (input[i] == ' ')
		{
			if (stack_of_numbers.size())
			{
				int number = 0;
				int stack_of_numbers_size = stack_of_numbers.size();	

				for (int j = 0; j < stack_of_numbers_size; ++j)
				{
					number += stack_of_numbers.top() * pow(10, j);
					stack_of_numbers.pop();
				}

				operands.push(number);
			}
		}

		else 
		{
			int first_number  = operands.top();
			operands.pop();
			int second_number = operands.top();

			int result;
			if 		(input[i] == '+') result = second_number + first_number;
			else if (input[i] == '-') result = second_number - first_number;
			else if (input[i] == '*') result = second_number * first_number;
			else if (input[i] == '/') result = second_number / first_number;
		
			operands.push(result);
		}
	}

	cout << endl << operands.top() << endl;

	return 0;
} 