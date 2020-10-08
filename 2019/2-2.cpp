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

struct ANS{
    ll a, b, c;
    ANS(ll a, ll b, ll c):a(a),b(b),c(c){};
};

ll N, M, A, B, C;
bool check(ll a, ll b, ll c) {
    return A * a + B * b + C * c == M;
}

ANS solve() {
    rep(i, N + 1) {
        ll a, b, c;
        a = i; b = N - i; c = 0;
        if (check(a, b, c))return ANS(a, b, c);
        a = 0; b = i; c = N - i;
        if (check(a, b, c))return ANS(a, b, c);
        a = N - 1; b = 0; c = i;
        if (check(a, b, c))return ANS(a, b, c);
        c = i;
        ll l = A * N - M + C * c - A * c;
        ll r = A - B;
        if (l < 0 && r < 0) {
            l = -l;
            r = -r;
        }
        if (l > 0 && r > 0 && l % r == 0) {
            b = l / r;
            a = N - b - c;
            if (check(a, b, c))return ANS(a, b, c);
        }
    }
    return ANS(-1, -1, -1);
}

int main(){

    for (;cin >> N >> M;){
        cin >> A >> B >> C;
        ANS ans = solve();
        cout << ans.a << " " << ans.b << " " << ans.c << endl;
    }

    return 0;
}