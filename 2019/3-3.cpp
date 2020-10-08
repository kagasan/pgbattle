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

ll X[303030];
ll Y[303030];
ll D[303030];
int rui[6060][6060];
int sum(ll x1, ll y1, ll x2, ll y2) {
    x1 = max(1LL, min(6030LL, x1));
    y1 = max(1LL, min(6030LL, y1));
    x2 = max(1LL, min(6030LL, x2));
    y2 = max(1LL, min(6030LL, y2));
    int res = 0;
    res += rui[y2][x2];
    res += rui[y1 - 1][x1 - 1];
    res -= rui[y1 - 1][x2];
    res -= rui[y2][x1 - 1];
    return res;
}
void cvt(ll x1, ll y1, ll &x2, ll &y2) {
    x2 = x1 + y1;
    y2 = y1 - x1 + 3001;
}


int main(){

    for (ll N; cin >> N;) {
        rep(i, 6060)rep(j, 6060)rui[i][j] = 0;
        rep(i, N) {
            cin >> X[i] >> Y[i] >> D[i];
            ll x, y;
            cvt(X[i], Y[i], x, y);
            rui[y][x]++;
        }
        rep(y, 6060)rep1(x, 6059)rui[y][x] += rui[y][x - 1];
        rep(x, 6060)rep1(y, 6059)rui[y][x] += rui[y - 1][x];
        rep(i, N) {
            ll x1, y1, x2, y2;
            cvt(X[i], Y[i] - D[i], x1, y1);
            cvt(X[i], Y[i] + D[i], x2, y2);
            cout << sum(x1, y1, x2, y2) << endl;
        }
    }

    return 0;
}