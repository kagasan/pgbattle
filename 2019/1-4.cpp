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
class P{
    public:
    ll t, idx;
    P(ll t, ll idx):t(t), idx(idx){};
    bool operator > (const P &p)const{return t > p.t;};
};
class EDGE{
    public:
    // x ~ y : 通過できない期間
    ll from, to, cost, d, x, y;
    EDGE(ll from, ll to, ll cost, ll d, ll x, ll y)
    :from(from), to(to), cost(cost),d(d),x(x),y(y){};
};
int main(){
    for (ll N, M, T, K; cin >> N >> M >> T >> K;) {
        priority_queue<P, vector<P>, greater<P>>Q;
        V v(N + 1, -1), tmp(N + 1, 0);
        vector<EDGE>path[101010];
        rep1(i, M) {
            ll a, b, c, d;
            cin >> a >> b >> c >> d;
            path[a].push_back(EDGE(a, b, c, d, T + K - d, T - K + d));
            path[b].push_back(EDGE(b, a, c, d, T + K - d, T - K + d));
        }
        Q.push(P(0, 1));
        ll ans = -1;
        while(!Q.empty()) {
            P p = Q.top();
            Q.pop();
            if (v[p.idx] >= 0)continue;
            if (p.idx == N) {
                ans = p.t;
                break;
            }
            for (auto e : path[p.idx]) {
                if (v[e.to] >= 0)continue;
                if (p.t + e.cost <= e.x || p.t >= e.y) {
                    if(tmp[e.to] == 0 || tmp[e.to] > p.t + e.cost){
                        tmp[e.to] = p.t + e.cost;
                        Q.push(P(p.t + e.cost, e.to));
                    }
                } else {
                    if(tmp[e.to] == 0 || tmp[e.to] > e.y + e.cost){
                        tmp[e.to] = e.y + e.cost;
                        Q.push(P(e.y + e.cost, e.to));
                    }
                }
            } 
        }
        cout << ans << endl;
    }

    return 0;
}