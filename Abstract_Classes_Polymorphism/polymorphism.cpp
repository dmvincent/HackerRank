#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache: protected Cache {
public:
	LRUCache() = default;
	LRUCache(int capacity) {
		cp = capacity;	
	}
	
	virtual void set(int thisKey, int thisValue) {
		Node n1(thisKey, thisValue);
		pair<int, Node*> p = make_pair(thisKey, &n1);
		mp.insert(p);
	}
	
	virtual int get(int thisKey) { 
		cout << "In get" << endl;
		auto it = mp.find(thisKey);
		if (it != mp.end()){
			Node *n1 = it->second;
			cout << "Key: " << n1->key << endl;
			//cout << "Value: " << n1.value << endl;
			return it->second->value;
		}
		else
			return -1;
	}

};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
