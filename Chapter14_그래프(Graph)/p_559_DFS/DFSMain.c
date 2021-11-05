#include <stdio.h>
#include "ALGraphDFS.h"

int main(void)
{
	ALGraph graph;
	GraphInit(&graph, 7);

	AddEdge(&graph, A, B);
	AddEdge(&graph, A, D);
	AddEdge(&graph, B, C);
	AddEdge(&graph, D, C);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, F);
	AddEdge(&graph, E, G);

	ShowGraphEdgeInfo(&graph);

	DFSShowGraphVertex(&graph, A); printf("\n");	
	DFSShowGraphVertex(&graph, C); printf("\n");
	DFSShowGraphVertex(&graph, E); printf("\n");
	DFSShowGraphVertex(&graph, G); printf("\n");

	GraphDestroy(&graph);
	return 0;
}