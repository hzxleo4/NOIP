#include<cstdio>
using namespace std;
int n,m,f[10010],x,y,z,a,b;
int find(int x){
	if (x == f[x])	return x;
	return f[x] = find(f[x]);//压缩路径 
} 
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)	f[i] = i;//每个人都是自己的爸爸 
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&z,&a,&b);
		x = find(a);
		y = find(b);
		if(z == 1){
			f[x] = y;//a与b有关系 b的祖先就是a 
		}
		else{
			if (x != y)//如果他们爸爸不同 
			printf("N\n");
			else
			printf("Y\n");
		}
	}
	return 0;
}