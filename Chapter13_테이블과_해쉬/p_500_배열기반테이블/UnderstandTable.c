#include <stdio.h>

typedef struct _empInfo
{
	int empNum;		// 직원의 고유번호 : Key
	int age;		// 직원의 나이 : Value
} EmpInfo;

int main(void)
{
	EmpInfo empInfoArr[1000];		// 직원들의 정보를 저장하기 위해 선언된 배열
	EmpInfo ei;
	int eNum;

	printf("사번과 나이 입력 : ");
	scanf("%d %d", &(ei.empNum), &(ei.age));
	empInfoArr[ei.empNum] = ei;		// 단번에 저장!

	printf("확인하고픈 직원의 사번 입력 : ");
	scanf("%d", &eNum);

	ei = empInfoArr[eNum];
	printf("사번 : %d, 나이 : %d\n", ei.empNum, ei.age);
	return 0;
}