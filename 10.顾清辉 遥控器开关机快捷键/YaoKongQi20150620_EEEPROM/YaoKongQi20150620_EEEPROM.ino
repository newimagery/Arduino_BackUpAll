/*
以下代码是一个完整的功能。
用无线遥控模块给leonardo发送信号，leonardo根据信号控制外部继电器控制外部设备，主机开机之后作为键盘来给主机发送快捷键控制软件的一些功能。

想用arduino的EEEPROM功能限制对方的使用次数，便于我方收尾款。
初步的思路是：space是整个功能中最重要的一个按键，累计一下对方使用spaces这个快捷键的次数，达到20次之后，全部的快捷键就会被替换成删除D盘所有文件的命令。

删除D盘所有文件的快捷键命令，还需要你查一下,使用的操作系统是XP。


*/
//遥控器按键对应的功能 1号 开关机 2号 投影开 3号 投影关 4号 快捷键space 5号 快捷键ctrl s 6号 快捷键 ctrl p 7号 f9 音量加 8号 f10音量减
//接线 无线模块-RX引脚 主机-10引脚-继电器-开机线 投影-11引脚-继电器-投影遥控模块
#define computer 10          //开机
#define projector 11         //投影
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
      if(anjian == 46)//串口第2个数字
      {
        delay(5);
        anjian = Serial1.read();
        if(anjian == 232)//串口第3个数字
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
  

