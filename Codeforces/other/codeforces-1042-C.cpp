#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i = (a); i<(n); i++)
#define per(i,a,n) for (int i = (n)-1; i>=(a); i--)
#define pb push_back
#define mp make_pair
#define all(now) (now).begin(),(now).end()
#define fi first
#define se second
#define SZ(now) ((int)(now).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod = 1e9+7;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
inline void read(int &a,int &b){read(a),read(b);}
inline void read(int &a,int &b,int &c){read(a,b),read(c);};
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 2e6+7;
int n, m, k;
vector<PII> big, sm; // val,pos;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n;
    int zero = 0;
    int fu = 0;
    rep(i,1,n+1){
        int val, pos;
        cin >> val;
        if(val==0)
            zero++;
        else if(val<0){
            fu++;
        }
        big.pb(mp(val, i));
    }
    sort(all(big));
    // 5 1 0 -2 -3
    int pos = -1;
    rep(j,1,n){
        if(pos!=-1 && big[j].fi!=0 && fu%2==1){
            cout << 1 << "_" << big[j-1].se << " " << big[j].se << endl;
            cout << 2 << "=" << big[j].se << endl;
        }
        else if(pos!=-1 && big[j].fi!=0 && fu%2==0){
            cout << 1 << "+" << big[pos].se << " " << big[j].se << endl;
        }
        else if(big[j].fi==0 && pos!=-1){
            pos = j-1;
        }
        else {
            cout << 1 << "." << big[j-1].se << " " << big[j].se << endl;
        }
    }

    return 0;
}
