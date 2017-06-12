#include <DirectIO.h>
unsigned long t2=0;
unsigned long t3=0;
double pt2=0;
double pt3=0;
bool state = false;
long position=0;
int n = 0;
double d = 0.0;
InputPin d2(2);
InputPin d3(3);
byte list[4]={0,0,0,0};

void blink2(){
    for(int i=1;i<4;i++){
        list[i-1] = list[i];
    }
    list[3] = (d2<<1)|d3;
    checklist();
}
void blink3(){
    for(int i=1;i<4;i++){
        list[i-1] = list[i];
    }
    list[3] = (d2<<1)|d3;
    checklist();

}
void checklist(){
    if(list[0]==2&&list[1]==3&&list[2]==1&&list[3]==0){
        position++;
    }else if(list[0]==1&&list[1]==3&&list[2]==2&&list[3]==0){
        position--;
    }
}
void setup(){
    Serial.begin(115200);
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(2), blink2, CHANGE  );
    attachInterrupt(digitalPinToInterrupt(3), blink3, CHANGE  );
}
void loop(){
    delay(100);
    Serial.println(position/100.0);
}