//Codigo base para competencia de Robochamps
//Se puede modificar editar o borrar cosas

//Seccion del codigo que importa la libreria
#include <AFMotor.h>
  
//Asi como inicializas variables tienes que declarar los motores
//Esto depende de la cantidad de motores y en que puerto este conectado
//Motor Izquierdo en el puerto 1 - frecuencia
AF_DCMotor motorIzquierdo(1, MOTOR12_1KHZ);

//Motor Derecho en el puerto 2 - frecuencia
AF_DCMotor motorDerecho(2, MOTOR12_1KHZ);

//Motor 3 en el puerto 3 - frecuencia
AF_DCMotor motor3_OtroUso(3, MOTOR34_1KHZ);

//Variable creada para recibir la senal del modulo bluetooth (Ahorita no tiene valor, posteriormente se le dara valor)
int valor_Recibido_Bluetooth;

int speed = 255; //Variable creada para dar una velocidad (255 - Velocidad maxima del motor,  0 - Velocidad minima no se va a mover)
  
void setup() {
  //En este espacio se hace setup a todo, en este codigo solo se declarara el Serial, que sirve para ir captando la senal del bluetooth
  Serial.begin(9600);

}


void loop(){
  //Condicional mencionada en el paso 5, en caso de que no se detecte modulo bluetooth el codigo no hara nada
  if(Serial.available() > 0){

      valor_Recibido_Bluetooth = Serial.read(); //Se le asignara lo recibido por el modulo bluetooth a esta variable
      

      //Inicializar con motores detenidos
      motorIzquierdo.setSpeed(0); //Se declara la velociada a la que girara el motor (0 - Nada)
      motorIzquierdo.run(RELEASE); //Se inicia el motor Release (No se aplicara ningun voltaje al motor)
      motorDerecho.setSpeed(0); //Se declara la velociada a la que girara el motor (0 - Nada)
      motorDerecho.run(RELEASE); //Se inicia el motor Release (No se aplicara ningun voltaje al motor)
      
      
      //Condicion que si el valor recibido por el modulo bluetooth es "F" (Boton de arriba) este realizara lo siguiente
      //En teoria el carro debe de avanzar
      if (valor_Recibido_Bluetooth == 'F'){
        motorIzquierdo.setSpeed(speed); //Se declara la velocidad a la que girara el motor
        motorIzquierdo.run(FORWARD); //Se inicia el motor en direccion FORWARD (Manecillas del reloj)
        motorDerecho.setSpeed(speed); //Se declara la velocidad a la que girara el motor
        motorDerecho.run(FORWARD); //Se inicia el motor en direccion FORWARD (Manecillas del reloj)
      }

      //Condicion que si el valor recibido por el modulo bluetooth es "B" (Boton de abajo) este realizara lo siguiente:
      //En teoria el carro debe de retroceder
      if (val == 'B'){
        motorIzquierdo.setSpeed(speed); //Se declara la velocidad a la que girara el motor
        motorIzquierdo.run(BACKWARD); //Se inicia el motor en direccion BACKWARD (Contra manecillas del reloj)
        motorDerecho.setSpeed(speed); //Se declara la velocidad a la que girara el motor
        motorDerecho.run(BACKWARD); //Se inicia el motor en direccion BACKWARD (Contra manecillas del reloj)
      }


      //Agregar mas ifs (Condicionales) dependiendo del boton o de lo que quieran hacer con el boton


  }
}