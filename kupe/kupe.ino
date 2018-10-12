#include <Servo.h>
#include <DFPlayer_Mini_Mp3.h>

int but1 = 23;
int but2 = 25;
int but3 = 27;
int but4 = 31;
int but5 = 37;
int but6 = 41;
int but7 = 45;
int but8 = 49;

int mosfet1_answerLED1 = 22; // HIGH signal = close circuit
int mosfet2_answerLED2 = 24; // HIGH signal = close circuit
int mosfet3_answerLED3 = 26; // HIGH signal = close circuit
int mosfet4_answerLED4 = 28; // HIGH signal = close circuit
int mosfet5_answerLED5 = 30; // HIGH signal = close circuit
int mosfet6_answerLED6 = 32; // HIGH signal = close circuit
int mosfet7_answerLED7 = 34; // HIGH signal = close circuit
int mosfet8_answerLED8 = 36; // HIGH signal = close circuit

int mosfet1_mirror = 46; // HIGH signal = close circuit
int mosfet2_tea = 44; // HIGH signal = close circuit
int mosfet7_book = 38; // HIGH signal = close circuit
int ssr1_light1 = 40; // LOW signal = close circuit
int ssr2_light2 = 42; // LOW signal = close circuit
int servo_pin = 10;

Servo servo; //declare variable for servo

int stepper_curtains_en = 3; // HIGH signal = motor is off
int stepper_curtains_stp = 4; 
int stepper_curtains_dir = 5;

int pleer1_busy = 15; //LOW = play, HIGH = stop
int pleer2_busy = 14;

unsigned long RamkaTime1;
unsigned long RamkaTime2;
unsigned long RamkaTime3;
unsigned long RamkaTime4;
unsigned long RamkaTime5;
unsigned long RamkaTime6;
unsigned long RamkaTime7;
unsigned long RamkaTime8;

unsigned long ButtonTime1;
unsigned long ButtonTime2;
unsigned long ButtonTime3;
unsigned long ButtonTime4;
unsigned long ButtonTime5;
unsigned long ButtonTime6;
unsigned long ButtonTime7;
unsigned long ButtonTime8;

bool flag1 = 0;
bool flag2 = 0;
bool flag3 = 0;
bool flag4 = 0;
bool flag5 = 0;
bool flag6 = 0;
bool flag7 = 0;
bool flag8 = 0;

const int delay_time = 3000; //time to read answer

void setup()
{
	pinMode(but1, INPUT_PULLUP);
    pinMode(but2, INPUT_PULLUP);
    pinMode(but3, INPUT_PULLUP);
    pinMode(but4, INPUT_PULLUP);
    pinMode(but5, INPUT_PULLUP);
    pinMode(but6, INPUT_PULLUP);
    pinMode(but7, INPUT_PULLUP);
    pinMode(but8, INPUT_PULLUP);
    pinMode(pleer1_busy, INPUT_PULLUP);
    pinMode(pleer2_busy, INPUT_PULLUP);

    pinMode(mosfet1_answerLED1, OUTPUT);
    pinMode(mosfet2_answerLED2, OUTPUT);
    pinMode(mosfet3_answerLED3, OUTPUT);
    pinMode(mosfet4_answerLED4, OUTPUT);
    pinMode(mosfet5_answerLED5, OUTPUT);
    pinMode(mosfet6_answerLED6, OUTPUT);
    pinMode(mosfet7_answerLED7, OUTPUT);
    pinMode(mosfet8_answerLED8, OUTPUT);
    pinMode(stepper_curtains_en, OUTPUT);
    pinMode(stepper_curtains_stp, OUTPUT);
	pinMode(stepper_curtains_dir, OUTPUT);
	servo.attach(servo_pin); //declare servo pin D10

    digitalWrite(mosfet1_answerLED1, HIGH);
  	digitalWrite(mosfet2_answerLED2, HIGH);
  	digitalWrite(mosfet3_answerLED3, HIGH);
  	digitalWrite(mosfet4_answerLED4, HIGH);
  	digitalWrite(mosfet5_answerLED5, HIGH);
  	digitalWrite(mosfet6_answerLED6, HIGH);
  	digitalWrite(mosfet7_answerLED7, HIGH);
  	digitalWrite(mosfet8_answerLED8, HIGH);
  	digitalWrite(stepper_curtains_en, LOW);

	Serial.begin(9600);
	Serial2.begin(9600);
	Serial3.begin(9600);
}

void loop()
{
	but1_rel();
}

void pleer1()
{
	if(digitalRead(pleer1_busy) == LOW)
	{
		mp3_set_serial(Serial3);
		delay(10);
		mp3_set_volume (20);
		mp3_play(1);
	}
}

void pleer2()
{
	if(digitalRead(pleer1_busy) == LOW)
	{
		mp3_set_serial(Serial2);
		delay(10);
		mp3_set_volume (20);
		mp3_play(1);
	}
}

void ticket()
{
	for (int i = 0; i <= 180; i++)
	{
		servo.write(i); //stand servo for i degrees
		delay(5); //wait time between steps
	}
	delay(2000);
	for (int i = 180; i > 0; i--)
	{
		servo.write(i); //stand servo for i degrees
		delay(20); //wait time between steps
	}
}

void but1_rel() // 1Gramofon
{
	if (digitalRead(but1) == LOW && flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0 && flag5 == 0 && flag6 == 0 && flag7 == 0 && flag8 == 0)
	{
		delay(50);
		flag1 = 1;
		Serial.println("Button_pushed, do something for a few seconds");
		//ticket(); //and do something
		ButtonTime1 = millis();
	}

	if ((millis() - ButtonTime1 > 3000) && flag1 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag1 = 0;
		digitalWrite(mosfet1_answerLED1, HIGH); //show the answer
		Serial.println("Something done, light is on for some time to read an answer");
		RamkaTime1 = millis();
		delay(delay_time);
		digitalWrite(mosfet1_answerLED1, LOW); //show the answer
		Serial.println("Light is off");

	}
}