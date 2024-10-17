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

  _la_data = LOADADDR(.data);

  .data :
  {
    _sdata = .;
    *(.data)
    _edata = .;
  } > RAM AT > FLASH

  .bss :
  {
    _sbss = .;
    __bss_start__ = _sbss;
    *(.bss)
    _ebss = .;
    __bss_end__ = _ebss;
  } > RAM

  /* Define the top of the stack (end of RAM) */
  _stack_top = ORIGIN(RAM) + LENGTH(RAM);
}
