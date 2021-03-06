//
//  Utils.cpp
//  IN204_Projet
//
//  Created by wangyu980312 on 20/12/2020.
//

#include "Utils.hpp"

std::vector<double> findIntersections(Ray ray, std::vector<Object*> objects)
{
    std::vector<double> intersections;
    for (int index = 0; index < objects.size(); index++){
        intersections.push_back(objects[index]->findIntersection(ray));
    }
    return intersections;
}

int findIndexClosest(std::vector<double> intersections)
{
    int index = -1;
    double min = DBL_MAX;
    for (int i = 0; i < intersections.size(); i++){
        if (intersections[i] > 0 && min > intersections[i]) {
            min = intersections[i];
            index = i;
        }
    }
    return index;
}

Color getColor(int indexClosest, Ray ray, std::vector<double> intersections, std::vector<Object*> objects, std::vector<Source*> sources)
{
    // Calculate some corresponding variables to facilitate subsequent calculations.
    Vector intersectionPsosition = ray.getOrigin().add( ray.getDirection().mul(intersections[indexClosest]));
    Color colorClosest = objects[indexClosest]->getColor();
    Vector normalClosest = objects[indexClosest]->getNormalAt(intersectionPsosition);
    
    // The basic color affected by the ambient light (mainly due to the diffuse reflection of other objects).
    // If it is a shaded area, this will be its final color.
    Color finalColor = colorClosest.mul(0.2);

    for(int i = 0; i < sources.size(); ++i){
        Vector lightDirection = sources[i]->getPosition().add(intersectionPsosition.negative()).normalize();
        float angle = normalClosest.dot(lightDirection);

        if(angle > 0){
            // If there is no other object blocking, the light source can directly illuminate this point.
            // Now we detect if there are other objects blocking (test for shadows).
            bool shadow = false;
            
            Vector toLight = sources[i]->getPosition().add(intersectionPsosition.negative());
            float distance = toLight.length();
            Ray shadowRay(intersectionPsosition, toLight.normalize());
            
            double SecondIntersections;
            for (int j = 0; j < objects.size() && shadow == false; ++j){
                SecondIntersections = objects[j]->findIntersection(shadowRay);
                if (SecondIntersections > 0.000001 && SecondIntersections <= distance){
                    // There is an object blocking it, it belongs to the shadow area,
                    shadow = true;
                    break;
                }
            }
            
            if(shadow == false){
                // It does not belong to the shadow area, so increase the influence of diffuse reflection (it is affected by the angle of light).
                finalColor = finalColor.add(colorClosest.modulate(sources[i]->getColor()).mul(angle));
                
                double reflect = objects[indexClosest]->getReflect();
                if (reflect > 0 && reflect <= 1){
                    // The surface has reflectiveness, so we need add the specular map.
                    // The specular map is used to express the surface properties of the model when light hits the surface of the model.
                    // For example, metal and skin, cloth, and plastic reflect different amounts of light, thus reflecting their different materials.
                    Vector intersectingRayDirection = ray.getDirection();
                    Vector reflectionDirection = intersectingRayDirection.negative().add(normalClosest.mul(normalClosest.dot(intersectingRayDirection.negative())).add(intersectingRayDirection).mul(2)).normalize();
                    
                    double specular = reflectionDirection.dot(lightDirection);
                    if (specular > 0){
                        specular = pow(specular, 10);
                        finalColor = finalColor.add(sources[i]->getColor().mul(specular*reflect));
                    }
                }
            }
        }
    }

    return finalColor;
}
