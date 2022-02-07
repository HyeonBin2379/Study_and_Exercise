#include <stdio.h>
#include "ArrayList3.h"
#include "NameCard.h"

int main(void)
{
	List list;
	NameCard * pcard;

	ListInit(&list);
	
	pcard = MakeNameCard("������", "010-1111-2222");
	LInsert(&list, pcard);
	pcard = MakeNameCard("������", "010-2222-5555");
	LInsert(&list, pcard);
	pcard = MakeNameCard("������", "010-3333-7777");
	LInsert(&list, pcard);

	printf("���� �������� ��: %d \n", LCount(&list));
	if (LFirst(&list, &pcard)) {

		ShowNameCardInfo(pcard);
		while (LNext(&list, &pcard))
		{
			ShowNameCardInfo(pcard);
		}
	}

	printf("�˻� ���: \n");
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "������")) {
			ShowNameCardInfo(pcard);
		}
		else {
			while (LNext(&list, &pcard))
			{
				if (!NameCompare(pcard, "������"))
					ShowNameCardInfo(pcard);
			}
		}
	}

	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "������")) {
			ChangePhoneNum(pcard, "010-9999-9999");
		}
		else {
			while (LNext(&list, &pcard))
			{
				if (!NameCompare(pcard, "������"))
					ChangePhoneNum(pcard, "010-9999-9999");
			}
		}
	}

	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "������")) {
			pcard = LRemove(&list);
			free(pcard);
		}
		else {
			while (LNext(&list, &pcard))
			{
				if (!NameCompare(pcard, "������")) {
					pcard = LRemove(&list);
					free(pcard);
				}
			}
		}
	}

	printf("���� �������� ��: %d \n", LCount(&list));
	if (LFirst(&list, &pcard)) {
		
		ShowNameCardInfo(pcard);
		while (LNext(&list, &pcard))
		{
			ShowNameCardInfo(pcard);
		}
	}
	return 0;
}