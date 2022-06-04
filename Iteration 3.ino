#define forward 10
#define backward 11
#define forward2 5
#define backward2 6

int bstate1 = 0;
int bstate2 = 0;
int bstate3 = 0;
int bstate4 = 0;

int button1 = 7;
int button2 = 4;
int button3 = 8;
int button4 = 12;

long duration; 
int distance;

//**************************************

void setup()
{
  pinMode(2, INPUT); //echo
  pinMode(3, OUTPUT); //trigger
  Serial.begin(9600);

  pinMode (button1,INPUT);
  pinMode (button2,INPUT);
  pinMode (button3,INPUT);
  pinMode (button4,INPUT);

  pinMode (9,OUTPUT);
  
  pinMode(forward,OUTPUT);
  pinMode(backward,OUTPUT);
  pinMode(forward2,OUTPUT);
  pinMode(backward2,OUTPUT);
}
//**************************************

void loop()
{
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
    
  /*
  analogWrite(forward,255);
  analogWrite(forward2,255);
  delay(2000);
  analogWrite(forward,0);
  analogWrite(forward2,0);
  delay(2000);
  analogWrite(backward,255);
  analogWrite(backward2,255);
  delay(2000);
  analogWrite(backward,0);
  analogWrite(backward2,0);
  delay(2000);
  */
}
