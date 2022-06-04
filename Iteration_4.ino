#include <IRremote.hpp> //IR Library

//motor pins
#define forward 10
#define backward 11
#define forward2 5
#define backward2 6

//button states
int bstate1 = 0;
int bstate2 = 0;
int bstate3 = 0;
int bstate4 = 0;

//button pins
int button1 = 7;
int button2 = 4;
int button3 = 8;
int button4 = 12;

//ultrasonic setup
long duration; 
int distance;

//these codes are specific to my remote that I associated with my reciever 
//if using a different remote, find new codes via the code finder code

#define Next_button 25245  // code received from vol+
#define Prev_button 43095  // code received from vol-
#define left_button 8925  // code received from previous
#define right_button 49725 // code received from skip
#define Stop_button 41565   // code received from Power button

//IR setup
int receiver_pin = A1;      //output pin of IR receiver to pin A1 of arduino
IRrecv receiver(receiver_pin); //Arduino will take output of IR receiver from pin 2
decode_results output;

//**************************************

void setup()
{
  //clasify IR and ultrasonic
  receiver.enableIRIn(); // Start to take the output from IR receiver, kind of like turning on serial monitor
  pinMode(2, INPUT); //echo
  pinMode(3, OUTPUT); //trigger
  Serial.begin(9600);
  //cllasify buttons
  pinMode (button1,INPUT);
  pinMode (button2,INPUT);
  pinMode (button3,INPUT);
  pinMode (button4,INPUT);
  //classify buzzer
  pinMode (9,OUTPUT);
  //clasify motor directions
  pinMode(forward,OUTPUT);
  pinMode(backward,OUTPUT);
  pinMode(forward2,OUTPUT);
  pinMode(backward2,OUTPUT);
}
//**************************************

void loop()
{
  //loop setup
  bstate1 = digitalRead (button1);
  bstate2 = digitalRead (button2);
  bstate3 = digitalRead (button3);
  bstate4 = digitalRead (button4);

  
  //trigger code
  digitalWrite(3, LOW); 
  delay(0.2); 
 
  digitalWrite(3, HIGH); 
  delay(0.10); 
 
  digitalWrite(3, LOW); 
  
  //echo code
  duration = pulseIn(2, HIGH); 
  
  distance = (duration*0.034)/2;
  

//**************************************

 //button control set
 if (distance >18) {
      Serial.println(distance);
  //forwards
      if (bstate1 == HIGH)
      {
        analogWrite(9,200);
        delay(300);
        analogWrite(9,225);
        delay(300);
        analogWrite(9,255);
        delay(300);
        digitalWrite(9,LOW);
        analogWrite(forward,255);
        analogWrite(forward2,255);
        analogWrite(backward,0);
        analogWrite(backward2,0);
        delay(3000);
        analogWrite(forward,0);
        analogWrite(forward2,0);
        analogWrite(backward,0);
        analogWrite(backward2,0);
      }
        else
      {
        analogWrite(forward,0);
        analogWrite(forward2,0);
        analogWrite(backward,0);
        analogWrite(backward2,0);
      }
        
        //reverse
      if (bstate2 == HIGH)
      {
        analogWrite(9,255);
        delay(300);
        analogWrite(9,225);
        delay(300);
        analogWrite(9,200);
        delay(300);
        digitalWrite(9,LOW);
        analogWrite(forward,0);
        analogWrite(forward2,0);
        analogWrite(backward,255);
        analogWrite(backward2,255);
        delay(3000);
        analogWrite(forward,0);
        analogWrite(forward2,0);
        analogWrite(backward,0);
        analogWrite(backward2,0);
      }
      else
      {
        analogWrite(forward,0);
        analogWrite(forward2,0);
        analogWrite(backward,0);
        analogWrite(backward2,0);
      }
      //left
      if (bstate4 == HIGH)
      {
         analogWrite(9,200);
        delay(300);
        digitalWrite(9,LOW);
        delay(300);
        analogWrite(9,200);
        delay(300);
        digitalWrite(9,LOW);
        analogWrite(forward,255);
        analogWrite(forward2,0);
        analogWrite(backward,0);
        analogWrite(backward2,0);
        delay(3000);
        analogWrite(forward,0);
        analogWrite(forward2,0);
        analogWrite(backward,0);
        analogWrite(backward2,0);
      }
      else
      {
        analogWrite(forward,0);
        analogWrite(forward2,0);
        analogWrite(backward,0);
        analogWrite(backward2,0);
      }
      //right
      if (bstate3 == HIGH)
      {
        analogWrite(9,200);
        delay(300);
        digitalWrite(9,LOW);
        delay(300);
        analogWrite(9,200);
        delay(300);
        digitalWrite(9,LOW);
        analogWrite(forward,0);
        analogWrite(forward2,255);
        analogWrite(backward,0);
        analogWrite(backward2,0);
        delay(3000);
        analogWrite(forward,0);
        analogWrite(forward2,0);
        analogWrite(backward,0);
        analogWrite(backward2,0);
      }
      else
      {
        analogWrite(forward,0);
        analogWrite(forward2,0);
        analogWrite(backward,0);
        analogWrite(backward2,0);
      }}
  else
    {
      analogWrite(forward,0);
      analogWrite(forward2,0);
      analogWrite(backward,0);
      analogWrite(backward2,0);
    }
//IR control set
   if (distance >18) {
    Serial.println(distance);
    if (receiver.decode(&output)) {
      unsigned int value = output.value;
      switch(value) {
        case Next_button:
          analogWrite(9,200);
          delay(300);
          analogWrite(9,225);
          delay(300);
          analogWrite(9,255);
          delay(300);
          digitalWrite(9,LOW);
          analogWrite(forward,255);
          analogWrite(forward2,255);
          analogWrite(backward,0);
          analogWrite(backward2,0);
          delay(3000);
          analogWrite(forward,0);
          analogWrite(forward2,0);
          analogWrite(backward,0);
          analogWrite(backward2,0);
          break;
          
        case Prev_button:
          analogWrite(9,255);
          delay(300);
          analogWrite(9,225);
          delay(300);
          analogWrite(9,200);
          delay(300);
          digitalWrite(9,LOW);
          analogWrite(forward,0);
          analogWrite(forward2,0);
          analogWrite(backward,255);
          analogWrite(backward2,255);
          delay(3000);
          analogWrite(forward,0);
          analogWrite(forward2,0);
          analogWrite(backward,0);
          analogWrite(backward2,0);
          break;
          
        case left_button: 
          analogWrite(9,200);
          delay(300);
          digitalWrite(9,LOW);
          delay(300);
          analogWrite(9,200);
          delay(300);
          digitalWrite(9,LOW);
          analogWrite(forward,255);
          analogWrite(forward2,0);
          analogWrite(backward,0);
          analogWrite(backward2,0);
          delay(3000);
          analogWrite(forward,0);
          analogWrite(forward2,0);
          analogWrite(backward,0);
          analogWrite(backward2,0);
          break;
          
        case right_button:
          analogWrite(9,200);
          delay(300);
          digitalWrite(9,LOW);
          delay(300);
          analogWrite(9,200);
          delay(300);
          digitalWrite(9,LOW);
          analogWrite(forward,0);
          analogWrite(forward2,255);
          analogWrite(backward,0);
          analogWrite(backward2,0);
          delay(3000);
          analogWrite(forward,0);
          analogWrite(forward2,0);
          analogWrite(backward,0);
          analogWrite(backward2,0);
          break;
          
        case Stop_button:
          analogWrite(forward,0);
          analogWrite(forward2,0);
          analogWrite(backward,0);
          analogWrite(backward2,0);
          break;
      }
      receiver.resume();
    }}}
