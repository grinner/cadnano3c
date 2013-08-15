#ifndef STYLES_H
#define STYLES_H

#include <QColor>
#include <QFont>
#include <QFontMetricsF>
#define ISWIN 1

// Slice Sizing
#define SLICE_HELIX_RADIUS              15
#define SLICE_HELIX_STROKE_WIDTH        0.5
#define SLICE_HELIX_HILIGHT_WIDTH       2.5
#define SLICE_HELIX_MOD_HILIGHT_WIDTH   1
#define HONEYCOMB_PART_MAXROWS          30
#define HONEYCOMB_PART_MAXCOLS          32
#define HONEYCOMB_PART_MAXSTEPS         2
#define SQUARE_PART_MAXROWS             50
#define SQUARE_PART_MAXCOLS             50
#define SQUARE_PART_MAXSTEPS            2

// Slice Colors
QColor *bluefill          = new QColor(153, 204, 255);  // 99ccff
QColor *bluestroke        = new QColor(0, 102, 204);  // 0066cc
QColor *bluishstroke      = new QColor(0, 182, 250);  //
QColor *orangefill        = new QColor(255, 204, 153);  // ffcc99
QColor *orangestroke      = new QColor(204, 102, 51);  // cc6633
QColor *lightorangefill   = new QColor(255, 234, 183);
QColor *lightorangestroke = new QColor(234, 132, 81);
QColor *grayfill          = new QColor(238, 238, 238);  // eeeeee (was a1a1a1)
QColor *graystroke        = new QColor(102, 102, 102);  // 666666 (was 424242)

// Path Sizing
#define VIRTUALHELIXHANDLEITEM_RADIUS        30
#define VIRTUALHELIXHANDLEITEM_STROKE_WIDTH  2
#define PATH_BASE_WIDTH                      20  // used to size bases (grid squares, handles, etc)
#define PATH_HELIX_HEIGHT                    (2 * PATH_BASE_WIDTH)  // staple + scaffold
#define PATH_HELIX_PADDING                   50 // gap between PathHelix objects in path view
#define PATH_GRID_STROKE_WIDTH               0.5
#define SLICE_HANDLE_STROKE_WIDTH            1
#define PATH_STRAND_STROKE_WIDTH             3
#define PATH_STRAND_HIGHLIGHT_STROKE_WIDTH   8
#define PATH_SELECTBOX_STROKE_WIDTH          1.5
#define PCH_BORDER_PADDING                   1
#define PATH_BASE_HL_STROKE_WIDTH            2  // PathTool highlight box
#define MINOR_GRID_STROKE_WIDTH              0.5
#define MAJOR_GRID_STROKE_WIDTH              0.5
#define OLIGOLENBELOWWHICHHIGHLIGHT          20
#define OLIGOLENABOVEWHICHHIGHLIGHT          49

// Path Drawing
#define PATH_XOVER_LINE_SCALE_X  0.035
#define PATH_XOVER_LINE_SCALE_Y  0.035

// Path Colors
QColor *scaffold_bkg_fill        = new QColor(230, 230, 230);
QColor *activeslicehandlefill    = new QColor(255, 204, 153, 128);  // ffcc99
QColor *activeslicehandlestroke  = new QColor(204, 102, 51, 128);  // cc6633
QColor *minorgridstroke          = new QColor(204, 204, 204);  // 999999
QColor *majorgridstroke          = new QColor(153, 153, 153);  // 333333
QColor *scafstroke               = new QColor(0, 102, 204);  // 0066cc
QColor *handlefill               = new QColor(0, 102, 204);  // 0066cc
QColor *pxi_scaf_stroke          = new QColor(0, 102, 204, 153);
QColor *pxi_stap_stroke          = new QColor(204, 0, 0, 153);
QColor *pxi_disab_stroke         = new QColor(204, 204, 204, 255);
QColor *redstroke                = new QColor(204, 0, 0);
QColor *erasefill                = new QColor(204, 0, 0, 63);
QColor *forcefill                = new QColor(0, 255, 255, 63);
QColor *breakfill                = new QColor(204, 0, 0, 255);
QColor *colorbox_fill            = new QColor(204, 0, 0);
QColor *colorbox_stroke          = new QColor(102, 102, 102);
QColor *stapcolors[] = { new QColor(204, 0, 0),
                        new QColor(247, 67, 8),
                        new QColor(247, 147, 30),
                        new QColor(170, 170, 0),
                        new QColor(87, 187, 0),
                        new QColor(0, 114, 0),
                        new QColor(3, 182, 162),
                        new QColor(23, 0, 222),
                        new QColor(115, 0, 222),
                        new QColor(184, 5, 108),
                        new QColor(51, 51, 51),
                        new QColor(136, 136, 136) };
QColor *scafcolors[] =   { new QColor(0, 102, 204) };
              // new QColor(64, 138, 212),
              // new QColor(0, 38, 76),
              // new QColor(23, 50, 76),
              // new QColor(0, 76, 153) };
#define DEFAULT_STAP_COLOR  "#888888"
#define DEFAULT_SCAF_COLOR  "#0066cc"
QColor *selected_color      = new QColor(255, 51, 51);

// Loop/Insertion path details
#define INSERTWIDTH   2
#define SKIPWIDTH     2

// Add Sequence Tool
QColor *invalid_dna_color       = new QColor(204, 0, 0);
#define UNDERLINE_INVALID_DNA   true

// Additional Prefs
#define PREF_AUTOSCAF_INDEX        0
#define PREF_STARTUP_TOOL_INDEX    0
#define PREF_ZOOM_SPEED            20 //50
#define PREF_ZOOM_AFTER_HELIX_ADD  true


//Z values
//bottom
#define ZACTIVESLICEHANDLE  10
#define ZPATHHELIXGROUP     20
#define ZPATHHELIX          30
#define ZPATHSELECTION      40
#define ZSLICEHELIX         50
#define ZDESELECTOR         60
#define ZFOCUSRING          70
#define ZPREXOVERHANDLE     80
#define ZXOVERITEM          90
#define ZBREAKPOINTHANDLE   100
#define ZSKIPHANDLE         110
#define ZBREAKITEM          120
#define ZPATHTOOL           130
#define ZSTRANDITEM         140
#define ZENDPOINTITEM       150
#define ZINSERTHANDLE       160
#define ZPARTITEM           200
//top

// sequence stuff
//if hasattr(QFont, 'dummy'):
//    #define SEQUENCEFONT                  0
//    #define SEQUENCEFONTH                 15
//    #define SEQUENCEFONTCHARWIDTH         12
//    #define SEQUENCEFONTCHARHEIGHT        12
//    #define SEQUENCEFONTEXTRAWIDTH        3
//    #define SEQUENCETEXTXCENTERINGOFFSET  0
//#else
QFont *SEQUENCEFONT = new QFont("Monaco");

#define SEQUENCEFONTH                          (PATH_BASE_WIDTH / 3.0)

QFontMetricsF *SEQUENCEFONTMETRICS = new QFontMetricsF(*SEQUENCEFONT);
#define SEQUENCEFONTCHARHEIGHT                 SEQUENCEFONTMETRICS.height()
#define SEQUENCEFONTEXTRAWIDTH                 (PATH_BASE_WIDTH - SEQUENCEFONTCHARWIDTH)
#define SEQUENCETEXTXCENTERINGOFFSET           (SEQUENCEFONTEXTRAWIDTH / 4.0)
#define SEQUENCETEXTYCENTERINGOFFSET           (PATH_BASE_WIDTH * 0.6)


#ifdef ISMAC
//    #define THEFONT           "Times"
    #define THEFONT           "Arial"
    #define THEFONTSIZE       10
    QFont *XOVER_LABEL_FONT = new QFont(THEFONT, THEFONTSIZE, QFont::Bold);
#elif ISWIN
//    #define THEFONT           "Segoe UI"
//    #define THEFONT           "Calibri"
    #define THEFONT           "Arial"
    #define THEFONTSIZE       9
    QFont *XOVER_LABEL_FONT = new QFont(THEFONT, THEFONTSIZE, QFont::Bold);
#else // linux
    #define THEFONT  "DejaVu Sans"
    #define THEFONTSIZE       9
    QFont *XOVER_LABEL_FONT = new QFont(THEFONT, THEFONTSIZE, QFont::Bold);
#endif

QFont *SLICE_NUM_FONT               =  new QFont(THEFONT, 10, QFont::Bold);
QFont *VIRTUALHELIXHANDLEITEM_FONT  = new  QFont(THEFONT, 3*THEFONTSIZE, QFont::Bold);
QColor *XOVER_LABEL_COLOR           = new QColor(0,0,0);

// Overwrite for Maya
// majorgridstroke                    QColor(255, 255, 255)  // ffffff for maya


#endif // STYLES_H
