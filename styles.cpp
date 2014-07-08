#include "styles.h"
// migrate to a Style Class that loads a json config file and creates
// a Q_GLOBAL_STATIC_WITH_ARGS(CN_Styles, my_cn_styles, "path to config.json")
// and only extern the my_cn_styles
// http://qt-project.org/doc/qt-5/qglobalstatic.html#details
// or create a context object?

namespace {

QColor bluefill          = QColor(153, 204, 255);  // 99ccff
QColor bluestroke        = QColor(0, 102, 204);  // 0066cc
QColor bluishstroke      = QColor(0, 182, 250);  //
QColor orangefill        = QColor(255, 204, 153);  // ffcc99
QColor orangestroke      = QColor(204, 102, 51);  // cc6633
QColor lightorangefill   = QColor(255, 234, 183);
QColor lightorangestroke = QColor(234, 132, 81);
QColor grayfill          = QColor(238, 238, 238);  // eeeeee (was a1a1a1)
QColor graystroke        = QColor(102, 102, 102);  // 666666 (was 424242)

QColor scaffold_bkg_fill        = QColor(230, 230, 230);
QColor activeslicehandlefill    = QColor(255, 204, 153, 128);  // ffcc99
QColor activeslicehandlestroke  = QColor(204, 102, 51, 128);  // cc6633
QColor minorgridstroke          = QColor(204, 204, 204);  // 999999
QColor majorgridstroke          = QColor(153, 153, 153);  // 333333
QColor scafstroke               = QColor(0, 102, 204);  // 0066cc
QColor handlefill               = QColor(0, 102, 204);  // 0066cc
QColor pxi_scaf_stroke          = QColor(0, 102, 204, 153);
QColor pxi_stap_stroke          = QColor(204, 0, 0, 153);
QColor pxi_disab_stroke         = QColor(204, 204, 204, 255);
QColor redstroke                = QColor(204, 0, 0);
QColor erasefill                = QColor(204, 0, 0, 63);
QColor forcefill                = QColor(0, 255, 255, 63);
QColor breakfill                = QColor(204, 0, 0, 255);
QColor colorbox_fill            = QColor(204, 0, 0);
QColor colorbox_stroke          = QColor(102, 102, 102);

QColor stapcolors[] = { QColor(204, 0, 0),
                       QColor(247, 67, 8),
                       QColor(247, 147, 30),
                       QColor(170, 170, 0),
                       QColor(87, 187, 0),
                       QColor(0, 114, 0),
                       QColor(3, 182, 162),
                       QColor(23, 0, 222),
                       QColor(115, 0, 222),
                       QColor(184, 5, 108),
                       QColor(51, 51, 51),
                       QColor(136, 136, 136) };

QColor scafcolors[] =   { QColor(0, 102, 204) };
                        // QColor(64, 138, 212),
                        // QColor(0, 38, 76),
                        // QColor(23, 50, 76),
                        // QColor(0, 76, 153) };

QColor selected_color      = QColor(255, 51, 51);

QColor invalid_dna_color       = QColor(204, 0, 0);

// Font stuff
QFont SEQUENCEFONT = QFont("Monaco");
int SEQUENCEFONTCHARWIDTH = 0;
QFontMetricsF SEQUENCEFONTMETRICS = QFontMetricsF(SEQUENCEFONT);
QFont XOVER_LABEL_FONT = QFont(THEFONT, THEFONTSIZE, QFont::Bold);

QFont SLICE_NUM_FONT               =  QFont(THEFONT, 10, QFont::Bold);
QFont VIRTUALHELIXHANDLEITEM_FONT  = QFont(THEFONT, 3*THEFONTSIZE, QFont::Bold);
QColor XOVER_LABEL_COLOR           = QColor(0,0,0);

void setupStyle(void) {
    SEQUENCEFONTCHARWIDTH = SEQUENCEFONTMETRICS.width('A');
    SEQUENCEFONT.setStyleHint(QFont::Monospace);
    SEQUENCEFONT.setFixedPitch(true);
    SEQUENCEFONT.setPixelSize(SEQUENCEFONTH);
    SEQUENCEFONT.setLetterSpacing(QFont::AbsoluteSpacing, SEQUENCEFONTEXTRAWIDTH);
}

}
