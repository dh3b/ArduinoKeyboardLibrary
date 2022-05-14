
# Arduino Keyboard library

#### About the project
The library can be used for variety of projects including stream deck or
an arduino hacking device (if you wish so).

#### Installation
The installation of library takes a few steps, so let's get to work. Shall we?

**1.** Create an arduino project in Arduino IDE (this step is the easiest one).

**2.** Open the directory from the menu or using the shortcut `ctrl + K`. After that copy `Characters.h` and `KeyboardLibrary.h` directly into folder next to `.ino` file.

**3.** Write an example project in the `ino.` file. You can use the one that I coded earlier.
```c
#include "KeyboardLibrary.h"

char firstSegment[] = "notepad.exe";
char secondSegment[] = "hello";

void setup() {
  Serial.begin(9600);

  winKey();
  key(R, true);
  delay(1000);

  keyString(firstSegment);
  key(ENTER, true);
  delay(2000);
  keyString(secondSegment);
}

void loop() {}
```
This should open the windows "run" window, open notepad and type "hello" into it. However it is reccomended for you to change the delay value according to your pc speed.

**4.** Upload the code to arduino

**5.** Now let's get to the more "difficult" part. First thing that you should do, is downloading [flip software](https://www.microchip.com/en-us/development-tool/flip). This will allow you to "change" the arduino into a keybaord device.

**6.** In the flip software from device selection pick `ATmega16U2`
![image 1](https://i.imgur.com/Oez1vri.png)

**7.** Make sure your arduino is plugged in and connect pins like so to put it into DFU mode (disconnect the pins right after the arduino flashes led)
![image 2](https://i.imgur.com/BH90ilo.png)

**8.** __Don't replug arduino__. In the flip software from the communication medium selection choose USB
![image 3](https://i.imgur.com/dEYQiCS.png)

**9.** Download `Arduino-usbserial-uno.hex` and `Arduino-keyboard-0.3.hex` from the repository

**10.** In the flip software click on `File > Load hex file` and browse for `Arduino-keyboard-0.3.hex`

**11.** After the file is loaded click run
![image 4](https://i.imgur.com/R8obaqD.png)

**12.** Replug your arduino and voilà!

### Okay my Arduino is a keyboard now, but how can I get it back!?

Follow the exact steps as before starting at step #7, but instead loading `Arduino-keyboard-0.3.hex`, load `Arduino-usbserial-uno.hex` and replug the arduino

### Functions in the library

| Function| Requirements     |
| :--------: | :-------: |
| `key`      | int, bool |

 This function can press a specified key, for example `key(R, true)` or `key(SPACE, true)`,
 the bool value specifies if the key should be let out right after it has been pressed. If you set it to `false` the key will remain presssed.

 | Function| Requirements     |
| :--------: | :-------: |
| `releaseKey`      | None |

Releases every key that has been pressed before

| Function| Requirements     |
| :--------: | :-------: |
| `shiftKey`      | None |

Presses the shift key (it will remain pressed until you wont use `key(<key>, true)` or `releaseKey()`

| Function| Requirements     |
| :--------: | :-------: |
| `ctrlKey`      | None |

Presses the control key (it will remain pressed until you wont use `key(<key>, true)` or `releaseKey()`

| Function| Requirements     |
| :--------: | :-------: |
| `winKey`      | None |

Presses the windows or meta key (it will remain pressed until you wont use `key(<key>, true)` or `releaseKey()`

| Function| Requirements     |
| :--------: | :-------: |
| `keyList`      | char, int |

Can type out sentences that are defined inside a list (`char[]`) the int has to be defined with the quantity of characters inside the list eg.
```
char List[] = [H, E, Y, DOT];
keyList(List, 4);
```
will print out `hey.`

| Function| Requirements     |
| :--------: | :-------: |
| `keyString`      | char |

That's the easiest function for now, it can print out whole sentences in a string eg.
```
char string[] = "hello, how are you?";
keyString(string);
```
will print out exactly `hello, how are you?`

### Rest of the information

You can view every character in `Characters.h`, also feel free to modify the library according to your needs.


