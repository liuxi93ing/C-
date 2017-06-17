#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// 4. 有三个整数a，b，c，由键盘输入，输出其中最大的数。
/*
int main()
{
        int a, b, c, t;
        printf("输入a，b，c的值，以空格分隔：");
        scanf("%d%d%d",&a,&b,&c);
        t = a > b? a : b;
        t = t > c? t : c;
        printf("最大的数是：%d\n",t);
        return 0;
}
*/

// 5. 从键盘输入一个小于1000的正数，要求输出它的平方根（如果平方根不是整数，则输出其整数部分）。要求输入数据后先对其进行检查是否为小于1000的正数。若不是，则要求重新输入。
/*
int main()
{
    double num = 0;
    printf("输入一个小于1000的正数：");
    scanf("%lf",&num);
    while(num>=1000||num<=0)
    {
        printf("超出范围，请重新输入：");
        scanf("%lf",&num);
    }

    printf("其平方根为：%d\n",(int)sqrt(num));
    return 0；
}
*/

// 6. 有一个函数（见课本）， 写程序，输入x的值，输出y对应的值。
/*
int main()
{
    double x , y;
    scanf("%lf",&x);

    if(x<1)
        y = x;
    else if(x<10)
        y = 2*x - 1;
    else
        y = 3*x - 11;

    printf("%ld\n",y); //%g 输出浮点数时，不会输入多余的0，最多输出6位小数,但是自动四舍五入而导致会丢失精度，不建议使用  (可改成以%g格式输出，分别尝试输入9.9999,和9.99999）
    return 0;
}
*/

// 8. 给出一百分制成绩，要求输出成绩等级‘A’‘B’‘C’‘D’‘E’。90分以上为‘A’，80~89分为‘B’，70~79分为‘C’，60~69分为‘D’，60分一下为‘E’。

/*
int main()
{
    double grade;
    scanf("%lf",&grade);

    if(grade>100||grade<0)
        printf("成绩错误");
    else if(grade>=90)
        printf("A");    //printf() 不能用单引号来输出单个字符，如printf('A')会报错
    else if(grade>=80)
        printf("B");
    else if(grade>=70)
        printf("C");
    else if(grade>=60)
        printf("D");
    else
        printf("E");

    return 0;
}
*/

// 9. 给一个不多于5位的正整数，要求：（1） 求出它是几位数 （2）分别输出每一位数字 （3）按逆序输出各位数字，例如原数为321，应输出123.

/*
int main()
{
    int num;
    printf("输入一个不多于5位的正整数：");
    scanf("%d",&num);
    int temp = num;

    int bits = (int)log10((double)num)+1;
    printf("这是%d位数\n",bits);


    printf("每一位数分别为:");
    while(bits--)
    {
        printf(" %d",temp/(int)round(pow(10,bits))); //若直接写成(int)pow(10,bits) 会导致精度丢失造成误差，比如经过浮点运算的期望值为1，但浮点数表示为0.99999，强制转化后(int)0.99999 = 0.
        temp = temp%(int)round(pow(10,bits));       // pow(),log10() 等数学函数的参数和返回值都应是double类型的，
    }                                               // 可以把整形当浮点型用（函数参数用整形），但不可以把浮点型直接赋给整形（返回值不能用整形接收），强制转化后也会出现精度丢失，需特别处理

    temp = num;
    printf("\n逆序每一位数分别为：");
    while(temp)
    {
        printf(" %d",temp%10);
        temp = temp/10;
    }

    return 0;
}


*/



// 10. 企业发放的奖金根据利润提成。利润I低于或等于100000元的，奖金可提10%；利润高于100000元，低于200000元（100000<I<=200000）时，低于100000元的部分按10%提成，
//     高于100000元的部分，可提成7.5%. 200000<I<=400000时，低于200000元的部分仍按上述办法提成（下同）。高于200000元的部分按5%提成；400000<I<=600000元时，高于400000元的部分按3%提成；
//     600000<I<=1000000元时，高于600000元的部分按1.5%提成；I>1000000时，超过1000000的部分按1%提成。从键盘输入当月利润I，求应发奖金综述。要求（1）用if语句编程 （2）用switch语句编程

/*
//if 语句编程
int main()
{
    double I, bouns;

    printf("请输入本月利润：");
    scanf("%lf",&I);

    if(I <= 100000)
        bouns = I * 0.1;
    else if(I <= 200000)
        bouns = 100000*0.1 + (I-100000)*0.075;
    else if(I <= 400000)
        bouns = 100000*0.1 + (200000-100000)*0.075 + (I-200000)*0.05;
    else if(I <= 600000)
        bouns = 100000*0.1 + (200000-100000)*0.075 + (400000-200000)*0.05 + (I-400000)*0.03;
    else if(I <= 1000000)
        bouns = 100000*0.1 + (200000-100000)*0.075 + (400000-200000)*0.05 + (600000-400000)*0.03 + (I-600000)*0.015;
    else if(I > 1000000)
        bouns = 100000*0.1 + (200000-100000)*0.075 + (400000-200000)*0.05 + (600000-400000)*0.03 + (10-600000)*0.015 + (I-1000000)*0.01;
    printf("应发奖金为：%lf\n",bouns);

    return 0;
}


//switch 语句编程

int main()
{
    double I,I2,bouns;

    printf("请输入本月利润：");
    scanf("%lf",&I);

    I2 = I;
    int t = (int)I2/100000;
    switch(t)
    {
        case 0: bouns = I* 0.1; break;
        case 1: bouns = 100000*0.1 + (I-100000)*0.075; break;
        case 2:
        case 3: bouns = 100000*0.1 + (200000-100000)*0.075 + (I-200000)*0.05; break;
        case 4:
        case 5: bouns = 100000*0.1 + (200000-100000)*0.075 + (400000-200000)*0.05 + (I-400000)*0.03; break;
        case 6:
        case 7:
        case 8:
        case 9: bouns = 100000*0.1 + (200000-100000)*0.075 + (400000-200000)*0.05 + (600000-400000)*0.03 + (I-600000)*0.015; break;
        default: bouns = 100000*0.1 + (200000-100000)*0.075 + (400000-200000)*0.05 + (600000-400000)*0.03 + (1000000-600000)*0.015 + (I-1000000)*0.01; break;
    }
    printf("应发奖金为：%lf\n",bouns);
}

*/

// 11. 输入4个整数，要求按由小到大的顺序输出。
/*
int main()
{
    int max(int a, int b)
    {
        return a>b?a:b;
    }

    int min(int a, int b)
    {
        return a<b?a:b;
    }

    int n1, n2, n3, n4;
    printf("输入4个整数，以空格分隔：");
    scanf("%d%d%d%d",&n1,&n2,&n3,&n4);

    int smallest = min(min(n1,n2),min(n3,n4));
    int largest = max(max(n1,n2),max(n3,n4));
    int middle_two_sum = n1+n2+n3+n4-smallest-largest;

    if(n1+n2 == middle_two_sum)
            printf("%d  %d  %d  %d\n",smallest,min(n1,n2),max(n1,n2),largest);
    else if(n1+n3 == middle_two_sum)
            printf("%d  %d  %d  %d\n",smallest,min(n1,n3),max(n1,n3),largest);
    else if(n1+n4 == middle_two_sum)
            printf("%d  %d  %d  %d\n",smallest,min(n1,n4),max(n1,n4),largest);
    else if(n2+n3 == middle_two_sum)
            printf("%d  %d  %d  %d\n",smallest,min(n2,n3),max(n2,n3),largest);
    else if(n2+n4 == middle_two_sum)
            printf("%d  %d  %d  %d\n",smallest,min(n2,n4),max(n2,n4),largest);
    else if(n3+n4 == middle_two_sum)
            printf("%d  %d  %d  %d\n",smallest,min(n3,n4),max(n3,n4),largest);
    return 0;

}
*/


// 12. 有4个圆塔，圆心分别为（2，2）、（-2，2）、（-2，-2）、（2，-2），圆半径为1，这4个塔的高度为10米，塔以外无建筑物。今输入任一点的坐标，求该点的建筑高度（塔外的高度为零）。

/*
int main()
{
    double x = 0, y = 0;
    double d1, d2, d3, d4;

    printf("输入此点坐标，以逗号分隔：");
    scanf("%lf,%lf",&x,&y);

    d1 = sqrt((x-2)*(x-2)+(y-2)*(y-2));
    d2 = sqrt((x-2)*(x-2)+(y+2)*(y+2));
    d3 = sqrt((x+2)*(x+2)+(y+2)*(y+2));
    d4 = sqrt((x+2)*(x+2)+(y-2)*(y-2));

    if(d1<=1||d2<=1||d3<=1||d4<=1)
        printf("此点的建筑高度为10米\n");
    else
        printf("此点的建筑高度为0米\n");

    return 0;

}
*/
