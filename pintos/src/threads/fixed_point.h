#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

#define F (1 << 14)  //fixed point 1
#define INT_MAX ((1 << 31) - 1)
#define INT_MIN (-(1 << 31))
//x and y denote fixed_point numbers in 17.14 format
//n is an integer

int int_to_fp (int n);
int fp_to_int_round (int x);
int fp_to_int (int x);
int add_fp (int x, int y);
int add_mixed (int x, int n);
int sub_fp (int x, int y);
int sub_mixed (int x, int n);
int mult_fp (int x, int y);
int mult_mixed (int x, int n);
int div_fp (int x, int y);
int div_mixed (int x, int n);

/* change integer to fixed point */
int 
int_to_fp (int n)
{
  return n * F;
}

/* round FP to int */
int
fp_to_int_round (int x)
{
  return (x >= 0) ? (x + F/2)/F : (x - F/2)/F;
}

/* round down FP to int */
int
fp_to_int (int x)
{
  return x / F;
}

/* FP addition */
int
add_fp (int x, int y)
{
  return x + y;
}

/* add FP and int */
int
add_mixed (int x, int n)
{
  return x + n * F;
}

/* subtract b/w FPs */
int 
sub_fp (int x, int y)
{
  return x - y;
}
/* subtract b/w FP and int */
int
sub_mixed (int x, int n)
{
  return x - n * F;
}

/* multiply FPs */
int 
mult_fp (int x, int y)
{
  return ((int64_t) x ) * y / F;
}

/* multiply FP and int */
int 
mult_mixed (int x, int n)
{
  return x * n;
}

/* divide b/w FP  */
int 
div_fp (int x, int y)
{
  return ((int64_t) x) * F / y;
}

/* divide b/w FP and int*/
int 
div_mixed (int x, int n)
{
  return x / n;
}

#endif /* threads/fixed_point.h */
