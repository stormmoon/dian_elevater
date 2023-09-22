#include <stdio.h>
int abs(int m)//绝对值函数
{
    if (m < 0)
    {
        m = m * -1;
    }
    return m;
}
int fi(int q[])//判断列表里还有没有人
{
    for (int i = 1;  i < 1000;i++)
    {
        if (q[i] != 0)
        {
            return 1;
        }
    }
    return 0;
}
int fi1(int q[], int n)//判断列表里还有没有人
{
    for (int i = n; i<1000; i++)
    {
        if (q[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}
int fi2(int q[], int n)//判断列表里还有没有人
{
    for (int i = n; i>0; i --)
    {
        if (q[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int org = 0, ck[1000] = { 0,0 }, ck1[1000] = { 0,0 }, cf = 1, dd = 1, max1 = 0, bl = 0, pd = 1, num = 0, time = -1;//这里设计的超载人数为13
    scanf_s("%d", &org);
    printf("请输入乘客信息：\n");
    while (dd > 0 && cf > 0)
    {
        scanf_s("%d %d", &cf, &dd);
        ck[cf] = dd;//ck用于保存每层楼的人想去的地方
        if (cf > max1)//此处用于寻找最高所需要出发的楼层
        {
            max1 = cf;
        }
    }
    printf("%d 0 0\n", org);
    if (max1 < org)//此处判断电梯有无向上的必要
    {
        pd = 0;
    }
    if (pd == 0)//此处代表电梯可以直接往下运行
    {
        
        while (fi(ck) == 1)//还有人没有上电梯
        {
            for (int i = org; i>0; i--)
            {
                time += 1;//每过一次循环代表时间加一
                if (ck1[i] < 0)//代表到这层之后有要下的人
                {
                    num += ck1[i];
                    printf("%d %d %d\n", i, time, num);
                    ck1[i] = 0;
                }
                int a = (ck[i] - i);//判断方向
                if ((ck[i] > 0) && (num < 13) && (a < 0))//没有超载且有人要上
                {
                    num += 1;
                    printf("%d %d %d\n", i, time, num);
                    ck1[ck[i]] -= 1;
                    ck[i] = 0;
                }
                if ((fi2(ck, i) == 1) && (fi2(ck1, i) == 1))//仍然有人没有下或者没有上
                {
                    org = i;
                    break;
                }
            }
            for (int i = org; i < 1000; i++)
            {
                time += 1;
                if (ck1[i] < 0)
                {
                    num += ck1[i];
                    printf("%d %d %d\n", i, time, num);
                    ck1[i] = 0;
                }
                int a = ck[i] - i;
                if ((ck[i] > 0) && (num < 13) && (a > 0))
                {
                    num += 1;
                    printf("%d %d %d\n", i, time, num);
                    ck1[ck[i]] -= 1;
                    ck[i] = 0;
                }
                if ((fi1(ck, i) == 1) && (fi1(ck1, i) == 1))
                {
                    org = i;
                    break;
                }
            }

        }
    }
    else
    {
        while (fi(ck) == 1)
        {
            for (int i = org; i < 1000; i++)
            {
                time += 1;
                int a = ck[i] - i;
                if (ck1[i] < 0)
                {
                    num += ck1[i];
                    printf("%d %d %d\n", i, time, num);
                    ck1[i] = 0;
                }
                if ((ck[i] > 0) && (num < 13) && (a > 0))
                {
                    num += 1;
                    printf("%d %d %d\n", i, time, num);
                    ck1[ck[i]] -= 1;
                    ck[i] = 0;
                }
                if ((fi1(ck, i) == 1) && (fi1(ck1, i) == 1))
                {
                    org = i;
                    break;
                }
            }
            for (int i = org; i > 0; i--)
            {
                time += 1;
                if (ck1[i] < 0)
                {

                    num += ck1[i];
                    printf("%d %d %d\n", i, time, num);
                    ck1[i] = 0;
                }
                int a = ck[i] - i;
                if (ck[i] > 0 && num < 13 && a > 0)
                {
                    num += 1;
                    printf("%d %d %d\n", i, time, num);
                    ck1[ck[i]] -= 1;
                    ck[i] = 0;
                }
                if ((fi2(ck, i) == 1) && (fi2(ck1, i) == 1))
                {
                    org = i;
                    break;
                }
            }

        }
    }//四块代码功能基本一致，所以我就写一部分注释了
    printf("电梯已结束运行。");
    return 0;
}