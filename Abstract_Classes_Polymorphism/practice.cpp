#include <iostream>
#include <map>

using namespace std;

int main() {

	map<int, string> students;
	students.insert(make_pair(2, "jasmine"));
	students.insert(make_pair(3, "daniel"));
	students.insert(make_pair(12, "cara"));
	students.insert(make_pair(9, "lemons"));
	students.insert(make_pair(7, "apples"));
	students.insert(make_pair(1, "karen"));

	auto it = students.find(9);
	if(it != students.end())
		cout << it->second << endl;
	return 0;
}
