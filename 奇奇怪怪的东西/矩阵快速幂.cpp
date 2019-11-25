#include<cstdio>
#define mo 1000000000+7
#define ll long long
using namespace std;
struct node{
    ll a[105][105];
}mp;
ll n,k;
node mul(node t,node z){
    node tt;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            tt.a[i][j] = 0;
            for(int k=1;k<=n;++k){
                tt.a[i][j] += t.a[i][k] * z.a[k][j];
                tt.a[i][j] %= mo;
            }
        }
    }
    return tt;
}
void poww(node mp,ll k){
    node zz = mp;
    k--;
    while(k){
        if(k&1)
            mp = mul(mp,zz);
        k>>=1;
        zz = mul(zz,zz);
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            printf("%lld ",mp.a[i][j]);
        }
        printf("\n");
    }
}
int main(){
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            scanf("%lld",&mp.a[i][j]);
        }
    }
    poww(mp,k);
    return 0;
}
