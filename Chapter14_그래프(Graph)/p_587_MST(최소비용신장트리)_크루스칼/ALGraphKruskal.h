#ifndef __AL_GRAPH_KRUSKAL
#define __AL_GRAPH_KRUSKAL

#include "DLinkedList.h"
#include "PriorityQueue.h"
#include "ALEdge.h"

enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual
{
	int numV;				// 정점의 수
	int numE;				// 간선의 수
	List *adjList;			// 간선의 정보
	int *visitInfo;
	PQueue pqueue;			// 간선의 가중치 정보 저장
} ALGraph;

// 그래프의 초기화 -- 이전 함수의 정의와 차이가 있음
void GraphInit(ALGraph *pg, int nv);

// 그래프의 리소스 해제  -- 이전 함수와 동일함
void GraphDestroy(ALGraph *pg);

// 간선의 추가  -- 이전 함수의 정의와 차이가 있음
void AddEdge(ALGraph *pg, int fromV, int toV, int weight);

// 간선의 정보 출력 -- 이전 함수와 동일함
void ShowGraphEdgeInfo(ALGraph *pg);

// 정점의 정보 출력 : Depth First Search 기반 -- 이전 함수와 동일함
void DFSShowGraphVertex(ALGraph *pg, int startV);

// 새로 추가된 함수
void ConkruskalMST(ALGraph *pg);		// 최소 비용 신장 트리의 구성

// 새로 추가된 함수
void ShowGraphEdgeWeightInfo(ALGraph *pg);		// 가중치 정보 출력

#endif