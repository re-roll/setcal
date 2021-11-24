#include <stdio.h>
#include <stdlib.h>

#define max_len 6

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

    int x = 0;
    int z = 0;

    int cnt_a = 0;
    int cnt_b = 0;

    rel_t *rel_buff;

    for (int i = 0; i <= max_len - 1; i++)
    {
        rel_buff = &rel[i];
        checking(rel_buff, &a, &b);

        a_buff = a;
        b_buff = b;

        x = a;
        z = b;

        for (int j = 0; j <= max_len - 1; j++)
        {
            rel_buff = &rel[j];
            checking(rel_buff, &a, &b);
            if (a == b_buff)
            {
                cnt_a++;
                checking(rel_buff, &b_buff, &c_buff);
                if ((a_buff == x) && (c_buff == z))
                {
                    cnt_b++;
                    break;
                }
                for (int k = 0; k <= max_len - 1; k++)
                {
                    rel_buff = &rel[k];
                    checking(rel_buff, &x, &z);
                    if ((a_buff == x) && (c_buff == z))
                    {
                        cnt_b++;
                        break;
                    }
                }
            }
        }
    }

    if (cnt_a == cnt_b)
        return 1;

    return 0;
}

int isFunction (rel_t *rel)
{
    int a = 0;
    int b = 0;

    int a_buff = 0;
    int b_buff = 0;

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
            if ((a == a_buff) && (b != b_buff) && (a != b))
                return 0;
        }
    }

    return 1;
}

int main()
{
    rel_t rel1[max_len] = { {3,1}, {1,3}, {0,0}, {5,1}, {7,3}, {2,1}};
    
    if (isRef (rel1))
        printf("reflexive\n");
    
    if (isSym (rel1))
        printf("symmetric\n");

    if (isAntisym (rel1))
        printf("antisymmetric\n");

    if (isTran(rel1))
        printf("transitive\n");
    
    if (isFunction(rel1))
        printf("function\n");

    return 0;
}
