#include<stdio.h>

void sender()
{
    int p[50],m[50];
    int count=0,i,j,n;
    printf("Enter the no of bits\n");
    scanf("%d",&n);
    printf("Enter the message bits\n");
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);
    for(j=0;j<8;j++)
        if(j==0 || j==7)
            m[j]=0;
        else
            m[j]=1;
    for(i=0;i<n;i++)
    {
        if(p[i]==1)
        {
            if(count==5)
            {
                m[j++]=0;
                m[j++]=p[i];
                count=0;
            }
            else
            {
                m[j++]=p[i];
                count++;
            }
        }
        else
        {
             if(count==5)
            {
                m[j++]=0;
                m[j++]=p[i];
                count=0;
            }
            else
            {
                m[j++]=p[i];
                count=0;
            }
        }
    }
    m[j++]=0;
    m[j++]=1;
    m[j++]=1;
    m[j++]=1;
    m[j++]=1;
    m[j++]=1;
    m[j++]=1;
    m[j++]=0;
    printf("THe meassage sent is : ");
    for(i=0;i<j;i++)
        printf("%d",m[i]);
    printf("\n");
    reciever(j,m);
}
void reciever(int n,int m[])
{
    int p[50];
    int i,j=0,count=0;
    for(i=8;i<n-8;i++)
    {
        if(m[i]==0)
        {
            if(count==5)
            {
                i++;
                p[j++]=m[i];
                count=0;
            }
            else
            {
                p[j++]=m[i];
                count=0;
            }
        }
        else
        {
            p[j++]=m[i];
            count++;
        }

    }
    printf("THe meassage sent is : ");
    for(i=0;i<j;i++)
        printf("%d",p[i]);
    printf("\n");
}
void main()
{
    sender();
}