/* victor_erase.cpp */

#include <iostream>
#include <vector>
#include <string>

int main() {
	int N{0};
	int n{0};
	std::vector<int> v;
	int pos{0};
	int rangeBeg{0}, rangeEnd{0};

	std::cin >> N;
	for(int i = 0; i < N; i++) {
		std::cin >> n;
		v.push_back(n);
	}

	std::cin >> pos;

	std::cin >> rangeBeg >> rangeEnd;

	int i = 1;
	for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		if(i == pos) {
			v.erase(it);
			it++;
		}	
		i++;
	}

	i = 1;
	for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		if(i >= rangeBeg && i<rangeEnd) {
			v.erase(it);
			it--;
		}
		i++;
	}

	std::cout << v.size() << std::endl;
	for(auto vec: v)
		std::cout << vec << " " << std::flush;
	std::cout << std::endl;
	return 0;
}
