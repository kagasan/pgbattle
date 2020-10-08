#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> V;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
void chmin(ll &a, ll b){if(a>b)a=b;}
void chmax(ll &a, ll b){if(a<b)a=b;}
const ll INF = 1010101010;
class RMQ{
    public:
    ll N;
    vector<ll>mn, mx, L, R;
    RMQ(ll n, ll x = 0){
        for(N = 1; N < n + 5;)N *= 2;
        mn.resize(2 * N, x);
        mx.resize(2 * N, x);
        L.resize(2 * N, -1);
        R.resize(2 * N, -1);
        for(ll i = 0; i < N; i++)L[i + N] = R[i + N] = i;
        for(ll i = N - 1; i > 0; i--){
            L[i] = L[i * 2];
            R[i] = R[i * 2 + 1];
        }
    }
    void add(ll idx, ll x){
        idx += N;
        mn[idx] += x;
        mx[idx] += x;
        for(idx /= 2; idx > 0; idx /= 2){
            mn[idx] = min(mn[idx * 2], mn[idx * 2 + 1]);
            mx[idx] = max(mx[idx * 2], mx[idx * 2 + 1]);
        }
    }
    void update(ll idx, ll x){
        add(idx, x - mn[idx + N]);
    }
    ll get(ll idx) {
        return mn[idx + N];
    }
    ll get_min(ll l, ll r, ll idx = 1){
        if(l <= L[idx] && R[idx] <= r)return mn[idx];
        if(R[idx * 2] < l)return get_min(l, r, idx * 2 + 1);
        if(r < L[idx * 2 + 1])return get_min(l, r, idx * 2);
        return min(get_min(l, r, idx * 2), get_min(l, r, idx * 2 + 1));
    }
    ll get_max(ll l, ll r, ll idx = 1){
        if(l <= L[idx] && R[idx] <= r)return mx[idx];
        if(R[idx * 2] < l)return get_max(l, r, idx * 2 + 1);
        if(r < L[idx * 2 + 1])return get_max(l, r, idx * 2);
        return max(get_max(l, r, idx * 2), get_max(l, r, idx * 2 + 1));
    }
};

class P{
    public:
    ll x, y, z, idx;
    bool operator < (const P &p)const{return z < p.z;}
};

int main(){

    for (ll N; cin >> N;) {
        vector<P>v(N);
        vector<string>ans(N);
        set<ll>S;
        rep(i, N) {
            cin >> v[i].x >> v[i].y >> v[i].z;
            v[i].idx = i;
            S.insert(v[i].x);
        }
        sort(v.begin(), v.end());
        map<ll, ll>za;
        ll cnt = 0;
        for (auto x : S)za[x] = ++cnt;
        RMQ rmq(N, INF);
        queue<P>Q;
        rep(i, N) {
            if (rmq.get_min(1, za[v[i].x] - 1) < v[i].y) ans[v[i].idx] = "Yes";
            else ans[v[i].idx] = "No";
            Q.push(v[i]);
            if (i + 1 == N || v[i].z < v[i + 1].z){
                while(!Q.empty()) {
                    P p = Q.front();
                    Q.pop();
                    ll idx = za[p.x];
                    if (rmq.get(idx) > p.y) {
                        rmq.update(idx, p.y);
                    }
                }
            }
        }
        rep(i, N)cout << ans[i] << endl;
    }

    return 0;
}