#include "chrono.h"


// 7.1 Chronomètre élémentaire, précis à la micro seconde.
// Fonction non visible en dehors de ce fichier
float chrono(int action) {
  static double ch = 0.0;
  double current;
  float delta;
  struct timeval tv;
  
  gettimeofday(&tv,NULL);
  current = tv.tv_sec + (float)(tv.tv_usec)*1e-6;
  if (action == 0) ch = current;
  delta = (float)(current-ch);
  return delta;
}

// Déclenchement du chrono
// Le remet à zéro s'il était déjà lancé
void  chrono_start() { chrono(0); }
// renvoie la valeur courante du chrono en secondes
float chrono_lap()   { return chrono(1); }
