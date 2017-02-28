#ifndef STUCOSYS_H__
#define STUCOSYS_H__
#include <stdbool.h>
// 学生信息结构体
typedef struct _student {
   char stuName[50];
   long stuID;
   int  stuAge;
   char stuSexual[10];
   char stuAddress[200];
   long stuMobileNum;
   char stuDomitory[50];
} Stu;
// 节点结构体，包含学生信息，和指向下一个节点的指针
typedef struct _node {
    // int id;
    Stu stuVal;
    struct _node *pNext;
} Node;
// 链表
typedef Node* List;
// 添加信息
int addStuVal(Stu *val, List *plist);
// 清空链表
void emptyList(List *plist);
// 判断链表是否为空
bool isEmpty(const List *plist);
// 通过学号删除整个节点
void deleteByID(const long ID, List *plist);
// 统计所有信息数目
int countInfo(const List *plist);
// 通过ID修改节点信息
int modifyByNode(const long ID, Stu modVal, List *plist);
// ------- Search
// 通过ID查找节点
Node* findByID(const long ID, const List *plist);
// 按学号查找
int searchByID(const long ID, const List *plist);
// 按姓名查找
int searchByName(const char Name[], const List *plist);
// 按年龄查找
int searchByAge(const int Age, const List *plist);
// 按性别查找
int searchBySexual(const char Sexual[], const List *plist);
// 按宿舍查找
int searchByDomitory(const char Domitory[], const List *plist);
#endif