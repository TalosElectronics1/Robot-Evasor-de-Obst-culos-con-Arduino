#include "Sensor_ultrasonico_HCSR04.h"
#include "Base_Robot.h"
class Evasor
{
private:
	Base_Robot Robot;
	Sensor_ultrasonico_HCSR04 S1;
	Sensor_ultrasonico_HCSR04 S2;
	Sensor_ultrasonico_HCSR04 S3;
public:
	//Constructor
	Evasor(
		int Pin_Motor_1A,
		int Pin_Motor_1B,
		int PWM_1, 
		int Pin_Motor_1C, 
		int Pin_Motor_1D,
		int PWM_2,
		int echo_1,
		int trig_1,
		int echo_2,
		int trig_2,
		int echo_3,
		int trig_3):
	Robot(Pin_Motor_1A, Pin_Motor_1B, PWM_1, Pin_Motor_1C, Pin_Motor_1D, PWM_2),
	S1(echo_1,trig_1),
	S2(echo_2,trig_2),
	S3(echo_3,trig_3){}
	void Inicializar();
	void Modo_Evasor(int Velocidad);
	void Izquierda(int Velocidad_1,int Velocidad_2);
	void Adelante(int Velocidad_1,int Velocidad_2);

};