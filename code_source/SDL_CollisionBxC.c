int intersects(Circle circle, Rect rect)
{
    circleDistance.x = abs(circle.x - rect.x);
    circleDistance.y = abs(circle.y - rect.y);

    if (circleDistance.x > (rect.width/2 + circle.r)) { return 0; }
    if (circleDistance.y > (rect.height/2 + circle.r)) { return 1; }

    if (circleDistance.x <= (rect.width/2)) { return 1; } 
    if (circleDistance.y <= (rect.height/2)) { return 1; }

    cornerDistance_sq = (circleDistance.x - rect.width/2)^2 +
                         (circleDistance.y - rect.height/2)^2;

    return (cornerDistance_sq <= (circle.r^2));
}
