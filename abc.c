#include<stdio.h>
int main()
{
    int t,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        c=a+b;
        printf("%d",c);
    }
    return 0;
}