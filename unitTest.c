#include <stdio.h>
#include <stdlib.h>
#include "stucosys.h"

void showLink(const List *plist)
{
    Node *ptmp = *plist;

    for (ptmp = *plist; ptmp; ptmp = ptmp->pNext) {
        printf("%s, %ld, %d, %s, %s, %ld, %s\n", 
            (ptmp->stuVal).stuName,
            (ptmp->stuVal).stuID,
            (ptmp->stuVal).stuAge,
            (ptmp->stuVal).stuSexual,
            (ptmp->stuVal).stuAddress,
            (ptmp->stuVal).stuMobileNum,
            (ptmp->stuVal).stuDomitory);
    }
}
void showNode(const Node *pNode)
{
    printf("%s, %ld, %d, %s, %s, %ld, %s\n", 
            (pNode->stuVal).stuName,
            (pNode->stuVal).stuID,
            (pNode->stuVal).stuAge,
            (pNode->stuVal).stuSexual,
            (pNode->stuVal).stuAddress,
            (pNode->stuVal).stuMobileNum,
            (pNode->stuVal).stuDomitory);
}
void showStrc(const Stu val)
{
    printf("%s, %ld, %d, %s, %s, %ld, %s\n", 
            val.stuName,
            val.stuID,
            val.stuAge,
            val.stuSexual,
            val.stuAddress,
            val.stuMobileNum,
            val.stuDomitory);
}
int main(int argc, char const *argv[])
{
    // List testLink = NULL;
    List head = NULL;
/*    Stu val1 = {"Lucifer",
            5157101244,
            23,
            "Male",
            "ZhangZhou,FuJian,China",
            18649712787,
            "10A602"};
    Stu val2 = {"王玮俊",5157101243,23,"男","福建省漳州市",18649712787,"四区10A602"};
    addStuVal(val1,&testLink);
    addStuVal(val2,&testLink);
    showLink(&testLink);
    printf("Total %d info\n", countInfo(&testLink));
    // Node tmp = findByID(5157101244,&testLink);
    // showNode(&tmp);
    Stu val3 = {"mod",5157101111,11,"male","Earth",11111111111,"Earth"};
    modifyByNode(5157101243,val3,&testLink);
    showLink(&testLink);
    emptyList(&testLink);*/
    // printf("当前总共有 %d 条数据\n", countInfo(&head));
    printf("当前总共有 %d 条数据\n", countInfo(&head));
    printf("请输入数据(姓名，学号，年龄，性别，住址，电话，宿舍号)：\n");
    Stu tmp;
    scanf("%s%ld%d%s%s%ld%s", 
            tmp.stuName,
            &tmp.stuID,
            &tmp.stuAge,
            tmp.stuSexual,
            tmp.stuAddress,
            &tmp.stuMobileNum,
            tmp.stuDomitory);
    if( addStuVal(tmp,&head) ) printf("添加成功!\n");
    else printf("添加失败!\n");
    // showStrc(tmp);
    printf("当前总共有 %d 条数据\n", countInfo(&head)); 
    showLink(&head);
    emptyList(&head);
    return 0;
}