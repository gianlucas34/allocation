#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{

    setlocale(LC_ALL, "");

    int *p;
    int i = 1, k, n;

    p = (int *)(malloc(i*sizeof(int)));

    if(p == NULL)
    {
        printf("\nErro de aloca��o de mem�ria!!!");
        exit(1);
    }

    for(k=0; k<i; k++)
    {
        printf("Digite o n�mero para o indice %d: ", k);
        scanf("%d", &p[k]);

        if(p[k]>0)
        {
            p = (int *)(realloc(p,(i+1)*sizeof(int)));

            i++;

            if(p == NULL)
            {
                printf("\nErro de re-aloca��o de mem�ria!!!");
                exit(1);
            }
        }
        else if(p[k]<=0)
        {
            printf("\nImposs�vel alocar n�meros negativos!!!");

            i -= 1;
            break;
        }
    }

    printf("\n\n");

    for(k=0; k<i; k++)
    {
        printf("O n�mero do indice %d � %d\n", k, p[k]);
    }

    free(p);

    return 0;
}
