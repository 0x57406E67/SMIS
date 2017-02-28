#include <stdio.h>
#include "stucosys.h"
#include "ui.h"
// List head = NULL;
Stu tmp1 = {"Lucifer",5157101244,23,"Male","Fujian,China",18649712787,"10A602"};
Stu tmp2 = {"wwj",5157101241,23,"Male","Fujian,China",18649712787,"10A602"};
Stu tmp3 = {"xlwensda",5157101242,23,"Male","Fujian,China",18649712787,"10A602"};
Stu tmp4 = {"Lucxsdf",5157101243,23,"Male","Fujian,China",18649712787,"10A602"};
void saveLink(const List *plist)
{
    Node *scan = *plist;
    FILE *p = fopen("data.dt","w");
    if( p == NULL ){
        return;
    }
    fprintf(p,"%s\t\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", 
            "Name",
            "ID",
            "Age",
            "Sexual",
            "Addr",
            "Mobile",
            "Domitory");
    while(scan){
        fprintf(p, "%-10s\t\t", scan->stuVal.stuName);
        fprintf(p, "%-ld\t", scan->stuVal.stuID);
        fprintf(p, "%-d\t\t", scan->stuVal.stuAge);
        fprintf(p, "%-s\t\t", scan->stuVal.stuSexual);
        fprintf(p, "%-s\t", scan->stuVal.stuAddress);
        fprintf(p, "%-ld\t", scan->stuVal.stuMobileNum);
        fprintf(p, "%-s\n", scan->stuVal.stuDomitory);
        scan = scan->pNext;
    }
    fclose(p);
}
int main(int argc, char const *argv[])
{
    List head = NULL;
    addStuVal(&tmp1,&head);
    addStuVal(&tmp2,&head);
    addStuVal(&tmp3,&head);
    addStuVal(&tmp4,&head);
    int flag = 1;
    while( flag ) {
        system("clear");
        showTitle(&head);
        char input;
        /*
         * C Primer Pluc P81
         * %c前面加空格，scanf()会跳到第一个非空白的字符。
         */
        scanf(" %c", &input);
        switch( input ) {
            case '1':
                addFunc(&head);
                break;
            case '2':
                modifyFunc(&head);
                break;
            case '3':
                deleteFunc(&head);
                break;
            case '4':
                checkFunc(&head);
                break;
            case '5':
                searchFunc(&head);
                break;
            case 'q':
                flag = 0;
                break;
            default:
                printf("Error operator!\n");
                break;
        }
    }
    saveLink(&head);
    emptyList(&head);
    system("clear");
    return 0;
}