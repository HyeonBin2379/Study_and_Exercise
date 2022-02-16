#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayBasedStack.h"

int GetOpPrec(char op)
{
	switch (op)
	{
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	}

	return -1;
}
int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)
		return 1;
	else if (op1Prec < op2Prec)
		return -1;
	else
		return 0;
}
void ConvToRPNExp(char exp[])
{
	// 변환용 스택, 문자열 선언
	Stack stack;
	int expLen = strlen(exp);
	char * convExp = (char *)malloc(sizeof(char)*expLen + 1);

	// 반복자, 피연산자, 연산자 변수
	int i, idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char)*expLen + 1);
	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];
		if (isdigit(tok))
		{
			convExp[idx++] = tok;
		}
		else 
		{
			switch (tok)
			{
			case '(':	// 괄호인 경우 괄호 끝날 때까지 배열에 추가
				SPush(&stack, tok);
				break;
			case ')':
				while (1)
				{
					popOp = SPop(&stack);
					if (popOp == '(')
						break;
					convExp[idx++] = popOp;
				}
				break;
			case '+': case '-':
			case '*': case '/':
				while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
					convExp[idx++] = SPop(&stack);
				SPush(&stack, tok);
				break;
			}
		}
	}

	// 스택 내 연산자를 모두 가져오기
	while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
		convExp[idx++] = SPop(&stack);

	// 원래 문자열에 변환 결과 저장
	strcpy(exp, convExp);
	free(convExp);
}