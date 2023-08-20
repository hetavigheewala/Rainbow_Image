

// This program produces a rainbow image
// preprocessor directives
// library includes
#include <iostream>
#include <fstream>

// set namespace
using namespace std;

/// -------------------------------------------------------------------------
/// Main entry-point for this application
///
/// @returns Exit-code for the process - 0 for success, else an error code.
/// -------------------------------------------------------------------------
int main() {
    // Local constant definition(s)
    const string MAGIC = "P3";          // output file magic number
    const int WIDTH = 510 * 3 + 1;      // image width
    const int HEIGHT = 50;              // image height
    const int INTENSITY = 255;          // pixel max intensity
    const string OFN = "rainbow.ppm";   // output file name.

    // Variable declarations(s)
    int exitState;              // tracks the exit code for the process
    exitState = EXIT_SUCCESS;   // set state to successful run

    // file handling variables
    ofstream fout;              // output file handler

    int r;                      // holds red   intensity 0-255
    int g;                      // holds green intensity 0-255
    int b;                      // holds blue  intensity 0-255

    /* ******* Output Phase ********************************************** */
    // open file and write image header
    cout << "This program creates a rainbow ppm image." << endl;

    fout.open(OFN);
    cout << "Writing image " << OFN << "..." << endl;

    fout << MAGIC << endl;                      // write magic number
    fout << WIDTH << ' ' << HEIGHT << endl;     // write size
    fout << INTENSITY << endl;                  // write max intensity

    // Iterate over each pixel
    for (int y = 0; y < HEIGHT; y++) {

        r = 255;
        g = 0;
        b = 0;

        fout << r << " " << g << " " << b << " ";
        // green raises (r = 255, g = 255, b = 0)
        while (g < 255) {
            g++;
            fout << r << " " << g << " " << b << " ";
        }

        // red lowers (r = 0, g = 255, b = 0)
        while (r > 0) {
            r--;
            fout << r << " " << g << " " << b << " ";
        }

        // climb to blue (r = 0, g = 255, b = 255)
        while (b < 255) {
            b++;
            fout << r << " " << g << " " << b << " ";
        }

        // green lowers (r = 0, g = 0, b = 255)
        while (g > 0) {
            g--;
            fout << r << " " << g << " " << b << " ";
        }

        // climb to red (r = 255, g = 0, b = 255)
        while (r < 255) {
            r++;
            fout << r << " " << g << " " << b << " ";
        }

        // blue lowers
        while (b > 0) {
            b--;
            fout << r << " " << g << " " << b << " ";
        }
        // end pixel row
        fout << "\n";
    }

    cout << "Done..." << endl;                  // message user
    cout << "To view the image on linux use: display "
    << OFN << " &\n" << endl;

    return exitState;
}