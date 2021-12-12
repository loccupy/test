#include <stdlib.h>
#include <stdio.h>
typedef int Data;
typedef struct Node
{
    Data data;
    struct Node * next;
    struct Node * prev;
}Node;
void print(Node * list) // печатать по порядку
{
    Node * p = list -> next;
    while(p != list) 
    {
        printf("%d ", p -> data);
        p = p->next;
    }
    printf("\n");
}
void print_dbg(Node * list)
{
    Node * p = list -> next;
    printf("---------\n");
    printf("list: prev=%p %p next = %p\n",  p->prev, p, p->next);
    printf("---------\n");
    while(p != list)
    {
        printf("%d [prev=%p %p next = %p]\n", p -> data, p->prev, p, p->next);
        p = p->next;
    }
    
}
void print_back(Node * list) // печатать в обратном порядке
{
    Node * p = list -> prev;
    while(p >= list)
    {
        printf("%d ", p -> data);
        p = p->prev;
    }
    printf("\n");
}
void insert(Node * p,Node * t)  //вставляем узел t после узла p
{
    Node * q = p->next; 
    t->prev = p;
    t->next = q;
    p->next = t;
    q->prev = t;
}
void insert_before(Node * q, Node * t) // всталяем узел t перед узлом q
{
    insert(q->prev, t);
}

void list_remove(Node * t)
{
    Node * p = t->prev;
    Node * q = p->next;
    p->next=p;
    q->prev=p;
}

void init(Node * list) // зацикливавем список НА СЕБЕ
{
    list->next=list;
    list->prev=list;
}
int is_empty(Node * list)
{
    return (list->prev == list && list->next == list);
}
int main()
{
    Node z, a, b, c, u, w;
    Node * list = &z;
    z.data = 0;
    a.data = 3;
    b.data = 17;
    c.data = 21;
    u.data = 10;
    w.data = 8;
    // z.next = &a; -- заменяем эту модель на init(Node * list)
    // z.prev = &c; -- заменяем эту модель на init(Node * list)
    // a.next = &b; -- заменяем эту модель на init(Node * list)
    // a.prev = &z; -- заменяем эту модель на init(Node * list)
    // b.next = &c; -- заменяем эту модель на init(Node * list)
    // b.prev = &a; -- заменяем эту модель на init(Node * list)
    // c.next = &z; -- заменяем эту модель на init(Node * list)
    // c.prev = &b; -- заменяем эту модель на init(Node * list)

    init(list);
    // print(list);
    // printf("\n");
    // print_back(list);
    // printf("\n");
    // print_dbg(list);

    printf("Empty %s\n", is_empty(list) ? "yes":"no");
    insert(list, &a); // 3
    print(list);
    printf("Empty %s\n", is_empty(list) ? "yes":"no");

    // insert_before(list, &b); // 3 17
    // print(list);
    // printf("\n");

    // insert_before(list, &c); // 3 17 21
    // print(list);
  //  insert_before(&z, &w);
    
    // print(list);
    // printf("\n");
 //   print_back(list);
  //  printf("\n");
  //  print_dbg(list);
    return 0;
}