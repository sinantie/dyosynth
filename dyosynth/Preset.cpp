#include "preset.h"

Preset::Preset() {

}

void Preset::loadPreset(int values[]) {
  Preset::setFilter((FILTER_TYPE)values[14]);
  Preset::setFilterCutoff(values[15]);
  Preset::setFilterResonance(values[16]);
  Preset::setFilterEnvModPercent(values[17]);
}


