#include<iostream>
#include<cstdio>
int t,n,m,a;
struct node{
	int l,r,p,c;
}d[100005];
void dfs(int x){
	if(a > d[x].c){
		if(d[x].r){
			dfs(d[x].r);
		}
		else{
			d[++m].c = a;
			d[m].p = a;
		}
	}
	else{
		if(d[x].l){
			dfs(d[x],l);
		}
		else{
			d[++m].c = a;
			d[m].p = a;
		}
	}
}
void zhong(int x){//中序遍历 
	if(d[x].l){
		dfs(d[x].l);
	}
	printf("%d",d[x].c);
	a[++t] = d[x].c;
	pre[t] = a[t-1];//前驱 
	succ[t-1] = a[t]; //后继 
	if(d[x].r){
		dfs(d[x].r);
	}
}
int main(){
	scanf("%d%d",&n,&d[1].c);
	for(m=1,int i=2;i<=n;++i){
		scanf("%d",&a);
		dfs(1);//插入 
	}
	zhong(1);
	
	del(1);
	return 0;
}
