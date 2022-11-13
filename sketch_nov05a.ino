#include <Wire.h>
#include <SoftwareSerial.h>
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif

MPU6050 mpu;


bool dmpReady = false;  
uint8_t mpuIntStatus;   
uint8_t devStatus;     
uint16_t packetSize;    
uint16_t fifoCount;     
uint8_t fifoBuffer[64]; 


Quaternion q;           
VectorInt16 aa;        
VectorInt16 aaReal;     
VectorInt16 aaWorld;    
VectorFloat gravity;    
float euler[3];         
float ypr[3];           
volatile bool mpuInterrupt = false;   

void setup() 
{
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
        TWBR = 24; 
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif

    Serial.begin(9600);  //For use with Arduino Uno
    

    Serial.println(F("Initializing I2C devices..."));
    mpu.initialize();

    Serial.println(F("Testing device connections..."));
    Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));
    Serial.println(F("Initializing DMP..."));
    devStatus = mpu.dmpInitialize();

    mpu.setXGyroOffset(220);
    mpu.setYGyroOffset(76);
    mpu.setZGyroOffset(-85);
    mpu.setZAccelOffset(1788); 
    if (devStatus == 0) {
        Serial.println(F("Enabling DMP..."));
        mpu.setDMPEnabled(true);
        Serial.println(F("Enabling interrupt detection (Arduino external interrupt 0)..."));
        attachInterrupt(0, dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();
        Serial.println(F("DMP ready! Waiting for first interrupt..."));
        dmpReady = true;
        packetSize = mpu.dmpGetFIFOPacketSize();
    } else {
        Serial.print(F("DMP Initialization failed (code "));
        Serial.print(devStatus);
        Serial.println(F(")"));
    }
   
}

void sendData(int x, int y, int z)
{
  
    if(z < -10){   
      //forward
      
      Serial.write("f");  // Write to Uno
      Serial.write(10);   //Stop bit
    } else if (z > 0){
      //backward
      
      Serial.write("b");
      Serial.write(10);
    } else if (y > 5){   //To make more sensitive change value to 4 or less
      //right
      
      Serial.write("r");
      Serial.write(10);
    } else if (y < -5){  //To make more sensitive change to -4 or greater 
      //left
     
      Serial.write("l");
      Serial.write(10);
    } else
      //stop
     
      Serial.write("s");
      Serial.write(10);
         
}

void loop() 
{
  
    if (!dmpReady) return;
    mpuInterrupt = false;
    mpuIntStatus = mpu.getIntStatus();
    fifoCount = mpu.getFIFOCount();
    if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
        mpu.resetFIFO();
        Serial.println(F("FIFO Overflow"));

    } else if (mpuIntStatus & 0x02) {
        while (fifoCount < packetSize) {
          fifoCount = mpu.getFIFOCount();
        }
        mpu.getFIFOBytes(fifoBuffer, packetSize);        
        fifoCount -= packetSize;
        mpu.dmpGetQuaternion(&q, fifoBuffer);
        mpu.dmpGetGravity(&gravity, &q);
        mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
        sendData(ypr[0] * 180/M_PI, ypr[1] * 180/M_PI, ypr[2] * 180/M_PI);
    }
}

void dmpDataReady() 
{
    mpuInterrupt = true;
}
