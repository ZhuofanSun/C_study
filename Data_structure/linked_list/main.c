#include <stdio.h>
#include <stdlib.h>
// 链表
// head 不放东西，index 从1开始
typedef int E; // int定义成E，element的类型

struct List_Node {
    E element;  //节点元素
    struct List_Node * next;  //指向下一个节点的指针
};

typedef struct  List_Node * Node;//这个node结构体的指针写做Node

void init_linked_list (Node node){
    // 由于这个单链表方法head不存数据，数据从index=1开始存数据，init函数会创造head节点并将next指向null
   node->next = NULL;//next存放下一个node的地址
}

_Bool insert(Node head, E element, int index){
    if(index < 1) return 0;
    Node current_node = head;

    while(--index){//如果想插入的地方是1，不执行。是2，执行1次。3，执行2次.....
        current_node = current_node->next; //结束是current在想插入的前一个
        if(current_node == NULL) return 0; //会空一个或以上是非法的
    }
    //下面这样Node创造的节点指针指向的地址随机分配，函数完成后销毁，所以不能这么用
    /**
    Node node;  //创建新节点
    node->element = element; //新节点存放element
    node->next = current_node->next; // 新节点的next指向index
    current_node->next = node;
    return 1;
    **/

    Node node = malloc(sizeof (struct List_Node)); // 要申请一块地址，创建新的node的指针指向这块地址
    if (node == NULL) return 0; // 判断申请成功了没
    node->element = element; // 新节点存放element
    node->next = current_node->next; // 新节点的next指向curr下一个（就是index）
    current_node->next = node; // curr的下一个指向新节点
    return 1;
}

_Bool delete_list(Node head, int index) {

    if (index < 1) return 0;
    Node current_node = head;

    while (--index) {//如果想删除的地方是1，不执行。是2，执行1次。3，执行2次.....
        current_node = current_node->next; //结束是current在想删除的前一个
        if (current_node == NULL) return 0; //会空一个或以上是非法的
    }
    if (current_node->next == NULL) return 0; //非法删除null

    Node temp = current_node->next; // 需要释放内存所以存一下，要我说不用也行
    current_node->next = current_node->next->next; // curr的下一个改成curr的下一个的下一个，这样第index个就被跳过了
    free(temp);
    return 1;
}

int find_list(Node head, E element){

    int index = 1;
    Node current_node = head->next;

    while(current_node != NULL){//循环结束就是没找到

        if(current_node->element == element) return index; //找到了就返回index
        else {
            current_node = current_node->next; //没找到就下一个
            index ++; //index也下一个
        }
    }
    return -1;

}

int size_list(Node head){//返回长度

    int index = 0;//从head开始，第零个
    Node current_node = head;

    while(current_node->next != NULL){ //下一个是空结束循环

        current_node = current_node->next;
        index ++;
    }

    return index;
}

void del_repeated_element(Node head){
    //在已排序的链表中删除重复元素，
    //已排序说明重复元素都是挨着的
    Node curr_node = head->next;
    int i = 1;
    while(curr_node != NULL) {

        if (curr_node->next == NULL) return;//最后一个
        if(curr_node->next->element == curr_node->element) delete_list(head, i + 1);//找到了捏
        else {

            curr_node = curr_node->next;
            i++;

        }

    }

}

void reverse_list(Node head){

    Node curr_node = head->next;
    for (int i = 1; i < size_list(head); ++i) {//从第二个开始插入到第一个，每次插入后删除后面的

        insert(head,curr_node->next->element,1);
        delete_list(head,i+2);

    }

}

void append(Node head, E element){


    insert(head, element, size_list(head) + 1);//

}

void add(Node head, E element){

    insert(head, element, 1);//在第一位插入

}



void printList(Node head){
    while (head->next) {
        head = head->next;
        printf("%d ", head->element);   //因为头结点不存放数据，所以从第二个开始打印
    }
}

int main() {
    struct List_Node head;
    init_linked_list(&head); // 输入  的是地址，会以指针接收
    for (int i = 1; i < 4; ++i) {
        insert(&head, i * 100, i);   //依次插入3个元素
    }
    printList(&head);   //打印一下看看

    printf("\n\n");
    delete_list(&head, 3);//删除第3个
    printList(&head);

    printf("\n\n");
    printf("%d", find_list(&head, 100));//找100

    printf("\n\n");
    printf("%d", size_list(&head));

    printf("\n\n");
    printf("%d", size_list(&head));

    printf("\n\n");
    insert(&head, 200, size_list(&head) + 1);
    insert(&head, 200, size_list(&head) + 1);
    insert(&head, 300, size_list(&head) + 1);
    insert(&head, 300, size_list(&head) + 1);
    insert(&head, 300, size_list(&head) + 1);
    insert(&head, 400, size_list(&head) + 1);
    printList(&head);
    printf("\n");
    del_repeated_element(&head);
    printList(&head);

    printf("\n\n");
    reverse_list(&head);
    printList(&head);

    printf("\n\n");
    append(&head, 111);
    printList(&head);

    printf("\n\n");
    add(&head, 500);
    printList(&head);

    printf("\n\n");
    reverse_list(&head);
    printList(&head);

}
