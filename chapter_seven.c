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

// 9. 编写一个函数，由实参传来一个字符串，统计次字符串中字母，数字，空格和其他字符的个数，在主函数中输入字符串以及输出上述结果。

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

//默认输入的字符串为符合英文书写规范的句子。
void longest_word(char sentence[])
{
    int i, j, length = 0;
    char temp[20] = {0};
    char word[20] = {0};
    for(i = 0, j = 0; i < strlen(sentence)+1; i++)
    {
        if(sentence[i]>='a'&&sentence[i]<='z'||sentence[i]>='A'&&sentence[i]<='Z'||sentence[i]=='-')
        {
            temp[j] = sentence[i];
            j++;
        }

        else
        {
            if(j> length)
            {
                length = j;
                strcpy(word, temp);
            }
            j = 0;
        }
    }

    printf("最大单词为: %s\n", word);
}

int main()
{
    char s[100] = {0};
    printf("请输入字符串：\n");
    gets(s);
    longest_word(s);
    return 0;
}


// 11. 写一个函数，用“气泡法”对输入的10个字符按有小到大的顺序排列。


int bubble(int a[], int count)
{
    int i, j, temp;
    for(i = 0; i < count; i++)
    {
        for(j = 0; j < count - i; j ++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main()
{
    int a[10];
    int i;
    srand((int)time(0));
    printf("原数组为：");
    for(i = 0; i < 10; i++)
    {
        a[i] = rand()%100;
        printf("%-4d",a[i]);
    }
    printf("\n");

    bubble(a,10);
    printf("排序后数组为：");

    for(i = 0; i < 10; i++)
    {
        printf("%-4d",a[i]);
    }
    printf("\n");
    return 0;
}

// 12. 用牛顿迭代法求根。方程ax^3+bx^2+cx+d=0中a,b,c,d的系数依次为1，2，3，4，由主函数输入。求x在1附近的一个实根。求出根后由主函数输出。
double a, b, c, d;

double func1(double x)
{
    return a*x*x*x+b*x*x+c*x+d;
}

double func2(double x)
{
    return 3*a*x*x+2*b*x+c;
}

int main()
{
    printf("请一次输入a,b,c,d的值：");
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    double x = 1.0;
    while(1)
    {
        if(fabs(func1(x)) < 0.0000001)           //以浮点数大小作为判定条件时，不要是用==0， 判断绝对值是否小于趋近0的数（精度）
            break;
        x = x - func1(x)/func2(x);              //牛顿迭代公式

    }

    printf("在1附近的实根为：%lf\n",x);
    return 0;
}
// 13. 用递归方法求n阶勒让德多项式的值（递归公式见书上）。

double lrd (int n, double x)
{
    if(n==0)
        return 1;
    else if(n==1)
        return x;
    else if(n>1)
        return ((2*n-1)*x-lrd(n-1,x)-(n-1)*lrd(n-2,x))/n;
}

int main()
{
    int n;
    double x;
    printf("输入n和x的值：");
    scanf("%d%lf",&n,&x);
    printf("结果为：%lf\n",lrd(n,x));
    return 0;
}


/** 14. 输入10个学生5门课的成绩，分别用函数实现下列功能：
       1) 计算每个学生的平均分；
       2) 计算每门课的平均分；
       3) 找出所有50个分数中最高的分数所对应的学生和课程；
       4) 计算平均分方差。
*/

void stu_average(int grades[][5])
{
    int i, j;
    int sum;
    double average[10];
    for(i = 0; i < 10; i++)
    {
        sum = 0;
        for(j = 0; j < 5; j++)
        {
            sum = sum + grades[i][j];
        }
        printf("%-4g \n",average[i] = sum/5.0);  //实型除以浮点型自动变成浮点型
    }
}

void class_average(int grades[][5])
{
    int i, j;
    int sum;
    double average[5];
    for(j = 0; j < 5; j++)
    {
        sum = 0;
        for(i = 0; i < 10; i++)
        {
            sum =  sum + grades[i][j];
        }
        printf("%g  ",sum/10.0);
    }
    printf("\n");
}

void highest_grade(int grades[][5])
{
    int i, j, stu, lec, max = 0;
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(grades[i][j]>max)
            {
                max = grades[i][j];
                stu = i+1;
                lec = j+1;
            }
        }
    }
    printf("分数最高的课程是%d号学生的第%d门课，为%d分\n",stu, lec, max);
}


void variance(int grades[][5])
{
    int i, j;
    double average[10],sum = 0, sum_a = 0, average_a = 0, result = 0;
    for(i = 0; i < 10; i++)
    {
        sum = 0;
        for(j = 0; j < 5; j++)
        {
            sum = sum + grades[i][j];
        }
        average[i] = sum/5.0;
        sum_a = sum_a + average[i];
    }
    average_a = sum_a/10;

    for(i = 0; i < 10; i ++)
    {
        result = result + (average[i]-average_a)*(average[i]-average_a);
    }
    result = result / 10;

    printf("方差为：%lf\n",result);
}

int main()
{
    srand((unsigned)time(0));
    int grades[10][5];
    int i, j, index;
    printf("10名学生的分数分别为：\n");
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 5; j ++)
        {
            printf("%-4d",grades[i][j] = (rand()+20)%100);
        }
        printf("\n");

    }

    while(1)
    {
        printf("输入序号来进行如下操作：\n1) 计算每个学生的平均分；\n2) 计算每门课的平均分；\n3) 找出所有50个分数中最高的分数所对应的学生和课程；\n4) 计算平均分方差。\n");
        scanf("%d",&index);
        switch(index)
        {
            case 1: stu_average(grades);break;
            case 2: class_average(grades);break;
            case 3: highest_grade(grades);break;
            case 4: variance(grades);break;
            default: printf("输入错误\n");break;
        }
    }
    return 0;

}

/** 15. 写几个函数：
       1) 输入10个职工的姓名和职工号；
       2) 按职工号有小到大顺序排序，姓名顺序也随之调整；
       3) 要求输入一个职工号，用折半查找法找出该职工的姓名，从主函数输入要查找的职工号，输出该职工姓名。
*/
/*鉴于未学习结构体知识，暂跳过此题*/
// 16. 写一个函数，输入一个十六位进制数，输出相应的十进制数。

long long int hex_to_dec(char hex[], int count)
{
    int i, j;
    long long int result = 0;
    for(i = 0; i < count; i++)
    {
        if(hex[i]>='0'&&hex[i]<='9')
            hex[i] = hex[i] - 48;
        else if(hex[i]>='A'&&hex[i]<='F')
            hex[i] = hex[i] - 55;
    }

    for(i = count-1, j = 0; i >= 0; i --)
    {
        result = result + hex[i]*pow(16,j);
        j++;
    }
    return result;
}

int main()
{
    char hex[20];
    int length, i, flag;
    while(1)
    {
        flag = 0;
        printf("请输入十六进制数：");
        scanf("%s",hex);
        length = strlen(hex);
        for(i = 0; i < length; i++)
            if(!(hex[i]>='0'&&hex[i]<='9'||hex[i]>='A'&&hex[i]<='F'))
                flag = 1;
        if(flag == 0)
            break;
        else
            printf("输入错误，请从新输入\n");
    }

    printf("转化出的十进制数为：%lld\n", hex_to_dec(hex, length));
    return 0;
}

// 17. 用递归法将一个整数n转化成字符串。例如，输入483，应输出字符串“483”。n的位数不确定，可以是任意位数的整数。
static char final_str[100];

void convert(long long int x)
{
    static int i = 0;
    long long int temp;

    temp = x%10;                            //把个位数记下，除10抹掉个位，迭代...直到仅剩首位，把该位写入数组第一个元素，
//    printf("number is %d\n",temp);
    if(x/10>0)                              //退出迭代过程中依次把本次迭代之前记录下的位数写入数组中，每次退出迭代i++。
    {
        x = x/10;
        convert(x);
    }
    final_str[i] = temp+48;
    i++;
//    printf("f[i] is %c, i is %d\n", final_str[i], i);
}

int main()
{
    long long int number;
    memset(final_str,0,100);
    printf("输入一个整数:\n");
    scanf("%lld",&number);
    convert(number);
    printf("字符串为:%s\n",final_str);
    return 0;
}


// 18. 给出年、月、日，计算该日是第几天。

int main()
{
    int year = 0, month = 0, day = 0, result = 0;
    int yue[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    while(year<=0)
    {
       printf("输入年:");
       scanf("%d",&year);
    }
    while(month<1||month>12)
    {
       printf("输入月:");
       scanf("%d",&month);
    }
    while(day<1||day>31)
    {
       printf("输入日:");
       scanf("%d",&day);
    }

    if(year%4==0&&year%100!=0||year%400==0)
        yue[1] = 29;

    int i;
    for(i = 0; i < month-1; i++)
        result = result + yue[i];

    result = result + day;
    printf("第%d日\n",result);
    return 0;
}
