#include<cstdio>
using namespace std;
//���Լ��(ŷ�����)
int gcd(int a, int b){
   if (b==0) return a;
   return gcd(b, a % b);
}
//��չŷ����� ��֤�������ٶȣ� 
int exgcd(int a,int b,int &x,int &y){
	if(b == 0){
		x = 1;		y = 0;
	}
	exgcd(b,a%b,y,x);
	y -= a/b * x;
} 
int main(){
	int a,b,c,x,y; 
	scanf("%d%d",&a,&b);
	int d = gcd(a,b);
	//ax+by = d;��x��y 
	exgcd(a,b,x,y);
	printf("%d%d",x,y);
	return 0;
}
