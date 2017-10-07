#include <stdio.h>
int num=359999;
int spf[359999],mob[359999];
void pre()
{
    int i,j;
    for(i=2;i<num;i++)
    {
        if(!spf[i])
        {
            j=i;
            while(j<num)
            {
                if(!spf[j]) spf[j]=i;
                j+=i;
            }
            
        }
    }
    for(i=1;i<num;i++)
    {
        if(i==1) mob[i]=1;
        else if(spf[i/spf[i]]==spf[i]) mob[i]=0;
        else mob[i]=-1*mob[i/spf[i]];
    }
}
int main()
{
    pre();
    printf("%d %d %d\n",mob[5],mob[6],mob[18]);
    return 0;
}