#include<stdio.h>
#include<stdlib.h>
#include<math.h>


// 3. ��������������m��n���������Լ������С��������

int main()
{
    int m, n;
    printf("input two integers��");
    scanf("%d%d",&m,&n);

    int i;
    int greatest_common_factor = 1;
    int least_common_muliple = 1;
    int min = n<m?n:m;

    for(i=1;i<=min;i++)
    {
        if(i==1)
            continue;
        if(m%i==0 && n%i==0)
            greatest_common_factor = i;
    }
    least_common_muliple = m*n/greatest_common_factor;

    printf("���Լ����:%d, ��С��������:%d\n",greatest_common_factor,least_common_muliple);
    return 0;

}

// 4. ����һ���ַ����ֱ�ͳ�Ƴ����е�Ӣ����ĸ���ո�������ַ��ĸ�����

int main()
{
    char a;
    int count1 = 0,count2 = 0,count3 = 0;

    while((a=getchar())!='\n')
    {
        if(a>='a'&&a<='z'||a>='A'&&a<='Z')
            count1++;
        else if(a==' ')
            count2++;
        else
            count3++;
    }
    printf("Ӣ����ĸ��%d�����ո���%d���������ַ���%d��\n",count1,count2,count3);
    return 0;
}


// 5. ��Sn=a+aa+aaa+.....+aaaaaa(n��a)��ֵ������a��һ�����֣�n��ʾa��λ����a��n�ɼ������롣


int main()
{
    int a, n;
    int addend = 0, sum = 0;
    printf("������a��");
    scanf("%d",&a);
    printf("������n��");
    scanf("%d",&n);

    int i;
    for(i=0;i<n;i++)
    {
        addend = addend*10 + a;
        sum = sum + addend;
    }
    printf("S=%d\n",sum);
    return 0;
}


// 6. ��1!+2!+3!+.....20!

int main()
{
    double sum = 0, addend = 1; //int �ͷ�Χ����
    int i;
    for(i=1;i<=20;i++)
    {
        addend = addend*i;
        sum = sum + addend;
    }
    printf("%lf\n",sum);
    return 0;
}


// 7. ��.....(��ʽ�򲻳������α�)

int main()
{
    double sum = 0, s1 = 0, s2 = 0, s3 = 0;
    int i = 0;

    for(i=1;i<=100;i++)
        s1 = s1 + i;

    for(i=1;i<=50;i++)
        s2 = s2 + i*i;

    for(i=1;i<=10;i++)
        s3 = s3 + 1.0/i;

    sum = s1 + s2 + s3;
    printf("%lf\n",sum);
    return 0;
}


// 8. �������е�ˮ�ɻ�������νˮ�ʻ�����ָһ����λ�����߸�λ���������͵��ڸ��������� 153=1+125+27��

int main()
{
    int i;
    int d1, d2, d3;
    for(i = 100; i<1000; i++)
    {
        d1 = i/100;
        d2 = (i-d1*100)/10;
        d3 = i%10;

        if(d1*d1*d1+d2*d2*d2+d3*d3*d3 == i)
            printf("%d\t",i);
    }

    return 0;
}


// 9. һ�������ǡ�õ�����������ֻ�ͣ�������ͱ���Ϊ�������������� 6 ��������1,2,3����6=1+2+3�����6 ��������������ҳ�1000֮���������������������ʽ��������ӣ� 6 its fractors are 1,2,3

int main()
{
    int i, j, sum = 0;

    for(i=1; i<=1000; i++)
    {
        sum = 0;
        for(j=1; j<i; j++)
        {
            if(i%j == 0)
                sum = sum + j;
        }
        if(sum == i)
        {
            printf("%d its fractors are 1",sum);
            for(j=2; j<i; j++)
            {
                if(i%j == 0)
                    printf(",%d",j);
            }
            printf("\n");
        }
    }
    return 0;
}


// 10. ��һ���������У� 2/1,3/2,5/3,8/5,13/8..... ����������ǰ20��ֻ�͡�

int main()
{
    int i;
    double sum, addend, f1 = 1, f2 = 1, f3= f1+f2;

    for(i = 1;i <= 20; i++)
    {
        addend = f3/f2;
        sum = sum + addend;
        f1 = f2;
        f2 = f3;
        f3 = f1 + f2;
    }

    printf("%lf\n",sum);
    return 0;
}



// 11. һ�����100m�߶��������䣬ÿ����ط�����ص�ԭ�߶ȵ�һ�룬�����䣬�ٷ����������ڵ�10�����ʱ�������������ף���10�η�����ߡ�

int main()
{
    double sum = 0, height = 100;
    int i;

    for(i = 0; i<10; i++)
    {
        sum = sum + height;
        height = height/2;
        sum = sum + height;
    }
    sum = sum - height;  //��ȥ��10�η����ĸ߶�

    printf("������%lf��,��10�η���%lf��\n",sum, height);
    return 0;
}
*/

// 12. ���ӳ������⡣���ӵ�1��ժ�����ɸ����ӣ���������һ�룬������񫣬�ֶ����1�����ڶ������Ͻ�ʣ�µ����ӳԵ�һ���ֶ����1�����Ժ�ÿ�����϶�����ǰһ��ʣ�µ�һ����1����
//     ����10���������ٳ�ʱ��ֻʣ1�������ˡ����һ��һ��ժ�˶��ٸ����ӡ�


int main()
{
    int number = 1;

    int i;
    for(i=0;i<9;i++)
        number = (number + 1)*2;

    printf("��һ��ժ��%d������\n",number);
    return 0;
}


// 13. �õ�������a��ƽ������������ʽ���α���Ҫ��ǰ���������x�Ĳ�ľ���ֵС��10��-5�η���

int main()
{
    double a, x = 1;
    double temp;
    printf("������a��ֵ��");
    scanf("%lf",&a);

    while(1)
    {
        temp = x;
        x = (x+ a/x)/2;

        if(fabs(temp-x)<0.00001)
            break;
    }
    printf("%lf��ƽ����Ϊ%lf\n",a,x);
    return 0;
}


// 14. ��ţ�ٵ����������淽����1.5�����ĸ��� 2x^3-4x^2+3x-6=0

int main()
{
    double func1(double x)
    {
        return 2*x*x*x - 4*x*x + 3*x -6;
    }

    double func2 (double x)
    {
        return 6*x*x - 8*x + 3;
    }

    double x = 1.5;
    while(1)
    {
        x = x - func1(x)/func2(x);
        if(fabs(func1(x))< 0.000001)                //�Ը�������С��Ϊ�ж�����ʱ����Ҫ����==0�� �жϾ���ֵ�Ƿ�С������0����
            break;
    }
    printf("�÷�����1.5�����ĸ�Ϊ%lf\n",x);
    return 0;
}


// 15. �ö��ַ������淽���ڣ�-10,10��֮��ĸ��� 2x^3-4x^2+3x-6=0  ע���ú����ڣ�-10,10�����䵥��������

int main()
{
    double func1(double x)
    {
        return 2*x*x*x - 4*x*x + 3*x -6;
    }

    double left = -10;
    double right = 10;
    double middle;

    while(1)
    {
        middle = (left + right)/2;
        if(func1(middle)<0)
            left = middle;
        else if (func1(middle)>0)
            right = middle;
        else if(func1(middle)==0)
            break;
    }
    printf("�÷�����1.5�����ĸ�Ϊ%lf\n",middle);
    return 0;
}


/** 16. ��������ͼ����
                              *
                             ***
                            *****
                           *******
                            *****
                             ***
                              *
*/


int main()
{
    int i, j;
    for(i=1; i<=4; i++)
    {
        printf("\t");
        for(j=4-i; j>0; j--)
            printf(" ");

        for(j=1; j<=2*i-1; j++)
            printf("*");

        printf("\n");
    }

    for(i=1; i<=3; i++)
    {
        printf("\t");
        for(j=1; j<=i; j++)
            printf(" ");

        for(j=1; j<=7-2*i; j++)
            printf("*");

        printf("\n");
    }
    return 0;
}


// 17. ����ƹ������б���������3�ˡ��׶�ΪA,B,C���ˣ��Ҷ�ΪX,Y,Z���ˡ��ѳ�ǩ���������������������Ա��������������A˵������X�ȣ�C˵������X,Z�ȣ������ҳ�3�����ֵ�������
// ˼·������X��Y��Z�ֱ��յ���0,1,2�š�����A��B��C��Ӧ0,1,2������������ҳ�����������

int main()
{

    int X=0, Y=1, Z=2;
    int A,B,C;
    for(A=0; A<3; A++)
        for(B=0; B<3; B++)
            for(C=0; C<3; C++)
                if(A!=B&&B!=C&&A!=C&&A!=X&&C!=X&&C!=Z)
                    printf("�������Ϊ��\n A---%d     X---0  \n B---%d     Y---1 \n C---%d     Z---2\n",A,B,C);
    return 0;
}

