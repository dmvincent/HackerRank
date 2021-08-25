#include <iostream>
#include <deque> 

#include <chrono>
#include <thread>

using namespace std;

void printKMax(int arr[], int n, int k){

	// Getting Start time for Current Test Case
	deque<int> deck(k);
	int i;

	for (i = 0; i < k; ++i) {
		while((!deck.empty()) && arr[i] >= deck.back()) {
			deck.pop_back();
		}
		deck.push_back(i);
	}

	for(; i < n; ++i) {
		cout << arr[deck.front()] << " ";

		while((!deck.empty()) && deck.front() <= (i-k))
			deck.pop_front();
		
		while((!deck.empty()) && arr[i] >= arr[deck.back()])
			deck.pop_back();

		deck.push_back(i);
	}

	cout << arr[deck.front()] << endl;

}


int main(){
	// Getting some time info
	
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
	    	cin >> n >> k;
	    	int i;
	    	int arr[n];
	    	for(i=0;i<n;i++)
	      		cin >> arr[i];
	    	printKMax(arr, n, k);
	    	t--;
  	}
  	return 0;
}
