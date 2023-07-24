# IOT-BASED-WATER-LEVEL-MONITORING-AND-CONTROL-SYSTEM
Internet of Things is becoming so popular in today’s era, Now-a-days people are used to implementing the features of the IoT in verities of fields. Now, with the evolution of the technology with IoT, we are able to control and monitor our electronic, and electrical devices from anywhere in the world. Here in our project, we have introduced a smart IoT-based water monitoring and controlling system which will eventually reduce the wastage of the water. The system we have developed can be able to control the electric water pumps and eventually our system can switch on and off the pump based on the capacity of the water inside the water tank. Our proposed concept and project are very helpful and will eventually reduce the wastage of water. In this project, we have used NodeMCU ESP 8266 board as the main microcontroller board, the ultrasonic sensor module used to detect the water level of the tank, and one relay module which will control the electric pump. In this project work, the Blynk platform has been used to get connected with the internet and control and monitor purposes. The Blynk is a cloud platform where anyone can build projects related to the Internet of Things. So, we actually plan the whole project to build a specific device enabled with IoT to meet our holy goal to save water and reduce the wastage of water in the time of filling the water tanks in our houses and government water tanks. Introduction: Water is the basic necessity and most significant resource of our planet, for the functioning of all life forms that exist on earth water is the prime necessity. Without water, we cannot imagine any life form that exists in the world. But, In the present scenario due to the increase in pollution and other harmful effects caused by humans the global average temperature is rising day by day. It is very painful to see that we are wasting water where lots of people are not getting proper drinking water. One of the major problems we are facing in our houses and society is the wastage of drinking water. Today, even in our village areas the people are installing the electric water pump which is used to pump the water from the ground and store that water in tanks but in this process sometimes water overflowed from the water tank due to lack of concentration of the person who is responsible for controlling the electric pump. For that stated reason, lots of gallons of water are wasted in a whole day. This project is dealing with IoT-based water level monitoring and controlling system. Our system is IoT-based for that reason anyone can control our system remotely from anywhere in the world. This system can monitor the water level in the water tanks and can control the pump based on the water level with or without any human interactions. Only the person or organization has to set up the whole system at once only for one time and the system will work automatically even without human interactions.

Key Components:

Ultrasonic Sensor: An ultrasonic sensor is used to measure the distance between the sensor and the water surface. This data is then used to calculate the water level.

NodeMCU or ESP8266: The NodeMCU or ESP8266 is used as the microcontroller board to interface with the ultrasonic sensor and connect to the Blynk cloud platform for remote monitoring and control.

Blynk Mobile Application: The Blynk mobile application acts as the user interface for this system. It allows users to view the real-time water level percentage, manually control the water motor, and enable/disable the automatic motor control.

Code Description:

The code starts with defining macros, including Blynk template ID, device name, firmware version, and print settings.

It then defines the pins used for the ultrasonic sensor (trig and echo) and the motor (RelayPin1).

The Blynk library, along with the BlynkTimer library, is included.

The code initializes variables such as tankDepth, manual_Motor, and auto_Motor, which are used to store the water tank depth and the state of manual and automatic motor control, respectively.

There are two Blynk virtual write functions (BLYNK_WRITE) defined for virtual pins V1 and V3. These functions receive data from the Blynk mobile app, updating the manual_Motor and auto_Motor variables accordingly.

The waterLevel function is the main function that measures the water level using the ultrasonic sensor, calculates the percentage, and controls the water motor based on the calculated level and user input.

In the setup function, the pins are initialized, and the Blynk communication is started using BlynkEdgent.begin(). The waterLevel function is also set to run at a regular interval using the Blynk timer.

The loop function calls BlynkEdgent.run() and timer.run() to handle Blynk communications and timers.

Functionality:

The ultrasonic sensor measures the distance between the sensor and the water surface.

The water level is calculated as the difference between the tank depth and the measured distance.

The calculated water level percentage is sent to the Blynk mobile app, where users can see the real-time water level.

Users can manually control the water motor by toggling the virtual pin V1 in the Blynk app. If manual motor control is enabled, the motor turns on.

Users can also enable or disable automatic motor control by toggling the virtual pin V3 in the Blynk app. If automatic control is enabled, the motor operates based on the water level percentage.

The motor is turned off when the water level reaches 80% of the tank capacity to prevent overfilling.
