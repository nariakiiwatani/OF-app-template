/*!
*/
#pragma once

typedef unsigned long u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed long s64;
typedef signed int s32;
typedef signed short s16;
typedef signed char s8;
typedef double f64;
typedef float f32;

// スクリーンサイズ
const s32 SCREEN_WIDTH = 1920;
const s32 SCREEN_HEIGHT = 1080;
const s32 SCREEN_WIDTH_DRAW = 1920;
const s32 SCREEN_HEIGHT_DRAW = 1080;

// 更新プライオリティ
enum {
	PRIO_UPDATE_TOP,

	PRIO_UPDATE_CORE_BEFORE_CLEAR,
	PRIO_UPDATE_CORE_CLEAR,
	PRIO_UPDATE_CORE_AFTER_CLEAR,

	PRIO_UPDATE_CORE_BEFORE_PREPARE,
	PRIO_UPDATE_CORE_PREPARE,
	PRIO_UPDATE_CORE_AFTER_PREPARE,

	PRIO_UPDATE_CORE_BEFORE_UPDATE,
	PRIO_UPDATE_CORE_UPDATE,
	PRIO_UPDATE_CORE_AFTER_UPDATE,

	PRIO_UPDATE_CORE_BEFORE_CLEANUP,
	PRIO_UPDATE_CORE_CLEANUP,
	PRIO_UPDATE_CORE_AFTER_CLEANUP,

	PRIO_UPDATE_BOTTOM
};

// 描画プライオリティ
enum {
	PRIO_DRAW_TOP,

	PRIO_DRAW_BOTTOM
};


/* EOF */