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

ll dp[5050][5050][3];


int main(){

    for (ll N; cin >> N;){
        V a(N), b(N);
        rep(i, N) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b.begin(), b.end());
        rep(i, N)dp[0][i][2] = abs(a[0] - b[i]);
        rep1(i, N - 1) {
            for (ll j = N - 1, k = N - 1; j >= 0; j--) {
                dp[i][j][0] = dp[i - 1][k][2] + abs(b[j] - b[k]);
                if (dp[i][j][0] > dp[i - 1][j][2]) {
                    k = j;
                    dp[i][j][0] = dp[i - 1][k][2];
                }
            }
            for (ll j = 0, k = 0; j < N; j++) {
                dp[i][j][1] = dp[i - 1][k][2] + abs(b[j] - b[k]);
                if (dp[i][j][1] > dp[i - 1][j][2]) {
                    k = j;
                    dp[i][j][1] = dp[i - 1][k][2];
                }
            }
            rep(j, N){
                dp[i][j][2] = abs(a[i] - b[j]) + min(dp[i][j][0], dp[i][j][1]);
            }
        }
        ll ans = dp[N - 1][N - 1][2];
        rep(i, N)chmin(ans, dp[N - 1][i][2]);
        cout << ans << endl;
    }

    return 0;
}