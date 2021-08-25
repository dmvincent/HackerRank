/* vector_sort.cpp */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	//  Get Number of itegers and enter them
	int N{0};
	int n{0};

	std::cin >> N;
	
	std::vector<int> v;
	for(int i = 0; i < N; i++) {
		std::cin >> n;
		v.push_back(n);	
	}

	sort(v.begin(), v.end());
	
	for(auto vee: v)
		std::cout << vee << " " << std::flush;

	return 0;
}
