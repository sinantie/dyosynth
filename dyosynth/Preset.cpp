#include "preset.h"

Preset::Preset() {

}

void Preset::loadPreset(int values[]) {
  Preset::setFilter((FILTER_TYPE)values[14]);
  Preset::setFilterCutoff(values[15]);
  Preset::setFilterResonance(values[16]);
  Preset::setFilterEnvModPercent(values[17]);
}

String Preset::toString() {
  String values = "Filter: " + String(Preset::getFilter()) + "\n" +
                  "Filter cutoff: " + String(Preset::getFilterCutoff()) + "\n" +
                  "Filter resonance: " + String(Preset::getFilterResonance()) + "\n" +
                  "Filter env mod percent: " + String(Preset::getFilterEnvModPercent()) + "\n";
  return values;
}

