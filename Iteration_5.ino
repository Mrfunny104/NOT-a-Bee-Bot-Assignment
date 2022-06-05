#include <IRremote.hpp> //IR Library

//NOTES:
//For accurate distances:
//Carpet:
//Forward&Back: 1400
//Left&Right: 1700
//
//Hard Floor:
//Forward&Back: 700
//Left&Right: 850


//control functions
#define back (  {\
        analogWrite(forward,255);\
        analogWrite(forward2,255);\
        analogWrite(backward,0);\
        analogWrite(backward2,0);\
        delay(700);\
        analogWrite(forward,0);\
        analogWrite(forward2,0);\
        analogWrite(backward,0);\
        analogWrite(backward2,0);\
    })


#define forwards ( {\
        analogWrite(forward,0);\
        analogWrite(forward2,0);\
        analogWrite(backward,255);\
        analogWrite(backward2,255);\
        delay(700);\
        analogWrite(forward,0);\
        analogWrite(forward2,0);\
        analogWrite(backward,0);\
        analogWrite(backward2,0);\
    })
  
  #define right ({\
        analogWrite(forward,0);\
        analogWrite(forward2,0);\
        analogWrite(backward,255);\
        analogWrite(backward2,0);\
        delay(850);\
        analogWrite(forward,0);\
        analogWrite(forward2,0);\
        analogWrite(backward,0);\
        analogWrite(backward2,0);\
    })
  
  #define left ({\ 
        analogWrite(forward,0);\
        analogWrite(forward2,0);\
        analogWrite(backward,0);\
        analogWrite(backward2,255);\
        delay(850);\
        analogWrite(forward,0);\
        analogWrite(forward2,0);\
        analogWrite(backward,0);\
        analogWrite(backward2,0);\
    })

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
int bstate5 = 0;

//button pins
int button1 = 7;
int button2 = 4;
int button3 = 8;
int button4 = 12;
int button5 = 13;

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
#define Func_button 57885  // code recieved from Func/Stop button

//IR setup
int receiver_pin = A1;      //output pin of IR receiver to pin A1 of arduino
IRrecv receiver(receiver_pin); //Arduino will take output of IR receiver from pin 2
decode_results output;


int list[6] = {};
int c = 0;
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
  pinMode (button5,INPUT);
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
  bstate5 = digitalRead (button5);
  
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
 if (distance >18) {
     //Serial.println(distance);
    if (bstate5 == true) {
        digitalWrite(9,HIGH);
        delay(500);
        digitalWrite(9,LOW);
        for(int x = 0; x<6; x){ 
        delay(300);
          bstate1 = digitalRead(button1);
          bstate2 = digitalRead(button2);
          bstate3 = digitalRead(button3);
          bstate4 = digitalRead(button4);
          bstate5 = digitalRead(button5);
          if (bstate1 == true) {list[x] = 1; x++;Serial.print("1");};
          if (bstate2 == true) {list[x] = 2; x++;Serial.print("2");};
          if (bstate3 == true) {list[x] = 3; x++;Serial.print("3");};
          if (bstate4 == true) {list[x] = 4; x++;Serial.print("4");};
          if (bstate5 == true) {c = x; break;};
        }
        for(int c = 0; c<6; c++) {
          if (list[c] == 1) {forwards;};
          if (list[c] == 2) {back;};
          if (list[c] == 3) {right;};
          if (list[c] == 4) {left;};
        }
      }}
  else
  {
    analogWrite(forward,0);
    analogWrite(forward2,0);
    analogWrite(backward,0);
    analogWrite(backward2,0);
  }
  
//**************************************

 //button control set
 if (distance >18) {
      //Serial.println(distance);
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
        analogWrite(forward,0);
        analogWrite(forward2,0);
        analogWrite(backward,255);
        analogWrite(backward2,255);
        delay(700);
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
        analogWrite(forward,255);
        analogWrite(forward2,255);
        analogWrite(backward,0);
        analogWrite(backward2,0);
        delay(700);
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
        analogWrite(forward,0);
        analogWrite(forward2,0);
        analogWrite(backward,255);
        analogWrite(backward2,0);
        delay(850);
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
        analogWrite(forward2,0);
        analogWrite(backward,0);
        analogWrite(backward2,255);
        delay(850);
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
    //Serial.println(distance);
    if (receiver.decode(&output)) {
      unsigned int value = output.value;
      switch(value) {
        case Next_button:
          forwards;
          break;
          
        case Prev_button:
          back;
          break;
          
        case left_button: 
          left;
          break;
          
        case right_button:
          right;
          break;
          
        case Stop_button:
          analogWrite(forward,0);
          analogWrite(forward2,0);
          analogWrite(backward,0);
          analogWrite(backward2,0);
          break;

        case Func_button:
        
          digitalWrite(9,1000);
          delay(500);
          digitalWrite(9,LOW);
          for(int x = 0; x<6; x){ 
            delay(300);
            bstate1 = digitalRead(button1);
            bstate2 = digitalRead(button2);
            bstate3 = digitalRead(button3);
            bstate4 = digitalRead(button4);
            bstate5 = digitalRead(button5);
            if (bstate1 == true) {list[x] = 1; x++;Serial.print("1");};
            if (bstate2 == true) {list[x] = 2; x++;Serial.print("2");};
            if (bstate3 == true) {list[x] = 3; x++;Serial.print("3");};
            if (bstate4 == true) {list[x] = 4; x++;Serial.print("4");};
            if (bstate5 == true) {c = x; break;};
          }
          for(int c = 0; c<6; c++) {
            if (list[c] == 1) {forwards;};
            if (list[c] == 2) {back;};
            if (list[c] == 3) {right;};
            if (list[c] == 4) {left;};
          }
          break;
        }
      }
      receiver.resume();
    }}
