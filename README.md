# mpu-9250_sensor-and-encoder-interfacing-with-Teensy4.0
> This experiment is contained to read the sensor value from both MPU-9250 and ENCODER Ics H9740, using Teensy4.0 Microcontroller  
##
# Interfacing MPU-9250 with Teensy4.0
> MPU-9250 has 10 pin on its chips the specific model has been shown below in figure 
![alt text](https://github.com/razainno/mpu-9250_sensor-and-encoder-interfacing-with-Teensy4.0/blob/master/mpu_9250.JPG)
> hardware connection of mpu-9250 and teensy4.0 has following pin connection
- Vcc pin of mpu-9250 is connected with 3v pin of Teeny4.0 
- GND pin of mpu-9250 is connected with GND pin of Teeny4.0
- SCL pin of mpu-9250 is connected with  pin-19 of Teeny4.0, its also connected with pin-16
- SDA pin of mpu-9250 is connected with  pin-18 of Teeny4.0, its also connected with pin-17
- ECL,EDA and NCS pins of mpu-9250 are not connected
- AD0  AND FSYNC pins of mpu-9250 are Grounded,ADO is used to select the address(ox68)
- INT pin of mpu-9250 is used for inturrupt, but in my case it is not connected 
![alt text](https://github.com/razainno/mpu-9250_sensor-and-encoder-interfacing-with-Teensy4.0/blob/master/mpu2.JPG)
