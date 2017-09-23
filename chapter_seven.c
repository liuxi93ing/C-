#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// 1. д�����������ֱ����������������Լ������С�����������������������������������������������������ɼ������롣

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
    printf("��������������");
    scanf("%d%d",&num_1,&num_2);
    printf("���Լ���ǣ�%d����С�������ǣ�%d\n",greatest_common_factor(num_1,num_2),least_common_multiple(num_1,num_2));
    return 0;
}
// 2. �󷽳�ax^2+bx+c=0�ĸ��������������ֱ��󵱣�b^2-4ac����0������0��С��0ʱ�ĸ�������������������������a,b,c��ֵ��

void above_0 (double a, double b, double c)
{
    double x1 = (b*(-1) + sqrt(b*b - 4*a*c))/(2*a);
    double x2 = (b*(-1) - sqrt(b*b - 4*a*c))/(2*a);
    printf("����������ʵ���ֱ�Ϊ��%lf, %lf\n",x1, x2);
    return 0;
}

void equal_0 (double a, double b)
{
    double x = (-1)*b/(2*a);
    printf("������һ��ʵ��Ϊ��%lf\n", x);
}

void below_0 ( )
{
    printf("������ʵ��\n");
}

int main()
{
    double a, b, c;
    printf("������ϵ��a,b,c��ֵ��");
    scanf("%lf%lf%lf",&a,&b,&c);
    double delta = b*b - 4*a*c;
    if(delta > 0)
        above_0(a,b,c);
    else if(delta == 0)
        equal_0(a,b);
    else
        below_0();

}




// 3. дһ���ж������ĺ�����������������һ������������Ƿ�Ϊ��������Ϣ��

int if_prime (int num)
{
    int count = 0, i = 0;
    for(i = 1; i <= sqrt(num); i++)
        if(num%i==0)
            count++;

    if(i==1)
        printf("������");
    else
        printf("��������");

    return 0;
}

int main()
{
    int number;
    printf("����һ��������");
    scanf("%d",&number);
    if_prime(number);
    return 0;
}


// 4. дһ��������ʹ������һ��3��3�Ķ�ά��������ת�ã������л�����

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
    printf("��ʼ����Ϊ��\n");
    print_array(array, 3);
    transpose_array(array, 3);
    printf("ת�ú����Ϊ��\n");
    print_array(array, 3);
    return 0;
}

// 5. дһ��������ʹ�����һ���ַ����������ţ��������������������ַ�����

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
    printf("�������ַ�����");
    gets(str);
    length = strlen(str);
    printf("������ַ���Ϊ��%s\n", str_reverse(str,length-1));
    return 0;
}


// 6. дһ���������������ַ������ӡ�

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
    printf("�������һ���ַ�����\n");
    gets(str1);
    printf("������ڶ����ַ�����\n");
    gets(str2);
    printf("���Ӻ���Ϊ��\n%s\n",concatenate(str1,str2));

    return 0;
}

// 7. дһ����������һ���ַ����е�Ԫ����ĸ���Ƶ���һ���ַ�����Ȼ�������

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
    printf("�������ַ�����\n");
    gets(str1);

    printf("ɸѡ����Ϊ��\n%s\n",extract(str1,str2));

    return 0;
}


// 8. дһ������������һ��4λ����Ҫ�������4�������ַ�����ÿ�������ּ��һ���ո������롰1990����Ӧ�����1 9 9 0����
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

    printf("���Ϊ��\n%s\n", output);
}

int main()
{
    int num;
    printf("������һ����λ����");
    scanf("%d",&num);
    func(num);
    return 0;
}

// 9. ��дһ����������ʵ�δ���һ���ַ�����ͳ�ƴ��ַ�������ĸ�����֣��ո�������ַ��ĸ��������������������ַ����Լ�������������

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
    printf("�������ַ�����\n");
    gets(s);
    statistics(s);
    printf("ͳ�ƽ��Ϊ����ĸ%d��,����%d��,�ո�%d��,�����ַ�%d����\n",letter,number,space,other);
    return 0;
}


// 10. дһ������������һ���ַ��������ַ�������ĵ��������

//Ĭ��������ַ���Ϊ����Ӣ����д�淶�ľ��ӡ�
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

    printf("��󵥴�Ϊ: %s\n", word);
}

int main()
{
    char s[100] = {0};
    printf("�������ַ�����\n");
    gets(s);
    longest_word(s);
    return 0;
}


// 11. дһ���������á����ݷ����������10���ַ�����С�����˳�����С�


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
    printf("ԭ����Ϊ��");
    for(i = 0; i < 10; i++)
    {
        a[i] = rand()%100;
        printf("%-4d",a[i]);
    }
    printf("\n");

    bubble(a,10);
    printf("���������Ϊ��");

    for(i = 0; i < 10; i++)
    {
        printf("%-4d",a[i]);
    }
    printf("\n");
    return 0;
}

// 12. ��ţ�ٵ��������������ax^3+bx^2+cx+d=0��a,b,c,d��ϵ������Ϊ1��2��3��4�������������롣��x��1������һ��ʵ������������������������
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
    printf("��һ������a,b,c,d��ֵ��");
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    double x = 1.0;
    while(1)
    {
        if(fabs(func1(x)) < 0.0000001)           //�Ը�������С��Ϊ�ж�����ʱ����Ҫ����==0�� �жϾ���ֵ�Ƿ�С������0���������ȣ�
            break;
        x = x - func1(x)/func2(x);              //ţ�ٵ�����ʽ

    }

    printf("��1������ʵ��Ϊ��%lf\n",x);
    return 0;
}
// 13. �õݹ鷽����n�����õ¶���ʽ��ֵ���ݹ鹫ʽ�����ϣ���

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
    printf("����n��x��ֵ��");
    scanf("%d%lf",&n,&x);
    printf("���Ϊ��%lf\n",lrd(n,x));
    return 0;
}


/** 14. ����10��ѧ��5�ſεĳɼ����ֱ��ú���ʵ�����й��ܣ�
       1) ����ÿ��ѧ����ƽ���֣�
       2) ����ÿ�ſε�ƽ���֣�
       3) �ҳ�����50����������ߵķ�������Ӧ��ѧ���Ϳγ̣�
       4) ����ƽ���ַ��
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
        printf("%-4g \n",average[i] = sum/5.0);  //ʵ�ͳ��Ը������Զ���ɸ�����
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
    printf("������ߵĿγ���%d��ѧ���ĵ�%d�ſΣ�Ϊ%d��\n",stu, lec, max);
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

    printf("����Ϊ��%lf\n",result);
}

int main()
{
    srand((unsigned)time(0));
    int grades[10][5];
    int i, j, index;
    printf("10��ѧ���ķ����ֱ�Ϊ��\n");
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
        printf("����������������²�����\n1) ����ÿ��ѧ����ƽ���֣�\n2) ����ÿ�ſε�ƽ���֣�\n3) �ҳ�����50����������ߵķ�������Ӧ��ѧ���Ϳγ̣�\n4) ����ƽ���ַ��\n");
        scanf("%d",&index);
        switch(index)
        {
            case 1: stu_average(grades);break;
            case 2: class_average(grades);break;
            case 3: highest_grade(grades);break;
            case 4: variance(grades);break;
            default: printf("�������\n");break;
        }
    }
    return 0;

}

/** 15. д����������
       1) ����10��ְ����������ְ���ţ�
       2) ��ְ������С����˳����������˳��Ҳ��֮������
       3) Ҫ������һ��ְ���ţ����۰���ҷ��ҳ���ְ����������������������Ҫ���ҵ�ְ���ţ������ְ��������
*/
/*����δѧϰ�ṹ��֪ʶ������������*/
// 16. дһ������������һ��ʮ��λ�������������Ӧ��ʮ��������

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
        printf("������ʮ����������");
        scanf("%s",hex);
        length = strlen(hex);
        for(i = 0; i < length; i++)
            if(!(hex[i]>='0'&&hex[i]<='9'||hex[i]>='A'&&hex[i]<='F'))
                flag = 1;
        if(flag == 0)
            break;
        else
            printf("����������������\n");
    }

    printf("ת������ʮ������Ϊ��%lld\n", hex_to_dec(hex, length));
    return 0;
}

// 17. �õݹ鷨��һ������nת�����ַ��������磬����483��Ӧ����ַ�����483����n��λ����ȷ��������������λ����������
static char final_str[100];

void convert(long long int x)
{
    static int i = 0;
    long long int temp;

    temp = x%10;                            //�Ѹ�λ�����£���10Ĩ����λ������...ֱ����ʣ��λ���Ѹ�λд�������һ��Ԫ�أ�
//    printf("number is %d\n",temp);
    if(x/10>0)                              //�˳��������������ΰѱ��ε���֮ǰ��¼�µ�λ��д�������У�ÿ���˳�����i++��
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
    printf("����һ������:\n");
    scanf("%lld",&number);
    convert(number);
    printf("�ַ���Ϊ:%s\n",final_str);
    return 0;
}


// 18. �����ꡢ�¡��գ���������ǵڼ��졣

int main()
{
    int year = 0, month = 0, day = 0, result = 0;
    int yue[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    while(year<=0)
    {
       printf("������:");
       scanf("%d",&year);
    }
    while(month<1||month>12)
    {
       printf("������:");
       scanf("%d",&month);
    }
    while(day<1||day>31)
    {
       printf("������:");
       scanf("%d",&day);
    }

    if(year%4==0&&year%100!=0||year%400==0)
        yue[1] = 29;

    int i;
    for(i = 0; i < month-1; i++)
        result = result + yue[i];

    result = result + day;
    printf("��%d��\n",result);
    return 0;
}
