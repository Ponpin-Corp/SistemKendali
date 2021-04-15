//Riffat Dzahabi - 6702181030
//PonpinCorp
//PID Kasus P

//pin buat sensor analog
int baca_sensor[6];
int sensor1 = A0;
int sensor2 = A1;
int sensor3 = A2;
int sensor4 = A3;
int sensor5 = A4;
int sensor6 = A5;

int button1 = 7;
int button2 = 8;

//int tahan[6];

//pin buat enable
int pinEnable = 4;
int pinEnable2 = 2;

//pin buat motor kiri
int motor_kiri1 = 5;
int motor_kiri2 = 6;

//pin buat motor kanan
int motor_kanan1 = 3;
int motor_kanan2 = 11;

int sensorBit;
int maxpwm = 255;
int x;
char buff[100];
int LastError = 0;
int error = 0;

//kp,ki,kd
int kp = 40, ki = 0, kd = 0;
int rate_i, rate_d;
int speedKanan, speedKiri, setpoint = 120;

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
  
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  
  Serial.begin(9600);
}

void readsensor() { 
  baca_sensor[0] = analogRead(sensor1);
  baca_sensor[1] = analogRead(sensor2);
  baca_sensor[2] = analogRead(sensor3);
  baca_sensor[3] = analogRead(sensor4);
  baca_sensor[4] = analogRead(sensor5);
  baca_sensor[5] = analogRead(sensor6);
  
  
  delay(50);
  //for(x=0;x<=5;x++){
  //	Serial.print("Sensor ");
  //  Serial.print(x+1);
  //  Serial.print(": ");
  //  Serial.println(baca_sensor[x]);
  //	Serial.print("\n");
  // }
  //for(int x=0;x<=5;x++){
  //  Serial.println(tahan[x]);
 // }
 // for(int x=0;x<=5;x++){
 //   if(baca_sensor[x] < 33){
 //     tahan[x] = 1;//Gelap
 //   }
 //   else{
  //    tahan[x] = 0;//Terang
  //  }
 // }
//    sensorBit = 0;
 //   for (int x=0;x<=5;x++){
//      sensorBit += tahan[x] * (0 << x);
 //   }
}
//void pv(){
  //switch(sensorBit){
    //case 0b100000: error = -3;break;
    //case 0b110000: error = -2;break;
   // case 0b010000: error = -1;break;
    //
   // case 0b001100: error = 0;break;
   // case 0b000100: error = 0;break;
   // case 0b001000: error = 0;break;
    //
   // case 0b000010: error = 1;break;
   // case 0b000011: error = 2;break;
   // case 0b000001: error = 3;break;
   // default: error;break;
  //}
//}
void loop(){
    
  readsensor();
  //Serial.print("Nilai Last Error : ");
  //Serial.println(LastError);
  digitalWrite(pinEnable, HIGH);
  digitalWrite(pinEnable2, HIGH);
  
   //Sensor 1 dan 2 mendeteksi gelap, sisanya terang 
  if (baca_sensor[0] < 34 && baca_sensor[1] < 34 && 
      baca_sensor[2] > 34 && baca_sensor[3] > 34 && 
      baca_sensor[4] > 34 && baca_sensor[5] > 34){

    LastError = -2;
    ikutline(LastError);
  }
  //Sensor 2 dan 3 mendeteksi gelap, sisanya terang 
  if (baca_sensor[0] > 34 && baca_sensor[1] < 34 && 
      baca_sensor[2] < 34 && baca_sensor[3] > 34 && 
      baca_sensor[4] > 34 && baca_sensor[5] > 34){

    LastError = -1;
    ikutline(LastError);
  }
  //Sensor 3 dan 4 mendeteksi gelap, sisanya terang 
  if (baca_sensor[0] > 34 && baca_sensor[1] > 34 && 
      baca_sensor[2] < 34 && baca_sensor[3] < 34 && 
      baca_sensor[4] > 34 && baca_sensor[5] > 34){
    
    LastError = 0;
    ikutline(LastError);
  }
  //Sensor 4 dan 5 mendeteksi gelap, sisanya terang 
  if (baca_sensor[0] > 34 && baca_sensor[1] > 34 && 
      baca_sensor[2] > 34 && baca_sensor[3] < 34 && 
      baca_sensor[4] < 34 && baca_sensor[5] > 34){
    
    LastError = 1;
    ikutline(LastError);
  }  
  //Sensor 5 dan 6 mendeteksi gelap, sisanya terang 
  if (baca_sensor[0] > 34 && baca_sensor[1] > 34 && 
      baca_sensor[2] > 34 && baca_sensor[3] > 34 && 
      baca_sensor[4] < 34 && baca_sensor[5] < 34){

    LastError = 2;
    ikutline(LastError);
  }  
  //Semua sensor mendeteksi terang 
  if (baca_sensor[0] > 34 && baca_sensor[1] > 34 && 
      baca_sensor[2] > 34 && baca_sensor[3] > 34 && 
      baca_sensor[4] > 34 && baca_sensor[5] > 34){

      analogWrite(motor_kiri1, 0);
      analogWrite(motor_kiri2, 0);

      analogWrite(motor_kanan1, 0);
      analogWrite(motor_kanan2, 0);
  }
  if (baca_sensor[0] < 34 && baca_sensor[1] > 34 && 
      baca_sensor[2] > 34 && baca_sensor[3] > 34 && 
      baca_sensor[4] > 34 && baca_sensor[5] > 34){  
  //sensor 1
	LastError = -2;
    ikutline(LastError);
   }
  if (baca_sensor[0] > 34 && baca_sensor[1] < 34 && 
      baca_sensor[2] > 34 && baca_sensor[3] > 34 && 
      baca_sensor[4] > 34 && baca_sensor[5] > 34){
  //sensor 2
	LastError = -1;
	ikutline(LastError);
   }
  if (baca_sensor[0] > 34 && baca_sensor[1] > 34 && 
      baca_sensor[2] < 34 && baca_sensor[3] > 34 && 
      baca_sensor[4] > 34 && baca_sensor[5] > 34){
  //sensor 3
    LastError = 0;
    ikutline(LastError);
   }

	if (baca_sensor[0] > 34 && baca_sensor[1] > 34 && 
    baca_sensor[2] > 34 && baca_sensor[3] < 34 && 
    baca_sensor[4] > 34 && baca_sensor[5] > 34){
  	//sensor 4
  	LastError = 0;
	ikutline(LastError);
   }

	if (baca_sensor[0] > 34 && baca_sensor[1] > 34 && 
    baca_sensor[2] > 34 && baca_sensor[3] > 34 && 
    baca_sensor[4] < 34 && baca_sensor[5] > 34){
  	//sensor 5
 	 LastError = 1;
  	ikutline(LastError);
   }  

	if (baca_sensor[0] > 34 && baca_sensor[1] > 34 && 
    baca_sensor[2] > 34 && baca_sensor[3] > 34 && 
    baca_sensor[4] > 34 && baca_sensor[5] < 34){
  	//sensor 6
  	LastError = 2;
  	ikutline(LastError);
   }
}

void ikutline(int LastError){
  
  rate_d = error - LastError;
  rate_i = error + LastError;
  error = LastError;
  int control = (kp * error) + (ki * rate_i) + (kd * rate_d);
  //Serial.println(control);
  speedKanan = setpoint - control;
  speedKiri = setpoint + control;
  Serial.println(speedKanan);
  setMotor(speedKiri, speedKanan);
}

void setMotor(int pwmKiri,int pwmKanan){
  if (pwmKiri > maxpwm){
    pwmKiri = maxpwm;
  }
  else if (pwmKiri < -maxpwm){
    pwmKiri = -maxpwm;
  }
  if (pwmKiri < 0){
    pwmKiri *= -1;
    analogWrite(motor_kiri2, pwmKiri);
    analogWrite(motor_kiri1, 0);
  }
  else{
    analogWrite(motor_kiri2, 0);
    analogWrite(motor_kiri1, pwmKiri);
  }
   if (pwmKanan > maxpwm){
    pwmKanan = maxpwm;
  }
  else if (pwmKanan < -maxpwm){
    pwmKanan = -maxpwm;
  }
  if (pwmKanan < 0){
    pwmKanan *= -1;
    analogWrite(motor_kanan2, pwmKanan);
    analogWrite(motor_kanan1, 0);
  }
  else{
    analogWrite(motor_kanan2, 0);
    analogWrite(motor_kanan1, pwmKanan);
  }
}