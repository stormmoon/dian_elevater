#include <stdio.h>
int abs(int m)//绝对值函数
{
    if (m < 0)
    {
        m = m * -1;
    }
    return m;
}
int fi(int q[])//判断列表里有没有人
{
    for (int i = 1; i < 1000; i++)
    {
        if (q[i] != 0)
        {
            return 1;
        }
    }
    return 0;
}
int fi1(int q[], int n)//判断列表里有没有人
{
    for (int i = n; i < 1000; i++)
    {
        if (q[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}
int fi2(int q[], int n)//判断列表里有没有人
{
    for (int i = n; i > 0; i--)
    {
        if (q[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}
int fi3(int q[][2])//判断列表里有没有人
{
    for (int i = 1; i < 1000; i++)
    {
        if (q[i][0] != -1)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int org = 0, ck[1000] = { 0,0 }, ck1[1000] = { 0,0 }, ck2[1000][2], cf = 1, dd = 1, spa = 0, max1 = 0, bl = 0, pd = 1, num = 0, time = -1;//这里设计的超载人数为13
    for (int i = 0; i < 1000; i++)//把时间的初值都赋值成-1
    {
        ck2[i][0] = -1;
    }
    scanf_s("%d", &org);
    printf("请输入乘客信息：\n");
    while (dd > 0 && cf > 0)
    {
        scanf_s("%d %d %d", &cf, &dd, &spa);//此处默认有人立刻按下了电梯,即一定有spa=0
        ck2[cf][0] = spa;
        ck2[cf][1] = dd;
        if (spa == 0)
        {
            ck[cf] = dd;//将已经按下电梯的人录入列表
        }
        if (cf > max1)
        {
            max1 = cf;//找到最大的出发楼层
        }
    }
    printf("%d 0 0\n", org);
    if (max1 < org)//判断是否需要向上
    {
        pd = 0;
    }
    if (pd == 0)//不需要向上
    {

        while (fi(ck) == 1 || fi3(ck2)==1)//列表里还有人的情况
        {
            for (int i = org; i > 0; i--)
            {
                time += 1;//每次循环时间加一
                for (int j = 1; j <= max1; j++)
                {
                    if (ck2[j][0] == time)//每次运行到时间后将按下电梯的用户录入
                    {
                        ck[j] = ck2[j][1];
                        ck2[j][0] = -1;
                    }
                }
                if (ck1[i] < 0)//有人在该楼下
                {
                    num += ck1[i];
                    printf("%d %d %d\n", i, time, num);
                    ck1[i] = 0;
                }
                int a = (ck[i] - i);//判断向上向下的方向
                if ((ck[i] > 0) && (num < 13) && (a < 0))//在没有超载时上人
                {
                    num += 1;
                    printf("%d %d %d\n", i, time, num);
                    ck1[ck[i]] -= 1;
                    ck[i] = 0;
                }
                if ((fi2(ck, i) == 1) && (fi2(ck1, i) == 1))//判断列表里有有没有人
                {
                    org = i;
                    break;
                }
            }
            for (int i = org; i < 1000; i++)
            {
                time += 1;
                for (int j = 1; j <= max1; j++)
                {
                    if (ck2[j][0] == time)
                    {
                        ck[j] = ck2[j][1];
                        ck2[j][0] = -1;
                    }
                }
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
        while (fi(ck) == 1 || fi3(ck2) == 1)
        {
            for (int i = org; i < 1000; i++)
            {
                time += 1;
                for (int j = 1; j <= max1; j++)
                {
                    if (ck2[j][0] == time)
                    {
                        ck[j] = ck2[j][1];
                        ck2[j][0] = -1;
                    }
                }
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
                for (int j = 1; j <= max1; j++)
                {
                    if (ck2[j][0] == time)
                    {
                        ck[j] = ck2[j][1];
                        ck2[j][0] = -1;
                    }
                }
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
    }//四段代码意思差不多，注释我就只写一段了
    printf("电梯已结束运行。");
    return 0;
}