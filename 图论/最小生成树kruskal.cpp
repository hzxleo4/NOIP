#include<cstdio>
#include<algorithm> 
using namespace std;
int n,m,a,b,x,y,c,ans,s,f[200010];
struct node{
	int a,b,c;
}e[210010];
int cmp(node a,node b){
	return a.c < b.c;
}
int find(int x){	//���鼯 
	if (x == f[x])	return x;
	return f[x] = find(f[x]);
}
int main(){
	scanf("%d%d",&n,&m);//n���㣬m���� 
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&a,&b,&c);//a��b��Ȩc 
		e[i].a = a;		e[i].b = b;		e[i].c = c;
	}
	sort(e+1,e+1+m,cmp);//��Ȩֵ�Ĵ�С���� 
	for(int i=1;i<=n;++i){//���鼯��ʼ�� 
		f[i] = i;
	}
	for(int i=1;i<m && ans < n-1/*��û������*/;++i){	
		a = e[i].a;		b = e[i].b;
		x = find(a);	y = find(b);
		if (x != y){//������������ӵ����µĵ� 
			ans++;
			s += e[i].c;
			f[x] = y;
		}
	}
	printf("%d",s);
	return 0;
}
