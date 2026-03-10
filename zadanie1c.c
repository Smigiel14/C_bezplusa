#include <stdio.h>
int x = 1;
int p;

int main (int argc, char *argv[] )
{
    if (argc==1)
{
    printf("utwórz prostokątną tabliczkę n na m\n");
    printf("Podaj wartość n: ");
    int n;
    scanf("%d", &n);
    printf("Podaj wartość m: ");
    int m;
    scanf("%d", &m);
    
    
    p = n*m;
    while(p!=0)
    {
        p=p/10;
        x++;
    }

    

    for (int i=1; i<= n; i++)
    {
        for (int j=1; j<= m; j++)
        {
            printf("%*d",x, i*j);
        }
            printf("\n");
    }
}
    if (argc>1)
{
    printf("utwórz prostokątną tabliczkę n na m\n");
    printf("Podaj wartość n: ");
    int n;
    scanf("%d", &n);
    printf("Podaj wartość m: ");
    int m;
    scanf("%d", &m);
    
    int p=n*n;
    while(p!=0)
    {
        p=p/16;
        x++;
    }

    

    
    for (int i=1; i<= n; i++)
    {
        for (int j=1; j<= m; j++)
        {
            printf("%*X",x, i*j);
        }
            printf("\n");
}
}
}