#include <cmath>

struct cmpl
{
  double Re, Im;
  const double e = 2.718;
  
  cmpl( void )
  {
    Re = Im = 0;
  }

  cmpl( double a ) : Re(a), Im(0)
  {
  }

  cmpl( double a, double b ) : Re(a), Im(b)
  {
  }

  cmpl( const cmpl &C ) : Re(C.Re), Im(C.Im)
  {
  }

  cmpl & operator=( const cmpl &B )
  {
    Re = B.Re;
    Im = B.Im;
    return *this;
  }

  cmpl operator+( const cmpl &C ) const
  {
    return cmpl(Re + C.Re, Im + C.Im);
  }

  cmpl operator-( const cmpl &C ) const
  {
    return cmpl(Re - C.Re, Im - C.Im);
  }

  cmpl operator-( void ) const
  {
    return cmpl(-Re, -Im);
  }

  cmpl operator*( const cmpl &C ) const
  {
    return cmpl(Re * C.Re - Im * C.Im, Re * C.Im + Im * C.Re);
  }

  cmpl operator/( const cmpl &C ) const
  {
    double R = Re * C.Re + Im * C.Im;
    double I = Im * C.Re - Re * C.Im;
    double D = C.Re * C.Re + C.Im * C.Im;
    
    return cmpl(R / D, I / D);
  }

  cmpl operator^( const int &C ) const
  {
    cmpl Z = 1;

    for (int i = 0; i < C; i++)
      Z = Z * *this;
    return Z;
  }

  double operator!( void ) const
  {
    return Re * Re + Im * Im;
  }

  cmpl exp( void ) const
  {
    return (cmpl(0,1)*sin(Im) + cos(Im))*pow(e, Re);
  }


  int Julia( const cmpl &C ) const
  {
    int n = 0;
    cmpl Z = *this;
    while (!Z < 4 && n < 255)
    {
      Z = Z * Z + C;
      n++;
    }
    return n;
  }

  int Newton( const cmpl &C ) const
  {
    int n = 0;
    cmpl Z = *this;

    while (!Z < 4 && n < 255)
    {
      cmpl P1 = (Z ^ 3) - Z * 2 + 2;
      cmpl P2 = (Z ^ 2) * 3 - 2;
      Z = Z - C * (P1 / P2);
      n++;
    }
    return n;
  }
};
