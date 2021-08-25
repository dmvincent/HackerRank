#include <iostream>
#include <map>

using namespace std;

int main() {
	std::multimap<std::string, int> scores{};
	int numQueries{};
	std::cin >> numQueries;
	
	int queryType{}, score{}, totalScore{};
	std::string name{};
	std::pair<std::string, int> studentScore{};

	pair<multimap<string,int>::iterator, multimap<string, int>::iterator> res{};

	while(numQueries--) {
		totalScore = 0;
		cin >> queryType;
		

		if(queryType == 1) {
			std::cin >> name >> score;		
			studentScore = make_pair(name, score);
			scores.insert(studentScore);
		}
		
		else if(queryType == 2) {
			cin >> name;
			res = scores.equal_range(name);	
			scores.erase(res.first, res.second);
		}

		else {
			std::cin >> name;
			res = scores.equal_range(name);		
			for(multimap<string, int>::iterator it = res.first; it != res.second; it++)
				totalScore += it->second;
			cout << totalScore << "\n";
		} 
	}

	return 0; 
}
