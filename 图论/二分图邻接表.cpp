#include<cstdio>
#include<cstring>
using namespace std;
struct node{
	int a,b,n;
}d[1000005];//Ҫ����һЩ 
int link[100005],n,m,k,v[100005],ans,h[100005],a,b;
int dfs(int a){
	for(int i=h[a];i;i=d[i].n){
		b = d[i].b;
		if (!v[b]){
			v[b] = 1;
			if (!link[b] || dfs(link[b])){
				link[b] = a;
				return 1;
			}
		}
	}
	return 0;
}
int main(){//�ڽӱ�ʵ�ֶ���ͼ�����ڽӾ���ԭ��һ�� 
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;++i){
		scanf("%d%d",&a,&b);
		if(b > m)	continue;
		d[i].a = a;		d[i].b = b;
		d[i].n = h[a];	h[a] = i;
	}
	for(int i=1;i<=n;++i){
		memset(v,0,sizeof v);
		if (dfs(i))
		ans++;
	}
	printf("%d",ans);
	return 0;
}
