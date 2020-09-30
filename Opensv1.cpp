#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;



int main() {		
		VideoCapture cap(3);		
		
		Mat frame;
		Mat img;

		while (1) {				
							
				// Capture frame-by-frame				
				cap >> frame;			                                 //orig
				// If the frame is empty, break immediately				
				if (frame.empty())					
					break;
				// Display the resulting frame				
				imshow("Frame", frame);
			
				cap >> img;                                             //conturi
				Mat edges;
				cvtColor(img, edges, CV_BGR2GRAY);
				Canny(edges, edges, 30, 60);
				imshow("window label", edges);

				cap >> img;                                             //blur
				Mat blr;
				cvtColor(img, edges, CV_LOAD_IMAGE_COLOR);
				blur(img, blr, Size(10, 10), Point(-1, -1), BORDER_DEFAULT);
				imshow("Blur window",blr);

				cap >> img;                                             //green filtr
				Mat green;
				cvtColor(img, green, COLOR_BGR2HSV);
				inRange(green, Scalar(0, 50, 0), Scalar(255, 100, 255), green);
				imshow("Green window", green);
				
				
				// Press  ESC on keyboard to exit				
				char c = (char)waitKey(25);			
				if (c == 27)					
					break;			
		}
		
		
		cap.release();					
		destroyAllWindows();		
		return 0;
	
}

