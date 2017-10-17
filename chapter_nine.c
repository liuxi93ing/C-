#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

// 本章多道题目有上下联系，为避免冗余，把这些有联系的题目一起实现

// 1. 定义一个结构体变量（包括年、月、日）。计算该日在本年中是第几天，主要闰年问题。
// 2. 写一个函数days，实现第1题的计算。由由主函数将年、月、日传递给days函数，计算后将日子传回主函数输出。

struct Day{
    int year;
    int month;
    int day;
};

int days(int year,int month,int day)
{
    int leap = 0;
    if(year%4==0&&year%100!=0||year%400==0)
        leap = 1;
    int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(leap==1)
        months[1] = 29;

    int i = 0, date = 0;
    while(i<month-1)
        date += months[i++];
    date = date + day;
    return date;
}

int main()
{
    struct Day today = {0,0,0};
    while(today.year<=0)
    {
       printf("输入年份：\n");
       scanf("%d",&today.year);
    }
    while(today.month<=0||today.month>12)
    {
       printf("输入月份：\n");
       scanf("%d",&today.month);
    }

    while(today.day<=0||today.day>366)
    {
       printf("输入日：\n");
       scanf("%d",&today.day);
    }

    printf("这天是那年的第%d天\n",days(today.year,today.month,today.day));
    return 0;
}

// 3. 编写一个print，打印一个学生的成绩数组，该数组中有5个学生的数据记录，每个记录包括num，name，score[3]，用主函数输入这些记录，用print函数输出这些记录。
// 4. 在第3题的基础上，编写一个函数input，用来输入这些记录，用print函数输出这些记录。
struct Stu{
    int num;
    char name[20];
    int score[3];
};

void input(struct Stu *s)
{

}

void print(struct Stu *s)
{

}

int main()
{
    struct Stu student[5];
    input()
}


// 5. 有10个学生，每个学生的数据包括学号、姓名、3门课程的成绩，从键盘输入10个学生的数据，要求输出3门课程总平均成绩，以及最高分的学生的数据（包括学号、姓名、3门课成绩，平均分数）。

// 6. 13个人围成一圈，从第1个人开始顺序报数1，2，3。凡报到3者退出圈子。找出最后留在圈子中的人原来的序号。要求用链表实现。

// 7. 在第9张例9.9和例9.10的基础上，写一个del函数，用来删除动态链表中指定结点。

// 8. 写一个函数insert，用来想一个动态链表插入结点。

// 9. 综合本章例9.9（建立链表的函数create）、例9.10（输出链表的函数print）和本章习题第7题、本章习题第8题，再编写一个主函数，先后调用这些函数。
//    用以上5个函数组成一个程序，实现链表的建立、输出、删除和插入，在主函数中指定需要删除和插入的结点的数据。

// 10. 已有a，b两个链表，每个链表中的结点包括学号、成绩。要求把两个链表合并，按学号升序排列。

// 11. 有两个链表a和b，设结点中包含学号、姓名。从a链表中删出于b链表中有相同学号的那些结点。

// 12. 建立一个链表，每个结点包含学号、姓名、性别、年龄。输入一个年龄，如果链表中的结点所包含的年龄等于此年龄，则将此结点删去。
