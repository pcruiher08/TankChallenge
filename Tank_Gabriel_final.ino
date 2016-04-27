#include <Servo.h>
#include<vexMotor.h>
vexMotor motorDerecho;
vexMotor motorIzquierdo;
vexMotor tira;
vexMotor tilt;
Servo pan;
int state;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available() > 0){     
      state = Serial.read();   
    }
    
//    --------------CONTROL POR BLUETOOTH--------------
//    --------------Adelante--------------------
if (state == '1'){
      adelante();
    }
      // --------------Atras--------------------
      
    else if (state == '2'){
      atras();
    }
      // --------------Izquierda--------------------
    else if (state == '3'){
      izquierda();
    }
      // --------------Derecha--------------------
    else if (state == '4'){
      derecha();
    }
      // --------------Arriba--------------------
    else if (state == '5'){
      arriba();
    }
      // --------------Abajo--------------------
      else if (state == '6'){
      abajo();
    }
      // --------------Pan Derecha--------------------
      else if (state == '7'){
      panDerecha();
    }
      // --------------Pan Izquierda--------------------
      else if (state == '8'){
      panIzquierda();
    }
      // --------------Tira--------------------
      else if (state == '9'){
      tirale();
    }
     
}

//1
void adelante(){
motorDerecho.write(255);
motorIzquierdo.write(-255);
}
//2
void atras(){
  motorDerecho.write(-255);
motorIzquierdo.write(255);
}
//3
void izquierda(){
motorDerecho.write(255);
motorIzquierdo.write(255);
}
//4
void derecha(){
motorDerecho.write(-255);
motorIzquierdo.write(-255);
}
//5
void arriba(){
  tilt.write(20);
}
//6
void abajo(){
tilt.write(-20);
}
//7
void panDerecha(){
int p=pan.read();
if(p<180)
pan.write(p++);
}
//8
void panIzquierda(){
int p=pan.read();
if(p>0)
pan.write(p--);
}
//9
void tirale(){
tira.write(200);
}




