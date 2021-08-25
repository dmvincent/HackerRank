#include <sstream>
#include <iostream>
#include <vector>

using namespace std;


vector<int> parseInts(string str) {
	vector<int> numbers;
	stringstream ss(str);

	char ch;

	int n{0};

	int num_commas{0};

	for(auto i: str) {
		if(i == ',')
			num_commas++;
	}

	for(int i = 0; i <= num_commas; i++) {
		ss >> n >> ch;
		numbers.push_back(n);
	}

	return numbers;
}



int main() {

	vector<int> numbers;

	string inputString;

	cout << "Enter string: " << flush;
	cin >> inputString;
	cout << endl;

	numbers = parseInts(inputString);
	
	int i{0};
	for(auto n: numbers) {
		cout << n << endl;
	}

	return 0;
}
