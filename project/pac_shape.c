#include <shape.h>
#include "./../circleLib/_abCircle.h"
#include "pac_shape.h"
#include <chordVec.h>



//sliced circle function
int pac_man_check(const AbCircle *circle, const Vec2 *centerPos, const Vec2 *pixel){
  Vec2 relPos;
  vec2Sub(&relPos, centerPos, pixel); /* vector from center to pixel, switching places of centerPos and pixel makes cut appear on opposite side, first quadran if centerPos is first. */
  
  
  /* reject pixels in slice */
  if (relPos.axes[0] >= 0 && relPos.axes[0] < relPos.axes[1]) //the division changes pacman apperture, from only one side
    return 0;
  else
    return abCircleCheck(circle, centerPos, pixel);
}
