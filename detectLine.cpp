/***
 * Author : Suryansh Kumar
 * 
 * 
 * LSD Line Segement Detector is modified for .jpg format
 * 
 ***/

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <opencv/cv.h>
#include <opencv/highgui.h>

#define BUF 20
#define COLS 7

using namespace std;
using namespace cv;

/*Read the file containing the coordinates of the line segment*/
/**You can optimise this function **/

Mat file2Mat(char *filename){
 ifstream infile;
 infile.open(filename,ios::in);
 
 if (!infile) {
  cerr << "Can't open input file "<< endl;
  exit(1);
 }
 
 char number[BUF];
 
 int rows=0; int cols=0;
  
 while (!infile.eof()) {
  infile>>number;
  cols++;
  if(cols==COLS){
   rows++;
   cols=0;
   }
 }			
 
 infile.close();	
 ifstream readfile;
 readfile.open(filename, ios::in);
 cout<<rows<<endl;
 
 Mat filemat(rows, COLS, CV_64F,Scalar(0));
 rows = 0; cols = 0;
 char val[BUF];
 
 while (!readfile.eof()) {
  readfile>>val;
  filemat.at<double>(rows,cols)=atof(val);
  cols++;
   if(cols==COLS){
		rows++;
		cols=0;
	 }
   }
 return filemat;						 
}



/*Function to draw the lines*/
void drawLSD(Mat fileData, Mat image){	
 
 for(int i = 0; i<fileData.rows; i++)
 {
  double x1 = fileData.at<double>(i,0); double y1 = fileData.at<double>(i,1);
  double x2 = fileData.at<double>(i,2); double y2 = fileData.at<double>(i,3);
  line(image, Point(x1, y1), Point(x2, y2), Scalar(0, 255, 0), 1.5);
 }
 imshow("Line", image);
 waitKey(0);
}





int main(int argc , char *argv[]){


 string s = "1.pgm";  ///Input .pgm image

 char s1[20] = "-P";
 
 char s2[20] = "image.result.eps";  ///Output .eps image
 
 char *s3 = new char[s.length() + 1];
 
 strcpy(s3, s.c_str());
 char s4[20] = "myfilecurrent.txt"; 
 
 char c1[200] = "gs -sDEVICE=jpeg -dJPEGQ=100 -dNOPAUSE -dBATCH -dSAFER -r300 -sOutputFile=myfilecurrent.jpg image.result.eps";
 
 char c2[200] = "mogrify -trim -resize 640x480 myfilecurrent.jpg";  ///Mogrify the image to fit the desired window size
 
 char command1[200]; char command2[200]; char buffer[200];
 
 
 printf("%s %s %s %s\n", s1, s2, s3, s4);
 
 sprintf(buffer, "./lsd %s %s %s %s",s1, s2, s3, s4);
 
 sprintf(command1, "%s",c1);
 
 sprintf(command2, "%s",c2);
 
 system(buffer);
 
 system(command1);
 
 system(command2);
 
 string sresult = "myfilecurrent.jpg";
 
 Mat lineData = file2Mat(s4);
 
 Mat image = imread(s, 1);
 
 drawLSD(lineData, image);
  
 return 0;
}
