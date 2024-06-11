float RGB[3];

int ldrPin = 0;     // LDR’nin bağlı olduğu pin

int ambientLight;   //ortam ışığının değişkenini tanımlıyoruz

int redLed   = 11;  //kırmızı bacağın bağlı olduğu pin

int greenLed = 10;  // yeşil bacağın bağlı olduğu pin

int blueLed  = 9;   // mavi bacağın bağlı olduğu pin

 

void setup(){

  pinMode(redLed,OUTPUT);  // RGB LED’in bacaklarını çıkış olarak ayarladık

  pinMode(greenLed,OUTPUT);

  pinMode(blueLed,OUTPUT); 

 

 

  digitalWrite(redLed,LOW);

  digitalWrite(greenLed,LOW);

  digitalWrite(blueLed,LOW);

}

 

void loop(){

  for (float x=0;x<PI;x=x+0.00001){

    RGB[0]=255*abs(sin(x*(180/PI)));           // ışığın seviyesini ölçüyoruz kırmızı led için

    RGB[1]=255*abs(sin((x+PI/3)*(180/PI)));    // ışığın seviyesini ölçüyoruz yeşil led için

    RGB[2]=255*abs(sin((x+(2*PI)/3)*(180/PI)));// ışığın seviyesini ölçüyoruz mavi led için

    ambientLight=analogRead(ldrPin); // ortamdaki ışık seviyesini okuma

    if(ambientLight>600){ // eğer ortamdaki ışık çok düşükse ise aşağaki komutlar uygulanıyor

      analogWrite(redLed,RGB[0]);

      analogWrite(greenLed,RGB[1]);

      analogWrite(blueLed,RGB[2]);

    }

    else{

      digitalWrite(redLed,LOW);

      digitalWrite(greenLed,LOW);

      digitalWrite(blueLed,LOW);

    }

    for(int i=0;i<3;i++){

      if(RGB[i]<1){

        delay(100); // bekleme

      }

      if(RGB[i]<5){

        delay(50);

      }

      if(RGB[i]<10){

        delay(10);

      }

      if(RGB[i]<100){

        delay(5);

      }

    }

    delay(1);

  }

}