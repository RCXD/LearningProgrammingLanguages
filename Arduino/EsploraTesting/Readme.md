# Arduino Esplora Testing Projects

## Contents
1. Tst01
2. Tst02
3. Tst03
4. Tst04
5. Tst05
   1. Merged Esplora Examples from [Link](https://www.arduino.cc/en/Tutorial/LibraryExamples/EsploraLedShow/)
   2. How to use
      1. Check the List on the very top: look up the peripherals you would like to use
      2. Next, check the Configuration 1: Peripherals
         1. e.g. If you'd like to use Joystick including mouse control and see its ouputs through **Serial Plotter**,
            1. Uncomment JOYSTICK, MOUSE, PLOTTER (make sure comment MONITOR)
            2. Comment things may duplicate in the future; ex. MONITOR, PLOTER in ACC
         2. Check the setup() and loop()
         3. Check **delay timing cycle in loop()** as you calculated
         4. 