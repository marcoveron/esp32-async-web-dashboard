# ESP32 Web Server & Remote hardware control 

A lightweight, asynchronous web server running on an ESP32 to control a RGB Led. 

## 🤕 Problem Solving 

* **RTOS Initialization Sequence:** Structured the exact boot sequence to establish WiFi connectivity *before* allocating server queues, preventing fatal semaphore errors.

* **Hardware Timers vs. GPIO Controllers:** Resolved conflicts between the ESP32's internal PWM Timers `analogWrite` and standard digital logic `digitalWrite`, ensuring clean state transitions for the connected peripherals.

## 💻 Tech Stack

### Software
* **Language:** C++ (Arduino Framework)
* **Frontend:** HTML, CSS
* **Libraries:** `WiFi.h`, `WebServer.h`

### Hardware
* **Microcontroller:** ESP32 (NodeMCU-32S)
* **Output Peripheral:** 1x RGB LED (Common Cathode)
* **Prototyping:** 1x Breadboard, Jumper Wires

## 🚀 How to Run

1. Clone this repository.
2. Update the `ssid` and `password` variables with your network credentials.
3. Flash to your ESP32.
4. Open the Serial Monitor (9600 baud) to get the assigned local IP.
5. Enter the IP in any web browser connected to the same network.