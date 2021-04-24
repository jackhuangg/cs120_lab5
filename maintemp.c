/*	Author: jhuan314
 *  Partner(s) Name:Jack Huang 
 *	Lab Section:23
 *	Assignment: Lab #4  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum SM1_STATES { SM1_SMStart,wait, current_state1, current_state2, current_state3, current_state4, current_state5, current_state6} SM1_STATE;

void Tick_StateMachine1() {
       unsigned char PINAi = ~PINA;	
   switch(SM1_STATE) { 
      case SM1_SMStart:
         SM1_STATE = wait;
         break;

      case wait:
	 if((PINAi) == 0x01){
	 SM1_STATE = current_state1;
	 }
	 else{
	 SM1_STATE = wait;
	 }
	 break;

      case current_state1:
	 if((PINAi) == 0x01){
	 SM1_STATE = current_state2;
	 }
         else{
         SM1_STATE = current_state1;
         }
         break;

      case current_state2:
         if((PINAi) == 0x01){
	 SM1_STATE = current_state3;
	 }
         else{
         SM1_STATE = current_state2;
         }
         break;

      case current_state3:
         if((PINAi) == 0x01){
	 SM1_STATE = current_state4;
	 }
         else{
         SM1_STATE = current_state3;
         }
         break;

      case current_state4:
         if((PINAi) == 0x01){
	 SM1_STATE = current_state5;
	 }
         else{
         SM1_STATE = current_state4;
         }
         break;

      case current_state5:
         if((PINAi) == 0x01){
	 SM1_STATE = current_state6;
	 }
         else{
         SM1_STATE = current_state5;
         }
         break;

      case current_state6:
         if((PINAi) == 0x01){
	 SM1_STATE = wait;
	 }
         else{
         SM1_STATE = current_state6;
         }
         break;
   }
   switch(SM1_STATE) {
      case SM1_SMStart:
	 PORTB = 0;
	 break;
      case wait:
	 PORTB = 0;
	 break;
      case current_state1:
	 PORTB = 0x20;
	 break;
      case current_state2:
	 PORTB = 0x10;
	 break;
      case current_state3:
	 PORTB = 0x08;
	 break;
      case current_state4:
	 PORTB = 0x04;
	 break;
      case current_state5:
	 PORTB = 0x02;
	 break;
      case current_state6:
	 PORTB = 0x01;
	 break;
   }
}
   int main(void) {
   DDRA = 0x00; PORTA = 0xFF; //Init outputs
   DDRB = 0xFF; PORTB = 0x00;
      while (1) {
         Tick_StateMachine1();       // Execute one tick of the BL synchSM
      }
   return 1;
   }
