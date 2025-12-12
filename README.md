# ESP32 Web-Controlled LED System

## Project Overview
Leveraging C++ microcontroller programming skills, I built this ESP32 project to gain experience with IoT (Internet of Things) and expand my skillset. This web-controlled LED system allowed me to apply HTML, CSS, and JavaScript programming alongside embedded C++ development.

This project transforms an ESP32 microcontroller into a standalone web-controlled LED device. It hosts its own Wi-Fi access point, serves an HTML/CSS/JavaScript interface, and uses WebSockets for real-time communication to toggle an LED connected to a GPIO pin.

Through this project, I developed skills in network programming, asynchronous communication protocols, embedded web server implementation, responsive UI design, client-server architecture, and security considerations for IoT devices.
## Demo Vid
[![Watch the video](https://i.ytimg.com/vi/MtGsBnDhFA8/hqdefault.jpg)](https://youtu.be/MtGsBnDhFA8)

### [Watch this video on YouTube](https://youtu.be/MtGsBnDhFA8)

## Date Completed
January 2024

## Languages, Libraries & Frameworks
- **C++** (Arduino framework)
- **Arduino core for ESP32**
- **ESPAsyncWebServer** for non-blocking HTTP handling
- **WebSocketsServer** for lightweight real-time communications
- **Vanilla JavaScript/WebSocket API** in browser
- **Plain CSS** for styling (no external CSS frameworks)

## Lines of Code: 197
- Arduino sketch (setup, loop, Wi-Fi & WebSocket logic): ~100 LOC
- Embedded HTML/CSS/JS (index.h): ~97 LOC

## Hardware Components Used
- ESP32 development board
- Single LED wired to GPIO 4 (with 100 ohm current-limiting resistor)
- USB cable for power & serial debug
- Client device (phone/PC) connecting via Wi-Fi to ESP32 AP

## Challenges Overcome
- Hosting a captive Wi-Fi AP and serving pages simultaneously
- Embedding multi-line HTML/CSS/JS into flash via `R"=====(…)====="`
- Ensuring WebSocket messages reliably toggle hardware state
- Preventing repeated toggles by comparing with `prevState`
- Coordinating asynchronous callbacks without blocking the main loop
- Dealing with Wi-Fi signal strength variability
- Managing memory constraints when serving web content
- Implementing secure authentication for the web interface
- Cross-browser compatibility for the web control interface
- Handling multiple client connections simultaneously
- Implementing error handling and recovery mechanisms
- Creating responsive design for various screen sizes
- Reducing latency in WebSocket communication with simple data transmission

## Skills Demonstrated
- Embedded C++ for microcontroller networking
- Asynchronous server design with ESPAsyncWebServer
- Real-time communication using WebSockets
- Front-end UI creation in pure HTML/CSS/JS
- State management and event-driven programming
- Debugging over serial and handling binary/text payloads
- Bridging hardware control with modern web interfaces
- IoT device configuration and management
- Wi-Fi access point (AP) mode setup and configuration
- Station mode implementation for connecting to existing networks
- Switching between station modes programmatically
- Network credential management and persistence
- Client-server architecture implementation
- Hardware-software integration for connected devices
- Low-level GPIO programming and control
- Optimizing for limited resources in embedded environments
- Web protocol implementation (HTTP, WebSockets)
