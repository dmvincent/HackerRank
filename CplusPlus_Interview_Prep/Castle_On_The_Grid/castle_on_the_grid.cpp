#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumMoves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY grid
 *  2. INTEGER startX
 *  3. INTEGER startY
 *  4. INTEGER goalX
 *  5. INTEGER goalY
 */

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
	// Initialize
	int N = grid.size();	
	array<int, 2> start{{startX, startY}};
	array<int, 2> goal{{goalX, goalY}};

	// Create queue to push Explored Nodes to
	queue<array<int, 2>> nodes;

	// Create grid to store color flags
	vector<vector<char>> color(N, vector<char>(N, 'w'));

	// Create gide to store predecessors
	vector<vector<array<int, 2>>> pred(N, vector<array<int, 2>>(N, array<int ,2>{{-1,-1}}));

	// Start running through the grid and populating your queue
	int i = 0;
	array<int, 2> hold{{0,0}};
	array<int, 2> insert{{0,0}};
	int m0{}, n0{};
	nodes.push(start);
	bool t = false;
	while(!t) {
		// Pop next node from queue making sure to store value
		m0 = (nodes.front())[0];
		n0 = (nodes.front())[1];
		cout << "We are at node (" << m0 << "," << n0 << ")" << endl;
		nodes.pop();

		// Change color indicating that we've visited the node
		if(color[m0][n0] == 'r')
			break;

		color[m0][n0] = 'r';

		// Push valid nodes to queue
		for(int n = 0; n < N; n++) {
			if(n == n0)
				continue;
			if(grid[m0][n] == 'X')
				break;
			if(color[m0][n] == 'w') {
				color[m0][n] = 'g';
				pred[m0][n] = array<int, 2>{{m0,n0}};
				nodes.push(array<int, 2>{{m0, n}});
				//for(int l = 0; l < color.size(); l++) {
				//	for(int j = 0; j < color[l].size(); j++) {
				//		cout << "\t" << color[l][j] << " ";
				//	}
				//	cout << endl;
				//}
				//for(int l = 0; l < pred.size(); l++) {
				//	for(int j = 0; j < pred[l].size(); j++) {
				//		cout << "\t" << "(" << (pred[l][j])[0] << "," << (pred[l][j])[1] << ") ";
				//	}
				//	cout << endl;
				//}
				//cout << endl;
				//cout << endl;
				if(nodes.back() == goal) {
					//cout << "Found: (" << (nodes.back())[0] << "," << (nodes.back())[1] << ")" << endl;
					t = true;
				}
			}
		}	

		for(int m = 0; m < N; m++) {
			if(m == m0)
				continue;
			if(grid[m][n0] == 'X')
				break;
			if(color[m][n0] == 'w') {
				color[m][n0] = 'g';
				nodes.push(array<int, 2>{{m, n0}});
				pred[m][n0] = array<int, 2>{{m0,n0}};
				//for(int l = 0; l < color.size(); l++) {
				//	for(int j = 0; j < color[l].size(); j++) {
				//		cout << "\t" << color[l][j] << " ";
				//	}
				//	cout << endl;
				//}
				//for(int l = 0; l < pred.size(); l++) {
				//	for(int j = 0; j < pred[l].size(); j++) {
				//		cout << "\t" << "(" << (pred[l][j])[0] << "," << (pred[l][j])[1] << ") ";
				//	}
				//	cout << endl;
				//}
				//cout << endl;
				//cout << endl;

				if(nodes.back() == goal) {
					//cout << "Found: (" << (nodes.back())[0] << "," << (nodes.back())[1] << ")" << endl;
					t = true;
				}
			}
		}
		//cout << endl;
		//cout << endl;
	}

	// Use predecessor grid to create the path in a stack
	stack<array<int,2>> path;
	int stepX{}, stepY{};
	array<int, 2> step2{};
	path.push(goal);
	while(path.top() != start){
		stepX = path.top()[0];
		stepY = path.top()[1];
		step2 = pred[stepX][stepY];
		path.push(step2);
	}
	//cout << "Steps required: " << path.size() - 1 << endl;
	//while(!path.empty()) {
	//	cout << "(" << (path.top())[0] << "," << (path.top())[1] << ")" << endl;
	//	path.pop();
	//}

	return (path.size() - 1);
}

//int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
//	int N = grid.size();	
//	array<int, 2> start{{startX, startY}};
//	array<int, 2> goal{{goalX, goalY}};
//	queue<array<int, 2>> nodes;
//	vector<vector<char>> color(N, vector<char>(N, 'w'));
//	vector<vector<array<int, 2>>> pred(N, vector<array<int, 2>>(N, array<int ,2>{{-1,-1}}));
//	int i = 0;
//	array<int, 2> hold{{0,0}};
//	array<int, 2> insert{{0,0}};
//	int m0{}, n0{};
//	nodes.push(start);
//	bool t = false;
//	while(!t) {
//		m0 = (nodes.front())[0];
//		n0 = (nodes.front())[1];
//		nodes.pop();
//		if(color[m0][n0] == 'r')
//			break;
//		color[m0][n0] = 'r';
//		for(int n = 0; n < N; n++) {
//			if(n == n0)
//				continue;
//			if(grid[m0][n] == 'X')
//				break;
//			if(color[m0][n] == 'w') {
//				color[m0][n] = 'g';
//				pred[m0][n] = array<int, 2>{{m0,n0}};
//				nodes.push(array<int, 2>{{m0, n}});
//				if(nodes.back() == goal) {
//					t = true;
//				}
//			}
//		}	
//		for(int m = 0; m < N; m++) {
//			if(m == m0)
//				continue;
//			if(grid[m][n0] == 'X')
//				break;
//			if(color[m][n0] == 'w') {
//				color[m][n0] = 'g';
//				nodes.push(array<int, 2>{{m, n0}});
//				pred[m][n0] = array<int, 2>{{m0,n0}};
//				if(nodes.back() == goal) {
//					t = true;
//				}
//			}
//		}
//	}
//	stack<array<int,2>> path;
//	int stepX{}, stepY{};
//	array<int, 2> step2{};
//	path.push(goal);
//	while(path.top() != start){
//		stepX = path.top()[0];
//		stepY = path.top()[1];
//		step2 = pred[stepX][stepY];
//		path.push(step2);
//	}
//	return (path.size() - 1);
//}



int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));
    ofstream fout("output.txt");

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int startX = stoi(first_multiple_input[0]);

    int startY = stoi(first_multiple_input[1]);

    int goalX = stoi(first_multiple_input[2]);

    int goalY = stoi(first_multiple_input[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

