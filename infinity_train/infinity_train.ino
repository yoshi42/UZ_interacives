int dir = 2;
int stp = 3;
int ms3 = 6;
int ms2 = 7;
int ms1 = 8;
int enable = 9;

#define SENS A7

int del = 0;

void setup()
{
	pinMode(dir, OUTPUT);
	pinMode(stp, OUTPUT);
	pinMode(ms1, OUTPUT);
	pinMode(ms2, OUTPUT);
	pinMode(ms3, OUTPUT);
	pinMode(enable, OUTPUT);
	pinMode(SENS, INPUT_PULLUP);

	digitalWrite(ms1, HIGH);
	digitalWrite(ms2, HIGH);
	digitalWrite(ms3, HIGH);
	digitalWrite(enable, LOW);

	Serial.begin(9600);
}

void loop()
{	if(analogRead(SENS) >= 550)
	{
		del = (1024-(analogRead(SENS))+50);
		Serial.println(del);
		go_go_go();
		digitalWrite(dir, LOW);
	}

	if(analogRead(SENS) < 450)
	{
		del = ((analogRead(SENS))+50);
		Serial.println(del);
		go_go_go();
		digitalWrite(dir, HIGH);
	}
}

void go_go_go()
{
	for(int i = 0; i < 200; i++)
	{
		digitalWrite(stp, HIGH);
		delayMicroseconds(del);
		digitalWrite(stp, LOW);
		delayMicroseconds(del);
	}
}