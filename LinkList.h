/******************************************************************\
* 版权所有 (C)2011, by Tristone
* 文件名称： LinkList.h
*
* 内容摘要：一种通用双向循环链表的模板与声明
*
* 历史：
* 创建时间：2011-06-06
* 修订日期: 2011-06-08
* 修改人: Tristone
* 描述: 1.丰富了一些接口	
* 修订日期: 2011-06-09
* 修改人: Tristone
* 描述: 1.修改了析构函数的错误
\******************************************************************/

#ifndef _LINKLIST_H_
#define _LINKLIST_H_

typedef struct VList
{
	void* pData;
	VList* pPre;
	VList* pNext;
}*pVList;

class LinkList
{
public:
	LinkList(void);						//构造函数,初始化各指针为为NULL
	~LinkList(void);					//析构函数,释放所有节点

	void LinkList::LIST_begin();		//将当前指针指向链表头
	void LinkList::LIST_next();			//将当前指针指向下一个节点
	void LinkList::LIST_pre();

	void LIST_add(void* data);			//添加一个节点(插入到所有节点前面,先插入的反而在后面,类似栈)
	//int LIST_free();					//被析构函数所替代
	int LIST_count();					//返回节点个数

	pVList LIST_geth();					//得到pHead
	pVList LIST_getc();					//得到pCur
	void* LIST_get();					//返回pCur当前指向节点的数据域指针
	void* LIST_get(int index);			//返回指定位置的节点的数据域指针,节点index值从1开始
	void* LIST_get(void* data);			//返回指定数据域指向data的节点的数据域地址

	int  LIST_remove(void* data);		//删除数据域指针为data的节点,返回0失败
	int  LIST_remove(int index);		//删除第index个节点,index的值从1开始,返回0失败

	int LIST_update(void* dest, void* data);	//更新数据域指针为dest的节点数据域为data,返回0失败
	int LIST_update(int index, void* data);		//更新第index个节点数据域为data,index从1开始,返回0失败
private:
		pVList pCur;	
		pVList pHead;		//链表头指针
};


#endif

