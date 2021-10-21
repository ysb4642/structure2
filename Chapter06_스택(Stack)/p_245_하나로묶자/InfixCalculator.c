#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h" // ConvToRPNExp 함수 호출
#include "PostCalculator.h" // EvalRPNExp 함수 호출

int EvalInfixExp(char exp[])
{
	int len = strlen(exp);
	int ret;
	char * expcpy = (char*)malloc(len + 1);
	strcpy(expcpy, exp);

	ConvToRPNExp(expcpy);			// 후위 표기법의 수식으로 변환
	ret = EvalRPNExp(expcpy);		// 변환된 수식의 계산

	free(expcpy);					// 문자열 저장공간 해체
	return ret;						// 계산결과 반환
}
