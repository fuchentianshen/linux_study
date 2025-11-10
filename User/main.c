#include "stdint.h"
#include "stm32f10x.h"
//��������
int main(void)
{
	/* ����GPIOA��ʱ�� */
	RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
	//*(uint32_t *)(0x40021000 + 0x18) = 4;

	/* ��PA0��PA1����Ϊͨ��������� */
	GPIOA->CRL |=GPIO_CRL_MODE0;
	GPIOA->CRL &= ~GPIO_CRL_CNF0;
	GPIOA->CRL |=GPIO_CRL_MODE1;
	GPIOA->CRL &= ~GPIO_CRL_CNF1;
	//*(uint32_t *)(0x40010800 + 0x00) = 0x33;
	//��PA8����Ϊͨ���������
	GPIOA->CRH |=GPIO_CRH_MODE8;
	GPIOA->CRH &= ~GPIO_CRH_CNF8;
	//*(uint32_t *)(0x40010800 + 0x04) = 0x03;
	/* ������Ĵ�����ֵ */
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
//dev2222


//0000
//1111


//dev2 555