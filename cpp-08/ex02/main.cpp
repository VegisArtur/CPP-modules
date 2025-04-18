#include "MutantStack.hpp"

#include "deque"

// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }

static void printChar(MutantStack<char> stack)
{
	MutantStack<char>::iterator it = stack.end();
	it--;
	std::cout << *it << std::endl;
}

int main()
{
	MutantStack<int> mstack;
	
	mstack.push(0);
	for (int i = 1; i < 10; i++)
	{
		mstack.push(i * 3 + mstack.top());
		std::cout << mstack.top() << std::endl;
	}
	std::cout << "Size of the current stack = " << mstack.size() << std::endl;

	try
	{
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		{
			// std::cout << *it << std::endl;
			// it--;
			// std::cout << *it << std::endl;

			// std::deque<int> myDeque = {10, 20, 30, 40, 50};
			// std::deque<int>::iterator it;

			// std::cout << *it << std::endl;
			// it--;
			// std::cout << *it << std::endl;
		}
		
		ite--;
		while (it != ite)
		{
			std::cout << *it << " != " << *ite << std::endl;
			it++;
		}
		std::cout << *it << " = " << *ite << std::endl;
		
		// it++;
		// std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::stack<int> s(mstack);
	std::cout << "Size of the new stack = " << s.size() << std::endl;

	std::cout << "---------- ||| ----------" << std::endl;

	MutantStack<std::string> stringStack;

	std::string test = "main testing";
	stringStack.push(test);
	stringStack.push("extra testing");

	MutantStack<std::string>::iterator it = stringStack.begin();

	std::cout << *it << std::endl;
	it++;
	std::cout << *it << std::endl;
	// it++;
	// std::cout << *it << std::endl;

	std::cout << "---------- ||| ----------" << std::endl;

	MutantStack<char> charStack;

	charStack.push('a');
	printChar(charStack);
	charStack.push('b');
	printChar(charStack);
	charStack.push('c');
	printChar(charStack);
	charStack.pop();
	printChar(charStack);
}