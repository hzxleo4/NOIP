#include<cstdio>//f区间合并最小 dp 区间合并最大 
#include<algorithm> 
#include<cstring>
using namespace std;
int maxn,n,a[205],dp[205][205],s[205],f[205][205],minn=1e9;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		a[i+n] = a[i];//破环 
	}
	for(int i=1;i<=2*n;++i){
		s[i] = s[i-1]+a[i];//前缀和 
	}
	memset(f,1,sizeof f);//预处理 
	for(int i=1;i<=2*n;++i){
		f[i][i] = 0;//合并自己代价为0
	}
	for(int i=2*n-1;i>=1;--i){//枚举起点（从后往前，这样不会重复计算） 
		for(int j=i+1;j<=2*n-1;++j){//终点
			for(int k=i;k<=j-1/*!!-1*/;++k){//枚举区间中的断点
				dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]+s[j]-s[i-1]);
				f[i][j] = min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
			}
		}
	}
	for(int i=1;i<=n;++i){//找最大最小值 
		maxn = max(maxn,dp[i][i+n-1]);
		minn = min(minn,f[i][i+n-1]);
	}
	printf("%d\n%d",minn,maxn);
	return 0;
}