#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


// 1. ��ɸѡ����100֮�ڵ�������
//��ɸѡ�������ж�1��������Ҳ���Ǻ�������ȥ��2�����������£����Ѻ�����Ա�2�����Ļ�ȥ�����ж�3,���������¡����ж�4��4���ж�2ʱ�Ѿ���ȥ�ˣ��������ж�5....��100�������µĶ�����������
/*
int main()
{
    int a[100];

    int i,j;
    for(i=0;i<100;i++)
        a[i]=i+1;

    for(i=0;i<100;i++)
    {
        if(a[i]==1)
            continue;
        for(j=i+1;j<100;j++)
        {
            if(a[j]%a[i]==0)
                a[j]=1;             //���Ǻ�����Ԫ��ֵ�ĳ�1����ʾ��ȥ
        }
    }

    for(i=0;i<100;i++)
        if(a[i]!=1)
            printf("%-4d",a[i]);    //���ֵ��Ϊ1��������

    return 0;
}
*/

// 2. ��ѡ�񷨶�10����������
//(ѡ�񷨣��ѵ�һ�����ͺ����һ�αȽϣ�ѡ����С���������һ�����Ի�λ�á��ٴӵڶ�������ʼ����Ƚϣ�ѡ����С����ڶ������Ի�...)
/*
int main()
{
    int a[10];
    int i,j;
    int t,temp,min;

    for(i=0;i<10;i++)
        scanf("%d",&a[i]);

    for(i=0;i<10;i++)
    {
        min = a[i];             // min �� t ��ֵ����������ѭ���仯�����ÿ���ڲ�ѭ����ʼǰҪ���ó�ʼֵ������ʹ���ϴ�ѭ�����µ�ֵ
        t = i;

        for(j=i;j<10;j++)
            if(a[j]<min)
            {
                min = a[j];
                t = j;
            }

        temp = a[t];
        a[t] = a[i];
        a[i] = temp;
    }

    printf("��С��������Ϊ��");
    for(i=0;i<10;i++)
        printf("%d  ",a[i]);
    printf("\n");

    return 0;
}

*/

// 3. ��һ��3��3����������Խ���Ԫ��֮�͡�

/*
int main()
{
    int a[3][3];
    int sum;
    int i,j;

    printf("���������\n");
    for(i=0;i<3;i++)
    {
        printf("�������%d������������",i+1);
        for(j=0;j<3;j++)
            scanf("%d",&a[i][j]);
    }

    sum = a[0][0]+a[1][1]+a[2][2]+a[0][2]+a[2][0];
    printf("�Խ���Ԫ��֮��Ϊ: %d\n",sum);
    return 0;
}
*/
// 4. ��һ�����źõ����飬Ҫ������һ�����󣬰�ԭ������Ĺ��ɽ������������С�
/*
int main()
{
    int a[20] = {1,5,8,9,10,20,50,100};         //δָ��ֵ��Ԫ�ر���ʼ��ΪNULL��ֵΪ0
    int x,temp;
    int i = 0,count = 0;

    printf("ԭ����Ϊ��");
    while(a[i]!=NULL)                       //�����������ʱδָ�����ȣ��� int a[] = {1,5,8,9,10,20,50,100}������������NULL���жϳ��ȣ���Ϊ��������������Ĵ洢��Ԫ���ݲ�Ϊ�ա�
    {
        printf("%d  ",a[i]);
        count++;
        i++;
    }

    printf("\n������һ����:");
    scanf("%d",&x);

    for(i=0;i<count;i++)
    {
        if(x>=a[i])
            continue;

        temp = a[i];
        a[i] = x;
        x = temp;
    }

    a[i] = x;

    printf("��������������Ϊ��");
    for(i=0;i<count+1;i++)
        printf("%d  ",a[i]);
    return 0;
}
*/

// 5. ��һ�������е�ֵ���������´�š����磬ԭ��˳��Ϊ8,6,5,4,1��Ҫ���Ϊ1,4,5,6,8.
/*
int main()
{
    int a[] = {8,6,5,4,1};
    int count = sizeof(a)/sizeof(a[0]);
    int i, temp;

    printf("ԭ����Ϊ��");            //���ԭ����
    for(i=0;i<count;i++)
        printf("%d  ",a[i]);
    printf("\n");

    for(i=0;i<count/2;i++)          //��һ�������һ���Ի����ڶ����뵹���ڶ����Ի�....
    {
        temp = a[i];
        a[i] = a[count-1-i];
        a[count-1-i] = temp;
    }

    printf("���������Ϊ��");         //�����������
    for(i=0;i<count;i++)
        printf("%d  ",a[i]);
    printf("\n");

    return 0;
}
*/

// 6. ������µ�������ǣ�Ҫ�����10�С�
/*
int main()
{
    int a[10][10];
    int i, j;

    for(i=0;i<10;i++)
        for(j=0;j<10;j++)           //�����������
        {
            if(j==0||i==j)
                a[i][j] = 1;
            else if(i>j)
                a[i][j] = a[i-1][j-1] + a[i-1][j];
            else
                a[i][j] = 0;
        }

    for(i=0;i<10;i++)           //������ʵ����ʽ����������
    {
        for(j=0;j<=i;j++)
            printf("%-4d",a[i][j]);

        printf("\n");
    }

    return 0;
}
*/

// 7. �����ħ���󡱡���νħ������ָ�����ķ�������ÿһ�С�ÿһ�кͶԽ���֮�;���ȡ����磬����ħ����Ϊ��
/**   8 1 6
      3 5 7
      4 9 2
      Ҫ�����1��n^2����Ȼ�����ɵ�ħ����
*/
/**   �����ҵ���������ħ������Ƶ�����
      (1)��1���ڵ�1�е��м�һ�С�
      (2)��2��ʼֱ��n��nֹ�������ΰ����й����ţ�ÿһ������ŵ��б�ǰһ������������1��������1���������������ħ����5��4����һ�к�һ�У���
      (3)�����һ��������Ϊ1������һ����������Ϊn(ָ����һ��)�����磬1�ڵ�һ�У���2Ӧ��������һ�У�����ͬ����1.
      (4)����һ����������Ϊnʱ����һ����������ӦΪ1��������1.���磬2�ڵ�3�����һ�У���3Ӧ���ڵ�2�е�1�С�
      (5)������������ȷ����λ����������������һ�����ǵ�һ�е�n��ʱ�������һ����������һ���������档���磬������Ĺ涨��4Ӧ�÷��ڵ�1�е�2�У�����λ���Ѿ���1ռ�ݣ�
         ����4�ͷ���3�����档����6�ǵ�1�е�3�У������һ�У�����7����6���档���˷������Եõ��κν׵�ħ����

      ż����ħ����ʹ����һ���Ƶ����򣬻�����Ƿ�Ϊ4�ı������ۡ��������ֻ�������������׵ĳ���
*/
//
/*
int main()
{
    int a[30][30] = {0};
    int i,j;
    int num, n;

    printf("����������ħ����Ľ�����������30����������");
    while(scanf("%d",&n))
    {
        if(n>0&&n<30&&n%2!=0)
            break;
        else
            printf("�������������Ҫ�����������룺");
    }

    i = 0;                                              //��i��j����¼ħ�����е��к��У���ʼλ��Ϊ��һ���м���
    j = n/2;
    a[i][j] = 1;                                        //������1
    for(num = 2; num <= n*n; num++)                     //��2��ʼ����������������ħ��������Ӧ�ڵ�λ��
    {
        if(i!=0&&j!=n-1)                                //�ȱ䶯λ�á����жϷ��������ʱ���ж���һ��a[i-1][j+1]�Ƿ�ռ��
        {
            if(a[i-1][j+1]==0)                          //��û��ռ�ݣ��Ƶ��ô�
            {
                i = i-1;
                j = j+1;
            }
            else if(a[i-1][j+1]!=0)                     //���ѱ�ռ�ݣ��Ƶ�������һ��
                i = i+1;
        }
        else if(i==0&&j==n-1)                           //��1���ҵ�n�����
            i = i+1;
        else if(i==0&&j!=n-1)                           //��1�зǵ�n�е�ʱ��Ҳ�÷���һ��a[n-1][j+1]�Ƿ�ռ��
        {
            if(a[n-1][j+1]==0)
            {
                i = n-1;
                j = j+1;
            }
            else if(a[n-1][j+1]!=0)
                i = i+1;
        }
        else if(i!=0&&j==n-1)                           //��n�зǵ�һ�е�ʱ��Ҳ�÷���һ��a[i-1][0]�Ƿ�ռ��
        {
            if(a[i-1][0]==0)
            {
                i = i-1;
                j = 0;
            }
            else if(a[i-1][0]!=0)
                i = i+1;
        }

        a[i][j] = num;                                  //������䶯��λ�ú�����
    }

    printf("%d��ħ�����������£�\n",n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%-4d",a[i][j]);
        printf("\n");
    }

    return 0;
}
*/

// 8. �ҳ�һ����ά�����еİ��㣬����λ���ϵ�Ԫ���ڸ���������ڸ�������С��Ҳ����û�а��㡣
/*
int main()
{
    int a[10][10] = {0};
    int count = 0;
    int i,j,k;
    int min, max,max_j,min_i;
    int flag = 0;

    printf("�ö�ά������ʾ���£�\n");
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
             a[i][j] = count++;           //Ϊ��ά���鸳ֵ����ӡ,��0��99֮��
             printf("%-4d",a[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<10;i++)                       //һ��һ�б���
    {
        max = a[i][0];                      //�ҳ�һ��������������¼�к�
        max_j = 0;
        for(j=0;j<10;j++)
        {
            if(a[i][j]>max)
            {
                max = a[i][j];
                max_j = j;
            }
        }

        min = a[0][max_j];                  //�Ѹ��д�ͷ�������ҳ���С��������¼�к�
        min_i = 0;
        for(k=0;k<10;k++)
        {
            if(a[k][max_j]<min)
            {
                min = a[k][max_j];
                min_i = k;
            }
        }

        if(min==max)                        //�����������ֵ������С�ģ��ҵ��˰��㣬��ӡ����
        {
            printf("\n��%d�е�%d�еĵ��ǰ��㣬��ֵΪ%d\n",min_i+1,max_j+1,max);
            flag = 1;
        }
    }

    if(flag==0)
        printf("û�а���\n");               //�����־λû�б仯��˵��û�а���

    return 0;
}
*/

// 9. ��15�������ɴ�С˳������һ�������У�����һ������Ҫ�����۰���ҷ��ҳ������������еڼ���Ԫ�ص�ֵ������������������У���������޴�������

/*
int main()
{
    int a[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int i, x;
    int left, right,middle;
    int flag = 0;

    printf("������Ϊ:");
    for(i=0;i<15;i++)
        printf("%-3d",a[i]);

    printf("\n������һ������");
    scanf("%d",&x);

    left = 0;
    right = 14;
    while(x>=a[left]&&x<a[right])
    {
        middle = (left+right)/2;        //����int������0ȡ����ȡ�������������������Ǹ����������ж�

        if(a[middle]==x)
        {flag = 1; break;}
        else if(a[middle]>x)
            right = middle;
        else if(a[middle]<x)
            left = middle;
    }

    if(flag==1)
        printf("%d�Ǹ������еĵ�%d��Ԫ��\n",x,middle+1);
    else if(x==a[14])
        printf("%d�Ǹ������еĵ�15��Ԫ��\n",x);
    else
        printf("�޴���\n");

    return 0;

}
*/

// 10. ��һƪ���£����������֣�ÿ��80���ַ���Ҫ��ֱ�ͳ�Ƴ�����Ӣ�Ĵ�д��ĸ��Сд��ĸ�����֣��ո��Լ������ַ��ĸ�����
/*
int main()
{
    char a[] = {"Glass cannons are Pokemons that offset their relative frailty with high attack-\ning power.In the turn-based main series, Pokemon with high Special and Physical\nAttack, in conjunction with a high Speed, could be used to ��sweep�� opponents.\n"};
    int i, length;
    int upper_case = 0, lower_case = 0, number = 0, space = 0, other = 0;

    length = strlen(a);

    printf("ԭ������:\n");
    for(i=0;i<length;i++)
    {
        putchar(a[i]);
        if(a[i]==' ')
            space++;
        else if(a[i]>='a'&&a[i]<='z')
            lower_case++;
        else if(a[i]>='A'&&a[i]<='Z')
            upper_case++;
        else if(a[i]>='0'&&a[i]<='9')
            number++;
        else
            other++;
    }

    printf("\n��д��ĸ��%d����Сд��ĸ��%d����������%d�����ո���%d��������������%d��\n",upper_case,lower_case,number,space,other);

    return 0;

}
*/
// 11. �������ͼ����
/**                     * * * * *
                          * * * * *
                            * * * * *
                              * * * * *
*/
/*
int main()
{
    char s[] = {"* * * * *"};

    int i,j;
    for(i=0;i<4;i++)
    {
        putchar('\t');
        for(j=0;j<2*i;j++)
            putchar(' ');
        puts(s);

    }

    return 0;
}
*/

// 12. ��һ�е��ģ��Ѱ���������ѳ����룺A->Z, a->z, B->Y, b->y.....������1����ĸ��ɵ�26����ĸ����i����ĸ��ɵڣ�26-i+1������ĸ������ĸ�ַ����䡣Ҫ���̽��������ԭ�ģ�����������ԭ�ġ�
/*
int main()
{
    char ciperText[] = {"abcdefghijklmnopqrstuvwxyz,ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    int length = strlen(ciperText);
    int i;

    printf("����Ϊ��\n");
    puts(ciperText);

    printf("ԭ��Ϊ��\n");
    for(i=0;i<length;i++)
    {
        if(ciperText[i]>=65&&ciperText[i]<=90)
            printf("%c",90-(ciperText[i]-65));
        else if(ciperText[i]>=97&&ciperText[i]<=122)
            printf("%c",122-(ciperText[i]-97));
        else
            printf("%c",ciperText[i]);
    }
    printf("\n");

    return 0;

}

*/

// 13. ��һ�����򣬽������ַ���������������Ҫ��strcat������
/*
int main()
{
    char* concatenate(char A[], char B[])
    {
        int len_A = strlen(A);
        int len_B = strlen(B);
        int i;

        for(i = 0; i<len_B; i++)
            A[len_A+i] = B[i];

        return A;
    }

    char str1[1000];
    char str2[200];
    printf("�������һ���ַ�����\n");
    gets(str1);
    printf("������ڶ����ַ�����\n");
    gets(str2);
    printf("���Ӻ���Ϊ��\n%s\n",concatenate(str1,str2));

    return 0;
}

*/

// 14. ��һ�����򣬽������ַ���s1��s2�Ƚϣ����s1>s2,���һ����������s1=s2,���0����s1<s2,���һ����������Ҫ��strcmp�����������ַ�����gets�������롣
//     ������������ľ���ֵӦ�ǱȽ������ַ�����Ӧ�ַ�ASCII��Ĳ�ֵ�����磬��A���롰C����ȣ����ڡ�A��<��C����Ӧ�����������-2����And���͡�Aid���Ƚϣ����ݵ�2���ַ��ȽϽ������n���ȡ�i����5��Ӧ�����5����
//     ������ʵ��strcmp��������ֻ�Ƚϵ���һ��������ַ��������ǱȽ������ַ������ܲ�ֵ��
/*
int main()
{
    int compare(char A[], char B[])
    {

        int i = 0, diff = 0;
        while(diff==0)
        {
            diff = A[i]-B[i];
            i++;
            if(A[i]=='\0'||B[i]=='\0')
                break;
        }
        return diff;
    }

    char str1[200];
    char str2[200];
    printf("�������һ���ַ�����\n");
    gets(str1);
    printf("������ڶ����ַ�����\n");
    gets(str2);
    printf("�ȽϺ���Ϊ��\n%d\n",compare(str1,str2));

    return 0;
}
*/

// 15. ��дһ�����򣬽��ַ�����s2�е�ȫ���ַ����Ƶ��ַ�����s1�С�����strcpy����������ʱ��'\0'ҲҪ���ƹ�ȥ����\0��������ַ������ơ�

/*
int main()
{
    int copy(char A[], char B[])
    {

        int i = 0, len_B = strlen(B);
        while(B[i]!='\0')
        {
            A[i] = B[i++];
        }
        A[i] = B[i];

        return A;
    }

    char str1[200];
    char str2[200];
    printf("�������һ���ַ�����\n");
    gets(str1);
    printf("������ڶ����ַ�����\n");
    gets(str2);
    printf("���ƺ���Ϊ��\n%s\n",copy(str1,str2));

    return 0;
}
*/
