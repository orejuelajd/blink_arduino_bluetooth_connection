// Con este skectch enviamos un 1 (uno) o un 0 (cero) desde el portatil o pc y lo que hace es enceder el led del pin 13,
// mediante la conexion via bluetooth. El 1 o 0 lo enviamos mediante el monitor serial o usando el programa tera term, y haciendo que
// estos analicen el COM (ya sea 0, 1, 2, 3, ...) o puerto serial que se crea al emparentar (mediante bluetooth) el modulo bluetooth a nuestro equipo.

#include <SoftwareSerial.h>// Libreria para el serial bluetooth

SoftwareSerial btserial(10, 11); // RX, TX
int ledpin=13; // led 13 que va a parpadear segun lo ordenemos
int btdata; // el dato dado por el computador

void setup() {
  btserial.begin(9600);
  btserial.println("Bluetooth Para prender presione 1 y para apagar presione 0 ..");
  pinMode(ledpin,OUTPUT);
}

void loop() {
   if (btserial.available()){
     btdata=btserial.read();
   if(btdata=='1'){   // Si el numero es 1 ... se prende
   digitalWrite(ledpin,1);
     btserial.println("LED 13 Prendido ! ");
   }
  if (btdata=='0'){// Si el numero es 0 ... se apaga
  digitalWrite(ledpin,0);
     btserial.println("LED 13 Apagado ! ");
  }
}
delay(100);// Espera para el siguiente dato ...
}
