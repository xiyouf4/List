// 带有头结点的链表库
#ifndef _List_H
#define _List_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

// 初始化一个带头结点的链表
List MakeEmpty(List L, int len);
// 判断当前结点是不是尾结点
int IsLast(Position P, List L);
// 判断当前链表是不是为空
int IsEmpty(List L);
// 获得一个新的结点
Position MallocNode(Position P);
// 找到数据为x的第一个结点
Position Find(int x, List L);
// 找到数据为x的结点的直接前驱
Position FindPrevious(int x, List L);
// 删除数据为x的结点
int Delete(int x, List L);
// 获得尾结点
Position Last(List L);
// 插入新的结点在尾部
void InsertLast(Position P, List L);
// 插入一个新的结点在数据为x的元素前
int Insert(int x, Position P, List L);
// 销毁链表
void DeleteList(List L);

#endif
