#include "RPSLocations.h"
#include <FEHUtility.h>

Position positionsForA[NUMBER_OF_LOCATIONS] = {
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f}
};
Position positionsForB[NUMBER_OF_LOCATIONS] = {
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f}
};
Position positionsForC[NUMBER_OF_LOCATIONS] = {
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f}
};
Position positionsForD[NUMBER_OF_LOCATIONS] = {
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f}
};
Position positionsForE[NUMBER_OF_LOCATIONS] = {
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f}
};
Position positionsForF[NUMBER_OF_LOCATIONS] = {
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f}
};
Position positionsForG[NUMBER_OF_LOCATIONS] = {
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f}
};
Position positionsForH[NUMBER_OF_LOCATIONS] = {
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f},
    {1.2f, 2.3f}
};

Position *allPositions[NUMBER_OF_COURSES] = {
    positionsForA,
    positionsForB,
    positionsForC,
    positionsForD,
    positionsForE,
    positionsForF,
    positionsForG,
    positionsForH,
};

RPSLocations::RPSLocations()
{
    //    addCourseALocations();
    //    addCourseBLocations();
    //    addCourseCLocations();
    //    addCourseDLocations();
    //    addCourseELocations();
    //    addCourseFLocations();
    //    addCourseGLocations();
    //    addCourseHLocations();
}

void RPSLocations::addAllCourseLocations(){
    for(int i = 0; i < NUMBER_OF_COURSES; i++){
        Course currentCourse = static_cast<Course>(i);
        for(int j = 0; j < NUMBER_OF_LOCATIONS; j++){
            LocationName currentLocationName = static_cast<LocationName>(j);
            Position currentPosition = *(allPositions[i] + j);

            Location currentLocation;
            currentLocation.courseName = currentCourse;
            currentLocation.locationName = currentLocationName;
            currentLocation.position = currentPosition;
            locations[i * NUMBER_OF_COURSES + j] = currentLocation;
        }
    }
}

void RPSLocations::setLocation(LocationName locationName, float x, float y){
    Position position = {x, y};
    setLocation(locationName, position);
}

void RPSLocations::setLocation(LocationName locationName, Position position){
    int courseIndex = RPS.CurrentRegion();
    Course currentCourse = static_cast<Course>(courseIndex);

    Location currentLocation;
    currentLocation.courseName = currentCourse;
    currentLocation.locationName = locationName;
    currentLocation.position = position;

    int locationIndex = static_cast<int>(locationName);
    locations[courseIndex * NUMBER_OF_COURSES + locationIndex] = currentLocation;
}

float RPSLocations::getLocationX(LocationName locationName, Course courseName) {
    int courseIndex = static_cast<int>(courseName);
    int locationIndex = static_cast<int>(locationName);

    return locations[courseIndex * NUMBER_OF_COURSES + locationIndex].position.x;
}

float RPSLocations::getLocationY(LocationName locationName, Course courseName) {
    int courseIndex = static_cast<int>(courseName);
    int locationIndex = static_cast<int>(locationName);

    return locations[courseIndex * NUMBER_OF_COURSES + locationIndex].position.x;
}

Position RPSLocations::getLocationPosition(LocationName locationName, Course courseName) {
    int courseIndex = static_cast<int>(courseName);
    int locationIndex = static_cast<int>(locationName);

    return locations[courseIndex * NUMBER_OF_COURSES + locationIndex].position;
}
