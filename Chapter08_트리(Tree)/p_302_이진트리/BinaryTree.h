#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H

typedef int BTDdata;

typedef struct _bTreeNode
{
	BTDdata data;
	struct _bTreeNode *left;
	struct _bTreeNode *right;
} BTreeNode;

BTreeNode *MakeBTreeNode(void);
BTDdata GetData(BTreeNode *bt);
void SetData(BTreeNode *bt, BTDdata data);

BTreeNode *GetLeftSubTree(BTreeNode *bt);
BTreeNode *GetRightSubTree(BTreeNode *bt);

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub);
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub);

#endif
