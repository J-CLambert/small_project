setup(
const int sensorPin = A0;

for ( int pinNumber = 2; pinNumber<5; pinNumber++){
  pinMode(pinNumber, OUTPUT);
  digitalWrite(pinNumber, LOW);
  }
)

loop(
  // valeur entre 0 et 1023 image de la temp
  // donc 0 degrer = la valeur 511
int sensorTempVal =  analogRead(sensorPin);

Serial.print("Valeur capteur: ");
Serial.print(sensorTempVal);

// retrouver la tension induite par le capteru de températur:
// règule de trois pour passer d'une valeur compris entre 0 à 1023 
// a une valeur décimal comprise entre 0.0 et 5.0 [V]
float sensorTempVoltage = convert10bitTo0_5V(vouvertsensorTempVal);

Serial.print("Tension capteur: ");
Serial.print(sensorTempVoltage);
)

float convert10bitTo0_5V(int intvalInBits){
  int max10bit = 1023;
  float maxVoltage 5;
  float ratioBit = max10bit / intvalInBits;
  float ratioVoltage = ratioBit * maxVoltage:
  return ratioVoltage;
}

void representTempUsingPin(int nbrPinToTrunOn){
  int const nbrPin = 3;
  for()
}

int numberOfPinToTurnOn(int sensorVal){
    const float baselineTemp = 22.0;

  if(sensorVal < baseLineTemp){
    float degreAboveBaseLineTemp = sensorVal - baseLineTemp;
    // nbrPintToTurnOn store float(of integer value) number that are facters of 2
    float nbrPinToTurnOn = (degreAboveBaseLineTemp / 2) - (degreAboveBaseLineTemp % 2); 

  }
  return static_cast<int>(round(nbrPinToTurnOn));
}