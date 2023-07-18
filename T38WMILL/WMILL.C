#include <stdio.h>
#include <math.h>
#include "wmill.h"

double pi = 3.14159265358979323846;

void LoadTex( char *FileName )
{
  unsigned char *img;
  int w = 0, h = 0;
  FILE *F;

  F = fopen(FileName, "rb");
  if (F == NULL)
    return;

  fread(&w, 2, 1, F);
  fread(&h, 2, 1, F);

  if ((img = malloc(3 * w * h)) == NULL)
  {
    fclose(F);
    return;
  }

  fread(img, 3, w * h, F);

  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  gluBuild2DMipmaps(GL_TEXTURE_2D, 3, w, h, GL_BGR_EXT, GL_UNSIGNED_BYTE, img);
  free(img);
  fclose(F);
}

void Base( double h0, double h1, double s0, double s1 )
{
  glBegin(GL_TRIANGLE_STRIP);
    glNormal3d(0, s0 - s1, h1 - h0);
    glTexCoord2d(0, 0);
    glVertex3d(s0, h0, s0);
    glTexCoord2d(0, 1);
    glVertex3d(-s0, h0, s0);
    glTexCoord2d(1, 0);
    glVertex3d(s1, h1, s1);
    glTexCoord2d(1, 1);
    glVertex3d(-s1, h1, s1);

    glNormal3d(h0 - h1, s0 - s1, 0);
    glTexCoord2d(0, 0);
    glVertex3d(-s1, h1, s1);
    glTexCoord2d(0, 1);
    glVertex3d(-s1, h1, -s1);
    glTexCoord2d(1, 0);
    glVertex3d(-s0, h0, s0);
    glTexCoord2d(1, 1);
    glVertex3d(-s0, h0, -s0);

    glNormal3d(0, s0 - s1, h0 - h1);
    glTexCoord2d(0, 0);
    glVertex3d(-s0, h0, -s0);
    glTexCoord2d(0, 1);
    glVertex3d(s0, h0, -s0);
    glTexCoord2d(1, 0);
    glVertex3d(-s1, h1, -s1);
    glTexCoord2d(1, 1);
    glVertex3d(s1, h1, -s1);

    glNormal3d(h1 - h0, s0 - s1, 0);
    glTexCoord2d(0, 0);
    glVertex3d(s1, h1, -s1);
    glTexCoord2d(0, 1);
    glVertex3d(s1, h1, s1);
    glTexCoord2d(1, 0);
    glVertex3d(s0, h0, -s0);
    glTexCoord2d(1, 1);
    glVertex3d(s0, h0, s0);
  glEnd();

  glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2d(0, 0);
    glVertex3d(s1, h1, s1);
    glTexCoord2d(0, 1);
    glVertex3d(-s1, h1, s1);
    glTexCoord2d(1, 0);
    glVertex3d(s1, h1, -s1);
    glTexCoord2d(1, 1);
    glVertex3d(-s1, h1, -s1);
  glEnd();
}

void Cone( double h0, double h1, double r, int N )
{
  int i;
  glBegin(GL_TRIANGLES);
  for (i = 0; i < N; i++)
  {
    glNormal3d((h1 - h0)*cos(i * 2 * pi / N), r, (h1 - h0)*sin(i * 2 * pi / N));
    glTexCoord2d(0, 0);
    glVertex3d(r*cos(i * 2 * pi / N), h0, r*sin(i * 2 * pi / N));
    glTexCoord2d(0, 1);
    glTexCoord2d(1, 1);
    glVertex3d(0, h1, 0);
    glTexCoord2d(1, 0);
    glVertex3d(r*cos((i + 1) * 2 * pi / N), h0, r*sin((i + 1) * 2 * pi / N));
  }
  glEnd();
}

void Vert( double xc, double yc, double zc, double l, double angle, int N )
{
  int i;

  glTranslated(xc, yc, zc);
  glRotated(angle * 80, 0, 0, 1);
  for (i = 0; i < N; i++)
  {
    glRotated(360/N, 0, 0, 1);
    Cone(-l, 0, 0.7, 20);
  }
}

void Zabor( double h0, double h1, double h2, double r, int N )
{
  int i;

  glBegin(GL_TRIANGLES);
  for (i = 1; i < N; i++)
  {
    glNormal3d(r*cos(i * 2 * pi / N), 0, r*sin(i * 2 * pi / N));

    glTexCoord2d(0, 0);
    glTexCoord2d(0, 1);
    glVertex3d(r*cos(i * 2 * pi / N), h0, r*sin(i * 2 * pi / N));
    glTexCoord2d(1, 0);
    glVertex3d(r*cos(i * 2 * pi / N), h1, r*sin(i * 2 * pi / N));
    glTexCoord2d(1, 1);
    glVertex3d(r*cos((i + 0.5) * 2 * pi / N), h2, r*sin((i + 0.5) * 2 * pi / N));

    glTexCoord2d(0, 0);
    glTexCoord2d(0, 1);
    glVertex3d(r*cos(i * 2 * pi / N), h0, r*sin(i * 2 * pi / N));
    glTexCoord2d(1, 0);
    glVertex3d(r*cos((i + 0.5) * 2 * pi / N), h2, r*sin((i + 0.5) * 2 * pi / N));
    glTexCoord2d(1, 1);
    glVertex3d(r*cos((i + 1) * 2 * pi / N), h1, r*sin((i + 1) * 2 * pi / N));

    glTexCoord2d(0, 0);
    glTexCoord2d(0, 1);
    glVertex3d(r*cos(i * 2 * pi / N), h0, r*sin(i * 2 * pi / N));
    glTexCoord2d(1, 0);
    glVertex3d(r*cos((i + 1) * 2 * pi / N), h1, r*sin((i + 1) * 2 * pi / N));
    glTexCoord2d(1, 1);
    glVertex3d(r*cos((i + 1) * 2 * pi / N), h0, r*sin((i + 1) * 2 * pi / N));
  }
  glEnd();
}

void Cyl( double l, double r, int N )
{
  int i;

  glBegin(GL_TRIANGLES);
  for (i = 0; i < N; i++)
  {
    glNormal3d(cos(i * 2 * pi / N), sin(i * 2 * pi / N), 0);
    glTexCoord2d(0, 0);
    glVertex3d(r*cos(i * 2 * pi / N), r*sin(i * 2 * pi / N), -l / 2);
    glTexCoord2d(0, 1);
    glVertex3d(r*cos(i * 2 * pi / N), r*sin(i * 2 * pi / N), l / 2);
    glTexCoord2d(1, 0);
    glVertex3d(r*cos((i + 1) * 2 * pi / N), r*sin((i + 1) * 2 * pi / N), -l / 2);

    glVertex3d(r*cos((i + 1) * 2 * pi / N), r*sin((i + 1) * 2 * pi / N), -l / 2);
    glTexCoord2d(1, 1);
    glVertex3d(r*cos((i + 1) * 2 * pi / N), r*sin((i + 1) * 2 * pi / N), l / 2);
    glTexCoord2d(0, 0);
    glVertex3d(r*cos(i * 2 * pi / N), r*sin(i * 2 * pi / N), l / 2);
  }
  glEnd();
}

void Dog( double l, double r, double W, int N )
{
  glPushMatrix();
  Cyl(l, r, N);

  glTranslated(-2*r/5, cos(W) * r / 4 - r, -l / 3 + sin(W) * r / 4);
  glRotated(90, 1, 0, 0);
  Cyl(l / 2, r / 4, N);

  glTranslated(3*r/4, 0, 0);
  Cyl(l / 2, r / 4, N);

  glTranslated(0, 3*l/5, 0);
  Cyl(l / 2, r / 4, N);

  glTranslated(-3*r/4, 0, 0);
  Cyl(l / 2, r / 4, N);
  glPopMatrix();
}

void Bird( double l, double W )
{
  int i;

  glPushMatrix();
  glRotated(90, 1, 0, 0);

  for (i = 0; i < 2; i++)
  {
    glPushMatrix();
    glRotated(20*asin(sin(5*W)), 1, 0, 0);
    Base(0, l, 0.5, 0.5);
    glTranslated(0, l, 0);
    glRotated(20*asin(sin(7*W)), 1, 0, 0);
    Base(0, l, 0.5, 0);
    glPopMatrix();
    glScaled(1, -1, 1);
  }
  glPopMatrix();
}

void DrawWindMill( double RotaAngle, double W )
{
  int N = 5, i;
  double h0 = 2, h1 = 13, s0 = 5, s1 = 4, w = 3;

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, TexNames[0]);
  glColor3d(0.5, 0.9, 0.5);
  Base(0, 0, 10 * s0, 10 * s0);
  glDisable(GL_TEXTURE_2D);

  glColor3d(1, 1, 1);

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, TexNames[2]);
  Zabor(0, h1 / 2, h1 / 2 + 5, 18, 20);
  glDisable(GL_TEXTURE_2D);

  glPushMatrix();
  glTranslated(18, 0, 0);
  glRotated(90, 1, 0, 0);
  glRotated(2*(90+180*sin(pi/20)/pi) * asin(sin(1.3*W)) / pi, 0, 0, 1);
  glScaled(0.5, 1, 1);
  glTranslated(18 * sin(pi / 10), 0, 0);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, TexNames[4]);
  Base(0, 0, 18 * sin(pi / 10), 18 * sin(pi / 10));
  glDisable(GL_TEXTURE_2D);
  glPopMatrix();

  for (i = 0; i < 5; i++)
  {
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glRotated(70 * W + i*360/5, 0, 1, 0);
    glTranslated(10, 2.5, 0);
    glBindTexture(GL_TEXTURE_2D, TexNames[5]);
    Dog(2, 1, 12 * W, 20);
    glTranslated(10, 10, 0);
    glRotated(90, 0, 1, 0);
    glBindTexture(GL_TEXTURE_2D, TexNames[4]);
    Bird(3, W);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
  }

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, TexNames[1]);
  Base(0, h0, s1, s1);
  glDisable(GL_TEXTURE_2D);

  glRotated(RotaAngle, 0, 1, 0);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, TexNames[3]);
  Base(h0, h1, s0, s1);
  glDisable(GL_TEXTURE_2D);
  
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, TexNames[0]);
  Cone(h1, 1.5 * h1, 1.5 * s1, 20);
  glDisable(GL_TEXTURE_2D);

  glColor3d(0.8, 0, 0);
  glLineWidth(w);
  glBegin(GL_LINES);
    glVertex3d(0, h1, 0);
    glVertex3d(0, h1, 1.3 * s0);
  glEnd();

  glEnable(GL_TEXTURE_2D);
  glColor3d(1, 0.9, 0.8);
  glBindTexture(GL_TEXTURE_2D, TexNames[4]);
  Vert(0, h1, 1.3 * s0, h1 / 2, W, N);
  glDisable(GL_TEXTURE_2D);
}
