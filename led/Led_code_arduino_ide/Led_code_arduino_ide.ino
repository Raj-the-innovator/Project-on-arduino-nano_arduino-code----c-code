//Led code to blink on 13 pin in arduino nano

void setup() {
pinMode(13,OUTPUT);  //set output 13 pin for arduino
}

void loop() {
digitalWrite(13,HIGH);  // write 1 on pin 13
delay(1000);             // delay for blink
digitalWrite(13,LOW);   // write 0 on pin 13
delay(1000);  
}
