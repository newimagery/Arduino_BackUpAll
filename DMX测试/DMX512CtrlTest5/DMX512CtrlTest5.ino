
#include <DmxSimple.h>
#include <EEPROM.h>
#include <Keyboard.h>

#define SEQNUM  4           //序列个数
#define CHANNELNUM  32      //通道个数

struct LIGHTSEQ 
{
  double startTime;
  double stopTime;
  int channel;
  int value;
 // unsigned long lastTime;
};
unsigned short LightStatus[CHANNELNUM+1] = {0};

struct LIGHTSEQ lightSeq[SEQNUM] = //起始时间 终止时间 通道号 变化值 
{
  {0.0, 0.0, 1, 255},   
  {1000.0, 5000.0, 2, 255}, 
  {5000.0, 10000.0, 2, 128},
  {10000.0, 20000.0, 2, 0},
};

void setup() 
{
  Serial1.begin(9600);
  for (int i=0;i<CHANNELNUM;i++)
  {
    DmxSimple.write (i, 0);
  }
}

int nSeqNum = 0;
int anjian = 0;
bool bStop=true;
bool bPlaying = false;
double startTime = 0;
double now = 0;
double lastTime = 0;
//unsigned long realLastTime = 0;
int curValue = 0;
double hhe;
void loop()
{
  now = (double)millis ();
  if (bPlaying && nSeqNum<SEQNUM)
  {
    for (int i=nSeqNum;i<SEQNUM;i++)
    {
      if (lightSeq[i].startTime > now - startTime)
      {
        break;
      }
      if (lightSeq[i].stopTime < now - startTime + lightSeq[i].startTime)
      {
        curValue = lightSeq[i].value;
        LightStatus[lightSeq[i].channel] = lightSeq[i].value;
        nSeqNum++;
      }
      else 
      {
        //realLastTime = lightSeq[i].startTime>lastTime?lightSeq[i].startTime:lastTime;
        curValue = LightStatus[lightSeq[i].channel] + (int)((lightSeq[i].value - LightStatus[lightSeq[i].channel]) * (now - lightSeq[i].startTime - startTime) / (lightSeq[i].stopTime - lightSeq[i].startTime));
      }
      DmxSimple.write (lightSeq[i].channel, curValue);
      Serial.println(lightSeq[i].startTime);
      Serial.println(now); 
      Serial.println(LightStatus[lightSeq[i].channel]);
      Serial.println(curValue);
      Serial.println("\n");
      //LightStatus[lightSeq[i].channel] = curValue;    
    }
    //lastTime = now;
  }
  else if (bStop)
  {
    for (int i=0;i<CHANNELNUM;i++)
    {
      DmxSimple.write (i, 0);
    }
  }
  else if (nSeqNum>=SEQNUM)
  {
    bPlaying = false;
    bStop = true;
    startTime = 0;
    lastTime = 0;
    nSeqNum = 0;
  }

  if (Serial1.available() > 0) 
  {
    anjian = Serial1.read();
    if(anjian == 6)//串口第1个数字
    {
      delay(5);
      anjian = Serial1.read();
      if(anjian == 170)//串口第2个数字
      {
        delay(5);
        anjian = Serial1.read();
        if(anjian == 186 )//串口第3个数字
        {
          delay(5);
          anjian = Serial1.read(); 
          switch(anjian)
          {
          case  12://串口第4个数字
            delay(5);
            anjian = Serial1.read();
            if(anjian == 0)
            {
              //4#jian 
              if(!bPlaying)
              {
                bPlaying = true;
                if (bStop)
                {
                  startTime = (double)millis();
                  Serial.println(startTime);
                  lastTime = startTime;
                  bStop = false;
                }
              }
              Serial.println("//4#jian ");
            }
          case  63://串口第4个数字
            delay(5);
            anjian = Serial1.read();
            if(anjian == 0)
            {
              //5#jian 
              if(!bStop)
              {                          
                bPlaying = false;
                bStop = true;
                startTime = 0;
                lastTime = 0;
                nSeqNum = 0;
              }
              Serial.println("//5#jian ");
            }
            break;
          case  60:
            delay(5);
            anjian = Serial1.read();
            if(anjian == 0)
            {
              //6#jian 
              if(bPlaying)
              {
                bPlaying = false;
              }
              Serial.println("//6#jian ");
            }
            break;
          }
        }
      }
    }
  }
  
}
