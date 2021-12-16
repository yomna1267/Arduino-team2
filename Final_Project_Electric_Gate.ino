// Switch
const int button_bazzer_Pin = 2; 
int button_bazzer_State = 0;         // variable for reading the pushbutton status
const int button_gate_Pin = 3; 
int button_gate_State = 0;         // variable for reading the pushbutton status
// DC Motor
#define EN 10
#define IN1 9
#define IN2 8
int motor_speed = 0;
int Buzzer_Pin = 5;
int pedal = A0;



void setup() {
   Serial.begin (9600);
  // put your setup code here, to run once:
 pinMode(button_bazzer_Pin, INPUT);
 pinMode(button_gate_State, INPUT);
  pinMode(IN1, OUTPUT); // motor pin 1
  pinMode(IN2, OUTPUT); // motor pin 2
  pinMode(EN, OUTPUT); // motor PWM pin
pinMode(Buzzer_Pin,OUTPUT);
  pinMode(pedal,INPUT); // potentiometer pin



}

void loop() {
  
  // put your main code here, to run repeatedly:
 button_bazzer_State = digitalRead(button_bazzer_Pin);
 button_gate_State = digitalRead(button_gate_Pin);
  int pedalValue = analogRead(pedal);
  delay(500);
  motor_speed = map(pedalValue, 0, 1024, 0, 255);


if (button_bazzer_State == 1) {
  
   analogWrite(Buzzer_Pin,HIGH);
} else {
   analogWrite(Buzzer_Pin,LOW);
}




if (!((motor_speed < 10) || (motor_speed > 250))) {

if (button_gate_State == 1) {

 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 analogWrite(EN,200);

} else {
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 analogWrite(EN,200);

}

  
} else {

 digitalWrite(IN1, LOW);

  
}



Serial.println(motor_speed);


}
