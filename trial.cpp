#include <iostream>
#include <deque>

using namespace std;

int main() {
	string str = "Hello, welcome to \"cleverTown\"";
	size_t foundQuote1 = str.find("\"");
	cout << str << endl;
	cout << "Found first quote at" << foundQuote1 << endl;
	
	size_t foundQuote2 = str.find("\"", foundQuote1+1);
	cout << "Found second quoet at: " << foundQuote2 << endl;
	cout << str.substr(foundQuote1 + 1, foundQuote2 - foundQuote1 - 1) << endl;
	return 0;

}
