#include<cstdio>
struct node{
	int b,n;
}d[10005];
int n,a,b,c,m,ru[10005],dui[10005],h[10005];
int main(){
	scanf("%d",&n);//n个点 （图） 
	for(int i=1; i <= n; ++i){
		scanf("%d",&b);
		while(b){
			m++,ru[b]++;
			d[m].b = b;
			d[m].n = h[i];
			h[i] = m;
			scanf("%d",&b);
		}
	}
	for(int i=1;i<=n;++i){
		if (!ru[i])	dui[++c] = i;//寻找根节点，找到入队 
	}
	for(int i=1;i<=c;++i){
		a = dui[i];	printf("%d ",a);//输出跟节点 
		for(int j=h[a];j;j =d[j].n){
			b = d[j].b;
			if (--ru[b] == 0)	dui[++c] = b;//成为新的根节点，入队 
		}
	}
	return 0;
}
