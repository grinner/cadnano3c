#ifndef STYLES_H
#define STYLES_H

#include <QColor>
#include <QFont>
#include <QFontMetricsF>

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
extern QColor bluefill;  // 99ccff
extern QColor bluestroke;  // 0066cc
extern QColor bluishstroke;  //
extern QColor orangefill;  // ffcc99
extern QColor orangestroke;  // cc6633
extern QColor lightorangefill;
extern QColor lightorangestroke;
extern QColor grayfill;  // eeeeee (was a1a1a1)
extern QColor graystroke;  // 666666 (was 424242)

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
extern QColor scaffold_bkg_fill;
extern QColor activeslicehandlefill;  // ffcc99
extern QColor activeslicehandlestroke;  // cc6633
extern QColor minorgridstroke;  // 999999
extern QColor majorgridstroke;  // 333333
extern QColor scafstroke;  // 0066cc
extern QColor handlefill;  // 0066cc
extern QColor pxi_scaf_stroke;
extern QColor pxi_stap_stroke;
extern QColor pxi_disab_stroke;
extern QColor redstroke;
extern QColor erasefill;
extern QColor forcefill;
extern QColor breakfill;
extern QColor colorbox_fill;
extern QColor colorbox_stroke;
extern QColor *stapcolors;
extern QColor *scafcolors;

//#define DEFAULT_STAP_COLOR  "#888888"
//#define DEFAULT_SCAF_COLOR  "#0066cc"
extern QColor selected_color;

// Loop/Insertion path details
#define INSERTWIDTH   2
#define SKIPWIDTH     2

// Add Sequence Tool
extern QColor invalid_dna_color;
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
extern QFont SEQUENCEFONT;
#define SEQUENCEFONTH                          (PATH_BASE_WIDTH / 3.0)

extern QFontMetricsF SEQUENCEFONTMETRICS;
extern int SEQUENCEFONTCHARWIDTH;
#define SEQUENCEFONTCHARHEIGHT                 SEQUENCEFONTMETRICS.height()
#define SEQUENCEFONTEXTRAWIDTH                 (PATH_BASE_WIDTH - SEQUENCEFONTCHARWIDTH)
#define SEQUENCETEXTXCENTERINGOFFSET           (SEQUENCEFONTEXTRAWIDTH / 4.0)
#define SEQUENCETEXTYCENTERINGOFFSET           (PATH_BASE_WIDTH * 0.6)

extern QFont XOVER_LABEL_FONT;
#ifdef Q_WS_WIN
//    #define THEFONT           "Times"
    #define THEFONT           "Arial"
    #define THEFONTSIZE       10

#elif Q_WS_MAC
//    #define THEFONT           "Segoe UI"
//    #define THEFONT           "Calibri"
    #define THEFONT           "Arial"
    #define THEFONTSIZE       9
#else // linux
    #define THEFONT  "DejaVu Sans"
    #define THEFONTSIZE       9
#endif

extern QFont SLICE_NUM_FONT;
extern QFont VIRTUALHELIXHANDLEITEM_FONT;
extern QColor XOVER_LABEL_COLOR;

// Overwrite for Maya
// majorgridstroke                    QColor(255, 255, 255)  // ffffff for maya

void setupStyle(void);

#endif // STYLES_H
