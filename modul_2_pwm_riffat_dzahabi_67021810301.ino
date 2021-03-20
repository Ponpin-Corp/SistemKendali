//pin buat sensor analog
int baca_sensor[6];
int sensor1 = A0;
int sensor2 = A1;
int sensor3 = A2;
int sensor4 = A3;
int sensor5 = A4;
int sensor6 = A5;

//pin buat enable
int pinEnable =4;
int pinEnable2 = 2;

//pin buat motor kiri
int motor_kiri1 = 5;
int motor_kiri2 = 6;

//pin buat motor kanan
int motor_kanan1 = 3;
int motor_kanan2 = 11;

int x;
int LastError = 0;

void setup(){
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);
  pinMode(sensor6, INPUT);
   
  pinMode(pinEnable, OUTPUT);
  pinMode(pinEnable2, OUTPUT);
  pinMode(motor_kiri1, OUTPUT);
  pinMode(motor_kiri2, OUTPUT);
  pinMode(motor_kanan1, OUTPUT);
  pinMode(motor_kanan2, OUTPUT);
  
  Serial.begin(9600);
}

void readsensor() { 
  baca_sensor[0] = analogRead(sensor1);
  baca_sensor[1] = analogRead(sensor2);
  baca_sensor[2] = analogRead(sensor3);
  baca_sensor[3] = analogRead(sensor4);
  baca_sensor[4] = analogRead(sensor5);
  baca_sensor[5] = analogRead(sensor6);
  
  
  delay(500);
  for(x=0;x<=5;x++){
  	Serial.print("Sensor ");
    Serial.print(x+1);
    Serial.print(": ");
    Serial.println(baca_sensor[x]);
  	Serial.print("\n");
  }
}

void loop(){
    
  readsensor();
  Serial.print("Nilai Last Error : ");
  Serial.println(LastError);
  
  if (baca_sensor[0] < 34 && baca_sensor[1] < 34 && 
      baca_sensor[2] > 34 && baca_sensor[3] > 34 && 
      baca_sensor[4] > 34 && baca_sensor[5] > 34){
 
    digitalWrite(pinEnable, HIGH);
    analogWrite(motor_kiri1, 0);
    analogWrite(motor_kiri2, 0);

    digitalWrite(pinEnable2, HIGH);
    analogWrite(motor_kanan1, 127);
    analogWrite(motor_kanan2, 0);
  }
	if (baca_sensor[0] > 34 && baca_sensor[1] < 34 && 
           baca_sensor[2] < 34 && baca_sensor[3] > 34 && 
           baca_sensor[4] > 34 && baca_sensor[5] > 34){
   
    digitalWrite(pinEnable, HIGH);
    analogWrite(motor_kiri1, 0.2*255);
    analogWrite(motor_kiri2, 0);

    digitalWrite(pinEnable2, HIGH);
    analogWrite(motor_kanan1, 0.5*255);
    analogWrite(motor_kanan2, 0);
  }
  if (baca_sensor[0] > 34 && baca_sensor[1] > 34 && 
           baca_sensor[2] < 34 && baca_sensor[3] < 34 && 
           baca_sensor[4] > 34 && baca_sensor[5] > 34){

    digitalWrite(pinEnable, HIGH);
    analogWrite(motor_kiri1, 0.6*255);
    analogWrite(motor_kiri2, 0);

    digitalWrite(pinEnable2, HIGH);
    analogWrite(motor_kanan1, 0.6*255);
    analogWrite(motor_kanan2, 0);
  }
  if (baca_sensor[0] > 34 && baca_sensor[1] > 34 && 
           baca_sensor[2] > 34 && baca_sensor[3] < 34 && 
           baca_sensor[4] < 34 && baca_sensor[5] > 34){
  
    digitalWrite(pinEnable, HIGH);
    analogWrite(motor_kiri1, 0.5*255);
    analogWrite(motor_kiri2, 0);

    digitalWrite(pinEnable2, HIGH);
    analogWrite(motor_kanan1, 0.2*255);
    analogWrite(motor_kanan2, 0);
  }
  if (baca_sensor[0] > 34 && baca_sensor[1] > 34 && 
      baca_sensor[2] > 34 && baca_sensor[3] > 34 && 
      baca_sensor[4] < 34 && baca_sensor[5] < 34){
 
    digitalWrite(pinEnable, HIGH);
    analogWrite(motor_kiri1, 127);
    analogWrite(motor_kiri2, 0);

    digitalWrite(pinEnable2, HIGH);
    analogWrite(motor_kanan1, 0);
    analogWrite(motor_kanan2, 0);
  }
  if (baca_sensor[0] > 34 && baca_sensor[1] > 34 && 
           baca_sensor[2] > 34 && baca_sensor[3] > 34 && 
           baca_sensor[4] > 34 && baca_sensor[5] > 34){
    //STOP CONDITION
    digitalWrite(pinEnable, HIGH);
    analogWrite(motor_kiri1, 0);
    digitalWrite(motor_kiri2, 0);

    digitalWrite(pinEnable2, HIGH);
    analogWrite(motor_kanan1, 0);
    analogWrite(motor_kanan2, 0);
  }
}