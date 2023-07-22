int data_0  = 10;
int data_1  = 9;
int data_2  = 8;
int data_3  = 7;
int w_e     = 6;
int addr_0  = 5;
int addr_1  = 4;
int addr_2  = 11;
int addr_3  = 12;

void setup() {
  Serial.begin(9600);
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
  clear_buffer();
}

void clear_buffer(){
  for(int address = 0; address < 16; address++){
    write_addr(address);
    write_data(7);
  }
}

void write_data(int value){
  digitalWrite(data_0, value & 0x01);
  digitalWrite(data_1, (value >> 1) & 0x01);
  digitalWrite(data_2, (value >> 2) & 0x01);
  digitalWrite(data_3, (value >> 3) & 0x01);
  digitalWrite(w_e, LOW);
  digitalWrite(w_e, HIGH);
}

void write_addr(int value){
  digitalWrite(addr_0, value & 0x01);
  digitalWrite(addr_1, (value >> 1) & 0x01);
  digitalWrite(addr_2, (value >> 2) & 0x01);
  digitalWrite(addr_3, (value >> 3) & 0x01);
}


int value = 0;
int desired = 0;
int observed = 0;
bool oneMiss = false;


void loop() {
  value = value + 1;
  if(value == 16){
    value = 0;
  }

  write_addr(value);
  desired = analogRead(0);
  observed = analogRead(4);
  //a0divinternal = a0in / (128);
  //if(old != a0divinternal){
    //Serial.println("new value");
      if(value == 5){
        //if(abs(observed-desired) > 20){
          
        
        if(observed > desired){
            write_data(0);
        }else{
            write_data(7);
        }
        //}
      }
      Serial.println(observed);
      //Serial.println(desired);
      
      
  //}
  //old = a0divinternal;
  //delay(1);

}
