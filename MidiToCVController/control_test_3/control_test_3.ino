int data_0  = 9;
int data_1  = 10;
int data_2  = 11;
int data_3  = 8;
int w_e     = 12;
int addr_0  = 4;
int addr_1  = 5;
int addr_2  = 6;
int addr_3  = 7;


int number;

void setup() {
    pinMode(data_0, OUTPUT);
    pinMode(data_1, OUTPUT);
    pinMode(data_2, OUTPUT);
    pinMode(data_3, OUTPUT);
    pinMode(w_e, OUTPUT);
    pinMode(addr_0, OUTPUT);
    pinMode(addr_1, OUTPUT);
    pinMode(addr_2, OUTPUT);
    pinMode(addr_3, OUTPUT);
    digitalWrite(w_e,HIGH);
  number = 0;

}

void write_to_189(int data){
  digitalWrite(data_0, !bitRead(data, 0));
  digitalWrite(data_1, !bitRead(data, 1));
  digitalWrite(data_2, !bitRead(data, 2));
  digitalWrite(data_3, !bitRead(data, 3));
  digitalWrite(w_e, LOW);
  delay(1);
  digitalWrite(w_e, HIGH);
}


int delay_amount = 1000;


void loop() {
  digitalWrite(addr_0, bitRead(number, 0));
  digitalWrite(addr_1, bitRead(number, 1));
  digitalWrite(addr_2, bitRead(number, 2));
  digitalWrite(addr_3, bitRead(number, 3));
  write_to_189(number);
  delay(delay_amount);
  number = number + 1;

}
