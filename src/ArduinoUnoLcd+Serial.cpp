#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); //Instancia objeto lcd

String cadena = "";
bool hayCadena = false;

void setup(){
  Serial.begin(9600);   //Inicia puerto serie
  lcd.init();   // Inicia LCD
  lcd.backlight(); // Agregar brillo posterior
  lcd.clear();   // Limpia el lcd
  lcd.setCursor(0, 0);  // Posiciona cursor en col 0, fila 0
  lcd.print("LCD i2c ESP8266 ");    // Imprime en LCD
  lcd.setCursor(0, 1); // Segunda fila col 0, fila 1
  lcd.print("tecteach.net.ar "); // Imprime en LCD
}

void loop(){
  if(hayCadena){      //Según el estado de la bandera hayCadena
    cadena.trim();    // Quita \n o espacio al final de cadena.
    lcd.setCursor(0,0);  // Posiciona cursor en col 0, fila 0
    lcd.print(cadena);  //Imprime la cadena en LCD
    cadena = "";    //Limpia cadena
    hayCadena = false; //limpia flag.
  }
}

void serialEvent(){
  while (Serial.available()){
    char inChar = (char)Serial.read();
    cadena += inChar;
    if (inChar == '\n') {
      hayCadena = true;
    }
  }
  
}