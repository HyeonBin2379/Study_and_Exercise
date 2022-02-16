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
	// ��ȯ�� ����, ���ڿ� ����
	Stack stack;
	int expLen = strlen(exp);
	char * convExp = (char *)malloc(sizeof(char)*expLen + 1);

	// �ݺ���, �ǿ�����, ������ ����
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
			case '(':	// ��ȣ�� ��� ��ȣ ���� ������ �迭�� �߰�
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

	// ���� �� �����ڸ� ��� ��������
	while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
		convExp[idx++] = SPop(&stack);

	// ���� ���ڿ��� ��ȯ ��� ����
	strcpy(exp, convExp);
	free(convExp);
}