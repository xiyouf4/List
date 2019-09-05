#ifndef _List_H
#define _List_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

// 创建一个带有一个结点的链表
List MakeEmpty(List L);
// 判断链表是不是空表
int IsEmpty(List L);
// 判断当前位置是不是表头
int IsHead(Position P, List L);
// 判断当前位置是不是末尾
int IsLast(Position P, List L);
// 找到数据元素为x的结点
Position Find(int x, List L);
// 找到数据元素为x的直接前驱
Position FindPrevious(int x, List L);
// 删除数据元素为x的结点
int Delete(int x, List L);
// 在数据元素为x的结点前添加一个结点
int Insert(int x, Position P, List L);
// 在尾部添加一个结点
void InsertLast(Position P, List L);
// 获取一个新节点
Position MallocNode(Position P);
// 获取尾结点
Position FindLast(List L);
// 销毁链表
void DeleteList(List L);

#endif
