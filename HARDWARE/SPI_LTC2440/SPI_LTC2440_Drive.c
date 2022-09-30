/******************************************************************************* 
包含头文件 
*******************************************************************************/ 
#include	"config.h"

//LTC2440--相关变量的声明
s32		LTC2440_24BitADC = 0;

s32		LTC2440_24BitADC_Sum = 0;
u8		LTC2440_24BitADC_Cn = 0;

s32		LTC2440_24BitADCVoltage = 0;

//u8		LTC2440_24BitADC_Buf[4];

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

//-----------------------------硬件接口-底层驱动-----------------------------

/************************************************************************* 
** 函数名称:	void	LTC2440_GPIO_Configuration(void)
** 工作环境: 	STM32F103C8T6【主时钟8MHZ--倍频72MHZ】
** 作    者:
** 生成日期: 	2019.11.12
** 功    能:	LTC2440的IO口初始化
** 入口参数:	无
** 出口参数:	无
** 备    注:	IO在输出模式下,可通过CR2寄存器控制输出速率
** 相关文件: 
** 修改日志:
*************************************************************************/
void	LTC2440_GPIO_Configuration(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;						//定义一个GPIO_InitTypeDef类型的结构体

	//启动GPIO
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB ,ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);	//禁用JTAG，可以使用SW
	
	//LTC2440 串行接口

	//LTC2440_CS			--GPIOB.04
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//设为输出口
	//GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//设为推挽模式
	//GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//上下拉电阻不使能

	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	//LTC2440_CLK		--GPIOB.05
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//设为输出口
	//GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//设为推挽模式
	//GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//上下拉电阻不使能

	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	//LTC2440_MISO		--GPIOB.06
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//GPIO_Mode_IN_FLOATING;
	//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
	//GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉

	GPIO_Init(GPIOB, &GPIO_InitStructure);

	//LTC2440_MOSI		--GPIOB.07
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//设为输出口
	//GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//设为推挽模式
	//GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//上下拉电阻不使能

	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	//LTC2440_EXT			--GPIOB.03
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//设为输出口
	//GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//设为推挽模式
	//GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//上下拉电阻不使能

	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	Set_LTC2440_CS;//LTC2440_CS = 1;
	Set_LTC2440_CLK;//LTC2440_CLK = 1;
	
	//Set_LTC2440_MISO;

	//SDI,EXT设置为LOW【可兼容LTC2410驱动】
	Cls_LTC2440_MOSI;//LTC2440_SDI = 0;
	Cls_LTC2440_EXT;//LTC2440_EXT = 0;

	//delay_ms(1);
}

/************************************************************************* 
** 函数名称: 	void	Init_LTC2440(void)
** 工作环境: 	STM32F103C8T6【主时钟8MHZ--倍频72MHZ】
** 作    者:     
** 生成日期: 	2019.11.12
** 功    能:		初始化LTC2440
** 入口参数: 	无
** 出口参数: 	无
** 备    注:	SDI,EXT设置为LOW【可兼容LTC2410驱动】
** 相关文件: 
** 修改日志: 	2019.11.12
*************************************************************************/
void	Init_LTC2440(void)
{
	//控制端口设置为输出模式
	//Set_LTC2440_CS;//LTC2440_CS = 1;
	//Set_LTC2440_CLK;//LTC2440_CLK = 1;
	
	//SDI,EXT设置为LOW【可兼容LTC2410驱动】
	//Cls_LTC2440_MOSI;//LTC2440_SDI = 0;
	//Cls_LTC2440_EXT;//LTC2440_EXT = 0;

	//Reset_LTC2440();//软件复位LTC2440

	//SysDelay1mS(1);
	delay_ms(1);
}
/************************************************************************* 
** 函数名称: 	s32		LTC2440_Read_3Byte(void)
** 工作环境: 	STM32F103C8T6【主时钟8MHZ--倍频72MHZ】
** 作    者:     
** 生成日期: 	2019.11.12
** 功    能:	主控器接收从器件方数据【三字节】
** 入口参数: 	无
** 出口参数: 	读取的数据
** 备    注:	转换结果为负数时，高高位要做特殊处理【负数为补码表示方式，高高位应该为0xFF】
** 备    注:	进行特殊处理--相当于22Bit
** 相关文件: 
** 修改日志: 	2019.11.12
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

	//采集LTC2440的EOC、DMY、SIG【Bit31,Bit30,Bit29,】
	for(LTC2440_RxDataCn = 0;LTC2440_RxDataCn < 3;LTC2440_RxDataCn++)
	{
		LTC2440_RxDataChar<<=1;

		//SDI Speed/Resolution Programming 
		//OSR4-ORS0:x1000--375nV--24--8192
		if(LTC2440_RxDataCn == 1)//设置分辨率
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

	//采集LTC2400的转换结果的24位数据【有效数据】
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
	
	//采集LTC2400的转换结果的最后几位数据【无效数据】
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

    //检测采集数据符号位
	if(LTC2440_RxDataChar&&BIT0)//SIG == 1;
	{
		LTC2440_OutData = LTC2440_OutData;
	}
	else//SIG == 0;
	{
		//大端模式
		//v_value(LTC2440_OutData,0) = 0xFF;//高高位强制赋值0xFF【相当于填充负数的补码，实际转换的数据的高高位为0x00】
		
		//小端模式
		v_value(LTC2440_OutData,3) = 0xFF;//高高位强制赋值0xFF【相当于填充负数的补码，实际转换的数据的高高位为0x00】
		//LTC2440_OutData = -LTC2440_OutData;
	}

	return LTC2440_OutData>>2;//返回接收到的数据【相当于22Bit】
}
