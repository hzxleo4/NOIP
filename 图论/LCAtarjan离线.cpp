#include<cstdio>//�㷨���Ӷ�O��n+m�������㷨 
using namespace std;
int v[10005],u[10005],h[10005][2],a,b,c,f[10005],n,m;
struct node{
	int a,b,c,n;
}road[10005],qs[10005];
int find(int x){//���鼯 
	if(x == f[x])
		return x;
	return f[x] = find(f[x]);
} 
void tarjan(int x,int s){
	f[x] = x;//�Լ����Լ������� 
	u[x] = s;//·�� 
	for(int i=h[x][1];i;i=qs[i].n){//ѯ�� 
		if(f[qs[i].b]){//֮ǰ�Ѿ����ʹ� 
			qs[i].c = find(qs[i].b);//�������������������� 
			//��Ϊ֮ǰ�Ѿ����ʹ��ĵ������ 
		}
	}
	for(int i=h[x][0];i;i=road[i].n){//��������
		if(!f[road[i].b]){//���û�� 
			tarjan(road[i].b,s+road[i].c);
			f[road[i].b] = x;//�����������Ķ��ӣ������Ӹ�ֵ
		}
	}
}
int main(){
	scanf("%d",&n);//n���� 
	for(int i=1;i<=n-1;++i){//����n-1���� 
		scanf("%d%d%d",&a,&b,&c);
		//++a,++b;
		road[i].a = road[i+n].b = a;
		road[i].b = road[i+n].a = b;
		road[i].c = road[i+n].c = c;
		road[i].n = h[a][0];	road[i+n].n = h[b][0];
		h[a][0] = i;			h[b][0] = i+n;
	}
	scanf("%d",&m);//m��ѯ�� 
	for(int i=1;i<=m;++i){
		scanf("%d%d",&a,&b);
		//++a,++b;
		qs[i].a = qs[i+m].b = a;
		qs[i].b = qs[i+m].a = b;
		qs[i].n = h[a][1];	qs[i+m].n = h[b][1];
		h[a][1] = i;		h[b][1] = i+m;
	}
	tarjan(road[1].a,0);//����һ����� 
	for(int i=1;i<=m;++i){
		if(!qs[i].c)	qs[i].c = qs[i+m].c;
		int ans = (u[qs[i].a] + u[qs[i].b]) - 2* u[qs[i].c];
		printf("%d\n",ans);
	}
	return 0;
} 
