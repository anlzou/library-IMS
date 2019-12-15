//#include "LibraryClerk.h"
//#include "PrintfData.cpp"
//#include "Page.c"
//#include "FileIo.c"
//int CensusAll=2;
//读取文件创建单链表 
char Uppercase(char *str)
{

      char ch;
      int n, tmp;
      tmp=(unsigned char)str[0]*256+(unsigned char)str[1];
      if(tmp >= 45217 && tmp <= 45252) ch='A'; 
      else if(tmp >= 45253 && tmp <= 45760) ch='B'; 
      else if(tmp >= 45761 &&  tmp <= 46317) ch='C';
      else if(tmp >= 46318 && tmp <= 46825) ch='D'; 
      else if(tmp >= 46826 && tmp <= 47009) ch='E';
      else if(tmp >= 47010 && tmp <= 47296) ch='F';
      else if(tmp >= 47297 && tmp <= 47613) ch='G';
      else if(tmp >= 47614 && tmp <= 48118) ch='H'; 
      else if(tmp >= 48119 && tmp <= 49061) ch='J'; 
      else if(tmp >= 49062  && tmp <= 49323) ch='K'; 
      else if(tmp >= 49324 && tmp <= 49895) ch='L';
      else if(tmp >= 49896 &&tmp <=  50370) ch='M';
      else if(tmp >= 50371 && tmp <= 50613) ch='N';
      else if(tmp >= 50614 && tmp <= 50621) ch='O';
      else if(tmp >= 50622 && tmp <= 50905) ch='P';
      else if(tmp >= 50906 && tmp <= 51386) ch='Q';
      else if(tmp >= 51387 && tmp <= 51445) ch='R';
      else if(tmp >= 51446 && tmp <= 52217) ch='S';
      else if(tmp >= 52218 && tmp  <= 52697) ch='T';
      else if(tmp >= 52698 && tmp <= 52979) ch='W';
      else if(tmp >= 52980 && tmp <= 53640) ch='X';
      else if(tmp >= 53689 && tmp <=  54480) ch='Y';
      else if(tmp >= 54481 && tmp <= 55289) ch='Z';
      else ch=' '; 
      n=ch;
      return n;
}

void AutherSort(Book *&Head)//按作者排序
{
    Book *pfirst;      /* 排列后有序链的表头指针 */  
    Book *ptail;       /* 排列后有序链的表尾指针 */  
    Book *pminBefore;  /* 保留键值更小的节点的前驱节点的指针 */  
    Book  *pmin;        /* 存储最小节点   */  
    Book  *p;           /* 当前比较的节点 */  
	Book  *head=Head->next;
    pfirst = NULL;  
    while (head != NULL)         /*在链表中找键值最小的节点。*/  
    {  
    /* 注意：这里for语句就是体现选择排序思想的地方 */  
        for (p = head, pmin = head; p->next != NULL; p = p->next) /*循环遍历链表中的节点，找出此时最小的节点。*/  
        {  
            if (Uppercase(p->next->AutherName)<Uppercase(pmin->AutherName)) /*找到一个比当前min小的节点。*/  
            {  
                pminBefore = p;           /*保存找到节点的前驱节点：显然p->next的前驱节点是p。*/  
                pmin       = p->next;     /*保存键值更小的节点。*/  
            }  
        }
    
    /*上面for语句结束后，就要做两件事；一是把它放入有序链表中；二是根据相应的条件判断，安排它离开原来的链表。*/  
      
        /*第一件事*/  
        if (pfirst == NULL)     /* 如果有序链表目前还是一个空链表                      */  
        {  
            pfirst = pmin;      /* 第一次找到键值最小的节点。                          */  
            ptail  = pmin;      /* 注意：尾指针让它指向最后的一个节点。                */  
        }  
        else                    /* 有序链表中已经有节点                                */  
        {  
            ptail->next = pmin; /* 把刚找到的最小节点放到最后，即让尾指针的next指向它。*/  
            ptail = pmin;       /* 尾指针也要指向它。                                  */  
        }  
  
        /*第二件事*/  
        if (pmin == head)        /* 如果找到的最小节点就是第一个节点                    */  
        {  
            head = head->next;   /* 显然让head指向原head->next,即第二个节点，就OK       */  
        }  
        else /*如果不是第一个节点*/  
        {  
            pminBefore->next = pmin->next;/*前次最小节点的next指向当前pmin的next,这样就让pmin离开了原链表。*/  
        }  
    }  
  
    if (pfirst != NULL)     /*循环结束得到有序链表first                */  
    {  
        ptail->next = NULL; /*单向链表的最后一个节点的next应该指向NULL */   
    }  
    Head->next = pfirst;  
}
void ClassSort(Book *&Head)//按分类号排序
{
    Book *pfirst;      /* 排列后有序链的表头指针 */  
    Book  *ptail;       /* 排列后有序链的表尾指针 */  
    Book  *pminBefore;  /* 保留键值更小的节点的前驱节点的指针 */  
    Book  *pmin;        /* 存储最小节点   */  
    Book  *p;           /* 当前比较的节点 */  
	Book *head=Head->next;
   
    pfirst = NULL;  
    while (head != NULL)         /*在链表中找键值最小的节点。*/  
    {  
    /* 注意：这里for语句就是体现选择排序思想的地方 */  
        for (p = head, pmin = head; p->next != NULL; p = p->next) /*循环遍历链表中的节点，找出此时最小的节点。*/  
        {  
            if (p->next->ClassNumber<pmin->ClassNumber) /*找到一个比当前min小的节点。*/  
            {  
                pminBefore = p;           /*保存找到节点的前驱节点：显然p->next的前驱节点是p。*/  
                pmin       = p->next;     /*保存键值更小的节点。*/  
            }  
        }  
    
    /*上面for语句结束后，就要做两件事；一是把它放入有序链表中；二是根据相应的条件判断，安排它离开原来的链表。*/  
      
        /*第一件事*/  
        if (pfirst == NULL)     /* 如果有序链表目前还是一个空链表                      */  
        {  
            pfirst = pmin;      /* 第一次找到键值最小的节点。                          */  
            ptail  = pmin;      /* 注意：尾指针让它指向最后的一个节点。                */  
        }  
        else                    /* 有序链表中已经有节点                                */  
        {  
            ptail->next = pmin; /* 把刚找到的最小节点放到最后，即让尾指针的next指向它。*/  
            ptail = pmin;       /* 尾指针也要指向它。                                  */  
        }  
  
        /*第二件事*/  
        if (pmin == head)        /* 如果找到的最小节点就是第一个节点                    */  
        {  
            head = head->next;   /* 显然让head指向原head->next,即第二个节点，就OK       */  
        }  
        else /*如果不是第一个节点*/  
        {  
            pminBefore->next = pmin->next; /*前次最小节点的next指向当前pmin的next,这样就让pmin离开了原链表。*/  
        }  
    }  
  
    if (pfirst != NULL)     /*循环结束得到有序链表first                */  
    {  
        ptail->next = NULL; /*单向链表的最后一个节点的next应该指向NULL */   
    }  
    Head->next = pfirst;   
}  
void PublishSort(Book *&Head)//按出版单位排序 
{
	Book *pfirst;      /* 排列后有序链的表头指针 */  
    Book *ptail;       /* 排列后有序链的表尾指针 */  
    Book *pminBefore;  /* 保留键值更小的节点的前驱节点的指针 */  
    Book  *pmin;        /* 存储最小节点   */  
    Book  *p;           /* 当前比较的节点 */  
	Book  *head=Head->next;
    pfirst = NULL;  
    while (head != NULL)         /*在链表中找键值最小的节点。*/  
    {  
    /* 注意：这里for语句就是体现选择排序思想的地方 */  
        for (p = head, pmin = head; p->next != NULL; p = p->next) /*循环遍历链表中的节点，找出此时最小的节点。*/  
        {  
            if (Uppercase(p->next->PublishUnit)<Uppercase(pmin->PublishUnit)) /*找到一个比当前min小的节点。*/  
            {  
                pminBefore = p;           /*保存找到节点的前驱节点：显然p->next的前驱节点是p。*/  
                pmin       = p->next;     /*保存键值更小的节点。*/  
            }  
        }
    
    /*上面for语句结束后，就要做两件事；一是把它放入有序链表中；二是根据相应的条件判断，安排它离开原来的链表。*/  
      
        /*第一件事*/  
        if (pfirst == NULL)     /* 如果有序链表目前还是一个空链表                      */  
        {  
            pfirst = pmin;      /* 第一次找到键值最小的节点。                          */  
            ptail  = pmin;      /* 注意：尾指针让它指向最后的一个节点。                */  
        }  
        else                    /* 有序链表中已经有节点                                */  
        {  
            ptail->next = pmin; /* 把刚找到的最小节点放到最后，即让尾指针的next指向它。*/  
            ptail = pmin;       /* 尾指针也要指向它。                                  */  
        }  
  
        /*第二件事*/  
        if (pmin == head)        /* 如果找到的最小节点就是第一个节点                    */  
        {  
            head = head->next;   /* 显然让head指向原head->next,即第二个节点，就OK       */  
        }  
        else /*如果不是第一个节点*/  
        {  
            pminBefore->next = pmin->next;/*前次最小节点的next指向当前pmin的next,这样就让pmin离开了原链表。*/  
        }  
    }  
  
    if (pfirst != NULL)     /*循环结束得到有序链表first                */  
    {  
        ptail->next = NULL; /*单向链表的最后一个节点的next应该指向NULL */   
    }  
    Head->next = pfirst; 
}
void PriceSort(Book *&Head)//按价格排序
{
    Book  *pfirst;      /* 排列后有序链的表头指针 */  
    Book  *ptail;       /* 排列后有序链的表尾指针 */  
    Book  *pminBefore;  /* 保留键值更小的节点的前驱节点的指针 */  
    Book  *pmin;        /* 存储最小节点   */  
    Book  *p;           /* 当前比较的节点 */
	Book  *head=Head->next;
    pfirst = NULL;  
    while (head != NULL)         /*在链表中找键值最小的节点。*/  
    {  
    /* 注意：这里for语句就是体现选择排序思想的地方 */  
        for (p = head, pmin = head; p->next != NULL; p = p->next) /*循环遍历链表中的节点，找出此时最小的节点。*/  
        {  
            if (p->next->Price<pmin->Price) /*找到一个比当前min小的节点。*/  
            {  
                pminBefore = p;           /*保存找到节点的前驱节点：显然p->next的前驱节点是p。*/  
                pmin       = p->next;     /*保存键值更小的节点。*/  
            } 
        }  
    
    /*上面for语句结束后，就要做两件事；一是把它放入有序链表中；二是根据相应的条件判断，安排它离开原来的链表。*/  
      
        /*第一件事*/  
        if (pfirst == NULL)     /* 如果有序链表目前还是一个空链表                      */  
        {  
            pfirst = pmin;      /* 第一次找到键值最小的节点。                          */  
            ptail  = pmin;      /* 注意：尾指针让它指向最后的一个节点。                */  
        }  
        else                    /* 有序链表中已经有节点                                */  
        {  
            ptail->next = pmin; /* 把刚找到的最小节点放到最后，即让尾指针的next指向它。*/  
            ptail = pmin;       /* 尾指针也要指向它。                                  */  
        }  
  
        /*第二件事*/  
        if (pmin == head)        /* 如果找到的最小节点就是第一个节点                    */  
        {  
            head = head->next;   /* 显然让head指向原head->next,即第二个节点，就OK       */  
        }  
        else /*如果不是第一个节点*/  
        {  
            pminBefore->next = pmin->next; /*前次最小节点的next指向当前pmin的next,这样就让pmin离开了原链表。*/  
        }  
    }  
  
    if (pfirst != NULL)     /*循环结束得到有序链表first                */  
    {  
        ptail->next = NULL; /*单向链表的最后一个节点的next应该指向NULL */   
    }  
    Head->next = pfirst;

}
void PubTimeSort(Book *&Head)//按出版时间排序
{
    Book  *pfirst;      /* 排列后有序链的表头指针 */  
    Book  *ptail;       /* 排列后有序链的表尾指针 */  
    Book  *pminBefore;  /* 保留键值更小的节点的前驱节点的指针 */  
    Book  *pmin;        /* 存储最小节点   */  
    Book  *p;           /* 当前比较的节点 */
	Book  *head=Head->next;
    pfirst = NULL;  
    while (head != NULL)         /*在链表中找键值最小的节点。*/  
    {  
    /* 注意：这里for语句就是体现选择排序思想的地方 */  
        for (p = head, pmin = head; p->next != NULL; p = p->next) /*循环遍历链表中的节点，找出此时最小的节点。*/  
        {  
            if(p->next->PublishTime.year<pmin->PublishTime.year||p->next->PublishTime.month<pmin->PublishTime.month||p->next->PublishTime.day<pmin->PublishTime.day) /*找到一个比当前min小的节点。*/  
            {  
                pminBefore = p;           /*保存找到节点的前驱节点：显然p->next的前驱节点是p。*/  
                pmin       = p->next;     /*保存键值更小的节点。*/  
            } 
        }  
    
    /*上面for语句结束后，就要做两件事；一是把它放入有序链表中；二是根据相应的条件判断，安排它离开原来的链表。*/  
      
        /*第一件事*/  
        if (pfirst == NULL)     /* 如果有序链表目前还是一个空链表                      */  
        {  
            pfirst = pmin;      /* 第一次找到键值最小的节点。                          */  
            ptail  = pmin;      /* 注意：尾指针让它指向最后的一个节点。                */  
        }  
        else                    /* 有序链表中已经有节点                                */  
        {  
            ptail->next = pmin; /* 把刚找到的最小节点放到最后，即让尾指针的next指向它。*/  
            ptail = pmin;       /* 尾指针也要指向它。                                  */  
        }  
  
        /*第二件事*/  
        if (pmin == head)        /* 如果找到的最小节点就是第一个节点                    */  
        {  
            head = head->next;   /* 显然让head指向原head->next,即第二个节点，就OK       */  
        }  
        else /*如果不是第一个节点*/  
        {  
            pminBefore->next = pmin->next; /*前次最小节点的next指向当前pmin的next,这样就让pmin离开了原链表。*/  
        }  
    }  
  
    if (pfirst != NULL)     /*循环结束得到有序链表first                */  
    {  
        ptail->next = NULL; /*单向链表的最后一个节点的next应该指向NULL */   
    }  
    Head->next = pfirst;
}
void ReviseTimeSort(Book *&Head)//按修改时间排序
{
    Book *pfirst;
	Book *ptail;
	Book *p;
	Book *head=Head->next;
	Book *pmin;
	Book *pminbefore;
	pfirst=NULL;
	while(head!=NULL)
	{
	  for(p=head,pmin=head;p->next!=NULL;p=p->next)
		  if(p->next->ReviseTime.year<pmin->ReviseTime.year||p->next->ReviseTime.month<pmin->ReviseTime.month||p->next->ReviseTime.day<pmin->ReviseTime.day)
		  {
		  pminbefore=p;
		  pmin=p->next;
		  }
		  if(pfirst==NULL)
		  {
		  pfirst=pmin;
		  ptail=pmin;
		  }
		  else
		  {
		  ptail->next=pmin;
		  ptail=pmin;		  
		  }
		  if(pmin==head)
		  {
		  head=head->next;
		  }
		  else
		  {
		  pminbefore->next=pmin->next;
		  }
	}
	if(pfirst!=NULL)
		ptail->next=NULL;
	Head->next=pfirst;
}

void Compositor()
{
	int choice;
	Book *L;
	choice=CompositorPage(36,40,text3);
	ReadDataCreateList(L,FileName);
	switch(choice)
	{
	case 1:
		AutherSort(L);
		PrintfData(L,TextSort[choice-1]);
		break;
	case 2:
		PriceSort(L); 
		PrintfData(L,TextSort[choice-1]);
		break;
	case 3:
		ClassSort(L); 
		PrintfData(L,TextSort[choice-1]);
		break;
	case 4:
		PublishSort(L);
		PrintfData(L,TextSort[choice-1]);
		break;
	case 5:
		PubTimeSort(L);
		PrintfData(L,TextSort[choice-1]);
		break;
	case 6:
		ReviseTimeSort(L);
		PrintfData(L,TextSort[choice-1]);
		break;
	}
	return ;
}
