  // Projeto de Detecção de Luz
	#include <LiquidCrystal.h>
  // Informando as variáveis para o código
  int sensorPin = A0; // Pino do sensor.
  int redPin = 13; // Pino do LED vermelho.
  int yellowPin = 12; // Pino do LED amarelo.
  int greenPin = 11; // Pino do LED verde.
  int buzzerPin = 2; // Pino do buzzer.
  int sensorValueRaw = 0; // Variável para armazenar o valor do sensor

  unsigned long previousMillis = 0; //Variável para estocar o millis anterior
  int buzzerDelay = 3000; //Delay do buzzer para desligar

  const int yellowAlert = 55; //Limite para acionar alerta amarelo
  const int redAlert = 67; // Limite para acionar o alerta vermelho

  LiquidCrystal lcd(10,9,8,6,5,4,3);
  // Setar a tipagem dos pinos
  void setup(){
    pinMode(redPin,OUTPUT);
    pinMode(yellowPin,OUTPUT);
    pinMode(greenPin,OUTPUT);
    pinMode(buzzerPin,OUTPUT);
    Serial.begin(9600);
    lcd.begin(16,2);
    lcd.print("EPDM Corp.");
    delay(5000);
    lcd.clear();
    lcd.print("Luminosidade");
    lcd.setCursor(2,1);
    lcd.print("%");
  }

  // Função para desligar o buzzer após 3 segundos utilizando millis como alternativa do delay
  void buzzer(){
    if ((millis() - previousMillis) > buzzerDelay){
      digitalWrite(buzzerPin, LOW);
      previousMillis = millis();
    }
  }

  // Função principal
  void loop(){
    sensorValueRaw = analogRead(sensorPin); // Lê o valor do sensor
    int sensorValue = map(sensorValueRaw, 17, 1005, 0, 100); // Converte o valor para o intervalo de PWM
    
    Serial.print("Intensidade de Luz: ");
    Serial.println(sensorValue); // Imprime o valor do sensor no monitor serial DELETAR
    lcd.setCursor(0,1);
	
    lcd.print(sensorValue);
    
    if (sensorValue <= 10){ // Se o valor for menor que 10, remove o segundo digito
    lcd.setCursor(1,1);
    lcd.print(" ");
    }
    Serial.println(sensorValueRaw);
  	
    
    if (sensorValue >= yellowAlert && sensorValue <= redAlert){ //Condição para acionar o alerta amarelo
      digitalWrite(redPin,LOW);
      digitalWrite(yellowPin,HIGH);
      digitalWrite(greenPin,LOW);
      
      digitalWrite(buzzerPin,HIGH);
      buzzer();
    } else if (sensorValue > redAlert){ //Condição para acionar o alerta vermelho
      digitalWrite(redPin,HIGH);
      digitalWrite(yellowPin,LOW);
      digitalWrite(greenPin,LOW);
      
      digitalWrite(buzzerPin,HIGH);
      buzzer();
    } else{	// Caso nenhuma das condições acima é acionada, fica no verde
      digitalWrite(redPin,LOW);
      digitalWrite(yellowPin,LOW);
      digitalWrite(greenPin,HIGH);
    
      digitalWrite(buzzerPin, LOW);
    }
    delay(500);
  }
