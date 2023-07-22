 int data_0  = 10;
int data_1  = 9;
int data_2  = 8;
int data_3  = 7;
int w_e     = 6;
int addr_0  = 5;
int addr_1  = 4;
int addr_2  = 11;
int addr_3  = 12;

bool addr_lsb;
bool addr_mb;
bool addr_msb;

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

  addr_lsb = false;
  addr_mb = false;
  addr_msb = false;

  digitalWrite(data_3,LOW);
  for(int index = 0; index < 4; index++){
    write_value(index);
    increment_address();
  }
  for(int index = 4; index > 0; index--){
    write_value(index);
    increment_address();
  }
  
  
}

void write_value(int value){
  digitalWrite(w_e,LOW);
  if(value == 7){
    digitalWrite(data_0, HIGH);
    digitalWrite(data_1, HIGH);
    digitalWrite(data_2, HIGH);
  }else if(value == 6){
    digitalWrite(data_0, LOW);
    digitalWrite(data_1, HIGH);
    digitalWrite(data_2, HIGH);
  }else if(value == 5){
    digitalWrite(data_0, HIGH);
    digitalWrite(data_1, LOW);
    digitalWrite(data_2, HIGH);
  }else if(value == 4){
    digitalWrite(data_0, LOW);
    digitalWrite(data_1, LOW);
    digitalWrite(data_2, HIGH);
  }else if(value == 3){
    digitalWrite(data_0, HIGH);
    digitalWrite(data_1, HIGH);
    digitalWrite(data_2, LOW);
  }else if(value == 2){
    digitalWrite(data_0, LOW);
    digitalWrite(data_1, HIGH);
    digitalWrite(data_2, LOW);
  }else if(value == 1){
    digitalWrite(data_0, HIGH);
    digitalWrite(data_1, LOW);
    digitalWrite(data_2, LOW);
  }else if(value == 0){
    digitalWrite(data_0, LOW);
    digitalWrite(data_1, LOW);
    digitalWrite(data_2, LOW);
  }
  delay(10);
  digitalWrite(w_e,HIGH);
}



void increment_address(){
  if(addr_msb){     //1xx
    if(addr_mb){      //11x
      if(addr_lsb){     //111 -> 000
        addr_msb = false;
        addr_mb = false;
        addr_lsb = false;
      }else{            //110 -> 111
        addr_msb = true;
        addr_mb = true;
        addr_lsb = true;
      }
    }else{            //10x
      if(addr_lsb){     //101 -> 110
        addr_msb = false;
        addr_mb = true;
        addr_lsb = true;
      }else{            //100 -> 101
        addr_msb = true;
        addr_mb = false;
        addr_lsb = true;
      }
    }
  }else{            //0xx
    if(addr_mb){      //01x
      if(addr_lsb){     //011 -> 100
        addr_msb = false;
        addr_mb = false;
        addr_lsb = true;
      }else{            //010 -> 011
        addr_msb = true;
        addr_mb = true;
        addr_lsb = false;
      }
    }else{            //00x
      if(addr_lsb){     //001 -> 010
        addr_msb = false;
        addr_mb = true;
        addr_lsb = false;
      }else{            //000 -> 001
        addr_msb = true;
        addr_mb = false;
        addr_lsb = false;
      }
    }
  }
  digitalWrite(addr_0, LOW);
  digitalWrite(addr_1, addr_lsb);
  digitalWrite(addr_2, addr_mb);
  digitalWrite(addr_3, addr_msb);
  
}

int delay_amount = 1000;


void loop() {
  //increment_address();
  //delay(delay_amount);
}
