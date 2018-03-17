#ifndef RPSLOCATIONS
#define RPSLOCATIONS

#include "Subsystems/DriveTrain.h"
#include "Subsystems/Sensors.h"
#include "Subsystems/Arm.h"

typedef enum {
	Exit_Start, Buttons, Jack_Corner, Wrench_Pickup, Bottom_Ramp, Leave_Garage, Crank, Top_Ramp, NUMBER_OF_LOCATIONS
} LocationName;

typedef enum {
    CourseA, CourseB, CourseC, CourseD, CourseE, CourseF, CourseG, CourseH
} Course;

typedef struct {
	LocationName locationName;
	Course courseName;
	float x;
	float y;
} Location;


class RPSLocations
{
private:
	Location locations[NUMBER_OF_LOCATIONS * 8];
public:

	RPSLocations();

	float getLocationX(LocationName locationName, Course courseName);
	float getLocationY(LocationName locationName, Course courseName);
};

#endif
