#include <IRremote.h> //including the remote library
int receiver_pin = A1; //output pin of IR receiver to pin 2 of arduino
IRrecv receiver(receiver_pin); //Arduino will take output of IR receiver from pin 2
decode_results output;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  receiver.enableIRIn(); // Start to take the output from IR receiver
}

void loop() {
  if (receiver.decode(&output)) {
    unsigned int value = output.value;
    Serial.println(value);
    receiver.resume();
  }
}
