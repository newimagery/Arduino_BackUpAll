//按键 1开关机 2投影开 3投影关 4 space 5 ctrl s 6 ctrl p 7ctrl f1 音量加 8 ctrl f2音量减
//接线 无线模块-RX 主机-10-继电器-开机线 投影-11-继电器-牛逼遥控器
#define computer 10          //开机
#define projector 11         //投影
#include<keyboard.h>
void setup()
{
  pinMode(computer, OUTPUT);
  pinMode(projector, OUTPUT);
  digitalWrite(computer,HIGH);
  digitalWrite(projector,HIGH);
  Serial1.begin(9600);
  Keyboard.begin();
}
int flag_projector = 0;
int nochar_count = 0;

int anjian = 0;
void loop()
{
  

  if (Serial1.available() > 0) 
  {
    anjian = 0;
    anjian = Serial1.read();
    if(anjian == 6)//串口第1个数字
    {
      delay(5);
      anjian = Serial1.read();
      if(anjian == 162)//串口第2个数字
      {
        delay(5);
        anjian = Serial1.read();
        if(anjian == 47 )//串口第3个数字
        {
          delay(5);
          anjian = Serial1.read();
          switch(anjian)
          {
            case  192://串口第4个数字
                        delay(5);
                        anjian = Serial1.read();
                        if(anjian == 0)
                        {
                            ////1#按键 
                             //开机
                             digitalWrite(computer,LOW);
                             delay(100);						//延时100ms
                             digitalWrite(computer,HIGH);	//
                             
                             Serial.println("//1#jian ");
                        }
                        break;
            case  48://串口第4个数字
                        delay(5);
                        anjian = Serial1.read();
                        if(anjian == 0)
                        { 
                             digitalWrite(projector,LOW);             //开投影   
                             Serial.println("//2#jian");
                        }
                        break;
            case  240://串口第4个数字
                        delay(5);
                        anjian = Serial1.read();
                        if(anjian == 0)
                        {
                            //3#jian 
                          digitalWrite(projector,HIGH);             //关投影
                            Serial.println("//3#jian ");
                        }
                        break;
            case  12://串口第4个数字
                        delay(5);
                        anjian = Serial1.read();
                        if(anjian == 0)
                        {
                            //4#jian 
                            Keyboard.press(' ');		//向电脑发送向播放的指令
                            delay(50);		
                            Keyboard.releaseAll();
                            Serial.println("//4#jian ");
                        }
                        break;
            case  63://串口第4个数字
                        delay(5);
                        anjian = Serial1.read();
                        if(anjian == 0)
                        {
                            //5#jian 
                             Keyboard.press(KEY_LEFT_CTRL);
                             Keyboard.press('s');		//向电脑发送向停止的指令
                            delay(50);		
                            Keyboard.releaseAll();
                            Serial.println("//5#jian ");
                        }
                        break;

           
            case  252://串口第4个数字
                        delay(5);
                        anjian = Serial1.read();
                        if(anjian == 0)
                        {
                            //7#jian 
                            
                            Keyboard.press(KEY_F10);			//向电脑发送音量减的指令
                            delay(50);		
                            Keyboard.releaseAll();
                            
                            Keyboard.press(KEY_F10);			//向电脑发送音量减的指令
                            delay(50);		
                            Keyboard.releaseAll();
                            
                            Keyboard.press(KEY_F10);			//向电脑发送音量减的指令
                            delay(50);		
                            Keyboard.releaseAll();
                            
                            Keyboard.press(KEY_F10);			//向电脑发送音量减的指令
                            delay(50);		
                            Keyboard.releaseAll();
                            
                            Keyboard.press(KEY_F10);			//向电脑发送音量减的指令
                            delay(50);		
                            Keyboard.releaseAll();
                            
                            Serial.println("//7#jian ");
                        }
                        break;                        
            case  3://串口第4个数字
                        delay(5);
                        anjian = Serial1.read();
                        if(anjian == 0)
                        {
                            //8#jian 
                            
                            Keyboard.press(KEY_F9);		//向电脑发送音量减的指令
                            delay(50);		
                            Keyboard.releaseAll();
                            
                            Keyboard.press(KEY_F9);		//向电脑发送音量减的指令
                            delay(50);		
                            Keyboard.releaseAll();
                            
                            Keyboard.press(KEY_F9);		//向电脑发送音量减的指令
                            delay(50);		
                            Keyboard.releaseAll();
                            
                            Keyboard.press(KEY_F9);		//向电脑发送音量减的指令
                            delay(50);		
                            Keyboard.releaseAll();
                            
                            Keyboard.press(KEY_F9);		//向电脑发送音量减的指令
                            delay(50);		
                            Keyboard.releaseAll();
                            
                            Serial.println("//8#jian ");
                        }
                        break;
            case  195://串口第4个数字
                        delay(5);
                        anjian = Serial1.read();
                        if(anjian == 0)
                        {
                            //9#jian 
                             Serial.println("//9#jian ");
                        }
                        break;
            case  243://串口第4个数字
                        delay(5);
                        anjian = Serial1.read();
                        if(anjian == 0)
                        {
                            //10#jian 
                             Serial.println("//10#jian ");
                        }
                        break;
            case  51://串口第4个数字
                        delay(5);
                        anjian = Serial1.read();
                        if(anjian == 0)
                        {
                            //11#jian 
                             Serial.println("//11#jian ");
                        }
                        break;
            case  15://串口第4个数字
                        delay(5);
                        anjian = Serial1.read();
                        if(anjian == 0)
                        {
                            //12#jian 
                             Serial.println("//12#jian ");
                        }
                        break;
            case  255://串口第4个数字
                        delay(5);
                        anjian = Serial1.read();
                        if(anjian == 0)
                        {
                            //13#jian 
                             Serial.println("//13#jian ");
                        }
                        break;
            case  207://串口第4个数字
                        delay(5);
                        anjian = Serial1.read();
                        if(anjian == 0)
                        {
                            //14#jian 
                             Serial.println("//14#jian ");
                        }
                        break;
            case  204://串口第4个数字
                        delay(5);
                        anjian = Serial1.read();
                        if(anjian == 0)
                        {
                            //15#jian 
                             Serial.println("//15#jian ");
                        }
                        break;
          }
        }
      }
    }
  }
}
  

