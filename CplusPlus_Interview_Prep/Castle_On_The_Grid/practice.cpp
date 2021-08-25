#include <bits/stdc++.h>

using namespace std;

int main() {
	//cout << str1 << "are good"  << endl;
	//cout << rtrim(str1) << "are good" << endl;
	//vector<int> start 	
	queue<array<int, 2>> nodes;
	//nodes.push(
	//int start[2]{1,2};
	//int end[2]{3,5};
	////nodes.push(start);
	////cout << *nodes.back() << endl;
	//nodes.push(end);
	////cout << *(nodes.back()+1) << endl;
	//int hold[2]{};
	//hold[0] = *nodes.front();
	//hold[1] = *(nodes.front()+1);
	//cout << hold[0] << ":" << hold[1] << endl;

	//queue<int> nodes;
	//nodes.push(1);
	//nodes.push(2);
	//nodes.push(3);
	//
	//cout << nodes.front() << endl;
	//nodes.pop();
	//
	//cout << nodes.front() << endl;
	//nodes.pop();
	//
	//cout << nodes.front() << endl;
	//nodes.pop();

	//nodes.push(insert);

	array<int,2> a2{{2,4}};
	array<int, 2> a3{{2,5}};

	nodes.push(a2);

	if(nodes.front() == a3)
		cout << "Match!" << endl;
	else
		cout << "No Match!" << endl;
	//while(!nodes.empty()) {
	//	//cout << "(" << *nodes.front() << "," << *(nodes.front()+1) << ")" << endl;	
	//	a2 = array.front();
	//	cout << a2 << endl;
	//	nodes.pop();
	//}
	
	return 0;
}

