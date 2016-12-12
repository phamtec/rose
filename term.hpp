/*
 * TERM
 * 
 * Interface to the terminal.
 * 
 * Author: Paul Hamilton
 * Date: 12 Dec 2016
 * 
 */
#ifndef H_TERM
#define H_TERM

class TERM {
public:
 
  void init();
  int waitForInput(unsigned long time);

private:
};

#endif // H_TERM
