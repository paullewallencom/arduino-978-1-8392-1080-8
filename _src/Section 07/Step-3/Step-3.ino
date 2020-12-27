/* 
   Udemy Course - Crazy about Arduino - Level 1 - Your Starting Point
   Step-3 - Motion Detection using PIR Sensor 
   
   Created by Idan Gabrieli 
*/
// ******************************************
// Global variables Declaration - Mapping physical sensors connections to Arduino PINs
const int testButton=2;      
const int waveButton=4;      
const int speedControlPin = A0; 
const int brightnessControlPin = A1;
const int pirSensor=12;

// Mapping all LEDs physical connections to Arduino PINs
const int ledsPin[]={3,5,6,9,10,11};
boolean ledsOn=false;         // the present state of the LEDs (ON/OFF)  
boolean lastButton=LOW;       // the last button state
boolean currentButton=LOW;    // the current button state 
int pirState = LOW;           // used for the PIR sensor, assuming no motion detected
// ******************************************
void setup()
{
    pinMode (testButton, INPUT); // set test button as input 
    pinMode (waveButton, INPUT); // set wave animation button as input 
    for (int i=0; i<6; i++)        // set all LEDs to output 
      pinMode(ledsPin[i], OUTPUT);  
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
    // letting the PIR sensor to learn the environment 
    Serial.println("Initialization:"); 
    for(int i=0; i<10; i++){
      Serial.print("."); 
      delay(1000);
    } 
    Serial.println(""); 
    Serial.println("System is Ready"); 
}
// ******************************************
void loop()
{
  checkTestButton();
  checWaveButton();
  checkPIR();
}
// ******************************************
// if the button was pressed than wait for the button state to stablize and 
boolean debounce(int buttonPIN,boolean last)
{
  boolean current= digitalRead(buttonPIN);
  if (current != last) {
    delay(5); // wait 5ms for button state stablizing 
    current = digitalRead(buttonPIN); // read it again
  }
  return current; 
}
// ******************************************
// checking if the test button was pressed and turn ON or OFF all LEDs
void checkTestButton()
{
  currentButton = debounce(testButton,lastButton);  
  if (currentButton == HIGH && lastButton == LOW) // button was pressed 
     ledsOn =!ledsOn; //toggle the LEDs state
   lastButton = currentButton;
   for (int i=0; i<6; i++)
       digitalWrite(ledsPin[i], ledsOn);
}
// ******************************************
// checking if the wave button was pressed and run animation wave on LEDs 
void checWaveButton()
{
  int brightnessLevel=analogRead(brightnessControlPin); 
  int speedLevel=analogRead(speedControlPin);
// mapping the relevant ranges from the sensors reading 
  speedLevel=map(speedLevel, 0, 1023, 700, 100);
  brightnessLevel=map(brightnessLevel, 0, 1023, 0, 255);

  if(digitalRead(waveButton) == HIGH)// button is pressed 
  {
    Serial.println("Running Animation Wave with the following Parameters:"); 
    Serial.print("Speed:");
    Serial.println(speedLevel);
    Serial.print("Brightness:");
    Serial.println(brightnessLevel);
    for(int i=0; i<6; i++)
    {
//     digitalWrite(ledsPin[i], HIGH);
     analogWrite(ledsPin[i],brightnessLevel);
     delay(speedLevel);
     digitalWrite(ledsPin[i], LOW);
    }
    for(int i=5; i>=0; i--)
    {
//     digitalWrite(ledsPin[i], HIGH);
     analogWrite(ledsPin[i],brightnessLevel);
     delay(speedLevel);
     digitalWrite(ledsPin[i], LOW);
    }
  }
}
// ******************************************
void checkPIR() 
{
  if (digitalRead(pirSensor) == HIGH) {            // check if the input is HIGH
    for (int i=0; i<6; i++)                        // turn ON all LEDs
       digitalWrite(ledsPin[i], HIGH);
    if (pirState == LOW) {                         // we have just turned ON 
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } 
  else {
    for (int i=0; i<6; i++)
       digitalWrite(ledsPin[i], LOW);
    if (pirState == HIGH){     // Going down from HIGH to LOW
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}
// ******************************************
// END OF PROGRAM

