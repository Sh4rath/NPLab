#include<stdio.h>

struct node{
    int dist[20];
    int from[20];
}rt[10];
void main()
{
    int dmat[10][10];
    printf("Enter the distance matrix size\n");
    int i,j,k,n;
    scanf("%d",&n);
    printf("Enter the distance matrix \n");
    for(i=0;i<n;i++)
    {
        dmat[i][i]=0;
        for(j=0;j<n;j++)
        {
            scanf("%d",&dmat[i][j]);
            
            rt[i].dist[j]=dmat[i][j];
            rt[i].from[j]=j;
        }
    }
    int count=0;
    do
    {
        count=0;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                for(k=0;k<n;k++)
                {
                    if(rt[i].dist[j]>dmat[i][k]+rt[k].dist[j])
                    {
                        rt[i].dist[j]=dmat[i][k]+rt[k].dist[j];
                        rt[i].from[j]=k;
                        count++;
                    }
                }
    } while (count!=0);
    printf("The matrix obtained:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",rt[i].dist[j]);
        printf("\n");
    }
    
}