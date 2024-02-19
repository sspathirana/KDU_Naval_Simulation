#include <avr/io.h>
#include <avr/interrupt.h>

volatile char x;
volatile bool flag = false;
void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  //--configure UART1 of MEGA: Bd = 9600; RXRDY interrupt----
  UCSR1B = 0b10011000;  //
  UCSR1C = 0b00000110;  //
  //-Bd: 9600-------------
  UBRR1L = 0x67;
  UBRR1H = 0x00;
  //--global int enable--
  bitSet(SREG, 7);
}

void loop()
{
  if (flag == true)
  {
    Serial.print(x);
    flag = false;
  }
}

ISR(USART1_RX_vect)
{
  //digitalWrite(13, HIGH); //debugging code
  x = UDR1;    //recive from phone via BT
  UDR1 = x;    //sending to phone via BT
  flag = true;
}