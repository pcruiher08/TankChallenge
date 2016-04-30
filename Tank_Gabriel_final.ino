#include <Servo.h>
#include<vexMotor.h>

vexMotor motorDerecho;
vexMotor motorIzquierdo;
vexMotor torreta;
vexMotor vertical;
vexMotor tira;

 int state;
 int velocidad=200;
 
void setup() {
  // put your setup code here, to run once:
motorDerecho.attach(9);
  motorIzquierdo.attach(10);
  torreta.attach(11);
  vertical.attach(6);
  tira.attach(5);
  
   Serial.begin(9600);
}

void loop() {

if(Serial.available() > 0){     
      state = Serial.read();   
    }
    if (state == '1'){
      adelante();
     
    }
      // --------------Atras--------------------
    else if (state == '0'){
      motorDerecho.write(0);
      motorIzquierdo.write(0);
      torreta.write(0);
 vertical.write(0);
 tira.write(0);
    }
    else if(state == '4'){
    atras();
    }
    
    else if(state == '3'){
    derecha();
    }
    else if(state == '2'){
    izquierda();
    }
    else if(state == '6'){
    torretaIzquierda();
    }
    else if(state == '7'){
    torretaDerecha();
   // up;
    }
    else if(state == '5'){
    up();
    }
    else if(state == '8'){
    down();
    }
    else if(state == '9'){
    tirale();
    }
    
}
  void adelante(){
motorDerecho.write(velocidad);
motorIzquierdo.write(velocidad);
}
//2
void atras(){
  motorDerecho.write(velocidad*-1);
motorIzquierdo.write(velocidad*-1);
}

void derecha(){
motorDerecho.write(velocidad);
motorIzquierdo.write(velocidad*-1);
}

void izquierda(){
motorDerecho.write(velocidad*-1);
motorIzquierdo.write(velocidad);
}

void torretaIzquierda(){
torreta.write(velocidad/2);
}

void torretaDerecha(){
torreta.write(velocidad/2 *-1);
}

void up(){
vertical.write(velocidad/2);
}

void down(){
vertical.write(velocidad/2 *-1);
}


void tirale(){
tira.write(velocidad);
}
