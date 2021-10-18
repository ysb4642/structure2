#ifndef __ARRAY_LIST_H
#define __ARRAY_LIST_H
#include "Point.h"

#define TRUE	1
#define FALSE	0

#define LIST_LEN	100
typedef Point * LData;

typedef struct __ArrayList
{
	LData arr[LIST_LEN];
	int numOfData;			// 저장된 데이터의 수
	int curPosition;		// 데이터 참조 위치를 기록
} ArrayList;

typedef ArrayList List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);

int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);

LData LRemove(List *plist);
int LCount(List *plist);

#endif
