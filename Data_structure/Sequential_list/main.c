#include <stdio.h>
#include <stdlib.h>
/**
 * 线性表一般需要包含以下功能：
** 这里顺序表从1开始，第一个第二个....
**初始化线性表：**将一个线性表进行初始化，得到一个全新的线性表。
**获取指定位置上的元素：**直接获取线性表指定位置i上的元素。
**获取元素的位置：**获取某个元素在线性表上的位置i。
**插入元素：**在指定位置i上插入一个元素。
**删除元素：**删除指定位置i上的一个元素。
**获取长度：**返回线性表的长度。
 */
typedef int E;  // 给int取个别名叫E，element的意思

struct List { //  创建一个结构体
    //E array[10];  //长度为10 的数组
    //改成内存空间地址，大小取决于容量和类型，用malloc申请空间
    E * array;
    int capacity; //容量
    int size;
};
typedef struct List * Array_list;  // 把这个结构体的指针定义为Array_list，要不太长了

_Bool init_list(Array_list list){  //结构体作为参数存进来要用指针，否则只会传递值，不能改变内容
    list -> array = malloc(sizeof(int) * (list -> capacity));  // array 指向长度为capacity的首元素，也就是数组
    if (list -> array == NULL) return 0;//判断申请成功没有，内存不足就会失败，返回NULL
    list -> capacity = 10;// 或者:   （*list).capacity = 10;
    list -> size = 0;
    return 1;
}

_Bool insert_list(Array_list list, E element, int index){
    if(list->size == list->capacity){ // 满了就要扩展储存空间

        int new_capacity = list->capacity * 2;//新的储存空间大小
        E * new_array = realloc(list->array, sizeof(E) * new_capacity);
        //realloc可以控制动态内存开辟的大小，其实是重新开辟一块新的空间，并且把原来地址上个所有数据按顺序拷贝上去
        if (new_array == NULL) return 0;  //因为后面的内存可能已经给了别的数据，可能扩展失败
        list->array = new_array;//替换地址
        list->capacity = new_capacity;//替换储存空间

    }

    if (list->size == 0) {

        list->array[0] = element;
        list->size ++;
        return 1;

    }
    for (int i = list->size - 1; i > index - 1 ; --i) //从size - 1 到index
        list->array[i] = list->array [i+1];//从最后一个元素开始到index向右移动一位
    list->array[index] = element;//index空了，所以可以把element放到index上
    list->size += 1;
    return 1;
}


_Bool delete_element(Array_list list, int index){

    if(index < 0 || index >= list->size) return 0;
    for (int i = index;i < list->size - 1; ++i) {
        list->array[i] = list->array[i + 1];
    }
    list->size --;
    return 1;

}

int get_size(Array_list list){
    return list->size;
}


E * get_element(Array_list list, int index){
    if(index < 1 || index >= list->size) return NULL;
    return &list->array[index];

}


int findList(Array_list list, E element){
    for (int i = 0; i < list->size; ++i) {
        if(list->array[i] == element) return i + 1;
    }
    return -1;
}





void printList(Array_list list){   //编写一个函数用于打印表当前的数据
    for (int i = 0; i < list->size; ++i)   //表里面每个元素都拿出来打印一次
        printf("%d  ", list->array[i]);
    printf("\n");
}

int main() {
    struct List list;
    init_list(&list);
    for (int i = 0; i < 30; ++i) {
        if (insert_list(&list,i,i)) printList(&list);
        else printf("shit");

    }
    printf("\n\n");
    printList(&list);
    delete_element(&list, 10);
    printList(&list);
    printf("capacity is: %d", list.capacity);

    printf("\n\n");
    printf("index 3: %d", *get_element(&list, 3));

    printf("\n\n");
    printf("find 20: %d", findList(&list,20));

    printf("\n\n");
    printf("size is: %d", get_size(&list));
    }


    /**
    int * p = malloc(sizeof(int) * 3);
    *(p + 1) = 2;  //内存操作法
    p[0] = 1;  // 数组操作法
    p[2] = 3;
    for (int i = 0; i < 4; ++i) {
        printf("%d  ", p[i]);
        **/






