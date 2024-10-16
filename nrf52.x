MEMORY
{
  /* NOTE K = KiBi = 1024 bytes */
  FLASH : ORIGIN = 0x00000000, LENGTH = 256K
  RAM : ORIGIN = 0x20000000, LENGTH = 64K
}

SECTIONS
{
  .text :
  {
    *(.isr_vector)  /* Vector table */
    *(.text)
  } > FLASH

  .data :
  {
    *(.data)
  } > RAM AT > FLASH

  .bss :
  {
    __bss_start__ = .;
    *(.bss)
    __bss_end__ = .;
  } > RAM

  /* Define the top of the stack (end of RAM) */
  _stack_top = ORIGIN(RAM) + LENGTH(RAM);
}
