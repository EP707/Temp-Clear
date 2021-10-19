# Temp-Clear

## Introduction:

### For Windows Users Only!

* A simple and small c++ program for Windows Systems that will clear all the temporary/junk files and folders!

* This will massively increase HDD/SSD storage space by deleting all of your temp files in one click!

* Some softwares like CCLeaner, Avast Cleaner, BitBleach etc.. does not have option to delete temp files under 'C:\Users\username\AppData\Local\Temp' for some reason. With this small program you can, it is actually very handy hence i use it on every startup.

* You don't go to the folder manually and delete files on your own. This Program will delete all temp/junk files,folders by just one click.

* This will delete temp files in this following locations.

     (1). **C:\Users\username\AppData\Local\Temp**.

     (2). **C:\Windows\Temp**.

     (3). **C:\Windows\SoftwareDistribution**.

* Addtionally this program will stop windows update, This will save your data if you are using mobile hotspot. This program also starts Disk Cleanup to delete more junk files.

Note: You need to compile this program only once on your own!!

<br>

## Requirements:

* <a href="https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download">MinGW </a>Required for compiling this program.

* To install MinGW refer this <a href="https://code.visualstudio.com/docs/languages/cpp#_example-install-mingwx64">link</a>.

* Thats All!

<br>

## How to Run:

After Installing MinGW and Adding it to your systems environment variables, 

* Open Your Terminal Window And Type `git clone https://github.com/EP707/Temp-Clear.git`.

* Type `cd Temp-Clear/`.

* Type `g++ tempclear.cpp -o Clear.exe`. You can type whatever name you want in 'Clear.exe'.

* Then Type `./Clear.exe` to clear temp files on your machine.

<br>

***Disclaimer*** - This will delete all of your temp files! Some files that are in process or use will not be deleted, So don't be scared :)!! 

<br>

## Credits:

I Found this program in <a href="https://forums.codeguru.com/showthread.php?290662-How-to-clear-Temp-folder"> this forum</a>.

* First of all, credits to the creater!!

* I added some modifications in that program to work efficiently and perfectly for our windows systems!

<br>

## Thank You!!
