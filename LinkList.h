/******************************************************************\
* ��Ȩ���� (C)2011, by Tristone
* �ļ����ƣ� LinkList.h
*
* ����ժҪ��һ��ͨ��˫��ѭ�������ģ��������
*
* ��ʷ��
* ����ʱ�䣺2011-06-06
* �޶�����: 2011-06-08
* �޸���: Tristone
* ����: 1.�ḻ��һЩ�ӿ�	
* �޶�����: 2011-06-09
* �޸���: Tristone
* ����: 1.�޸������������Ĵ���
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
	LinkList(void);						//���캯��,��ʼ����ָ��ΪΪNULL
	~LinkList(void);					//��������,�ͷ����нڵ�

	void LinkList::LIST_begin();		//����ǰָ��ָ������ͷ
	void LinkList::LIST_next();			//����ǰָ��ָ����һ���ڵ�
	void LinkList::LIST_pre();

	void LIST_add(void* data);			//���һ���ڵ�(���뵽���нڵ�ǰ��,�Ȳ���ķ����ں���,����ջ)
	//int LIST_free();					//���������������
	int LIST_count();					//���ؽڵ����

	pVList LIST_geth();					//�õ�pHead
	pVList LIST_getc();					//�õ�pCur
	void* LIST_get();					//����pCur��ǰָ��ڵ��������ָ��
	void* LIST_get(int index);			//����ָ��λ�õĽڵ��������ָ��,�ڵ�indexֵ��1��ʼ
	void* LIST_get(void* data);			//����ָ��������ָ��data�Ľڵ���������ַ

	int  LIST_remove(void* data);		//ɾ��������ָ��Ϊdata�Ľڵ�,����0ʧ��
	int  LIST_remove(int index);		//ɾ����index���ڵ�,index��ֵ��1��ʼ,����0ʧ��

	int LIST_update(void* dest, void* data);	//����������ָ��Ϊdest�Ľڵ�������Ϊdata,����0ʧ��
	int LIST_update(int index, void* data);		//���µ�index���ڵ�������Ϊdata,index��1��ʼ,����0ʧ��
private:
		pVList pCur;	
		pVList pHead;		//����ͷָ��
};


#endif

