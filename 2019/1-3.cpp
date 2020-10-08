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

int main(){

    for (ll N, M; cin >> N >> M;) {
        V v(M + 1, 0);
        rep1(c, N) {
            ll a, b;
            cin >> a >> b;
            ll d = c - a - b;
            if (1 <= d && d <= M) v[d] = 1;
        }
        ll ans = 0;
        rep1(i, M) ans += v[i];
        cout << ans << endl;
    }

    return 0;
}