/*********************************************************************
 *  CMPSC 457 Section 001                                            *
 *  Template code for Homework 1                                     *
 *  August 30, 2021                                                  *
 *  YOUR NAME                                                        *
 *  YOUR ACCESS ID                                                   *
 *********************************************************************/  

/*********************************************************************
 *                                                                   *
 *                                                                   *
 *     Put your answer to the written part of assignment here        *
 *                                                                   *
 *                                                                   *
 *********************************************************************/



//////////////////     YOUR PROGRAM GOES HERE    /////////////////////

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

struct RGB {
		float r;
		float g;
		float b;
};		

int main(int argc, char** argv){
		// retrieve height and width from argumensts and convert them to type int
		
		int height = atoi(argv[1]), width = atoi(argv[2]);
		//char* cheight = argv[1];
	        //char* cwidth = argv[2];
		//creatte an output file stream
	
		std::ofstream file;
		
		//retrieve the `
		file.open(argv[3]);

		file << "P3" << "\r\n";
		file << width << " " << height << "\r\n" << "255" << "\r\n";

			
		struct RGB **raster =  new RGB*[width];
		
		for(int i = 0; i < width; i++)
				raster[i] = new RGB[height];
		
				
		for(int h = 0; h < height; h++){
				for(int w = 0; w < width; w++){
						int col = ((w & 0x08) == 0) ^ ((h & 0x08) == 0);
						raster[h][w].r = 255 * static_cast<float>(col);
						raster[h][w].g = 255 * static_cast<float>(col & 0x00);
						raster[h][w].b = 255 * static_cast<float>(col & 0x11);
						
						file << raster[h][w].r << " " << raster[h][w].g << " " << raster[h][w].b << " "; 
				}
				file << "\r\n";
		}


		
		return 0;
}
