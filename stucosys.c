#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memcmp() strcmp()
#include "stucosys.h"
int addStuVal(Stu *val, List *plist)
{
    Node *scan = *plist;
    Node *pnew = (Node*) malloc (sizeof(Node));
    if( pnew == NULL ) {
        return 0; // 返回0，分配内存失败，则显示添加失败
    }
    //---判断学号是否已存在
    Node *check = *plist;
    while( check ) { //遍历链表
        if( check->stuVal.stuID == val->stuID )
            return -1; //如果链表内存在相同的学号，则返回-1，显示学号不能相同
        else
            check = check->pNext;
    }
    //---
    (pnew->stuVal) = *val;
    pnew->pNext = NULL;
    if( scan ) {
        while( scan->pNext ) {
            scan = scan->pNext;
        }
        scan->pNext = pnew;
    } else {
        *plist = pnew;
    }
    return 1; // 返回1，添加成功
}
void emptyList(List *plist)
{
    Node *psave;
    while( *plist ) {
        psave = (*plist)->pNext;
        free(*plist);
        *plist = psave;
    }
}
bool isEmpty(const List *plist)
{
    if( *plist == NULL )
        return true;
    else
        return false;
}
void deleteByID(const long ID, List *plist)
{
    Node *p,*q;
    for(q = NULL, p = *plist; p; q = p, p = p->pNext) {
        if( p->stuVal.stuID == ID ) {
            if( q )
                q->pNext = p->pNext;
            else
                *plist = p->pNext;
            free(p);
            break;
        }
    }
}
int countInfo(const List *plist)
{
    Node *ptmp = *plist;
    unsigned int count = 0;
    while( ptmp ) {
        ++count;
        ptmp = ptmp->pNext;
    }
    return count;
}

int modifyByNode(const long ID, Stu modVal, List *plist)
{
    Node *scan = *plist;
    if( scan == NULL ) return 0;
    while( scan ) {
        if( scan->stuVal.stuID == ID ) {
            scan->stuVal = modVal;
            return 1;
        }
        else
            scan = scan->pNext;
    }
}

Node* findByID(const long ID, const List *plist)
{
    Node *scan = *plist;
    while( scan ) {
        if( scan->stuVal.stuID == ID )
            return scan;
        else
            scan = scan->pNext;
        // 如果没找到，返回NULL。
        if( scan == NULL ) return NULL;
    }
}
int searchByID(const long ID, const List *plist)
{
    Node *scan = *plist;
    if( *plist == NULL ) return 0; // 链表为空，返回0，显示当前没有任何数据
    while( scan ) {
        if( scan->stuVal.stuID == ID )
            return 1; // 找到匹配，返回1，表示成功
        else
            scan = scan->pNext;
        if( scan == NULL ) return -1; // 没找到匹配，返回-1
    }
}

int searchByName(const char Name[], const List *plist)
{
    Node *scan = *plist;
    int count = 0;
    if( *plist == NULL ) return 0; // 链表为空，返回0，显示当前没有任何数据
    while( scan ) {
        if( 0 == strcmp(scan->stuVal.stuName,Name) ) {
            showNode(scan);
            count++;
            scan = scan->pNext;
        }
        else
            scan = scan->pNext;
        if( scan == NULL && 0 != count ) return count; // 返回找到的个数
        if( scan == NULL && 0 == count ) return -1; // 没找到匹配，返回-1
    }
}

int searchByAge(const int Age, const List *plist)
{
    Node *scan = *plist;
    int count = 0;
    if( *plist == NULL ) return 0; // 链表为空，返回0，显示当前没有任何数据
    while( scan ) {
        if( scan->stuVal.stuAge == Age ) {
            showNode(scan);
            count++;
            scan = scan->pNext;
        }
        else
            scan = scan->pNext;
        if( scan == NULL && 0 != count ) return count; // 返回找到的个数
        if( scan == NULL && 0 == count ) return -1; // 没找到匹配，返回-1
    }
}

int searchBySexual(const char Sexual[], const List *plist)
{
    Node *scan = *plist;
    int count = 0;
    if( *plist == NULL ) return 0; // 链表为空，返回0，显示当前没有任何数据
    while( scan ) {
        if( 0 == strcmp(scan->stuVal.stuSexual,Sexual) ) {
            showNode(scan);
            count++;
            scan = scan->pNext;
        }
        else
            scan = scan->pNext;
        if( scan == NULL && 0 != count ) return count; // 返回找到的个数
        if( scan == NULL && 0 == count ) return -1; // 没找到匹配，返回-1
    }
}

int searchByDomitory(const char Domitory[], const List *plist)
{
    Node *scan = *plist;
    int count = 0;
    if( *plist == NULL ) return 0; // 链表为空，返回0，显示当前没有任何数据
    while( scan ) {
        if( 0 == strcmp(scan->stuVal.stuDomitory,Domitory) ) {
            showNode(scan);
            count++;
            scan = scan->pNext;
        }
        else
            scan = scan->pNext;
        if( scan == NULL && 0 != count ) return count; // 返回找到的个数
        if( scan == NULL && 0 == count ) return -1; // 没找到匹配，返回-1
    }
}