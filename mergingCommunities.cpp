//https://www.hackerrank.com/challenges/merging-communities/problem


#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct UFD{
    UFD* parent;
    int size;
};

int main() {
    int people, queries, first, second;
    map<int, UFD* > m;
    cin >> people >> queries;
    for(int i = 1; i <= people; i++){
        UFD *cur = new UFD;
        cur->size = 1;
        cur->parent = cur;
        m[i] = cur;
    }
    char type;
    for (int i = 0; i < queries; i++) {
        cin >> type;
        if(type == 'Q'){
            cin >> first;
            UFD *cur = m[first];
            while(cur->parent != cur) cur = cur->parent;
            cout << cur->size << endl;
        } else {
            cin >> first >> second;
            UFD *firstUFD = m[first];
            UFD *secondUFD = m[second];
            UFD *cur = m[second];
            while(firstUFD->parent != firstUFD) firstUFD = firstUFD->parent;
            while(secondUFD->parent != secondUFD){
                cur = secondUFD;
                secondUFD = secondUFD->parent;
                cur->parent = firstUFD;
            }
            if (firstUFD != secondUFD) {
              secondUFD->parent = firstUFD;
              firstUFD->size += secondUFD->size;
            }
        }
    }

    return 0;
}
