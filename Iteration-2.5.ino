

int bstate1 = 0;
int bstate2 = 0;
int bstate3 = 0;
int bstate4 = 0;
int bstate5 = 0;
int bstate6 = 0;
int negitive_dc = 6;
int positive_dc = 5;
int negitive_dc2 = 11;
int positive_dc2 = 10;
int button1 = 7;
int button2 = 4;
int button3 = 8;
int button4 = 12;
int button5 = 13;//set button
int button6 = A0;//clear button

long duration; 

int distance;


void setup ()
{
  pinMode(2, INPUT); //echo
  pinMode(3, OUTPUT); //trigger

  Serial.begin(9600);
  pinMode (negitive_dc,OUTPUT);
  pinMode (positive_dc,OUTPUT);
  pinMode (negitive_dc2,OUTPUT);
  pinMode (positive_dc2,OUTPUT);
  pinMode (button1,INPUT);
  pinMode (button2,INPUT);
  pinMode (button3,INPUT);
  pinMode (button4,INPUT);
  pinMode (button5,INPUT);
  pinMode (button6,INPUT);
  pinMode (9,OUTPUT);
}

void loop ()
{
  
  
  bstate1 = digitalRead (button1);
  bstate2 = digitalRead (button2);
  bstate3 = digitalRead (button3);
  bstate4 = digitalRead (button4);
  bstate5 = digitalRead (button5);
  bstate6 = digitalRead (button6);
  
  
  //trigger code
  digitalWrite(3, LOW); 
  delay(0.2); 
 
  digitalWrite(3, HIGH); 
  delay(0.10); 
 
  digitalWrite(3, LOW); 
  
  //echo code
  duration = pulseIn(2, HIGH); 
  
  distance = (duration*0.034)/2;
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
      digitalWrite (positive_dc,HIGH);
      digitalWrite (negitive_dc,LOW);
      digitalWrite (positive_dc2,HIGH);
      digitalWrite (negitive_dc2,LOW);
      delay(3000);
      digitalWrite (positive_dc,LOW);
      digitalWrite (negitive_dc,LOW);
      digitalWrite (positive_dc2,LOW);
      digitalWrite (negitive_dc2,LOW);
    }
      else
    {
      digitalWrite (positive_dc,LOW);
      digitalWrite (negitive_dc,LOW);
      digitalWrite (positive_dc2,LOW);
      digitalWrite (negitive_dc2,LOW);
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
      digitalWrite (positive_dc,LOW);
      digitalWrite (negitive_dc,HIGH);
      digitalWrite (positive_dc2,LOW);
      digitalWrite (negitive_dc2,HIGH);
     delay(3000);
      digitalWrite (positive_dc,LOW);
      digitalWrite (negitive_dc,LOW);
      digitalWrite (positive_dc2,LOW);
      digitalWrite (negitive_dc2,LOW);
    }
    else
    {
      digitalWrite (positive_dc,LOW);
      digitalWrite (negitive_dc,LOW);
      digitalWrite (positive_dc2,LOW);
      digitalWrite (negitive_dc2,LOW);
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
      digitalWrite (positive_dc,HIGH);
      digitalWrite (negitive_dc,LOW);
      digitalWrite (positive_dc2,LOW);
      digitalWrite (negitive_dc2,LOW);//change to high if you want to on the spot turn
      delay(3000);
      digitalWrite (positive_dc,LOW);
      digitalWrite (negitive_dc,LOW);
      digitalWrite (positive_dc2,LOW);
      digitalWrite (negitive_dc2,LOW);
    }
    else
    {
      digitalWrite (positive_dc,LOW);
      digitalWrite (negitive_dc,LOW);
      digitalWrite (positive_dc2,LOW);
      digitalWrite (negitive_dc2,LOW);
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
      digitalWrite (positive_dc,LOW);
      digitalWrite (negitive_dc,LOW);//change to high if you want to on the spot turn
      digitalWrite (positive_dc2,HIGH);
      digitalWrite (negitive_dc2,LOW);
      delay(3000);
      digitalWrite (positive_dc,LOW);
      digitalWrite (negitive_dc,LOW);
      digitalWrite (positive_dc2,LOW);
      digitalWrite (negitive_dc2,LOW);
    }
    else
    {
      digitalWrite (positive_dc,LOW);
      digitalWrite (negitive_dc,LOW);
      digitalWrite (positive_dc2,LOW);
      digitalWrite (negitive_dc2,LOW);
    }
  }
  else
    {
      digitalWrite (positive_dc,LOW);
      digitalWrite (negitive_dc,LOW);
      digitalWrite (positive_dc2,LOW);
      digitalWrite (negitive_dc2,LOW);
    }
  

  
}
