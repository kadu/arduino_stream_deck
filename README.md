# StreamDeck BLE

During my firsts lives on twitch, I saw some streamers using cool hardware that with just some clicks on little screens can command all the live scenes, open and close programs, and other things, the name of this tech gadget, Elgato StreamDeck, here in Brazil it is so expensive that made me think how can I do the same without this keyboard, with a quick google search a lot of results are point to Arduino versions, someone more simple, others with OLED screens and almost same functionality that the original.

In my streams, I talk about IoT, Home Automation, Arduino, Electronics, and related things, in this moment I think, why do I not develop my own Stream Deck in my stream? Here we are, this is a result of some nights with friends talking about how cool will be to have a BLE keyboard that controls OBS.

**Let's share!**

The first version that I made fail badly (img1), I've used an Arduino Leonardo to send commands, using only one analog pin. My circuit sometimes sends the wrong value to the computer, and I lost some records because of that. After saw another twitch streamer (https://www.twitch.tv/tearing5) using the ESP32 as a Bluetooth keyboard I have the idea to create a simple node32s shield, with some buttons and RGB Leds (why not?) that send keystrokes to my computer.



-   Here is the schematic that I've created  

![Schematic](assets/schematic.png "Schematic")

-   Here is the board that I made and send to JLCPCB to create my Board

![PCB](assets/pcb01.png "PCB")

![PCB](assets/pcb02.png "PCB")

![PCB](assets/pcb03.png "PCB")

-   And here are the board :D

![Real PCB 01](assets/live01.jpg "Real Life 01")

![Real PCB 02](assets/live02.jpg "Real Life 02")

**Show me "the code"**

The hardware part is a NODE32S as an MCU, and my PCB acting like an Arduino shield over it.

I've used 3 libraries
-   Adafruit NeoPixel - that brings RGB to life!
-   ESP32 BLE Keyboard - abstract all BLE stuff
-   OneButton - help with buttons

You can get the code here

**Configuration**

The "StreamDeck BLE" act as a BLE keyboard and has 9 buttons, each one sends a keystroke to the computer (CTRL+ALT+SHIFT+[LETTER]).

LETTERS:
| Button  | Letter   |
|----|----|
| 01 | Z  |
| 02 | Y  |
| 03 | W  |
| 04 | X  |
| 05 | V  |
| 06 | U  |
| 07 | T  |
| 08 | S  |
| 09 | R  |

**How to USE**

Just connect on "StreamDeckBLE" on your Bluetooth, go to OBS Settings -> Hot Keys, and press each button wherever you want  

**BE HAPPY**

https://oshwlab.com/nicodemosbr/streamdeck_ble

**3D Case**

To create this 3D case I had to win several battles, it was hours and hours fighting with myself and Fusion 360. But I got the help of knights who joined me and helped me build this case. Here is my thanks to @Leo_Churrasqueiro, a brilliant warrior who detached from several moments helping me in the battle, and to @psampaiobh who made excellent Fusion 360 tutorials that served as a tips guide and helped me better understand this 360-head Hydra ;)

And a special thanks to all that guys that were in twitch chat helping us!

We have some pictures of this battle:
![Wireframe](assets/wireframe.png "Wireframe")

![With lid](assets/lado_comtampa.png "With lid")
![Without lid](assets/lado_semtampa.png "Without lid")

and now, the "printed version"

![3d case 01](assets/teclado_frente.png "3D Case")
![3d case 02](assets/Teclado_traseira.png "3D Case")

We decided to have a 18650 battery on it, and for this, we use these components:
- MT3608 - Step UP Conversor
- TP4056 - Single Cell Li-ion battery charger
- Button Switch.

Is possible to use TP4056 with step up on IT, but will need some hack on the printed case.