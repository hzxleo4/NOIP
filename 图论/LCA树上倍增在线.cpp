#include<cstdio>//�㷨���Ӷ�O��mlogn�������㷨 
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
	if(dep[a] < dep[b])	swap(a,b);//a����ȴ� 
	for(int i=20;i>=0;--i){//a����������b�����ͬ 
		if(dep[b] <= dep[anc[a][i]])
			a = anc[a][i]; 
	}
	if(a == b)	return a;//���� 
	for(int i=20;i>=0;--i){//һ��������������ͬ���� 
		if(anc[a][i] != anc[b][i]){
			a = anc[a][i];
			b = anc[b][i];
		}
	}
	return anc[a][0];//���ع������� 
}
void dfs(int a){
	anc[a][0] = f[a];//����2��0�η������� 
	for(int i=1;i<=20;++i){
		anc[a][i] = anc[anc[a][i-1]][i-1];//���ϵ���Ԥ�������� 
	}
	for(int i=h[a];i;i=d[i].n){//������ 
		int b = d[i].b;
		if(b != f[a]){//
			f[b] = a;
			dep[b] = dep[a]+1;//���+1 
			dfs(b);
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&s);//n����m��ѯ��s���ڵ� 
	for(int i=1;i<=n-1;++i){//�����
		int a,b;
		scanf("%d%d",&a,&b); 
		init(a,b,i);
		init(b,a,i+m);
	}
	f[s] =s;dep[s] = 1;//��ʼ�������ĸ������Լ� ���Ϊ1 
	dfs(s);
	for(int i=1;i<=m;++i){//ѯ�� 
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",LCA(a,b));
	}
	return 0;
}
