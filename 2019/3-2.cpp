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
        V flag(N + 10, 1);
        ll l1 = 1, l2 = 1;
        ll r1 = N, r2 = N;
        rep(i, N) {
            char c;
            cin >> c;
            ll pos = 0;
            if (c == 'L') {
                for (;!pos && l1 <= N; l1+=2) {
                    if (flag[l1 - 1] && flag[l1] && flag[l1 + 1])pos = l1;
                }
                for (;!pos;l2++)if (flag[l2])pos = l2;
            } else {
                for (;!pos && r1 >= 1; r1-=2) {
                    if (flag[r1 - 1] && flag[r1] && flag[r1 + 1])pos = r1;
                }
                for (;!pos;r2--)if (flag[r2])pos = r2;
            }
            cout << pos << endl;
            flag[pos] = 0;
        }

    }

    return 0;
}