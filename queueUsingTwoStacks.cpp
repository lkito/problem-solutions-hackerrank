//https://www.hackerrank.com/challenges/queue-using-two-stacks/problem


#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


int main() {
    stack<int> head, backUp;
    int n, type, cur;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> type;
        if(type == 1){
            cin >> cur;
            backUp.push(cur);
        } else {
            if(head.empty()){
                int size = backUp.size();
                for (int k = 0; k < size; k++) {
                  head.push(backUp.top());
                  backUp.pop();
                }
            }
            if(type == 2) {
                head.pop();
            } else {
                cout << head.top() << endl;
            }
        }
    }
    return 0;
}
