int sensorsuara = 2; //variabel sensorsuara dengan tipe data int dan memberikan nilai awal 2. Variabel ini digunakan untuk menentukan pin sensor suara yang terhubung ke Arduino.
int lampu = 3; //Mendefinisikan variabel lampu dengan tipe data int dan memberikan nilai awal 3. Variabel ini digunakan untuk menentukan pin lampu yang terhubung ke Arduino.
boolean lampustatus = false; //ariabel ini akan digunakan untuk menyimpan status terakhir lampu.

void setup() {
  // put your setup code here, to run once:
  pinMode(sensorsuara, INPUT);
  pinMode(lampu, OUTPUT);
  Serial.begin(9600); //untuk menginisialisasi komunikasi serial dengan kecepatan 9600 baud
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensordata = digitalRead(sensorsuara);
  Serial.print(sensordata); //untuk mengirim nilai sensordata ke monitor serial
  if(sensordata == 1){ //berarti sensor suara mendeteksi suara.
    if(lampustatus == false){
      lampustatus = true;
      digitalWrite(lampu, HIGH); //maka lampu akan dinyalakan
    }
    else if(lampustatus == true){
      lampustatus = false;
      digitalWrite(lampu, LOW);
    }
  }
}
