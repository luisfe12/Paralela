// Filename: cimg_1.cpp
// Very basic usage of CImg library
// Thus program reads and displays a color image using CImg

// Starting with include headers and required namespace
#include "CImg.h"
using namespace cimg_library;

// The CImg makes use of only 4 classes:
// 1) cimg_library::CImg
// 2) cimg_library::CImgList
// 3) cimg_library::CImgDisplay
// 4) cimg_library::CImgException

// Out of the above classes for the classes needed for our purpose are CImg
// and CImgDisplay.

int main() {
  // Let's us read the image using CImg class constructor;
  //CImg<unsigned char> image("pintura.jpg");
  // To display the image create an object of CImgDisplay class and pass
  // object of image to be displayed and title of the display window.
  //CImgDisplay dispWindow(image, "gaaaaaaaaa");
  // By default the window is closed after a fraction of second after
  // displaying, so while loop is used to tell the display window to wait until
  // user explicitely closes the same.
  
  CImg<float> image("pintura.jpg"),
  	gray(image.width(), image.height(), 1,1,0);
  //image.normalize(0,1);
  cimg_forXY(image,x,y) {
    //imgR(x,y,0,0) = image(x,y,0,0),    // Red component of image sent to imgR
    //imgG(x,y,0,1) = image(x,y,0,1),    // Green component of image sent to imgG
    //imgB(x,y,0,2) = image(x,y,0,2);    // Blue component of image sent to imgB
 
    // want to print out the RGB value of each pixel? Uncomment the following:
    /*
    * cout << image.width() << "x" << image.height() << endl;
    * cout << "(" << x << "," << y << ") ="
    *             << " R:" << (int)image(x,y,0,0)
    *             << " G:" << (int)image(x,y,0,1)
    *             << " B:" << (int)image(x,y,0,2) << endl;
    */
 
    // Separation of channels
    int R = (int)image(x,y,0,0);
    int G = (int)image(x,y,0,1);
    int B = (int)image(x,y,0,2);
    // Arithmetic addition of channels for gray
    int grayValue = (int)(0.33*R + 0.33*G + 0.33*B);
    // Real weighted addition of channels for gray
    //int grayValueWeight = (int)(0.299*R + 0.587*G + 0.114*B);
    // saving píxel values into image information
    gray(x,y,0,0) = grayValue;
    //grayWeight(x,y,0,0) = grayValueWeight;
}//sacado de https://obsessive-coffee-disorder.com/rgb-to-grayscale-using-cimg/
  gray.quantize(16);
  gray.normalize(0,1);
  gray.threshold(0.5f);
  gray.normalize(0,255);
  CImgDisplay dispWindow(image, "gaaaaaaaaa"),
  	draw_dispGr(gray, "Gray");

  while (!dispWindow.is_closed()) {
    dispWindow.wait();
  }

  return 0;
}
