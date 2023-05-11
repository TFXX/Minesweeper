#pragma once

#include "stdafx.h"

/**
	@fn ��ʾͨ�ؽ���
**/
void show_win(const score_t *pScore);

/**
	@fn ��ʾʧ�ܽ���
**/
void show_gameover(const score_t *pScore);

/**
	@fn ��ʾ��ʼ�˵�
**/
void show_first_play_menu();

/**
	@fn ��ʾ��һ������˵�
**/
void show_next_play_menu();

/**
	@fn ��ȡ��ҵ�һ�ε��, clickCount + 1
	@return ʼ�շ���1
**/
uint32_t get_click(uint32_t *pXPos, uint32_t *pYPos, score_t *pScore);

/**
	@fn ��ȡѡ��
	@return ����һ��menuChoice_t��������ʾ��������ѡ��
**/
menuChoice_t get_choice();

/**
	@fn ��ʾ���������ʾ��Ϣ
**/
void show_already_cleaned();

/**
	@fn ��ʾ��Ч�������ʾ��Ϣ
**/
void show_invalid_click();

/**
	@fn ��ʾ��Ч�������ʾ��Ϣ
**/
void show_illegal_input();

/**
	@fn ��ʾ��Ч�������ʾ��Ϣ
	@page ����ʾ��ҳ��
	@return ����һ����Чҳ����1�����ҳ����Ч�ķ���0
**/
uint32_t show_page(const surfacePage_t page);

/**
	@fn ��ʾ�������ҳ��
**/
void show_bye();