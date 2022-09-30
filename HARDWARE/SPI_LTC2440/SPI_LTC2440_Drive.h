
#ifndef		__SPI_LTC2440_Drive_H__
#define		__SPI_LTC2440_Drive_H__

//LTC2440--��ر���������
extern	s32		LTC2440_24BitADC;
extern	s32		LTC2440_24BitADC_Sum;
extern	u8		LTC2440_24BitADC_Cn;

extern	s32		LTC2440_24BitADCVoltage;
//extern	u8		LTC2440_24BitADC_Buf[4];


//=========���ڶ˿ڶ���==========

//ģ��LTC2440�����źŶ���

// LTC2440_CS			--GPIOB.4
#define		Set_LTC2440_CS			GPIO_SetBits(GPIOB , GPIO_Pin_4)
#define		Cls_LTC2440_CS			GPIO_ResetBits(GPIOB , GPIO_Pin_4)

// LTC2440_CLK			��GPIOB.5
#define		Set_LTC2440_CLK			GPIO_SetBits(GPIOB , GPIO_Pin_5)
#define		Cls_LTC2440_CLK			GPIO_ResetBits(GPIOB , GPIO_Pin_5)

// LTC2440_SDO(MISO)	��GPIOB.6
#define		Set_LTC2440_MISO		GPIO_SetBits(GPIOB , GPIO_Pin_6)
#define		Cls_LTC2440_MISO		GPIO_ResetBits(GPIOB , GPIO_Pin_6)

//��LTC2440���ݡ���LTC2440_SDO
#define		Read_LTC2440_MISO		GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6)	

//���������������š�����LTC2410�Ľӿ�������
// LTC2440_SDI(MOSI)	��GPIOB.7
#define		Set_LTC2440_MOSI		GPIO_SetBits(GPIOB , GPIO_Pin_7)
#define		Cls_LTC2440_MOSI		GPIO_ResetBits(GPIOB , GPIO_Pin_7)

// LTC2440_EXT			--GPIOB.3
#define		Set_LTC2440_EXT			GPIO_SetBits(GPIOB , GPIO_Pin_3)
#define		Cls_LTC2440_EXT			GPIO_ResetBits(GPIOB , GPIO_Pin_3)

//ϵͳ����ʱ�궨��
#define		CPU_NOP_125nS			__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();

#define		LTC2440_NOP_250nS		CPU_NOP_125nS;CPU_NOP_125nS;
#define		LTC2440_NOP_375nS		CPU_NOP_125nS;CPU_NOP_125nS;CPU_NOP_125nS;

#define		LTC2440_NOP_500nS		CPU_NOP_125nS;CPU_NOP_125nS;CPU_NOP_125nS;
#define		LTC2440_NOP_1uS			LTC2440_NOP_500nS;LTC2440_NOP_500nS;

#define		LTC2440_SOME_NOP		LTC2440_NOP_1uS;LTC2440_NOP_250nS;



////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

//-----------------------------Ӳ���ӿ�-�ײ�����-----------------------------

void	LTC2440_GPIO_Configuration(void);//LTC2440 �˿�����

//ģ��SPIģ�������
void	Init_LTC2440(void);//��ʼ��SPI����

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

//-----------------------------Ӧ�ýӿ�--����-----------------------------
s32		LTC2440_Read_3Byte(void);//��ָ����ַ��ȡ���ֽ�����

#endif
