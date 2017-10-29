#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

// 3. 从键盘输入一个字符串，将其中的小写字母全部转化成大写字母，然后输入到一个磁盘文件"test"中保存，输入的字符串以"!"结束。
/** 由于需要判断字符是否为小写字母，选择逐个字符录入*/
/** 应为fgets需要指定读入字符串长度，当长度未知时一般都逐个字符读入*/
int main()
{
    FILE *fp = NULL;
    if(NULL==(fp=fopen("test.txt","w")))
    {
        printf("open file error");
        exit(0);
    }
    char temp = 0;
    while(temp!='!')
    {
        scanf("%c",&temp);
        if(temp<='z'&&temp>='a')
            temp = temp - 32;
        fputc(temp,fp);
    }
    fclose(fp);
    return 0;
}


// 4. 有两个磁盘文件“A”和“B”，各存放一行字母，今要求把这两个文件中的信息合并(按字母顺排列)，输出到一个新文件“C”中去。

void quick_sort(char *a, int left, int right)
{
    if(right<=left)
        return;

    char temp;
    int i, j;
    i = left;
    j = right;
    char key = a[left];

    while(i<j)
    {
        while(i<j&&a[j]>=key)
            j--;
        while(i<j&&a[i]<=key)
            i++;
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    a[left] = a[i];
    a[i] = key;

    quick_sort(a, left, i-1);
    quick_sort(a, i+1, right);
}

int main()
{
    FILE *pa, *pb, *pc;
    if(NULL==(pa = fopen("A.txt","r"))||NULL==(pb = fopen("B.txt","r"))||NULL==(pc = fopen("C.txt","w")))
    {
        printf("open file error");
        exit(0);
    }
    char temp1[200] = {0};
    char temp2[100] = {0};
    char c = 0;
    int i = 0;
    while(1)
    {
        c = fgetc(pa);
        if(feof(pa))                        // 为了跳出循环，c肯定要取到文件结束符。 为了不把文件结束符 EOF 也写入temp，在向temp写入前加判断条件
            break;
        temp1[i++]= c;
    }

    i = 0;
    c = 0;
    while(1)
    {
        c = fgetc(pb);
        if(c==EOF)                          // 所以也可以用接受字符c来判断，不适用于fgets
            break;
        temp2[i++] = c;
    }

    strcat(temp1, temp2);
    int length = strlen(temp1);
    quick_sort(temp1,0,length-1);           // 快速排序的后两个参数表示第一个元素和最后一元素的下标，所以传入0和length-1
    printf("%s,%d\n",temp1,length);

    fputs(temp1,pc);                        // 整个字符串写入C文件
    fclose(pa);
    fclose(pb);
    fclose(pc);
    return 0;
}


// 5. 有5个学生，每个学生有3门课程的成绩，从键盘输入学生数据(包括学号，姓名，3门课成绩等)，计算出平均成绩，将原有的数据和计算出的平均分数存放在磁盘文件"stud"中。
/** 数据不多，使用结构体数组处理*/

struct Student
{
    int number;
    char name[20];
    double score[3];
    double average;
};

int main()
{
    struct Student stu[5];
    int i = 0;
    printf("请输入学生数据\n");
    for(i=0;i<5;i++)
    {
        printf("---------\n第%d个学生:\n",i+1);
        printf("请输入该学生的学号:");
        scanf("%d",&stu[i].number);
        printf("请输入该学生的姓名:");
        scanf("%s",stu[i].name);
        printf("请输入该学生的三门课成绩:");
        scanf("%lf%lf%lf",&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);

        stu[i].average = (stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3;
    }

    FILE *stud;
    if(NULL==(stud = fopen("stud.txt","w")))
    {
        printf("open file error\n");
        exit(0);
    }

    i = 0;
    for(i=0;i<5;i++)
    {
/*
        fprintf(stud,"number: %d\n",stu[i].number);
        fprintf(stud,"name: %s\n",stu[i].name);
        fprintf(stud,"scores: %lf\t%lf\t%lf\n",stu[i].score[0],stu[i].score[1],stu[i].score[2]);
        fprintf(stud,"average: %lf\n\n",stu[i].average);
*/
        fwrite(&stu[i],sizeof(struct Student),1,stud);      // 由于是成块的数据，有fwrite 读入，以二进制存储
    }

    fclose(stud);
    return 0;
}
// 6. 将第5题“stud”文件中的学生数据，按平均分进行排序处理，将已排序的学生数据存入一个新文件"stud_sort"中。
struct Student
{
    int number;
    char name[20];
    double score[3];
    double average;
};

int main()
{
    struct Student stu[5];
    struct Student temp;
    FILE *stud;
    if(NULL==(stud = fopen("stud.dat","rb")))       // 从stud.dat 读入结构体数据
    {
        printf("open file stud.dat error");
        exit(0);
    }
    int i = 0,  j = 0;
    for(i = 0;i<5; i++)
    {
        fread(&stu[i],sizeof(struct Student),1,stud);
/*
        printf("%d\n",stu[i].number);
        printf("%s\n",stu[i].name);
        printf("%lf,%lf,%lf\n",stu[i].score[0],stu[i].score[1],stu[i].score[2]);
        printf("%lf\n",stu[i].average);
*/
    }

    for(i=0; i<4; i++)                              // 冒泡排序， 可以以结构体为单位传值
    {
        for(j= 0; j<4-i; j++)
            if(stu[j].average>stu[j+1].average)
            {
                temp = stu[j];
                stu[j] = stu[j+1];
                stu[j] = temp;
            }
    }

    FILE *stud_sort;
    if(NULL==(stud_sort = fopen("stud_sort.dat","wb")))       // 写入新文件 stud_sort
    {
        printf("open file stud.dat error");
        exit(0);
    }
    for(i=0; i<5; i++)
        fwrite(&stu[i],sizeof(struct Student), 1, stud_sort);

    fclose(stud);
    fclose(stud_sort);
    return 0;
}

// 7. 将第6题已排序的学生成绩文件进行插入处理。插入一个学生的3门课程成绩，程序先计算新插入学生的平均成绩，然后将它按成绩高低顺序插入，插入后建立一个新文件。
// 8. 将第7题结果仍存入原有的“stu_sort”文件而不另建立新文件。
struct Student{
    int number;
    char name[20];
    double score[3];
    double average;
};

int main()
{
    FILE *stud_sort;
    FILE *stud_new;
    if(NULL==(stud_sort=fopen("stud_sort.dat","rb")))
    {
        printf("open file stud_sort.dat error");
        exit(0);
    }
    if(NULL==(stud_sort=fopen("stud_new.dat","wb")))
    {
        printf("open file stud_new.dat error");
        exit(0);
    }

    struct Stu[6];                                          // 原纪录中包含5个数据，把新增数据放在结构体数组末尾
    int i = 0
    for(i=0; i<5; i++)
        fread(&stu[i],sizeof(struct Student),1, stud_sort);

    printf("输入新增学生的学号:\n");
    scanf("%d",&stu[5].number);
    printf("输入新增学生的姓名:\n");
    scanf("%s",stu[5].name);
    printf("输入新增学生的分数:\n");
    scanf("%lf%lf%lf",&stu[5].score[0],&stu[5].score[2],&stu[5].score[2]);

    stu[5].average = (stu[5].score[0]+stu[5].score[1]+stu[5].score[2])/3;

    for(i=5;i>0;i--)                                        // 把新数据插入到正确的位置
    {
        if(stu[i].average<stu[i-1].average)
        {
            temp = stu[i];
            stu[i] = stu[i-1];
            stu[i-1] = temp;
        }
    }

    for(i=0;i<6;i++)
        fwrite(&stu[i],sizeof(struct Student),1,stud_new);   // 若要存回stud_sort, 打开stud_sort 时应为 rb+, 此行stud_new 改为stud_sort

    fclose(stud_sort);
    fclose(stud_new);
    return 0;
}




// 9. 有一磁盘文件“employee”，内存放职工的数据。每个职工的数据包括职工姓名、职位、性别、年龄、住址、工资、健康状况、文化程度。
//    今要求将职工名、工资的信息单独抽出来新建另一个简明的职工工资文件。
/**先创建磁盘文件，为简单起见，使用fwrite写入二进制文件*/
struct employee{
    char name[20];
    char position[10];
    char gender[6];
    int age;
    char address[50];
    int salary;
    char health[10];
    char education[10];
}em[5];

int main()
{
    FILE * fp;
    if(NULL==(fp=fopen("employee.dat","wb")))
    {
        printf("open file employee error");
        exit(0);
    }

    em[0].age = 25; em[0].salary = 5000; strcyp(em[0].name,"Nedd Stark");strcyp(em[0].position,"lord");strcyp(em[0].gender ,"male");
    strcyp(em[0].address ,"Winter Fell");strcyp(em[0].health ,"dead");strcyp(em[0].education ,"educated");
    em[1].age = 25; em[1].salary = 5000; strcyp(em[1].name,"Tyrion Lannister");strcyp(em[1].position,"hand");strcyp(em[1].gender ,"male");
    strcyp(em[1].address ,"Dragon Stone");strcyp(em[1].health ,"heathy");strcyp(em[1].education ,"educated");
    em[2].age = 25; em[1].salary = 5000; strcyp(em[2].name,"Moutain");strcyp(em[2].position,"guard");strcyp(em[2].gender ,"male");
    strcyp(em[2].address ,"Red Keep");strcyp(em[2].health ,"undead");strcyp(em[2].education ,"unkown");
    em[3].age = 25; em[1].salary = 5000; strcyp(em[3].name,"John Snow");strcyp(em[3].position,"King");strcyp(em[3].gender ,"male");
    strcyp(em[3].address ,"Black castle");strcyp(em[3].health ,"revived");strcyp(em[3].education ,"educated");
    em[4].age = 25; em[1].salary = 5000; strcyp(em[4].name,"Mother of Dragon");strcyp(em[4].position,"queen");strcyp(em[4].gender ,"female");
    strcyp(em[4].address ,"Dragon Stone");strcyp(em[4].health ,"unbrunt");strcyp(em[4].education ,"educated");

    int i;
    for(i=0; i<5; i++)
        fwrite(&em[i],sizeof(struct employee), 1, fp);
    fclose(fp);


}



// 10. 从第9题的"职工工资文件"中删去一个职工的数据，再存回原文件。

// 11. 从键盘输入若干行字符串(每行长度不等)，输入后把它们存储到一磁盘文件中。再从该文件中读入这些数据，将其中小写字母转换成大写字母后在显示屏上输出。
int main()
{
    FILE *fp;
    if(NULL==(fp=fopen("strings.txt","w")))
    {
        printf("open file strings.txt error");
        exit(0);
    }

    char temp[50] = {0};
    char c;
    int t;
    printf("共输入多少行字符串?");
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",temp);
        fprintf(fp,"%s",temp);
    }
    fclose(fp);

    FILE *fp2;
    if(NULL==(fp2=fopen("strings.txt","r")))
    {
        printf("open file strings.txt error");
        exit(0);
    }

    while(1)
    {
        c = fgetc(fp2);
        if(c==EOF)
            break;
        if(c>='a'&&c<='z')
            c = c -32;
        putchar(c);
    }
    fclose(fp);
    return 0;
}
