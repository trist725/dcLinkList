/******************************************************************\
* 版权所有 (C)2011, by Tristone
* 文件名称： LinkList.cpp
*
* 内容摘要：一种通用双向循环链表的实现
*
* 历史：详见LinkList.h
\******************************************************************/

#include <cstring>
//#include <iostream>
//using namespace std;
#include "LinkList.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

LinkList::LinkList(void)
{
	pHead = NULL;
	pCur = NULL;
	//cout << "构造函数被调用" << endl;
}

LinkList::~LinkList(void)
{
	int count = LIST_count();
	for(int i = 1; i <= count; i++)
	{
		LIST_remove(i);
	}
	//cout << "析构函数被调用" << endl;
}

void LinkList::LIST_begin()
{
	pCur = pHead;
}

void LinkList::LIST_next()
{
	pCur = pCur->pNext;
}

void LinkList::LIST_pre()
{
	pCur = pCur->pPre;
}

pVList LinkList::LIST_getc()
{
	return pCur;
}

pVList LinkList::LIST_geth()
{
	return pHead;
}

void LinkList::LIST_add(void *data)
{
	pVList p = NULL;
	if(pHead)
	{
		p = pHead->pPre;
		p->pNext = new VList;
		pVList p0 = p;
		p = p->pNext;
		p->pPre = p0;
		p->pNext = pHead;
		p->pData = data;
		if(p0 == pHead)
		{
			p0->pPre = p;
		}
		p0->pNext = p;
		pHead->pPre = p;
	}
	else	//添加第一个节点
	{
		pHead = new VList;
		p = pHead;
		p->pData = data;
		p->pNext = pHead;
		p->pPre = pHead;
	}
}

int LinkList::LIST_count()
{
	int count = 0;
	LIST_begin();
	if(!pCur)	//若链表为空
	{
		return 0;
	}
	do
	{
		count++;
		pCur = pCur->pNext;
	}
	while(pCur != pHead);
	return count;
}

void* LinkList::LIST_get()
{
	if(pCur)
	{
		return pCur->pData;
	}
	else
	{
		return NULL;
	}
}

void* LinkList::LIST_get(int index)
{
	pVList p = pHead;
	if(!p || (index <= 0))
	{
		return NULL;
	}
	for(; index > 1; index--)	//大于1是因为节点index值从1开始
	{
		p = p->pNext;
		if(p == pHead)
		{
			return NULL;
		}
	}
	return p->pData;
}

void* LinkList::LIST_get(void* data)
{
	pVList p = pHead;
	if(!p)
	{
		return NULL;
	}
	do
	{
		if(p->pData == data)
		{
			return p->pData;
		}	
		p = p->pNext;
	}
	while(p != pHead);
	return NULL;
}

int LinkList::LIST_remove(void* data)
{
	pVList p = pHead;
	if(!p)
	{
		return 0;
	}
	do
	{
		if(p->pData == data)
		{
			if(p == pHead)				//若要释放的是头结点
			{
				if(p->pNext == pHead)	//该节点是尾节点
				{
					pHead = NULL;
					delete p;			//没有释放数据域指针指向的那块空间
					return 1;
				}
				else
				{
					pHead = p->pNext;
					if(pHead->pNext == p)	//是否有再下一个节点
					{
						pHead->pPre = pHead;
						pHead->pNext = pHead;
					}
					else
					{
						pHead->pPre = p->pPre;
					}
					delete p;
					return 1;
				}
			}
			else						//要释放的不是头节点
				if(p->pNext == pHead)	//该节点是尾节点
				{
					pVList p0 = p->pPre;
					p0->pNext = p->pNext;
					delete p;
					return 1;
				}
				else
				{
					pVList p0 = p->pPre;
					pVList p1 = p->pNext;
					p0->pNext = p->pNext;
					p1->pPre = p->pPre;
					delete p;
					return 1;
				}
		}
		p = p->pNext;
	}
	while(p != pHead);
	return 0;
}

int LinkList::LIST_remove(int index)
{
	pVList p = pHead;
	if(!p || (index <= 0))
	{
		return 0;
	}
	for(; index > 1; index--)	//大于1是因为节点index值从1开始
	{
		p = p->pNext;
		if(p == pHead)
		{
			return 0;
		}
	}
	if(p == pHead)				//若要释放的是头结点
	{
		if(p->pNext == pHead)	//该节点是尾节点
		{
			pHead = NULL;
			delete p;			//没有释放数据域指针指向的那块空间
			return 1;
		}
		else
		{
			pHead = p->pNext;
			if(pHead->pNext == p)	//是否有再下一个节点
			{
				pHead->pPre = pHead;
				pHead->pNext = pHead;
			}
			else
			{
				pHead->pPre = p->pPre;
			}
			delete p;
			return 1;
		}
	}
	else						//要释放的不是头节点
		if(p->pNext == pHead)	//该节点是尾节点
		{
			pVList p0 = p->pPre;
			p0->pNext = p->pNext;
			delete p;
			return 1;
		}
		else
		{
			pVList p0 = p->pPre;
			pVList p1 = p->pNext;
			p0->pNext = p->pNext;
			p1->pPre = p->pPre;
			delete p;
			return 1;
		}
}

int LinkList::LIST_update(void* dest, void* data)
{
	pVList p = pHead;
	if(!p)
	{
		return 0;
	}
	do
	{
		if(p->pData == dest)
		{
			p->pData = data;
			return 1;
		}
		p = p->pNext;
	}
	while(p != pHead);
	return 0;
}

int LinkList::LIST_update(int index, void* data)
{
	pVList p = pHead;
	if(!p || (index <= 0))
	{
		return 0;
	}
	for(; index > 1; index--)	//大于1是因为节点index值从1开始
	{
		p = p->pNext;
		if(p == pHead)
		{
			return 0;
		}
	}
	p->pData = data;
	return 1;
}


