#include<stdio.h>
int abs(int m)//绝对值函数
{
	if (m < 0)
	{
		return m * -1;
	}
	return m;
}
int main()
{
	int cf = 0, dd = 0,dt=0,time=0;
	scanf_s("%d", &dt);
	printf("请输入乘客信息：");
	scanf_s("%d %d", &cf, &dd);
	printf("%d %d 0\n", dt, time);//此处是在电梯出发处
	time += abs(dt - cf);
	printf("%d %d 1\n", cf, time);//此处电梯到达客人所在楼层
	time += abs(cf - dd);
	printf("%d %d 0\n", dd, time);//此处电梯到达目标位置
	return 0;
}