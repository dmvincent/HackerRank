/* lower_bound_stl.cpp */
#include <iostream>
#include <vector>

int main() {
	// Get length of input vector
	int N{0};
	std::cin >> N;

	// Get the vector
	int n{0};
	std::vector<int> vec;
	for(int i = 0; i < N; i++) {
		std::cin >> n;
		vec.push_back(n);
	}
		
	// Get number of queries
	int Q{0};
	std::cin >> Q;

	// Get the queries
	int q[Q];
	for(int i = 0; i < Q; i++) {
		std::cin >> q[i];
	}

	for(int i = 0; i < Q; i++) {
		bool found = false;
		std::vector<int>::iterator lower;	
		lower = std::lower_bound(vec.begin(), vec.end(), q[i]);
		if(vec[lower - vec.begin()] == q[i])
			std::cout << "Yes " << (lower - vec.begin()) + 1<< std::endl;
		else
			std::cout << "No " << (lower - vec.begin()) + 1 << std::endl;
	}

	return 0;
}
