#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll tt;
    cin >> tt;
    while (tt--)
    {
        /* code */
        ll n;
        cin>>n;
        bool flag=false;
        ll a,b;
        cin>>a;
        if(a==1 &&  n==1){
            cout<<"Yes"<<endl;
            continue;
        }
        if(n==1 && a!=1){
            cout<<"No"<<endl;
            continue;
        }
        b=1;
        for(int i=1;i<n;i++){
            cin>>a;
            ll r=b*2;
            if(i==n-1){
                if(a&1 || a!=r){
                    flag=true;
                }
            }
            if(a>r){
                flag=true;
            }
            if(a<=r){
                b=r-a;
            }
        }
        if(flag){
            cout<<"No"<<endl;
        }
        else{
            cout<<"Yes"<<endl;
        }
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}