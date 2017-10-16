#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

//����ϰ��Ҫ����ָ�뷽������
// 1. ����3������������С�����˳�������

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
    printf("��������������");
    scanf("%d%d%d",a,b,c);
    switch_by_3_int(a,b,c);
    printf("��С����Ϊ:%d  %d  %d\n",num1, num2,num3);
    return 0;
}
// 2. ���������ַ���������С�����˳�������

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
    printf("�����һ���ַ�����");
    scanf("%s",a);
    getchar();
    printf("����ڶ����ַ�����");
    scanf("%s",b);
    getchar();
    printf("����������ַ�����");
    scanf("%s",c);
    getchar();
    switch_by_3(a,b,c);
    printf("��С����Ϊ:\n%s\n%s\n%s\n",a,b,c);
    return 0;
}


// 3. ����10����������������С�������һ�����Ի����������������һ�����Ի���д3����������1������10����������2�����д�����3�����10������

void input_integers(int *p, int count)
{
    printf("����10���������Կո�ָ���");
    while(count--)
        scanf("%d",p++);
}

void output_integers(int *p, int count)
{
    printf("ʮ�������ֱ�Ϊ��");
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
// 4. ��n��������ʹǰ�����˳�������m��λ�ã����m���������ǰ��m��������ͼ8.43��дһ������ʵ�����Ϲ��ܣ�������������n������������������n������

int * transposition(int *p, int n, int m)
{
    int *temp = (int*)malloc(sizeof(int)*1000);     // ������ʱ�ռ�
    memset(temp,0,sizeof(int)*1000);
    int i = 0;

    int *cursor = p + n - m;                        // �Ѻ��m������������ʱ�ռ�
    for(;i<m; i++)
        temp[i] = cursor[i];

    cursor = p + n - m -1;                          //��ǰ��n-m�������Ųm,�ӱ������һ������ʼһ��һ��Ų
    for(i = 0; i< n-m; i++)
    {
         cursor[m] = cursor[0];
         cursor--;
    }

    cursor = p;                                     //�ٰ���ʱ�ռ��е�m������������
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
    printf("����n��m(n<1000,m<1000,m<n):");
    scanf("%d%d",&n,&m);

    printf("\n����ǰ����Ϊ:\n");
    i = n;
    while(i--)
        printf("%d ", *p++);

    transposition(array, n, m);

    printf("\n����������Ϊ:\n");
    i = n;
    p = array;
    while(i--)
        printf("%d ", *p++);

    return 0;
}



// 5. ��n����Χ��һȦ��˳���źš��ӵ�һ���˿�ʼ��������1��3��������������3�����˳�Ȧ�ӣ���������µ���ԭ�����ŵ���λ��

int functin(int *p, int number)
{
    int *head = p, *tail = p + number - 1; // ����10���˲μӣ�tailָ���10���ˣ�headָ���1��������֮���ֵΪ10-1
    int *temp = head, i = 1, count = number;
    while(1)            // ÿ��ѭ����ʾһ���˱�һ��������¼�������Ѿ�����3��������pָ��ǰ�������ˣ�i��ʾ��ǰ������
    {                   // ��β�����ص���ͷ���ű�; ÿ��һ���˱�����֮����������һ��ʣһ��ʱ����ѭ�����ҳ�ʣ�µ�û��3���Ǹ�
        if(*p == 3)     // p-head��ʾ����֮ǰ���˼����ˣ�headָ���һ���ˣ�p-headΪ2��pָ��3���ˣ����Է���p-head+1
        {
            p++;
            continue;   //!!!һ��ѭ����ָ��pֻ�ܱ䶯һ�Σ�Ҫô��������Ҫô����3��Ҫôβ��ͷ!!!
        }

        if(p-1==tail)
        {
            p = head;
            continue;   //!!���һ��ѭ��������ƶ�������!!
        }

        if(i>=1&&i<=3)  // ÿ���˱�������1��2��3
        {
            if(i==3)
                count--; // ÿ��һ���˱�3����ǰ������1
             *p++ = i++;
        }
        if(i==4)
            i = 1;

        if(count==1)
            break;
    }
    for(p = head; p <= tail; p++)
    {
        if(*p!=3)           // ���ֻʣһ����û����3
            break;
    }

    return p-head+1;        // �������ǵڼ���
}

int main()
{
    int array[1000] = {0};
    int n;
    printf("��������n(С��1000)��");
    scanf("%d",&n);
    printf("ʣ�µ����������%d��\n",functin(array,n));
    return 0;
}

// 6. дһ����������һ���ַ����ĳ��ȡ���main�����������ַ�����������䳤�ȡ�
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
    printf("����һ���ַ�����");
    scanf("%s",p);
    printf("�ַ�������Ϊ��%d",string_len(p));
    free(p);
    p = NULL;
    return 0;
}

// 7. ��һ���ַ���������n���ַ���дһ�������������ַ����дӵ�m���ַ���ʼ��ȫ���ַ����Ƴ���һ���ַ�����

char *cut(char *str, int m)
{
    char *s_new = (char *)malloc(sizeof(char)*1000);        //���￪�ٵ��ַ����飬�������ý����󲻻ᱻ���գ�������������󱻻���
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

    printf("����һ���ַ���(length<1000)��\n");
    gets(s);
    printf("����m(m<1000)��");
    scanf("%d",&m);
    printf("���ַ���Ϊ:\n");
    puts(cut(s,m));
    return 0;
}

// 8. ����һ�����֣��ҳ����д�д��ĸ��Сд��ĸ���ո������Լ������ַ����ж��١�

int main()
{
    char *s = (char*)malloc(sizeof(char)*1000);
    memset(s,0,sizeof(char)*1000);
    char *cursor = s;
    int upper = 0, lower = 0, space = 0, number = 0, others = 0;

    printf("�������ַ�����\n");
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
    printf("��д��ĸ%d����Сд��ĸ%d�����ո�%d��������%d���������ַ�%d����\n",upper,lower,space,number,others);
    free(s);
    return 0;
}

// 9. дһ����������һ��3��3�ľ���ת�á�

void transpose_array(int *s, int n)
{
    int i, j, temp;
    for(i = 0; i < n; i++)                  // ����һ��ľ��󣬽�s[i][j]��s[j][i]����
        for(j = i; j< n; j++)
        {
             temp = *(s+i*n+j);             // s[i][j] ��ָ���ʾΪ *��s+n*i+j) nΪ�ڶ�ά�ĳ���
             *(s+i*n+j) = *(s+j*n+i);
             *(s+j*n+i)=temp;
        }
}

int main()
{
    int arr[3][3];
    int *p = *arr, i =0;
    srand((int)time(0));

    printf("ԭ����Ϊ:\n");
    for(i=0;i<9;i++)
    {
        printf("%-4d", *(p+i)=rand()%99+1);
        if(i==2||i==5||i==8)
            printf("\n");
    }
    transpose_array(arr,3);
    printf("ת�ú�ľ���Ϊ:\n");
    for(i=0;i<9;i++)
    {
        printf("%-4d", *(p+i));
        if(i==2||i==5||i==8)
            printf("\n");
    }
    return 0;
}

// 10. ��һ��5��5�ľ���������Ԫ�ط������ģ�4���Ƿֱ��4����С��Ԫ�أ�˳��Ϊ�����ң����ϵ������δӴ�С��ţ���дһ������ʵ��֮����main�������á�

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

void trans_array(int *a, int x)                             // �����Ȱ���������ĸ���С����ȡ������һ�𽻻���������ظ����������Ӧ��ÿ��ȥһ���ͻ�һ��
{                                                           // ȡ��С��ʱҪ����ǰ����ȡ���ĸ�С������
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
    printf("ԭ����Ϊ��\n");
    print_array(a, 5);
    trans_array(a, 5);
    printf("\nת���ԭ����Ϊ��\n");
    print_array(a, 5);
    return 0;
}

// 11. ��������������10���ȳ����ַ���������һ����������������Ȼ���������������10���źõ��ַ�����

void generate_str(char *str, int row, int col)      // ������ɵȳ��ַ���, ��Χ��48-122 �� ��0������z���������������
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

void print_str_1(char (*str)[20], int row)            // ����char (*str)[20] Ҳ���� д�� char str[][20], ���ߵ�ͬ��������20����ʡ
{                                                     // ��ʱstr��ָ��һά�����ָ�룬
    int i;
    for(i = 0; i<row; i++)
        puts(str+i);                                  // str��1�ʹ���ָ����һ���ַ���
}

void print_str_2(char *str, int row, int col)
{
    int i;
    for(i = 0; i<row; i++)                             // ��ʱstrָ�򵥸��ַ�����ָ����һ���ַ����͵ü� i��������
        puts(str+i*col);
}                                                      // ����������str���Ͳ�ͬ����ֵ��ͬ����puts������������һ���ַ���


void sort_str(char *str_1, char *str_2, int row, int col)
{
        int i, j;
        char *min_str, *temp_min = str_2;

        j = row;
        while(j--)                                      // ˫��ѭ�����ڲ�ѭ��ÿ��ȡ��str_1�е�ǰ��С���ַ���������ȡ������С�ַ���д��str_2��
        {
            min_str = "zzzzzzzzzzzzzzzz";
            for(i = 0; i<row; i++)
                if(strcmp(str_1+i*col,min_str)<0&&strcmp(temp_min,str_1+i*col)<0)       // ����֤��ǰ��ȡ������С�ַ������Ѿ�д�뵽str_2�еĶ�Ҫ��
                    min_str = str_1+i*col;

            strcpy(str_2, min_str);
            temp_min = str_2;
            str_2 = str_2 + col;
        }
}

int main()
{
    char original_str[10][20] = {{0}};                  // ��ά�����ʼ��ֻ��һ������Ż���warning
    char sorted_str[10][20] = {{0}};
    generate_str(*original_str,10,20);                 // �������ԭ�ַ��� Ҳ����д��generate_str(original_str,10,20); ����warning�����Ͳ�ƥ��
    printf("ԭ�ַ���Ϊ��\n");
//  print_str_1(original_str, 10);                    // �������Ͳ�ͬ��print������Ч����ͬ ����ʹ����һ��
    print_str_2(*original_str, 10, 20);

    sort_str(*original_str,*sorted_str,10,20);            // ���Ѷ��ַ�����������sort����������һ���µ����飬 ��ԭ�����ַ�������С����д��

    printf("\n�������ַ���Ϊ��\n");
    print_str_2(*sorted_str,10,20);
    return 0;
}



// 12. ��ָ�����鴦����һ��Ŀ���ַ������ȳ���

void sort_string(char *s[], int number)                 //ð������
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
    for(i=0;i<10;i++)                           // ����10���ַ�ָ��ָ��10���ַ���
        p[i] = original_str[i];

    printf("����10���ַ���:\n");
    for(i=0;i<10;i++)
        gets(p[i]);

    sort_string(p, 10);                         // ��ָ�������õ�һ��ָ����С��....���˳������ָ��

    printf("�������ַ���Ϊ:\n");
    for(i=0;i<10;i++)
        puts(p[i]);

    return 0;
}

// 13. дһ�����η��󶨻��ֵ�ͨ�ú������ֱ���sinx��cosx��e^x�Ķ����֣���������Ϊ0��1��
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
        printf("���������󶨻��ֺ��������(����-1�˳�����)��\n��1��sin(x)\n��2��cos(x)\n��3��e^x\n");
        scanf("%d",&type);
        switch(type)
        {
            case 1: printf("���Ϊ%lf\n\n",integral(func1,0,1.0));break;
            case 2: printf("���Ϊ%lf\n\n",integral(func2,0,1.0));break;
            case 3: printf("���Ϊ%lf\n\n",integral(func3,0,1.0));break;
            case -1: return 0;
            default: printf("�������\n\n");break;
        }
    }
}

// 14. ��n����������ʱ˳����������У��ú���ʵ�֡�

void reverse_array(int *a, int n)
{
    int *head = a;
    int *tail = a + n - 1;
    int temp;

    while((tail-head)>=1)                       //��������Ϊ����ż�������ͬ
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
    printf("��������n:");
    scanf("%d", &n);

    printf("����n������:\n");
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
// 15. ��һ����4��ѧ����5�ſγ̡�(1)���һ�ſγ̵�ƽ���֣�(2)�ҳ����������Ͽγ̲������ѧ����������ǵ�ѧ�ź�ȫ���γ̳ɼ���ƽ���ɼ���
//     (3)�ҳ�ƽ���ɼ���90�����ϻ�ȫ���γ̳ɼ���85�����ϵ�ѧ�����ֱ��д3������ʵ������3��Ҫ��
void print_array(int *p, int row, int col)
{
    int i, j;
    printf("ѧ���ɼ�Ϊ��\n");
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
    printf("��һ�ſε�ƽ����Ϊ��%g\n",result);
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
            printf("%d��ѧ�����ɼ�Ϊ��",i+1);
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
            printf("%d��ѧ�����ɼ�Ϊ��",i+1);
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
        printf("\n������������в���(-1��������)��\n(1)���һ�ſε�ƽ����\n(2)�ҳ����ſγ̲������ѧ��\n(3)�ҳ�ƽ���ɼ�90��ȫ���ɼ�85�����ϵ�ѧ��\n");
        scanf("%d",&type);
        switch(type)
        {
            case 1:func_1(grades,row,col);break;
            case 2:func_2(grades,row,col);break;
            case 3:func_3(grades,row,col);break;
            case -1:return 0;
            default: printf("�������\n");break;
        }
    }
}

// 16. ����һ���ַ������������ֺͷ������ַ������磺A123*456 17960? 302tab5876
//     ������������������Ϊһ�����������δ��������a�С�����123����a[0],456����a[1]...��ͳ��һ���ж��ٸ��������������Щ������

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


    for(p = str; *p!='\0'; p++)                         // ˼·Ϊ�ҵ���һ�����֣����ڲ�ѭ����������������ֱ������������ʱ�����
    {                                                   // ���������ת��������ֵ���ѵ�ǰָ��ָ��������ĩβ
        if(isdigit(*p))
        {
            memset(temp, 0, 20);
            from = p;
            to = temp;
            while(isdigit(*from))
                *(to++) =*(from++);
            p = from;
            a[count++] = string_to_digit(temp);         // ��������������count��0��ʼ�ǣ���һ�ε�����++���1���ڶ��ε�����Ϊ2��������Ϊ3��
        }                                               // count ����ֵ��׼�ģ����ö����1
    }

    printf("����%d���������ֱ�Ϊ��", count);
    int i;
    for(i = 0; i<count; i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}


/* 17. дһ��������ʵ�������ַ����Ƚϡ����Լ�ʵ��strcmp����������ԭ��Ϊ int strcmp(char *p1��char *p2)
        ��p1ָ���ַ���s1��p2ָ���ַ���s2��Ҫ��s1=s2ʱ������ֵΪ0����s1������s2���������Ƕ��ߵ�1����ͬ�ַ���ASCII���ֵ���硰BOY���͡�BAD����2����ĸ��ͬ��
        ��O���롰A��֮���Ϊ 79-65=14�������s1>s2���������ֵ�����s1<s2���������ֵ��
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
    printf("�����һ���ַ�����\n");
    gets(str1);
    printf("����ڶ����ַ�����\n");
    gets(str2);
    printf("���ַ����ȽϽ��Ϊ��%d\n",strcmp_x(str1,str2));
    return 0;
}

// 18. ��һ���������·ݺţ�������µ�Ӣ�����������磬����"3"���������March����Ҫ����ָ�����鴦��
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

    printf("�����·�:\n");
    scanf("%d",&x);
    printf("����·�Ϊ: %s\n", s[x-1]);
    return 0;
}
// 19. (1) ��дһ������ new����n���ַ����������Ĵ洢�ռ䣬�˺���Ӧ����һ��ָ��(��ַ)��ָ���ַ�����ʼ�Ŀռ䡣new(n)��ʾ����n���ֽڵ��ڴ�ռ䡣
//     (2) дһ������free����ǰ��new����ռ�õĿռ��ͷš�free(p)��ʾ��p(��ַ)ָ��ĵ�Ԫ�Ժ���ڴ��ͷš�
/**��������Թٷ��ο���*/
#define NEWSIZE 1000                    //ָ�����ٴ������������
char newbuf[NEWSIZE];                   //�����ַ�����newbuf
char *newp=newbuf;                      //����ָ�����newp��ָ��ɴ�����ʼ��
char *new(int n)                        //���忪�ٴ����ĺ���new,���ٴ洢���󷵻�ָ��
{
    if (newp+n<=newbuf+NEWSIZE)         // ������δ����newbuf����Ĵ�С
    {
        newp+=n;                          // newpָ��洢����ĩβ
        return(newp-n);                  // ����һ��ָ��,��ָ������Ŀ�ʼλ��
    }
    else
        return(NULL);                    // ��������������ʱ,����һ����ָ��
}


#define NEWSIZE 1000
char newbuf[NEWSIZE];
char *newp=newbuf;
void free(char *p)                             //�ͷŴ�������
{
    if(p>=newbuf && p< newbuf + NEWSIZE)
        newp=p;
}
// 20. ��ָ��ָ���ָ��ķ�����5���ַ������������

/** ������ͬ��12�⣬ֻ����ʹ�� **s ��Ϊ����������������*s[], ����ʵ�ʵ�ͬ*/

void sort_string(char **s, int number)                 //ð������
{
    char *temp;
    int i, j;
    for(i=0; i<number; i++)
    {
        for(j=0; j<number-1-i; j++)
        {
            if(strcmp(s[j],s[j+1])>0)
            {
                temp = s[j];                            // s[j] ����д�� *��s+j��
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
    for(i=0;i<5;i++)                           // ����10���ַ�ָ��ָ��10���ַ���
        p[i] = original_str[i];

    printf("����10���ַ���:\n");
    for(i=0;i<5;i++)
        gets(p[i]);

    p1 = p;
    sort_string(p1, 5);                         // ����p��һ����
                                                // ��ָ�������õ�һ��ָ����С��....���˳������ָ��
    printf("�������ַ���Ϊ:\n");
    for(i=0;i<5;i++)
        puts(p[i]);

    return 0;
}
// 21. ��ָ��ָ���ָ��ķ�����n���������������Ҫ�����򵥶�д��һ��������n�������������������룬������������������
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
    printf("����n������(nΪ10)��\n");
    int i = 0;
    for(i = 0; i<N; i++)
        p[i] = &a[i];
    for(i = 0; i<N; i++)
        scanf("%d",p[i]);

    x = p;
    int_sort(x);
    printf("����������Ϊ��\n");           //��ָ��ָ��������ԭ����û�䡣���ʱ��ָ�����
    for(i = 0; i<N; i++)
        printf("%d ", *p[i]);
    return 0;
}
