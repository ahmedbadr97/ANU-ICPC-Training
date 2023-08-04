#include <bits/stdc++.h>

using namespace std;
bool testing = false;
#define F first
#define S second
#define ll long long
#define tc int t;cin>>t; while(t--)
#define all(A) A.begin(),A.end()

// ---------------Ordered Set-----------------//
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        indexed_set;

/*
indexed_set s;
s.insert(2);
s.insert(3);
s.insert(7);
s.insert(9);
s.insert(2)
auto x = s.find_by_order(2);
returns iterator on element at index 2 if the elements are in sorted array
 will return iterator on 7

 s.order_of_key(7) returns the index of the element if it exists
  it will return 2

 */
// -------------------------------------------//

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

void exec_time() {

    using namespace std::chrono;
    // Get starting timepoint
    static auto start = high_resolution_clock::now();
    static bool end = false;
    // Get ending timepoint
    if (end) {
        auto stop = high_resolution_clock::now();

        // Get duration. Substart timepoints to
        // get durarion. To cast it to proper unit
        // use duration cast method
        auto duration = duration_cast<milliseconds>(stop - start);

        cout << "\nExec Time :"
             << duration.count() << " milliseconds\n";
    } else
        end = true;

}

ll first_true(ll l, ll r, const function<bool(ll)> &f) {
    // FFFFFF(T)TTTTTT
    ll m;
    ll last = -1;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (f(m)) {
            last = m;
            r = m - 1;
        } else
            l = m + 1;
    }
    return last;
}

ll last_true(ll l, ll r, const function<bool(ll)> &f) {
    ll m; //TTTTTTTFFFFFFFF
    ll last = -1;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (f(m)) {
            last = m;
            l = m + 1;
        } else
            r = m - 1;
    }
    return last;
}


ll fastPower(ll x, ll p) {
    ll ans;
    if (!p)//p==0
        return 1;
    ans = fastPower(x, p / 2);
    ans *= ans;
    if (p & 1)//p is odd
        ans *= x;
    return ans;
}

ll fastPower_mod(ll x, ll p, ll m) {
    ll ans = 1;
    if (!p)//p==0
        return 1;
    ans = fastPower_mod(x, p / 2ll, m);
    ans = (ans * ans);
    if (p & 1)//p is odd
        ans *= x;
    return ans % m;
}

ll fastPower_iter(ll x, ll y) {
    ll ans = 1;
    while (y) {
        if (y & 1) {
            ans *= x;
        }
        x *= x;
        y /= 2;

    }
    return ans;
}

ll fastPower_iter_mod(ll x, ll y, ll m) {
    ll ans = 1;
    x = x % m;
    while (y) {
        if (y & 1) {
            ans = (ans * x) % m;
        }
        x = x * x;
        if (x >= m) {
            x = x % m;
        }
        y >>= 1;
    }
    return ans;
}

ll mod_inv(ll a, ll mod) {
    return fastPower_mod(a, mod - 2, mod);
}

ll mul_mod(ll a, ll b, ll mod) { // log b
    // 10^18 * 10^18
    ll r = 0;
    while (b) {
        if (b & 1) {
            r = (r + a) % mod;
        }
        a = (a + a) % mod;
        b /= 2;
    }
    return r;
}

vector<int> getFactors(int x) {
    vector<int> f;

    int d;
    for (int i = 1; i * i <= x; ++i) {
        d = x / i;
        if (d * i == x) {
            f.push_back(i);
            if (d != i)
                f.push_back(i);
        }
    }
    return f;

}

vector<pair<int, int>> getPrimeFactors_powers(int x) {
    // returns the prime factor and it's power
    vector<pair<int, int>> f;
    int cnt;
    for (int i = 2; i * i <= x; i++) {
        cnt = 0;
        while (x % i == 0) {
            cnt++;
            x /= i;
        }
        if (cnt)
            f.emplace_back(i, cnt);
    }
    if (x > 1) f.emplace_back(x, 1);
    return f;

}

vector<pair<int, int>> getPrimeFactors_powers_seive(int x, vector<int> &seive) {
    // returns the prime factor and it's power
    vector<pair<int, int>> f;
    int pfactor;
    int cnt;
//    if (seive[x] == 0) //Prime number
//        return f;

    while (x != 1) {
        pfactor = seive[x];
        cnt = 0;
        if (pfactor == 0) {
            f.emplace_back(x, 1);
            break;
        }
        while (x != 1 && x % pfactor == 0) {
            x = x / pfactor;
            cnt++;
        }
        f.emplace_back(pfactor, cnt);

    }
    return f;

}


vector<int> getPrimeFactors(int x) {
    // 16 = 2^4 it will return 2 only not 2 2 2 2
    vector<int> f;
    bool isFactor;
    for (int i = 2; i * i <= x; i++) {
        isFactor = false;
        while (x % i == 0) {
            x /= i;
            isFactor = true;
        }
        if (isFactor)
            f.push_back(i);
    }
    if (x > 1) f.push_back(x);
    return f;
}

vector<int> getPrimeFactors_seive(int x, vector<int> &seive) {
    // 16 = 2^4 it will return 2 only not 2 2 2 2
    vector<int> ret;
    int pfactor;
    while (x != 1) {
        pfactor = seive[x];
        if (!pfactor) {
            ret.push_back(x);
            break;
        } else
            ret.push_back(pfactor);
        while (x != 1 && x % pfactor == 0)
            x /= pfactor;
    }
    return ret;
}

vector<int> seive(int x) {
    // if s[i]==0 then i isPrime;
    // else s[i] will have the smallest prime factor for i
    vector<int> s(x + 1, 0);
    s[0] = s[1] = 1;
    for (int i = 2; i <= x; i++) {
        if (s[i]) continue;
        for (int u = 2 * i; u <= x; u += i) {
            if (s[u])continue;
            s[u] = i;
        }
    }
    return s;
}

bool isPrime(int x) {
    if (x <= 1)
        return false;
    if (x <= 3)
        return true;
    if (x % 2 == 0 || x % 3 == 0)
        return false;
    for (int i = 5; i * i <= x; i = i + 6)
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    return true;
}

ll mult(ll x, ll y, ll mod) {
    ll ans = 0;

    while (y) {
        if (y & 1) {
            ans += x;
            if (ans >= mod)
                ans = ans % mod;
        }
        x += x;
        if (x >= mod)
            x = x % mod;
        y >>= 1;
    }
    return ans % mod;
}


int lcm(int a, int b) {
    return a * b / __gcd(a, b);
}

struct edge {
    int from, to, weight;

    edge(int from, int to, int weight) {
        this->from = from;
        this->weight = weight;
        this->to = to;
    }

    bool operator<(const edge &anotherEdge) const {
        return anotherEdge.weight > this->weight;
    }
};

struct cmp {
    bool operator()(const char a, const char b) const {
        return a > b;
    }
};

// ------------------ Global variables declaration --------------------- //
vector<vector<int>> adj;
vector<vector<pair<int, int>>> adjWeighted;
vector<int> visited;

queue<int> sticksOrder;

// -------------------------------------------------------------------- //
bool bfs(int src) {
    int cnt = 0;
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;
        for (int v: adj[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }

    }
    return true;
}

ll mx_dist = -1;

ll dfsShortest(int u, ll dist = 0) {
    visited[u] = true;
    ll sum = 0;
    for (auto v: adjWeighted[u]) {
        if (!visited[v.S]) {
            sum += dfsShortest(v.S, dist + v.F) + v.F;
        }
    }
    mx_dist = max(mx_dist, dist);
    return sum;
}

int dfs(int u) {
    int valid = 1;
    // pending
    visited[u] = 1;
    for (int v: adj[u]) {
        if (!visited[v]) {
            valid *= dfs(v);
        } else if (visited[v] == 1) {
            valid = 0;
            break;
        }
    }
    visited[u] = 2;
    sticksOrder.push(u);

    return valid;


}

int main() {
//    testing = true;
    fio();
    if (testing) {
        file_io("test");
        exec_time();
    }
    //----------------------------------------------------------------------




    //-----------------------------------------------------------------------
    if (testing)

        exec_time();

    return 0;
}