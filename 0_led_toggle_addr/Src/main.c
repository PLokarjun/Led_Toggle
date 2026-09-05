//where is the led connected
//port:A or B
//pin:5 or 13
#define RCC_BASE        0x40023800UL
#define GPIOA_BASE      0x40020000UL

#define RCC_AHB1EN_R    (*(volatile unsigned int *)(RCC_BASE + 0x30))
#define GPIOA_MODE_R    (*(volatile unsigned int *)(GPIOA_BASE + 0x00))
#define GPIOA_OD_R      (*(volatile unsigned int *)(GPIOA_BASE + 0x14))

#define GPIOAEN         (1U << 0)
#define PIN5            (1U << 5)

int main(void)
{
    /* Enable GPIOA clock */
    RCC_AHB1EN_R |= GPIOAEN;

    /* Configure PA5 as output */
    GPIOA_MODE_R |=  (1U << 10);
    GPIOA_MODE_R &= ~(1U << 11);

    while(1)
    {
        /* Turn LED ON */
        GPIOA_OD_R |= PIN5;
        // toggle pin
        GPIOA_OD_R ^= PIN5;
        for (volatile unsigned int i=0;i<100000;i++)
        {

        }
    }
}
