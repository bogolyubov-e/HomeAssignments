#include <iostream>

int main()
{
	std::string input;
	std::getline(std::cin, input);
	const size_t input_size = input.size();
	const size_t stack_size = (input_size + 1) / 2;
	if (input[input_size - 1] != ' ') input = input + ' ';

	int* stack = new int[stack_size];
	int* header = stack - 1;
	size_t  index = 0;

	while (index < input_size)
	{
		int result;
		const size_t start = index;

		while(input[index] != ' ') index++;

		std::string token = input.substr(start, index - start);
		bool oper_add, oper_sub, oper_prod, oper_div;
		bool is_number = true;
		oper_add = token[0] == '+';
		oper_sub = token[0] == '-';
		oper_prod = token[0] == '*';
		oper_div = token[0] == '/';

		if (token.size() == 1 && (oper_add || oper_sub || oper_prod || oper_div))
		{
			int num1 = *(header--);
			int num2 = *(header--);
			is_number = false;
			if (oper_add) result = num2 + num1;
			else if(oper_sub) result = num2 - num1;
			else if(oper_prod) result = num2 * num1;
			else result = num2 / num1;
		}

		if(is_number) result = stoi(token);

               	*(++header) = result;
		index++;
	}
	std::cout << *(header) << std::endl;
	delete[] stack;
	return 0;
}
