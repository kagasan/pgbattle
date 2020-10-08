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

    for (ll N; cin >> N; ) {
        V v(2 * N);
        rep(i, 2 * N) cin >> v[i];
        sort(v.begin(), v.end());
        ll ans = v[N] - v[0];
        rep(i, N)chmin(ans, v[N + i] - v[i]);
        cout << ans << endl;
    }

    return 0;
}