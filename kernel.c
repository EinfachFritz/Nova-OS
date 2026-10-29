
void kernel_main(void)
{
    volatile unsigned short *screen =
        (volatile unsigned short *) 0xB8000;

    const char *message = "Hello from NOVA OS!";
    int i = 0;

    while (message[i] != '\0')
    {
        screen[i] = message[i] | 0x0F00;
        i++;
    }

   
    /* Tell the virtual computer that the test passed. */
    __asm__ volatile (
        "outb %0, %1"
        :
        : "a"((unsigned char)0x10),
          "Nd"((unsigned short)0xF4)
    );

    while (1)
    {
        __asm__ volatile ("hlt");
    }
