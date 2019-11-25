#include<cstdio>//算法复杂度O（mlogn）在线算法 
#include<iostream> 
using namespace std;
int n,m,s,h[500005],anc[500005][22],dep[500005],f[500005];
struct node{
	int b,n;
}d[1000005];
void init(int a,int b,int x){
	d[x].b = b;	d[x].n = h[a];
	h[a] = x;
}
int LCA(int a,int b){
	if(dep[a] < dep[b])	swap(a,b);//a的深度大 
	for(int i=20;i>=0;--i){//a向上跳到与b深度相同 
		if(dep[b] <= dep[anc[a][i]])
			a = anc[a][i]; 
	}
	if(a == b)	return a;//特判 
	for(int i=20;i>=0;--i){//一起向上跳，不相同就跳 
		if(anc[a][i] != anc[b][i]){
			a = anc[a][i];
			b = anc[b][i];
		}
	}
	return anc[a][0];//返回公共祖先 
}
void dfs(int a){
	anc[a][0] = f[a];//向上2的0次方的祖先 
	for(int i=1;i<=20;++i){
		anc[a][i] = anc[anc[a][i-1]][i-1];//向上递推预处理祖先 
	}
	for(int i=h[a];i;i=d[i].n){//搜索边 
		int b = d[i].b;
		if(b != f[a]){//
			f[b] = a;
			dep[b] = dep[a]+1;//深度+1 
			dfs(b);
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&s);//n个点m次询问s根节点 
	for(int i=1;i<=n-1;++i){//读入边
		int a,b;
		scanf("%d%d",&a,&b); 
		init(a,b,i);
		init(b,a,i+m);
	}
	f[s] =s;dep[s] = 1;//初始化，根的父亲是自己 深度为1 
	dfs(s);
	for(int i=1;i<=m;++i){//询问 
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",LCA(a,b));
	}
	return 0;
}
