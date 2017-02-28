#ifndef UI_H__
#define UI_H__
#include "stucosys.h"
void showStrc(const Stu val);
void showNode(const Node *pNode);
void showLink(const List *plist);

void showTitle(List *plist);
void addFunc(List *plist);
void modifyFunc(List *plist);
void deleteFunc(List *plist);
void checkFunc(List *plist);
void searchFunc(List *plist);
void idSearch(List *plist);
void nameSearch(List *plist);
void ageSearch(List *plist);
void sexSearch(List *plist);
void domitorySearch(List *plist);
#endif