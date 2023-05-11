#include "surface.h"

surfacePage_t currentSurfacePage = PAGE_INVALID;

inline void show_score(const score_t *pScore)
{
	if (NULL == pScore)
	{
		exit(-1);
	}

	system("cls");
	puts("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[");
	puts("�U     ɨ��       �U");
	puts("�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g");
	puts("�U  ��������ɼ�  �U");
	puts("�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g");
	printf("�U�ۼƵ������:%d�ΨU\n", pScore -> clickCount);
	printf("�U�ۼƺ�ʱ:%5lld��U\n", (GetTickCount64() - (pScore -> beginTick64)) / 1000 + 1);
	puts("�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g");
	puts("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a");
	system("pause");
}

void show_win(const score_t *pScore)
{
	

	system("cls");
	fputs("(������ͨ�أ���󽥽�����һƪ����...)\n", stdout);
	system("pause");

	system("cls");
	fputs("���������ܵе�ˮƽ��������Ƭ����!\n", stdout);
	system("pause");

	system("cls");
	fputs("��л��Ϊ�����ƽ�����Ĺ���!\n", stdout);
	system("pause");

	show_score(pScore);
}

void show_gameover(const score_t *pScore)
{
	system("cls");
	fputs("(Bombһ�����졪����������)\n", stdout);
	system("pause");

	system("cls");
	fputs("��ʲôB�����������޴�������ŵ�������һ��...\n", stdout);
	system("pause");

	system("cls");
	fputs("����̧ͷ����ͷ�ϵ��Ƕ��⻷ʱ�����ƺ������һ��......\n", stdout);
	system("pause");

	show_score(pScore);
}

void show_first_play_menu()
{
	system("cls");

	puts("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[");
	puts("�U     ɨ��       �U");
	puts("�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g");
	puts("�U1.��ʼ��Ϸ      �U");
	puts("�U2.�˳���Ϸ      �U");
	puts("�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g");
	puts("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");

	// ����GUI״̬
	currentSurfacePage = PAGE_FIRST_PLAY;
}

void show_next_play_menu()
{
	system("cls");

	puts("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[");
	puts("�U     ɨ��       �U");
	puts("�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g");
	puts("�U1.����һ��      �U");
	puts("�U2.�˳���Ϸ      �U");
	puts("�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g");
	puts("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a");

	// ����GUI״̬
	currentSurfacePage = PAGE_NEXT_PLAY;
}

uint32_t get_click(uint32_t *pXPos, uint32_t *pYPos, score_t *pScore)
{
	if (NULL == pScore)
	{
		exit(-1);
	}

	/*
	fputs("��ʾ>11 4���������11�е�4�е�λ�ã�5 14����������5�е�14�е�λ��\n", stdout);
	printf("��ʾ>��ǰ�������: %d��\n", pScore -> clickCount);
	printf("��ʾ>��ǰ��ʱ: %lld��\n", (0 == (pScore -> clickCount))?0:(GetTickCount64() - (pScore -> beginTick64)) / 1000 + 1);
	*/
	fputs("�������������λ��>", stdout);

	fflush(stdin);
	char inputBuffer[128];
	gets_s(inputBuffer, 128);
	
	if (2 != sscanf(inputBuffer, "%d %d", pYPos, pXPos))
	{
		return 0;
	}

#ifdef _DEBUG
	printf("�����������: X:%d Y:%d\n",*pXPos, *pYPos);
	system("pause");
#endif

	// ����ۼƴ�����1
	pScore -> clickCount += 1;

	return 1;
}

menuChoice_t get_choice()
{
	uint32_t choiceId = 0;
	fputs("������ѡ��>", stdout);

	fflush(stdin);

	char inputBuffer[128];
	gets_s(inputBuffer, 128);

	if (1 != sscanf(inputBuffer, "%d", &choiceId))
	{
		return CHOICE_INVALID;
	}

#ifdef _DEBUG
	printf("�������ѡ��Id: %d\n", choiceId);
#endif

	switch (currentSurfacePage)
	{
	case PAGE_FIRST_PLAY:
		switch (choiceId)
		{
		case 1:
			return CHOICE_FIRST_PLAY;
		case 2:
			return CHOICE_EXIT;
		}
		break;
	case PAGE_NEXT_PLAY:
		switch (choiceId)
		{
		case 1:
			return CHOICE_NEXT_PLAY;
		case 2:
			return CHOICE_EXIT;
		}
		break;
	case PAGE_PLAYING:
		switch (choiceId)
		{
		case 1:
			return CHOICE_EXIT;
		case 2:
			return CHOICE_RESTART;
		}
		break;
	}

	return CHOICE_INVALID;
}

void show_already_cleaned()
{
	fputs("��ʾ>����ط��Ѿ���������ˣ���һ�������ط�����������!\n", stdout);
	system("pause");
}

void show_invalid_click()
{
	fputs("��ʾ>����ط������������ķ�Χ!\n", stdout);
	system("pause");
}

void show_illegal_input()
{
	fputs("��ʾ>��û������������˼...\n�볢�Ի�һ����ȷ�ķ�������������Ҫ��ʲô:D\n", stdout);
	system("pause");
}

uint32_t show_page(const surfacePage_t page)
{
	switch (currentSurfacePage)
	{
	case PAGE_FIRST_PLAY:
		show_first_play_menu();
		break;
	case PAGE_NEXT_PLAY:
		show_next_play_menu();
		break;
	default:
		return 0;
	}

	return 1;
}

void show_bye()
{
	system("cls");
	puts("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[");
	puts("�U     ɨ��       �U");
	puts("�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g");
	puts("�U  ��л��������  �U");
	puts("�U     �ټ�       �U");
	puts("�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g");
	puts("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a");
	system("pause");
}