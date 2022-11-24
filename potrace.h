#ifndef POTRACE_H
#define POTRACE_H

#include "potracelib.h"
#include "auxiliary.h"
#include "trans.h"
#include <vector>

/* structure to hold a dimensioned value */
struct dim_s
{
  double x; /* value */
  double d; /* dimension (in pt), or 0 if not given */
};
typedef struct dim_s dim_t;

#define DIM_IN (72)
#define DIM_CM (72 / 2.54)
#define DIM_MM (72 / 25.4)
#define DIM_PT (1)
#define UNIT 10

/* set some configurable defaults */

#ifdef USE_METRIC
#define DEFAULT_DIM DIM_CM
#define DEFAULT_DIM_NAME "centimeters"
#else
#define DEFAULT_DIM DIM_IN
#define DEFAULT_DIM_NAME "inches"
#endif

#ifdef USE_A4
#define DEFAULT_PAPERWIDTH 595
#define DEFAULT_PAPERHEIGHT 842
#define DEFAULT_PAPERFORMAT "a4"
#else
#define DEFAULT_PAPERWIDTH 612
#define DEFAULT_PAPERHEIGHT 792
#define DEFAULT_PAPERFORMAT "letter"
#endif

/* structure to hold per-image information, set e.g. by calc_dimensions */
struct imginfo_s
{
  int pixwidth;                  /* width of input pixmap */
  int pixheight;                 /* height of input pixmap */
  double width;                  /* desired width of image (in pt or pixels) */
  double height;                 /* desired height of image (in pt or pixels) */
  double lmar, rmar, tmar, bmar; /* requested margins (in pt) */
  trans_t trans;                 /* specify relative position of a tilted rectangle */
};

struct QuantizedValue;

typedef struct imginfo_s imginfo_t;
  char *start(
    uint8_t pixels[],
    int width,
    int height,
    uint8_t transform,
    uint8_t pathonly,
    uint8_t extract_colors,
    uint8_t quantlevel,
    uint8_t posterization_algorithm,
    int turdsize,
    int turnpolicy,
    double alphamax,
    int opticurve,
    double opttolerace
    );

  char* start(
      std::vector<QuantizedValue>& pixels,
      int width,
      int height,
      uint8_t transform,
      uint8_t pathonly,
      int turdsize,
      int turnpolicy,
      double alphamax,
      int opticurve,
      double opttolerace
  );
#endif /* POTRACE_H */
