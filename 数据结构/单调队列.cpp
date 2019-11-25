#include<cstdio>
using namespace std;
struct node{
	int x,i;
}a[2000005];
int n,k,head,tail; 
int main(){
	scanf("%d%d",&n,&k);
	printf("0\n");
	scanf("%d",&a[1].x);
	a[1].i = 1;
	head = tail = 1;
	for(int i=2;i<=n;++i){	
		if(a[head].i+k < i)	head++;
		while(head < tail && a[tail].x <= a[tail-1].x)	a[tail-1] = a[tail], tail--;
		printf("%d\n",a[head].x);
		scanf("%d",&a[++tail].x);
		a[tail].i = i;
	}
	return 0;
}
