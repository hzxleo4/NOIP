#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int a,b,c,v,n;
}d[100005];
int h[100005],w[100005],v[100005],n,m,s,t,q[100005],u[100005],f[100005]; 
void input(int i,int a,int b,int c,int v){
	d[i].a = a;	d[i].b = b;
	d[i].c = c;	d[i].v = v;
	d[i].n = h[a];	h[a] = i;
}
void bfs(){
	int head,tail;
	memset(w,0,sizeof(w));
	memset(u,0,sizeof(u));
	memset(v,1,sizeof(v));
	v[s] = 0;	w[s] = 2e9;
	head = tail = 1;
	q[1] = s;
	while(head <= tail){
		int a = q[head++];
		u[a] = 0;
		for(int i=h[a];i;i=d[i].n){
			int b = d[i].b,c = d[i].c,z = d[i].v;
			if(c && v[a] + z < v[b]){
				w[b] = min(w[a],c);
				v[b] = v[a] + z;
				f[b] = i;
				if(!u[b]){
					if(v[q[head]] > v[b] && head > 1){
						q[--head] = b;
					}
					else	q[++tail] = b;
					u[b] = 1;
				}	
			}
		}	
	}
	for(int i=f[t];i;i=f[d[i].a]){
		d[i].c -= w[t];
		d[i+m].c += w[t];
	}
}
int main(){
	int a,b,c,z,ans1 = 0,ans2 = 0;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d%d",&a,&b,&c,&z);
		input(i,a,b,c,z);
		input(i+m,b,a,0,-z);
	}
	while(1){
		bfs();
		if(w[t] > 0){
			ans1 += w[t];
			ans2 += v[t] * w[t];
		}
		else	break;
	}
	printf("%d %d",ans1,ans2);
	return 0;
}
