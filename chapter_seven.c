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

// 11. дһ���������á����ݷ����������10���ַ�����С�����˳�����С�


// 12. ��ţ�ٵ��������������ax^3+bx^2+cx+d=0��a,b,c,d��ϵ������Ϊ1��2��3��4�������������롣��x��1������һ��ʵ������������������������

// 13. �õݹ鷽����n�����õ¶���ʽ��ֵ���ݹ鹫ʽ�����ϣ���

// 14. ����10��ѧ��5�ſεĳɼ����ֱ��ú���ʵ�����й��ܣ�
/**    1) ����ÿ��ѧ����ƽ���֣�
       2) ����ÿ�ſε�ƽ���֣�
       3) �ҳ�����50����������ߵķ�������Ӧ��ѧ���Ϳγ̣�
       4) ����ƽ���ַ��
*/

// 15. д����������
/**    1) ����10��ְ����������ְ���ţ�
       2) ��ְ������С����˳����������˳��Ҳ��֮������
       3) Ҫ������һ��ְ���ţ����۰���ҷ��ҳ���ְ����������������������Ҫ���ҵ�ְ���ţ������ְ��������
*/

// 16. дһ������������һ��ʮ��λ�������������Ӧ��ʮ��������

// 17. �õݹ鷨��һ������nת�����ַ��������磬����483��Ӧ����ַ�����483����n��λ����ȷ��������������λ����������

// 18. �����ꡢ�¡��գ���������ǵڼ��졣
