<br />
<div align="center">
<h3 align="center">Bad USB</h3>
<p>Author: Walid Loutfi</p>
</div>

<!-- ABOUT THE PROJECT -->

## About this project
I have build a small device that looks like a normal USB, but is actually a powerful tool for executing malicious commands on a target computer. This project is built to use on an Arduino Pro Micro board.

The goal of the project is to use the Rubber Ducky USB to gain a reverse shell on a MacBook. This is accomplished by programming the device to mimic a keyboard and execute a series of pre-written commands that exploit vulnerabilities in the target system's security. Once the device is plugged into the MacBook, it will automatically run the pre-written script, allowing the attacker to gain remote access to the system. 

This project is specifically designed for an Azerty keyboard's key mapping. To change the keyboard layout, navigate to Arduino/libraries/Keyboard/src/Keyboard.h and change the parameter in the *void begin()* to the desired keyboard layout:
```console
class Keyboard_ : public Print
{
private:
    KeyReport _keyReport;
    const uint8_t *_asciimap;
    void sendReport(KeyReport* keys);
public:
    Keyboard_(void);
    //void begin(const uint8_t *layout = KeyboardLayout_da_DK);
    *void begin(const uint8_t *layout = KeyboardLayout_be_BE);*
    void end(void);
    size_t write(uint8_t k);
    size_t write(const uint8_t *buffer, size_t size);
    size_t press(uint8_t k);
    size_t release(uint8_t k);
    void releaseAll(void);
};
```

### Built With
* [C++](https://en.cppreference.com/w/)

<!-- GETTING STARTED -->
## Getting Started

To get a local copy up and running follow these simple steps.

### Prerequisites
* Arduino Pro micro/ Arduino Leonardo

### Installation
1. Clone the repository with the following command:
   ```console
   git clone https://github.com/walid-loutfi/bad-usb.git
   ```
   
2. Open the script in the Arduino IDE or any other IDE capable of running Arduino code.

3. In the IDE, select "Arduino Leonardo" as the board to use.

<!-- LICENSE -->
## LICENSE
This project is licensed under the MIT License - see the LICENSE file for details.