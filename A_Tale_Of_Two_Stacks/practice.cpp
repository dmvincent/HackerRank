#include <iostream>
#include <stack>

int main() {
	std::stack<int> s1;
	s1.push(4);
	s1.push(3);
	s1.push(8);
	s1.push(1);
	s1.push(5);
	s1.push(9);

	s1.top();

	std::cout << s1.top() << std::endl;
	return 0;
}
