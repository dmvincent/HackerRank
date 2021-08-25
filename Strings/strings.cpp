#include <iostream>
#include <string>

int main() {
	std::string string1, string2;

	std::cin >> string1 >> string2;

	std::cout << string1.size() << " " << string2.size() << std::endl;
	
	std::cout << string1 << string2 << std::endl;

	// Output strings with first letter swapped
	for(int i = 0; i < string1.size(); i++) {
		if(i == 0)
			std::cout << string2[i];
		else
			std::cout << string1[i];
	}
	std::cout << " ";

	for(int i = 0; i < string2.size(); i++) {
		if(i == 0)
			std::cout << string1[i];
		else
			std::cout << string2[i];
	}

	return 0;
}
