#include <DirectIO.h>
long positionX = 0;
long prevX = 0;
InputPin d2(2);
InputPin d3(3);
byte listX[4]={0,0,0,0};

void blinkX(){
    for(int i=1;i<4;i++){
        listX[i-1] = listX[i];
    }
    listX[3] = (d2<<1)|d3;
    checkListX();
}
void checkListX(){
    if(listX[0]==2&&listX[1]==3&&listX[2]==1&&listX[3]==0){
        positionX++;
    }else if(listX[0]==1&&listX[1]==3&&listX[2]==2&&listX[3]==0){
        positionX--;
    }
}
void setup(){
    Serial.begin(115200);
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(2), blinkX, CHANGE  );
    attachInterrupt(digitalPinToInterrupt(3), blinkX, CHANGE  );
}
void loop(){
    if(positionX!=prevX){
        prevX = positionX;
        Serial.print("X:");
        Serial.println(positionX/100.0);
    }
}