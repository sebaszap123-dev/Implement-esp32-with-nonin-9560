#include <LiquidCrystal_I2C.h>  //Libreria liquid crystal
#include <Arduino.h>            // La confiable libreria de arduino

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;
// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

class DisplayInfo {
public:
  void initLCD(bool);             // imprime el valor de LCD
  void initMessage(void);         // imprime el valor  inicial del mensaje
  void printLCD(String, String);  // imprimir el sensor
};

void DisplayInfo::initLCD(bool value) {
  lcd.begin(lcdColumns, lcdRows);  // inicializamos lcd, declaramos las columnas y las filas
  lcd.init();                      // iniciamos lcd
  lcd.clear();                     // limpiamos lcd
  lcd.home();
  lcd.backlight();
  initMessage();
}
void DisplayInfo::initMessage(void) {
  lcd.setCursor(0, 0);          // nos colocamos al inicio del lcd
  lcd.print("IOT 6 semestre");  // imprimimos en el lcd
  lcd.setCursor(0, 1);          // ahora nos colocamos un espacio despues
  lcd.print("software ");       // imprimimos software
  lcd.write(0);                 // llamamos al caracter declarado en la posicion 0
  lcd.print(" 2023");           //imprimimos 2022
}

void DisplayInfo::printLCD(String data, String status) {
  lcd.clear();           //limpiamos la lcd
  lcd.setCursor(0, 0);   // nos colocamos al inicio de lcd
  lcd.print("data: ");  //immprimimos el string
  lcd.print(data);       // imprimimos la variable 
  // lcd.write(1);// llamamos al caracter declarado en la posicion 1
  // lcd.print("C");//imprimimos c
  lcd.setCursor(0, 1);  // colocamos el cursor un espacio adelante
  lcd.print("Status:");   // imprimimos 
  lcd.print(status);      // imprimimos el contenido de la variable
}