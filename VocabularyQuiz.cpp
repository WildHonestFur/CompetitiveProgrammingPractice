#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
    cin >> n;
    vector<long long> tree[n+1] = {};
    long long parent[n+1] = {};
    long long score[n+1] = {};
    long long stacklen[n+1] = {};
    long long invalid[n+1] = {};
    for (long long i = 1; i < n+1; i++) {
        long long val;
        cin >> val;
        tree[val].push_back(i);
        parent[i] = val;
    }
    vector<long long> stack = {};
    
    stack.push_back(0);
    long long m = 0;
    while (stack.size() > 0) {
        vector<long long> new_stack = {};
        for (long long i = 0; i < stack.size(); i++) {
            vector<long long> branch = tree[stack[i]];
            stacklen[stack[i]] = branch.size();
            if (branch.size() > 1) {
                for (long long j = 0; j < branch.size(); j++) {
                    score[branch[j]] = 1+score[stack[i]];
                    new_stack.push_back(branch[j]);
                }
            }
            else if (branch.size() == 1) {
                tree[stack[i]] = tree[branch[0]];
                score[branch[0]] = score[stack[i]];
                new_stack.push_back(stack[i]);
            }
            else {
                m++;
            }
        }
        stack = new_stack;
    }
    for (long long i = 0; i < m; i++) {
        long long find;
        cin >> find;
        cout << score[find] << "\n";
        stacklen[parent[find]]--;
        invalid[find] = 1;
        if (stacklen[parent[find]] == 0 and i != m-1) {
            while (stacklen[parent[find]] == 0) {
                find = parent[find];
                invalid[find] = 1;
            }
            stacklen[parent[find]]--;
        }
        if (stacklen[parent[find]] == 1) {
            for (long long j = 0; j < tree[parent[find]].size(); j++) {
                long long current = tree[parent[find]][j];
                if (invalid[current] != 1) {
                    tree[parent[find]] = {tree[parent[find]][j]};
                    while (true) {
                        score[current] = score[parent[current]];
                        if (stacklen[current] != 1) {
                            break;
                        }
                        else {
                            current = tree[current][0];
                        }
                    }
                }
            }
        }
    }
}
