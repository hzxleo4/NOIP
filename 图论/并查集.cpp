#include<cstdio>
using namespace std;
int n,m,f[10010],x,y,z,a,b;
int find(int x){
	if (x == f[x])	return x;
	return f[x] = find(f[x]);//ѹ��·�� 
} 
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)	f[i] = i;//ÿ���˶����Լ��İְ� 
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&z,&a,&b);
		x = find(a);
		y = find(b);
		if(z == 1){
			f[x] = y;//a��b�й�ϵ b�����Ⱦ���a 
		}
		else{
			if (x != y)//������ǰְֲ�ͬ 
			printf("N\n");
			else
			printf("Y\n");
		}
	}
	return 0;
}