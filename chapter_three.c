
#include<stdio.h>
#include <stdlib.h>
#include<math.h>

// 1. 假如我国国民生产总值年增长率为9%，计算10年后我国国民生产总值于现在相比增长了多少百分比。r为增长率，n为年数，p为与现在相比的倍数。

int main()
{
    double r = 0.09;
    int n = 10;
    double p = 1;

    int i = 0;
    for(i = 0; i<n; i++)
    {
        p = p*(1 + r);
    }

    printf("%lf\n",p);

    return 0;
}



/** 2. 存款利息的计算。 有1000元，想存5年，可按以下5种办法存：
  *  （1）一次存5年。
  *  （2）先存2年期，到期后将本息再存3年。
  *  （3）先存3年期，到期后将本息再存2年。
  *  （4）存1年期，到期后将本息再存1年期，连续存五年。
  *  （5）存活期存款。活期利息每季度结算一次。
  *  2007年12月银行存款利息如下：
  *  1年定期存款利息为4.14%；
  *  2年定期存款利息为4.68%；
  *  3年定期存款利息为5.4%；
  *  5年定期存款利息为5.85%；
  *  活期存款利息为0.72%（活期存款每一季度结算一次利息）。
  */

int main()
{
    double interest = 1;
    int principal = 1000;
    double r1 = 0.0414;
    double r2 = 0.0468;
    double r3 = 0.054;
    double r5 = 0.0585;
    double r_s = 0.0072;

    printf("(1)\t%lf\n",principal*(1+r5));
    printf("(2)\t%lf\n",principal*(1+r2)*(1+r3));
    printf("(3)\t%lf\n",principal*(1+r3)*(1+r2));

    int i = 0;
    for(i = 0; i<5; i++)
        interest = interest*(1 + r1);
    printf("(4)\t%lf\n",principal*interest);

    i = 0;
    interest = 1;
    for(i = 0; i<20; i++)
        interest = interest*(1 + r_s/4);
    printf("(5)\t%lf\n",principal*interest);

    return 0;
}



// 3. 购房从银行贷了一笔款d，主内每月还款额为p，月利率为r，计算多少月能还清。设d为30000元，p为6000元，r为1%、对求得的月份去小数点后一位，对第2位按四舍五入处理。(公式见课本)

int main()
{
    double d = 30000;
    double p = 6000;
    double r = 0.01;
    double n;

    double numerator = log(p) - log(p - (d * r));
    double denominator = log(1 + r);
    n = numerator/denominator;

    n = (int)(n * 10 + 0.5); //利用int向零取正来实现四舍五入
    n = (double)n/10.0;      //也可以用ceil() floor() 或round() 函数
    printf("%.1lf\n",n);

    return 0;
}



// 6. 请编译程序将“China”译成密码，密码规律是：用原来的字母后面第4个字母代替原来的字母。例如，字母“A”后面第4个字母是“E”，用“E”来代替“A”。因此，“China”应该译为“Glmre”。
//    请编一程序，用赋初值的方式是c1,c2,c3,c4,c5这5个变量的值分别为‘C’，‘h’，‘i’，‘n’，‘a’，经过运算，使c1,c2,c3,c4,c5这5个变量分别变为‘G’‘l’‘m’‘r’‘e’。分别用putchar和printf来输出这5个字符。


int main()
{
    char c1 = 'C';
    char c2 = 'h';
    char c3 = 'i';
    char c4 = 'n';
    char c1 = 'a';

    c1 = c1 + 4;
    c2 = c2 + 4;
    c3 = c3 + 4;
    c4 = c4 + 4;
    c5 = c5 + 4;

    putchar(c1);
    putchar(c2);
    putchar(c3);
    putchar(c4);
    putchar(c5);
    putchar(\n);

    printf("%c%c%c%c%c\n",c1,c2,c3,c4,c5);

    return 0;
}


// 7.设圆的半径r=1.5，圆柱高h=3，求圆周长，圆面积，圆球表面积，圆球体积，圆柱体积。用scanf输入数据，输出计算结果，输出时要求有文字说明，取小数点后2位数字。


#define PI 3.1415926

int main()
{
    double r = 0;
    double h = 0;

    scanf("请输入圆的半径：%lf",r);
    scanf("请输入圆柱的高：%lf",h);

    printf("圆的周长是：%0.2lf\n",round(2*PI*r*100)/100);     //round() 是整数位四舍五入的函数
    printf("圆的面积是：%0.2lf\n",round(PI*r*r*100)/100);
    printf("圆球的表面积是：%0.2lf\n",round(4*PI*r*r*100)/100);
    printf("圆柱的体积是：%0.2lf\n",round(3*PI*r*r*r/4*100)/100);

    return 0;
}


