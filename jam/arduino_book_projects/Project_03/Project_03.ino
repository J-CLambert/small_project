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

  float temperature = covertVoltageToDegre(sensorTempVoltage);
  int nbrPinToTurnOn = defineNbrPinToTurnOn(temperature);
  representTempUsingPin(nbrPinToTurnOn);

  delay(1);

}


//buisness logic
int defineNbrPinToTurnOn(float temperature){
   
  const float baseLineTemp = 22.0;

   if(temperature <= baseLineTemp){
       return 0;
    }

  float degreAboveBaseLineTemp = temperature - baseLineTemp;

  return roundNextOddSup(degreAboveBaseLineTemp) / 2;
}


//util
float convert10bitTo0_5V(int intvalInBits){
  float maxVoltage = 5.0;

  float ratioBit = intvalInBits / 1023.0 ;
  float ratioVoltage = ratioBit * maxVoltage;
  return ratioVoltage;
}

float covertVoltageToDegre(float volatage){
  return (volatage - .5) * 100;
}

int roundNextOddSup(float number){
  int numberRoundedToSup = 0;
  // condertire en int 3.5 -> 3 0.5 -> 1
  //1) arondire au supérieur
  numberRoundedToSup = static_cast<int>(ceil(number));

  //2) si non paire ajouter un
  if(numberRoundedToSup % 2 != 0){
    numberRoundedToSup += 1;
  }
  return numberRoundedToSup;
}

//interface
void representTempUsingPin(int nbrPinToTurnOn){
  int const nbrPin = 3;

  //pin: {2 3 4} itérer nbrPinToTurnOn fois de 2 a 4
  if(nbrPinToTurnOn < 0 || nbrPinToTurnOn > 3){
    //value not expected : error 001
    showError(1);
    return;
  }

  for(int pin = 2; pin < 5; pin ++){
    if(pin < 2 + nbrPinToTurnOn){
      digitalWrite(pin, HIGH);
    }else{
      digitalWrite(pin, LOW);
    } 
  }
}


void showError(int errorNumber){
  // 3 errors possible (pin2, pin3, pin4) 011 010 001
  //1) 001 is error for case when the number of pin to turn on is higher then the existing number of led
  //2) 010 is error for case when
  //3) 011 is error for case when the errorNumber is not a error number
  //error 3 = 011 is for unknow error -> errorNumber is not includ in [1,2]

  if(errorNumber < 1 || errorNumber > 2){ // error 3) 011
    digitalWrite(2, LOW);  //0
    digitalWrite(3, HIGH);  //1
    digitalWrite(4, HIGH); //1

  }else if(errorNumber == 1){// error 1) 001
  //1) 001 is error for case when the number of pin to turn on is higher then the existing number of led
    digitalWrite(2, LOW);  //0
    digitalWrite(3, LOW); //0
    digitalWrite(4, HIGH); //1

  }else{ // error 2) 010
    digitalWrite(2, LOW);  //0
    digitalWrite(3, HIGH); //1
    digitalWrite(4, LOW);  //0
  }
}