#include "stdint.h"
#include "stm32f10x.h"
//打开三个灯
int main(void)
{
	/* 开启GPIOA的时钟 */
	RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
	//*(uint32_t *)(0x40021000 + 0x18) = 4;

	/* 给PA0、PA1设置为通用推挽输出 */
	GPIOA->CRL |=GPIO_CRL_MODE0;
	GPIOA->CRL &= ~GPIO_CRL_CNF0;
	GPIOA->CRL |=GPIO_CRL_MODE1;
	GPIOA->CRL &= ~GPIO_CRL_CNF1;
	//*(uint32_t *)(0x40010800 + 0x00) = 0x33;
	//给PA8设置为通用推挽输出
	GPIOA->CRH |=GPIO_CRH_MODE8;
	GPIOA->CRH &= ~GPIO_CRH_CNF8;
	//*(uint32_t *)(0x40010800 + 0x04) = 0x03;
	/* 给输出寄存器赋值 */
	GPIOA->ODR &= ~GPIO_ODR_ODR0;
	GPIOA->ODR &= ~GPIO_ODR_ODR1;
	GPIOA->ODR &= ~GPIO_ODR_ODR8;
	//*(uint32_t *)(0x40010800 + 0x0c) = 0xfefc;
	while (1)
	{
	}
}
//1111
//dev 111
//dev2 111