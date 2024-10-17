#include <stdint.h>

extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _la_data;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _stack_top;

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

typedef void(*vector_table_t)(void);
extern const vector_table_t _vectors[64];
const vector_table_t _vectors[64] __attribute__((used, section(".isr_vector"))) = {
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
    /* Device specific interrupt handlers */
    CLOCK_POWER_IRQHandler,
    RADIO_IRQHandler,
    UART0_UARTE0_IRQHandler,
    SPI0_SPIM0_SPIS0_TWI0_TWIM0_TWIS0_IRQHandler,
    SPI1_SPIM1_SPIS1_TWI1_TWIM1_TWIS1_IRQHandler,
    NFCT_IRQHandler,
    GPIOTE_IRQHandler,
    SAADC_IRQHandler,
    TIMER0_IRQHandler,
    TIMER1_IRQHandler,
    TIMER2_IRQHandler,
    RTC0_IRQHandler,
    TEMP_IRQHandler,
    RNG_IRQHandler,
    ECB_IRQHandler,
    AAR_CCM_IRQHandler,
    WDT_IRQHandler,
    RTC1_IRQHandler,
    QDEC_IRQHandler,
    COMP_LPCOMP_IRQHandler,
    EGU0_SWI0_IRQHandler,
    EGU1_SWI1_IRQHandler,
    EGU2_SWI2_IRQHandler,
    EGU3_SWI3_IRQHandler,
    EGU4_SWI4_IRQHandler,
    EGU5_SWI5_IRQHandler,
    TIMER3_IRQHandler,
    TIMER4_IRQHandler,
    PWM0_IRQHandler,
    PDM_IRQHandler,
    0,
    0,
    MWU_IRQHandler,
    PWM1_IRQHandler,
    PWM2_IRQHandler,
    SPI2_SPIM2_SPIS2_IRQHandler,
    RTC2_IRQHandler,
    I2S_IRQHandler,
    FPU_IRQHandler,
    USBD_IRQHandler,
    UARTE1_IRQHandler,
    QSPI_IRQHandler,
    CRYPTOCELL_IRQHandler,
    0,
    0,
    PWM3_IRQHandler,
    0,
    SPIM3_IRQHandler,
};

/*---------------------------------------------------------------------------
  Exception / Interrupt Handler
 *---------------------------------------------------------------------------*/
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
