#include <stdio.h>
#include "ui.h"
#include "stucosys.h"
void showStrc(const Stu val)
{
    printf("%-10s\t\t%-ld\t%-d\t\t%-s\t\t%-s\t%-ld\t%-s\n", 
            val.stuName,
            val.stuID,
            val.stuAge,
            val.stuSexual,
            val.stuAddress,
            val.stuMobileNum,
            val.stuDomitory);
}
void showNode(const Node *pNode)
{
    printf("%-10s\t\t%-ld\t%-d\t\t%-s\t\t%-s\t%-ld\t%-s\n", 
            (pNode->stuVal).stuName,
            (pNode->stuVal).stuID,
            (pNode->stuVal).stuAge,
            (pNode->stuVal).stuSexual,
            (pNode->stuVal).stuAddress,
            (pNode->stuVal).stuMobileNum,
            (pNode->stuVal).stuDomitory);
}
void showLink(const List *plist)
{
    Node *ptmp = *plist;

    for (ptmp = *plist; ptmp; ptmp = ptmp->pNext) {
        printf("%-10s\t\t%-ld\t%-d\t\t%-s\t\t%-s\t%-ld\t%-s\n", 
            (ptmp->stuVal).stuName,
            (ptmp->stuVal).stuID,
            (ptmp->stuVal).stuAge,
            (ptmp->stuVal).stuSexual,
            (ptmp->stuVal).stuAddress,
            (ptmp->stuVal).stuMobileNum,
            (ptmp->stuVal).stuDomitory);
    }
}

void showTitle(List *plist)
{
    printf("\t\t\t\tStudent Infomation Management System\n");
    printf("===========================================================================\n");
    printf("Currently has a total of %d messages.\n", countInfo(plist));    
    printf("1.Add\n");
    printf("2.Modify\n");
    printf("3.Delete\n");
    printf("4.Check\n");
    printf("5.Search\n");
    printf("q.QUIT\n");
}
void addFunc(List *plist)
{
    system("clear");
    Stu tmp;
    printf("Input student info\n");
    printf("Include NAME, ID, AGE, SEXUAL, ADDRESS, MOBILE, DOMITORY\n");
    printf("Separated by SPACE:\n");
    scanf("%s%ld%d%s%s%ld%s", 
            tmp.stuName,
            &tmp.stuID,
            &tmp.stuAge,
            tmp.stuSexual,
            tmp.stuAddress,
            &tmp.stuMobileNum,
            tmp.stuDomitory);
    int state = addStuVal(&tmp,plist);
    if( 1 == state ) {
        system("clear");
        printf("Successed!\n");
        printf("1.Continue\n2.Back\n");
        int ag;
        scanf("%d", &ag);
        if( 1 == ag )
            addFunc(plist);
        if( 2 == ag )
            return;
    }
    if( -1 == state ) {
        system("clear");
        printf("Failed!ID CAN NOT BE THE SAME！\n");
        printf("1.Try again\n2.Back\n");
        int ag;
        scanf("%d", &ag);
        if( 1 == ag )
            addFunc(plist);
        if( 2 == ag )
            return;
    }
}
void modifyFunc(List *plist)
{
    system("clear");
    Stu tmp;
    printf("Input ID you want to mod:\n");
    long int id;
    scanf("%ld", &id);
    Node *tmpNode = findByID(id,plist);
    if( tmpNode == NULL ) {
        system("clear");
        printf("There is no data.\n");
        printf("1.Try agian\n");
        printf("2.Back\n");
        int ag;
        scanf("%d", &ag);
        if( 1 == ag ) 
            modifyFunc(plist);
        if( 2 == ag )
            return;
    } else {
        printf("Here is the information you want to mod:\n");
        printf("%s\t\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", 
            "Name",
            "ID",
            "Age",
            "Sexual",
            "Addr",
            "Mobile",
            "Domitory");
        showNode(tmpNode);
        printf("Are you sure to change it?(y/n)\n");
        char confirm;
        scanf(" %c", &confirm);
        if( 'n' == confirm ) return;
        if( 'y' == confirm ) {
            printf("Input the new information:\n");
            scanf("%s%ld%d%s%s%ld%s", 
                tmp.stuName,
                &tmp.stuID,
                &tmp.stuAge,
                tmp.stuSexual,
                tmp.stuAddress,
                &tmp.stuMobileNum,
                tmp.stuDomitory);
            int state = modifyByNode(id,tmp,plist);
            if( 1 == state ) {
                system("clear");
                printf("Successed\n");
                printf("1.Back\n");
                int ag;
                scanf("%d", &ag);
                if( 1 == ag ) return;
            }
            if( 0 == state ) {
                system("clear");
                printf("Failed\n");
                printf("1.Back\n");
                int ag;
                scanf("%d", &ag);
                if( 1 == ag ) return;
            }
        }
    }
}
void deleteFunc(List *plist)
{
    system("clear");
    printf("Input ID you want to delete:\n");
    long int id;
    scanf("%ld", &id);
    Node *tmpNode = findByID(id,plist);
    if( tmpNode == NULL ) {
        system("clear");
        printf("There is no data.\n");
        printf("1.Try agian\n");
        printf("2.Back\n");
        int ag;
        scanf("%d", &ag);
        if( 1 == ag ) 
            deleteFunc(plist);
        if( 2 == ag )
            return;
    } else {
        printf("Here is the information you want to delete:\n");
        printf("%s\t\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", 
            "Name",
            "ID",
            "Age",
            "Sexual",
            "Addr",
            "Mobile",
            "Domitory");
        showNode(tmpNode);
        printf("Are you sure to delete it?(y/n)\n");
        char confirm;
        scanf(" %c", &confirm);
        if( 'n' == confirm ) return;
        if( 'y' == confirm ) {
            deleteByID(id,plist);
            system("clear");
            printf("Successed!\n");
            printf("1.Back\n");
            int ag;
            scanf("%d", &ag);
            if( 1 == ag ) return;
        }
    }
}
void checkFunc(List *plist)
{
    system("clear");
    if( *plist == NULL ) {
        printf("There is no any data.\n");
    } else {
        printf("%s\t\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", 
            "Name",
            "ID",
            "Age",
            "Sexual",
            "Addr",
            "Mobile",
            "Domitory");
        showLink(plist);
    }
    printf("1.Back\n");
    int ag;
    scanf("%d", &ag);
    if( 1 == ag ) return;
}
void searchFunc(List *plist)
{
    system("clear");
    printf("1.Search by ID\n");
    printf("2.Search by Name\n");
    printf("3.Search by Age\n");
    printf("4.Search by Sexual\n");
    printf("5.Search by Domitory\n");
    printf("6.Bcak\n");
    int input;
    scanf("%d", &input);
    switch( input ) {
        case 1:
            idSearch(plist);
            break;
        case 2:
            nameSearch(plist);
            break;
        case 3:
            ageSearch(plist);
            break;
        case 4:
            sexSearch(plist);
            break;
        case 5:
            domitorySearch(plist);
        case 6:
            break;
    }
}
void idSearch(List *plist)
{
    system("clear");
    printf("Input ID you want to search:\n");
    long int id;
    int state;
    scanf("%ld", &id);
    state = searchByID(id,plist);
    if( 1 == state ) {
        system("clear");
        Node *tmpNode = findByID(id,plist);
        printf("Successed.Here is the data:\n");
        printf("%s\t\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", 
            "Name",
            "ID",
            "Age",
            "Sexual",
            "Addr",
            "Mobile",
            "Domitory");
        showNode(tmpNode);
        printf("1.Back\n");
        int ag;
        scanf("%d", &ag);
        if( 1 == ag ) searchFunc(plist);//return;
    } else if( 0 == state ) {
        system("clear");
        printf("Failed: There is no any data\n");
        printf("1.Back\n");
        int ag;
        scanf("%d", &ag);
        if( 1 == ag ) searchFunc(plist);//return;
    } else if( -1 == state ) {
        system("clear");
        printf("Failed:No match is found\n");
        printf("1.Back\n");
        int ag;
        scanf("%d", &ag);
        if( 1 == ag ) searchFunc(plist);//return;
    }
}
void nameSearch(List *plist)
{
    system("clear");
    printf("Input Name you want to search:\n");
    int state;
    char name[50];
    scanf("%s", name);
    state = searchByName(name,plist);
    if( state >= 1 ) {
        system("clear");
        printf("Successed.Here is the data:\n");
        printf("%s\t\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", 
            "Name",
            "ID",
            "Age",
            "Sexual",
            "Addr",
            "Mobile",
            "Domitory");
        searchByName(name,plist);
        printf("Total find %d info.\n", state);
        printf("1.Back\n");
        int ag;
        scanf("%d", &ag);
        if( 1 == ag ) searchFunc(plist);
    } else if( 0 == state ) {
        system("clear");
        printf("Failed: There is no any data\n");
        printf("1.Back\n");
        int ag;
        scanf("%d", &ag);
        if( 1 == ag ) searchFunc(plist);
    } else if( -1 == state ) {
        system("clear");
        printf("Failed:No match is found\n");
        printf("1.Back\n");
        int ag;
        scanf("%d", &ag);
        if( 1 == ag ) searchFunc(plist);
    }
}
void ageSearch(List *plist)
{
    system("clear");
    printf("Input Age you want to search:\n");
    int age, state;
    scanf("%d", &age);
    state = searchByAge(age,plist);
    if( state >= 1 ) {
        system("clear");
        printf("Successed.Here is the data:\n");
        printf("%s\t\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", 
            "Name",
            "ID",
            "Age",
            "Sexual",
            "Addr",
            "Mobile",
            "Domitory");
        searchByAge(age,plist);
        printf("Total find %d info.\n", state);
        printf("1.Back\n");
        int ag;
        scanf("%d", &ag);
        if( 1 == ag ) searchFunc(plist);
    } else if( 0 == state ) {
        system("clear");
        printf("Failed: There is no any data\n");
        printf("1.Back\n");
        int ag;
        scanf("%d", &ag);
        if( 1 == ag ) searchFunc(plist);
    } else if( -1 == state ) {
        system("clear");
        printf("Failed:No match is found\n");
        printf("1.Back\n");
        int ag;
        scanf("%d", &ag);
        if( 1 == ag ) searchFunc(plist);
    }
}
void sexSearch(List *plist)
{
    system("clear");
    printf("Input Sexual you want to search:\n");
    int state;
    char sexual[10];
    scanf("%s", sexual);
    state = searchBySexual(sexual,plist);
    if( state >= 1 ) {
        system("clear");
        printf("Successed.Here is the data:\n");
        printf("%s\t\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", 
            "Name",
            "ID",
            "Age",
            "Sexual",
            "Addr",
            "Mobile",
            "Domitory");
        searchBySexual(sexual,plist);
        printf("Total find %d info.\n", state);
        printf("1.Back\n");
        int ag;
        scanf("%d", &ag);
        if( 1 == ag ) searchFunc(plist);
    } else if( 0 == state ) {
        system("clear");
        printf("Failed: There is no any data\n");
        printf("1.Back\n");
        int ag;
        scanf("%d", &ag);
        if( 1 == ag ) searchFunc(plist);
    } else if( -1 == state ) {
        system("clear");
        printf("Failed:No match is found\n");
        printf("1.Back\n");
        int ag;
        scanf("%d", &ag);
        if( 1 == ag ) searchFunc(plist);
    }
}
void domitorySearch(List *plist)
{
    system("clear");
    printf("Input Domitory you want to search:\n");
    int state;
    char domitory[50];
    scanf("%s", domitory);
    state = searchByDomitory(domitory,plist);
    if( state >= 1 ) {
        system("clear");
        printf("Successed.Here is the data:\n");
        printf("%s\t\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", 
            "Name",
            "ID",
            "Age",
            "Sexual",
            "Addr",
            "Mobile",
            "Domitory");
        searchByDomitory(domitory,plist);
        printf("Total find %d info.\n", state);
        printf("1.Back\n");
        int ag;
        scanf("%d", &ag);
        if( 1 == ag ) searchFunc(plist);//return;
    } else if( 0 == state ) {
        system("clear");
        printf("Failed: There is no any data\n");
        printf("1.Back\n");
        int ag;
        scanf("%d", &ag);
        if( 1 == ag ) searchFunc(plist);//return;
    } else if( -1 == state ) {
        system("clear");
        printf("Failed:No match is found\n");
        printf("1.Back\n");
        int ag;
        scanf("%d", &ag);
        if( 1 == ag ) searchFunc(plist);//return;
    }
}