/******************************************************************************* 
����ͷ�ļ� 
*******************************************************************************/ 
#include	"config.h"

//LTC2440--��ر���������
s32		LTC2440_24BitADC = 0;

s32		LTC2440_24BitADC_Sum = 0;
u8		LTC2440_24BitADC_Cn = 0;

s32		LTC2440_24BitADCVoltage = 0;

//u8		LTC2440_24BitADC_Buf[4];

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

//-----------------------------Ӳ���ӿ�-�ײ�����-----------------------------

/************************************************************************* 
** ��������:	void	LTC2440_GPIO_Configuration(void)
** ��������: 	STM32F103C8T6����ʱ��8MHZ--��Ƶ72MHZ��
** ��    ��:
** ��������: 	2019.11.12
** ��    ��:	LTC2440��IO�ڳ�ʼ��
** ��ڲ���:	��
** ���ڲ���:	��
** ��    ע:	IO�����ģʽ��,��ͨ��CR2�Ĵ��������������
** ����ļ�: 
** �޸���־:
*************************************************************************/
void	LTC2440_GPIO_Configuration(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;						//����һ��GPIO_InitTypeDef���͵Ľṹ��

	//����GPIO
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB ,ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);	//����JTAG������ʹ��SW
	
	//LTC2440 ���нӿ�

	//LTC2440_CS			--GPIOB.04
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��Ϊ�����
	//GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//��Ϊ����ģʽ
	//GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//���������費ʹ��

	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	//LTC2440_CLK		--GPIOB.05
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��Ϊ�����
	//GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//��Ϊ����ģʽ
	//GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//���������費ʹ��

	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	//LTC2440_MISO		--GPIOB.06
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//GPIO_Mode_IN_FLOATING;
	//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
	//GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����

	GPIO_Init(GPIOB, &GPIO_InitStructure);

	//LTC2440_MOSI		--GPIOB.07
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��Ϊ�����
	//GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//��Ϊ����ģʽ
	//GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//���������費ʹ��

	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	//LTC2440_EXT			--GPIOB.03
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��Ϊ�����
	//GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//��Ϊ����ģʽ
	//GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//���������費ʹ��

	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	Set_LTC2440_CS;//LTC2440_CS = 1;
	Set_LTC2440_CLK;//LTC2440_CLK = 1;
	
	//Set_LTC2440_MISO;

	//SDI,EXT����ΪLOW���ɼ���LTC2410������
	Cls_LTC2440_MOSI;//LTC2440_SDI = 0;
	Cls_LTC2440_EXT;//LTC2440_EXT = 0;

	//delay_ms(1);
}

/************************************************************************* 
** ��������: 	void	Init_LTC2440(void)
** ��������: 	STM32F103C8T6����ʱ��8MHZ--��Ƶ72MHZ��
** ��    ��:     
** ��������: 	2019.11.12
** ��    ��:		��ʼ��LTC2440
** ��ڲ���: 	��
** ���ڲ���: 	��
** ��    ע:	SDI,EXT����ΪLOW���ɼ���LTC2410������
** ����ļ�: 
** �޸���־: 	2019.11.12
*************************************************************************/
void	Init_LTC2440(void)
{
	//���ƶ˿�����Ϊ���ģʽ
	//Set_LTC2440_CS;//LTC2440_CS = 1;
	//Set_LTC2440_CLK;//LTC2440_CLK = 1;
	
	//SDI,EXT����ΪLOW���ɼ���LTC2410������
	//Cls_LTC2440_MOSI;//LTC2440_SDI = 0;
	//Cls_LTC2440_EXT;//LTC2440_EXT = 0;

	//Reset_LTC2440();//�����λLTC2440

	//SysDelay1mS(1);
	delay_ms(1);
}
/************************************************************************* 
** ��������: 	s32		LTC2440_Read_3Byte(void)
** ��������: 	STM32F103C8T6����ʱ��8MHZ--��Ƶ72MHZ��
** ��    ��:     
** ��������: 	2019.11.12
** ��    ��:	���������մ����������ݡ����ֽڡ�
** ��ڲ���: 	��
** ���ڲ���: 	��ȡ������
** ��    ע:	ת�����Ϊ����ʱ���߸�λҪ�����⴦������Ϊ�����ʾ��ʽ���߸�λӦ��Ϊ0xFF��
** ��    ע:	�������⴦��--�൱��22Bit
** ����ļ�: 
** �޸���־: 	2019.11.12
*************************************************************************/
s32		LTC2440_Read_3Byte(void)
{
	u8		LTC2440_RxDataCn = 0 ;
	u8		LTC2440_RxDataChar = 0 ;

	s32		LTC2440_OutData = 0 ;
	
	Cls_LTC2440_CLK;//LTC2440_CLK = 0;
	LTC2440_SOME_NOP;

	Cls_LTC2440_CS;//LTC2440_CS = 0;
	LTC2440_SOME_NOP;

	//Bit31--EOC,Bit30--DMY,Bit29--SIG,Bit28--MSB .... Bit5--LSB24

	//�ɼ�LTC2440��EOC��DMY��SIG��Bit31,Bit30,Bit29,��
	for(LTC2440_RxDataCn = 0;LTC2440_RxDataCn < 3;LTC2440_RxDataCn++)
	{
		LTC2440_RxDataChar<<=1;

		//SDI Speed/Resolution Programming 
		//OSR4-ORS0:x1000--375nV--24--8192
		if(LTC2440_RxDataCn == 1)//���÷ֱ���
		{
			Set_LTC2440_MOSI;
		}
		if(LTC2440_RxDataCn > 1)
		{
			Cls_LTC2440_MOSI;
		}

		LTC2440_SOME_NOP;
		Set_LTC2440_CLK;//LTC2440_CLK = 1;

		LTC2440_SOME_NOP;
		if(Read_LTC2440_MISO)
		{
			LTC2440_RxDataChar|=1;//LTC2440_SDO = 1;
		}

		LTC2440_SOME_NOP;
		Cls_LTC2440_CLK;//LTC2440_CLK = 0;
	}

	//�ɼ�LTC2400��ת�������24λ���ݡ���Ч���ݡ�
	for(LTC2440_RxDataCn = 0;LTC2440_RxDataCn < 24;LTC2440_RxDataCn++)
	{
		LTC2440_OutData<<=1;

		LTC2440_SOME_NOP;
		Set_LTC2440_CLK;//LTC2440_CLK = 1;
		
		LTC2440_SOME_NOP;
		if(Read_LTC2440_MISO)
		{
			LTC2440_OutData|=1;//LTC2440_SDO = 1;
		}
		
		LTC2440_SOME_NOP;
		Cls_LTC2440_CLK;//LTC2440_CLK = 0;
	}
	
	//�ɼ�LTC2400��ת����������λ���ݡ���Ч���ݡ�
	for(LTC2440_RxDataCn = 0;LTC2440_RxDataCn < 5;LTC2440_RxDataCn++)
	{
		LTC2440_SOME_NOP;
		Set_LTC2440_CLK;//LTC2440_CLK = 1;

		if(Read_LTC2440_MISO)
		{
			//LTC2440_OutData|=1;//LTC2440_SDO = 1;
		}

		LTC2440_SOME_NOP;
		Cls_LTC2440_CLK;//LTC2440_CLK = 0;
	}
	
	Set_LTC2440_CS;//LTC2440_CS = 1;

    //���ɼ����ݷ���λ
	if(LTC2440_RxDataChar&&BIT0)//SIG == 1;
	{
		LTC2440_OutData = LTC2440_OutData;
	}
	else//SIG == 0;
	{
		//���ģʽ
		//v_value(LTC2440_OutData,0) = 0xFF;//�߸�λǿ�Ƹ�ֵ0xFF���൱����为���Ĳ��룬ʵ��ת�������ݵĸ߸�λΪ0x00��
		
		//С��ģʽ
		v_value(LTC2440_OutData,3) = 0xFF;//�߸�λǿ�Ƹ�ֵ0xFF���൱����为���Ĳ��룬ʵ��ת�������ݵĸ߸�λΪ0x00��
		//LTC2440_OutData = -LTC2440_OutData;
	}

	return LTC2440_OutData>>2;//���ؽ��յ������ݡ��൱��22Bit��
}
