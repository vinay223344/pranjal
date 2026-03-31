//#include <stdint.h>
//
///* ================= RCC ================= */
//#define RCC_BASE        0x40021000
//#define RCC_APB1ENR1    (*(volatile uint32_t*)(RCC_BASE + 0x58))
//#define RCC_BDCR        (*(volatile uint32_t*)(RCC_BASE + 0x90))
//#define RCC_CSR         (*(volatile uint32_t*)(RCC_BASE + 0x94))
//
//#define RCC_AHB2ENR     (*(volatile uint32_t*)(RCC_BASE + 0x4C))
//
///* ================= GPIO ================= */
//#define GPIOA_BASE      0x48000000
//#define GPIOB_BASE      0x48000400
//
//#define GPIOA_MODER     (*(volatile uint32_t*)(GPIOA_BASE + 0x00))
//#define GPIOA_BSRR      (*(volatile uint32_t*)(GPIOA_BASE + 0x18))
//
//#define GPIOB_MODER     (*(volatile uint32_t*)(GPIOB_BASE + 0x00))
//#define GPIOB_OTYPER    (*(volatile uint32_t*)(GPIOB_BASE + 0x04))
//#define GPIOB_PUPDR     (*(volatile uint32_t*)(GPIOB_BASE + 0x0C))
//#define GPIOB_AFRH      (*(volatile uint32_t*)(GPIOB_BASE + 0x24))
//
///* ================= PWR ================= */
//#define PWR_BASE        0x40007000
//#define PWR_CR1         (*(volatile uint32_t*)(PWR_BASE + 0x00))
//
///* ================= RTC ================= */
//#define RTC_BASE        0x40002800
//#define RTC_TR          (*(volatile uint32_t*)(RTC_BASE + 0x00))
//#define RTC_DR          (*(volatile uint32_t*)(RTC_BASE + 0x04))
//#define RTC_ISR         (*(volatile uint32_t*)(RTC_BASE + 0x0C))
//#define RTC_PRER        (*(volatile uint32_t*)(RTC_BASE + 0x10))
//#define RTC_WPR         (*(volatile uint32_t*)(RTC_BASE + 0x24))
//#define RTC_BKP0R       (*(volatile uint32_t*)(RTC_BASE + 0x50))
//
///* ================= I2C ================= */
//#define I2C1_BASE       0x40005400
//#define I2C1_CR1        (*(volatile uint32_t*)(I2C1_BASE + 0x00))
//#define I2C1_CR2        (*(volatile uint32_t*)(I2C1_BASE + 0x04))
//#define I2C1_TIMINGR    (*(volatile uint32_t*)(I2C1_BASE + 0x10))
//#define I2C1_ISR        (*(volatile uint32_t*)(I2C1_BASE + 0x18))
//#define I2C1_TXDR       (*(volatile uint32_t*)(I2C1_BASE + 0x28))
//
//#define OLED_ADDR 0x3C
//
///* ================= DELAY ================= */
//void delay(volatile int t){ while(t--); }
//
///* ================= FONT ================= */
//uint8_t font[10][5] = {
//{0x3E,0x51,0x49,0x45,0x3E},{0x00,0x42,0x7F,0x40,0x00},
//{0x42,0x61,0x51,0x49,0x46},{0x21,0x41,0x45,0x4B,0x31},
//{0x18,0x14,0x12,0x7F,0x10},{0x27,0x45,0x45,0x45,0x39},
//{0x3C,0x4A,0x49,0x49,0x30},{0x01,0x71,0x09,0x05,0x03},
//{0x36,0x49,0x49,0x49,0x36},{0x06,0x49,0x49,0x29,0x1E}
//};
//
//uint8_t font_colon[5]={0x00,0x36,0x36,0x00,0x00};
//uint8_t font_slash[5]={0x20,0x10,0x08,0x04,0x02};
//
///* ================= OLED ================= */
//void oled_cmd(uint8_t cmd)
//{
//    I2C1_CR2 = (OLED_ADDR<<1) | (2<<16);
//    I2C1_CR2 |= (1<<13);
//
//    while(!(I2C1_ISR&(1<<1)));
//    I2C1_TXDR = 0x00;
//
//    while(!(I2C1_ISR&(1<<1)));
//    I2C1_TXDR = cmd;
//
//    while(!(I2C1_ISR&(1<<6)));
//    I2C1_CR2 |= (1<<14);
//}
//
//void oled_data(uint8_t data)
//{
//    I2C1_CR2 = (OLED_ADDR<<1) | (2<<16);
//    I2C1_CR2 |= (1<<13);
//
//    while(!(I2C1_ISR&(1<<1)));
//    I2C1_TXDR = 0x40;
//
//    while(!(I2C1_ISR&(1<<1)));
//    I2C1_TXDR = data;
//
//    while(!(I2C1_ISR&(1<<6)));
//    I2C1_CR2 |= (1<<14);
//}
//
//void oled_set_pos(uint8_t page, uint8_t col)
//{
//    oled_cmd(0xB0 + page);
//    oled_cmd(0x00 + (col & 0x0F));
//    oled_cmd(0x10 + (col >> 4));
//}
//
//void oled_clear()
//{
//    for(int page=0; page<8; page++)
//    {
//        oled_set_pos(page,0);
//        for(int i=0;i<128;i++)
//            oled_data(0x00);
//    }
//}
//
//void oled_char(uint8_t *ch)
//{
//    for(int i=0;i<5;i++)
//        oled_data(ch[i]);
//    oled_data(0x00);
//}
//
//void oled_print_num(uint8_t num)
//{
//    oled_char(font[num/10]);
//    oled_char(font[num%10]);
//}
//
///* ================= RTC ================= */
//void rtc_init()
//{
//    RCC_APB1ENR1 |= (1<<28);   // PWR clock
//    PWR_CR1 |= (1<<8);         // Backup access
//
//    if(RTC_BKP0R == 0x1234) return;
//
//    /* 🔥 RESET BACKUP DOMAIN (IMPORTANT) */
//    RCC_BDCR |= (1<<16);   // BDRST
//    RCC_BDCR &= ~(1<<16);
//
//    /* 🔥 ENABLE LSE */
//    RCC_BDCR |= (1<<0);        // LSEON
//    while(!(RCC_BDCR & (1<<1))); // LSERDY
//
//    /* 🔥 SELECT LSE ONLY */
//    RCC_BDCR &= ~(3<<8);
//    RCC_BDCR |= (1<<8);        // LSE selected
//
//    RCC_BDCR |= (1<<15);       // RTC enable
//
//    /* 🔥 RTC CONFIG */
//    RTC_WPR = 0xCA;
//    RTC_WPR = 0x53;
//
//    RTC_ISR |= (1<<7);
//    while(!(RTC_ISR & (1<<6)));
//
//    /* 🔥 PERFECT 1 SECOND */
//    RTC_PRER = (127<<16) | 255;
//
//    RTC_TR = (0x12<<16); // 12:00:00
//    RTC_DR = (0x26<<16)|(0x03<<8)|(0x31);
//
//    RTC_ISR &= ~(1<<7);
//
//    RTC_WPR = 0xFF;
//
//    RTC_BKP0R = 0x1234;
//}
//void rtc_read_time(uint8_t *h,uint8_t *m,uint8_t *s)
//{
//    uint32_t t=RTC_TR;
//    *h=((t>>20)&0xF)*10+((t>>16)&0xF);
//    *m=((t>>12)&0xF)*10+((t>>8)&0xF);
//    *s=((t>>4)&0xF)*10+(t&0xF);
//}
//
//void rtc_read_date(uint8_t *d,uint8_t *mo,uint8_t *y)
//{
//    uint32_t t=RTC_DR;
//    *y=((t>>20)&0xF)*10+((t>>16)&0xF);
//    *mo=((t>>12)&0xF)*10+((t>>8)&0xF);
//    *d=((t>>4)&0xF)*10+(t&0xF);
//}
//
///* ================= MAIN ================= */
//int main()
//{
//    uint8_t h,m,s,d,mo,y;
//    /* ================= CLOCK ENABLE ================= */
//    RCC_AHB2ENR |= (1<<0) | (1<<1);   // GPIOA + GPIOB
//    RCC_APB1ENR1 |= (1<<21);          // I2C1
//
//    /* ================= GPIO CONFIG ================= */
//    // PB8, PB9 → I2C
//    GPIOB_MODER &= ~(3<<(8*2)) & ~(3<<(9*2));
//    GPIOB_MODER |=  (2<<(8*2)) | (2<<(9*2));
//
//    GPIOB_AFRH |= (4<<0) | (4<<4);
//
//    GPIOB_OTYPER |= (1<<8)|(1<<9);
//
//    GPIOB_PUPDR |= (1<<(8*2)) | (1<<(9*2));
//
//    /* ================= I2C INIT ================= */
//    I2C1_CR1 &= ~(1<<0);
//    I2C1_TIMINGR = 0x00707CBB;
//    I2C1_CR1 |= (1<<0);
//
////    delay(100000);
//
//    /* ================= OLED INIT ================= */
//    oled_cmd(0xAE);
//    oled_cmd(0xD5); oled_cmd(0x80);
//    oled_cmd(0xA8); oled_cmd(0x3F);
//    oled_cmd(0xD3); oled_cmd(0x00);
//    oled_cmd(0x40);
//    oled_cmd(0x8D); oled_cmd(0x14);
//    oled_cmd(0x20); oled_cmd(0x00);
//    oled_cmd(0xA1);
//    oled_cmd(0xC8);
//    oled_cmd(0xDA); oled_cmd(0x12);
//    oled_cmd(0x81); oled_cmd(0x7F);
//    oled_cmd(0xD9); oled_cmd(0xF1);
//    oled_cmd(0xDB); oled_cmd(0x40);
//    oled_cmd(0xA4);
//    oled_cmd(0xA6);
//    oled_cmd(0xAF);
//
//    oled_clear();
//
//    rtc_init();
//
//    while(1)
//    {
//        static uint8_t prev_s = 255;
//
//        rtc_read_time(&h,&m,&s);
//        rtc_read_date(&d,&mo,&y);
//
//        if(s != prev_s)
//        {
//            prev_s = s;
//
//            oled_set_pos(0,0);
//            oled_print_num(h); oled_char(font_colon);
//            oled_print_num(m); oled_char(font_colon);
//            oled_print_num(s);
//
//            oled_set_pos(2,0);
//            oled_print_num(d); oled_char(font_slash);
//            oled_print_num(mo); oled_char(font_slash);
//            oled_print_num(y);
//        }
//    }
//}















//#include <stdint.h>
//
///* ================= RCC ================= */
//#define RCC_BASE        0x40021000
//#define RCC_APB1ENR1    (*(volatile uint32_t*)(RCC_BASE + 0x58))
//#define RCC_BDCR        (*(volatile uint32_t*)(RCC_BASE + 0x90))
//#define RCC_AHB2ENR     (*(volatile uint32_t*)(RCC_BASE + 0x4C))
//
///* ================= GPIO ================= */
//#define GPIOA_BASE      0x48000000
//#define GPIOB_BASE      0x48000400
//
//#define GPIOA_MODER     (*(volatile uint32_t*)(GPIOA_BASE + 0x00))
//#define GPIOA_AFRL      (*(volatile uint32_t*)(GPIOA_BASE + 0x20))
//
//#define GPIOB_MODER     (*(volatile uint32_t*)(GPIOB_BASE + 0x00))
//#define GPIOB_OTYPER    (*(volatile uint32_t*)(GPIOB_BASE + 0x04))
//#define GPIOB_PUPDR     (*(volatile uint32_t*)(GPIOB_BASE + 0x0C))
//#define GPIOB_AFRH      (*(volatile uint32_t*)(GPIOB_BASE + 0x24))
//
///* ================= USART2 ================= */
//#define USART2_BASE 0x40004400
//#define USART2_CR1  (*(volatile uint32_t*)(USART2_BASE + 0x00))
//#define USART2_BRR  (*(volatile uint32_t*)(USART2_BASE + 0x0C))
//#define USART2_ISR  (*(volatile uint32_t*)(USART2_BASE + 0x1C))
//#define USART2_RDR  (*(volatile uint32_t*)(USART2_BASE + 0x24))
//
///* ================= PWR ================= */
//#define PWR_BASE        0x40007000
//#define PWR_CR1         (*(volatile uint32_t*)(PWR_BASE + 0x00))
//
///* ================= RTC ================= */
//#define RTC_BASE        0x40002800
//#define RTC_TR          (*(volatile uint32_t*)(RTC_BASE + 0x00))
//#define RTC_ISR         (*(volatile uint32_t*)(RTC_BASE + 0x0C))
//#define RTC_PRER        (*(volatile uint32_t*)(RTC_BASE + 0x10))
//#define RTC_WPR         (*(volatile uint32_t*)(RTC_BASE + 0x24))
//
///* ================= I2C ================= */
//#define I2C1_BASE       0x40005400
//#define I2C1_CR1        (*(volatile uint32_t*)(I2C1_BASE + 0x00))
//#define I2C1_CR2        (*(volatile uint32_t*)(I2C1_BASE + 0x04))
//#define I2C1_TIMINGR    (*(volatile uint32_t*)(I2C1_BASE + 0x10))
//#define I2C1_ISR        (*(volatile uint32_t*)(I2C1_BASE + 0x18))
//#define I2C1_TXDR       (*(volatile uint32_t*)(I2C1_BASE + 0x28))
//
//#define OLED_ADDR 0x3C
//
///* ================= FONT ================= */
//uint8_t font[10][5] = {
//{0x3E,0x51,0x49,0x45,0x3E},{0x00,0x42,0x7F,0x40,0x00},
//{0x42,0x61,0x51,0x49,0x46},{0x21,0x41,0x45,0x4B,0x31},
//{0x18,0x14,0x12,0x7F,0x10},{0x27,0x45,0x45,0x45,0x39},
//{0x3C,0x4A,0x49,0x49,0x30},{0x01,0x71,0x09,0x05,0x03},
//{0x36,0x49,0x49,0x49,0x36},{0x06,0x49,0x49,0x29,0x1E}
//};
//
//uint8_t font_colon[5]={0x00,0x36,0x36,0x00,0x00};
//
///* ================= UART ================= */
//void uart_init()
//{
//    RCC_AHB2ENR |= (1<<0);
//    RCC_APB1ENR1 |= (1<<17);
//
//    GPIOA_MODER &= ~(3<<(2*2)) & ~(3<<(3*2));
//    GPIOA_MODER |=  (2<<(2*2)) | (2<<(3*2));
//
//    GPIOA_AFRL |= (7<<(2*4)) | (7<<(3*4));
//
//    USART2_BRR = 0x1A1;
//    USART2_CR1 |= (1<<2);
//    USART2_CR1 |= (1<<0);
//}
//
//void uart_receive(char *buf)
//{
//    int i = 0;
//    while(1)
//    {
//        while(!(USART2_ISR & (1<<5)));
//        char c = USART2_RDR;
//        if(c == '\n') break;
//        buf[i++] = c;
//    }
//}
//
///* ================= I2C + OLED ================= */
//void oled_cmd(uint8_t cmd)
//{
//    I2C1_CR2 = (OLED_ADDR<<1) | (2<<16);
//    I2C1_CR2 |= (1<<13);
//
//    while(!(I2C1_ISR&(1<<1)));
//    I2C1_TXDR = 0x00;
//
//    while(!(I2C1_ISR&(1<<1)));
//    I2C1_TXDR = cmd;
//
//    while(!(I2C1_ISR&(1<<6)));
//    I2C1_CR2 |= (1<<14);
//}
//
//void oled_data(uint8_t data)
//{
//    I2C1_CR2 = (OLED_ADDR<<1) | (2<<16);
//    I2C1_CR2 |= (1<<13);
//
//    while(!(I2C1_ISR&(1<<1)));
//    I2C1_TXDR = 0x40;
//
//    while(!(I2C1_ISR&(1<<1)));
//    I2C1_TXDR = data;
//
//    while(!(I2C1_ISR&(1<<6)));
//    I2C1_CR2 |= (1<<14);
//}
//
//void oled_set_pos(uint8_t page,uint8_t col)
//{
//    oled_cmd(0xB0+page);
//    oled_cmd(0x00+(col&0x0F));
//    oled_cmd(0x10+(col>>4));
//}
//
//void oled_clear()
//{
//    for(int p=0;p<8;p++){
//        oled_set_pos(p,0);
//        for(int i=0;i<128;i++) oled_data(0);
//    }
//}
//
//void oled_char(uint8_t *ch)
//{
//    for(int i=0;i<5;i++) oled_data(ch[i]);
//    oled_data(0);
//}
//
//void oled_print_num(uint8_t num)
//{
//    oled_char(font[num/10]);
//    oled_char(font[num%10]);
//}
//
///* ================= RTC ================= */
//void rtc_init()
//{
//    RCC_APB1ENR1 |= (1<<28);
//    PWR_CR1 |= (1<<8);
//
//    RCC_BDCR |= (1<<16);
//    RCC_BDCR &= ~(1<<16);
//
//    RCC_BDCR |= (1<<0);
//    while(!(RCC_BDCR&(1<<1)));
//
//    RCC_BDCR |= (1<<8);
//    RCC_BDCR |= (1<<15);
//
//    RTC_WPR=0xCA; RTC_WPR=0x53;
//    RTC_ISR|=(1<<7);
//    while(!(RTC_ISR&(1<<6)));
//
//    RTC_PRER=(127<<16)|255;
//
//    RTC_ISR&=~(1<<7);
//    RTC_WPR=0xFF;
//}
//
//void rtc_set_from_uart(char *buf)
//{
//    uint8_t h=(buf[0]-'0')*10+(buf[1]-'0');
//    uint8_t m=(buf[3]-'0')*10+(buf[4]-'0');
//    uint8_t s=(buf[6]-'0')*10+(buf[7]-'0');
//
//    uint32_t tr=((h/10)<<20)|((h%10)<<16)|((m/10)<<12)|((m%10)<<8)|((s/10)<<4)|(s%10);
//
//    RTC_WPR=0xCA; RTC_WPR=0x53;
//    RTC_ISR|=(1<<7);
//    while(!(RTC_ISR&(1<<6)));
//
//    RTC_TR=tr;
//
//    RTC_ISR&=~(1<<7);
//    RTC_WPR=0xFF;
//}
//
//void rtc_read(uint8_t *h,uint8_t *m,uint8_t *s)
//{
//    uint32_t t=RTC_TR;
//    *h=((t>>20)&0xF)*10+((t>>16)&0xF);
//    *m=((t>>12)&0xF)*10+((t>>8)&0xF);
//    *s=((t>>4)&0xF)*10+(t&0xF);
//}
//
///* ================= MAIN ================= */
//int main()
//{
//    uint8_t h,m,s;
//    char buf[10];
//
//    RCC_AHB2ENR |= (1<<0)|(1<<1);
//    RCC_APB1ENR1 |= (1<<21);
//
//    /* I2C pins */
//    GPIOB_MODER &= ~(3<<(16)) & ~(3<<(18));
//    GPIOB_MODER |= (2<<(16)) | (2<<(18));
//    GPIOB_AFRH |= (4<<0)|(4<<4);
//    GPIOB_OTYPER |= (1<<8)|(1<<9);
//    GPIOB_PUPDR |= (1<<(16))|(1<<(18));
//
//    I2C1_TIMINGR=0x00707CBB;
//    I2C1_CR1|=(1<<0);
//
//    oled_cmd(0xAE);
//    oled_cmd(0xAF);
//    oled_clear();
//
//    rtc_init();
//    uart_init();
//
//    uart_receive(buf);
//    rtc_set_from_uart(buf);
//
//    while(1)
//    {
//        static uint8_t ps=255;
//        rtc_read(&h,&m,&s);
//
//
//        if(ps!=s){
//            ps=s;
//            oled_set_pos(0,0);
//            oled_print_num(h); oled_char(font_colon);
//            oled_print_num(m); oled_char(font_colon);
//            oled_print_num(s);
//        }
//    }
//}
//


#include <stdint.h>

/* ================= RCC ================= */
#define RCC_BASE        0x40021000
#define RCC_APB1ENR1    (*(volatile uint32_t*)(RCC_BASE + 0x58))
#define RCC_BDCR        (*(volatile uint32_t*)(RCC_BASE + 0x90))
#define RCC_AHB2ENR     (*(volatile uint32_t*)(RCC_BASE + 0x4C))

/* ================= GPIO ================= */
#define GPIOA_BASE      0x48000000
#define GPIOB_BASE      0x48000400

#define GPIOA_MODER     (*(volatile uint32_t*)(GPIOA_BASE + 0x00))
#define GPIOA_AFRL      (*(volatile uint32_t*)(GPIOA_BASE + 0x20))

#define GPIOB_MODER     (*(volatile uint32_t*)(GPIOB_BASE + 0x00))
#define GPIOB_OTYPER    (*(volatile uint32_t*)(GPIOB_BASE + 0x04))
#define GPIOB_PUPDR     (*(volatile uint32_t*)(GPIOB_BASE + 0x0C))
#define GPIOB_AFRH      (*(volatile uint32_t*)(GPIOB_BASE + 0x24))

/* ================= USART2 ================= */
#define USART2_BASE 0x40004400
#define USART2_CR1  (*(volatile uint32_t*)(USART2_BASE + 0x00))
#define USART2_BRR  (*(volatile uint32_t*)(USART2_BASE + 0x0C))
#define USART2_ISR  (*(volatile uint32_t*)(USART2_BASE + 0x1C))
#define USART2_RDR  (*(volatile uint32_t*)(USART2_BASE + 0x24))

/* ================= PWR ================= */
#define PWR_BASE        0x40007000
#define PWR_CR1         (*(volatile uint32_t*)(PWR_BASE + 0x00))

/* ================= RTC ================= */
#define RTC_BASE        0x40002800
#define RTC_TR          (*(volatile uint32_t*)(RTC_BASE + 0x00))
#define RTC_DR          (*(volatile uint32_t*)(RTC_BASE + 0x04))
#define RTC_ISR         (*(volatile uint32_t*)(RTC_BASE + 0x0C))
#define RTC_PRER        (*(volatile uint32_t*)(RTC_BASE + 0x10))
#define RTC_WPR         (*(volatile uint32_t*)(RTC_BASE + 0x24))

/* ================= I2C ================= */
#define I2C1_BASE       0x40005400
#define I2C1_CR1        (*(volatile uint32_t*)(I2C1_BASE + 0x00))
#define I2C1_CR2        (*(volatile uint32_t*)(I2C1_BASE + 0x04))
#define I2C1_TIMINGR    (*(volatile uint32_t*)(I2C1_BASE + 0x10))
#define I2C1_ISR        (*(volatile uint32_t*)(I2C1_BASE + 0x18))
#define I2C1_TXDR       (*(volatile uint32_t*)(I2C1_BASE + 0x28))

#define OLED_ADDR 0x3C

/* ================= FONT ================= */
uint8_t font[10][5] = {
{0x3E,0x51,0x49,0x45,0x3E},{0x00,0x42,0x7F,0x40,0x00},
{0x42,0x61,0x51,0x49,0x46},{0x21,0x41,0x45,0x4B,0x31},
{0x18,0x14,0x12,0x7F,0x10},{0x27,0x45,0x45,0x45,0x39},
{0x3C,0x4A,0x49,0x49,0x30},{0x01,0x71,0x09,0x05,0x03},
{0x36,0x49,0x49,0x49,0x36},{0x06,0x49,0x49,0x29,0x1E}
};

uint8_t font_colon[5]={0x00,0x36,0x36,0x00,0x00};

/* ================= UART ================= */
void uart_init()
{
    RCC_AHB2ENR |= (1<<0);
    RCC_APB1ENR1 |= (1<<17);

    GPIOA_MODER &= ~(3<<(2*2)) & ~(3<<(3*2));
    GPIOA_MODER |=  (2<<(2*2)) | (2<<(3*2));

    GPIOA_AFRL |= (7<<(2*4)) | (7<<(3*4));

    USART2_BRR = 0x1A1;
    USART2_CR1 |= (1<<2);
    USART2_CR1 |= (1<<0);
}

/* receive ONLY time: "HH:MM:SS" */
void uart_receive(char *buf)
{
    int i = 0;
    while(1)
    {
        while(!(USART2_ISR & (1<<5)));
        char c = USART2_RDR;
        if(c == '\n') break;
        buf[i++] = c;
    }
}

/* ================= OLED ================= */
// (same as your code, unchanged)
void oled_cmd(uint8_t cmd){ I2C1_CR2=(OLED_ADDR<<1)|(2<<16); I2C1_CR2|=(1<<13);
while(!(I2C1_ISR&(1<<1))); I2C1_TXDR=0x00;
while(!(I2C1_ISR&(1<<1))); I2C1_TXDR=cmd;
while(!(I2C1_ISR&(1<<6))); I2C1_CR2|=(1<<14); }

void oled_data(uint8_t data){ I2C1_CR2=(OLED_ADDR<<1)|(2<<16); I2C1_CR2|=(1<<13);
while(!(I2C1_ISR&(1<<1))); I2C1_TXDR=0x40;
while(!(I2C1_ISR&(1<<1))); I2C1_TXDR=data;
while(!(I2C1_ISR&(1<<6))); I2C1_CR2|=(1<<14); }

void oled_set_pos(uint8_t p,uint8_t c){ oled_cmd(0xB0+p);
oled_cmd(0x00+(c&0x0F)); oled_cmd(0x10+(c>>4)); }

void oled_clear(){ for(int p=0;p<8;p++){ oled_set_pos(p,0);
for(int i=0;i<128;i++) oled_data(0);} }

void oled_char(uint8_t *ch){ for(int i=0;i<5;i++) oled_data(ch[i]); oled_data(0); }

void oled_print_num(uint8_t n){ oled_char(font[n/10]); oled_char(font[n%10]); }

/* ================= RTC ================= */
void rtc_init()
{
    RCC_APB1ENR1 |= (1<<28);
    PWR_CR1 |= (1<<8);

    RCC_BDCR |= (1<<16);
    RCC_BDCR &= ~(1<<16);

    RCC_BDCR |= (1<<0);
    while(!(RCC_BDCR&(1<<1)));

    RCC_BDCR |= (1<<8);
    RCC_BDCR |= (1<<15);

    RTC_WPR=0xCA; RTC_WPR=0x53;
    RTC_ISR|=(1<<7);
    while(!(RTC_ISR&(1<<6)));

    RTC_PRER=(127<<16)|255;

    RTC_ISR&=~(1<<7);
    RTC_WPR=0xFF;
}

/* set ONLY TIME from UART */
void rtc_set_time(char *buf)
{
    uint8_t h=(buf[0]-'0')*10+(buf[1]-'0');
    uint8_t m=(buf[3]-'0')*10+(buf[4]-'0');
    uint8_t s=(buf[6]-'0')*10+(buf[7]-'0');

    uint32_t tr=((h/10)<<20)|((h%10)<<16)|((m/10)<<12)|((m%10)<<8)|((s/10)<<4)|(s%10);

    RTC_WPR=0xCA; RTC_WPR=0x53;
    RTC_ISR|=(1<<7);
    while(!(RTC_ISR&(1<<6)));

    RTC_TR=tr;

    RTC_ISR&=~(1<<7);
    RTC_WPR=0xFF;
}

/* set FIXED DATE */
void rtc_set_date_fixed()
{
    uint8_t d=31, mo=3, y=26;

    uint32_t dr=((y/10)<<20)|((y%10)<<16)|((mo/10)<<12)|((mo%10)<<8)|((d/10)<<4)|(d%10);

    RTC_WPR=0xCA; RTC_WPR=0x53;
    RTC_ISR|=(1<<7);
    while(!(RTC_ISR&(1<<6)));

    RTC_DR=dr;

    RTC_ISR&=~(1<<7);
    RTC_WPR=0xFF;
}

/* READ TOGETHER */
void rtc_read_all(uint8_t *h,uint8_t *m,uint8_t *s,
                  uint8_t *d,uint8_t *mo,uint8_t *y)
{
    uint32_t t = RTC_TR;
    uint32_t dt = RTC_DR;

    *h=((t>>20)&0xF)*10+((t>>16)&0xF);
    *m=((t>>12)&0xF)*10+((t>>8)&0xF);
    *s=((t>>4)&0xF)*10+(t&0xF);

    *y=((dt>>20)&0xF)*10+((dt>>16)&0xF);
    *mo=((dt>>12)&0xF)*10+((dt>>8)&0xF);
    *d=((dt>>4)&0xF)*10+(dt&0xF);
}

/* ================= MAIN ================= */
int main()
{
    uint8_t h,m,s,d,mo,y;
    char buf[10];

    RCC_AHB2ENR |= (1<<0)|(1<<1);
    RCC_APB1ENR1 |= (1<<21);

    /* I2C setup */
    GPIOB_MODER &= ~(3<<(16)) & ~(3<<(18));
    GPIOB_MODER |= (2<<(16)) | (2<<(18));
    GPIOB_AFRH |= (4<<0)|(4<<4);
    GPIOB_OTYPER |= (1<<8)|(1<<9);
    GPIOB_PUPDR |= (1<<(16))|(1<<(18));

    I2C1_TIMINGR=0x00707CBB;
    I2C1_CR1|=(1<<0);

    oled_cmd(0xAE);
    oled_cmd(0xAF);
    oled_clear();

    rtc_init();
    uart_init();

    uart_receive(buf);     // <-- send "HH:MM:SS"
    rtc_set_time(buf);     // set time
    rtc_set_date_fixed();  // set fixed date

    while(1)
    {
        static uint8_t ps=255;

        rtc_read_all(&h,&m,&s,&d,&mo,&y);

        if(ps!=s){
            ps=s;

            oled_set_pos(0,0);
            oled_print_num(h); oled_char(font_colon);
            oled_print_num(m); oled_char(font_colon);
            oled_print_num(s);

            oled_set_pos(2,0);
            oled_print_num(d); oled_char(font_colon);
            oled_print_num(mo); oled_char(font_colon);
            oled_print_num(y);
        }
    }
}
