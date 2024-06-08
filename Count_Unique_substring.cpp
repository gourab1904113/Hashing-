
/* Count Unique Substring */

#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long int ll;

typedef tree<
ll,
null_type,
less_equal<ll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define db double
#define pii pair<ll,ll>
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fr(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define ss second
#define ff first
#define in insert
#define sq(x)  (x*x)
#define all(a)  a.begin(),a.end()
#define nl '\n'
#define parr pair<ll,ll>
#define mpr  priority_queue <parr, vector<parr>, greater<parr> >

ll gcd(ll a,ll b){
       if(b==0)return a;
       return gcd(b,a%b);
}
int getRandom(int L,int R)
{
    return rng()%(R-L+1) + L;
}

ll lcm(ll a,ll b){
       return ((a)/gcd(a,b))*b;
}

ll cube(ll a){
  return a*a*a;
}

const ll  N = 50005;
const ll mod = 998244353;
const ll neginf= -1e18;
const ll inf = 1e15;


int count_unique_substring(string s){

    ll n=s.size();

    ll p=31;
    ll m= 1e9 + 9;

    vector<ll>p_pow(n);

    p_pow[0]=1;

    for(int i=1;i<n;i++){

        p_pow[i]=(p_pow[i-1]*p)%m;
    }

    vector<ll>hs(n+1,0);

    for(ll i=1;i<=n;i++){

         hs[i]= (hs[i-1]+ (s[i-1]-'a'+1)* p_pow[i-1])%m;
    }

    ll cnt=0;

    for(ll l=1;l<=n;l++){

         unordered_set<ll>st;

         for(ll i=0;i<=n-l;i++){



            ll cur_h= ( hs[i+l] - hs[i] + m )%m;

            cur_h= (cur_h * p_pow[n-i-1])%m;
            st.insert(cur_h);

         }

         cnt+=st.size();

    }


    return cnt;





}

int main(){

       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       cout.tie(NULL);

       string s;
       cin>>s;


         ll cnt= count_unique_substring(s);

          cout<<cnt<<endl;




}
