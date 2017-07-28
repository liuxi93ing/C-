#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


// 1. 用筛选法求100之内的素数。
//（筛选法：先判断1不是质数也不是合数，划去。2是质数，留下，并把后面可以被2整除的划去。再判断3,是质数留下。再判断4，4在判断2时已经划去了，跳过。判断5....到100最终留下的都是质数。）
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
                a[j]=1;             //把是合数的元素值改成1来表示划去
        }
    }

    for(i=0;i<100;i++)
        if(a[i]!=1)
            printf("%-4d",a[i]);    //输出值不为1的所有数

    return 0;
}
*/

// 2. 用选择法对10个整数排序。
//(选择法：把第一个数和后面的一次比较，选出最小的数，与第一个数对换位置。再从第二个数开始往后比较，选出最小的与第二个数对换...)
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
        min = a[i];             // min 和 t 的值都随着内曾循环变化，因此每次内层循环开始前要赋好初始值，避免使用上次循环留下的值
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

    printf("由小到大排序为：");
    for(i=0;i<10;i++)
        printf("%d  ",a[i]);
    printf("\n");

    return 0;
}

*/

// 3. 求一个3乘3的整数矩阵对角线元素之和。

/*
int main()
{
    int a[3][3];
    int sum;
    int i,j;

    printf("请输入矩阵：\n");
    for(i=0;i<3;i++)
    {
        printf("请输入第%d行三个整数：",i+1);
        for(j=0;j<3;j++)
            scanf("%d",&a[i][j]);
    }

    sum = a[0][0]+a[1][1]+a[2][2]+a[0][2]+a[2][0];
    printf("对角线元素之和为: %d\n",sum);
    return 0;
}
*/
// 4. 有一个已排好的数组，要求输入一个数后，按原来排序的规律将它插入数组中。
/*
int main()
{
    int a[20] = {1,5,8,9,10,20,50,100};         //未指定值的元素被初始化为NULL，值为0
    int x,temp;
    int i = 0,count = 0;

    printf("原数组为：");
    while(a[i]!=NULL)                       //如果创建数组时未指定长度，如 int a[] = {1,5,8,9,10,20,50,100}；则不能用这用NULL来判断长度，因为该数组结束后后面的存储单元内容不为空。
    {
        printf("%d  ",a[i]);
        count++;
        i++;
    }

    printf("\n请输入一个数:");
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

    printf("插入此数后的数组为：");
    for(i=0;i<count+1;i++)
        printf("%d  ",a[i]);
    return 0;
}
*/

// 5. 将一个数组中的值按逆序重新存放。例如，原来顺序为8,6,5,4,1。要求改为1,4,5,6,8.
/*
int main()
{
    int a[] = {8,6,5,4,1};
    int count = sizeof(a)/sizeof(a[0]);
    int i, temp;

    printf("原数组为：");            //输出原数组
    for(i=0;i<count;i++)
        printf("%d  ",a[i]);
    printf("\n");

    for(i=0;i<count/2;i++)          //第一个与最后一个对换，第二个与倒数第二个对换....
    {
        temp = a[i];
        a[i] = a[count-1-i];
        a[count-1-i] = temp;
    }

    printf("逆序的数组为：");         //输出逆序数组
    for(i=0;i<count;i++)
        printf("%d  ",a[i]);
    printf("\n");

    return 0;
}
*/

// 6. 输出以下的杨辉三角，要求输出10行。
/*
int main()
{
    int a[10][10];
    int i, j;

    for(i=0;i<10;i++)
        for(j=0;j<10;j++)           //构造杨辉三角
        {
            if(j==0||i==j)
                a[i][j] = 1;
            else if(i>j)
                a[i][j] = a[i-1][j-1] + a[i-1][j];
            else
                a[i][j] = 0;
        }

    for(i=0;i<10;i++)           //按书上实例格式输出杨辉三角
    {
        for(j=0;j<=i;j++)
            printf("%-4d",a[i][j]);

        printf("\n");
    }

    return 0;
}
*/

// 7. 输出“魔方阵”。所谓魔方阵是指这样的方阵，它的每一行。每一列和对角线之和均相等。例如，三阶魔方阵为：
/**   8 1 6
      3 5 7
      4 9 2
      要求输出1到n^2的自然数构成的魔方阵。
*/
/**   网上找到的奇数阶魔方阵的推导规则：
      (1)将1放在第1行的中间一列。
      (2)从2开始直到n×n止各数依次按下列规则存放：每一个数存放的行比前一个数的行数减1，列数加1（例如上面的三阶魔方阵，5在4的上一行后一列）。
      (3)如果上一数的行数为1，则下一个数的行数为n(指最下一行)。例如，1在第一行，则2应放在最下一行，列数同样加1.
      (4)当上一个数的列数为n时，下一个数的列数应为1，行数减1.例如，2在第3行最后一列，则3应放在第2行第1列。
      (5)如果按上面规则确定的位置上已有数，或上一个数是第一行第n列时，则把下一个数放在上一个数的下面。例如，按上面的规定，4应该放在第1行第2列，但该位置已经被1占据，
         所以4就放在3的下面。由于6是第1行第3列（即最后一列），故7放在6下面。按此方法可以得到任何阶的魔方阵。

      偶数阶魔方阵使用另一套推导规则，还需分是否为4的倍数讨论。因此我们只考虑生成奇数阶的程序。
*/
//
/*
int main()
{
    int a[30][30] = {0};
    int i,j;
    int num, n;

    printf("请输入所求魔方阵的阶数（不超过30的奇数）：");
    while(scanf("%d",&n))
    {
        if(n>0&&n<30&&n%2!=0)
            break;
        else
            printf("输入阶数不符合要求，请重新输入：");
    }

    i = 0;                                              //用i和j来记录魔方阵中的行和列，初始位置为第一行中间列
    j = n/2;
    a[i][j] = 1;                                        //单独填1
    for(num = 2; num <= n*n; num++)                     //从2开始把所有数依次填入魔方阵中其应在的位置
    {
        if(i!=0&&j!=n-1)                                //先变动位置。先判断非特殊情的时候，判断下一处a[i-1][j+1]是否被占据
        {
            if(a[i-1][j+1]==0)                          //若没被占据，移到该处
            {
                i = i-1;
                j = j+1;
            }
            else if(a[i-1][j+1]!=0)                     //若已被占据，移到该列下一行
                i = i+1;
        }
        else if(i==0&&j==n-1)                           //第1行且第n的情况
            i = i+1;
        else if(i==0&&j!=n-1)                           //第1行非第n列的时候，也得分下一处a[n-1][j+1]是否被占据
        {
            if(a[n-1][j+1]==0)
            {
                i = n-1;
                j = j+1;
            }
            else if(a[n-1][j+1]!=0)
                i = i+1;
        }
        else if(i!=0&&j==n-1)                           //第n列非第一行的时候，也得分下一处a[i-1][0]是否被占据
        {
            if(a[i-1][0]==0)
            {
                i = i-1;
                j = 0;
            }
            else if(a[i-1][0]!=0)
                i = i+1;
        }

        a[i][j] = num;                                  //分情况变动完位置后，填数
    }

    printf("%d阶魔方阵输入如下：\n",n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%-4d",a[i][j]);
        printf("\n");
    }

    return 0;
}
*/

// 8. 找出一个二维数组中的鞍点，即该位置上的元素在该行上最大，在该列上最小。也可能没有鞍点。
/*
int main()
{
    int a[10][10] = {0};
    int count = 0;
    int i,j,k;
    int min, max,max_j,min_i;
    int flag = 0;

    printf("该二维数组显示入下：\n");
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
             a[i][j] = count++;           //为二维数组赋值并打印,在0到99之间
             printf("%-4d",a[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<10;i++)                       //一行一行遍历
    {
        max = a[i][0];                      //找出一行中最大的数，记录列号
        max_j = 0;
        for(j=0;j<10;j++)
        {
            if(a[i][j]>max)
            {
                max = a[i][j];
                max_j = j;
            }
        }

        min = a[0][max_j];                  //把该列从头遍历，找出最小的数，记录行号
        min_i = 0;
        for(k=0;k<10;k++)
        {
            if(a[k][max_j]<min)
            {
                min = a[k][max_j];
                min_i = k;
            }
        }

        if(min==max)                        //如果最大的数的值等于最小的，找到了鞍点，打印出来
        {
            printf("\n第%d行第%d列的点是鞍点，其值为%d\n",min_i+1,max_j+1,max);
            flag = 1;
        }
    }

    if(flag==0)
        printf("没有鞍点\n");               //如果标志位没有变化，说明没有鞍点

    return 0;
}
*/

// 9. 有15个数按由大到小顺序存放在一个数组中，输入一个数，要求用折半查找法找出该数是数组中第几个元素的值。如果该数不在数组中，则输出“无此数”。

/*
int main()
{
    int a[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int i, x;
    int left, right,middle;
    int flag = 0;

    printf("该数组为:");
    for(i=0;i<15;i++)
        printf("%-3d",a[i]);

    printf("\n请输入一个数：");
    scanf("%d",&x);

    left = 0;
    right = 14;
    while(x>=a[left]&&x<a[right])
    {
        middle = (left+right)/2;        //由于int类型向0取整，取不到整个数组中最大的那个数，单独判断

        if(a[middle]==x)
        {flag = 1; break;}
        else if(a[middle]>x)
            right = middle;
        else if(a[middle]<x)
            left = middle;
    }

    if(flag==1)
        printf("%d是该数组中的第%d个元素\n",x,middle+1);
    else if(x==a[14])
        printf("%d是该数组中的第15个元素\n",x);
    else
        printf("无此数\n");

    return 0;

}
*/

// 10. 有一篇文章，共有三行字，每行80个字符。要求分别统计出其中英文大写字母，小写字母，数字，空格以及其他字符的个数。
/*
int main()
{
    char a[] = {"Glass cannons are Pokemons that offset their relative frailty with high attack-\ning power.In the turn-based main series, Pokemon with high Special and Physical\nAttack, in conjunction with a high Speed, could be used to “sweep” opponents.\n"};
    int i, length;
    int upper_case = 0, lower_case = 0, number = 0, space = 0, other = 0;

    length = strlen(a);

    printf("原文如下:\n");
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

    printf("\n大写字母有%d个，小写字母有%d个，数字有%d个，空格有%d个，其他符号有%d个\n",upper_case,lower_case,number,space,other);

    return 0;

}
*/
// 11. 输出以下图案：
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

// 12. 有一行电文，已按下面规律已成密码：A->Z, a->z, B->Y, b->y.....。即第1个字母变成第26个字母，第i个字母变成第（26-i+1）个字母。非字母字符不变。要求编程将密码译回原文，并输出密码和原文。
/*
int main()
{
    char ciperText[] = {"abcdefghijklmnopqrstuvwxyz,ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    int length = strlen(ciperText);
    int i;

    printf("密文为：\n");
    puts(ciperText);

    printf("原文为：\n");
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

// 13. 编一个程序，将两个字符串连接起来，不要用strcat函数。
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
    printf("请输入第一个字符串：\n");
    gets(str1);
    printf("请输入第二个字符串：\n");
    gets(str2);
    printf("连接后结果为：\n%s\n",concatenate(str1,str2));

    return 0;
}

*/

// 14. 编一个程序，将两个字符出s1和s2比较，如果s1>s2,输出一个正数；若s1=s2,输出0；若s1<s2,输出一个负数。不要用strcmp函数。两个字符串用gets函数读入。
//     输出正数或负数的绝对值应是比较两个字符串相应字符ASCII码的差值。例如，“A”与“C”相比，由于“A”<“C”，应输出负数，即-2。“And”和“Aid”比较，根据第2个字符比较结果，“n”比“i”大5，应输出“5”。
//     （本题实现strcmp函数，即只比较到第一个相异的字符，而不是比较所有字符计算总差值）
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
    printf("请输入第一个字符串：\n");
    gets(str1);
    printf("请输入第二个字符串：\n");
    gets(str2);
    printf("比较后结果为：\n%d\n",compare(str1,str2));

    return 0;
}
*/

// 15. 编写一个程序，将字符数组s2中的全部字符复制到字符数组s1中。不用strcpy函数。复制时，'\0'也要复制过去。‘\0’后面的字符不复制。

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
    printf("请输入第一个字符串：\n");
    gets(str1);
    printf("请输入第二个字符串：\n");
    gets(str2);
    printf("复制后结果为：\n%s\n",copy(str1,str2));

    return 0;
}
*/
