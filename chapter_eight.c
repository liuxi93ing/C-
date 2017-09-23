#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//本章习题要求用指针方法处理
// 1. 输入3个整数，按由小到大的顺序输出。

void switch_by_3_int(int *a, int *b, int *c)
{
    if(*a > *b)
        switch_by_2(a,b);
    if(*a > *c)
        switch_by_2(a,c);
    if(*b > *c)
        switch_by_2(b,c);
}

void switch_by_2(int *a, int *b)
{
    int temp;
    if(a > b)
    {
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main()
{
    int *a, *b, *c, num1, num2, num3;
    a = &num1;
    b = &num2;
    c = &num3;
    printf("输入三个整数：");
    scanf("%d%d%d",a,b,c);
    switch_by_3_int(a,b,c);
    printf("有小到大为:%d  %d  %d\n",num1, num2,num3);
    return 0;
}
// 2. 输入三个字符串，按由小到大的顺序输出。

void switch_by_3(int *a, int *b, int *c)
{
    if(strcmp(a,b)>0)
        switch_by_2(a,b);
    if(strcmp(a,c)>0)
        switch_by_2(a,c);
    if(strcmp(b,c)>0)
        switch_by_2(b,c);
}

void switch_by_2(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}

int main()
{
    char *a, *b, *c, str1[100], str2[100], str3[100];
    a = str1;
    b = str2;
    c = str3;
    printf("输入第一个字符串：");
    scanf("%s",a);
    getchar();
    printf("输入第二个字符串：");
    scanf("%s",b);
    getchar();
    printf("输入第三个字符串：");
    scanf("%s",c);
    getchar();
    switch_by_3(a,b,c);
    printf("由小到大为:\n%s\n%s\n%s\n",a,b,c);
    return 0;
}


// 3. 输入10个整数，将其中最小的数与第一个数对换，把最大的数与最后一个数对换。写3个函数：（1）输入10个整数；（2）进行处理；（3）输出10个数。

void input_integers(int *p, int count)
{
    printf("输入10个整数，以空格分隔：");
    while(count--)
        scanf("%d",p++);
}

void output_integers(int *p, int count)
{
    printf("十个整数分别为：");
    while(count--)
        printf("%d ",*p++);
}

void process_integers(int *p, int count)
{
    int *head, *tail, *max, *min, temp;
    head = p;
    tail = p+count-1;
    max = min = p;
    while(count--)
    {
        if(*p>*max)
            max = p;
        if(*p<*min)
            min = p;
        p++;
    }

    temp = *head;
    *head = *min;
    *min = *head;

    temp = *tail;
    *tail = *max;
    *max = temp;
}

int main()
{
    int array[10];
    input_integers(array,10);
    process_integers(array,10);
    output_integers(array,10);
    return 0;
}
// 4. 有n个整数，使前面各数顺序向后移m个位置，最后m个数变成最前面m个数，见图8.43。写一个函数实现以上功能，在主函数输入n个整数和输出调整后的n个数。


// 5. 有n个人围成一圈，顺序排号。从第一个人开始报数（从1到3报数），凡报到3的人退出圈子，问最后留下的是原来几号的那位。

int functin(int *p, int number)
{
    int *head = p, *tail = p + number - 1; // 如有10个人参加，tail指向第10个人，head指向第1个，他们之间差值为10-1
    int *temp = head, i = 1, count = number;
    while(1)            // 每次循环表示一个人报一个数，记录下来；已经报过3的跳过；p指向当前报数的人，i表示当前的数；
    {                   // 结尾报完后回到从头接着报; 每有一个人报了三之后，总人数减一，剩一人时跳出循环。找出剩下的没报3的那个
        if(*p == 3)     // p-head表示他们之前隔了几个人，head指向第一个人，p-head为2，p指向3个人，所以返回p-head+1
        {
            p++;
            continue;   //!!!一次循环中指针p只能变动一次，要么正常报，要么跳过3，要么尾到头!!!
        }

        if(p-1==tail)
        {
            p = head;
            continue;   //!!如果一次循环向后推移多个会出错!!
        }

        if(i>=1&&i<=3)
        {
            if(i==3)
                count--;
             *p++ = i++;
        }
        if(i==4)
            i = 1;

        if(count==1)
            break;
    }
    for(p = head; p <= tail; p++)
    {
        if(*p!=3)
            break;
    }

    return p-head+1;
}

int main()
{
    int array[1000] = {0};
    int n;
    printf("输入人数n(小于1000)：");
    scanf("%d",&n);
    printf("剩下的人是最初的%d号\n",functin(array,n));
    return 0;
}

// 6. 写一个函数，求一个字符串的长度。在main函数中输入字符串，并输出其长度。
int string_len(char *s)
{
    int length = 0;
    while(*s++!='\0')
        length++;
    return length;
}

int main()
{
    char *p = (char*)malloc(sizeof(char)*100);
    memset(p,0,sizeof(char)*100);
    printf("输入一个字符串：");
    scanf("%s",p);
    printf("字符串长度为：%d",string_len(p));
    free(p);
    return 0;
}

// 7. 有一个字符串，包含n个字符。写一个函数，将此字符串中从第m个字符开始的全部字符复制成另一个字符串。

// 8. 输入一行文字，找出其中大写字母，小写字母，空格，数字以及其他字符各有多少。

// 9. 写一个函数，将一个3乘3的矩阵转置。

// 10. 将一个5乘5的矩阵中最大的元素放在中心，4个角分别放4个最小的元素（顺序为从左到右，从上到下依次从大到小存放），写一个函数实现之。用main函数调用。

// 11. 在主函数中输入10个等长的字符串。用另一个函数对他们排序。然后在主函数输出这10个排好的字符串。

// 12. 用指针数组处理上一题目，字符串不等长。

// 13. 写一个矩形法求定积分的通用函数，分别求sinx，cosx和e^x的定积分，积分区间为0到1。

// 14. 将n个数按输入时顺序的逆序排列，用函数实现。

// 15. 有一个班4个学生，5门课程。(1)求第一门课程的平均分；(2)找出有两门以上课程不及格的学生，输出他们的学号和全部课程成绩及平均成绩；
//     (3)找出平均成绩在90分以上或全部课程成绩在85分以上的学生。分别编写3个函数实现以上3个要求。

// 16. 输入一个字符串，内有数字和非数字字符，例如：A123*456 17960? 302tab5876
//     将其中连续的数字作为一个整数，一次存放在数组a中。例如123放在a[0],456放在a[1]...，统计一共有多少个整数，并输出这些整数。

/** 17. 写一个函数，实现两个字符串比较。即自己实现strcmp函数，函数原型为 int strcmp(char *p1，char *p2)
        设p1指向字符串s1，p2指向字符串s2。要求当s1=s2时，返回值为0；若s1不等于s2，返回他们二者第1个不同字符的ASCII码差值（如“BOY”和“BAD”第2个字母不同，
        “O”与“A”之间差为 79-65=14）。如果s1>s2，这输出正值；如果s1<s2，则输出负值。
*/

// 18. 编一程序，输入月份号，输出该月的英文月名。例如，输入"3"，则输出“March”，要求用指针数组处理。

// 19. (1) 编写一个函数 new，对n个字符开辟连续的存储空间，此函数应返回一个指针(地址)，指向字符串开始的空间。new(n)表示分配n个字节的内存空间。
//     (2) 写一个函数free，将前面new函数占用的空间释放。free(p)表示将p(地址)指向的单元以后的内存释放。

// 20. 用指向指针的指针的方法对5个字符串排序并输出。

// 21. 用指向指针的指针的方法对n个整数排序并输出。要求将排序单独写成一个函数。n个整数在主函数中输入，最后在主函数中输出。
