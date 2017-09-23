#include<stdio.h>
#include<stdlib.h>
#include<math.h>


// 3. 输入两个正整数m和n，求其最大公约数和最小公倍数。

int main()
{
    int m, n;
    printf("input two integers：");
    scanf("%d%d",&m,&n);

    int i;
    int greatest_common_factor = 1;
    int least_common_muliple = 1;
    int min = n<m?n:m;

    for(i=1;i<=min;i++)
    {
        if(i==1)
            continue;
        if(m%i==0 && n%i==0)
            greatest_common_factor = i;
    }
    least_common_muliple = m*n/greatest_common_factor;

    printf("最大公约数是:%d, 最小公倍数是:%d\n",greatest_common_factor,least_common_muliple);
    return 0;

}

// 4. 输入一行字符，分别统计出其中的英文字母，空格和其他字符的个数。

int main()
{
    char a;
    int count1 = 0,count2 = 0,count3 = 0;

    while((a=getchar())!='\n')
    {
        if(a>='a'&&a<='z'||a>='A'&&a<='Z')
            count1++;
        else if(a==' ')
            count2++;
        else
            count3++;
    }
    printf("英文字母有%d个，空格有%d个，其他字符有%d个\n",count1,count2,count3);
    return 0;
}


// 5. 求Sn=a+aa+aaa+.....+aaaaaa(n个a)的值。其中a是一个数字，n表示a的位数。a和n由键盘输入。


int main()
{
    int a, n;
    int addend = 0, sum = 0;
    printf("请输入a：");
    scanf("%d",&a);
    printf("请输入n：");
    scanf("%d",&n);

    int i;
    for(i=0;i<n;i++)
    {
        addend = addend*10 + a;
        sum = sum + addend;
    }
    printf("S=%d\n",sum);
    return 0;
}


// 6. 求1!+2!+3!+.....20!

int main()
{
    double sum = 0, addend = 1; //int 型范围不够
    int i;
    for(i=1;i<=20;i++)
    {
        addend = addend*i;
        sum = sum + addend;
    }
    printf("%lf\n",sum);
    return 0;
}


// 7. 求.....(公式打不出，见课本)

int main()
{
    double sum = 0, s1 = 0, s2 = 0, s3 = 0;
    int i = 0;

    for(i=1;i<=100;i++)
        s1 = s1 + i;

    for(i=1;i<=50;i++)
        s2 = s2 + i*i;

    for(i=1;i<=10;i++)
        s3 = s3 + 1.0/i;

    sum = s1 + s2 + s3;
    printf("%lf\n",sum);
    return 0;
}


// 8. 输入所有的水仙花数，所谓水鲜花数是指一个三位数，七个位数字立方和等于该数本身。如 153=1+125+27。

int main()
{
    int i;
    int d1, d2, d3;
    for(i = 100; i<1000; i++)
    {
        d1 = i/100;
        d2 = (i-d1*100)/10;
        d3 = i%10;

        if(d1*d1*d1+d2*d2*d2+d3*d3*d3 == i)
            printf("%d\t",i);
    }

    return 0;
}


// 9. 一个数如果恰好等于它的因子只和，这个数就被成为“完数”。例如 6 的因子是1,2,3，而6=1+2+3，因此6 就是完数。编程找出1000之内所有完数，并按下面格式输出其因子： 6 its fractors are 1,2,3

int main()
{
    int i, j, sum = 0;

    for(i=1; i<=1000; i++)
    {
        sum = 0;
        for(j=1; j<i; j++)
        {
            if(i%j == 0)
                sum = sum + j;
        }
        if(sum == i)
        {
            printf("%d its fractors are 1",sum);
            for(j=2; j<i; j++)
            {
                if(i%j == 0)
                    printf(",%d",j);
            }
            printf("\n");
        }
    }
    return 0;
}


// 10. 有一个分数序列， 2/1,3/2,5/3,8/5,13/8..... 求出这个数列前20项只和。

int main()
{
    int i;
    double sum, addend, f1 = 1, f2 = 1, f3= f1+f2;

    for(i = 1;i <= 20; i++)
    {
        addend = f3/f2;
        sum = sum + addend;
        f1 = f2;
        f2 = f3;
        f3 = f1 + f2;
    }

    printf("%lf\n",sum);
    return 0;
}



// 11. 一个球从100m高度自由下落，每次落地反跳后回到原高度的一半，再下落，再反弹。求它在第10次落地时，共经过多少米，第10次反弹多高。

int main()
{
    double sum = 0, height = 100;
    int i;

    for(i = 0; i<10; i++)
    {
        sum = sum + height;
        height = height/2;
        sum = sum + height;
    }
    sum = sum - height;  //减去第10次反弹的高度

    printf("共经过%lf米,第10次反弹%lf米\n",sum, height);
    return 0;
}
*/

// 12. 猴子吃桃问题。猴子第1天摘下若干个桃子，当即吃了一半，还不过瘾，又多吃了1个。第二天早上将剩下的桃子吃掉一半又多吃了1个。以后每天早上都吃了前一天剩下的一半零1个。
//     到第10天早上想再吃时就只剩1个桃子了。求第一天一共摘了多少个桃子。


int main()
{
    int number = 1;

    int i;
    for(i=0;i<9;i++)
        number = (number + 1)*2;

    printf("第一天摘了%d个桃子\n",number);
    return 0;
}


// 13. 用迭代法求a的平方根。迭代公式见课本。要求前后两次求出x的差的绝对值小于10的-5次方。

int main()
{
    double a, x = 1;
    double temp;
    printf("请输入a的值：");
    scanf("%lf",&a);

    while(1)
    {
        temp = x;
        x = (x+ a/x)/2;

        if(fabs(temp-x)<0.00001)
            break;
    }
    printf("%lf的平方根为%lf\n",a,x);
    return 0;
}


// 14. 用牛顿迭代法求下面方程在1.5附近的根： 2x^3-4x^2+3x-6=0

int main()
{
    double func1(double x)
    {
        return 2*x*x*x - 4*x*x + 3*x -6;
    }

    double func2 (double x)
    {
        return 6*x*x - 8*x + 3;
    }

    double x = 1.5;
    while(1)
    {
        x = x - func1(x)/func2(x);
        if(fabs(func1(x))< 0.000001)                //以浮点数大小作为判定条件时，不要是用==0， 判断绝对值是否小于趋近0的数
            break;
    }
    printf("该方程在1.5附近的根为%lf\n",x);
    return 0;
}


// 15. 用二分法求下面方程在（-10,10）之间的根： 2x^3-4x^2+3x-6=0  注：该函数在（-10,10）区间单调递增。

int main()
{
    double func1(double x)
    {
        return 2*x*x*x - 4*x*x + 3*x -6;
    }

    double left = -10;
    double right = 10;
    double middle;

    while(1)
    {
        middle = (left + right)/2;
        if(func1(middle)<0)
            left = middle;
        else if (func1(middle)>0)
            right = middle;
        else if(func1(middle)==0)
            break;
    }
    printf("该方程在1.5附近的根为%lf\n",middle);
    return 0;
}


/** 16. 输入以下图案：
                              *
                             ***
                            *****
                           *******
                            *****
                             ***
                              *
*/


int main()
{
    int i, j;
    for(i=1; i<=4; i++)
    {
        printf("\t");
        for(j=4-i; j>0; j--)
            printf(" ");

        for(j=1; j<=2*i-1; j++)
            printf("*");

        printf("\n");
    }

    for(i=1; i<=3; i++)
    {
        printf("\t");
        for(j=1; j<=i; j++)
            printf(" ");

        for(j=1; j<=7-2*i; j++)
            printf("*");

        printf("\n");
    }
    return 0;
}


// 17. 两个乒乓球进行比赛，各处3人。甲队为A,B,C三人，乙队为X,Y,Z三人。已抽签决定比赛名单。有人向队员打听比赛名单，A说他不和X比，C说他不和X,Z比，请编程找出3对赛手的名单。
// 思路：假设X，Y，Z分别收到了0,1,2号。遍历A，B，C对应0,1,2的所有情况，找出符合条件的

int main()
{

    int X=0, Y=1, Z=2;
    int A,B,C;
    for(A=0; A<3; A++)
        for(B=0; B<3; B++)
            for(C=0; C<3; C++)
                if(A!=B&&B!=C&&A!=C&&A!=X&&C!=X&&C!=Z)
                    printf("对阵情况为：\n A---%d     X---0  \n B---%d     Y---1 \n C---%d     Z---2\n",A,B,C);
    return 0;
}

