#include <iostream>
#include <set>

int main() {
	int numQ{};
	std::cin >> numQ;
	
	std::set<int> values{};
	
	int query{}, arg{};
	while(numQ--) {
		std::cin >> query >> arg;
		if(query ==1)
			values.insert(arg);
		else if(query == 2) {
			if(values.find(arg) != values.end())
				values.erase(values.find(arg));
			else
				continue;
		}
		else
			if(values.find(arg) != values.end())
				std::cout << "Yes\n";
			else
				std::cout << "No\n";
			
	}

	return 0;
}
