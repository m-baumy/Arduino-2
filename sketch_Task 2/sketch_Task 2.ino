int Buzzer_Pin = 9;
int LDC1_Pin = A0;
int LDC2_Pin = A1;
int Insider = 0;
int inroom = 0;
int enter = 0;
int out = 0;


void setup() {
  
pinMode(Buzzer_Pin,OUTPUT);
pinMode(LDC1_Pin,INPUT);
pinMode(LDC2_Pin,INPUT);
Serial.begin(9600);
}


void loop() {
  
  
 int LDC1_sensor = analogRead(LDC1_Pin);
 int LDC2_sensor = analogRead(LDC2_Pin);


Serial.println( Insider);


  
if (inroom > 0) {
    if ( LDC1_sensor <= 300 && LDC2_sensor > 300 && enter == 0) {
     enter++;
    }
}

if ( LDC1_sensor > 300 && enter > 0) { 
     Insider++;
    out = 0;
    enter = 0;
    inroom=0;
  }
  
 
if (LDC2_sensor > 300 && LDC1_sensor > 300) {
  inroom++;
}

  
if (inroom > 0) {
    if ( LDC2_sensor <= 300 && LDC1_sensor > 300  && enter == 0) {
      out++; 
      }
}
if ( LDC2_sensor > 300 && out > 0) { 
     Insider--;
    enter =0;
    out = 0;
    inroom =0;
  }


  
if ( Insider < 0) {
   Insider = 0;
}

if ( Insider > 5) {
   Insider = 5;
}



if ( Insider == 5 ||  Insider > 5) {
analogWrite(Buzzer_Pin,HIGH);
} else {
 analogWrite(Buzzer_Pin,LOW);

}


}
