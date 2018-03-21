#ifndef RPSLOCATIONS
#define RPSLOCATIONS

#include "FEHRPS.h"

#include "Subsystems/DriveTrain.h"
#include "Subsystems/Sensors.h"
#include "Subsystems/Arm.h"

typedef enum {
	Exit_Start, Buttons, Jack_Corner, Wrench_Pickup, Bottom_Ramp, Leave_Garage, Crank, Top_Ramp, NUMBER_OF_LOCATIONS
} LocationName;

typedef enum {
    CourseA, CourseB, CourseC, CourseD, CourseE, CourseF, CourseG, CourseH, NUMBER_OF_COURSES
} Course;

typedef struct position_{
    float x;
    float y;
} Position;

typedef struct {
	LocationName locationName;
	Course courseName;
    Position position;
} Location;

class RPSLocations
{
private:
    Location locations[NUMBER_OF_LOCATIONS * NUMBER_OF_COURSES];

    void addAllCourseLocations();
public:

	RPSLocations();

    void setLocation(LocationName locationName, float x, float y);
    void setLocation(LocationName locationName, Position position);

	float getLocationX(LocationName locationName, Course courseName);
	float getLocationY(LocationName locationName, Course courseName);
    Position getLocationPosition(LocationName locationName, Course courseName);
};

#endif
