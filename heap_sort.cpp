#include <bits/stdc++.h>

using namespace std;

int main(){
	priority_queue<int> q;
	vector<int> sorted;
	int size = 0;
	cin >> size;
	int temp = 0;
	for(int i=0; i < size; i++){
		cin >> temp;
		q.push(temp);
	}
	for(int i=0; i < size; i++){
		sorted.push_back(q.top());
		q.pop();
	}

	for(auto i=sorted.rbegin(); i != sorted.rend(); i++){
		cout << *i << " ";
	}
	cout << endl;
}
