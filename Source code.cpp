#include <bits/stdc++.h>
using namespace std;

const string initialState = "xxx_ooo";
const string finalState = "ooo_xxx";
set<string> Set;

struct tree {   
    string s;
    struct tree *one, *two, *three, *four;
    struct tree *parent;
};

struct tree *newNode(string str) {
    struct tree *node;
    node = (struct tree*) malloc(sizeof(struct tree));
    node->s = str;
    node->one = nullptr;
    node->two = nullptr;
    node->three = nullptr;
    node->four = nullptr;
    return node;
}

void display(struct tree *node) {
    struct tree * par = node->parent;
    while(node->parent != nullptr) {
        cout << node->s << endl;
        node = par;
        par = node->parent;
    }
    cout << node->s << endl;
}
string nextState(string s, int choice) {
    int index;
    for(int i = 0; i < static_cast<int>(s.size()); i++) {
        if(s[i] == '_') {
            index = i;
        }
    }    
    if(index + choice >= 0 && index + choice < 7)
        swap(s[index], s[index + choice]);
    return s;
}

void insertUpdated(struct tree *curr, string str, int num) {
    switch(num) {
        case 1: curr->one = newNode(str);
            curr->one->parent = curr;
            break;
        case 2: curr->two = newNode(str);
            curr->two->parent = curr;
            break;
        case 3: curr->three = newNode(str);
            curr->three->parent = curr;
            break;
        case 4: curr->four = newNode(str);
            curr->four->parent = curr;
            break;
    }
}

void generateChild(struct tree *root) {
    queue<struct tree*> q;
    struct tree* ans;
    q.push(root);
    int cnt = 0;
    while(true) {
        struct tree *temp = q.front();
        q.pop();
        cnt++;
        if(temp->s == finalState){
            ans = temp;
            break;
        }
        string s1, s2, s3, s4, curr = temp->s;
        s1 = nextState(curr,-2);
        s2 = nextState(curr,-1);
        s3 = nextState(curr,1);
        s4 = nextState(curr,2);
        insertUpdated(temp, s1, 1);
        insertUpdated(temp, s2, 2);
        insertUpdated(temp, s3, 3);
        insertUpdated(temp, s4, 4);
        if(Set.count(s1) == 0) {
        	q.push(temp->one);
        	Set.insert(s1);
        }
        if(Set.count(s2) == 0) {
        	q.push(temp->two);
        	Set.insert(s2);
        }
        if(Set.count(s3) == 0) {
        	q.push(temp->three);
        	Set.insert(s3);
        }
        if(Set.count(s4) == 0) {
        	q.push(temp->four);
        	Set.insert(s4);
        }
    }   
    display(ans);
}

int main() {
	struct tree *root = newNode(initialState);
    generateChild(root);
	return 0;
}