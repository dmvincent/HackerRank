#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */   

	// Get the number of lines in the program and queries from user input
	int N{0}, Q{0};
	cin >> N >> Q;
	//cout << endl;

	// Read the program from user input and store lines in a vector of strings
	vector<string> programLines;
	string line;
	for(int i = 0; i <= N; i++) {
		getline(cin, line);
		if(i == 0)
			continue;

		programLines.push_back(line);
	}

	// Read the queries from the user input
	vector<string> queryRequests;
	for(int i = 0; i < Q; i++) {
		getline(cin, line);
		queryRequests.push_back(line);
	}

	// Look values to return
	vector<bool> isMultiTag;
	vector<string> toi;
	vector<string> attoi;

	vector<vector<string> > tagAtts(Q, vector<string>(2));

	for(auto q: queryRequests) {
		string tagReq;

		size_t tildePos = q.find("~");
		size_t periodPos = q.find(".");
		
		if(periodPos != string::npos) {
			isMultiTag.push_back(true);
			periodPos = q.find_last_of(".");
			
		}
		else {
			isMultiTag.push_back(false);
			periodPos = 0;
		}

		if(periodPos == 0)
			tagReq = q.substr(periodPos, tildePos - periodPos);
		else
			tagReq = q.substr(periodPos+1, tildePos - periodPos-1);

		attoi.push_back(q.substr(tildePos+1, q.size()));
	
		toi.push_back(tagReq);

	}


	for(int row = 0; row < tagAtts.size(); row++) {
		for(int col=0; col<tagAtts[row].size(); col++) {

		}	
	}

	// Look for tags and attributes in HRML
	size_t foundTag;
	
	for(int i = 0; i < toi.size(); i++) {
		for(auto p: programLines) {
			// Look for the first instance of the tag
			// If its not found, get out of the current loop iteration, but continue the search
			foundTag = p.find(toi[i]);
			if(foundTag!=string::npos) {
				size_t foundAtt;
				// Look the the attribute
				// If its not found, display "Not Found!"
				foundAtt = p.find(attoi[i]);
				size_t foundQuote;
				size_t foundQuote2;
				if(foundAtt!=string::npos) {
					foundQuote = p.find("\"", foundAtt);
					foundQuote2 = p.find("\"", foundQuote + 1);

					cout << p.substr(foundQuote + 1, foundQuote2 - foundQuote - 1) << endl;
				}
				else
					cout << "Not Found!" << endl;
				
				break;
			}
			else
				continue;
		}
	}
	
	return 0;

}
