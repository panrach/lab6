#include <stdio.h>
#include "point.h"

// writing binary
ssize_t save_points(const char *pathname, const point *a, size_t n) {
  FILE *f = fopen(pathname, "w");

  if (f == NULL) {
    fprintf(stderr, "Error opening file\n");
    return -1;
  }

  size_t output = fwrite(a , sizeof(a[0]), n, f);
  fclose(f);

  return output;
}

// reading binary
ssize_t load_points(const char *pathname, point *a, size_t n) {
  FILE *f = fopen(pathname, "r");

  if (f == NULL) {
    fprintf(stderr, "Error reading file\n");
    return -1;
  }

  size_t output = fread(a , sizeof(a[0]), n, f);

  fclose(f);


  return output;
}

// scanf
// reading human readable
ssize_t scan_points(const char *pathname, point *a, size_t n) {
  if (pathname == NULL || a == NULL || n == 0) {
    fprintf(stderr, "Error opening file\n");
    return -1;
  }

  FILE *file = fopen(pathname, "r");
  if (file == NULL) {
    return -1; // Unable to open the file
  }

  size_t count = 0; // Number of points read
  int x, y;

  // Continue reading until we reach the end of file or read all points
  while (count < n && fscanf(file, "%d %d", &x, &y) == 2) {
    a[count].x = x;
    a[count].y = y;
    count++;
  }

  fclose(file);
  return count; // Return the number of complete points read
}