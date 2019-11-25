#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int st[20][100005],a[100005],n,m;
int main(){
	scanf("%d",&n);//st表 区间查询O(1) 
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		st[0][i] = a[i];
	}

	for(int i=1;i<=20;++i){//二十层，每层都是2的n次方 
		for(int j=1;j+(1<<i)-1 <= n;++j){//枚举每一层的每一个值 
			st[i][j] = min(st[i-1][j],st[i-1][j+(1<<(i-1))]);//选上一层的最小/大值 
		}
	}
	for(int i=0;i<=5;++i){
		for(int j=1;j<=n;++j){
			printf("%d ",st[i][j]);
		}
		printf("\n");
	}
		scanf("%d",&m);//m次询问 
	for(int i=1;i<=m;++i){
		int x;
		int y;
		scanf("%d%d",&x,&y);
		int z=log2(y-x+1);//找到(x,y)在的层数 
		printf("%d\n",min(st[z][x],st[z][y+1-(1<<z)]));//选一个最小/大值 
	}
	return 0;
}
