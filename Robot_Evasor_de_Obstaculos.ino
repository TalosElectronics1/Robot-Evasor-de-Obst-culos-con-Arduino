//Sensor ultrasonico Izquierda
#define SI_Echo    13    // Pin de Eco
#define SI_Trig    12    // Pin de Disparo

//Sensor ultrasonico Centro
#define SC_Echo    11    // Pin de Eco
#define SC_Trig    10    // Pin de Disparo

//Sensor ultrasonico Derecha
#define SD_Echo    9    // Pin de Eco
#define SD_Trig    8    // Pin de Disparo

//Motores
#define Motor1A   3    // Señal A Motor 1 
#define Motor1B   2    // Señal B Motor 1 
#define Motor2A   5    // Señal A Motor 2 
#define Motor2B   4    // Señal B Motor 2  
#define MotorE    6    // Señal Enable Motor 1 y 2 

void Adelante();  
void Izquierda();

long lduration_SI   = 0;
long ldistance_SI   = 0;
long lduration_SC   = 0;
long ldistance_SC   = 0;
long lduration_SD   = 0;
long ldistance_SD   = 0;

void setup() 
{  
  //Configuración Sensor Ultrasonico Izquierda
  pinMode(SI_Trig, OUTPUT);
  pinMode(SI_Echo, INPUT); 

  //Configuración Sensor Ultrasonico Centro
  pinMode(SC_Trig, OUTPUT);
  pinMode(SC_Echo, INPUT); 

  //Configuración Sensor Ultrasonico Derecha
  pinMode(SD_Trig, OUTPUT);
  pinMode(SD_Echo, INPUT); 

  //Configuración motores
  pinMode(Motor1A, OUTPUT);
  pinMode(Motor1B, OUTPUT);
  pinMode(Motor2A, OUTPUT);
  pinMode(Motor2B, OUTPUT);  
  pinMode(MotorE, OUTPUT);  
}

void loop() 
{ 
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //    Genera una señal PWM en una escala de 0 a 255, sirve para regular la velucidad de los motores a pasos   //
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  analogWrite(MotorE, 200);            
  
  while(1)
  {
      ////////////////////////////////////////////////////////////////
      //    Mide la distancia a la que se encuentra el obstaculo    //
      ////////////////////////////////////////////////////////////////
      
      digitalWrite(SI_Trig, LOW);               
      delayMicroseconds(2); 
      digitalWrite(SI_Trig, HIGH);
      delayMicroseconds(10);
      digitalWrite(SI_Trig, LOW);
      lduration_SI = pulseIn(SI_Echo, HIGH);
      ldistance_SI =  (lduration_SI/2) / 29.1;

      digitalWrite(SC_Trig, LOW);               
      delayMicroseconds(2); 
      digitalWrite(SC_Trig, HIGH);
      delayMicroseconds(10);
      digitalWrite(SC_Trig, LOW);
      lduration_SC = pulseIn(SC_Echo, HIGH);
      ldistance_SC =  (lduration_SC/2) / 29.1;

      digitalWrite(SD_Trig, LOW);               
      delayMicroseconds(2); 
      digitalWrite(SD_Trig, HIGH);
      delayMicroseconds(10);
      digitalWrite(SD_Trig, LOW);
      lduration_SD = pulseIn(SD_Echo, HIGH);
      ldistance_SD =  (lduration_SD/2) / 29.1;

      //////////////////////////////////////////
      //    Algoritmo evasor de obstaculos    //
      //////////////////////////////////////////
      
      if(ldistance_SI < 20 ||  ldistance_SC < 20 || ldistance_SD < 20)   
      {       
          Izquierda();
      }
      else
      {                  
          Adelante();
      }
   }
}

void Adelante()
{
  digitalWrite(Motor1A, HIGH); 
  digitalWrite(Motor1B, LOW);
  digitalWrite(Motor2A, HIGH); 
  digitalWrite(Motor2B, LOW);
}
void Izquierda()
{
  digitalWrite(Motor1A, HIGH); 
  digitalWrite(Motor1B, LOW);
  digitalWrite(Motor2A, LOW); 
  digitalWrite(Motor2B, HIGH);
}
