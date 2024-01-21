# Smart Home Guardian: Arduino Project <br>

## Summary <br>
Our project introduces a smart device that keeps a constant watch on your building or house to prevent fire risks. It checks important factors like temperature, humidity, CO2, CO3, and alcohol levels in rooms or specific areas. With this simple yet powerful technology, we aim to enhance safety and provide an effective way to avoid potential fire hazards.<br>

## Associated devices<br>
The power of Arduino microprocessors were used alongside an array of other essential components. This system comprises a master device, referred to as the parent device, and a set of child devices strategically deployed to monitor specific areas.<br>

## Functionality<br>
The implemented child devices operate seamlessly, providing continuous monitoring of environmental factors such as temperature, humidity, CO2 levels, CO3 levels, and alcohol levels in specific areas. These devices independently process the gathered data and transmit the results to the parent device for a comprehensive overview.<br>

Each room device (child device) is equipped with the capability to autonomously represent its data. In case of unfavorable environmental conditions, an intuitive visual cue is triggered—LEDs shift from green to red, signaling an issue. Simultaneously, the pertinent data is transmitted to the parent device for further analysis.<br>

The parent device has  a user-friendly LCD display that shows  detailed insights into the status of each room or child device. Upon receiving a signal indicating an anomaly, the LCD promptly highlights the specific issue next to the corresponding room number. To enhance awareness, a buzzer is activated, ensuring immediate notification of potential hazards. <br>



## Communication Establishment (SPI).
In here, these devices communicate with each other wirelessly using NRF24L01 modules, which operate in the 2.4 GHz ISM band, offering a choice of data rates (250 kbps, 1 Mbps, 2 Mbps) and channels (125 in total). This is very helpful when we build such a project like this because we can have many child devices assigned which gives the ability to monitor more spaces. These modules have adjustable output power, affecting range and power consumption, and support packet sizes from 1 to 32 bytes. Utilizing addresses (3-5 bytes), the modules can communicate distinctively in a network.
The core of programming these modules is the RF24 library, which simplifies module initialization, buffer and address management, and power level adjustments. This library also handles the switching between transmitter and receiver modes, essential for bidirectional communication. It features Dynamic Payloads for flexible data lengths and an Auto-Acknowledge system, ensuring reliable data transfer by confirming packet receipt.
The main reason that we selected NRF24L01 specifically because it has some advanced features such as Enhanced ShockBurst™ for automated packet handling and retransmission, plus a 'Multiceiver' capability which is known as trans receiver. This allowing one device to communicate with up to six others at the same time. The choice between models with and without an external antenna offers a balance between range and compactness. However, using these modules requires careful consideration of interference, as they share the 2.4 GHz band with many common devices like Wi-Fi and Bluetooth. Selecting the appropriate channel and data rate is crucial to minimize this interference. Additionally, programming robust error handling and potentially designing a simple networking protocol can significantly enhance communication reliability and efficiency in complex projects like this when we implement this to monitor hundreds of spaces at the same time.<br>
 
## Components we used :<br>
·   	Microprocessor : ATmega 328p (Atmel) single-chip micro controller.<br>
    -This is an ideal single-chip microcontroller for a project like this since this  8-bit AVR microcontroller is a robust, RISC-based processor featuring 32 KB ISP flash memory with unique read-while-write capabilities, complemented by 1 KB EEPROM and 2 KB SRAM for storage. It boasts 23 general-purpose I/O lines and 32 working registers for versatile functionality. The device is equipped with 3 flexible timers/counters, internal and external interrupts, and a serial programmable USART for comprehensive communication options. It also includes a byte-oriented 2-wire serial interface, an SPI serial port, and a 6-channel (expandable to 8 in certain packages) 10-bit A/D converter for enhanced data handling. Additional features include a programmable watchdog timer with an internal oscillator for system reliability and five power-saving modes for efficient operation. Operating on a voltage range from 1.8 to 5.5 volts, this microcontroller achieves efficient throughput, nearing 1 MIPS per MHz, making it highly suitable for a variety of electronic applications like this.<br>
 
·   	Communication: NRF24L01<br>
·   	Display : LCD 2004 (We used with I2C)<br>
·   	Sensors :<br>

&emsp; &emsp; -Temperature & Humidity : DH-11<br>
&emsp; &emsp; -Harmful gas detection : MQ-2. This an analog Smoke/LPG/CO Gas Sensor module utilizes an MQ-2 as the sensitive component and has a protection resistor and an adjustable resistor on board. The MQ-2 gas sensor is sensitive to LPG, i-butane, propane, methane, alcohol, Hydrogen and smoke. It could be used in gas leakage detecting equipments in family and industry. The resistance of the sensitive component changes as the concentration of the target gas changes.<br>
&emsp; &emsp; -Alcohol & Air Quality Detection : MQ-135 air quality sensor is extremely sensitive to ammonia, sulfide, bernze, smoke, and other harmful gas. The resistance of the sensitive component changes as the concentration of the gas changes making it ideal for air quality control applications. The tested concentration range from 10 to 1000ppm<br>
&emsp; &emsp; -LED : Basic RGB LED for pulses.<br>

**Authors**<br>
Chasindu Kumarasiri <br>
Hulya Yasar <br>
Maureen Rahman <br>
Fengyu Yang<br>
Saraphtha Sasikumar <br>
<br>
