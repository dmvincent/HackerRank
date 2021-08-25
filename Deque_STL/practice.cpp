#include <iostream>
#include <deque>

using namespace std;

int main() {
	deque<int> myDeque;
	myDeque.push_back(3);
	myDeque.push_back(9);
	myDeque.push_back(5);
	myDeque.push_back(8);
	myDeque.push_back(2);

	int i = 1;
	//for(deque<int>::iterator it = myDeque.begin(); it != myDeque.end(); it++) {
	//	cout << i << ": " << *it << endl;
	//	i++;
	//}
	for(deque<int>::iterator it = myDeque.begin(); it != myDeque.end(); it++) {
		if(*it == 5)
			myDeque.erase(it);
		cout << i << ": " << *it << endl;
		i++;
	}
	return 0;
}
