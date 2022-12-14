
#include	"config.h"

//AD效率分析------
u16 ADP1_ips;//每秒AD输出速率
u16 ADP1_ict;//转换计数

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

//-----------------------------应用接口--驱动-----------------------------

/************************************************************************* 
** 函数名称: 	int   Main(void)
** 工作环境: 	STM32F103C8T6【主时钟8MHZ--倍频72MHZ】
** 作    者:
** 生成日期: 	2019.08.22
** 功    能: 	
** 入口参数: 	无
** 出口参数: 	无
** 备    注:
** 相关文件: 
** 修改日志:
*************************************************************************/
int    main(void)
{
	//RCC_Clock_Config(); 
	//GPIO_Configuration();

	delay_init();//延时函数初始化
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// 设置中断优先级分组2
	
	LTC2440_GPIO_Configuration();//LTC2400的端口配置
	Init_LTC2440();//初始化LTC2400

	LTC2440_24BitADC_Sum = 0;LTC2440_24BitADC_Cn = 0;

	while(1)
	{
		delay_ms(200);//AI采样周期--200mS--
		ADP1_ict = ADP1_ict + 1;
		LTC2440_24BitADC_Sum = LTC2440_24BitADC_Sum + LTC2440_Read_3Byte();
		LTC2440_24BitADC_Cn = LTC2440_24BitADC_Cn + 1;
	}
}

