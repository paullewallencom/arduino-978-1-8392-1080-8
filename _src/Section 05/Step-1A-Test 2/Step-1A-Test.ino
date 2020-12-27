 /* 
   Udemy Course - Crazy about Arduino - Level 1 - Your Starting Point
   Step-1A - LEDs Test and Animation Wave    
   
   Created by Idan Gabrieli 
*/
// ******************************************
// Mapping all LEDs physical connections to Arduino digital PINs
const int ledsPin[]={3,5,6,9,10,11}; 
// ******************************************
void setup()
{
    for (int i=0; i<6; i++)        // set all LEDs to output 
      pinMode(ledsPin[i], OUTPUT);        
}
// ******************************************
void loop()
{
  for (int i=0; i<6; i++)
          digitalWrite(ledsPin[i], HIGH);   // turn ON
  delay(5000);   
  for (int i=0; i<6; i++)                 
      digitalWrite(ledsPin[i], LOW);        // turn OFF
  delay(5000);     
}
// ******************************************
// END OF PROGRAM

