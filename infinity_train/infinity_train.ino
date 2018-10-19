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
{	
	del = ((analogRead(SENS)/5)+20);
	//Serial.println((del));
	go_go_go();
}

void go_go_go()
{
	for(int i = 0; i < 200; i++)
	{
		digitalWrite(dir, LOW);
		digitalWrite(stp, HIGH);
		delayMicroseconds(del);
		digitalWrite(stp, LOW);
		delayMicroseconds(del);
	}
}