//
//  main.cpp
//  IN204_Projet
//
//  Created by wangyu980312 on 20/12/2020.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <chrono>
#include <omp.h>

#include "Utils.hpp"

const int Width = 640;
const int Height = 480;
const int kNumPixelSamples = 64; //

const int sample = 400;
// It determines the proportional relationship between spatial distance and pixel pitch.
// The larger its value, the smaller the spatial distance represented by the pixel pitch.

int main(int argc, char *argv[]){
    srand((int)time(NULL));
    std::chrono::time_point<std::chrono::system_clock> start, end;
    
    start = std::chrono::system_clock::now();
    // Define the camera.
    Camera camera = Camera();
    camera.generateCamera(Vector(5.0, 1.5, -5.0), Vector(0.0));
 
    // Define the light source.
    std::vector <Source*> sources;
    Light light (Vector(5.0, 10.0, 5.0), Color(1.0));
    sources.push_back(dynamic_cast<Source*>(&light));

    // Define scene objects.
    std::vector<Object*> objects;
    Sphere sphere1 (Vector(0.0, 1.0, 0.0), 1, Color(1.0, 1.0, 0.0), 0.3);
    Sphere sphere2 (Vector(1.0, 0.5, -2.0), 0.5, Color(0.0, 1.0, 1.0), 0.2);
    Plane plane (0, Vector(0.0, 1.0, 0.0), Color(0.5, 0.25, 0.0), 0.0);
    objects.push_back(dynamic_cast<Object*>(&sphere1));
    objects.push_back(dynamic_cast<Object*>(&sphere2));
    objects.push_back(dynamic_cast<Object*>(&plane));
    
    // Store calculation results.
    Color pixels[Width*Height];
    
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = end-start;
    std::cout << "Temps de Définir la scène: " << elapsed.count() << std::endl;


    start = std::chrono::system_clock::now();
    #pragma omp parallel for
    for (int x = 0; x < Height; ++x)
    {
        for (int y = 0; y < Width; ++y)
        {
            pixels[x*Width+y] = Color(0.0);
            
            // Calculate a random position within the pixel to hide aliasing.
            for(int i = 0; i < kNumPixelSamples; ++i){
                double xPosition = (double)(x - 0.5*Height + rand()/double(RAND_MAX) - 0.5)/(double)sample ;
                double yPosition = (double)(y - 0.5*Width + rand()/double(RAND_MAX) - 0.5)/(double)sample;

                // Generate a corresponding ray according to the position of the pixel
                Ray ray = camera.generateRay(xPosition, yPosition);
                
                // Given a ray, find its intersection with all objects and return it in object order.
                std::vector<double> intersections = findIntersections(ray, objects);

                //  Among all the intersection points, we choose the point closest to the camera and return its index, -1 indicates that there is no intersection with all objects.
                int indexClosest = findIndexClosest(intersections);
                
                if (indexClosest != -1) {
                    // There is an intersection so we get the color of this pixel and store it.
                    pixels[x*Width+y] = pixels[x*Width+y].add(getColor(indexClosest, ray, intersections, objects, sources));
                }
            }
            pixels[x*Width+y] = pixels[x*Width+y].mul(1/(double)kNumPixelSamples);
        }
    }
    end = std::chrono::system_clock::now();
    elapsed = end-start;
    std::cout << "Temps de calcul des pixels: " << elapsed.count() << std::endl;
    
    // Create PPM file
    start = std::chrono::system_clock::now();
    std::ostringstream headerStream;
    headerStream << "P6\n";
    headerStream << Width << ' ' << Height << '\n';
    headerStream << "255\n";
    std::ofstream fileStream("Result.ppm", std::ios::out | std::ios::binary);
    fileStream << headerStream.str();
    unsigned char r, g, b;
    for(int i = 0;i < Width*Height;++i){
        pixels[i].clamp();
        r = static_cast<unsigned char>(pixels[i].getR() * 255.0);
        g = static_cast<unsigned char>(pixels[i].getG() * 255.0);
        b = static_cast<unsigned char>(pixels[i].getB() * 255.0);
        fileStream << r << g << b;
    }
    end = std::chrono::system_clock::now();
    elapsed = end-start;
    std::cout << "Temps de stockage de données: " << elapsed.count() << std::endl;
    
    fileStream.flush();
    fileStream.close();
     
    return 0;
}

