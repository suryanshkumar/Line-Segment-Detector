# Line_Segment_Detector
C/C++ code for line segment detector (LSD)

Modified by : Suryansh Kumar

If you are using this code you should refer to
[1]. Rafael Grompone von Gioi, Jérémie Jakubowicz, Jean-Michel Morel, and Gregory Randall, LSD: a Line Segment Detector, Image Processing On Line, 2 (2012), pp. 35–55.
Its c code is available at http://www.ipol.im/pub/art/2012/gjmr-lsd/

However, its written in c for .pgm image format. 
Keeping in mind the application of line segment detection in robot vision. I have modified it to use this 
robust algorithm for .jpg format. So, that you can easily integrate with your ROS repository or other 
vision or image processing related codes.   

Compiled and tested on Linux (Ubuntu 13.04, 14.04)
A sample image has been provided to test.

Dependencies : 
1. ghostscript
2. imagemagick
3. opencv

compile command
$ make

run command
$ ./detectLine                
