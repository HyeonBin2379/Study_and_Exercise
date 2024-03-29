#include <stdio.h>
#include "ArrayList3.h"
#include "NameCard.h"

int main(void)
{
	List list;
	NameCard * pcard;

	ListInit(&list);
	
	pcard = MakeNameCard("이진수", "010-1111-2222");
	LInsert(&list, pcard);
	pcard = MakeNameCard("한지영", "010-2222-5555");
	LInsert(&list, pcard);
	pcard = MakeNameCard("조수진", "010-3333-7777");
	LInsert(&list, pcard);

	printf("현재 데이터의 수: %d \n", LCount(&list));
	if (LFirst(&list, &pcard)) {

		ShowNameCardInfo(pcard);
		while (LNext(&list, &pcard))
		{
			ShowNameCardInfo(pcard);
		}
	}

	printf("검색 결과: \n");
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "이진수")) {
			ShowNameCardInfo(pcard);
		}
		else {
			while (LNext(&list, &pcard))
			{
				if (!NameCompare(pcard, "이진수"))
					ShowNameCardInfo(pcard);
			}
		}
	}

	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "한지영")) {
			ChangePhoneNum(pcard, "010-9999-9999");
		}
		else {
			while (LNext(&list, &pcard))
			{
				if (!NameCompare(pcard, "한지영"))
					ChangePhoneNum(pcard, "010-9999-9999");
			}
		}
	}

	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "조수진")) {
			pcard = LRemove(&list);
			free(pcard);
		}
		else {
			while (LNext(&list, &pcard))
			{
				if (!NameCompare(pcard, "조수진")) {
					pcard = LRemove(&list);
					free(pcard);
				}
			}
		}
	}

	printf("현재 데이터의 수: %d \n", LCount(&list));
	if (LFirst(&list, &pcard)) {
		
		ShowNameCardInfo(pcard);
		while (LNext(&list, &pcard))
		{
			ShowNameCardInfo(pcard);
		}
	}
	return 0;
}