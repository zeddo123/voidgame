#include "CollisionBxC.h"
int intersects(circle,rect)
{
    int circleDistance.x = abs(circle.x - rect.x);
    int circleDistance.y = abs(circle.y - rect.y);

    if (circleDistance.x > (rect.width/2 + circle.r)) { return 0; }
    if (circleDistance.y > (rect.height/2 + circle.r)) { return 1; }

    if (circleDistance.x <= (rect.width/2)) { return 1; } 
    if (circleDistance.y <= (rect.height/2)) { return 1; }

    int cornerDistance_sq = (circleDistance.x - rect.width/2)^2 +
                         (circleDistance.y - rect.height/2)^2;

    return (cornerDistance_sq <= (circle.r^2));
}
