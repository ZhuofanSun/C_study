#include <stdio.h>
#include <string.h>
#include <stdlib.h> // standard library
#include "test.h"
/**

void test(){
    static int a = 0;  // 静态执行完毕后不会删除变量，而是保留
    a += 10;
    printf("%d\n", a);
}
void swap(int,int);
int quanjubianliang = 0;
int sum(int,int);

int main() {
    int a = 5;
    int b = 4;
    swap(a , b);  //在函数里只是赋值过去了，并不会改变局部变量的值
    printf("a 是 %d    b是  %d\n", a , b);
    test();
    test();
    int s = sum(5,7) * 2;
    printf("(5 + 7) * 2 = %d\n", s);
}


void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;

}

int sum(int a,int b){
    int s = a+b;
    return s;

}


**/
/**
// 从一个数组里返回第一个小于0的数字，并且返回
// 没有就返回0
int findMin(int arr[], int len);   //需要两个参数，一个是数组本身，还有一个是数组的长度

int main() {
    int arr[] = {1, 4, -9, 2, -4, 7};
    int min = findMin(arr, 6);
    printf("第一个小于0的数是：%d", min);
}

int findMin(int arr[], t len) {in
    for (int i = 0; i < len; ++i) {
        if(arr[i] < 0) return arr[i];   //当判断找到后，直接return返回即可，这样的话函数会直接返回结果，无论后面还有没有代码没有执行完，整个函数都会直接结束。
    }
    return 0;   //如果没有找到就返回0
}

**/

/**

int mod(int i, int j){
    if (i < j) {
        return i;
    }
    else{
        mod(i -= j, j);

    }
}
int main(){
    int i = 100;
    int j = 6;
    printf("%d", mod(i, j));
}
**/
/**
int factorial_times(int i){
    if(i <= 1){
        return i;
    }
    else{
        return factorial_times(i - 1) * i;
    }

}

int main(){
    int i = 6;
    printf("%d", factorial_times(i));
}
**/
/**
void move(char from, char to, int num){
    printf("第%d个圆盘： 从 %c ---> %c\n", num, from, to);
}
//fst_rod 是初始柱子， snd_rod 是存放柱子， thd_rod是目标柱子, num是要从第一个到第三个柱子移动的圆盘数
void hannuo(char fst_rod, char snd_rod, char thd_rod, int num){
    if (num == 1){
        move(fst_rod, thd_rod, num);

    }
    else{
        hannuo(fst_rod, thd_rod, snd_rod, num - 1);
        move(fst_rod, thd_rod, num);
        hannuo(snd_rod, fst_rod, thd_rod, num - 1);
    }
}
int main(){
    hannuo('A', 'B', 'C', 3);
}
 **/















/**
void swap(int *fst, int *snd);

int main(){

    int a = 10;
    //指针类型需要与变量的类型相同，且后面需要添加一个*符号（注意这里不是乘法运算）表示是对于类型的指针
    int * p = &a;   //这里的&并不是进行按位与运算，而是取地址操作，也就是拿到变量a的地址 系统随机分配地址
    printf("a在内存中的地址为：%p\n", p);  //地址使用%p表示
    printf("内存%p 上存储的值为：%d\n", p, *p);   //我们可以在指针变量前添加一个*号（间接运算符，也可以叫做解引用运算符）来获取对应地址存储的值
    *p = 666;
    printf("内存是 %p 上储存的变量是: %d\n", p, *p);
    int b = 20;
    printf("a is %d, b is %d\n", a, b);
    swap(&a, &b);
    printf("a is %d, b is %d\n", a, b);
    printf("------------------------------------------------------------------\n");

        char str[] = "Hello World!";
        char * ps = str;   // str 储存的地址是第一个元素的地址， 所以*ps储存的是H的地址

        printf("%c\n", *ps);

    printf("%c\n", ps[3]);  // 间接运算符
    printf("第一个字符是 %c, 第二个是 %c\n", *ps, *(ps + 1)); // *（p+1）是加数组里一个元素类型占据的内存长度
    // 和p[1] 一样
    printf("%c\n", * ps + 1);
    /**
     * *p   //数组的第一个元素
ps   //数组的第一个元素的地址
ps == str   //肯定是真，因为都是数组首元素地址
*str    //因为str就是首元素的地址，所以这里对地址加*就代表第一个元素，使用的是指针表示法
&str[0]   //这里得到的实际上还是首元素的地址
*(ps + 1)   //代表第二个元素
ps + 1    //第二个元素的内存地址
*ps + 1    //注意*的优先级比+要高，所以这里代表的是首元素的值+1，得到字符'I'
     *



    int arr[2][3] = {{1,2,3},{4,5,6}};
    int *q = arr[0];
    printf("想要输出 4：  %d == %d\n", *(q + 3), arr[1][0]);

        int z = 20;
        int * pp = &z;   //指向普通变量的指针
        //因为现在要指向一个int *类型的变量，所以类型为int* 再加一个*
        int ** ppp = &pp;   //指向指针的指针（二级指针）
        int *** pppp = &ppp;   //指向指针的指针的指针（三级指针）
    printf("%d\n", ***pppp);


    printf("------------------------------\n");
    printf("数组指针\n");
     int arrrr[3] = {1,2,3};
     int (*pq)[3] = &arrrr;//这个长度为3的数组指针指向的是这个数组的首元素地址的地址，首元素代表整个数组，(*p)[1] 就是数组里第二个元素
    int *pqq = arrrr;// 这个指针指向的是数组第一个元素的地址，*(p+1)就是数组里第二个元素。
    printf("%d\n", (*pq)[1]); // *pq 这个数组指针
    printf("%d, %d, %d\n", *(*pq+0),*(*pq + 1) , *(*pq + 2));// *pq 就是首元素的地址，**pq就是首元素
    printf("%d\n",*(pqq+1)); //这里pqq就是首元素地址，*pqq是首元素


    int strr[2][3] = {{1,2,3,},{4,5,6}};
    int (*p_str)[3] = strr;
    printf("最后一个元素：%d\n", *(*(p_str+1)+2)); //里面跳到第二个数组，外面是跳到第二个数组的第三个元素
    printf("另一种表达方式：%d\n", p_str[1][2]);



}

void swap(int * fst, int * snd){
    int temp = *fst;
    *fst = *snd;
    *snd = temp;




}

**/







/**
    struct Student{  // 使用（struct关键字+结构体类型名称） 来声明结构体类型，这种类型那个是我们自己创建的
        // （同时也可以作为函数的参数、返回值之类的）
        int id; // 结构体中可以包含多个不同类型的数据，这些数据共同组成了整个结构体类型（当然结构体内部也可能包含结构体类型的变量）
        int age;
        char * name;//用户名可以用指针指向一个字符串，也可以用char数组来存，如果是指针的话，
        // 那么数据不会存在结构体中，只会存放字符串的地址，但是如果是数组的话，数据会存放在结构体中


    };
    struct test{
        int b;
        int c;
        char a;
        int d;
    };


int main(){
    struct Student student = {1,18,"傻逼"};
   int a = student.age;
    printf("%d\n",a);
   student.age = 17;
    printf("%d\n",student.age);
    printf("计算占的内存大小\n");
    printf("\n\n");



    printf("%lu\n",sizeof (a));//就是上面定义的a是int类型，占四个字节
    int arr[10];
    printf("%lu\n",sizeof(arr));//一个int占4字节，这个数组十个int就是40


    printf("%lu\n", sizeof(struct test)); //char int short

    /**
    结构体中的各个数据要求字节对齐，规则如下：
    **规则一：**结构体中元素按照定义顺序依次置于内存中，但并不是紧密排列的。从结构体首地址开始依次将元素放入内存时，元素会被放置在其自身对齐大小的整数倍地址上（0默认是所有大小的整数倍）
    **规则二：**如果结构体大小不是所有元素中最大对齐大小的整数倍，则结构体对齐到最大元素对齐大小的整数倍，填充空间放置到结构体末尾。
    **规则三：**基本数据类型的对齐大小为其自身的大小，结构体数据类型的对齐大小为其元素中最大对齐大小元素的对齐大小。





    printf("\n\n\n");
    struct Student arrr[] = {
            {1, 18,"xiaoming"},
            {2,17,"xiaohong"},
            {3,18,"xiaogang"}
    }; //结构组数组
    printf("%s\n",arrr[1].name);

    struct Student * p = &student;//结构组指针
    printf("%s\n",(*p).name);
    printf("%D",p->age);



}


**/










/**
int main(){
union Object {
    int a;
    short b;
    char c;
};
    union Object object;
    object.a = 30;
    printf("%d\n",object.a);
    printf("%d\n",object.b);
    printf("%d\n", object.c);
    printf("%lu\n",sizeof (union Object)); //联合体的大小就是最大的数据类型的大小
    printf("\n\n\n");


enum Status {
    low , middle = 2, high
};

enum Status status = high;
enum Status status1 = low;
    printf("%d\n", status);//默认没有初始值：low =0, middle=1, high=2
    //如果给了一个初始值，以后每个加一
    printf("%d\n", status1);




    typedef int zhengshu;
    zhengshu i = 10;
    printf("%d", i);
}


**/
/**
int main(){
    printf("Hello world.\n"); //定义这个函数的源文件是<stdio.h>
    // #include 就是引入的意思。引入了stdio.h才能使用printf
    int c = sum(20,30);//引入自test.h
    printf("%d\n",c);

    char  a[20] = "Hello ", * b = "world";

    strcat(a, b);  //前面的必须装得下后面的，改的是a，a的长度要能装的下b
    printf("%s\n", a);
    strcpy(a, b);//把b拷贝到a里去
    printf("%s\n",a);
    char * a1 = "AAA",* b1 = "AAB";
    int value = strcmp(a1,b1);//从头开始逐个比较两个字符串，知道某个字符不相同或者其中一个字符串比较完毕才停止比较，
    // 字符的比较按照ascii码的大小进行判断。比较完成后，会返回不匹配的两个字符的ascii之差
    printf("%d\n", value);
    printf("宏\n\n");
# define M (aaa + bbb)
    int aaa = 10, bbb = 20;
    printf("%d\n", M * aaa);
# define MUL(x) x*x // 替换x
    printf("%d\n", MUL(9));
# define TEST(n) x##n  //会把x和接收到的n拼接
    int x1 = 10;
    printf("%d\n", TEST(1));
# undef PI
    printf("PI\n");

    printf("%s\n", __DATE__);
    printf("%s\n", __TIME__);
    printf("%s\n", __FILE__);
#ifdef PI//如果PI被定义了
#define MM = 111//定义M
#else//没定义PI
#define MM  999 //定义M
    //结束判定
# endif

#ifndef PI//如果PI没有被定义
#define MMM = 999
#endif
}
 **/

/**
int compare(const void * a,const void * b){// 参数为两个待比较的元素，返回值负数表示a比b小，整数表示a比b大，0表示相等
    //直接返回a-b就行了，但要类型转换成int
    int * x = (int *)a, * y = (int *)b;//强制类型转换
    return *x - *y;

}

int main(){
    int arr[] = {5,2,4,0,7,3,8,1,9,6};
    // 待排序数组，待排序的数量（一开始就是数组长度），元素大小(几个字节），排序规则（函数实现）
    //void	 qsort(void *__base, size_t __nel, size_t __width,
    //	    int (* _Nonnull __compar)(const void *, const void *));
    //void * 也就是void指针可以接受任何类型的数据地址，因为不知道数据类型所以要引入数据大小
    qsort(arr, 10, sizeof (int), compare );
    for (int i = 0; i < 10; ++i) {
        printf("%d  ", arr[i]);
    }

}
 **/

/*
int main(){
    //malloc 函数来动态申请内存空间
    //也就是用这个函数返回一个指向这块空间的地址，用指针接受
    char ** i = malloc(sizeof (char) * 30); //几个什么类型的空间
    *i = "this is a test";
    printf("%s\n", *i);
    free(i); //用完需要释放内存，并不会用储存空间
    i = NULL;//不用i指针了，指向空

}
*/
int main(){

    printf("%lu", sizeof (int));

}
