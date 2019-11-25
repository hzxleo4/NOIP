#include<cstdio>
#include<cstring>
using namespace std;
int link[10001];
int v[10001],mp[1005][1005],n,m,k,a,b,ans;
int dfs(int a){
	for(int i=1;i<=m;++i){
		if (mp[a][i] && !v[i]){//如果这个点可以走 
			v[i] = 1;
			if (!link[i] || dfs(link[i])){//这个点还没匹配 || 这个点的原匹配还有其他匹配 
				link[i] = a;//异或 
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);//n个人，m个人，k个关系 
	for(int i=1;i<=k;++i){
		scanf("%d%d",&a,&b);
		//if(b > m)	continue;
		mp[a][b] = 1;
	}
	for(int i=1;i<=n;++i){
		memset(v,0,sizeof(v));
		if(dfs(i))//如果匹配成功 
		ans++;
	}
	printf("%d",ans);
	return 0;
}
