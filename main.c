#include <stdio.h>
#include <stdlib.h>

#define max_len 6
#define max_len_u 8

typedef struct
{
    int x;
    int y;
} rel_t;

typedef struct
{
    int x;
} uni_t;

void checking(rel_t *rel, int *a, int *b)
{
    *a = rel -> x;
    *b = rel -> y;
}

void checking_u(uni_t *uni, int *a)
{
    *a = uni -> x;
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

    for (int i = 0; i < max_len; i++)
    {
        rel_buff = &rel[i];
        checking(rel_buff, &a, &b);

        a_buff = a;
        b_buff = b;

        for (int j = 0; j < max_len; j++)
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

    for (int i = 0; i < max_len; i++)
    {
        rel_buff = &rel[i];
        checking(rel_buff, &a, &b);

        a_buff = a;
        b_buff = b;

        for (int j = 0; j < max_len; j++)
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

    for (int i = 0; i < max_len; i++)
    {
        rel_buff = &rel[i];
        checking(rel_buff, &a, &b);

        a_buff = a;
        b_buff = b;

        x = a;
        z = b;

        for (int j = 0; j < max_len; j++)
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
                for (int k = 0; k < max_len; k++)
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

int isFun(rel_t *rel)
{
    int a = 0;
    int b = 0;

    int a_buff = 0;

    rel_t *rel_buff;

    for (int i = 0; i < max_len; i++)
    {
        rel_buff = &rel[i];
        checking(rel_buff, &a, &b);
        a_buff = a;
        int cnt = 0;
        for (int j = 0; j < max_len; j++)
        {
            rel_buff = &rel[j];
            checking(rel_buff, &a, &b);
            if (a == a_buff)
                cnt++;
        }
        if (cnt != 1)
            return 0;
    }

    return 1;
}

void domain(rel_t *rel)
{
    int a = 0;
    int b = 0;

    rel_t *rel_buff;

    for (int i = 0; i <= max_len - 1; i++)
    {
        rel_buff = &rel[i];
        checking(rel_buff, &a, &b);
        printf("%d ", a);
    }

    printf("\n");
}

void codomain(rel_t *rel)
{
    int a = 0;
    int b = 0;

    rel_t *rel_buff;

    for (int i = 0; i <= max_len - 1; i++)
    {
        rel_buff = &rel[i];
        checking(rel_buff, &a, &b);
        printf("%d ", b);
    }

    printf("\n");
}

int isInj(rel_t *rel)
{
    if (!(isFun(rel)))
        return 0;
    
    int a = 0;
    int b = 0;

    int b_buff = 0;
    int a_buff = 0;

    rel_t *rel_buff;
    for (int i = 0; i < max_len; i++)
    {
        rel_buff = &rel[i];
        checking(rel_buff, &a, &b);
        b_buff = b;
        a_buff = a;
        for (int j = 0; j < max_len; j++)
        {
            if (i == j)
                break;
            rel_buff = &rel[j];
            checking(rel_buff, &a, &b);
            if (b == b_buff)
                if (a != a_buff)
                   return 0;
        }
    }

return 1;
}

int isSur(rel_t *rel, uni_t *uni)
{
    if (!(isFun(rel)))
        return 0;
    
    int a = 0;
    int b = 0;

    int x = 0;

    int cnt = 0;

    rel_t *rel_buff;
    uni_t *uni_buff;
    for (int i = 0; i < max_len_u; i++)
    {
        rel_buff = &rel[i];
        checking(rel_buff, &a, &b);

        uni_buff = &uni[i];
        checking_u(uni_buff, &x);

        for (int j = 0; j < max_len; j++)
        {
            rel_buff = &rel[j];
            checking(rel_buff, &a, &b);
            if (b == x)
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

int isBij(rel_t *rel, uni_t *uni)
{
    if ((isInj(rel)) && (isSur(rel, uni)))
        return 1;

    return 0;
}

int main()
{
    rel_t rel1[max_len] = { {3,8}, {6,9}, {0,0}, {5,5}, {7,2}, {2,6}};
    uni_t uni[max_len_u] = {{3}, {8}, {6}, {9}, {0}, {5}, {7}, {2}};
    
    if (isRef (rel1))
        printf("reflexive\n");
    
    if (isSym (rel1))
        printf("symmetric\n");

    if (isAntisym (rel1))
        printf("antisymmetric\n");

    if (isTran(rel1))
        printf("transitive\n");
    
    if (isFun(rel1))
        printf("function\n");

    domain(rel1);

    codomain(rel1);

    if (isInj(rel1))
        printf("injection\n");

    if (isSur(rel1, uni))
        printf("surjection\n");

    if (isBij(rel1, uni))
        printf("bijection\n");

    return 0;
}
