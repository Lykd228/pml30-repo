/* Orlov Maxim, 11-5, 04.02.2023 */
#ifndef __shape_h_
#define __shape_h_

#define MAX_SHAPE 10000

class shape
{
public:
  virtual void Draw(void)
  {}
  virtual void Response(double time)
  {}
};

#endif // __shape_h_
