#include <bits/stdc++.h>
#include <list>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



int main()
{
    string n_temp;

    vector<string> numberStrings{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    if(n >=1 && n <=9 )
	cout << numberStrings[n-1];
    else
	cout << "Greater than 9" << endl;

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
