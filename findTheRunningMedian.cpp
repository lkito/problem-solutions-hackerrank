//https://www.hackerrank.com/challenges/find-the-running-median/problem


#include <bits/stdc++.h>

using namespace std;

void add(priority_queue<int, vector<int>, greater<int>> &min,
         priority_queue<int, vector<int>, less<int>> &max, int n) {
    if(max.empty() || n < max.top()) {
        max.push(n);
    } else
        min.push(n);
    if (max.size() < min.size()) {
        max.push(min.top());
        min.pop();
    }
    if (max.size() == min.size() + 2) {
        min.push(max.top());
        max.pop();
    }
}

/*
 * Complete the runningMedian function below.
 */
vector<double> runningMedian(vector<int> a) {
    vector<double> res;
    priority_queue<int, vector<int>, greater<int> > min;
    priority_queue<int, vector<int>, less<int> > max;
    for(int i = 0; i < a.size(); i++){
        add(min, max, a[i]);
        if(i % 2 == 0){
            res.push_back((double) max.top());
        } else res.push_back(((double) min.top() + max.top()) /2);
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int a_count;
    cin >> a_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> a(a_count);

    for (int a_itr = 0; a_itr < a_count; a_itr++) {
        int a_item;
        cin >> a_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        a[a_itr] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
