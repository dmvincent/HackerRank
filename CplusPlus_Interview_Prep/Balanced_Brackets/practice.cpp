#include <iostream>
#include <bits/stdc++.h>
#include <typeinfo>

using namespace std;

int main() {
	string str = "[{{[";
	int i = 1;
	for(auto c: str) {
		cout << "I: " << i << endl;
		switch(c) {
			case('{'):
			case('['):
				std::cout << c <<  "yabitsh" << std::endl;
				break;
		}
		i++;
	}

	return 0;	
}
