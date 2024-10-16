#include<stdint.h>

#define SRAM_START  0x20000000U
#define SRAM_SIZE   (64U * 1024U) //128KB
#define SRAM_END    ((SRAM_START) + (SRAM_SIZE))

#define STACK_START   SRAM_END

extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _la_data;

extern uint32_t _sbss;
extern uint32_t _ebss;

int main(void);

/*---------------------------------------------------------------------------
  Prototypes for Exception / Interrupt Handlers
 *---------------------------------------------------------------------------*/
/* Exceptions */
void Reset_Handler(void);

void NMI_Handler(void) { while(1); }

void HardFault_Handler(void) { while(1); }

void MemoryManagement_Handler(void) { while(1); }

void BusFault_Handler(void) { while(1); }

void UsageFault_Handler(void) { while(1); }

void SVC_Handler(void) { while(1); }

void DebugMon_Handler(void) { while(1); }

void PendSV_Handler(void) { while(1); }

void SysTick_Handler(void) { while(1); }

/* Device specific interrupt handlers */
void CLOCK_POWER_IRQHandler                                      (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void RADIO_IRQHandler                                            (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void UART0_UARTE0_IRQHandler                                     (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void SPI0_SPIM0_SPIS0_TWI0_TWIM0_TWIS0_IRQHandler                (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void SPI1_SPIM1_SPIS1_TWI1_TWIM1_TWIS1_IRQHandler                (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void NFCT_IRQHandler                                             (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void GPIOTE_IRQHandler                                           (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void SAADC_IRQHandler                                            (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void TIMER0_IRQHandler                                           (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void TIMER1_IRQHandler                                           (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void TIMER2_IRQHandler                                           (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void RTC0_IRQHandler                                             (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void TEMP_IRQHandler                                             (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void RNG_IRQHandler                                              (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void ECB_IRQHandler                                              (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void AAR_CCM_IRQHandler                                          (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void WDT_IRQHandler                                              (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void RTC1_IRQHandler                                             (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void QDEC_IRQHandler                                             (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void COMP_LPCOMP_IRQHandler                                      (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void EGU0_SWI0_IRQHandler                                        (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void EGU1_SWI1_IRQHandler                                        (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void EGU2_SWI2_IRQHandler                                        (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void EGU3_SWI3_IRQHandler                                        (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void EGU4_SWI4_IRQHandler                                        (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void EGU5_SWI5_IRQHandler                                        (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void TIMER3_IRQHandler                                           (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void TIMER4_IRQHandler                                           (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void PWM0_IRQHandler                                             (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void PDM_IRQHandler                                              (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void MWU_IRQHandler                                              (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void PWM1_IRQHandler                                             (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void PWM2_IRQHandler                                             (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void SPI2_SPIM2_SPIS2_IRQHandler                                 (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void RTC2_IRQHandler                                             (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void I2S_IRQHandler                                              (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void FPU_IRQHandler                                              (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void USBD_IRQHandler                                             (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void UARTE1_IRQHandler                                           (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void QSPI_IRQHandler                                             (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void CRYPTOCELL_IRQHandler                                       (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void PWM3_IRQHandler                                             (void) __attribute__ ((weak, alias("Default_Handler"))) ;
void SPIM3_IRQHandler                                            (void) __attribute__ ((weak, alias("Default_Handler"))) ;

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

// __VECTOR_TABLE_ATTRIBUTE const VECTOR_TABLE_Type __VECTOR_TABLE[] = {
//     (VECTOR_TABLE_Type)(__STACK_BASE),
uint32_t vectors[] __attribute__((section(".isr_vector")))   = {
    STACK_START,
/* Exceptions */
    (uint32_t)Reset_Handler,
    (uint32_t)NMI_Handler,
    (uint32_t)HardFault_Handler,
    (uint32_t)MemoryManagement_Handler,
    (uint32_t)BusFault_Handler,
    (uint32_t)UsageFault_Handler,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)SVC_Handler,
    (uint32_t)DebugMon_Handler,
    (uint32_t)0,
    (uint32_t)PendSV_Handler,
    (uint32_t)SysTick_Handler,
/* Device specific interrupt handlers */
    (uint32_t)CLOCK_POWER_IRQHandler,
    (uint32_t)RADIO_IRQHandler,
    (uint32_t)UART0_UARTE0_IRQHandler,
    (uint32_t)SPI0_SPIM0_SPIS0_TWI0_TWIM0_TWIS0_IRQHandler,
    (uint32_t)SPI1_SPIM1_SPIS1_TWI1_TWIM1_TWIS1_IRQHandler,
    (uint32_t)NFCT_IRQHandler,
    (uint32_t)GPIOTE_IRQHandler,
    (uint32_t)SAADC_IRQHandler,
    (uint32_t)TIMER0_IRQHandler,
    (uint32_t)TIMER1_IRQHandler,
    (uint32_t)TIMER2_IRQHandler,
    (uint32_t)RTC0_IRQHandler,
    (uint32_t)TEMP_IRQHandler,
    (uint32_t)RNG_IRQHandler,
    (uint32_t)ECB_IRQHandler,
    (uint32_t)AAR_CCM_IRQHandler,
    (uint32_t)WDT_IRQHandler,
    (uint32_t)RTC1_IRQHandler,
    (uint32_t)QDEC_IRQHandler,
    (uint32_t)COMP_LPCOMP_IRQHandler,
    (uint32_t)EGU0_SWI0_IRQHandler,
    (uint32_t)EGU1_SWI1_IRQHandler,
    (uint32_t)EGU2_SWI2_IRQHandler,
    (uint32_t)EGU3_SWI3_IRQHandler,
    (uint32_t)EGU4_SWI4_IRQHandler,
    (uint32_t)EGU5_SWI5_IRQHandler,
    (uint32_t)TIMER3_IRQHandler,
    (uint32_t)TIMER4_IRQHandler,
    (uint32_t)PWM0_IRQHandler,
    (uint32_t)PDM_IRQHandler,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)MWU_IRQHandler,
    (uint32_t)PWM1_IRQHandler,
    (uint32_t)PWM2_IRQHandler,
    (uint32_t)SPI2_SPIM2_SPIS2_IRQHandler,
    (uint32_t)RTC2_IRQHandler,
    (uint32_t)I2S_IRQHandler,
    (uint32_t)FPU_IRQHandler,
    (uint32_t)USBD_IRQHandler,
    (uint32_t)UARTE1_IRQHandler,
    (uint32_t)QSPI_IRQHandler,
    (uint32_t)CRYPTOCELL_IRQHandler,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)PWM3_IRQHandler,
    (uint32_t)0,
    (uint32_t)SPIM3_IRQHandler,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
};

/*---------------------------------------------------------------------------
  Exception / Interrupt Handler
 *---------------------------------------------------------------------------*/
void Default_Handler(void)
{
	while(1);
}

void Reset_Handler(void) {

	//copy .data section to RAM
	uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata;
	
	uint8_t *pDst = (uint8_t*)&_sdata; // RAM
	uint8_t *pSrc = (uint8_t*)&_la_data; // Flash
	
	for(uint32_t i =0 ; i < size ; i++)
	{
		*pDst++ = *pSrc++;
	}
	
	//Init. the .bss section to zero in RAM
	size = (uint32_t)&_ebss - (uint32_t)&_sbss;
	pDst = (uint8_t*)&_sbss;
	for(uint32_t i =0 ; i < size ; i++)
	{
		*pDst++ = 0;
	}

	main();
	
}
