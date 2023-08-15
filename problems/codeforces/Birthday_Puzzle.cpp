#include <bits/stdc++.h>

using namespace std;

#define ll long long

void fio() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
}

void file_io(string fname) {
    freopen((fname + ".in").c_str(), "r", stdin);
    freopen((fname + ".out").c_str(), "w", stdout);

}


ll ans = 0;
stack<int> s;
int arr[21];
int n;

void solve(int i, list<int> &sub_set) {
    if (i == n) {
        int sum = 0;
        for (auto num: sub_set)
            sum |= num;
        ans += sum;
    } else {
        sub_set.push_back(arr[i]);
        solve(i + 1, sub_set);
        sub_set.pop_back();
        solve(i + 1, sub_set);
    }
}

int main() {
    list<int> l;
    fio();
//    file_io("test");
    cin >> n;


    for (auto &e: arr)cin >> e;


    solve(0, l);
    cout << ans;

    return 0;
}
