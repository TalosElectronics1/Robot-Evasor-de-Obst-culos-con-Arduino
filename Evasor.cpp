#include <Arduino.h> //Permite utilizar los comandos de Arduino
#include "Evasor.h"
void Evasor::Inicializar()
{
	Robot.Inicializar_Robot();
	S1.Inicializar_ultrasonico();
	S2.Inicializar_ultrasonico();
	S3.Inicializar_ultrasonico();
}
void Evasor::Izquierda(int Velocidad_1,int Velocidad_2)
{
	Robot.Motor_1.Adelante(Velocidad_1);
    Robot.Motor_2.Atras(Velocidad_2);
}
void Evasor::Adelante(int Velocidad_1,int Velocidad_2)
{
	Robot.Atras(Velocidad_1,Velocidad_2);
}
void Evasor::Modo_Evasor(int Velocidad)
{
	float Distancia_1;
	float Distancia_2;
	float Distancia_3;
	//Robot.Atras(Velocidad,Velocidad);
	
      ////////////////////////////////////////////////////////////////
      //    Mide la distancia a la que se encuentra el obstaculo    //
      ////////////////////////////////////////////////////////////////
  	Distancia_1=S1.Obtener_Distancia();
  	Distancia_2=S2.Obtener_Distancia();
  	Distancia_3=S3.Obtener_Distancia();
  	//////////////////////////////////////////
      //    Algoritmo evasor de obstaculos    //
      //////////////////////////////////////////
      
      if(Distancia_1 < 20 ||  Distancia_2 < 20 || Distancia_3 < 20)   
      {       
          Izquierda(Velocidad,Velocidad);
      }
      else
      {                  
          Adelante(Velocidad,Velocidad);
      }

}