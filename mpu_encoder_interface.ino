/*
This code is written to read the data from sensor mpu-9250 and encoder H-9740, USING THE TENSY4.0
SCL PIN of sensor is connected with teensy pin 19
Ssda PIN of sensor is connected with teensy pin 18
VCC PIN of sensor is connected with teensy pin 3V
AD0,Ground and FSYNC PINS of sensor ARE connected with teeny Ground


there are two encoder are used with name 'Right' and 'Left', each encoder has four pin 
vcc is connected with TEENSY PIN vin
Ground pin is connected with TEENSY Gound
for 'left' encoder chanel A and Channel B are connected with TEENSY pin-0 and pin-1
for 'right' encoder chanel A and Channel B are connected with TEENSY pin-2 and pin-3
*/

#include "MPU9250.h"
#include "QuadEncoder.h"


// an MPU9250 object with the MPU-9250 sensor on I2C bus 0 with address 0x68
MPU9250 IMU(Wire,0x68);
int status;
QuadEncoder knobLeft(1, 0, 1);
// Encoder on channel 2 of 4 available
//Phase A (pin2), PhaseB(pin3), Pullups Req(0)
QuadEncoder knobRight(2, 2, 3);
void setup() {
  // serial to display data
  Serial.begin(115200);
   knobLeft.setInitConfig();
  knobLeft.init();
  /* Initialize Encoder/knobRight. */
  knobRight.setInitConfig();
  knobRight.init();
  while(!Serial) {}
  

  // start communication with IMU 
  status = IMU.begin();
  if (status < 0) {
    Serial.println("IMU initialization unsuccessful");
    Serial.println("Check IMU wiring or try cycling power");
    Serial.print("Status: ");
    Serial.println(status);
    while(1) {}
  }
  // setting the accelerometer full scale range to +/-8G 
  IMU.setAccelRange(MPU9250::ACCEL_RANGE_8G);
  // setting the gyroscope full scale range to +/-500 deg/s
  IMU.setGyroRange(MPU9250::GYRO_RANGE_500DPS);
  // setting DLPF bandwidth to 20 Hz
  IMU.setDlpfBandwidth(MPU9250::DLPF_BANDWIDTH_20HZ);
  // setting SRD to 19 for a 50 Hz update rate
  IMU.setSrd(19);
}

long positionLeft  = 100;
long positionRight = 100;

void loop() {
  long newLeft, newRight;
  
  // read the sensor
  newLeft = knobLeft.read();
  newRight = knobRight.read();
  IMU.readSensor();
  // display the data
  Serial.print(" accelerometer value along x,y ,z axis");
   Serial.print(" \n");
  Serial.print(IMU.getAccelX_mss(),6);
  Serial.print(" \t");
  Serial.print(IMU.getAccelY_mss(),6);
  Serial.print("\t");
  Serial.print(IMU.getAccelZ_mss(),6);
  Serial.print("\n");
  Serial.print("********************************************* ");
   Serial.print("\n");
  Serial.print(" Gyroscope value along x,y ,z axis in Radian");
  Serial.print("\n");
  Serial.print(IMU.getGyroX_rads(),6);
  Serial.print("\t");
  Serial.print(IMU.getGyroY_rads(),6);
  Serial.print("\t");
  Serial.print(IMU.getGyroZ_rads(),6);
  Serial.print("\n");
  Serial.print("********************************************* ");
   Serial.print("\n");
  Serial.print(" Magnetometer value along x,y ,z axis in Micro Taxila");
  Serial.print("\n"); 
  Serial.print(IMU.getMagX_uT(),6);
  Serial.print("\t");
  Serial.print(IMU.getMagY_uT(),6);
  Serial.print("\t");
  Serial.print(IMU.getMagZ_uT(),6);
  Serial.print("\n");
  Serial.print("********************************************* ");
   Serial.print("\n");
  Serial.print(" temperature value in centigrate");
  Serial.print("\n");
  Serial.println(IMU.getTemperature_C(),6);
  Serial.print("\n");
  Serial.print("********************************************* ");
   Serial.print("\n");
  Serial.print("\n");
  Serial.print(" left and right encoder values");
  Serial.print("\n");
  
   Serial.print("Left = ");
   Serial.print(newLeft);
   Serial.print(", Right = ");
   Serial.print(newRight);
   Serial.println();
   positionLeft = newLeft;
   positionRight = newRight;
  
  // if a character is sent from the serial monitor,
  // reset both back to zero.
  if (Serial.available()) {
    Serial.read();
    Serial.println("Reset both knobs to zero");
    knobLeft.write(0);
    knobRight.write(0);
  }
   Serial.print("********************************************* ");
   Serial.print("\n");
  delay(1000);
}
