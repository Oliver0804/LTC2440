
#ifndef		__SPI_LTC2440_Drive_H__
#define		__SPI_LTC2440_Drive_H__

//LTC2440--相关变量的声明
extern	s32		LTC2440_24BitADC;
extern	s32		LTC2440_24BitADC_Sum;
extern	u8		LTC2440_24BitADC_Cn;

extern	s32		LTC2440_24BitADCVoltage;
//extern	u8		LTC2440_24BitADC_Buf[4];


//=========串口端口定义==========

//模拟LTC2440总线信号定义

// LTC2440_CS			--GPIOB.4
#define		Set_LTC2440_CS			GPIO_SetBits(GPIOB , GPIO_Pin_4)
#define		Cls_LTC2440_CS			GPIO_ResetBits(GPIOB , GPIO_Pin_4)

// LTC2440_CLK			—GPIOB.5
#define		Set_LTC2440_CLK			GPIO_SetBits(GPIOB , GPIO_Pin_5)
#define		Cls_LTC2440_CLK			GPIO_ResetBits(GPIOB , GPIO_Pin_5)

// LTC2440_SDO(MISO)	—GPIOB.6
#define		Set_LTC2440_MISO		GPIO_SetBits(GPIOB , GPIO_Pin_6)
#define		Cls_LTC2440_MISO		GPIO_ResetBits(GPIOB , GPIO_Pin_6)

//读LTC2440数据——LTC2440_SDO
#define		Read_LTC2440_MISO		GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6)	

//设置以下两个引脚【兼容LTC2410的接口驱动】
// LTC2440_SDI(MOSI)	—GPIOB.7
#define		Set_LTC2440_MOSI		GPIO_SetBits(GPIOB , GPIO_Pin_7)
#define		Cls_LTC2440_MOSI		GPIO_ResetBits(GPIOB , GPIO_Pin_7)

// LTC2440_EXT			--GPIOB.3
#define		Set_LTC2440_EXT			GPIO_SetBits(GPIOB , GPIO_Pin_3)
#define		Cls_LTC2440_EXT			GPIO_ResetBits(GPIOB , GPIO_Pin_3)

//系统空延时宏定义
#define		CPU_NOP_125nS			__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();

#define		LTC2440_NOP_250nS		CPU_NOP_125nS;CPU_NOP_125nS;
#define		LTC2440_NOP_375nS		CPU_NOP_125nS;CPU_NOP_125nS;CPU_NOP_125nS;

#define		LTC2440_NOP_500nS		CPU_NOP_125nS;CPU_NOP_125nS;CPU_NOP_125nS;
#define		LTC2440_NOP_1uS			LTC2440_NOP_500nS;LTC2440_NOP_500nS;

#define		LTC2440_SOME_NOP		LTC2440_NOP_1uS;LTC2440_NOP_250nS;



////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

//-----------------------------硬件接口-底层驱动-----------------------------

void	LTC2440_GPIO_Configuration(void);//LTC2440 端口配置

//模拟SPI模块的设置
void	Init_LTC2440(void);//初始化SPI总线

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

//-----------------------------应用接口--驱动-----------------------------
s32		LTC2440_Read_3Byte(void);//从指定地址读取三字节数据

#endif
