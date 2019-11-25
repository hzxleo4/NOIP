#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct node{
	int a,b,c,n;
}d[100005];
int z,q[100005],h[10004],ans,m,n,s,t,v[10005],ansf,zz; 
void rest(){
	for(int i=1;i<=z;++i){
		d[q[i]].c -= ans;
		d[q[i]+m].c += ans;
	}
	return ;
}
void dfs(int x){
	if(x == t){
		zz = 1;
		rest();
		return;
	}
	v[x] = 1;
	for(int i=h[x];i;i=d[i].n){
		int b = d[i].b,	c = d[i].c;
		if(!v[b] && c){
			ans = min(ans,c);
			q[++z] = i;
			dfs(b);
			if(zz)	return;
			--z;
		}
	}
}
int main(){
	int a,b,c;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&a,&b,&c);
		d[i].a = d[i+m].b = a;
		d[i].b = d[i+m].a = b;
		d[i].c = c;
		d[i].n = h[a];	d[i+m].n = h[b];
		h[a] = i;		h[b] = i+m;
	}
	while(1){
		ans = 1e9;
		z = 0;
		zz = 0;
		memset(q,0,sizeof(q));
		memset(v,0,sizeof(v));
		dfs(s);
		if(ans == 1e9)
		break;
		ansf += ans;
	}
	printf("%d",ansf);
	return 0;
}
