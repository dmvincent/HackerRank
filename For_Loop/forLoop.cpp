/* forLoop.cpp */

#include <iostream>
#include <map>

using namespace std;

int main() {
	map<int, string> numberSets;
	numberSets[1] = "one";
	numberSets[2] = "two";
	numberSets[3] = "three";
	numberSets[4] = "four";
	numberSets[5] = "five";
	numberSets[6] = "six";
	numberSets[7] = "seven";
	numberSets[8] = "eight";
	numberSets[9] = "nine";

	int a{0}, b{0};
	cin >> a >> b;

	for(int i = a; i <= b; i++) {
		if(i >=1 && i <= 9)
			cout << numberSets[i] << endl;

		if(i > 9 && ((i%2) != 0))	//Check if odd
			cout << "odd" << endl;

		if(i > 9 && ((i%2) == 0))	//Check if even
			cout << "even" << endl;
	}

	return 0;
}
