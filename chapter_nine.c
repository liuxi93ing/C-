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
// 5. 有10个学生，每个学生的数据包括学号、姓名、3门课程的成绩，从键盘输入10个学生的数据，要求输出3门课程总平均成绩，以及最高分的学生的数据（包括学号、姓名、3门课成绩，平均分数）。
/**理解为输出总成绩最高的学生数据*/

#define NUM 5
struct Stu{
    int num;
    char name[20];
    int score[3];
};

void input(struct Stu *s, int number)
{
    int i,j;
    for(i=0; i<number; i++)
    {
        printf("输入第%d个学生的个人信息:\n",i+1);
        printf("学号：");
        scanf("%d",&(s+i)->num);
        printf("姓名：");
        scanf("%10s",(s+i)->name);
        printf("成绩：\n");
        for(j=0; j<3; j++)
        {
            printf("第%d科：", j+1);
            scanf("%d",&(s+i)->score[j]);
        }
    }
}

void print(struct Stu *s, int number)
{
    int i,j;
    printf("\n学号------姓名------第一科  第二科  第三科\n");
    for(i=0; i<number; i++)
    {
        printf("%-10d",(s+i)->num);
        printf("%-10s",(s+i)->name);
        for(j=0; j<3; j++)
           printf("%-8d",(s+i)->score[j]);
        printf("\n");
    }
}

void select(struct Stu *s, int number)
{
    int i, highest;
    double average1 = 0,average2 = 0, average3 = 0, sum = 0, temp = 0;
    for(i=0; i<number; i++)
    {
        average1 += (s+i)->score[0];
        average2 += (s+i)->score[1];
        average3 += (s+i)->score[2];
    }
    average1 = average1/number;
    average2 = average2/number;
    average3 = average3/number;
    printf("\n三门课的平均成绩为：%-8.2lf %-8.2lf %-8.2lf\n",average1,average2,average3);
    for(i = 0; i<number; i++)
    {
        temp = (s+i)->score[0]+(s+i)->score[1]+(s+i)->score[2];
        if(temp>sum)
        {
            sum = temp;
            highest = i;
        }
    }
    printf("\n成绩最高的学生是：\n");
    print(s+highest,1);
}

int main()
{
    struct Stu student[NUM];
    input(student, NUM);
    print(student, NUM);
    select(student,NUM);
    return 0;
}

// 6. 13个人围成一圈，从第1个人开始顺序报数1，2，3。凡报到3者退出圈子。找出最后留在圈子中的人原来的序号。要求用链表实现。

#define SIZE sizeof(struct node)
struct node{
    int num;
    struct node *next;
};

int generate_chain(struct node *head, int number)
{
    struct node *cursor = head;                 // cursor指向当前节点
    struct node *build = NULL;                  // build来建立新节点
    int i;
    head->num = 1;
    head->next = NULL;                          // 给头结点赋值
    for(i = 1; i<number; i++)
    {
        if(NULL==(build = (struct node *)malloc(SIZE)))
        {
            printf("memory allocation fail\n");
            return 1;
        }
        cursor->next = build;                   // 每新建一个节点，要保证上一个节点连过来，初始化数据，新节点指向空
        cursor = build;
        cursor->num = i+1;
        cursor->next = NULL;
    }
    cursor->next = head;                        // 本体需收尾相连形成环
    return 0;
}

struct node *number_off(struct node *head)
{
    int count = 1;                              // 初始化head结点报1，第一次循环是从head的下一个结点开始
    struct node *cursor = head;
    struct node *previous = NULL;
    while(++count)                              // 每次循环开始 count先++作为本次要报的数。cursor移到下一个结点，即本次循环要报数的结点
    {
        previous = cursor;
        cursor = cursor->next;
        if(count==3)                           // 如果本机循环报3， 则删除该结点，cursor退回上一个结点，count归0。
        {
            previous->next = cursor->next;
            free(cursor);
            cursor = previous;
            count = 0;
        }
        if(cursor->next==cursor)                // 如果 cursor->指向自己，说明只剩一个结点了，退出
            break;
    }
    return cursor;

}

int main()
{
    struct node *head = (struct node *)malloc(SIZE);
    if(head==NULL)
    {
        printf("memory allocation fail\n");
        return 1;
    }
    struct node *remain = NULL;
    generate_chain(head, 13);
    remain = number_off(head);
    printf("剩下的人原来是%d号\n",remain->num);
    return 0;
}


// 7. 在第9张例9.9和例9.10的基础上，写一个del函数，用来删除动态链表中指定结点。
// 8. 写一个函数insert，用来想一个动态链表插入结点。
// 9. 综合本章例9.9（建立链表的函数create）、例9.10（输出链表的函数print）和本章习题第7题、本章习题第8题，再编写一个主函数，先后调用这些函数。
//    用以上5个函数组成一个程序，实现链表的建立、输出、删除和插入，在主函数中指定需要删除和插入的结点的数据。

#define SIZE sizeof(struct Student)
struct Student{
    int number;
    int score;
    struct Student *next;
};

struct Student *create_s()
{
     struct Student *head;
     struct Student *cursor, *build;
     int n = 0;

     while(++n)                                                      // 先++n使n变为1， 再判断while循环条件
     {
        if(NULL == (build = (struct Student *)malloc(SIZE)))         // 判断是否分配内存成功
        {
            printf("memory allocation fail\n");
            return NULL;
        }
        if(n==1)                                                    // 如果是第一个结点，head指向它，如果不是，前一个结点连入它
            head = build;
        else
            cursor->next = build;

        cursor = build;                                             // 当前光标指针指向新节点

        printf("输入学生的学号(输入0来结束输入):");                 // 为新结点赋值
        scanf("%d",&cursor->number);
        printf("输入学生的成绩:");
        scanf("%d",&cursor->score);
        cursor->next = NULL;                                        // 新结点指向空

        if(cursor->number==0)                                       // 判断退出条件， 也就是说链表最后一个结点存储的是空数据，属于收尾结点
            break;
     }
     return head;
}

void print_s(struct Student *head)
{
    struct Student *cursor = head;
    while(cursor->next!=NULL)
    {
        printf("学号: %-6d 成绩: %-4d\n", cursor->number, cursor->score);
        cursor = cursor->next;
    }
}

struct Student *insert_s(struct Student *head, int n_number, int n_score)      // 假设学号是有序排列的
{
     struct Student *prev = head;
     struct Student *cursor = head;
     struct Student *build = NULL;
     struct Student *new_head = head;

     while(cursor->number<=n_number&&cursor->number!=0)             // 遍历，使cursor指向比新学号高的结点，prev指向cursor的前一结点
     {
             prev = cursor;
             cursor = cursor->next;
     }

     if(NULL == (build = (struct Student *)malloc(SIZE)))           // 创建新结点，插入到cursor之间
     {
         printf("memory allocation fail\n");
         return NULL;
     }
     build->number = n_number;
     build->score = n_score;
     build->next = cursor;

     if(head->number<=n_number)                                     // 如果在head后面插入，prev指向新节点
        prev->next = build;
     else                                                           // 如果插入在head之前， 新节点成为head；
        new_head = build;

    return new_head;
}

struct Student *delete_s(struct Student *head, int d_number)
{
     struct Student *prev = head;
     struct Student *cursor = head;
     struct Student *new_head = head;

     if(head->number==d_number)                                     // 单独处理删除头结点的情况
     {
         new_head = head->next;
         free(cursor);
         return new_head;
     }

     while(cursor->number!=d_number&&cursor->number!=0)             // 遍历寻找要删除的结点
     {
         prev = cursor;
         cursor = cursor->next;
     }
     if(cursor->number==0)                                          // 未找到情况
     {
         printf("未找到要删除的学号\n");
         return new_head;
     }

     prev->next = cursor->next;
     free(cursor);

     return new_head;
}

int main()
{
    struct Student *head= NULL;
    head = create_s();

    int menu = 0;
    int n_number, n_score;
    int d_number;
    while(1)
    {
        printf("\n输入序号进行的操作:\n(1).打印当前记录。\n(2).插入新记录。\n(3).删除已有记录。\n(4).退出\n");
        scanf("%d",&menu);
        switch(menu)
        {
            case 1: print_s(head);break;
            case 2:
                {
                    printf("请输入新记录的学号:");                         // 插入和删除属于写操作，可能会影响head，所以需要返回新head
                    scanf("%d",&n_number);
                    printf("请输入新记录中的成绩:");
                    scanf("%d",&n_score);
                    head = insert_s(head, n_number, n_score);
                    break;
                }
            case 3:
                {
                    printf("请输入要删除的记录的学号:");
                    scanf("%d",&d_number);
                    head = delete_s(head,d_number);
                    break;
                }
            case 4: return 0;
            default: printf("输入错误\n");
        }
    }
}

// 10. 已有a，b两个链表，每个链表中的结点包括学号、成绩。要求把两个链表合并，按学号升序排列。

/** 由题目得知a，b均为静态链表，默认链表排序为通过移动结点位置而不是交换结点中数据。
    思路为先把两个链表连起来，使用选择排序法，每次选出最小的结点，连成一个新表*/

#define SIZE sizeof(struct Student)
struct Student{
    int number;
    int score;
    struct Student *next;
};

struct Student *concatenate_sort(struct Student *head_1, struct Student *head_2)
{
    struct Student *new_head, *cursor, *prev, *min_stu_prev, *min_stu, *ordered=NULL;
    int min_number;

    cursor = head_1;                                //遍历到第一个链表末尾，接上第二个链表的头
    while(cursor->next!=NULL)
        cursor = cursor->next;
    cursor->next = head_2;

    while(head_1!=NULL)                        // 思路是建立一个新的链表ordered，内层循环每次遍历原链表找出数值最小的
    {                                          // 结点，从原链表删除该结点，连入ordered链表中
        min_stu = head_1;                      // 需分情况判断删除结点是否为head，以及新加入结点为ordered中第一个结点的情况
        min_stu_prev = head_1;
        min_number = head_1->number;            // 当原表中结点为0时，即head指向NULL，循环结束
        for(cursor = head_1; cursor!=NULL; cursor = cursor->next)
        {
            if(cursor->number<min_number)
            {
                min_stu = cursor;               // 为了记录并删除最小数值结点，需记录该结点与该结点前一结点
                min_stu_prev = prev;
                min_number = cursor->number;
            }
            prev = cursor;
        }

        if(min_stu==head_1)
            head_1 = head_1->next;
        else
            min_stu_prev->next = min_stu->next;

        if(ordered==NULL)                       // 当第一个结点加入ordered中，order指向它，同时这也是新的头结点（new_head）
        {
            ordered = min_stu;
            new_head = ordered;
            ordered->next = NULL;
        }
        else
        {
            ordered->next = min_stu;            // 不是第一个时，连入order->next
            ordered = ordered->next;
            ordered->next = NULL;
        }
    }
    return new_head;
}

void print_s(struct Student *head)
{
    struct Student *cursor = head;
    while(cursor!=NULL)                         //  上一题链表中有收尾结点，因此最后一个结点不输出。本题输出所以结点
    {                                           //  因此循环结束条件不同
        printf("学号: %-6d 成绩: %-4d\n", cursor->number, cursor->score);
        cursor = cursor->next;
    }
}

int main()
{
    struct Student *head_1, *head_2,*head_3;
    struct Student a,b,c,d,e,f,g,h;

    head_1 = &a;
    a.number = 1014; a.score = 97; a.next = &b;
    b.number = 1007; b.score = 85; b.next = &c;
    c.number = 1028; c.score = 100; c.next = &d;
    d.number = 1013; d.score = 79; d.next = NULL;
    head_2 = &e;
    e.number = 1011; e.score = 77; e.next = &f;
    f.number = 1039; f.score = 99; f.next = &g;
    g.number = 1001; g.score = 93; g.next = &h;
    h.number = 1022; h.score = 69; h.next = NULL;

    printf("链表1为:\n");
    print_s(head_1);
    printf("链表2为:\n");
    print_s(head_2);
    head_3 = concatenate_sort(head_1,head_2);
    printf("排序后的链表为:\n");
    print_s(head_3);
    return 0;
}


// 11. 有两个链表a和b，设结点中包含学号、姓名。从a链表中删出与b链表中有相同学号的那些结点。
/**默认为静态链表，思路是外层循环遍历b表每个结点，内层循环遍历a表每个结点，有相同删除a中结点*/


// 12. 建立一个链表，每个结点包含学号、姓名、性别、年龄。输入一个年龄，如果链表中的结点所包含的年龄等于此年龄，则将此结点删去。
