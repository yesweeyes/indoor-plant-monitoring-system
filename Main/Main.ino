const int temperatureSensor_pin = A3;
const int soilMoistureSensor_pin = A4;
const int lightDependentResistor_pin = A5;

float temperatureSensorReading(int temperatureSensor_pin) {
  float valTempAnalog;
  float valTemp_Celsius;

  valTempAnalog = analogRead(temperatureSensor_pin);
  valTemp_Celsius = (valTempAnalog/1024)*5;
  valTemp_Celsius = valTemp_Celsius * 10;

  return valTemp_Celsius;
}


float soilMoistureSensorReading(int soilMoistureSensor_pin) {
  float valMoistureAnalog;
  float valMoisturePercenatge;

  valMoistureAnalog = analogRead(soilMoistureSensor_pin);
  valMoisturePercenatge = 100 - (valMoistureAnalog/1024)*100;

  return valMoisturePercenatge;
}


float lightDependetResistorReading(int lightDependentResistor_pin) {
  float valLightAnalog;
  float valLight;

  valLightAnalog = analogRead(lightDependentResistor_pin);
  valLight = valLightAnalog;  // Placeholder for formula

  return valLight;
}


void serialOutput(char string[], float val) {
  Serial.print(String(string) + ": " + String(val) + "\n");
}


void setup() {
  Serial.begin(9600);
  Serial.print("\n");
}

void loop() {
  float valFromTempModule = temperatureSensorReading(temperatureSensor_pin);
  float valFromSoilMoistureModule = soilMoistureSensorReading(soilMoistureSensor_pin);
  float valFromLDRModule = lightDependetResistorReading(lightDependentResistor_pin);

  Serial.println("##########");
<<<<<<< HEAD
  serialOutput("Temperature (°C) ", valFromTempModule);
  serialOutput("Soil Moisture (%) ", valFromSoilMoistureModule);
  serialOutput("Light ", valFromLDRModule);
=======
  serialOutput("Temperature (°C): ", valFromTempModule);
  serialOutput("Soil Moisture (%): ", valFromSoilMoistureModule);
  serialOutput("Light: ", valFromLDRModule);
>>>>>>> 9182fd689655eb4752dfe7e69b46d1749e2461bd
  Serial.print("\n");
  Serial.println("##########");

  delay(1500);
}
