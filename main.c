#include <stdio.h>
#include <stdlib.h>

#define max_len 5

typedef struct
{
    int x;
    int y;
} rel_t;

void checking(rel_t *rel, int *a, int *b)
{
    *a = rel -> x;
    *b = rel -> y;
}

int isRef(rel_t *rel)
{
    int a = 0;
    int b = 0;

    rel_t *rel_buff;

    for (int i = 0; i < max_len - 1; i++)
    {
        rel_buff = &rel[i];
        checking(rel_buff, &a, &b);

        if (a == b)
            return 1;
        else
            continue;
    }
    
    return 0;
}

int isSym(rel_t *rel)
{
    int a = 0;
    int b = 0;

    int a_buff = 0;
    int b_buff = 0;

    int cnt = 0;

    rel_t *rel_buff;

    for (int i = 0; i <= max_len - 1; i++)
    {
        rel_buff = &rel[i];
        checking(rel_buff, &a, &b);

        a_buff = a;
        b_buff = b;

        for (int j = 0; j <= max_len - 1; j++)
        {
            rel_buff = &rel[j];
            checking(rel_buff, &a, &b);
            if ((a == b_buff) && (b == a_buff))
            {
                if ((a_buff == b_buff) && (a == b))
                {
                    cnt++;
                    break;
                }
                cnt++;
                break;
            }
        }
    }

    if (cnt == max_len)
        return 1;

    return 0;
}

int isAntisym(rel_t *rel)
{
    int a = 0;
    int b = 0;

    int a_buff = 0;
    int b_buff = 0;

    int cnt = 0;

    rel_t *rel_buff;

    for (int i = 0; i <= max_len - 1; i++)
    {
        rel_buff = &rel[i];
        checking(rel_buff, &a, &b);

        a_buff = a;
        b_buff = b;

        for (int j = 0; j <= max_len - 1; j++)
        {
            rel_buff = &rel[j];
            checking(rel_buff, &a, &b);
            if ((a == b_buff) && (b == a_buff))
            {
                if ((a_buff == b_buff) && (a == b))
                {
                    cnt++;
                    break;
                }
                else
                    return 0;
            }
            else
            {
                cnt++;
                break;
            }
        }
    }

    if (cnt == max_len)
        return 1;

    return 0;
}

int isTran(rel_t *rel)
{
    int a = 0;
    int b = 0;

    int a_buff = 0;
    int b_buff = 0;
    int c_buff = 0;

    rel_t *rel_buff;

    for (int i = 0; i <= max_len - 1; i++)
    {
        rel_buff = &rel[i];
        checking(rel_buff, &a, &b);

        a_buff = a;
        b_buff = b;

        for (int j = 0; j <= max_len - 1; j++)
        {
            if (a == b)
                break;
            rel_buff = &rel[j];
            checking(rel_buff, &a, &b);
            if (a == b_buff)
            {
                checking(rel_buff, &b_buff, &c_buff);
                printf("(%d %d) (%d %d) -> (%d %d)\n", a_buff, b_buff, b_buff, c_buff, a_buff, c_buff);
            }
        }
    }

    return 0;
}

int main()
{
    rel_t rel1[max_len] = { {0,3}, {3,2}, {3,3}, {1,1}, {4,0} };
    
    if (isRef (rel1))
        printf("reflexive\n");
    
    if (isSym (rel1))
        printf("symmetric\n");

    if (isAntisym (rel1))
        printf("antisymmetric\n");

    isTran(rel1);

    return 0;
}
