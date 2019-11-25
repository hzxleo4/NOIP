#include<cstdio>
#include<algorithm>
using namespace std;
int a[10],len;
void push(int x){
	int p,s;
	a[++len] = x;
	p = len/2;
	s = len;
	while(p>0	&&	a[s]	<	a[p]){
		swap(a[s],a[p]);
		s = p;
		p /= 2;
	}
}
void pop(){
	int next = 1;
	int now = 1;
	a[1] = a[len--];
	while(1){
		if (now*2 <= len  && a[now*2] < a[next])	next = now*2;
		if (now*2+1 <=len && a[now*2+1] < a[next])	next = now*2+1;
			if (now == next)	break;	
			swap(a[now],a[next]);
			now = next;

	}
}
int main(){//最小堆 
	int n,x;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&x);
		if (x == 1){
			scanf("%d",&x);
			push(x);//放进堆 
		}
		if (x == 2)
		printf("%d ",a[1]);
		if (x == 3)
		pop();//出堆 
	}
	return 0;
}
