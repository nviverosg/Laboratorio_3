/*
Código de funcionamiento circuito electróninco 
Entrada analógica - salida en serie
La entrada analógica es procesada mediante el 
potenciómetro 
el valor leído por este varía entre 0-255
y dependiendo de la lectura del dispositivo
se establece la luminosidad de salida del led
(dependiendo de la resistencia establecida en el 
potenciómetro - resistencia variable) 
*/

/*
  Analog input, analog output, serial output
Respecto a las conexioness, el potenciómetro se alimenta
con +5V en el extremo positivo, y cierra su circuito 
conectando a tierra GND en placa arduino.
La luz led se conecta al pin 9, alimentado por placa 
arduino, y su otro extremo también conectado a tierra
*/
//Se definen variables globales para modificar lecturas
int sensorValue = 0;

int outputValue = 0;
// mediante función set up se establecen pines utilizados
// se establecen 9600 baudios
void setup()
{
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);

}
// mediante función loop se establece funcionamiento del circuito
void loop()
{
  // se lee valor del potenciómetro:
  sensorValue = analogRead(A0);
  // rango de salida actuación de entrada analógica:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // se interviene luz led, dependiendo de lectura:
  analogWrite(9, outputValue);
  // se imprime valor de actuación luz led:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);
  // se establece duración de 2 milisegundos para volver 
  // a releer loop, tiempo para lectura de señales
  // y lectura del usuario en pantalla:
  delay(2); // Wait for 2 millisecond(s)
}
