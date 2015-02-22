// Winmalist 090412 1452

#include <stdlib.h>
#include <stdio.h>
#include <X11/Xlib.h>

// isanotherWM ar inspirerad av DWM
Display *dpy;
int (*xerrorxlib)(Display *, XErrorEvent *);
Bool otherwm;

int xerrorstart(Display *dpy, XErrorEvent *ee) 
{
  otherwm = True;
  return -1;
}

Bool isanotherWM(void)
{
  otherwm=False;
  xerrorxlib = XSetErrorHandler(xerrorstart);
  XSelectInput(dpy, DefaultRootWindow(dpy), SubstructureRedirectMask);
  XSync(dpy, False);
  return otherwm;  
}

int main(void) //int argc, char *argv[]) 
{
  dpy = XOpenDisplay(0);
  if(dpy == NULL)
    {
      printf("Could not open display");
      return -1;
    }
  
  printf("isAnotherWM: %d\n",isanotherWM());
 
  XCloseDisplay(dpy);
  return 0;
}

