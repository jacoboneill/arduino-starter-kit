#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SW_1 PD2
#define D1   PD5
#define D2   PD4
#define D3   PD3

#define FLASH 75 // ms

int main(void){
  // Set D1, D2, and D3 to OUTPUT
  DDRD |= (1 << D1) | (1 << D2) | (1 << D3);

  // Loop
  while(1){
    if(PIND & (1 << SW_1)){
      // Button Pressed
      // Set D3 LOW and alternate D1 and D2 between high and low out of phase
      PORTD &= ~((1 << D2) | (1 << D3));
      PORTD |= 1 << D1;
      _delay_ms(FLASH);
      // Toggle D1 and D2
      PORTD ^= (1 << D1) | (1 << D2);
      _delay_ms(FLASH);
    }else{
      // Button not pressed
      // Set D3 HIGH and PD1 and D2 LOW
      PORTD |= 1 << D3;
      PORTD &= ~((1 << D1) | (1 << D2));
    } 
  }
}
