#include <malloc.h>
#include <stdio.h>

#include "monkeyFun.h"

struct person *constructlink(int n)  //返回循环链表头指针
{
	int i;
    struct person *p=NULL, *q=NULL, *head;
    for(i=0; i<n; i++)
    {        
        p = (struct person *)malloc(sizeof(struct person));
        p->num = i+1;
        if(NULL != q)
            q->next = p;
        else
            head = p;
        q=p;
    }
    q->next = head;  //如果用非循环链表则q->next=NULL;
    return head;
}


int ShowData(struct person  *pHead)  //给出头指针
{
	struct person  *pNode;//用于遍历的指针变量
	if (pHead == NULL) 
 	    return -1;

	pNode = pHead;				//从第一个元素开始
	do
	{
		  printf ("%d--->", pNode->num);	//对每个结点出输出信息
		  pNode = pNode->next;			//准备处理下一个结点
	}while (pNode != pHead);			//判断当前结点是否为第一个节点

	printf ("\n");

	return 1;
}

// pre---->cur
void deletenode(struct person *pre, struct person *cur)
{
	pre->next = cur->next;
	free(cur);
	cur = NULL;
	return;
}
