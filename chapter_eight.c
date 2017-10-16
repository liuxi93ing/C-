#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

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

        if(i>=1&&i<=3)  // 每个人报数，报1或2或3
        {
            if(i==3)
                count--; // 每有一个人报3，当前人数减1
             *p++ = i++;
        }
        if(i==4)
            i = 1;

        if(count==1)
            break;
    }
    for(p = head; p <= tail; p++)
    {
        if(*p!=3)           // 最后只剩一个人没报过3
            break;
    }

    return p-head+1;        // 返回他是第几号
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
    p = NULL;
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
    char original_str[10][20] = {{0}};                  // 二维数组初始化只用一层大括号会有warning
    char sorted_str[10][20] = {{0}};
    generate_str(*original_str,10,20);                 // 随机生成原字符串 也可以写成generate_str(original_str,10,20); 会有warning，类型不匹配
    printf("原字符串为：\n");
//  print_str_1(original_str, 10);                    // 参数类型不同的print函数，效果相同 建议使用下一个
    print_str_2(*original_str, 10, 20);

    sort_str(*original_str,*sorted_str,10,20);            // 很难对字符串数组真正sort，所以生成一个新的数组， 把原数组字符串按从小到大写入

    printf("\n排序后的字符串为：\n");
    print_str_2(*sorted_str,10,20);
    return 0;
}



// 12. 用指针数组处理上一题目，字符串不等长。

void sort_string(char *s[], int number)                 //冒泡排序
{
    char *temp;
    int i, j;
    for(i=0; i<number-1; i++)
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
double func1(double x)
{
    return sin(x);
}

double func2(double x)
{
    return cos(x);
}

double func3(double x)
{
    return exp(x);
}

double integral(double (*p)(double),double lower_bound, double upper_bound)
{
    double result = 0, i;
    double interval = (upper_bound-lower_bound)/10000;
    for(i = lower_bound; i<upper_bound; i=i+interval)
    {
        result += p(i)*interval;
    }
    return result;
}

int main()
{
    int type = 100;
    while(type!=-1)
    {
        printf("请输入想求定积分函数的序号(输入-1退出程序)：\n（1）sin(x)\n（2）cos(x)\n（3）e^x\n");
        scanf("%d",&type);
        switch(type)
        {
            case 1: printf("结果为%lf\n\n",integral(func1,0,1.0));break;
            case 2: printf("结果为%lf\n\n",integral(func2,0,1.0));break;
            case 3: printf("结果为%lf\n\n",integral(func3,0,1.0));break;
            case -1: return 0;
            default: printf("输入错误\n\n");break;
        }
    }
}

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
void print_array(int *p, int row, int col)
{
    int i, j;
    printf("学生成绩为：\n");
    for(i = 0; i<row; i++)
    {
        for(j = 0; j<col; j++)
            printf("%d ",*(p+i*col+j));
        printf("\n");
    }
}

void func_1(int *p, int row, int col)
{
    int i, j;
    double result = 0;
    for(i = 0; i<row; i++)
        result = result + *(p+i*col);

    result = result/(double)row;
    printf("第一门课的平均分为：%g\n",result);
}

void func_2(int *p, int row, int col)
{
    int i, j;
    int count, fail[4] = {0};
    for(i = 0; i<row; i++)
    {
        count = 0;
        for(j=0; j<col; j++)
            if(*(p+i*col+j)<60)
                count++;
        if(count>2)
            fail[i] = 1;
    }

    for(i=0; i<row; i++)
    {
        if(fail[i]==1)
        {
            printf("%d号学生，成绩为：",i+1);
            for(j=0; j<col; j++)
                printf("%d ", *(p+i*col+j));
            printf("\n");
        }
    }
}

void func_3(int *p, int row, int col)
{
    int i, j, sum;
    int flag[4] = {1};

    for(i = 0; i <row; i++)
    {
        sum = 0;
        for(j = 0; j<col; j++)
        {
            sum += *(p+i*col+j);
            if(*(p+i*col+j)<85)
                flag[i] = 0;
        }
        if(sum>=90*col)
            flag[i] = 1;
    }

    for(i=0; i<row; i++)
    {
        if(flag[i]==1)
        {
            printf("%d号学生，成绩为：",i+1);
            for(j=0; j<col; j++)
                printf("%d ", *(p+i*col+j));
            printf("\n");
        }
    }
}

int main()
{
    int grades[4][5] = {
    {56, 58, 70, 45, 67},
    {85, 87, 80, 99, 94},
    {93, 95, 96, 90, 86},
    {76, 73, 78, 87, 82}};

    int row = 4;
    int col = 5;
    print_array(grades, row, col);
    int type = 0;
    while(1)
    {
        printf("\n输入序号来进行操作(-1结束输入)：\n(1)求第一门课的平均分\n(2)找出两门课程不及格的学生\n(3)找出平均成绩90或全部成绩85分以上的学生\n");
        scanf("%d",&type);
        switch(type)
        {
            case 1:func_1(grades,row,col);break;
            case 2:func_2(grades,row,col);break;
            case 3:func_3(grades,row,col);break;
            case -1:return 0;
            default: printf("输入错误\n");break;
        }
    }
}

// 16. 输入一个字符串，内有数字和非数字字符，例如：A123*456 17960? 302tab5876
//     将其中连续的数字作为一个整数，依次存放在数组a中。例如123放在a[0],456放在a[1]...，统计一共有多少个整数，并输出这些整数。

int string_to_digit(char *s)
{
    int i, result = 0;
    int length = strlen(s);
    for(i = 0; i<length; i++)
        result += (s[length-1-i] - 48)*pow(10,i);
    return result;
}

int main()
{
    char str[] = {"A123*456 17960? 302tab5876"};
    char *p, *from, *to;
    char temp[20] = {0};
    int a[10] = {0};
    int length = strlen(str), count = 0;


    for(p = str; *p!='\0'; p++)                         // 思路为找到第一个数字，用内层循环把它及后面的数字遍历并完存在临时数组里，
    {                                                   // 把这个数组转化成数字值，把当前指针指向本组数字末尾
        if(isdigit(*p))
        {
            memset(temp, 0, 20);
            from = p;
            to = temp;
            while(isdigit(*from))
                *(to++) =*(from++);
            p = from;
            a[count++] = string_to_digit(temp);         // 假如有三个数，count从0开始记，第一次调用完++变成1，第二次调用完为2，第三次为3。
        }                                               // count 的数值是准的，不用额外加1
    }

    printf("共有%d个整数，分别为：", count);
    int i;
    for(i = 0; i<count; i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}


/* 17. 写一个函数，实现两个字符串比较。即自己实现strcmp函数，函数原型为 int strcmp(char *p1，char *p2)
        设p1指向字符串s1，p2指向字符串s2。要求当s1=s2时，返回值为0；若s1不等于s2，返回他们二者第1个不同字符的ASCII码差值（如“BOY”和“BAD”第2个字母不同，
        “O”与“A”之间差为 79-65=14）。如果s1>s2，这输出正值；如果s1<s2，则输出负值。
*/

int strcmp_x(char *p1, char *p2)
{
    int different = 0;
    int i = 0;
    while(different==0)
    {
        different = *(p1+i)-*(p2+i);
        i++;
    }
    return different;
}

int main()
{
    char str1[100] = {0};
    char str2[100] = {0};
    printf("输入第一个字符串：\n");
    gets(str1);
    printf("输入第二个字符串：\n");
    gets(str2);
    printf("两字符串比较结果为：%d\n",strcmp_x(str1,str2));
    return 0;
}

// 18. 编一程序，输入月份号，输出该月的英文月名。例如，输入"3"，则输出“March”，要求用指针数组处理。
int main()
{
    char month[12][20] = {
    {"January"},
    {"February"},
    {"March"},
    {"Apirl"},
    {"May"},
    {"June"},
    {"July"},
    {"August"},
    {"September"},
    {"Ocotober"},
    {"November"},
    {"December"}};
    char *s[12];
    int i, x;
    for(i = 0; i<12; i++)
        s[i] = month[i];

    printf("输入月份:\n");
    scanf("%d",&x);
    printf("输出月份为: %s\n", s[x-1]);
    return 0;
}
// 19. (1) 编写一个函数 new，对n个字符开辟连续的存储空间，此函数应返回一个指针(地址)，指向字符串开始的空间。new(n)表示分配n个字节的内存空间。
//     (2) 写一个函数free，将前面new函数占用的空间释放。free(p)表示将p(地址)指向的单元以后的内存释放。
/**此题答案来自官方参考答案*/
#define NEWSIZE 1000                    //指定开辟存区的最大容量
char newbuf[NEWSIZE];                   //定义字符数组newbuf
char *newp=newbuf;                      //定义指针变量newp，指向可存区的始端
char *new(int n)                        //定义开辟存区的函数new,开辟存储区后返回指针
{
    if (newp+n<=newbuf+NEWSIZE)         // 开辟区未超过newbuf数组的大小
    {
        newp+=n;                          // newp指向存储区的末尾
        return(newp-n);                  // 返回一个指针,它指向存区的开始位置
    }
    else
        return(NULL);                    // 当存区不够分配时,返回一个空指针
}


#define NEWSIZE 1000
char newbuf[NEWSIZE];
char *newp=newbuf;
void free(char *p)                             //释放存区函数
{
    if(p>=newbuf && p< newbuf + NEWSIZE)
        newp=p;
}
// 20. 用指向指针的指针的方法对5个字符串排序并输出。

/** 几乎等同于12题，只不过使用 **s 作为函数参数，而不是*s[], 两者实际等同*/

void sort_string(char **s, int number)                 //冒泡排序
{
    char *temp;
    int i, j;
    for(i=0; i<number; i++)
    {
        for(j=0; j<number-1-i; j++)
        {
            if(strcmp(s[j],s[j+1])>0)
            {
                temp = s[j];                            // s[j] 可以写成 *（s+j）
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

int main()
{
    char *p[5], **p1;
    char original_str[5][100] = {0};
    int i = 0;
    for(i=0;i<5;i++)                           // 定义10个字符指针指向10个字符串
        p[i] = original_str[i];

    printf("输入10个字符串:\n");
    for(i=0;i<5;i++)
        gets(p[i]);

    p1 = p;
    sort_string(p1, 5);                         // 传入p是一样的
                                                // 给指针排序，让第一个指向最小的....最后顺序输入指针
    printf("排序后的字符串为:\n");
    for(i=0;i<5;i++)
        puts(p[i]);

    return 0;
}
// 21. 用指向指针的指针的方法对n个整数排序并输出。要求将排序单独写成一个函数。n个整数在主函数中输入，最后在主函数中输出。
#define N 10

void int_sort(int **p)
{
    int *temp = NULL;
    int i = 0, j = 0;
    for(i=0; i<N-1; i++)
    {
        for(j=i; j<N-i-1; j++)
        {
            if(*(p+j)>*(p+j+1))
            {
                temp = *(p+j);
                *(p+j) = *(p+j+1);
                *(p+j+1) = temp;
            }
        }
    }
}

int main()
{
    int a[N] = {0};
    int *p[N] = {NULL}, **x =NULL;
    printf("输入n个整数(n为10)：\n");
    int i = 0;
    for(i = 0; i<N; i++)
        p[i] = &a[i];
    for(i = 0; i<N; i++)
        scanf("%d",p[i]);

    x = p;
    int_sort(x);
    printf("排序后的数组为：\n");           //把指针指向排了序，原数组没变。输出时按指针输出
    for(i = 0; i<N; i++)
        printf("%d ", *p[i]);
    return 0;
}
