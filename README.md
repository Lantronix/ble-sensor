# BLE Heart Rate monitor gateway

## Summary
This is a software module for use with the Lantronix xPico 250 SDK. The software
will scan for BLE heart rate sensors. When it detects them, it will connect to
them, receive the data, and display it on the xPico's local webserver.

For more details, please see the Application Note:
https://www.lantronix.com/blog/bluetooth-connectivity-iot-applications/

## How to Use

* Copy the source code from this application into the custom/module directory
of the xPico 200 SDK installation. The module should be in a
directory called bleSensor.
* Create a project in custom/project
* Ensure that the modules.make file in your project directory includes the
bleSensor module
* Build the project
* Update firmware on xPico 250 with the firmware just created
* Create the http directory in the xPico 250 filesystem
* Upload the files from the http directory in the source package to the http
directory. Make sure to create the /http/js directory for the appropriate
files
* Power on a heart rate monitor
* Access the display with your browser, at: http://ip.address.of.device/bleSensor.html
