#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int a,b,c,n;
}d[20];
int a,b,c,n,m,dui[20],wan[20],zao[20],k,h[20],ru[20];
int main(){
	scanf("%d%d",&n,&m);//n���㣬m���� 
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&a,&b,&c);
		d[i].a = a;		d[i].b = b;
		d[i].c = c;		d[i].n = h[a];
		h[a] = i;		ru[b]++;
	}
	for(int i=1;i<=n;++i){
		if (!ru[i])
		dui[++k] = i;	//Ѱ�Ҹ��ڵ� 
	}
	for(int i=1;i<=k;++i){
		a =dui[i];
		for(int j=h[a];j;j=d[j].n){
			b = d[j].b;
			c = d[j].c;
			zao[b] = max(zao[b],zao[a]+c);//Ѱ���������ʱ�� 
			if (--ru[b] == 0)
				dui[++k] = b;
			}
	}
	for(int i=1;i<=n;++i){
		wan[i] = zao[dui[k]];//����������һ�� 
	}
	for(int i=k;i>=1;--i){//����������һ�� 
		a = dui[i];
		for(int j=h[a];j;j=d[j].n){
			b = d[j].b;
			c = d[j].c;
			wan[a] = min(wan[a],wan[b]-c);//Ѱ���������ʱ�� 
		}
	}
	for(int i=1;i<=n;++i){
		if(zao[i] == wan[i])//��ͬ��� 
		printf("%d ",i);
	}	
	return 0;
}
