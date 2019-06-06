#include <stdio.h>
#include <malloc.h>
#include "monkeyFun.h"

int main()
{
    //声明变量
    struct person *head, *pre;
    int n, m, k, count=0, i;

    //获取参数  k>=1
    printf("input the number n,m,k:");
    scanf("%d%d%d",&n, &m, &k);

    //初始化链表
    head = constructlink(n);
	
	//最初的状态
	printf("The begining status of the link:\n");
	ShowData(head);

    //找到编号为m的人
    for (i=0;i<m-1;i++){
        head = head->next;
    }
	
	printf("The status of the link after finding the No. %d monkey :\n", m);
	ShowData(head);
		
	//开始选大王
    do{
		count++;  //报数
		pre = head;
		head=head->next;
		
		//找到报数为k的人
        if(count == k-1)
        {
			printf("The status of the link after deleting the No. %d monkey. \n",head->num);
			deletenode(pre, head);   //delete node head
			count = 0; //重新报数
			head=pre->next;
			ShowData(head);
        }
    }while(head->next!=head);

    //输出结果
    printf(" the king is: %4d ",head->num);
    free(head);
	head=NULL;
}
