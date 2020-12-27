 /* 
   Udemy Course - Crazy about Arduino - Level 1 - Your Starting Point
   Step-1A - LEDs Test and Animation Wave    
   
   Created by Idan Gabrieli 
*/
// ******************************************
// Global variables Declaration - Mapping physical sensors connections to Arduino digital PINs
const int testButton=2;      
const int waveButton=4;      

// Mapping all LEDs physical connections to Arduino digital PINs
const int ledsPin[]={3,5,6,9,10,11}; 
// ******************************************
void setup()
{
    pinMode (testButton, INPUT); // set test button as input 
    pinMode (waveButton, INPUT); // set wave animation button as input 
    for (int i=0; i<6; i++)        // set all LEDs to output 
      pinMode(ledsPin[i], OUTPUT);  
}
// ******************************************
void loop()
{
  checkTestButton();
  checkWaveButton();
}
// ******************************************
// checking if the test button was pressed and turn ON all LEDs for 1 sec
void checkTestButton()
{
  if (digitalRead(testButton) == HIGH) // button is pressed 
    {
      for (int i=0; i<6; i++)
          digitalWrite(ledsPin[i], HIGH);   // turn ON
      delay(1000); 
    }
  for (int i=0; i<6; i++)                 
      digitalWrite(ledsPin[i], LOW);        // turn OFF
}
// ******************************************
// checking if the wave button was pressed and run animation wave on LEDs 
void checkWaveButton()
{
  if(digitalRead(waveButton) == HIGH)// button is pressed 
  {
    for(int i=0; i<6; i++)
    {
     digitalWrite(ledsPin[i], HIGH);
     delay(400);
     digitalWrite(ledsPin[i], LOW);
    }
    for(int i=5; i>=0; i--)
    {
     digitalWrite(ledsPin[i], HIGH);
     delay(400);
     digitalWrite(ledsPin[i], LOW);
    }
  }
}
// ******************************************
// END OF PROGRAM

