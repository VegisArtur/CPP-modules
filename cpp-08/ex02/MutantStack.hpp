#pragma once

#include <stack>
#include <iostream>
#include <iterator>

// template<typename T>
// class MutantStack
// {
// 	private:
// 		std::deque<T> stack;

// 	public:
// 		MutantStack() {}
// 		MutantStack(const MutantStack& other) : stack(other.stack) {}
// 		~MutantStack() {}
// 		MutantStack operator=(const MutantStack& other)
// 		{
// 			if (*this != other) 
// 				stack = other.stack;
// 			return *this;
// 		}
		
// 		std::deque<T>& getDeque() { return stack; }

// 		const std::deque<T>& getDeque() const { return stack; }

// 		void push(const T& value) { stack.push_back(value); }

// 		void pop()
// 		{
// 			if (!empty())
// 				stack.pop_back();
// 		}

// 		T& top()
// 		{
// 			if (!empty())
// 				return stack.back();
// 			throw std::out_of_range("Stack is empty");
// 		}

// 		const T& top() const
// 		{
// 			if (!empty())
// 				return stack.back();
// 			throw std::out_of_range("Stack is empty");
// 		}

// 		bool empty() const { return stack.empty(); }

// 		size_t size() { return stack.size(); }

// 		typedef typename std::deque<T>::iterator iterator;
// 		typedef typename std::deque<T>::const_iterator const_iterator;

// 		iterator begin() { return stack.begin(); }

// 		iterator end() { return stack.end(); }

// 		const_iterator begin() const { return stack.begin(); }

// 		const_iterator end() const { return stack.end(); }

// 		typedef typename std::deque<T>::reverse_iterator reverse_iterator;
// 		typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

// 		reverse_iterator rbegin() { return stack.rbegin(); }

// 		reverse_iterator rend() { return stack.rend(); }

// 		const_reverse_iterator rbegin() const { return stack.rbegin(); }

// 		const_reverse_iterator rend() const { return stack.rend(); }
// };

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
	typedef typename std::stack<T>::container_type container_type;
	MutantStack() = default;
	MutantStack(const MutantStack& other) = default;
	~MutantStack() = default;
	MutantStack& operator=(const MutantStack& other)
	{
		if (this != &other)
			std::stack<T>::operator=(other);
		return *this;
	}
	
	typedef typename container_type::iterator iterator;
	typedef typename container_type::const_iterator const_iterator;

	iterator begin() { return this->c.begin(); }

	iterator end() { return this->c.end(); }

	const_iterator begin() const { return this->c.begin(); }

	const_iterator end() const { return this->c.end(); }

	typedef typename container_type::reverse_iterator reverse_iterator;
	typedef typename container_type::const_reverse_iterator const_reverse_iterator;

	reverse_iterator rbegin() { return this->c.rbegin(); }

	reverse_iterator rend() { return this->c.rend(); }

	const_reverse_iterator rbegin() const { return this->c.rbegin(); }

	const_reverse_iterator rend() const { return this->c.rend(); }
};