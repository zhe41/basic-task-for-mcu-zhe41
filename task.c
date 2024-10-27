

void delay_ms(unsigned int x)  // 延时函数
{
    unsigned int i,j;
    if(x==1000)
    {
        for(i=0;i<19601;i++)//延时1s
        {
            for(j=5;j>0;j--);
        }
    }
    else while(x--)for(j=115;j>0;j--);
}

// tips: 原理图当中led为低电平点亮，比如点亮LED2,代码为： P0 = 0xFE (1111 1110)


void main()
{
    unsigned char led = 0x01;  // 初始点亮最左边的灯

    while (1)
    {
        P0 = led;  // 输出当前点亮的灯
        delay_ms(500);  // 延时 500ms

        led <<= 1;  // 左移一位，准备点亮下一个灯
        if (led == 0)  // 如果已经移到最右边，重新从最左边开始
            led = 0x01;
    }
}
