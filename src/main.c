#include "stm32kiss.h"
#include "usart_mini.h"
#include "packet_receiver.h"
#include "sfu_commands.h"

//#define SIMPLE_TEST
//#define TEST_PRINTF

#if !defined(SIMPLE_TEST) && !defined(TEST_PRINTF)
void main(void)
{
	ticks_init();
	usart_init();

	systick_on(1000);
	__WFI();
	__WFI();

	recive_packets_init();
	sfu_command_init();

	while (1)
	{
		recive_packets_worker();
		recive_packets_print_stat();
		__WFI();
	}
}
#endif

#ifdef TEST_PRINTF

#pragma GCC diagnostic ignored "-Wformat" //for simple printf without format %l modificator

volatile uint32_t testvalue = 0x12345677; //test data section initialization

void main(void)
{
	//SystemCoreClockUpdate();
	usart_init();
	ticks_init();
	delay_ms(1000);
	printf("SystemCoreClock\t%i\tHz\r\n", SystemCoreClock);

	while (1)
	{
		delay_ms(1000); //test delay and systemclock
		testvalue++;
		printf("testvalue\t%08X\r\n", testvalue);
	}
}
#endif

#ifdef SIMPLE_TEST
void main(void)
{
	usart_init();
	ticks_init();

	while (1)
	{
		delay_ms(100); //test delay and systemclock

		if (recive_count() > 100)
			send('!');

		uint8_t rx = 0;
		if (recive_byte(&rx))
			send(rx);
	}
}
#endif
