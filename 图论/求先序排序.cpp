#include<cstdio>
#include<cstring>
using namespace std;
char s1[25],s2[25];
void dfs(int l1,int r1,int l2,int r2){
	if(l1 > r1 || l2 > r2)	return ;
	printf("%c",s2[r2]);
	int mid = l1;
	while(s1[mid] != s2[r2] && mid <= r1){
		mid++;
	}
	if(s1[mid] == s2[r2]){
		dfs(l1,mid-1,l2,l2-l1+mid-1);
		dfs(mid+1,r1,l2+mid-l1,r2-1);
	}
}
int main(){
	scanf("%s",s1);
	scanf("%s",s2);
	dfs(0,strlen(s1)-1,0,strlen(s2)-1);
	return 0;
}
