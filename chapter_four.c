#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// 4. ����������a��b��c���ɼ������룬���������������
/*
int main()
{
        int a, b, c, t;
        printf("����a��b��c��ֵ���Կո�ָ���");
        scanf("%d%d%d",&a,&b,&c);
        t = a > b? a : b;
        t = t > c? t : c;
        printf("�������ǣ�%d\n",t);
        return 0;
}
*/

// 5. �Ӽ�������һ��С��1000��������Ҫ���������ƽ���������ƽ����������������������������֣���Ҫ���������ݺ��ȶ�����м���Ƿ�ΪС��1000�������������ǣ���Ҫ���������롣
/*
int main()
{
    double num = 0;
    printf("����һ��С��1000��������");
    scanf("%lf",&num);
    while(num>=1000||num<=0)
    {
        printf("������Χ�����������룺");
        scanf("%lf",&num);
    }

    printf("��ƽ����Ϊ��%d\n",(int)sqrt(num));
    return 0��
}
*/

// 6. ��һ�����������α����� д��������x��ֵ�����y��Ӧ��ֵ��
/*
int main()
{
    double x , y;
    scanf("%lf",&x);

    if(x<1)
        y = x;
    else if(x<10)
        y = 2*x - 1;
    else
        y = 3*x - 11;

    printf("%ld\n",y); //%g ���������ʱ��������������0��������6λС��,�����Զ�������������»ᶪʧ���ȣ�������ʹ��  (�ɸĳ���%g��ʽ������ֱ�������9.9999,��9.99999��
    return 0;
}
*/

// 8. ����һ�ٷ��Ƴɼ���Ҫ������ɼ��ȼ���A����B����C����D����E����90������Ϊ��A����80~89��Ϊ��B����70~79��Ϊ��C����60~69��Ϊ��D����60��һ��Ϊ��E����

/*
int main()
{
    double grade;
    scanf("%lf",&grade);

    if(grade>100||grade<0)
        printf("�ɼ�����");
    else if(grade>=90)
        printf("A");    //printf() �����õ���������������ַ�����printf('A')�ᱨ��
    else if(grade>=80)
        printf("B");
    else if(grade>=70)
        printf("C");
    else if(grade>=60)
        printf("D");
    else
        printf("E");

    return 0;
}
*/

// 9. ��һ��������5λ����������Ҫ�󣺣�1�� ������Ǽ�λ�� ��2���ֱ����ÿһλ���� ��3�������������λ���֣�����ԭ��Ϊ321��Ӧ���123.

/*
int main()
{
    int num;
    printf("����һ��������5λ����������");
    scanf("%d",&num);
    int temp = num;

    int bits = (int)log10((double)num)+1;
    printf("����%dλ��\n",bits);


    printf("ÿһλ���ֱ�Ϊ:");
    while(bits--)
    {
        printf(" %d",temp/(int)round(pow(10,bits))); //��ֱ��д��(int)pow(10,bits) �ᵼ�¾��ȶ�ʧ��������羭���������������ֵΪ1������������ʾΪ0.99999��ǿ��ת����(int)0.99999 = 0.
        temp = temp%(int)round(pow(10,bits));       // pow(),log10() ����ѧ�����Ĳ����ͷ���ֵ��Ӧ��double���͵ģ�
    }                                               // ���԰����ε��������ã��������������Σ����������԰Ѹ�����ֱ�Ӹ������Σ�����ֵ���������ν��գ���ǿ��ת����Ҳ����־��ȶ�ʧ�����ر���

    temp = num;
    printf("\n����ÿһλ���ֱ�Ϊ��");
    while(temp)
    {
        printf(" %d",temp%10);
        temp = temp/10;
    }

    return 0;
}


*/



// 10. ��ҵ���ŵĽ������������ɡ�����I���ڻ����100000Ԫ�ģ��������10%���������100000Ԫ������200000Ԫ��100000<I<=200000��ʱ������100000Ԫ�Ĳ��ְ�10%��ɣ�
//     ����100000Ԫ�Ĳ��֣������7.5%. 200000<I<=400000ʱ������200000Ԫ�Ĳ����԰������취��ɣ���ͬ��������200000Ԫ�Ĳ��ְ�5%��ɣ�400000<I<=600000Ԫʱ������400000Ԫ�Ĳ��ְ�3%��ɣ�
//     600000<I<=1000000Ԫʱ������600000Ԫ�Ĳ��ְ�1.5%��ɣ�I>1000000ʱ������1000000�Ĳ��ְ�1%��ɡ��Ӽ������뵱������I����Ӧ������������Ҫ��1����if����� ��2����switch�����

/*
//if �����
int main()
{
    double I, bouns;

    printf("�����뱾������");
    scanf("%lf",&I);

    if(I <= 100000)
        bouns = I * 0.1;
    else if(I <= 200000)
        bouns = 100000*0.1 + (I-100000)*0.075;
    else if(I <= 400000)
        bouns = 100000*0.1 + (200000-100000)*0.075 + (I-200000)*0.05;
    else if(I <= 600000)
        bouns = 100000*0.1 + (200000-100000)*0.075 + (400000-200000)*0.05 + (I-400000)*0.03;
    else if(I <= 1000000)
        bouns = 100000*0.1 + (200000-100000)*0.075 + (400000-200000)*0.05 + (600000-400000)*0.03 + (I-600000)*0.015;
    else if(I > 1000000)
        bouns = 100000*0.1 + (200000-100000)*0.075 + (400000-200000)*0.05 + (600000-400000)*0.03 + (10-600000)*0.015 + (I-1000000)*0.01;
    printf("Ӧ������Ϊ��%lf\n",bouns);

    return 0;
}


//switch �����

int main()
{
    double I,I2,bouns;

    printf("�����뱾������");
    scanf("%lf",&I);

    I2 = I;
    int t = (int)I2/100000;
    switch(t)
    {
        case 0: bouns = I* 0.1; break;
        case 1: bouns = 100000*0.1 + (I-100000)*0.075; break;
        case 2:
        case 3: bouns = 100000*0.1 + (200000-100000)*0.075 + (I-200000)*0.05; break;
        case 4:
        case 5: bouns = 100000*0.1 + (200000-100000)*0.075 + (400000-200000)*0.05 + (I-400000)*0.03; break;
        case 6:
        case 7:
        case 8:
        case 9: bouns = 100000*0.1 + (200000-100000)*0.075 + (400000-200000)*0.05 + (600000-400000)*0.03 + (I-600000)*0.015; break;
        default: bouns = 100000*0.1 + (200000-100000)*0.075 + (400000-200000)*0.05 + (600000-400000)*0.03 + (1000000-600000)*0.015 + (I-1000000)*0.01; break;
    }
    printf("Ӧ������Ϊ��%lf\n",bouns);
}

*/

// 11. ����4��������Ҫ����С�����˳�������
/*
int main()
{
    int max(int a, int b)
    {
        return a>b?a:b;
    }

    int min(int a, int b)
    {
        return a<b?a:b;
    }

    int n1, n2, n3, n4;
    printf("����4���������Կո�ָ���");
    scanf("%d%d%d%d",&n1,&n2,&n3,&n4);

    int smallest = min(min(n1,n2),min(n3,n4));
    int largest = max(max(n1,n2),max(n3,n4));
    int middle_two_sum = n1+n2+n3+n4-smallest-largest;

    if(n1+n2 == middle_two_sum)
            printf("%d  %d  %d  %d\n",smallest,min(n1,n2),max(n1,n2),largest);
    else if(n1+n3 == middle_two_sum)
            printf("%d  %d  %d  %d\n",smallest,min(n1,n3),max(n1,n3),largest);
    else if(n1+n4 == middle_two_sum)
            printf("%d  %d  %d  %d\n",smallest,min(n1,n4),max(n1,n4),largest);
    else if(n2+n3 == middle_two_sum)
            printf("%d  %d  %d  %d\n",smallest,min(n2,n3),max(n2,n3),largest);
    else if(n2+n4 == middle_two_sum)
            printf("%d  %d  %d  %d\n",smallest,min(n2,n4),max(n2,n4),largest);
    else if(n3+n4 == middle_two_sum)
            printf("%d  %d  %d  %d\n",smallest,min(n3,n4),max(n3,n4),largest);
    return 0;

}
*/


// 12. ��4��Բ����Բ�ķֱ�Ϊ��2��2������-2��2������-2��-2������2��-2����Բ�뾶Ϊ1����4�����ĸ߶�Ϊ10�ף��������޽������������һ������꣬��õ�Ľ����߶ȣ�����ĸ߶�Ϊ�㣩��

/*
int main()
{
    double x = 0, y = 0;
    double d1, d2, d3, d4;

    printf("����˵����꣬�Զ��ŷָ���");
    scanf("%lf,%lf",&x,&y);

    d1 = sqrt((x-2)*(x-2)+(y-2)*(y-2));
    d2 = sqrt((x-2)*(x-2)+(y+2)*(y+2));
    d3 = sqrt((x+2)*(x+2)+(y+2)*(y+2));
    d4 = sqrt((x+2)*(x+2)+(y-2)*(y-2));

    if(d1<=1||d2<=1||d3<=1||d4<=1)
        printf("�˵�Ľ����߶�Ϊ10��\n");
    else
        printf("�˵�Ľ����߶�Ϊ0��\n");

    return 0;

}
*/
