#include "HardwareInterface.h"

class PageButton {
    private:
        HardwareButton* button;

    public:    
        void (* nextValueCallback)(void);  
    //  uint8_t (* getValueCallback)(void);
    //  HardwareButton* getButton();
        void processChanges();
        PageButton(HardwareButton* button);
        PageButton();
};
