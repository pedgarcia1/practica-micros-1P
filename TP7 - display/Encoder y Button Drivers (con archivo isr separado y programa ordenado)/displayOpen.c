
#define DISPLAY_CYCLES 1000000
void displayOpen(void)
    {
      int i;
      int openArray[] = {0x3f,0x73,0x7b,0x37}; //O P E N para la pantalla
      while (1)
      {
        for (i = 0; i < 4*DISPLAY_CYCLES; i++)
        {
          printDigit(openArray[i%4],i%4);
        }
        __delay_cycles(1000000);
        
      }

    }