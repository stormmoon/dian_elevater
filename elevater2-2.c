#include <stdio.h>
int sx(int m, int n)//判断方向
{
    if (m > n)
    {
        return -1;
    }
    return 1;
}
int fi(int q[][2])//判断列表里有没有人
{
    for (int i = 0; i < 1000; i++)
    {
        if (q[i][0] != 0);
        {
            return 1;
        }
    }
    return 0;
}
int abs(int m)//绝对值函数
{
    if (m < 0)
    {
        m = m * -1;
    }
    return m;
}
int main()
{
    int cf = 1, dd = 1, dd1[100] = {0}, dd2[100] = {0}, spa = -1, dt1[2] = {0,0}, dt2[2] = {0,0}, lc[100][2] = {0}, yx[100][2] = {0}, time = 0, min = 1000, max = 0, num1 = 0, num2 = 0, pd,ls1=0,ls2=0;
    printf("elevater:\n");
    scanf_s("%d %d", &ls1, &ls2);
    dt1[0] = ls1;//电梯一号
    dt2[0] = ls2;//电梯二号
    for (int i = 0; i < 100; i++)//储存时间的初始化
    {
        lc[i][1] = -1;
    }
    while (cf != 0 && dd != 0)//录入乘客数据
    {
        scanf_s("%d %d %d", &cf, &dd, &spa);
        lc[cf][0] = dd;
        lc[cf][1] = spa;
        if (min > cf && spa==0)
        {
            min = cf;
        }
        if (max < cf && spa==0)
        {
            max = cf;
        }
    }
    if (dt2[0] > dt1[0])//判断初次运动方向
    {
        if (max > dt1[0])
        {
            dt1[1] = 1;
        }
        else if (lc[dt1[0]] != 0)
        {
            dt1[1] = sx(dt1[0], lc[dt1[0]][0]);
        }
        if (min < dt2[0])
        {
            dt2[1] = -1;
        }
        else if (lc[dt2[0]]!=0)
        {
            dt2[1] = sx(dt2[0], lc[dt2[0]][0]);
        }
    }
    else
    {
        if (max > dt2[0])
        {
            dt2[1] = 1;
        }
        else if (lc[dt2[0]] != 0)
        {
            dt2[1] = sx(dt2[0], lc[dt2[0]][0]);
        }
        if (min < dt1[0])
        {
            dt1[1] = -1;
        }
        else if (lc[dt1[0]] != 0)
        {
            dt1[1] = sx(dt1[0], lc[dt1[0]][0]);
        }
    }
    while (fi(lc)==1 || fi(yx)==1 ||num1!=0 || num2!=0 )//电梯正式开始运行
    {
        for (int i = 1; i < 100; i++)
        {
            if (lc[i][1] == time)//录入刚刚按下电梯的乘客并且确定乘客的上下界
            {
                yx[i][0] = lc[i][0];
                yx[i][1] = sx(i, yx[i][0]);
                lc[i][0] = 0;
                lc[i][1] = -1;
                if (yx[i][0] > max)
                {
                    max = yx[i][0];
                }
                if (yx[i][0] < min)
                {
                    min = yx[i][0];
                }
            }
        }
        if (dt1[0] > dt2[0] && dt1[1] == -1 && dt2[1] == 1)//在相向而行时判断是否有电梯应该停下来
        {
            pd = 1;
            for (int i = dt2[0]; i < (dt1[0]+dt2[0])/2; i++)
            {
                if (yx[i][0] != 0)
                {
                    pd = 0;
                    break;
                }
            }
            if (pd == 1)
            {
                dt2[1] = 0;
            }
            pd = 1;
            for (int i = dt1[0]; i >= (dt1[0] + dt2[0]) / 2; i--)
            {
                if (yx[i][0] != 0)
                {
                    pd = 0;
                    break;
                }
            }
            if (pd == 1)
            {
                dt1[1] = 0;
            }
        }
        if (yx[dt1[0]][0] != 0 && dt1[1]==yx[dt1[0]][1])//电梯一号上人
        {
            if (yx[dt1[0]][0] < min)
            {
                min = yx[dt1[0]][0];
            }
            if (yx[dt1[0]][0] > max)
            {
                max = yx[dt1[0]][0];
            }
            num1 += 1;
            yx[dt1[0]][0] = 0;
            dd1[dt1[0]] += yx[dt1[0]][0];
            printf("电梯一号：%d %d %d\n", dt1[0], time, num1);
        }
        if (dd1[dt1[0]] >0)//电梯一号下人
        {
            num1 -= dd1[dt1[0]];
            dd1[dt1[0]] = 0;
            printf("电梯一号：%d %d %d\n", dt1[0], time, num1);
        }
        if (yx[dt2[0]][0] != 0 && dt2[1] == yx[dt2[0]][1])//电梯二号上任
        {
            if (yx[dt2[0]][0] < min)
            {
                min = yx[dt2[0]][0];
            }
            if (yx[dt2[0]][0] >max)
            {
                max = yx[dt2[0]][0];
            }
            num2 += 1;
            yx[dt2[0]][0] = 0;
            dd2[dt2[0]]+= yx[dt2[0]][0];
            printf("电梯二号：%d %d %d\n", dt2[0], time, num2);
        }
        if (dd1[dt2[0]] >0)///电梯二号下人
        {
            num2 -= dd2[dt2[0]];
            dd2[dt2[0]] = 0;
            printf("电梯二号：%d %d %d\n", dt2[0], time, num2);
        }
        if (min == dt1[0]|| min==dt2[0])//转向
        {
            if (min == dt1[0])
                dt1[1] = dt1[1] * -1;
            if (min == dt2[0])
                dt2[1] = dt2[1] * -1;
            min = 1000;
            for (int i = 1; i < 100; i++)
            {
                if (dd1[i] <min  || dd2[i]<min)
                {
                    min = i;
                    break;
                }
            }
        }
        if (max == dt1[0] || max == dt2[0])//转向
        {
            if (max == dt1[0])
                dt1[1] = dt1[1] * -1;
            if (max == dt2[0])
                dt2[1] = dt2[1] * -1;
            max = 0;
            for (int i = 99; i >0; i--)
            {
                if (dd1[i]>max || dd2[i]>max)
                {
                    max = i;
                    break;
                }
            }
        }
        time += 1;
        dt1[0] += dt1[1];
        dt2[0] += dt2[1];//电梯运动
    }
    return 0;
}