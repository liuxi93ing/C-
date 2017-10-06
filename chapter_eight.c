#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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

int * transposition(int *p, int n, int m)
{
    int *temp = (int*)malloc(sizeof(int)*1000);     // 开辟临时空间
    memset(temp,0,sizeof(int)*1000);
    int i = 0;

    int *cursor = p + n - m;                        // 把后段m个数拷贝到临时空间
    for(;i<m; i++)
        temp[i] = cursor[i];

    cursor = p + n - m -1;                          //把前段n-m个数像后挪m,从本段最后一个数开始一个一个挪
    for(i = 0; i< n-m; i++)
    {
         cursor[m] = cursor[0];
         cursor--;
    }

    cursor = p;                                     //再把临时空间中的m个数拷贝回来
    for(i = 0;i < m; i++)
        cursor[i] = temp[i];

    free(temp);
    return p;
}

int main()
{
    int array[1000], i, *p;
    p = array;
    srand((int)time(0));
    for(i =0; i<1000; i++)
        array[i] = rand()%100;

    int m, n;
    printf("输入n和m(n<1000,m<1000,m<n):");
    scanf("%d%d",&n,&m);

    printf("\n调整前数列为:\n");
    i = n;
    while(i--)
        printf("%d ", *p++);

    transposition(array, n, m);

    printf("\n调整后数列为:\n");
    i = n;
    p = array;
    while(i--)
        printf("%d ", *p++);

    return 0;
}



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

char *cut(char *str, int m)
{
    char *s_new = (char *)malloc(sizeof(char)*1000);        //堆里开辟的字符数组，函数调用结束后不会被回收，整个程序结束后被回收
    memset(s_new,0,sizeof(char)*1000);

    char *cursor_old = str + m - 1;
    char *cursor_new = s_new;
    while(*cursor_old!='\0')
        *cursor_new++=*cursor_old++;
    return s_new;
}
int main()
{
    char *s = (char *)malloc(sizeof(char)*1000);
    memset(s,0,sizeof(char)*1000);
    int m;

    printf("输入一个字符串(length<1000)：\n");
    gets(s);
    printf("输入m(m<1000)：");
    scanf("%d",&m);
    printf("新字符串为:\n");
    puts(cut(s,m));
    return 0;
}

// 8. 输入一行文字，找出其中大写字母，小写字母，空格，数字以及其他字符各有多少。

int main()
{
    char *s = (char*)malloc(sizeof(char)*1000);
    memset(s,0,sizeof(char)*1000);
    char *cursor = s;
    int upper = 0, lower = 0, space = 0, number = 0, others = 0;

    printf("请输入字符串：\n");
    gets(s);
    while(*cursor!='\0')
    {
        if(*cursor>='A'&&*cursor<='Z')
            upper++;
        else if(*cursor>='a'&&*cursor<='z')
            lower++;
        else if(*cursor>='0'&&*cursor<='9')
            number++;
        else if(*cursor==' ')
            space++;
        else
            others++;

        cursor++;
    }
    printf("大写字母%d个，小写字母%d个，空格%d个，数字%d个，其他字符%d个。\n",upper,lower,space,number,others);
    free(s);
    return 0;
}

// 9. 写一个函数，将一个3乘3的矩阵转置。

void transpose_array(int *s, int n)
{
    int i, j, temp;
    for(i = 0; i < n; i++)                  // 遍历一半的矩阵，将s[i][j]与s[j][i]交换
        for(j = i; j< n; j++)
        {
             temp = *(s+i*n+j);             // s[i][j] 用指针表示为 *（s+n*i+j) n为第二维的长度
             *(s+i*n+j) = *(s+j*n+i);
             *(s+j*n+i)=temp;
        }
}

int main()
{
    int arr[3][3];
    int *p = *arr, i =0;
    srand((int)time(0));

    printf("原矩阵为:\n");
    for(i=0;i<9;i++)
    {
        printf("%-4d", *(p+i)=rand()%99+1);
        if(i==2||i==5||i==8)
            printf("\n");
    }
    transpose_array(arr,3);
    printf("转置后的矩阵为:\n");
    for(i=0;i<9;i++)
    {
        printf("%-4d", *(p+i));
        if(i==2||i==5||i==8)
            printf("\n");
    }
    return 0;
}

// 10. 将一个5乘5的矩阵中最大的元素放在中心，4个角分别放4个最小的元素（顺序为从左到右，从上到下依次从大到小存放），写一个函数实现之。用main函数调用。

void swap_num(int *a, int m, int n)
{
    int temp;
    temp = *(a+n);
    *(a+n) = *(a+m);
    *(a+m) = temp;
}

void print_array(int *a, int x)
{
    int i;
    for(i = 0;i < x*x; i++)
    {
        printf("%-3d",*(a+i));
        if((i+1)%x==0)
            printf("\n");
    }
}

void generate_array(int *a, int x)
{
    srand((int)time(0));
    int i;
    for(i = 0; i< x*x; i++)
        *(a+i) = rand()%99;
}

void trans_array(int *a, int x)                             // 不能先把最大数和四个最小数先取到，再一起交换，会出现重复交换情况。应该每次去一个就换一个
{                                                           // 取最小数时要跳过前面已取到的更小的数。
    int max = *a, min1 , min2 , min3 , min4;
    int max_index = 0, min1_index, min2_index , min3_index , min4_index;
    int i;
    for(i = 0; i < x*x; i++)
    {
        if(*(a+i)>max)
        {
            max = *(a+i);
            max_index = i;
        }
    }
    swap_num(a, max_index, 12);

    min1 = max;
    min1_index = 12;
    for(i = 0; i < x*x; i++)
    {
        if(*(a+i)<min1)
        {
            min1 = *(a+i);
            min1_index = i;
        }
    }
    swap_num(a, min1_index, 24);

    min2 = max;
    min2_index = 12;
    for(i = 0; i < x*x; i++)
    {
        if(i == 24)
            continue;
        if(*(a+i)<min2)
        {
            min2 = *(a+i);
            min2_index = i;
        }
    }
    swap_num(a, min2_index, 20);

    min3 = max;
    min3_index = 12;
    for(i = 0; i < x*x; i++)
    {
        if(i == 24||i == 20)
            continue;
        if(*(a+i)<min3)
        {
            min3 = *(a+i);
            min3_index = i;
        }
    }
    swap_num(a, min3_index, 4);

    min4 = max;
    min4_index = 12;
    for(i = 0; i < x*x; i++)
    {
        if(i == 24||i == 20||i == 4)
            continue;
        if(*(a+i)<min4)
        {
            min4 = *(a+i);
            min4_index = i;
        }
    }
    swap_num(a, min4_index, 0);
}

int main()
{
    int a[5][5];
    generate_array(a, 5);
    printf("原数组为：\n");
    print_array(a, 5);
    trans_array(a, 5);
    printf("\n转变后原数组为：\n");
    print_array(a, 5);
    return 0;
}

// 11. 在主函数中输入10个等长的字符串。用另一个函数对他们排序。然后在主函数输出这10个排好的字符串。

void generate_str(char *str, int row, int col)      // 随机生成等长字符串, 范围是48-122 ， ‘0’到‘z’，包含特殊符号
{
    int i, j;
    srand((int)time(0));
    for(i = 0; i<row; i++)
    {
        for(j = 0; j<col-1; j++)
            *(str+i*col+j)=rand()%74+48;
        *(str+i*col+col-1) = '\0';
    }
}

void print_str_1(char (*str)[20], int row)            // 参数char (*str)[20] 也可以 写成 char str[][20], 两者等同，但列数20不能省
{                                                     // 此时str是指向一维数组的指针，
    int i;
    for(i = 0; i<row; i++)
        puts(str+i);                                  // str加1就代表指向下一个字符串
}

void print_str_2(char *str, int row, int col)
{
    int i;
    for(i = 0; i<row; i++)                             // 此时str指向单个字符，想指向下一个字符串就得加 i乘列数。
        puts(str+i*col);
}                                                      // 两个函数中str类型不同，但值相同，用puts输出都会输出第一个字符串


void sort_str(char *str_1, char *str_2, int row, int col)
{
        int i, j;
        char *min_str, *temp_min = str_2;

        j = row;
        while(j--)                                      // 双重循环，内层循环每次取出str_1中当前最小的字符串，外层把取到的最小字符串写入str_2中
        {
            min_str = "zzzzzzzzzzzzzzzz";
            for(i = 0; i<row; i++)
                if(strcmp(str_1+i*col,min_str)<0&&strcmp(temp_min,str_1+i*col)<0)       // 还保证当前次取到的最小字符串比已经写入到str_2中的都要大
                    min_str = str_1+i*col;

            strcpy(str_2, min_str);
            temp_min = str_2;
            str_2 = str_2 + col;
        }
}

int main()
{
    char original_str[10][20] = {0};
    char sorted_str[10][20] = {0};
    generate_str(*original_str,10,20);                 // 随机生成原字符串
    printf("原字符串为：\n");
//  print_str_1(equal_len,10);                          // 参数类型不同的print函数，效果相同
    print_str_2(*original_str, 10, 20);

    sort_str(original_str,sorted_str,10,20);            // 很难对字符串数组真正sort，所以生成一个新的数组， 把原数组字符串按从小到大写入

    printf("\n排序后的字符串为：\n");
    print_str_2(*sorted_str,10,20);
    return 0;
}


// 12. 用指针数组处理上一题目，字符串不等长。

void sort_string(char *s[], int number)                 //冒泡排序
{
    char *temp;
    int i, j;
    for(i=0; i<number; i++)
    {
        for(j=0; j<number-1-i; j++)
        {
            if(strcmp(s[j],s[j+1])>0)
            {
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

int main()
{
    char *p[10];
    char original_str[10][100] = {0};
    int i = 0;
    for(i=0;i<10;i++)                           // 定义10个字符指针指向10个字符串
        p[i] = original_str[i];

    printf("输入10个字符串:\n");
    for(i=0;i<10;i++)
        gets(p[i]);

    sort_string(p, 10);                         // 给指针排序，让第一个指向最小的....最后顺序输入指针

    printf("排序后的字符串为:\n");
    for(i=0;i<10;i++)
        puts(p[i]);

    return 0;
}

// 13. 写一个矩形法求定积分的通用函数，分别求sinx，cosx和e^x的定积分，积分区间为0到1。

// 14. 将n个数按输入时顺序的逆序排列，用函数实现。

void reverse_array(int *a, int n)
{
    int *head = a;
    int *tail = a + n - 1;
    int temp;

    while((tail-head)>=1)                       //数组数量为奇数偶数情况不同
    {
        temp = *head;
        *head = *tail;
        *tail = temp;

        head++;
        tail--;
    }
}

int main()
{
    int *s = (int*)malloc(sizeof(int)*100);
    memset(s, NULL, sizeof(int)*100);
    int *p = s;

    int n = 0;
    printf("输入整数n:");
    scanf("%d", &n);

    printf("输入n个整数:\n");
    int i = n;
    while(i--)
        scanf("%d", p++);

    reverse_array(s,n);

    i = 0;
    while(i<n)
    {
        printf("%d  ",*(s+i));
        i++;
    }
    printf("\n");
    free(s);
    return 0;
}
// 15. 有一个班4个学生，5门课程。(1)求第一门课程的平均分；(2)找出有两门以上课程不及格的学生，输出他们的学号和全部课程成绩及平均成绩；
//     (3)找出平均成绩在90分以上或全部课程成绩在85分以上的学生。分别编写3个函数实现以上3个要求。




// 16. 输入一个字符串，内有数字和非数字字符，例如：A123*456 17960? 302tab5876
//     将其中连续的数字作为一个整数，依次存放在数组a中。例如123放在a[0],456放在a[1]...，统计一共有多少个整数，并输出这些整数。

/** 17. 写一个函数，实现两个字符串比较。即自己实现strcmp函数，函数原型为 int strcmp(char *p1，char *p2)
        设p1指向字符串s1，p2指向字符串s2。要求当s1=s2时，返回值为0；若s1不等于s2，返回他们二者第1个不同字符的ASCII码差值（如“BOY”和“BAD”第2个字母不同，
        “O”与“A”之间差为 79-65=14）。如果s1>s2，这输出正值；如果s1<s2，则输出负值。
*/

// 18. 编一程序，输入月份号，输出该月的英文月名。例如，输入"3"，则输出“March”，要求用指针数组处理。

// 19. (1) 编写一个函数 new，对n个字符开辟连续的存储空间，此函数应返回一个指针(地址)，指向字符串开始的空间。new(n)表示分配n个字节的内存空间。
//     (2) 写一个函数free，将前面new函数占用的空间释放。free(p)表示将p(地址)指向的单元以后的内存释放。

// 20. 用指向指针的指针的方法对5个字符串排序并输出。

// 21. 用指向指针的指针的方法对n个整数排序并输出。要求将排序单独写成一个函数。n个整数在主函数中输入，最后在主函数中输出。
