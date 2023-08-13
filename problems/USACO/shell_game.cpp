#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define ll long long
#define tc int t;cin>>t; while(t--)

void fio() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
}

void file_io(string fname) {

    freopen((fname + ".in").c_str(), "r", stdin);
    freopen((fname + ".out").c_str(), "w", stdout);
}

void file_i(string fname) {

    freopen((fname + ".in").c_str(), "r", stdin);
}



int main() {

    fio();

    file_io("shell");

    //----------------------------------------------------------------------

    int n;
    cin >> n;
    vector<pair<int, int>> switches(n);
    vector<int> guess(n);

    for (int i=0; i < n; i++)
    {
        cin>>switches[i].F>>switches[i].S;
        cin>>guess[i];
    }
    int mx=-1;
    for(int start=1;start<=3;start++)
    {
        vector<int> places(4,0);
        places[start]=1;
        int new_ans=0;
        for(int i=0;i<n;i++)
        {

            swap(places[switches[i].F],places[switches[i].S]);

            new_ans+=places[guess[i]];
        }
        mx=max(mx,new_ans);
    }
    cout<<mx;



    //-----------------------------------------------------------------------

    return 0;
}