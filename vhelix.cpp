#include "vhelix.h"

bool VirtualHelix::isDrawn5to3(StrandType ss_idx) {
    bool isScaf = ss_idx == Scaffold;
    bool isEven = isEvenParity();
    return isEven == isScaf;
}

bool VirtualHelix::isEvenParity() {
    return m_part->isEvenParity(m_coord);
}
