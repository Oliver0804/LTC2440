/******************************************************************************************************
** File Name: config.h
** Descriptions: User Configurable File
********************************************************************************************************/
#ifndef		__CONFIG_H__ 
#define		__CONFIG_H__

/*-------------------------------------------------------------------------
 *   Standard Bits
 *-------------------------------------------------------------------------*/

#define		BIT0                (0x01)
#define		BIT1                (0x02)
#define		BIT2                (0x04)
#define		BIT3                (0x08)
#define		BIT4                (0x10)
#define		BIT5                (0x20)
#define		BIT6                (0x40)
#define		BIT7                (0x80)
#define		BIT8                (0x0100)
#define		BIT9                (0x0200)
#define		BITA                (0x0400)
#define		BITB                (0x0800)
#define		BITC                (0x1000)
#define		BITD                (0x2000)
#define		BITE                (0x4000)
#define		BITF                (0x8000)

//This segment should not be modified
#ifndef		TRUE
#define		TRUE		1
#endif

#ifndef		FALSE
#define		FALSE		0
#endif

typedef		unsigned	char	uint8;	/* defined for unsigned 8-bits integer variable 	�޷���8λ���ͱ���  */
typedef		signed		char	int8;	/* defined for signed 8-bits integer variable		�з���8λ���ͱ���  */
typedef		unsigned	int		uint16;	/* defined for unsigned 16-bits integer variable 	�޷���16λ���ͱ��� */
typedef		signed		int		int16;	/* defined for signed 16-bits integer variable 		�з���16λ���ͱ��� */
typedef		unsigned	long	uint32;	/* defined for unsigned 32-bits integer variable 	�޷���32λ���ͱ��� */
typedef		signed		long	int32;	/* defined for signed 32-bits integer variable 		�з���32λ���ͱ��� */
typedef		float				fp32;	/* single precision floating point variable (32bits) �����ȸ�������32λ���ȣ� */
typedef		double				fp64;	/* double precision floating point variable (64bits) ˫���ȸ�������64λ���ȣ� */


/********************************/
/*Application Program Configurations*/
/*     Ӧ�ó�������             */
/********************************/

//-------------------------�������Ͷ������

#include	"stm32f10x.h"              /* special function register declarations   */

#include 	<stm32f10x_conf.h>

#include	<stdio.h>
#include	<string.h>
#include	<math.h>

//#include	<intrins.h>
#include	<stdlib.h>

#include 	<stdio.h>
#include 	<string.h>
#include 	<ctype.h>
#include 	<stdlib.h>
#include 	<stdarg.h>

//#include 	<ucos_ii.h>

#include	"main.h"

#include	"delay.h"
#include	"sys.h"

//ϵͳӲ������

#include	"SPI_LTC2440_Drive.h"

//Ӧ�ýӿ�

#define		CPU_NOP_1uS			_nop_();

//430������ȫ��ȷ--���int
#define		v_value(src,x)				*((unsigned char*)&src+x)


#endif
/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/
