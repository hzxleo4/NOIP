#include<cstdio>
#include<algorithm>
using namespace std;
int w[10005],v[10005],dp[10005],n,m;
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;++i){
        scanf("%d%d",&w[i],&v[i]);//重量 价值 
    }
    //01背包 
     	for(int i=1;i<=n;++i){
            for(int j=m;j>=w[i];--j){//每件物品只能用一次 
                dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
    //完全背包
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){//每件物品可以用无限次 
                dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
    //分组背包
        for(int i=1;i<=n;++i){
            for(int j=m;j>=1;--i){//每个组只选一个 
                for(int k=1;k<=h[q];++k)
                if(j >= w[q][k])
                    dp[j] = max(dp[j],dp[j-w[q][k]]+v[q][k]);
                    
            }
        } 
    printf("%d",dp[m]);
    return 0;
}
