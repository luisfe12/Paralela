
#include "CImg.h"
using namespace cimg_library;
int main() {
    CImg<unsigned char> img("pintura.jpg");
    img.display("Image");
    return 0;
}
