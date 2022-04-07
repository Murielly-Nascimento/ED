#include <stdio.h>

void shellsort(int v[], int n)
{
    int i = 0, j = 0, k = 0, h = 1;
    int aux = 0;

    do
    {
        h = h * 3 + 1;
    } while (h < n);

    do
    {
        h /= 3;
        for (i = h; i < n; i++)
        {
            aux = v[i];
            j = i;
            while (v[j - h] > aux)
            {
                v[j] = v[j - h];
                j -= h;
                if (j < h)
                    break;
            }
            v[j] = aux;
        }
    } while (h != 1);
}

int main(void)
{
    int v[] = {6, 5, 4, 3, 2, 1};
    int n = 6;

    shellsort(v, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
