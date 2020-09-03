//Author: kb_1024bytes
#include <bits/stdc++.h>
using namespace std;

const string initialState = "xxx_ooo";
const string finalState = "ooo_xxx";

class Node {
	public:
		string s;
		Node *parent = nullptr;
		Node(string val, Node* par) {
			s = val;
			if(par == nullptr) {
				parent = nullptr;
			} else {
				parent = par;
			}
		}	
};

string nextState(string s, int choice) {
    int index = 100;
    for(int i = 0; i < static_cast<int>(s.size()); i++) {
        if(s[i] == '_') {
            index = i;
        }
    }    
    if(index < 0 || index > 6) return "NO";
    if(index + choice >= 0 && index + choice < 7) {
        swap(s[index], s[index + choice]);
    	return s;
    }
    return "NO";
}

void display(Node *node) {
	vector<string> ans;
	while(node != nullptr) {
		ans.emplace_back(node->s);
		node = node->parent;
	}
	reverse(ans.begin(), ans.end());
	for(auto x: ans) cout << x << '\n';
}

int main() {
	set<string> visited;
	Node *node = new Node(initialState, nullptr);
	vector<Node*> queue;
	queue.emplace_back(node);
	visited.insert(node->s);
	for(int j = 0; j < static_cast<int> ((queue).size()); j++) {
		Node *currNode = queue[j];
		string currString = currNode->s;
		if(currString == finalState) {
			display(currNode);
			return 0;
		}
		vector<string> states(5);
		for(int i = 0; i < 5; i++) {
			states[i] = nextState(currString, i - 2);
		}
		for(int i = 0; i < 5; i++) {
			if(i == 2 || states[i] == "NO" || visited.count(states[i]) == 1) continue;
			Node *child = new Node(states[i], currNode);
			queue.emplace_back(child);
			visited.insert(states[i]);
		}
	}
	return 0;
}
