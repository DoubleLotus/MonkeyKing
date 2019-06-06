#ifndef _MONKEYFUN_H_
#define _MONKEYFUN_H_

struct person
{ 
    int num;
    struct person *next;
};

struct person *constructlink(int n);  //返回循环链表头指针

int ShowData(struct person  *pHead);  //给出头指针

// pre---->cur
void deletenode(struct person *pre, struct person *cur);

#endif
