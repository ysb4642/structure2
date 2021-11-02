#include <stdio.h>
#include"BinaryTree3.h"

BTreeNode *RotateLL(BTreeNode *bst)
{
	BTreeNode *pNode;		// parent node
	BTreeNode *cNode;		// child node

	// pnode와 cnode가 LL회전을 위해 적절한 위치를 가리키게 한다.
	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	// 실제 LL회전을 담당하는 두 개의 문장
	ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
	ChangeRightSubTree(cNode, pNode);

	// LL회전으로 인해서 변경된 루트 노드의 주소값 반환
	return cNode;
}

BTreeNode *RotateRR(BTreeNode *bst)
{
	BTreeNode *pNode;
	BTreeNode *cNode;

	pNode = bst;
	cNode = GetRightSubTree(pNode);

	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree(cNode, pNode);

	return cNode;
}

BTreeNode *RotateRL(BTreeNode *bst)
{
	BTreeNode *pNode;
	BTreeNode *cNode;

	pNode = bst;
	cNode = GetRightSubTree(pNode);

	ChangeRightSubTree(pNode, RotateLL(cNode));
	return RotateRR(pNode);
}

BTreeNode *RotateLR(BTreeNode *bst)
{
	BTreeNode *pNode;
	BTreeNode *cNode;

	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	ChangeLeftSubTree(pNode, RotateRR(cNode));
	return RotateLL(pNode);
}

int GetHeight(BTreeNode *bst)		// 트리의 높이를 계산하여 반환
{
	int leftH;		// left height
	int rightH;		// right height

	if (bst == NULL)
		return 0;
	
	leftH = GetHeight(GetLeftSubTree(bst));		// 왼쪽 서브트리 높이 계산
	rightH = GetHeight(GetRightSubTree(bst));	// 오른쪽 서브트리 높이 계산

	// 큰 값의 높이를 반환
	if (leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

int GetHeightDiff(BTreeNode *bst)		// 두 서브트리의 높이의차 (균형인수)를 반환
{
	int lsh;		// left sub tree height
	int rsh;		// right sub tree height

	if (bst == NULL)
		return 0;
	
	lsh = GetHeight(GetLeftSubTree(bst));		// 왼쪽 서브트리 높이
	rsh = GetHeight(GetRightSubTree(bst));		// 오른쪽 서브트리 높이
	
	return lsh - rsh;	// 균형인수 계산결과 반환
}

BTreeNode *Rebalance(BTreeNode **pRoot)
{
	int hDiff = GetHeightDiff(*pRoot);		// 균형인수 계산

	// 균형인수가 +2 이상이면 LL상태 또는 LR상태이다.
	if (hDiff > 1)		// 왼쪽 서브트리 방향으로 높이가 2이상 크다면
	{
		if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
			*pRoot = RotateLL(*pRoot);
		else
			*pRoot = RotateLR(*pRoot);
	}

	// 균형인수가 -2이하이면 RR상태 또는 RL상태이다.
	if (hDiff < -1)
	{
		if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
			*pRoot = RotateRR(*pRoot);
		else
			*pRoot = RotateRL(*pRoot);
	}

	return *pRoot;
}