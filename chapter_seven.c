#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// 1. 写两个函数，分别求两个整数的最大公约数和最小公倍数数，用主函数调用这两个函数，并输出结果。两个整数由键盘输入。

int greatest_common_factor(int num_1, int num_2)
{
    int i;
    int result = 1;
    int min = num_1 < num_2?num_1:num_2;
    for(i = 1; i <= min; i++)
    {
        if(num_1%i==0&&num_2%i==0)
            result = i;
    }
    return result;
}

int least_common_multiple(int num_1, int num_2)
{
    int i;
    int max = num_1*num_2;
    int result = max;
    for(i = max; i >= num_1; i--)
    {
        if(i%num_1==0&&i%num_2==0)
            result = i;
    }
    return result;
}

int main()
{
    int num_1, num_2;
    printf("输入两个整数：");
    scanf("%d%d",&num_1,&num_2);
    printf("最大公约数是：%d，最小公倍数是：%d\n",greatest_common_factor(num_1,num_2),least_common_multiple(num_1,num_2));
    return 0;
}
// 2. 求方程ax^2+bx+c=0的根，用三个函数分别求当：b^2-4ac大于0、等于0和小于0时的根并输出结果。从主函数中输入a,b,c的值。

void above_0 (double a, double b, double c)
{
    double x1 = (b*(-1) + sqrt(b*b - 4*a*c))/(2*a);
    double x2 = (b*(-1) - sqrt(b*b - 4*a*c))/(2*a);
    printf("方程有两个实根分别为：%lf, %lf\n",x1, x2);
    return 0;
}

void equal_0 (double a, double b)
{
    double x = (-1)*b/(2*a);
    printf("方程有一个实根为：%lf\n", x);
}

void below_0 ( )
{
    printf("方程无实根\n");
}

int main()
{
    double a, b, c;
    printf("请输入系数a,b,c的值：");
    scanf("%lf%lf%lf",&a,&b,&c);
    double delta = b*b - 4*a*c;
    if(delta > 0)
        above_0(a,b,c);
    else if(delta == 0)
        equal_0(a,b);
    else
        below_0();

}

// 3. 写一个判断素数的函数，在主函数输入一个整数，输出是否为素数的信息。

int if_prime (int num)
{
    int count = 0, i = 0;
    for(i = 1; i <= sqrt(num); i++)
        if(num%i==0)
            count++;

    if(i==1)
        printf("是素数");
    else
        printf("不是素数");

    return 0;
}

int main()
{
    int number;
    printf("输入一个正整数");
    scanf("%d",&number);
    if_prime(number);
    return 0;
}


// 4. 写一个函数，使给定的一个3乘3的二维整形数组转置，即行列互换。

void transpose_array(int a[][3], int size)
{
    int i, j, temp;
    for(i = 0; i < size; i++)
    {
        for(j = i; j <size; j++)
        {
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
}

void print_array(int a[][3], int size)
{
    int i, j;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

}
int main()
{
    int array[3][3] = {1,2,3,4,5,6,7,8,9};
    printf("初始矩阵为：\n");
    print_array(array, 3);
    transpose_array(array, 3);
    printf("转置后矩阵为：\n");
    print_array(array, 3);
    return 0;
}

// 5. 写一个函数，使输入的一个字符串按反序存放，在主函数中输入和输出字符串。

char* str_reverse(char s[], int count)
{
    int i;
    char temp;
    for(i = 0; i <= count/2; i++)
    {
        temp = s[i];
        s[i] = s[count-i];
        s[count-i] = temp;
    }
    return s;
}

int main()
{
    char str[100];
    int length;
    printf("请输入字符串：");
    gets(str);
    length = strlen(str);
    printf("反序的字符串为：%s\n", str_reverse(str,length-1));
    return 0;
}


// 6. 写一个函数，将两个字符串连接。

char* concatenate(char A[], char B[])
{
    int len_A = strlen(A);
    int len_B = strlen(B);
    int i;
    for(i = 0; i<len_B; i++)
        A[len_A+i] = B[i];

    return A;
}

int main()
{
    char str1[1000];
    char str2[200];
    printf("请输入第一个字符串：\n");
    gets(str1);
    printf("请输入第二个字符串：\n");
    gets(str2);
    printf("连接后结果为：\n%s\n",concatenate(str1,str2));

    return 0;
}

// 7. 写一个函数，将一个字符串中的元音字母复制到另一个字符串，然后输出。

char* extract(char A[], char B[])
{
    int len_A = strlen(A);
    int i, j;
    for(i = 0, j = 0; i<len_A; i++)
        if(A[i]=='a'||A[i]=='A'||A[i]=='e'||A[i]=='E'||A[i]=='i'||A[i]=='I'||A[i]=='o'||A[i]=='O'||A[i]=='u'||A[i]=='U')
            B[j++] = A[i];

    return B;
}

int main()
{
    char str1[100] = {0};
    char str2[100] = {0};
    printf("请输入字符串：\n");
    gets(str1);

    printf("筛选后结果为：\n%s\n",extract(str1,str2));

    return 0;
}


// 8. 写一个函数，输入一个4位数，要求输出这4个数字字符，但每两个数字间空一个空格。如输入“1990”，应输出“1 9 9 0”。
void func(int number)
{
    char digit[4] = {0};
    digit[0] = number/1000+48;
    digit[1] = (number%1000)/100+48;
    digit[2] = (number%100)/10+48;
    digit[3] = (number%10)/1+48;

    char output[8] = {0};
    int i = 0, j = 0;
    for(i = 0; i< 7; i++)
    {
        if(i%2==1)
            output[i] = ' ';
        else
            output[i] = digit[j++];
    }

    printf("输出为：\n%s\n", output);
}

int main()
{
    int num;
    printf("请输入一个四位数：");
    scanf("%d",&num);
    func(num);
    return 0;
}

// 9. 编写一个函数，有实参传来一个字符串，统计次字符串中字母，数字，空格和其他字符的个数，在主函数中输入字符串以及输出上述结果。

int letter = 0, number = 0, space = 0, other = 0;

void statistics (char string[])
{
    int i = 0;
    int length = strlen(string);
    for(i=0;i<length;i++)
    {
        if(string[i]==' ')
            space++;
        else if(string[i]>='a'&&string[i]<='z'||string[i]>='A'&&string[i]<='Z')
            letter++;
        else if(string[i]>='0'&&string[i]<='9')
            number++;
        else
            other++;
    }
}

int main()
{
    char s[100] = {0};
    printf("请输入字符串：\n");
    gets(s);
    statistics(s);
    printf("统计结果为：字母%d个,数字%d个,空格%d个,其他字符%d个。\n",letter,number,space,other);
    return 0;
}


// 10. 写一个函数，输入一行字符，将此字符串中最长的单词输出。

// 11. 写一个函数，用“气泡法”对输入的10个字符按有小到大的顺序排列。


// 12. 用牛顿迭代法求根。方程ax^3+bx^2+cx+d=0中a,b,c,d的系数依次为1，2，3，4，由主函数输入。求x在1附近的一个实根。求出根后由主函数输出。

// 13. 用递归方法求n阶勒让德多项式的值（递归公式见书上）。

// 14. 输入10个学生5门课的成绩，分别用函数实现下列功能：
/**    1) 计算每个学生的平均分；
       2) 计算每门课的平均分；
       3) 找出所有50各分数中最高的分数所对应的学生和课程；
       4) 计算平均分方差。
*/

// 15. 写几个函数：
/**    1) 输入10个职工的姓名和职工号；
       2) 按职工号有小到大顺序排序，姓名顺序也随之调整；
       3) 要求输入一个职工号，用折半查找法找出该职工的姓名，从主函数输入要查找的职工号，输出该职工姓名。
*/

// 16. 写一个函数，输入一个十六位进制数，输出相应的十进制数。

// 17. 用递归法讲一个整数n转化成字符串。例如，输入483，应输出字符串“483”。n的位数不确定，可以是任意位数的整数。

// 18. 给出年、月、日，计算该日是第几天。
