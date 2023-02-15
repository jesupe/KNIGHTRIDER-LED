
int ledPins[8] = {4,5,6,7,8,9,10,11};
int countOFpin = 8; 
int LightType = 0;
const int buttonPin = 2;  
unsigned long button_time = 0;  
unsigned long last_button_time = 0;
void setup() 
            {
                attachInterrupt(digitalPinToInterrupt(buttonPin), BttPresd, RISING);

              pinMode(buttonPin, INPUT);   
              for (int PIN = 0; PIN < countOFpin; PIN = PIN + 1)   
                 {  
                    pinMode(ledPins[PIN], OUTPUT);  
                  }  
            }

void loop() {
  
  switch (LightType) {

      case 1:
           LFTtoRighON();
           LFTtoRighOFF();
           break;
    
      case 2:
           RGHtoLftON();
           RGHtoLftOFF();
           break;
      case 3:
           SplitSideTo_midle();
           break;

  }


}
void LFTtoRighON()    //Func RUNNING  TURN ON FROM LEFT TO RIGHT 
{

    for ( int PIN =0; PIN <= countOFpin; PIN = PIN + 1)   {  
  digitalWrite(ledPins[PIN], HIGH); 
  delay ( 100);
    }
}
void LFTtoRighOFF()   //Func RUNNING  TURN OFF FROM LEFT TO RIGHT
{
    for ( int PIN =0; PIN <= countOFpin; PIN = PIN + 1)   {  
  digitalWrite(ledPins[PIN], LOW); 
  delay ( 100);
  }
}
void RGHtoLftON()     //Func RUNNING  TURN ON FROM RIGHT TO LEFT
 {

       for (int PIN = countOFpin-1; PIN >=0 ; PIN  --)   {  
    digitalWrite(ledPins[PIN], HIGH);  
   
    delay(100);}
}
void RGHtoLftOFF()   //Func RUNNING  TURN OFF FROM RIGHT TO LEFT 
 {

    for (int PIN = countOFpin-1; PIN >=0 ; PIN  --)   {  
    digitalWrite(ledPins[PIN], LOW);  
    
    delay(100);}
}

void SplitSideTo_midle()
{
    int PinMidle_Left=3;  
    int PinMidle_Right =8;

     
     for (int PIN =0; PIN <= PinMidle_Left; PIN = PIN +1)   {    
          digitalWrite(ledPins[PIN], HIGH);
          PinMidle_Right --;
          digitalWrite(ledPins[ PinMidle_Right], HIGH);
          delay(100);
     }
      for (int PIN = PinMidle_Left; PIN >=0;PIN=PIN-1){
        digitalWrite(ledPins[PIN], LOW);
        digitalWrite(ledPins[PinMidle_Right], LOW);
        PinMidle_Right ++;
        delay(100);      
       
         }
         
         

      }
           // Interrupt service for Button pin2
    void BttPresd() {
      
      button_time = millis();
      //check to see if increment() was called in the last 250 milliseconds
      if (button_time - last_button_time > 250)
         {
           last_button_time = button_time;
           if (LightType >= 3 ) 
           {
               LightType = 0 ; 
               }
          LightType = LightType +1;
         }
         
          

    }
    
      

 

  
