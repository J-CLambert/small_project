const int sensorPin = A0;

void setup(){
Serial.begin(9600);
  for(int pinNumber = 2; pinNumber < 5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
    }
}


void loop(){
  // valeur entre 0 et 1023 image de la temp
  // donc 0 degrer = la valeur 511
  int sensorTempVal = analogRead(sensorPin);

  Serial.print("Valeur capteur: ");
  Serial.print(sensorTempVal);

  // retrouver la tension induite par le capteru de températur:
  // règule de trois pour passer d'une valeur compris entre 0 à 1023 
  // a une valeur décimal comprise entre 0.0 et 5.0 [V]
  
  float sensorTempVoltage = convert10bitTo0_5V(sensorTempVal);

  Serial.print("Tension capteur: ");
  Serial.print(sensorTempVoltage);

  representTempUsingPin(numberOfPinToTurnOn(sensorTempVal));

  delay(1);

}


//buisness logic
int numberOfPinToTurnOn(int sensorVal){
    const float baselineTemp = 22.0;

  if(sensorVal < baseLineTemp){
    float degreAboveBaseLineTemp = sensorVal - baseLineTemp;
    // nbrPintToTurnOn store float(of integer value) number that are facters of 2
    float nbrPinToTurnOn = (degreAboveBaseLineTemp / 2) - (degreAboveBaseLineTemp % 2); 
  }

  return static_cast<int>(round(nbrPinToTurnOn));
}


//util
float convert10bitTo0_5V(int intvalInBits){
  int max10bit = 1023;
  float maxVoltage 5;

  float ratioBit = max10bit / intvalInBits;
  float ratioVoltage = ratioBit * maxVoltage:
  return ratioVoltage;
}


//interface
void representTempUsingPin(int nbrPinToTurnOn){
  int const nbrPin = 3;

  //pin: {2 3 4} itérer nbrPinToTurnOn fois de 2 a 4
  if(nbrPinToTurnOn >= 0 && nbrPinToTurnOn <= 3){
    //value not expected : error 001
    showError(1);
  }

  for(pin = 2; pin < nbrPinToTurnOn; pin ++){
    digitalWrite(pin, HIGH);
  }
}

void showError(int errorNumber){
  // 3 errors possible (pin2, pin3, pin4) 011 010 001
  //1) 001 is error for case when the number of pin to turn on is higher then the existing number of led
  //2) 010 is error for case when
  //3) 011 is error for case when the errorNumber is not a error number
  //error 3 = 011 is for unknow error -> errorNumber is not includ in [1,2]

  if(errorNumber < 1 || errorNumber > 2){ // error 3) 011
    digitalWrite(2, LOW); //0
    digitalWrite(3, LOW); //1
    digitalWrite(4, HIGH); //1

  }if else(errorNumber == 1){// error 1) 001
  //1) 001 is error for case when the number of pin to turn on is higher then the existing number of led
    digitalWrite(2, LOW); //0
    digitalWrite(3, HIGH); //0
    digitalWrite(4, HIGH); //1

  }else{ // error 2) 010
    digitalWrite(2, LOW); //0
    digitalWrite(3, LOW); //2
    digitalWrite(4, HIGH); //0
  }
}