#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

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


// 3. ����10����������������С�������һ�����Ի����������������һ�����Ի���д3����������1������10����������2�����д�������3�����10������

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
    return 0;
}

// 7. ��һ���ַ���������n���ַ���дһ�������������ַ����дӵ�m���ַ���ʼ��ȫ���ַ����Ƴ���һ���ַ�����

// 8. ����һ�����֣��ҳ����д�д��ĸ��Сд��ĸ���ո������Լ������ַ����ж��١�

// 9. дһ����������һ��3��3�ľ���ת�á�

// 10. ��һ��5��5�ľ���������Ԫ�ط������ģ�4���Ƿֱ��4����С��Ԫ�أ�˳��Ϊ�����ң����ϵ������δӴ�С��ţ���дһ������ʵ��֮����main�������á�

// 11. ��������������10���ȳ����ַ���������һ����������������Ȼ���������������10���źõ��ַ�����

// 12. ��ָ�����鴦����һ��Ŀ���ַ������ȳ���

// 13. дһ�����η��󶨻��ֵ�ͨ�ú������ֱ���sinx��cosx��e^x�Ķ����֣���������Ϊ0��1��

// 14. ��n����������ʱ˳����������У��ú���ʵ�֡�

// 15. ��һ����4��ѧ����5�ſγ̡�(1)���һ�ſγ̵�ƽ���֣�(2)�ҳ����������Ͽγ̲������ѧ����������ǵ�ѧ�ź�ȫ���γ̳ɼ���ƽ���ɼ���
//     (3)�ҳ�ƽ���ɼ���90�����ϻ�ȫ���γ̳ɼ���85�����ϵ�ѧ�����ֱ��д3������ʵ������3��Ҫ��

// 16. ����һ���ַ������������ֺͷ������ַ������磺A123*456 17960? 302tab5876
//     ������������������Ϊһ��������һ�δ��������a�С�����123����a[0],456����a[1]...��ͳ��һ���ж��ٸ��������������Щ������

/** 17. дһ��������ʵ�������ַ����Ƚϡ����Լ�ʵ��strcmp����������ԭ��Ϊ int strcmp(char *p1��char *p2)
        ��p1ָ���ַ���s1��p2ָ���ַ���s2��Ҫ��s1=s2ʱ������ֵΪ0����s1������s2���������Ƕ��ߵ�1����ͬ�ַ���ASCII���ֵ���硰BOY���͡�BAD����2����ĸ��ͬ��
        ��O���롰A��֮���Ϊ 79-65=14�������s1>s2���������ֵ�����s1<s2���������ֵ��
*/

// 18. ��һ���������·ݺţ�������µ�Ӣ�����������磬����"3"���������March����Ҫ����ָ�����鴦����

// 19. (1) ��дһ������ new����n���ַ����������Ĵ洢�ռ䣬�˺���Ӧ����һ��ָ��(��ַ)��ָ���ַ�����ʼ�Ŀռ䡣new(n)��ʾ����n���ֽڵ��ڴ�ռ䡣
//     (2) дһ������free����ǰ��new����ռ�õĿռ��ͷš�free(p)��ʾ��p(��ַ)ָ��ĵ�Ԫ�Ժ���ڴ��ͷš�

// 20. ��ָ��ָ���ָ��ķ�����5���ַ������������

// 21. ��ָ��ָ���ָ��ķ�����n���������������Ҫ�����򵥶�д��һ��������n�������������������룬������������������