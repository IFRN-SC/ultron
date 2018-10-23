#define MOTOR_D OUT_A
#define MOTOR_E OUT_C

#define DISTANCIA_OBSTACULO 7
#define DISTANCIA_RAMPA 15

#define SONAR_FRE SensorUS (S2)
#define SONAR_LAT SensorUS (S3)

#define SENSOR_DIR S1
#define SENSOR_ESQ S4


// todas as variaveis presentes no código 
float verde_direito, verde_esquerdo, cinza_direito, cinza_esquerdo;
float preto_direito, preto_esquerdo, branco_direito, branco_esquerdo;

float S_direito_verde, S_esquerdo_verde;
float S_direito_preto, S_esquerdo_preto;
float H_direito_verde, H_esquerdo_verde;


bool sensor_direito_preto, sensor_esquerdo_preto;
bool sensor_direito_verde, sensor_esquerdo_verde;
bool sensor_direito_cinza, sensor_esquerdo_cinza;
bool sensor_direito_branco, sensor_esquerdo_branco;


bool interromper = false;
int posicaoZona = 1;


/*
     valores da variavel "posicaoZona"  
     1: zona direita
     2: zona esquerda
     3: zona bunda
 */

