#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include <windows.h>
#include <sysinfoapi.h>

#define COL 12
#define ROW 12

#define MINE_NUM 12

#define DIRECTION_RIGHT 1
#define DIRECTION_UP 2
#define DIRECTION_LEFT 4
#define DIRECTION_DOWN 8

//#define CLEAN_OUT_ROUND

//#define NO_REGULARLY_RANDOM

typedef enum{
	POS_EMPTY = 0,
	POS_1 = 1,
	POS_2 = 2,
	POS_3 = 3,
	POS_4 = 4,
	POS_5 = 5,
	POS_6 = 6,
	POS_7 = 7,
	POS_8 = 8,
	POS_UNKNOWN = 9,
	POS_MINE = 10,
	POS_INVALID = 11
} posStatus_t;

//��ǰҳ��
typedef enum{
	PAGE_INVALID,
	PAGE_FIRST_PLAY,
	PAGE_NEXT_PLAY,
	PAGE_PLAYING
} surfacePage_t;

//�˵�ѡ��
typedef enum{
	CHOICE_INVALID,
	CHOICE_FIRST_PLAY,
	CHOICE_NEXT_PLAY,
	CHOICE_RESTART,
	CHOICE_EXIT
} menuChoice_t;

typedef uint32_t direction_t;

typedef struct{
	uint32_t width;
	uint32_t heigh;
} rect_t;

typedef struct{
	rect_t *pMapRect;
	uint32_t *pUserBoard;
	uint32_t *pMineBoard;
} mineMap_t;

typedef struct{
	uint32_t clickCount;
	uint64_t beginTick64;
	uint64_t endTick64;
}score_t;

/**
	@fn ��ȡ�����״̬
	@return ����һ��posStatus_t���͵ı�������ʾ�����״̬
**/
posStatus_t get_pos_status(const rect_t *pRect, const uint32_t *const pBoard, const uint32_t xPos, const uint32_t yPos);

/**
	@fn ��ȡ��Χ�׵�����(O(8))
	@return ����[0, 8]֮���һ������
**/
uint32_t get_around_mine_num(const mineMap_t *const pMineMap, const uint32_t xCenterPos, const uint32_t yCenterPos);

/**
	@fn ���������״̬
	@return ���������Ч����0�����򷵻�1
**/
uint32_t set_pos_status(const rect_t *const pRect, uint32_t *const pBoard, const uint32_t xPos, const uint32_t yPos, const posStatus_t posStatus);

/**
	@fn �ݹ�ɨ��,�������߽���߸������׵ĸ��Ӻ�ֹͣ�ݹ�
	@param xPos ���̺�����
	@param yPos ����������
	@return ʼ�շ���1
**/
uint32_t clean_empty(const mineMap_t *const pMineMap, const uint32_t xPos, const uint32_t yPos, const direction_t direction);

/**
	@fn ���������⻷
	@return ʼ�շ���1
**/
uint32_t clean_out_round(const mineMap_t* const pMineMap);

/**
	@fn ��ָ������ɨ��
	@param xPos ���̺�����
	@param yPos ����������
	@return ����ȵ��׷���0����֮����1
**/
uint32_t clean_mine(const mineMap_t* pMineMap, uint32_t xPos, uint32_t yPos);


inline pause_and_exit(const char *str, const int i)
{
	fputs(str, stdout);
	system("pause");
	exit(i);
}