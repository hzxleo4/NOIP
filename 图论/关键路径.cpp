#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int a,b,c,n;
}d[20];
int a,b,c,n,m,dui[20],wan[20],zao[20],k,h[20],ru[20];
int main(){
	scanf("%d%d",&n,&m);//n个点，m条边 
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&a,&b,&c);
		d[i].a = a;		d[i].b = b;
		d[i].c = c;		d[i].n = h[a];
		h[a] = i;		ru[b]++;
	}
	for(int i=1;i<=n;++i){
		if (!ru[i])
		dui[++k] = i;	//寻找根节点 
	}
	for(int i=1;i<=k;++i){
		a =dui[i];
		for(int j=h[a];j;j=d[j].n){
			b = d[j].b;
			c = d[j].c;
			zao[b] = max(zao[b],zao[a]+c);//寻找最早完成时间 
			if (--ru[b] == 0)
				dui[++k] = b;
			}
	}
	for(int i=1;i<=n;++i){
		wan[i] = zao[dui[k]];//反过来再找一次 
	}
	for(int i=k;i>=1;--i){//逆拓扑排序一次 
		a = dui[i];
		for(int j=h[a];j;j=d[j].n){
			b = d[j].b;
			c = d[j].c;
			wan[a] = min(wan[a],wan[b]-c);//寻找最晚完成时间 
		}
	}
	for(int i=1;i<=n;++i){
		if(zao[i] == wan[i])//相同输出 
		printf("%d ",i);
	}	
	return 0;
}
