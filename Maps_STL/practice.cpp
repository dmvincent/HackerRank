#include <iostream>
#include <map>
#include <typeinfo>

int main() {
	std::multimap<std::string, int> mymm;
	std::pair<std::string, int> p1;
	p1 = std::make_pair("Daniel", 3);
	mymm.insert(p1);	
	p1 = std::make_pair("Jeff", 8);
	mymm.insert(p1);	
	p1 = std::make_pair("David", 4);
	mymm.insert(p1);	
	p1 = std::make_pair("Jeff", 7);
	mymm.insert(p1);	
	p1 = std::make_pair("Tony", 2);
	mymm.insert(p1);	

	//std::multimap<std::string, int>::iterator positions = mymm.find("Jeff");
	//mymm.erase(positions, ++mymm.end());

	//for(std::multimap<std::string, int>::iterator its = mymm.begin(); its != mymm.end(); its++) 
	//	std::cout << its->first << ": " << its->second << std::endl;

	std::pair<std::multimap<std::string, int>::iterator, std::multimap<std::string, int>::iterator> positions = mymm.equal_range("Jeff");
	mymm.erase(positions.first, positions.second);

	for(std::multimap<std::string, int>::iterator its = mymm.begin(); its != mymm.end(); its++) 
		std::cout << its->first << ": " << its->second << std::endl;



	return 0;
}
