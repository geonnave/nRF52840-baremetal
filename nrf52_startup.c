#include <stdint.h>

// linker symbols for memory sections
extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _la_data;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _stack_top;

// the main function
int main(void);

// exception handlers
void Reset_Handler(void);
void NMI_Handler(void)                __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler(void)          __attribute__ ((weak, alias("Default_Handler")));
void MemoryManagement_Handler(void)   __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler(void)           __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler(void)         __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler(void)                __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler(void)           __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler(void)             __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler(void)            __attribute__ ((weak, alias("Default_Handler")));

// vector table (note that it is missing all interrupt handlers)
typedef void(*vector_table_t)(void);
extern const vector_table_t _vectors[16];
const vector_table_t _vectors[16] __attribute__((used, section(".isr_vector"))) = {
   (vector_table_t)&_stack_top,
    /* Exceptions */
    Reset_Handler,
    NMI_Handler,
    HardFault_Handler,
    MemoryManagement_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    0,
    0,
    0,
    0,
    SVC_Handler,
    DebugMon_Handler,
    0,
    PendSV_Handler,
    SysTick_Handler,
};

void Default_Handler(void)
{
	while(1);
}

void Reset_Handler(void) {
	// copy .data section to RAM
	uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata;
	uint8_t *pDst = (uint8_t*)&_sdata; // RAM
	uint8_t *pSrc = (uint8_t*)&_la_data; // Flash
	for(uint32_t i =0 ; i < size ; i++) {
		*pDst++ = *pSrc++;
	}
	
	// initialize the .bss section to zero in RAM
	size = (uint32_t)&_ebss - (uint32_t)&_sbss;
	pDst = (uint8_t*)&_sbss;
	for(uint32_t i =0 ; i < size ; i++) {
		*pDst++ = 0;
	}

	main();
}
