/*
 * File: Model_TranslationEngine64_TuneVar.c
 *
 * Code generated for Simulink model 'Model_TranslationEngine64'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Mar  6 16:20:04 2024
 *
 * Target selection: ert_shrlib.tlc
 * Embedded hardware selection: Intel->x86-32 (Windows32)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <ctype.h>
#include "rtwtypes.h"
#include "Model_TranslationEngine64_TuneVar.h"
#include "ASDID.h"                     // for SimulinkDatatypeId
#include "Model_TranslationEngine64.h" // for tune variable output signals
#include <stdio.h>                     // for sscanf, vsnprintf
#include <stdarg.h>                    // for variadic args (va_start)
#include <string.h>                    // for memset, memcpy, strlen, etc
#define MAX_TUNEVAR_DIM                7U

// TuneVar table record
typedef struct TuneVar_tag
{
    const char* name;                  // name of TuneVar
    int sightings_count;             // counts RecognizeTuneVariable invocations
    SimulinkDatatypeId dtype_id;      // SimulinkDatatypeId of numeric data type
    int string_parse;                  // 0=numeric input, 1=string input
    int element_bytes;                 // byte size of a single element
    int width;                         // maximum supported elements
    int max_size[MAX_TUNEVAR_DIM];     // maximum for each dimension
    int variable_dim;
                  // index of the dimension allowed to vary in size (for inputs)
    int num_dims;                      // number of dimensions
    int current_width;
             // width of current value (although stored in max dimensional size)
    void* default_value;
    int default_width;
    double* current_dims;              // dimensions of current value
    void* value_ptr;                   // array of current numeric value
    int translation_count;
                        // indicates how many translations feed off this TuneVar
    enum TranslationNumber *translations;
                        // array of translation numbers feeding off this TuneVar
}
TuneVar_type;

// Translation numbers local to this model:
enum TranslationNumber
{
    ID_Translation_Model_141_1371,     /* '<S636>/S-Function' */
    ID_Translation_Model_141_345_50_36,/* '<S766>/S-Function' */
    ID_Translation_Model_141_346_67_18,/* '<S771>/S-Function' */
    ID_Translation_Model_141_2888,     /* '<S759>/S-Function' */
    ID_Translation_Model_141_2926,     /* '<S783>/S-Function' */
    ID_Translation_Model_141_2932,     /* '<S786>/S-Function' */
    ID_Translation_Model_141_2939,     /* '<S789>/S-Function' */
    ID_Translation_Model_141_2947,     /* '<S792>/S-Function' */
    ID_Translation_Model_141_2955,     /* '<S795>/S-Function' */
    ID_Translation_Model_141_2962,     /* '<S798>/S-Function' */
    ID_Translation_Model_141_2968,     /* '<S801>/S-Function' */
    ID_Translation_Model_141_3372,     /* '<S814>/S-Function' */
    ID_Translation_Model_141_3380,     /* '<S817>/S-Function' */
    ID_Translation_Model_141_3388,     /* '<S820>/S-Function' */
    ID_Translation_Model_141_3395,     /* '<S823>/S-Function' */
    ID_Translation_Model_141_3402,     /* '<S826>/S-Function' */
    ID_Translation_Model_141_3410,     /* '<S829>/S-Function' */
    ID_Translation_Model_141_3418,     /* '<S832>/S-Function' */
    ID_Translation_Model_141_3426,     /* '<S835>/S-Function' */
    ID_Translation_Model_141_3434,     /* '<S838>/S-Function' */
    ID_Translation_Model_141_3442,     /* '<S841>/S-Function' */
    ID_Translation_Model_141_3495,     /* '<S849>/S-Function' */
    ID_Translation_Model_141_3596,     /* '<S859>/S-Function' */
    ID_Translation_Model_141_3602,     /* '<S862>/S-Function' */
    ID_Translation_Model_141_3609,     /* '<S865>/S-Function' */
    ID_Translation_Model_141_3617,     /* '<S868>/S-Function' */
    ID_Translation_Model_141_3625,     /* '<S871>/S-Function' */
    ID_Translation_Model_141_3632,     /* '<S874>/S-Function' */
    ID_Translation_Model_141_3638,     /* '<S877>/S-Function' */
    ID_Translation_Model_141_4091,     /* '<S890>/S-Function' */
    ID_Translation_Model_141_4099,     /* '<S893>/S-Function' */
    ID_Translation_Model_141_4107,     /* '<S896>/S-Function' */
    ID_Translation_Model_141_4114,     /* '<S899>/S-Function' */
    ID_Translation_Model_141_4121,     /* '<S902>/S-Function' */
    ID_Translation_Model_141_4129,     /* '<S905>/S-Function' */
    ID_Translation_Model_141_4137,     /* '<S908>/S-Function' */
    ID_Translation_Model_141_4145,     /* '<S911>/S-Function' */
    ID_Translation_Model_141_4153,     /* '<S914>/S-Function' */
    ID_Translation_Model_141_4161,     /* '<S917>/S-Function' */
    ID_Translation_Model_141_983_182,  /* '<S929>/S-Function' */
    ID_Translation_Model_141_983_188,  /* '<S932>/S-Function' */
    ID_Translation_Model_141_983_194,  /* '<S935>/S-Function' */
    ID_Translation_Model_141_983_200,  /* '<S938>/S-Function' */
    ID_Translation_Model_141_983_206,  /* '<S941>/S-Function' */
    ID_Translation_Model_141_983_287,  /* '<S948>/S-Function' */
    ID_Translation_Model_141_983_293,  /* '<S951>/S-Function' */
    ID_Translation_Model_141_983_299,  /* '<S954>/S-Function' */
    ID_Translation_Model_141_983_305,  /* '<S957>/S-Function' */
    ID_Translation_Model_141_984_182,  /* '<S967>/S-Function' */
    ID_Translation_Model_141_984_188,  /* '<S970>/S-Function' */
    ID_Translation_Model_141_984_194,  /* '<S973>/S-Function' */
    ID_Translation_Model_141_984_200,  /* '<S976>/S-Function' */
    ID_Translation_Model_141_984_206,  /* '<S979>/S-Function' */
    ID_Translation_Model_141_984_287,  /* '<S986>/S-Function' */
    ID_Translation_Model_141_984_293,  /* '<S989>/S-Function' */
    ID_Translation_Model_141_984_299,  /* '<S992>/S-Function' */
    ID_Translation_Model_141_984_305,  /* '<S995>/S-Function' */
    ID_Translation_Model_141_472_255_36,/* '<S1005>/S-Function' */
    ID_Translation_Model_141_472_235,  /* '<S1008>/S-Function' */
    ID_Translation_Model_141_472_239_67_18,/* '<S1015>/S-Function' */
    ID_Translation_Model_141_472_240_67_18,/* '<S1019>/S-Function' */
    ID_Translation_Model_141_473_12_36,/* '<S1023>/S-Function' */
    ID_Translation_Model_141_595_191,  /* '<S1027>/S-Function' */
    ID_Translation_Model_141_595_238_36,/* '<S1030>/S-Function' */
    ID_Translation_Model_141_4193,     /* '<S1036>/S-Function' */
    ID_Translation_Model_150_574_67_18,/* '<S1044>/S-Function' */
    ID_Translation_Model_232_8_34_50_36,/* '<S1165>/S-Function' */
    ID_Translation_Model_232_8_36_67_18,/* '<S1170>/S-Function' */
    ID_Translation_Model_232_11_191,   /* '<S1172>/S-Function' */
    ID_Translation_Model_232_12_191,   /* '<S1175>/S-Function' */
    ID_Translation_Model_247_149,      /* '<S1183>/S-Function' */
    ID_Translation_Model_247_153,      /* '<S1184>/S-Function' */
    ID_Translation_Model_247_174,      /* '<S1182>/S-Function' */
    ID_Translation_Model_247_176,      /* '<S1185>/S-Function' */
    ID_Translation_Model_247_210_67_18,/* '<S1199>/S-Function' */
    ID_Translation_Model_247_229_67_18,/* '<S1203>/S-Function' */
    ID_Translation_Model_247_209_67_18,/* '<S1207>/S-Function' */
    ID_Translation_Model_249_47,       /* '<S1210>/S-Function' */
    ID_Translation_Model_249_48,       /* '<S1211>/S-Function' */
    ID_Translation_Model_249_46,       /* '<S1209>/S-Function' */
    ID_Translation_Model_249_49,       /* '<S1212>/S-Function' */
    ID_Translation_Model_249_50_67_18, /* '<S1226>/S-Function' */
    ID_Translation_Model_249_51_67_18, /* '<S1230>/S-Function' */
    ID_Translation_Model_249_52_67_18, /* '<S1234>/S-Function' */
    ID_Translation_Model_642,          /* '<S1241>/S-Function' */
    ID_Translation_Model_670_67_18,    /* '<S1250>/S-Function' */
    ID_Translation_Model_712,          /* '<S1256>/S-Function' */
    ID_Translation_Model_729,          /* '<S1262>/S-Function' */
    ID_Translation_Model_730,          /* '<S1263>/S-Function' */
    ID_Translation_Model_731,          /* '<S1264>/S-Function' */
    ID_Translation_Model_741,          /* '<S1268>/S-Function' */
    ID_Translation_Model_747,          /* '<S1271>/S-Function' */
    ID_Translation_Model_251_149,      /* '<S1275>/S-Function' */
    ID_Translation_Model_251_153,      /* '<S1276>/S-Function' */
    ID_Translation_Model_251_174,      /* '<S1274>/S-Function' */
    ID_Translation_Model_251_176,      /* '<S1277>/S-Function' */
    ID_Translation_Model_251_210_67_18,/* '<S1291>/S-Function' */
    ID_Translation_Model_251_229_67_18,/* '<S1295>/S-Function' */
    ID_Translation_Model_251_209_67_18,/* '<S1299>/S-Function' */
    ID_Translation_Model_1495,         /* '<S1857>/S-Function' */
    ID_Translation_Model_1498,         /* '<S1860>/S-Function' */
    ID_Translation_Model_1496,         /* '<S1858>/S-Function' */
    ID_Translation_Model_1499,         /* '<S1861>/S-Function' */
    ID_Translation_Model_1497,         /* '<S1859>/S-Function' */
    ID_Translation_Model_1500,         /* '<S1862>/S-Function' */
    ID_Translation_Model_72_276_67_18, /* '<S1874>/S-Function' */
    ID_Translation_Model_76_36,        /* '<S1877>/S-Function' */
    ID_Translation_Model_1527,         /* '<S1881>/S-Function' */
    ID_Translation_Model_1528,         /* '<S1882>/S-Function' */
    ID_Translation_Model_397,          /* '<S8>/S-Function' */
    ID_Translation_Model_141_246_96,   /* '<S609>/S-Function' */
    ID_Translation_Model_141_246_141_36,/* '<S613>/S-Function' */
    ID_Translation_Model_141_246_148_36,/* '<S617>/S-Function' */
    ID_Translation_Model_141_246_111_67_18,/* '<S622>/S-Function' */
    ID_Translation_Model_141_1196_67_18,/* '<S628>/S-Function' */
    ID_Translation_Model_141_1560,     /* '<S647>/S-Function' */
    ID_Translation_Model_141_1561,     /* '<S648>/S-Function' */
    ID_Translation_Model_141_1988,     /* '<S653>/S-Function' */
    ID_Translation_Model_141_1989,     /* '<S654>/S-Function' */
    ID_Translation_Model_141_1990,     /* '<S655>/S-Function' */
    ID_Translation_Model_141_2031_67_18,/* '<S664>/S-Function' */
    ID_Translation_Model_141_2423,     /* '<S674>/S-Function' */
    ID_Translation_Model_141_2424,     /* '<S675>/S-Function' */
    ID_Translation_Model_141_2654,     /* '<S680>/S-Function' */
    ID_Translation_Model_141_2655,     /* '<S681>/S-Function' */
    ID_Translation_Model_141_2656,     /* '<S682>/S-Function' */
    ID_Translation_Model_141_2697_67_18,/* '<S691>/S-Function' */
    ID_Translation_Model_141_2783,     /* '<S696>/S-Function' */
    ID_Translation_Model_141_2787,     /* '<S700>/S-Function' */
    ID_Translation_Model_141_2784,     /* '<S697>/S-Function' */
    ID_Translation_Model_141_2785,     /* '<S698>/S-Function' */
    ID_Translation_Model_141_2786,     /* '<S699>/S-Function' */
    ID_Translation_Model_141_2808_67_18,/* '<S713>/S-Function' */
    ID_Translation_Model_141_2849,     /* '<S717>/S-Function' */
    ID_Translation_Model_141_2850,     /* '<S718>/S-Function' */
    ID_Translation_Model_141_2851,     /* '<S719>/S-Function' */
    ID_Translation_Model_141_2852,     /* '<S720>/S-Function' */
    ID_Translation_Model_141_2853,     /* '<S721>/S-Function' */
    ID_Translation_Model_141_2865_67_18,/* '<S737>/S-Function' */
    ID_Translation_Model_141_2866_67_18,/* '<S741>/S-Function' */
    ID_Translation_Model_141_2867_67_18,/* '<S745>/S-Function' */
    ID_Translation_Model_141_2878_50_36,/* '<S749>/S-Function' */
    ID_Translation_Model_449_67_18,    /* '<S1075>/S-Function' */
    ID_Translation_Model_450_67_18,    /* '<S1079>/S-Function' */
    ID_Translation_Model_455,          /* '<S1082>/S-Function' */
    ID_Translation_Model_459_67_18,    /* '<S1086>/S-Function' */
    ID_Translation_Model_460_67_18,    /* '<S1090>/S-Function' */
    ID_Translation_Model_175_136_99,   /* '<S1096>/S-Function' */
    ID_Translation_Model_175_136_98,   /* '<S1095>/S-Function' */
    ID_Translation_Model_176_136_99,   /* '<S1103>/S-Function' */
    ID_Translation_Model_176_136_98,   /* '<S1102>/S-Function' */
    ID_Translation_Model_489_67_18,    /* '<S1110>/S-Function' */
    ID_Translation_Model_533,          /* '<S1113>/S-Function' */
    ID_Translation_Model_538_67_18,    /* '<S1122>/S-Function' */
    ID_Translation_Model_539_67_18,    /* '<S1126>/S-Function' */
    ID_Translation_Model_540_67_18,    /* '<S1130>/S-Function' */
    ID_Translation_Model_545,          /* '<S1132>/S-Function' */
    ID_Translation_Model_596,          /* '<S1136>/S-Function' */
    ID_Translation_Model_601_67_18,    /* '<S1145>/S-Function' */
    ID_Translation_Model_602_67_18,    /* '<S1149>/S-Function' */
    ID_Translation_Model_603_67_18,    /* '<S1153>/S-Function' */
    ID_Translation_Model_608,          /* '<S1155>/S-Function' */
    ID_Translation_Model_117_21_67_18, /* '<S26>/S-Function' */
    ID_Translation_Model_117_1781,     /* '<S30>/S-Function' */
    ID_Translation_Model_117_43_332,   /* '<S38>/S-Function' */
    ID_Translation_Model_117_43_351,   /* '<S40>/S-Function' */
    ID_Translation_Model_117_43_340,   /* '<S44>/S-Function' */
    ID_Translation_Model_117_43_403,   /* '<S48>/S-Function' */
    ID_Translation_Model_117_44_721,   /* '<S68>/S-Function' */
    ID_Translation_Model_117_44_722,   /* '<S69>/S-Function' */
    ID_Translation_Model_117_44_723,   /* '<S70>/S-Function' */
    ID_Translation_Model_117_44_894,   /* '<S73>/S-Function' */
    ID_Translation_Model_117_44_736,   /* '<S72>/S-Function' */
    ID_Translation_Model_117_44_895,   /* '<S71>/S-Function' */
    ID_Translation_Model_117_44_469_67_18,/* '<S84>/S-Function' */
    ID_Translation_Model_117_44_470_67_18,/* '<S88>/S-Function' */
    ID_Translation_Model_117_44_332_67_18,/* '<S92>/S-Function' */
    ID_Translation_Model_117_44_333_67_18,/* '<S96>/S-Function' */
    ID_Translation_Model_117_44_334_67_18,/* '<S100>/S-Function' */
    ID_Translation_Model_117_44_335_67_18,/* '<S104>/S-Function' */
    ID_Translation_Model_117_44_341_67_18,/* '<S108>/S-Function' */
    ID_Translation_Model_117_44_342_67_18,/* '<S112>/S-Function' */
    ID_Translation_Model_117_44_484_67_18,/* '<S116>/S-Function' */
    ID_Translation_Model_117_44_485_67_18,/* '<S120>/S-Function' */
    ID_Translation_Model_117_44_315_67_18,/* '<S136>/S-Function' */
    ID_Translation_Model_117_44_316_67_18,/* '<S140>/S-Function' */
    ID_Translation_Model_117_44_317_67_18,/* '<S144>/S-Function' */
    ID_Translation_Model_117_44_318_67_18,/* '<S148>/S-Function' */
    ID_Translation_Model_117_44_666,   /* '<S153>/S-Function' */
    ID_Translation_Model_117_44_645,   /* '<S152>/S-Function' */
    ID_Translation_Model_117_44_672,   /* '<S154>/S-Function' */
    ID_Translation_Model_117_44_325_67_18,/* '<S161>/S-Function' */
    ID_Translation_Model_117_44_633,   /* '<S164>/S-Function' */
    ID_Translation_Model_117_44_343_67_18,/* '<S169>/S-Function' */
    ID_Translation_Model_117_44_337_67_18,/* '<S173>/S-Function' */
    ID_Translation_Model_117_44_338_67_18,/* '<S177>/S-Function' */
    ID_Translation_Model_117_44_913_67_18,/* '<S181>/S-Function' */
    ID_Translation_Model_117_44_346_67_18,/* '<S185>/S-Function' */
    ID_Translation_Model_117_44_328,   /* '<S188>/S-Function' */
    ID_Translation_Model_117_516_1944, /* '<S200>/S-Function' */
    ID_Translation_Model_117_516_1707_67_18,/* '<S214>/S-Function' */
    ID_Translation_Model_117_516_1708_67_18,/* '<S218>/S-Function' */
    ID_Translation_Model_117_516_1732_67_18,/* '<S224>/S-Function' */
    ID_Translation_Model_117_516_1733_67_18,/* '<S228>/S-Function' */
    ID_Translation_Model_117_516_1751_67_18,/* '<S238>/S-Function' */
    ID_Translation_Model_117_516_1752_67_18,/* '<S242>/S-Function' */
    ID_Translation_Model_117_516_1753_67_18,/* '<S246>/S-Function' */
    ID_Translation_Model_117_516_1755_67_18,/* '<S250>/S-Function' */
    ID_Translation_Model_117_516_1754_67_18,/* '<S254>/S-Function' */
    ID_Translation_Model_117_516_1758, /* '<S257>/S-Function' */
    ID_Translation_Model_117_516_1774_67_18,/* '<S262>/S-Function' */
    ID_Translation_Model_117_516_1789, /* '<S267>/S-Function' */
    ID_Translation_Model_117_516_1795, /* '<S270>/S-Function' */
    ID_Translation_Model_117_516_1804_67_18,/* '<S275>/S-Function' */
    ID_Translation_Model_117_516_1778_67_18,/* '<S279>/S-Function' */
    ID_Translation_Model_117_516_1849_50_36,/* '<S285>/S-Function' */
    ID_Translation_Model_117_516_1847_50_36,/* '<S290>/S-Function' */
    ID_Translation_Model_117_516_957,  /* '<S294>/S-Function' */
    ID_Translation_Model_117_517_435,  /* '<S305>/S-Function' */
    ID_Translation_Model_117_517_422,  /* '<S314>/S-Function' */
    ID_Translation_Model_117_517_415,  /* '<S317>/S-Function' */
    ID_Translation_Model_117_517_330_67_18,/* '<S321>/S-Function' */
    ID_Translation_Model_117_517_331_67_18,/* '<S325>/S-Function' */
    ID_Translation_Model_117_517_332_67_18,/* '<S329>/S-Function' */
    ID_Translation_Model_117_517_429_67_18,/* '<S333>/S-Function' */
    ID_Translation_Model_117_517_515_50_36,/* '<S339>/S-Function' */
    ID_Translation_Model_117_517_516_50_36,/* '<S344>/S-Function' */
    ID_Translation_Model_117_517_459_67_18,/* '<S349>/S-Function' */
    ID_Translation_Model_117_517_351,  /* '<S352>/S-Function' */
    ID_Translation_Model_117_517_388,  /* '<S361>/S-Function' */
    ID_Translation_Model_117_517_397,  /* '<S364>/S-Function' */
    ID_Translation_Model_117_517_404,  /* '<S367>/S-Function' */
    ID_Translation_Model_117_517_270_67_18,/* '<S372>/S-Function' */
    ID_Translation_Model_117_517_572_67_18,/* '<S380>/S-Function' */
    ID_Translation_Model_117_517_573_67_18,/* '<S384>/S-Function' */
    ID_Translation_Model_117_517_577,  /* '<S386>/S-Function' */
    ID_Translation_Model_117_517_582_67_18,/* '<S391>/S-Function' */
    ID_Translation_Model_117_517_553_67_18,/* '<S395>/S-Function' */
    ID_Translation_Model_117_2074,     /* '<S409>/S-Function' */
    ID_Translation_Model_117_2078_67_18,/* '<S414>/S-Function' */
    ID_Translation_Model_117_2079_67_18,/* '<S418>/S-Function' */
    ID_Translation_Model_117_2082,     /* '<S420>/S-Function' */
    ID_Translation_Model_117_2086_67_18,/* '<S425>/S-Function' */
    ID_Translation_Model_117_2087_67_18,/* '<S429>/S-Function' */
    ID_Translation_Model_117_2093,     /* '<S432>/S-Function' */
    ID_Translation_Model_117_2099_67_18,/* '<S436>/S-Function' */
    ID_Translation_Model_117_2100_67_18,/* '<S440>/S-Function' */
    ID_Translation_Model_117_2115,     /* '<S445>/S-Function' */
    ID_Translation_Model_117_2121,     /* '<S448>/S-Function' */
    ID_Translation_Model_117_2125_67_18,/* '<S453>/S-Function' */
    ID_Translation_Model_117_2149,     /* '<S460>/S-Function' */
    ID_Translation_Model_117_2155,     /* '<S463>/S-Function' */
    ID_Translation_Model_117_2158_67_18,/* '<S467>/S-Function' */
    ID_Translation_Model_117_2159_67_18,/* '<S471>/S-Function' */
    ID_Translation_Model_120_196,      /* '<S483>/S-Function' */
    ID_Translation_Model_120_446,      /* '<S487>/S-Function' */
    ID_Translation_Model_120_203,      /* '<S489>/S-Function' */
    ID_Translation_Model_120_122_67_18,/* '<S494>/S-Function' */
    ID_Translation_Model_120_123_67_18,/* '<S498>/S-Function' */
    ID_Translation_Model_120_189,      /* '<S500>/S-Function' */
    ID_Translation_Model_120_264,      /* '<S510>/S-Function' */
    ID_Translation_Model_120_514,      /* '<S514>/S-Function' */
    ID_Translation_Model_120_257,      /* '<S516>/S-Function' */
    ID_Translation_Model_120_218_67_18,/* '<S521>/S-Function' */
    ID_Translation_Model_120_219_67_18,/* '<S525>/S-Function' */
    ID_Translation_Model_120_250,      /* '<S527>/S-Function' */
    ID_Translation_Model_120_439,      /* '<S534>/S-Function' */
    ID_Translation_Model_120_422_50_36,/* '<S538>/S-Function' */
    ID_Translation_Model_120_319_67_18,/* '<S543>/S-Function' */
    ID_Translation_Model_123_280,      /* '<S547>/S-Function' */
    ID_Translation_Model_123_281_67_18,/* '<S553>/S-Function' */
    ID_Translation_Model_123_256_67_18,/* '<S557>/S-Function' */
    ID_Translation_Model_135_79,       /* '<S566>/S-Function' */
    ID_Translation_Model_135_81_67_18, /* '<S577>/S-Function' */
    ID_Translation_Model_135_83_67_18, /* '<S581>/S-Function' */
    ID_Translation_Model_135_84_67_18, /* '<S585>/S-Function' */
    ID_Translation_Model_135_143_67_18,/* '<S589>/S-Function' */
    ID_Translation_Model_135_85_67_18, /* '<S593>/S-Function' */
    ID_Translation_Model_135_90,       /* '<S596>/S-Function' */
    ID_Translation_Model_420_67_18,    /* '<S1053>/S-Function' */
    ID_Translation_Model_421_67_18,    /* '<S1057>/S-Function' */
    ID_Translation_Model_874_36,       /* '<S1314>/S-Function' */
    ID_Translation_Model_863,          /* '<S1318>/S-Function' */
    ID_Translation_Model_915_36,       /* '<S1324>/S-Function' */
    ID_Translation_Model_903,          /* '<S1328>/S-Function' */
    ID_Translation_Model_926,          /* '<S1332>/S-Function' */
    ID_Translation_Model_1026,         /* '<S1340>/S-Function' */
    ID_Translation_Model_1063_36,      /* '<S1351>/S-Function' */
    ID_Translation_Model_1052,         /* '<S1355>/S-Function' */
    ID_Translation_Model_1104_36,      /* '<S1361>/S-Function' */
    ID_Translation_Model_1092,         /* '<S1365>/S-Function' */
    ID_Translation_Model_1115,         /* '<S1369>/S-Function' */
    ID_Translation_Model_1215,         /* '<S1377>/S-Function' */
    ID_Translation_Model_831_67_18,    /* '<S1383>/S-Function' */
    ID_Translation_Model_1234,         /* '<S1386>/S-Function' */
    ID_Translation_Model_1475_36,      /* '<S1402>/S-Function' */
    ID_Translation_Model_1310_67_18,   /* '<S1407>/S-Function' */
    ID_Translation_Model_1331,         /* '<S1415>/S-Function' */
    ID_Translation_Model_1338,         /* '<S1419>/S-Function' */
    ID_Translation_Model_1343,         /* '<S1421>/S-Function' */
    ID_Translation_Model_1347_67_18,   /* '<S1426>/S-Function' */
    ID_Translation_Model_1348_67_18,   /* '<S1430>/S-Function' */
    ID_Translation_Model_1351,         /* '<S1432>/S-Function' */
    ID_Translation_Model_1368,         /* '<S1441>/S-Function' */
    ID_Translation_Model_1375,         /* '<S1445>/S-Function' */
    ID_Translation_Model_1380,         /* '<S1447>/S-Function' */
    ID_Translation_Model_1384_67_18,   /* '<S1452>/S-Function' */
    ID_Translation_Model_1385_67_18,   /* '<S1456>/S-Function' */
    ID_Translation_Model_1388,         /* '<S1458>/S-Function' */
    ID_Translation_Model_1405,         /* '<S1467>/S-Function' */
    ID_Translation_Model_1412,         /* '<S1471>/S-Function' */
    ID_Translation_Model_1417,         /* '<S1473>/S-Function' */
    ID_Translation_Model_1421_67_18,   /* '<S1478>/S-Function' */
    ID_Translation_Model_1422_67_18,   /* '<S1482>/S-Function' */
    ID_Translation_Model_1425,         /* '<S1484>/S-Function' */
    ID_Translation_Model_1442,         /* '<S1493>/S-Function' */
    ID_Translation_Model_1449,         /* '<S1497>/S-Function' */
    ID_Translation_Model_1454,         /* '<S1499>/S-Function' */
    ID_Translation_Model_1458_67_18,   /* '<S1504>/S-Function' */
    ID_Translation_Model_1459_67_18,   /* '<S1508>/S-Function' */
    ID_Translation_Model_1462,         /* '<S1510>/S-Function' */
    ID_Translation_Model_1254_7_67_18, /* '<S1529>/S-Function' */
    ID_Translation_Model_1254_8_67_18, /* '<S1533>/S-Function' */
    ID_Translation_Model_1254_9_67_18, /* '<S1537>/S-Function' */
    ID_Translation_Model_1254_72_67_18,/* '<S1541>/S-Function' */
    ID_Translation_Model_1254_74_67_18,/* '<S1545>/S-Function' */
    ID_Translation_Model_1254_75_67_18,/* '<S1549>/S-Function' */
    ID_Translation_Model_1254_76_67_18,/* '<S1553>/S-Function' */
    ID_Translation_Model_1254_99_67_18,/* '<S1557>/S-Function' */
    ID_Translation_Model_1254_85,      /* '<S1559>/S-Function' */
    ID_Translation_Model_1254_53_67_18,/* '<S1566>/S-Function' */
    ID_Translation_Model_1254_54_67_18,/* '<S1570>/S-Function' */
    ID_Translation_Model_1255_44,      /* '<S1574>/S-Function' */
    ID_Translation_Model_1257_276_67_18,/* '<S1581>/S-Function' */
    ID_Translation_Model_1259_139,     /* '<S1583>/S-Function' */
    ID_Translation_Model_1259_192_67_18,/* '<S1590>/S-Function' */
    ID_Translation_Model_1259_190_67_18,/* '<S1594>/S-Function' */
    ID_Translation_Model_1265_7_67_18, /* '<S1612>/S-Function' */
    ID_Translation_Model_1265_8_67_18, /* '<S1616>/S-Function' */
    ID_Translation_Model_1265_9_67_18, /* '<S1620>/S-Function' */
    ID_Translation_Model_1265_72_67_18,/* '<S1624>/S-Function' */
    ID_Translation_Model_1265_74_67_18,/* '<S1628>/S-Function' */
    ID_Translation_Model_1265_75_67_18,/* '<S1632>/S-Function' */
    ID_Translation_Model_1265_76_67_18,/* '<S1636>/S-Function' */
    ID_Translation_Model_1265_99_67_18,/* '<S1640>/S-Function' */
    ID_Translation_Model_1265_85,      /* '<S1642>/S-Function' */
    ID_Translation_Model_1265_53_67_18,/* '<S1649>/S-Function' */
    ID_Translation_Model_1265_54_67_18,/* '<S1653>/S-Function' */
    ID_Translation_Model_1266_44,      /* '<S1657>/S-Function' */
    ID_Translation_Model_1268_276_67_18,/* '<S1664>/S-Function' */
    ID_Translation_Model_1270_139,     /* '<S1666>/S-Function' */
    ID_Translation_Model_1270_192_67_18,/* '<S1673>/S-Function' */
    ID_Translation_Model_1270_190_67_18,/* '<S1677>/S-Function' */
    ID_Translation_Model_1276_7_67_18, /* '<S1695>/S-Function' */
    ID_Translation_Model_1276_8_67_18, /* '<S1699>/S-Function' */
    ID_Translation_Model_1276_9_67_18, /* '<S1703>/S-Function' */
    ID_Translation_Model_1276_72_67_18,/* '<S1707>/S-Function' */
    ID_Translation_Model_1276_74_67_18,/* '<S1711>/S-Function' */
    ID_Translation_Model_1276_75_67_18,/* '<S1715>/S-Function' */
    ID_Translation_Model_1276_76_67_18,/* '<S1719>/S-Function' */
    ID_Translation_Model_1276_99_67_18,/* '<S1723>/S-Function' */
    ID_Translation_Model_1276_85,      /* '<S1725>/S-Function' */
    ID_Translation_Model_1276_53_67_18,/* '<S1732>/S-Function' */
    ID_Translation_Model_1276_54_67_18,/* '<S1736>/S-Function' */
    ID_Translation_Model_1277_44,      /* '<S1740>/S-Function' */
    ID_Translation_Model_1279_276_67_18,/* '<S1747>/S-Function' */
    ID_Translation_Model_1281_139,     /* '<S1749>/S-Function' */
    ID_Translation_Model_1281_192_67_18,/* '<S1756>/S-Function' */
    ID_Translation_Model_1281_190_67_18,/* '<S1760>/S-Function' */
    ID_Translation_Model_1287_7_67_18, /* '<S1778>/S-Function' */
    ID_Translation_Model_1287_8_67_18, /* '<S1782>/S-Function' */
    ID_Translation_Model_1287_9_67_18, /* '<S1786>/S-Function' */
    ID_Translation_Model_1287_72_67_18,/* '<S1790>/S-Function' */
    ID_Translation_Model_1287_74_67_18,/* '<S1794>/S-Function' */
    ID_Translation_Model_1287_75_67_18,/* '<S1798>/S-Function' */
    ID_Translation_Model_1287_76_67_18,/* '<S1802>/S-Function' */
    ID_Translation_Model_1287_99_67_18,/* '<S1806>/S-Function' */
    ID_Translation_Model_1287_85,      /* '<S1808>/S-Function' */
    ID_Translation_Model_1287_53_67_18,/* '<S1815>/S-Function' */
    ID_Translation_Model_1287_54_67_18,/* '<S1819>/S-Function' */
    ID_Translation_Model_1288_44,      /* '<S1823>/S-Function' */
    ID_Translation_Model_1290_276_67_18,/* '<S1830>/S-Function' */
    ID_Translation_Model_1292_139,     /* '<S1832>/S-Function' */
    ID_Translation_Model_1292_192_67_18,/* '<S1839>/S-Function' */
    ID_Translation_Model_1292_190_67_18,/* '<S1843>/S-Function' */
    ID_Translation_Model_291_138_8_67_18,/* '<S1895>/S-Function' */
    ID_Translation_Model_291_138_44_67_18,/* '<S1900>/S-Function' */
    ID_Translation_Model_296_67_18,    /* '<S1904>/S-Function' */
    NUM_TRANSLATION_NUMBERS
};

static int32_T DefValue_PreAmpMedusaDeciRateWiggleFilterDelaySamples[] =
{
    0
};

static int32_T DefValue_PreAmpMedusaDeciRateNearWiggleFilterDelaySamples[] =
{
    0
};

static int32_T DefValue_PreAmpMedusaHoligramFilterAlignmentDelaySamples[] =
{
    0
};

static real32_T DefValue_PreAmpMedusatailCompEQsosCoefficients[] =
{
    1.0F, 1.0F, 1.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 1.0F, 1.0F, 1.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
};

static real32_T DefValue_PreAmpMedusatailCompEQnumStages[] =
{
    1.0F, 1.0F, 1.0F, 1.0F
};

static real_T DefValue_PreAmpMedusaWiggleFilter[] =
{
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0
};

static int32_T DefValue_PreAmpMedusaDeciRateWiggleFilterDelaySamples1[] =
{
    0
};

static int32_T DefValue_PreAmpMedusaDeciRateNearWiggleFilterDelaySamples1[] =
{
    0
};

static real_T DefValue_PreAmpMedusaFullRateMixerBackwardDownmixMax[] =
{
    0.5
};

static real_T DefValue_PreAmpMedusaFullRateMixerBackwardDownmixThreshold[] =
{
    0.5
};

static real_T DefValue_PreAmpMedusaFullRateMixerDownmixWeights_CS[] =
{
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0
};

static real_T DefValue_PreAmpMedusaFullRateMixerDownmixWeights_Left[] =
{
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0
};

static real_T DefValue_PreAmpMedusaFullRateMixerDownmixWeights_Right[] =
{
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0
};

static real_T DefValue_PreAmpMedusaFullRateMixerForwardDownmixThreshold[] =
{
    0.2
};

static real_T DefValue_PreAmpMedusaFullRateMixerForwardDownmixMax[] =
{
    1.0
};

static real_T DefValue_PreAmpMedusaFullRateMixerDetentLevel_CS[] =
{
    1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0
};

static real_T DefValue_PreAmpMedusaFullRateMixerDetentLevel_Left[] =
{
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0
};

static real_T DefValue_PreAmpMedusaFullRateMixerDetentLevel_Right[] =
{
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0
};

static real_T DefValue_PreAmpMedusaFullRateMixerInterpolation_Method[] =
{
    0.0
};

static real_T DefValue_PreAmpMedusaFullRateMixerMaxLevel_CS[] =
{
    2.0, 0.0, 2.0, 0.0, 2.0, 0.0, 0.0, 2.0, 0.0, 2.0, 0.0, 2.0
};

static real_T DefValue_PreAmpMedusaFullRateMixerMaxLevel_Left[] =
{
    2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 0.0, 0.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
    2.0, 0.0, 0.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 0.0, 0.0, 2.0, 2.0
};

static real_T DefValue_PreAmpMedusaFullRateMixerMaxLevel_Right[] =
{
    2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 0.0, 0.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
    2.0, 0.0, 0.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 0.0, 0.0, 2.0, 2.0
};

static real_T DefValue_PreAmpMedusaFullRateMixerMinLevel_CS[] =
{
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
};

static real_T DefValue_PreAmpMedusaFullRateMixerMinLevel_Left[] =
{
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
};

static real_T DefValue_PreAmpMedusaFullRateMixerMinLevel_Right[] =
{
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
};

static real_T DefValue_PreAmpMedusaPremixMonoSurroundPhaseAngle[] =
{
    180.0
};

static real_T DefValue_PreAmpMedusaPremixBackwardDownmixMax[] =
{
    0.5
};

static real_T DefValue_PreAmpMedusaPremixBackwardDownmixThreshold[] =
{
    0.5
};

static real_T DefValue_PreAmpMedusaPremixDownmixWeights_CS[] =
{
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0
};

static real_T DefValue_PreAmpMedusaPremixDownmixWeights_Left[] =
{
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    0.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0
};

static real_T DefValue_PreAmpMedusaPremixDownmixWeights_Right[] =
{
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    0.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0
};

static real_T DefValue_PreAmpMedusaPremixForwardDownmixThreshold[] =
{
    0.2
};

static real_T DefValue_PreAmpMedusaPremixForwardDownmixMax[] =
{
    1.0
};

static real_T DefValue_PreAmpMedusaPremixDetentLevel_CS[] =
{
    1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0,
    1.0, 0.0, 1.0, 0.0, 1.0
};

static real_T DefValue_PreAmpMedusaPremixDetentLevel_Left[] =
{
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    0.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0
};

static real_T DefValue_PreAmpMedusaPremixDetentLevel_Right[] =
{
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    0.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0
};

static real_T DefValue_PreAmpMedusaPremixInterpolation_Method[] =
{
    0.0
};

static real_T DefValue_PreAmpMedusaPremixMaxLevel_CS[] =
{
    2.0, 0.0, 2.0, 0.0, 2.0, 0.0, 2.0, 0.0, 2.0, 0.0, 0.0, 2.0, 0.0, 2.0, 0.0,
    2.0, 0.0, 2.0, 0.0, 2.0
};

static real_T DefValue_PreAmpMedusaPremixMaxLevel_Left[] =
{
    2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 0.0, 0.0, 2.0, 2.0, 2.0, 2.0, 2.0,
    2.0, 2.0, 2.0, 2.0, 2.0, 0.0, 0.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
    0.0, 2.0, 0.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 0.0, 0.0, 2.0, 2.0,
    2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0
};

static real_T DefValue_PreAmpMedusaPremixMaxLevel_Right[] =
{
    2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 0.0, 0.0, 2.0, 2.0, 2.0, 2.0, 2.0,
    2.0, 2.0, 2.0, 2.0, 2.0, 0.0, 0.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
    0.0, 2.0, 0.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 0.0, 0.0, 2.0, 2.0,
    2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0
};

static real_T DefValue_PreAmpMedusaPremixMinLevel_CS[] =
{
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0
};

static real_T DefValue_PreAmpMedusaPremixMinLevel_Left[] =
{
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0
};

static real_T DefValue_PreAmpMedusaPremixMinLevel_Right[] =
{
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0
};

static real_T DefValue_PreAmpMedusaVLSDrvGainsBackwardDownmixMax[] =
{
    0.0
};

static real_T DefValue_PreAmpMedusaVLSDrvGainsBackwardDownmixThreshold[] =
{
    0.5
};

static real_T DefValue_PreAmpMedusaVLSDrvGainsDownmixWeights[] =
{
    1.0, 0.0, 1.0, 0.0, 0.5, 0.0, 0.5, 0.0, 1.0, 0.0, 1.0, 0.0
};

static real_T DefValue_PreAmpMedusaVLSDrvGainsForwardDownmixThreshold[] =
{
    0.2
};

static real_T DefValue_PreAmpMedusaVLSDrvGainsForwardDownmixMax[] =
{
    0.0
};

static real_T DefValue_PreAmpMedusaVLSDrvGainsDetentLevel[] =
{
    1.0, 0.0, 1.0, 0.0, 0.5, 0.0, 0.5, 0.0, 1.0, 0.0, 1.0, 0.0
};

static real_T DefValue_PreAmpMedusaVLSDrvGainsInterpolation_Method[] =
{
    0.0
};

static real_T DefValue_PreAmpMedusaVLSDrvGainsMaxLevel[] =
{
    2.0, 0.0, 2.0, 0.0, 1.0, 0.0, 1.0, 0.0, 2.0, 0.0, 2.0, 0.0
};

static real_T DefValue_PreAmpMedusaVLSDrvGainsMinLevel[] =
{
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
};

static real_T DefValue_PreAmpMedusaVLSPaxGainsBackwardDownmixMax[] =
{
    0.0
};

static real_T DefValue_PreAmpMedusaVLSPaxGainsBackwardDownmixThreshold[] =
{
    0.5
};

static real_T DefValue_PreAmpMedusaVLSPaxGainsDownmixWeights[] =
{
    1.0, 0.0, 1.0, 0.0, 0.5, 0.0, 0.5, 0.0, 1.0, 0.0, 1.0, 0.0
};

static real_T DefValue_PreAmpMedusaVLSPaxGainsForwardDownmixThreshold[] =
{
    0.2
};

static real_T DefValue_PreAmpMedusaVLSPaxGainsForwardDownmixMax[] =
{
    0.0
};

static real_T DefValue_PreAmpMedusaVLSPaxGainsDetentLevel[] =
{
    1.0, 0.0, 1.0, 0.0, 0.5, 0.0, 0.5, 0.0, 1.0, 0.0, 1.0, 0.0
};

static real_T DefValue_PreAmpMedusaVLSPaxGainsInterpolation_Method[] =
{
    0.0
};

static real_T DefValue_PreAmpMedusaVLSPaxGainsMaxLevel[] =
{
    2.0, 0.0, 2.0, 0.0, 1.0, 0.0, 1.0, 0.0, 2.0, 0.0, 2.0, 0.0
};

static real_T DefValue_PreAmpMedusaVLSPaxGainsMinLevel[] =
{
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
};

static real_T
    DefValue_PreAmpMedusaDRHoligramPoolIirTunableConfigsosCoefficients[] =
{
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
};

static real_T DefValue_PreAmpMedusaDRHoligramPoolIirTunableConfignumStages[] =
{
    12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0,
    12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0,
    12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0,
    12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0,
    12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0,
    12.0
};

static real_T DefValue_PreAmpMedusaDRHoligramFIRCoeffs[] =
{
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
};

static uint32_T DefValue_PreAmpMedusaDRHoligramFIRLengths[] =
{
    532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U,
    532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U,
    532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U,
    532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U,
    532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U,
    532U
};

static uint32_T DefValue_PreAmpMedusaDRHoligramPaddedFIRLengths[] =
{
    532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U,
    532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U,
    532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U,
    532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U,
    532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U, 532U,
    532U
};

static uint32_T DefValue_PreAmpMedusaDRHoligramInputMapping[] =
{
    0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U, 16U,
    17U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};

static uint32_T DefValue_PreAmpMedusaDRHoligramOutputMapping[] =
{
    0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U, 16U,
    17U
};

static real_T DefValue_PreAmpMedusaFRHoligramIirConfigsosCoefficients[] =
{
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331
};

static real_T DefValue_PreAmpMedusaFRHoligramIirConfignumStages[] =
{
    8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0,
    8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0
};

static real_T DefValue_PreAmpMedusaHeadrestCompEQFIRCoeffs[] =
{
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0
};

static real_T DefValue_PreAmpMedusaHeadrestCompEQFIRLengths[] =
{
    532.0, 532.0, 532.0, 532.0, 532.0, 532.0, 532.0, 532.0, 532.0, 532.0, 532.0,
    532.0
};

static real_T DefValue_PreAmpMedusaHeadrestCompEQPaddedFIRLengths[] =
{
    532.0, 532.0, 532.0, 532.0, 532.0, 532.0, 532.0, 532.0, 532.0, 532.0, 532.0,
    532.0
};

static real_T DefValue_PreAmpMedusaHeadrestCompEQIirConfigsosCoefficients[] =
{
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 1.9560609584131194, 1.9560609584131194,
    1.9560609584131194, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972,
    0.97803047920655972, 0.97803047920655972, 0.97803047920655972, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 1.9555782403150355, 1.9555782403150355,
    1.9555782403150355, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331,
    0.95654367651120331, 0.95654367651120331, 0.95654367651120331, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0
};

static real_T DefValue_PreAmpMedusaHeadrestCompEQIirConfignumStages[] =
{
    8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0
};

static real_T DefValue_PreAmpMedusaNonHeadrestSpeakerDelaySamples[] =
{
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0
};

static real_T DefValue_PreAmpMedusaHeadrestDrvSpeakerDelaySamples[] =
{
    0.0
};

static real_T DefValue_PreAmpMedusaHeadrestPaxSpeakerDelaySamples[] =
{
    0.0
};

static real_T DefValue_PreAmpMedusaFRHoligramDelaySamples[] =
{
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
};

static real_T DefValue_PreAmpMedusaRoutingMap[] =
{
    0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0,
    14.0, 15.0, 16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0
};

static real32_T DefValue_PreAmpVLSXtalkCancellationIIRsosCoefficients[] =
{
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F,
    1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F,
    1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F,
    1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F,
    1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F,
    1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F,
    1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F,
    1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F,
    1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F,
    1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F,
    1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F,
    1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F,
    1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F,
    1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F,
    1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F,
    1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F,
    1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F,
    1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F,
    1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F,
    1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F,
    1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F, 1.95606101F,
    1.95606101F, 1.95606101F, 1.95606101F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F,
    0.978030503F, 0.978030503F, 0.978030503F, 0.978030503F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
    1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
    1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
    1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
    1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
    1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
    1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
    1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
    1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
    1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
    1.0F, 1.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F,
    1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F,
    1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F,
    1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F,
    1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F,
    1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F,
    1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F,
    1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F,
    1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F,
    1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F,
    1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F,
    1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F,
    1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F,
    1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F,
    1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F,
    1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F,
    1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F,
    1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F,
    1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F,
    1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F,
    1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F, 1.95557821F,
    1.95557821F, 1.95557821F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F,
    0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F,
    0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F,
    0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F,
    0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F,
    0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F,
    0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F,
    0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F,
    0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F,
    0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F,
    0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F,
    0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F,
    0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F,
    0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F,
    0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F,
    0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F,
    0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F,
    0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F,
    0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F,
    0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F,
    0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F,
    0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F,
    0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F,
    0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F,
    0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F, 0.956543684F,
    0.956543684F, 0.956543684F, 0.956543684F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F
};

static real32_T DefValue_PreAmpVLSXtalkCancellationIIRnumStages[] =
{
    8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F,
    8.0F, 8.0F, 8.0F
};

static real_T DefValue_PreAmpVLSXtalkCancellationDelay[] =
{
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0
};

static real_T DefValue_PreAmpVLSGenerationDrvFIRCoeffs[] =
{
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0
};

static real_T DefValue_PreAmpVLSGenerationDrvPaddedFIRLengths[] =
{
    288.0, 288.0, 288.0, 288.0, 288.0, 288.0, 288.0, 288.0, 288.0, 288.0, 288.0,
    288.0, 288.0, 288.0, 288.0, 288.0, 288.0, 288.0, 288.0, 288.0
};

static real_T DefValue_PreAmpVLSGenerationPaxFIRCoeffs[] =
{
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0
};

static real_T DefValue_PreAmpVLSGenerationPaxPaddedFIRLengths[] =
{
    288.0, 288.0, 288.0, 288.0, 288.0, 288.0, 288.0, 288.0, 288.0, 288.0, 288.0,
    288.0, 288.0, 288.0, 288.0, 288.0, 288.0, 288.0, 288.0, 288.0
};

static real_T DefValue_PreAmpBassBoostFrequencyHz[] =
{
    120.0
};

static real_T DefValue_PreAmpBassCutFrequencyHz[] =
{
    120.0
};

static real_T DefValue_PreAmpBassBoostMaximum_dB[] =
{
    20.0
};

static real_T DefValue_PreAmpBassCutMaximum_dB[] =
{
    20.0
};

static real_T DefValue_PreAmpBassOffset[] =
{
    128.0
};

static real_T DefValue_PreAmpBassramptime[] =
{
    30.0
};

static real_T DefValue_PreAmpBassScale[] =
{
    127.0
};

static real_T DefValue_PreAmpMidrangeBoostFrequencyHz[] =
{
    775.0
};

static real_T DefValue_PreAmpMidrangeBoostQValue[] =
{
    0.9
};

static real_T DefValue_PreAmpMidrangeCutFrequencyHz[] =
{
    775.0
};

static real_T DefValue_PreAmpMidrangeCutQValue[] =
{
    0.9
};

static real_T DefValue_PreAmpMidrangeBoostMaximum_dB[] =
{
    20.0
};

static real_T DefValue_PreAmpMidrangeCutMaximum_dB[] =
{
    20.0
};

static real_T DefValue_PreAmpMidrangeOffset[] =
{
    128.0
};

static real_T DefValue_PreAmpMidrangeRampTime[] =
{
    30.0
};

static real_T DefValue_PreAmpMidrangeScale[] =
{
    127.0
};

static real32_T DefValue_PreAmpA[] =
{
    -10.0F
};

static real32_T DefValue_PreAmpG[] =
{
    1.0F
};

static real_T DefValue_PreAmpAnnPred[] =
{
    90.0
};

static real_T DefValue_PreAmpLimiterAttack[] =
{
    10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0,
    10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0,
    10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0,
    10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0
};

static real_T DefValue_PreAmpLimiterDecay[] =
{
    100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0,
    100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0,
    100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0
};

static real_T DefValue_PreAmpLimiterMaxAttack[] =
{
    10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0,
    10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0,
    10.0, 10.0, 10.0, 10.0, 10.0, 10.0
};

static real_T DefValue_PreAmpOffset[] =
{
    6.0
};

static real_T DefValue_PreAmpUpperThreshold[] =
{
    90.0
};

static real_T DefValue_PreAmpTrebleBoostFrequencyHz[] =
{
    4000.0
};

static real_T DefValue_PreAmpTrebleCutFrequencyHz[] =
{
    4000.0
};

static real_T DefValue_PreAmpTrebleBoostMaximum_dB[] =
{
    20.0
};

static real_T DefValue_PreAmpTrebleCutMaximum_dB[] =
{
    20.0
};

static real_T DefValue_PreAmpTrebleOffset[] =
{
    128.0
};

static real_T DefValue_PreAmpTrebleramptime[] =
{
    30.0
};

static real_T DefValue_PreAmpTrebleScale[] =
{
    127.0
};

static real_T DefValue_PostProcessLimiterAttack[] =
{
    10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0,
    10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0,
    10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0
};

static real_T DefValue_PostProcessLimiterThreshold[] =
{
    0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9,
    0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9
};

static real_T DefValue_PostProcessLimiterAttack_low[] =
{
    10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0,
    10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0,
    10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0
};

static real_T DefValue_PostProcessLimiterThreshold_low[] =
{
    0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
    0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5
};

static real_T DefValue_PostProcessLimiterDecay[] =
{
    100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0,
    100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0,
    100.0, 100.0
};

static real_T DefValue_PostProcessLimiterDecay_low[] =
{
    100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0,
    100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0,
    100.0, 100.0
};

static real_T DefValue_PostProcessLimiterMaxAttack[] =
{
    10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0,
    10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0
};

static real_T DefValue_PostProcessLimiterMaxAttack_low[] =
{
    10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0,
    10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0
};

static real_T DefValue_PostProcessMuteRampTime[] =
{
    100.0
};

static real32_T DefValue_PostProcessPostLimiterEqsosCoefficients[] =
{
    1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
    1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
    1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
    1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F
};

static real32_T DefValue_PostProcessPostLimiterEqnumStages[] =
{
    1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
    1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F
};

static real_T DefValue_PostProcessSoftClipperYMax[] =
{
    1.0
};

static real_T DefValue_PostProcessSoftClipperXMin[] =
{
    0.65
};

static real_T DefValue_PostProcessSoftClipperYMaxLow[] =
{
    1.0
};

static real_T DefValue_PostProcessSoftClipperXMinLow[] =
{
    0.65
};

static real_T DefValue_InputSelectRouterCfgMap[] =
{
    1.0, 2.0, 3.0, 4.0, 5.0
};

static real_T DefValue_PreAmpMedusaSurroundOn[] =
{
    0.0
};

static real_T DefValue_PreAmpMedusaBassManagerLeftMixWeights[] =
{
    1.0
};

static real_T DefValue_PreAmpMedusaBassManagerRightMixWeights[] =
{
    1.0
};

static real_T DefValue_PreAmpMedusaBassManagerHpfsosCoefficients[] =
{
    0.98731829245508229, 1.0, 0.98731829245508229, 1.0, 0.0, 0.0,
    -0.98731829245508229, -2.0, -0.98731829245508229, -2.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, -0.98731803587991429,
    -1.9871566970233894, -0.98731803587991429, -1.9871566970233894, 0.0, 0.0,
    0.0, 0.98731854903025029, 0.0, 0.98731854903025029, 0.0, 0.0
};

static real_T DefValue_PreAmpMedusaBassManagerHpfnumStages[] =
{
    2.0, 2.0
};

static real_T DefValue_PreAmpMedusaBassManagerLpfsosCoefficients[] =
{
    2.5657516797168764E-7, 1.0, 2.5657516797168764E-7, 1.0, 0.0, 0.0,
    2.5657516797168764E-7, 2.0, 2.5657516797168764E-7, 2.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, -0.98731803587991429,
    -1.9871566970233894, -0.98731803587991429, -1.9871566970233894, 0.0, 0.0,
    0.0, 0.98731854903025029, 0.0, 0.98731854903025029, 0.0, 0.0
};

static real_T DefValue_PreAmpMedusaBassManagerLpfnumStages[] =
{
    2.0, 2.0
};

static real32_T DefValue_PreAmpMedusaBassManagerGainLfe2C[] =
{
    1.0F
};

static real_T DefValue_PreAmpMedusaDummyTune[] =
{
    1.0
};

static real_T DefValue_PreAmpMedusaDeciRateFdpLsSmoothCutoff[] =
{
    1.44166589555648
};

static real_T DefValue_PreAmpMedusaDeciRateFdpSlowPsdSmoothCutoff[] =
{
    3.03388081591392
};

static real_T DefValue_PreAmpMedusaDeciRateFdpFastPsdSmoothCutoff[] =
{
    21.533203125
};

static real_T DefValue_PreAmpMedusaDeciRateFdpDirectPathSec[] =
{
    0.0232199546485261
};

static real_T DefValue_PreAmpMedusaDeciRateFdpXpMax[] =
{
    0.9
};

static real_T DefValue_PreAmpMedusaDeciRateFdpCoeffsXpMin[] =
{
    0.2
};

static real_T DefValue_PreAmpMedusaDeciRateFdpCoeffsESDUpperbounddB[] =
{
    -2.0
};

static real_T DefValue_PreAmpMedusaDeciRateFdpCoeffsESDLowerbounddB[] =
{
    -10.0
};

static real_T DefValue_PreAmpMedusaDeciRateFdpSpumOverwrite[] =
{
    0.0
};

static real_T DefValue_PreAmpMedusaFullRateFdpLsSmoothCutoff[] =
{
    1.44166589555648
};

static real_T DefValue_PreAmpMedusaFullRateFdpSlowPsdSmoothCutoff[] =
{
    3.03388081591392
};

static real_T DefValue_PreAmpMedusaFullRateFdpFastPsdSmoothCutoff[] =
{
    21.533203125
};

static real_T DefValue_PreAmpMedusaFullRateFdpDirectPathSec[] =
{
    0.0232199546485261
};

static real_T DefValue_PreAmpMedusaFullRateFdpXpMax[] =
{
    0.9
};

static real_T DefValue_PreAmpMedusaFullRateFdpCoeffsXpMax[] =
{
    0.7
};

static real_T DefValue_PreAmpMedusaFullRateFdpCoeffsXpMin[] =
{
    0.2
};

static real_T DefValue_PreAmpMedusaFullRateFdpCoeffsESDUpperbounddB[] =
{
    -2.0
};

static real_T DefValue_PreAmpMedusaFullRateFdpCoeffsESDLowerbounddB[] =
{
    -4.8571
};

static real_T DefValue_PreAmpMedusaFullRateFdpSpumOverwrite[] =
{
    0.0
};

static real_T DefValue_PreAmpMedusaMonoDetectorLevelCutoff[] =
{
    40.0
};

static real_T DefValue_PreAmpMedusaMonoDetectorLSSmoothCutoff[] =
{
    0.25
};

static real_T DefValue_PreAmpMedusaMonoDetectorLSSmoothResetCutoff[] =
{
    40.0
};

static real_T DefValue_PreAmpMedusaMonoDetectorHPFCutoff[] =
{
    1000.0
};

static real_T DefValue_PreAmpMedusaMonoDetectorNoiseFloordB[] =
{
    -100.0
};

static real_T DefValue_PreAmpMedusaMonoDetectorLRMatchTolerancedB[] =
{
    0.5
};

static real_T DefValue_PreAmpMedusaMonoDetectorThresholdMonoInput[] =
{
    0.995
};

static real_T DefValue_PreAmpMedusaMonoDetectorThresholdStereoInput[] =
{
    0.99
};

static int32_T DefValue_PreAmpMedusaMonoDetectorEnable[] =
{
    1
};

static real_T DefValue_PreAmpMedusaSPUMDecayEstPSDSmoothCutoff[] =
{
    3.8903810093129221
};

static real_T DefValue_PreAmpMedusaSPUMDecayEstDecaySmoothCutoff[] =
{
    0.13777233653605728
};

static real_T DefValue_PreAmpMedusaSPUMDecayEstFastAttackCutoff[] =
{
    8.82141105784354
};

static real_T DefValue_PreAmpMedusaSPUMDecayEstSlowAttackCutoff[] =
{
    0.27692922573026191
};

static real_T DefValue_PreAmpMedusaSPUMDecayEstStepSize[] =
{
    2.0
};

static real_T DefValue_PreAmpMedusaSPUMDecayEstDirectPathSec[] =
{
    0.023219954648526078
};

static real_T DefValue_PreAmpMedusaSPUMDecayEstNoiseFloor[] =
{
    3.0
};

static real_T DefValue_PreAmpMedusaSPUMDecayEstOnsetThreshold[] =
{
    1.875
};

static real_T DefValue_PreAmpMedusaSPUMDecayEstSlewThreshold[] =
{
    0.8
};

static real32_T DefValue_PreAmpMedusaSPUMDecayEstHPFsosCoefficients[] =
{
    0.180821896F, 1.0F, 1.0F, 0.180821896F, 1.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.361643791F, -2.0F, -2.0F, -0.361643791F, -2.0F, -2.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.180821896F, 1.0F, 1.0F, 0.180821896F, 1.0F,
    1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.763918F, -0.860972106F, -1.10388601F,
    -0.763918F, -0.860972106F, -1.10388601F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.158599868F, 0.305797517F, 0.674213946F, 0.158599868F, 0.305797517F,
    0.674213946F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
};

static real32_T DefValue_PreAmpMedusaSPUMDecayEstHPFnumStages[] =
{
    3.0F, 3.0F
};

static real_T DefValue_PreAmpFadeControlBoostDisable[] =
{
    0.0
};

static real_T DefValue_PreAmpFadeControlEnableSilentExtreme[] =
{
    1.0
};

static real_T DefValue_PreAmpFadeControlTable[] =
{
    0.0, 10.0, 31.0, 52.0, 74.0, 95.0, 116.0, 128.0, 138.0, 159.0, 180.0, 202.0,
    223.0, 244.0, 255.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, -30.0, -27.0, -14.0, -7.0, -5.0, -3.0, -1.0, 0.0, -1.0,
    -3.0, -5.0, -7.0, -14.0, -27.0, -30.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
};

static real_T DefValue_PreAmpFadeControloffset[] =
{
    128.0
};

static real_T DefValue_PreAmpFadeControlRampTime[] =
{
    30.0
};

static real_T DefValue_PreAmpFadeRamperDRChannelToRamperMap[] =
{
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0
};

static real_T DefValue_PreAmpFadeRamperDRCutoffHz[] =
{
    120.0
};

static real_T DefValue_PreAmpFadeRamperFRChannelToRamperMap[] =
{
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0
};

static real_T DefValue_PreAmpFadeRamperFRCutoffHz[] =
{
    120.0
};

static real_T DefValue_PreAmpMuteControlRampTime[] =
{
    100.0
};

static real_T DefValue_PreAmpSleepingBeautyDRChannelToRamperMap[] =
{
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0
};

static real_T DefValue_PreAmpSleepingBeautyDROffset[] =
{
    128.0
};

static real_T DefValue_PreAmpSleepingBeautyDRRampTime[] =
{
    30.0
};

static real_T DefValue_PreAmpSleepingBeautyDRMutesBass[] =
{
    0.0
};

static real_T DefValue_PreAmpSleepingBeautyDRTaperGainTable[] =
{
    0.0, 10.0, 31.0, 52.0, 74.0, 95.0, 116.0, 128.0, 138.0, 159.0, 180.0, 202.0,
    223.0, 244.0, 255.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, -40.0, -30.0, -20.0, -10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, -10.0, -20.0, -30.0, -40.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0
};

static real_T DefValue_PreAmpSleepingBeautyFRChannelToRamperMap[] =
{
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0
};

static real_T DefValue_PreAmpSleepingBeautyFROffset[] =
{
    128.0
};

static real_T DefValue_PreAmpSleepingBeautyFRRampTime[] =
{
    30.0
};

static real_T DefValue_PreAmpSleepingBeautyFRMutesBass[] =
{
    0.0
};

static real_T DefValue_PreAmpSleepingBeautyFRTaperGainTable[] =
{
    0.0, 10.0, 31.0, 52.0, 74.0, 95.0, 116.0, 128.0, 138.0, 159.0, 180.0, 202.0,
    223.0, 244.0, 255.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, -40.0, -30.0, -20.0, -10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, -10.0, -20.0, -30.0, -40.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0
};

static real_T DefValue_PreAmpAudiopilotTwoDowngrade[] =
{
    0.0
};

static real32_T DefValue_PreAmpAudiopilotHvacTable[] =
{
    0.0F, 0.0666666701F, 0.13333334F, 0.2F, 0.266666681F, 0.333333343F, 0.4F,
    0.466666669F, 0.533333361F, 0.6F, 0.666666687F, 0.733333349F, 0.8F,
    0.866666675F, 0.933333337F, 1.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F,
    60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F
};

static real32_T DefValue_PreAmpAudiopilotAntiZipperRampFreqHz[] =
{
    200.0F
};

static real32_T DefValue_PreAmpAudiopilotBassBpfCenterFreqHz[] =
{
    40.0F
};

static real32_T DefValue_PreAmpAudiopilotBassBpfQ[] =
{
    1.1F
};

static real32_T DefValue_PreAmpAudiopilotMidrangeLpfCutoffFreqHz[] =
{
    4000.0F
};

static real32_T DefValue_PreAmpAudiopilotMidrangeLpfAlignDelaySamples[] =
{
    4.0F
};

static real32_T DefValue_PreAmpAudiopilotAudiopilotOn[] =
{
    1.0F
};

static real32_T DefValue_PreAmpAudiopilotBassSlope0Dbperdb[] =
{
    0.65F
};

static real32_T DefValue_PreAmpAudiopilotMidrangeSlope0DbPerDb[] =
{
    0.52F
};

static real32_T DefValue_PreAmpAudiopilotTrebleSlope0DbPerDb[] =
{
    0.35F
};

static real32_T DefValue_PreAmpAudiopilotBassSlope1DbPerDb[] =
{
    0.75F
};

static real32_T DefValue_PreAmpAudiopilotMidrangeSlope1DbPerDb[] =
{
    0.8F
};

static real32_T DefValue_PreAmpAudiopilotTrebleSlope1DbPerDb[] =
{
    0.5F
};

static real32_T DefValue_PreAmpAudiopilotBassThresh0Db[] =
{
    -3.0F
};

static real32_T DefValue_PreAmpAudiopilotBassThresh1Db[] =
{
    -4.0F
};

static real32_T DefValue_PreAmpAudiopilotHfNoiseHighBoundDbspl[] =
{
    30.0F
};

static real32_T DefValue_PreAmpAudiopilotHfNoiseLowBoundDbspl[] =
{
    20.0F
};

static real32_T DefValue_PreAmpAudiopilotLfNoiseHighBoundDbspl[] =
{
    88.0F
};

static real32_T DefValue_PreAmpAudiopilotLfNoiseLowBoundDbspl[] =
{
    83.0F
};

static real32_T DefValue_PreAmpAudiopilotMidrangeThresh0Db[] =
{
    -4.5F
};

static real32_T DefValue_PreAmpAudiopilotMidrangeThresh1Db[] =
{
    -5.5F
};

static real32_T DefValue_PreAmpAudiopilotTrebleThresh0Db[] =
{
    -7.0F
};

static real32_T DefValue_PreAmpAudiopilotTrebleThresh1Db[] =
{
    -7.5F
};

static real32_T DefValue_PreAmpAudiopilotBassDownwardThreshDbspl[] =
{
    40.0F
};

static real32_T DefValue_PreAmpAudiopilotBassMaxAudiopilotBoostDb[] =
{
    20.0F
};

static real32_T DefValue_PreAmpAudiopilotBassMaxDyneqBoostDb[] =
{
    20.0F
};

static real32_T DefValue_PreAmpAudiopilotBassMaxTotalBoostDb[] =
{
    40.0F
};

static real32_T DefValue_PreAmpAudiopilotDownwardExpansionOn[] =
{
    0.0F
};

static real32_T DefValue_PreAmpAudiopilotMidrangeDownwardSlopeDbPerDb[] =
{
    1.0F
};

static real32_T DefValue_PreAmpAudiopilotBassDownwardSlopeDbPerDb[] =
{
    1.25F
};

static real32_T DefValue_PreAmpAudiopilotTrebleDownwardSlopeDbPerDb[] =
{
    1.0F
};

static real32_T DefValue_PreAmpAudiopilotDyneqBassThreshDbspl[] =
{
    95.0F
};

static real32_T DefValue_PreAmpAudiopilotDyneqBassSlopeDbPerDb[] =
{
    0.35F
};

static real32_T DefValue_PreAmpAudiopilotDyneqOn[] =
{
    1.0F
};

static real32_T DefValue_PreAmpAudiopilotMinSignalLevelDbspl[] =
{
    40.0F
};

static real32_T DefValue_PreAmpAudiopilotMidrangeDownwardThreshDbspl[] =
{
    40.0F
};

static real32_T DefValue_PreAmpAudiopilotMidrangeMaxTotalBoostDb[] =
{
    20.0F
};

static real32_T DefValue_PreAmpAudiopilotTrebleDownwardThreshDbspl[] =
{
    43.0F
};

static real32_T DefValue_PreAmpAudiopilotTrebleMaxTotalBoostDb[] =
{
    14.0F
};

static real32_T DefValue_PreAmpAudiopilotEnableRampTauS[] =
{
    0.1F
};

static real32_T DefValue_PreAmpAudiopilotHfNoiseRefPowerMinDb[] =
{
    -160.0F
};

static real32_T
    DefValue_PreAmpAudiopilotHfNoiseImpulseRejectionMinstatAlphaFactor[] =
{
    0.96F
};

static real32_T DefValue_PreAmpAudiopilotHfNoiseImpulseRejectionMinstatAlphaMin[]
    =
{
    0.2F
};

static real32_T DefValue_PreAmpAudiopilotHfNoiseImpulseRejectionMinstatBeta[] =
{
    0.7F
};

static real32_T DefValue_PreAmpAudiopilotHfNoiseImpulseRejectionMinstatMin[] =
{
    0.7F
};

static real32_T
    DefValue_PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessHighIndex[] =
{
    40.0F
};

static real32_T
    DefValue_PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessLowIndex[] =
{
    10.0F
};

static real32_T DefValue_PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessThresh[]
    =
{
    0.9F
};

static real32_T DefValue_PreAmpAudiopilotHfNoiseImpulseRejectionMinSearchCoef[] =
{
    0.7F
};

static real32_T
    DefValue_PreAmpAudiopilotHfNoiseImpulseRejectionMinSearchMinGain[] =
{
    2.12F
};

static real32_T DefValue_PreAmpAudiopilotHfNoiseImpulseRejectionSubWinTimeS[] =
{
    1.0F
};

static real32_T DefValue_PreAmpAudiopilotHfNoiseImpulseRejectionLevelUpdateCoef[]
    =
{
    0.07F
};

static real32_T DefValue_PreAmpAudiopilotHfNoiseSlewAttackDbPerS[] =
{
    3.0F
};

static real32_T DefValue_PreAmpAudiopilotHfNoiseSlewDecayDbPerS[] =
{
    -12.0F
};

static real32_T DefValue_PreAmpAudiopilotHfNoiseSlewThresholdDb[] =
{
    2.0F
};

static real32_T DefValue_PreAmpAudiopilotHfNoiseOffsetDb[] =
{
    72.0F
};

static real32_T
    DefValue_PreAmpAudiopilotHfNoisePreprocessAntiAliassosCoefficients[] =
{
    0.0034983512F, 1.0F, 0.0034983512F, 1.0F, 0.0034983512F, 1.0F, 0.0034983512F,
    1.0F, 0.0034983512F, 1.0F, -0.00475919526F, -1.86167896F, -0.00475919526F,
    -1.86167896F, -0.00475919526F, -1.86167896F, -0.00475919526F, -1.86167896F,
    -0.00475919526F, -1.86167896F, 0.0034983512F, 1.0F, 0.0034983512F, 1.0F,
    0.0034983512F, 1.0F, 0.0034983512F, 1.0F, 0.0034983512F, 1.0F, 1.0F, 1.0F,
    1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, -1.84952378F, -1.91980386F,
    -1.84952378F, -1.91980386F, -1.84952378F, -1.91980386F, -1.84952378F,
    -1.91980386F, -1.84952378F, -1.91980386F, 0.86048317F, 0.949717343F,
    0.86048317F, 0.949717343F, 0.86048317F, 0.949717343F, 0.86048317F,
    0.949717343F, 0.86048317F, 0.949717343F
};

static real32_T DefValue_PreAmpAudiopilotHfNoisePreprocessAntiAliasnumStages[] =
{
    2.0F, 2.0F, 2.0F, 2.0F, 2.0F
};

static real32_T
    DefValue_PreAmpAudiopilotHfNoisePreprocessBandpassLowpasssosCoefficients[] =
{
    9.7564957E-8F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 0.00107411703F, 1.0F, 1.0F,
    0.00107411703F, 1.0F, 1.0F, 0.00107411703F, 1.0F, 1.0F, 0.00107411703F, 1.0F,
    1.0F, 1.95129914E-7F, 2.0F, 2.0F, -2.0F, -2.0F, -2.0F, 0.00214823405F, 2.0F,
    2.0F, 0.00214823405F, 2.0F, 2.0F, 0.00214823405F, 2.0F, 2.0F, 0.00214823405F,
    2.0F, 2.0F, 9.7564957E-8F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 0.00107411703F,
    1.0F, 1.0F, 0.00107411703F, 1.0F, 1.0F, 0.00107411703F, 1.0F, 1.0F,
    0.00107411703F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
    1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, -1.38827622F,
    -1.4374969F, -1.36788642F, -1.50163555F, -1.38578272F, -1.56682026F,
    -0.836346388F, -0.93861413F, -1.19082308F, -0.836346388F, -0.93861413F,
    -1.19082308F, -0.836346388F, -0.93861413F, -1.19082308F, -0.836346388F,
    -0.93861413F, -1.19082308F, 0.869090617F, 0.874203324F, 0.899350464F,
    0.909862041F, 0.961295F, 0.966843963F, 0.186740249F, 0.331853926F,
    0.689727843F, 0.186740249F, 0.331853926F, 0.689727843F, 0.186740249F,
    0.331853926F, 0.689727843F, 0.186740249F, 0.331853926F, 0.689727843F
};

static real32_T
    DefValue_PreAmpAudiopilotHfNoisePreprocessBandpassLowpassnumStages[] =
{
    6.0F, 3.0F, 3.0F, 3.0F, 3.0F
};

static real32_T DefValue_PreAmpAudiopilotHfNoiseRefLatencyMs[] =
{
    25.0F
};

static real32_T DefValue_PreAmpAudiopilotLfNoiseEnergyLpfTauS[] =
{
    0.5F
};

static real32_T DefValue_PreAmpAudiopilotLfNoiseImpulseRejectionGamma0TauS[] =
{
    0.75F
};

static real32_T
    DefValue_PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceFiltTauS[] =
{
    1.5F
};

static real32_T
    DefValue_PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceScale[] =
{
    10.0F
};

static real32_T
    DefValue_PreAmpAudiopilotLfNoiseImpulseRejectionMusicVarianceScale[] =
{
    -0.05F
};

static real32_T
    DefValue_PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVarianceScale[] =
{
    0.1F
};

static real32_T DefValue_PreAmpAudiopilotLfNoiseImpulseRejectionOutputMin[] =
{
    0.0001F
};

static real32_T DefValue_PreAmpAudiopilotLfNoiseMicsosCoefficients[] =
{
    0.000157780625F, 1.0F, 1.0F, -0.000314462319F, -1.99897337F, -1.99939823F,
    0.000157780625F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, -1.99280834F, -1.99538469F,
    -1.99838531F, 0.992839098F, 0.995508671F, 0.998585045F
};

static real32_T DefValue_PreAmpAudiopilotLfNoiseMicnumStages[] =
{
    3.0F
};

static real32_T DefValue_PreAmpAudiopilotLfNoiseRefsosCoefficients[] =
{
    0.000157780625F, 1.0F, 1.0F, -0.000314462319F, -1.99897337F, -1.99939823F,
    0.000157780625F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, -1.99280834F, -1.99538469F,
    -1.99838531F, 0.992839098F, 0.995508671F, 0.998585045F
};

static real32_T DefValue_PreAmpAudiopilotLfNoiseRefnumStages[] =
{
    3.0F
};

static real32_T DefValue_PreAmpAudiopilotLfNoiseOffsetDb[] =
{
    0.0F
};

static real32_T DefValue_PreAmpAudiopilotLfNoiseRefLatencyMs[] =
{
    70.0F
};

static real32_T DefValue_PreAmpAudiopilotLfNoiseSlewAttackDbPerS[] =
{
    3.0F
};

static real32_T DefValue_PreAmpAudiopilotLfNoiseSlewDecayDbPerS[] =
{
    -12.0F
};

static real32_T DefValue_PreAmpAudiopilotLfNoiseSlewSlowDbPerS[] =
{
    0.5F
};

static real32_T DefValue_PreAmpAudiopilotLfNoiseSlewThresholdDb[] =
{
    3.0F
};

static real32_T DefValue_PreAmpAudiopilotLfNoiseSpeedBoundsAxis[] =
{
    0.0F, 4.0F, 8.0F, 12.0F, 16.0F, 20.0F, 24.0F, 28.0F, 32.0F, 36.0F, 40.0F,
    44.0F, 48.0F, 52.0F, 56.0F, 60.0F, 64.0F, 68.0F, 72.0F, 76.0F, 80.0F, 84.0F,
    88.0F, 92.0F, 96.0F, 100.0F, 104.0F, 108.0F, 112.0F, 116.0F, 120.0F, 124.0F,
    128.0F, 132.0F, 136.0F, 140.0F, 144.0F, 148.0F, 152.0F, 156.0F, 160.0F,
    164.0F, 168.0F, 172.0F, 176.0F, 180.0F, 184.0F, 188.0F, 192.0F, 196.0F,
    200.0F, 204.0F, 208.0F, 212.0F, 216.0F, 220.0F, 224.0F, 228.0F, 232.0F,
    236.0F, 240.0F, 244.0F, 248.0F, 252.0F, 256.0F, 260.0F, 264.0F, 268.0F,
    272.0F, 276.0F, 280.0F, 284.0F, 288.0F, 292.0F, 296.0F, 300.0F, 304.0F,
    308.0F, 312.0F, 316.0F, 320.0F, 324.0F, 328.0F, 332.0F, 336.0F, 340.0F,
    344.0F, 348.0F, 352.0F, 356.0F, 360.0F, 364.0F, 368.0F, 372.0F, 376.0F,
    380.0F, 384.0F, 388.0F, 392.0F, 396.0F, 400.0F, 404.0F, 408.0F, 412.0F,
    416.0F, 420.0F, 424.0F, 428.0F, 432.0F, 436.0F, 440.0F, 444.0F, 448.0F,
    452.0F, 456.0F, 460.0F, 464.0F, 468.0F, 472.0F, 476.0F, 480.0F, 484.0F,
    488.0F, 492.0F, 496.0F, 500.0F, 504.0F, 508.0F
};

static real32_T DefValue_PreAmpAudiopilotLfNoiseSpeedBoundsMaxDbspl[] =
{
    3.0F, 6.0F, 9.0F, 12.0F, 15.0F, 18.0F, 21.0F, 24.0F, 27.0F, 30.0F, 33.0F,
    36.0F, 39.0F, 42.0F, 45.0F, 48.0F, 51.0F, 54.0F, 57.0F, 60.0F, 63.0F, 66.0F,
    69.0F, 72.0F, 75.0F, 78.0F, 81.0F, 84.0F, 87.0F, 90.0F, 93.0F, 96.0F, 99.0F,
    102.0F, 105.0F, 108.0F, 111.0F, 114.0F, 117.0F, 120.0F, 123.0F, 126.0F,
    129.0F, 132.0F, 135.0F, 138.0F, 141.0F, 144.0F, 147.0F, 150.0F, 153.0F,
    156.0F, 159.0F, 162.0F, 165.0F, 168.0F, 171.0F, 174.0F, 177.0F, 180.0F,
    183.0F, 186.0F, 189.0F, 192.0F, 195.0F, 198.0F, 201.0F, 204.0F, 207.0F,
    210.0F, 213.0F, 216.0F, 219.0F, 222.0F, 225.0F, 228.0F, 231.0F, 234.0F,
    237.0F, 240.0F, 243.0F, 246.0F, 249.0F, 252.0F, 255.0F, 258.0F, 261.0F,
    264.0F, 267.0F, 270.0F, 273.0F, 276.0F, 279.0F, 282.0F, 285.0F, 288.0F,
    291.0F, 294.0F, 297.0F, 300.0F, 303.0F, 306.0F, 309.0F, 312.0F, 315.0F,
    318.0F, 321.0F, 324.0F, 327.0F, 330.0F, 333.0F, 336.0F, 339.0F, 342.0F,
    345.0F, 348.0F, 351.0F, 354.0F, 357.0F, 360.0F, 363.0F, 366.0F, 369.0F,
    372.0F, 375.0F, 378.0F, 381.0F, 384.0F
};

static real32_T DefValue_PreAmpAudiopilotLfNoiseSpeedBoundsMindBSPL[] =
{
    3.0F, 6.0F, 9.0F, 12.0F, 15.0F, 18.0F, 21.0F, 24.0F, 27.0F, 30.0F, 33.0F,
    36.0F, 39.0F, 42.0F, 45.0F, 48.0F, 51.0F, 54.0F, 57.0F, 60.0F, 63.0F, 66.0F,
    69.0F, 72.0F, 75.0F, 78.0F, 81.0F, 84.0F, 87.0F, 90.0F, 93.0F, 96.0F, 99.0F,
    102.0F, 105.0F, 108.0F, 111.0F, 114.0F, 117.0F, 120.0F, 123.0F, 126.0F,
    129.0F, 132.0F, 135.0F, 138.0F, 141.0F, 144.0F, 147.0F, 150.0F, 153.0F,
    156.0F, 159.0F, 162.0F, 165.0F, 168.0F, 171.0F, 174.0F, 177.0F, 180.0F,
    183.0F, 186.0F, 189.0F, 192.0F, 195.0F, 198.0F, 201.0F, 204.0F, 207.0F,
    210.0F, 213.0F, 216.0F, 219.0F, 222.0F, 225.0F, 228.0F, 231.0F, 234.0F,
    237.0F, 240.0F, 243.0F, 246.0F, 249.0F, 252.0F, 255.0F, 258.0F, 261.0F,
    264.0F, 267.0F, 270.0F, 273.0F, 276.0F, 279.0F, 282.0F, 285.0F, 288.0F,
    291.0F, 294.0F, 297.0F, 300.0F, 303.0F, 306.0F, 309.0F, 312.0F, 315.0F,
    318.0F, 321.0F, 324.0F, 327.0F, 330.0F, 333.0F, 336.0F, 339.0F, 342.0F,
    345.0F, 348.0F, 351.0F, 354.0F, 357.0F, 360.0F, 363.0F, 366.0F, 369.0F,
    372.0F, 375.0F, 378.0F, 381.0F, 384.0F
};

static real32_T DefValue_PreAmpAudiopilotLfNoiseSpeedBoundsOn[] =
{
    1.0F
};

static real32_T DefValue_PreAmpAudiopilotLfNoiseSysMaxDbspl[] =
{
    120.0F
};

static real32_T DefValue_PreAmpAudiopilotRatioUpdateFlagHoldTimeS[] =
{
    6.0F
};

static real32_T DefValue_PreAmpAudiopilotRatioUpdateHfNoiseThreshDbspl[] =
{
    30.0F
};

static real32_T DefValue_PreAmpAudiopilotRatioUpdateLfNoiseThreshDbspl[] =
{
    60.0F
};

static real32_T DefValue_PreAmpAudiopilotRatioUpdateLfNoiseUpdatePeriodS[] =
{
    1.5F
};

static real32_T DefValue_PreAmpAudiopilotRatioUpdateLfNoiseUpdateThreshDb[] =
{
    2.0F
};

static real32_T DefValue_PreAmpAudiopilotRatioUpdateSpeedUpdateThreshMph[] =
{
    40.0F
};

static real32_T DefValue_PreAmpAudiopilotRatioEnergyLpfTauS[] =
{
    0.2F
};

static real32_T DefValue_PreAmpAudiopilotRatioHighBoundDb[] =
{
    60.0F
};

static real32_T DefValue_PreAmpAudiopilotRatioLowBoundDb[] =
{
    50.0F
};

static real32_T DefValue_PreAmpAudiopilotRatioSlewAttackDbPerS[] =
{
    3.0F
};

static real32_T DefValue_PreAmpAudiopilotRatioSlewDecayDbPerS[] =
{
    -12.0F
};

static real32_T DefValue_PreAmpAudiopilotRatioSlewThresholdDb[] =
{
    1.0F
};

static real32_T DefValue_PreAmpAudiopilotRatioImpulseRejectionGamma0TauS[] =
{
    1.5F
};

static real32_T
    DefValue_PreAmpAudiopilotRatioImpulseRejectionImpulseVarianceLpfTauS[] =
{
    0.2F
};

static real32_T
    DefValue_PreAmpAudiopilotRatioImpulseRejectionImpulseVarianceScale[] =
{
    100.0F
};

static real32_T
    DefValue_PreAmpAudiopilotRatioImpulseRejectionNoiseVarianceScale[] =
{
    0.1F
};

static real32_T DefValue_PreAmpAudiopilotLevelDetectFastDecayDbPerS[] =
{
    5.0F
};

static real32_T DefValue_PreAmpAudiopilotLevelDetectHoldMarginDb[] =
{
    6.0F
};

static real32_T DefValue_PreAmpAudiopilotLevelDetectHoldTimeS[] =
{
    3.0F
};

static real32_T DefValue_PreAmpAudiopilotLevelDetectMaxVolumeDb[] =
{
    0.0F
};

static real32_T DefValue_PreAmpAudiopilotLevelDetectMinVolumeDb[] =
{
    -80.0F
};

static real32_T DefValue_PreAmpAudiopilotLevelDetectSlowDecayDbPerS[] =
{
    0.1F
};

static real32_T DefValue_PreAmpDyneqLevelDetectFastDecayDbPerS[] =
{
    5.0F
};

static real32_T DefValue_PreAmpDyneqLevelDetectHoldMarginDb[] =
{
    6.0F
};

static real32_T DefValue_PreAmpDyneqLevelDetectHoldTimeS[] =
{
    3.0F
};

static real32_T DefValue_PreAmpDyneqLevelDetectMaxVolumeDb[] =
{
    0.0F
};

static real32_T DefValue_PreAmpDyneqLevelDetectMinVolumeDb[] =
{
    -80.0F
};

static real32_T DefValue_PreAmpDyneqLevelDetectSlowDecayDbPerS[] =
{
    0.1F
};

static real32_T DefValue_PreAmpLevelDetectLatencyMs[] =
{
    1.5F
};

static real32_T DefValue_PreAmpLevelDetectPreemphasissosCoefficients[] =
{
    0.997677922F, 0.997677922F, -1.97744F, -1.97744F, 0.97992152F, 0.97992152F,
    1.0F, 1.0F, -1.97739339F, -1.97739339F, 0.977646053F, 0.977646053F
};

static real32_T DefValue_PreAmpLevelDetectPreemphasisnumStages[] =
{
    1.0F, 1.0F
};

static real32_T DefValue_PreAmpLevelDetectSysMaxDbspl[] =
{
    123.0F
};

static real_T DefValue_PreAmpVolumeCfgTable[] =
{
    0.0, 0.5, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, -100.0, -30.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0
};

static real_T DefValue_PreAmpVolumeCfgmaxgain[] =
{
    0.0
};

static real_T DefValue_PreAmpVolumeCfgRampTime[] =
{
    100.0
};

static real_T DefValue_PreAmpBalance_CfgChanRampMap[] =
{
    1.0, 2.0
};

static real_T DefValue_PreAmpBalance_CfgBoostDisable[] =
{
    0.0
};

static real_T DefValue_PreAmpBalance_CfgOffset[] =
{
    128.0
};

static real_T DefValue_PreAmpBalance_CfgRampTime[] =
{
    30.0
};

static real_T DefValue_PreAmpBalance_CfgSleepingBeautyMutesBass[] =
{
    1.0
};

static real_T DefValue_PreAmpBalance_CfgEnableSilentExtreme[] =
{
    1.0
};

static real_T DefValue_PreAmpBalance_CfgTable[] =
{
    0.0, 10.0, 31.0, 52.0, 74.0, 95.0, 116.0, 128.0, 138.0, 159.0, 180.0, 202.0,
    223.0, 244.0, 255.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, -30.0, -27.0, -14.0, -7.0, -5.0, -3.0, -1.0, 0.0, -1.0,
    -3.0, -5.0, -7.0, -14.0, -27.0, -30.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
};

static real_T DefValue_PreAmpNearWiggleCoeffs[] =
{
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
};

static real_T DefValue_PreAmpNearDelay[] =
{
    1024.0
};

static real_T DefValue_NearDr_PooliirsosCoefficients[] =
{
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
};

static real_T DefValue_NearDr_PooliirnumStages[] =
{
    14.0, 14.0, 14.0, 14.0, 14.0, 14.0, 14.0
};

static real32_T DefValue_NearDr_f1_del[] =
{
    0.0F
};

static real32_T DefValue_NearDr_f2_del[] =
{
    0.0F
};

static real32_T DefValue_NearDr_f3_del[] =
{
    0.0F
};

static real32_T DefValue_NearDr_f4_del[] =
{
    0.0F
};

static real32_T DefValue_NearDr_f5_del[] =
{
    0.0F
};

static real32_T DefValue_NearDr_f6_del[] =
{
    0.0F
};

static real32_T DefValue_NearDr_f7_del[] =
{
    0.0F
};

static real_T DefValue_NearDr_PoolIirTunablesosCoefficients[] =
{
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
};

static real_T DefValue_NearDr_PoolIirTunablenumStages[] =
{
    25.0, 25.0, 25.0, 25.0
};

static real32_T DefValue_NearDr_driver_src1[] =
{
    0.0F
};

static real32_T DefValue_NearDr_driver_src2[] =
{
    0.0F
};

static real32_T DefValue_NearDr_driver_src3[] =
{
    0.0F
};

static real32_T DefValue_NearDr_driver_src4[] =
{
    0.0F
};

static real32_T DefValue_NearDr_passenger_src1[] =
{
    0.0F
};

static real32_T DefValue_NearDr_passenger_src2[] =
{
    0.0F
};

static real32_T DefValue_NearDr_passenger_src3[] =
{
    0.0F
};

static real32_T DefValue_NearDr_passenger_src4[] =
{
    0.0F
};

static real_T DefValue_NearDr_RouterMap[] =
{
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0
};

static real32_T DefValue_NearDr_f1_mix[] =
{
    4.0F, 3.0F, 2.0F, 1.0F, 0.0F, 3.0F, 2.25F, 1.5F, 0.75F, 0.0F, 2.0F, 1.5F,
    1.0F, 0.5F, 0.0F, 1.0F, 0.75F, 0.5F, 0.25F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F
};

static real32_T DefValue_NearDr_f2_mix[] =
{
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.75F, 0.5F, 0.25F, 0.0F, 2.0F, 1.5F,
    1.0F, 0.5F, 0.0F, 3.0F, 2.25F, 1.5F, 0.75F, 0.0F, 4.0F, 3.0F, 2.0F, 1.0F,
    0.0F
};

static real32_T DefValue_NearDr_f3_mix[] =
{
    0.0F, 1.0F, 2.0F, 3.0F, 4.0F, 0.0F, 0.75F, 1.5F, 2.25F, 3.0F, 0.0F, 0.5F,
    1.0F, 1.5F, 2.0F, 0.0F, 0.25F, 0.5F, 0.75F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F
};

static real32_T DefValue_NearDr_f4_mix[] =
{
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.25F, 0.5F, 0.75F, 1.0F, 0.0F, 0.5F,
    1.0F, 1.5F, 2.0F, 0.0F, 0.75F, 1.5F, 2.25F, 3.0F, 0.0F, 1.0F, 2.0F, 3.0F,
    4.0F
};

static real32_T DefValue_NearDr_f5_mix[] =
{
    9.0F, 8.0F, 7.0F, 6.0F, 5.0F, 8.0F, 7.25F, 6.5F, 5.75F, 5.0F, 7.0F, 6.5F,
    6.0F, 5.5F, 5.0F, 6.0F, 5.75F, 5.5F, 5.25F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F,
    5.0F
};

static real32_T DefValue_NearDr_f6_mix[] =
{
    5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 6.0F, 5.75F, 5.5F, 5.25F, 5.0F, 7.0F, 6.5F,
    6.0F, 5.5F, 5.0F, 8.0F, 7.25F, 6.5F, 5.75F, 5.0F, 9.0F, 8.0F, 7.0F, 6.0F,
    5.0F
};

static real32_T DefValue_NearDr_f7_mix[] =
{
    5.0F, 6.0F, 7.0F, 8.0F, 9.0F, 5.0F, 5.75F, 6.5F, 7.25F, 8.0F, 5.0F, 5.5F,
    6.0F, 6.5F, 7.0F, 5.0F, 5.25F, 5.5F, 5.75F, 6.0F, 5.0F, 5.0F, 5.0F, 5.0F,
    5.0F
};

static real32_T DefValue_NearDr_LFI0_mix[] =
{
    5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.25F, 5.5F, 5.75F, 6.0F, 5.0F, 5.5F,
    6.0F, 6.5F, 7.0F, 5.0F, 5.75F, 6.5F, 7.25F, 8.0F, 5.0F, 6.0F, 7.0F, 8.0F,
    9.0F
};

static real32_T DefValue_NearDr_LFT0_mix[] =
{
    14.0F, 13.0F, 12.0F, 11.0F, 10.0F, 13.0F, 12.25F, 11.5F, 10.75F, 10.0F,
    12.0F, 11.5F, 11.0F, 10.5F, 10.0F, 11.0F, 10.75F, 10.5F, 10.25F, 10.0F,
    10.0F, 10.0F, 10.0F, 10.0F, 10.0F
};

static real32_T DefValue_NearDr_RFI0_mix[] =
{
    10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 11.0F, 10.75F, 10.5F, 10.25F, 10.0F,
    12.0F, 11.5F, 11.0F, 10.5F, 10.0F, 13.0F, 12.25F, 11.5F, 10.75F, 10.0F,
    14.0F, 13.0F, 12.0F, 11.0F, 10.0F
};

static real32_T DefValue_NearDr_RFT0_mix[] =
{
    10.0F, 11.0F, 12.0F, 13.0F, 14.0F, 10.0F, 10.75F, 11.5F, 12.25F, 13.0F,
    10.0F, 10.5F, 11.0F, 11.5F, 12.0F, 10.0F, 10.25F, 10.5F, 10.75F, 11.0F,
    10.0F, 10.0F, 10.0F, 10.0F, 10.0F
};

static real32_T DefValue_NearDr_LSI0_mix[] =
{
    10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.25F, 10.5F, 10.75F, 11.0F,
    10.0F, 10.5F, 11.0F, 11.5F, 12.0F, 10.0F, 10.75F, 11.5F, 12.25F, 13.0F,
    10.0F, 11.0F, 12.0F, 13.0F, 14.0F
};

static real32_T DefValue_NearDr_LST0_mix[] =
{
    19.0F, 18.0F, 17.0F, 16.0F, 15.0F, 18.0F, 17.25F, 16.5F, 15.75F, 15.0F,
    17.0F, 16.5F, 16.0F, 15.5F, 15.0F, 16.0F, 15.75F, 15.5F, 15.25F, 15.0F,
    15.0F, 15.0F, 15.0F, 15.0F, 15.0F
};

static real32_T DefValue_NearDr_RSI0_mix[] =
{
    15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 16.0F, 15.75F, 15.5F, 15.25F, 15.0F,
    17.0F, 16.5F, 16.0F, 15.5F, 15.0F, 18.0F, 17.25F, 16.5F, 15.75F, 15.0F,
    19.0F, 18.0F, 17.0F, 16.0F, 15.0F
};

static real32_T DefValue_NearDr_RST0_mix[] =
{
    15.0F, 16.0F, 17.0F, 18.0F, 19.0F, 15.0F, 15.75F, 16.5F, 17.25F, 18.0F,
    15.0F, 15.5F, 16.0F, 16.5F, 17.0F, 15.0F, 15.25F, 15.5F, 15.75F, 16.0F,
    15.0F, 15.0F, 15.0F, 15.0F, 15.0F
};

static real32_T DefValue_NearDr_LCI0_mix[] =
{
    15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.25F, 15.5F, 15.75F, 16.0F,
    15.0F, 15.5F, 16.0F, 16.5F, 17.0F, 15.0F, 15.75F, 16.5F, 17.25F, 18.0F,
    15.0F, 16.0F, 17.0F, 18.0F, 19.0F
};

static real32_T DefValue_NearDr_LCT0_mix[] =
{
    24.0F, 23.0F, 22.0F, 21.0F, 20.0F, 23.0F, 22.25F, 21.5F, 20.75F, 20.0F,
    22.0F, 21.5F, 21.0F, 20.5F, 20.0F, 21.0F, 20.75F, 20.5F, 20.25F, 20.0F,
    20.0F, 20.0F, 20.0F, 20.0F, 20.0F
};

static real32_T DefValue_NearDr_RCI0_mix[] =
{
    20.0F, 20.0F, 20.0F, 20.0F, 20.0F, 21.0F, 20.75F, 20.5F, 20.25F, 20.0F,
    22.0F, 21.5F, 21.0F, 20.5F, 20.0F, 23.0F, 22.25F, 21.5F, 20.75F, 20.0F,
    24.0F, 23.0F, 22.0F, 21.0F, 20.0F
};

static real32_T DefValue_NearDr_RCT0_mix[] =
{
    20.0F, 21.0F, 22.0F, 23.0F, 24.0F, 20.0F, 20.75F, 21.5F, 22.25F, 23.0F,
    20.0F, 20.5F, 21.0F, 21.5F, 22.0F, 20.0F, 20.25F, 20.5F, 20.75F, 21.0F,
    20.0F, 20.0F, 20.0F, 20.0F, 20.0F
};

static real32_T DefValue_NearDr_LFI1_mix[] =
{
    20.0F, 20.0F, 20.0F, 20.0F, 20.0F, 20.0F, 20.25F, 20.5F, 20.75F, 21.0F,
    20.0F, 20.5F, 21.0F, 21.5F, 22.0F, 20.0F, 20.75F, 21.5F, 22.25F, 23.0F,
    20.0F, 21.0F, 22.0F, 23.0F, 24.0F
};

static real32_T DefValue_NearDr_LFT1_mix[] =
{
    29.0F, 28.0F, 27.0F, 26.0F, 25.0F, 28.0F, 27.25F, 26.5F, 25.75F, 25.0F,
    27.0F, 26.5F, 26.0F, 25.5F, 25.0F, 26.0F, 25.75F, 25.5F, 25.25F, 25.0F,
    25.0F, 25.0F, 25.0F, 25.0F, 25.0F
};

static real32_T DefValue_NearDr_RFI1_mix[] =
{
    25.0F, 25.0F, 25.0F, 25.0F, 25.0F, 26.0F, 25.75F, 25.5F, 25.25F, 25.0F,
    27.0F, 26.5F, 26.0F, 25.5F, 25.0F, 28.0F, 27.25F, 26.5F, 25.75F, 25.0F,
    29.0F, 28.0F, 27.0F, 26.0F, 25.0F
};

static real32_T DefValue_NearDr_RFT1_mix[] =
{
    25.0F, 26.0F, 27.0F, 28.0F, 29.0F, 25.0F, 25.75F, 26.5F, 27.25F, 28.0F,
    25.0F, 25.5F, 26.0F, 26.5F, 27.0F, 25.0F, 25.25F, 25.5F, 25.75F, 26.0F,
    25.0F, 25.0F, 25.0F, 25.0F, 25.0F
};

static real32_T DefValue_NearDr_LSI1_mix[] =
{
    25.0F, 25.0F, 25.0F, 25.0F, 25.0F, 25.0F, 25.25F, 25.5F, 25.75F, 26.0F,
    25.0F, 25.5F, 26.0F, 26.5F, 27.0F, 25.0F, 25.75F, 26.5F, 27.25F, 28.0F,
    25.0F, 26.0F, 27.0F, 28.0F, 29.0F
};

static real32_T DefValue_NearDr_LST1_mix[] =
{
    34.0F, 33.0F, 32.0F, 31.0F, 30.0F, 33.0F, 32.25F, 31.5F, 30.75F, 30.0F,
    32.0F, 31.5F, 31.0F, 30.5F, 30.0F, 31.0F, 30.75F, 30.5F, 30.25F, 30.0F,
    30.0F, 30.0F, 30.0F, 30.0F, 30.0F
};

static real32_T DefValue_NearDr_RSI1_mix[] =
{
    30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 31.0F, 30.75F, 30.5F, 30.25F, 30.0F,
    32.0F, 31.5F, 31.0F, 30.5F, 30.0F, 33.0F, 32.25F, 31.5F, 30.75F, 30.0F,
    34.0F, 33.0F, 32.0F, 31.0F, 30.0F
};

static real32_T DefValue_NearDr_RST1_mix[] =
{
    30.0F, 31.0F, 32.0F, 33.0F, 34.0F, 30.0F, 30.75F, 31.5F, 32.25F, 33.0F,
    30.0F, 30.5F, 31.0F, 31.5F, 32.0F, 30.0F, 30.25F, 30.5F, 30.75F, 31.0F,
    30.0F, 30.0F, 30.0F, 30.0F, 30.0F
};

static real32_T DefValue_NearDr_LCI1_mix[] =
{
    30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.25F, 30.5F, 30.75F, 31.0F,
    30.0F, 30.5F, 31.0F, 31.5F, 32.0F, 30.0F, 30.75F, 31.5F, 32.25F, 33.0F,
    30.0F, 31.0F, 32.0F, 33.0F, 34.0F
};

static real32_T DefValue_NearDr_LCT1_mix[] =
{
    39.0F, 38.0F, 37.0F, 36.0F, 35.0F, 38.0F, 37.25F, 36.5F, 35.75F, 35.0F,
    37.0F, 36.5F, 36.0F, 35.5F, 35.0F, 36.0F, 35.75F, 35.5F, 35.25F, 35.0F,
    35.0F, 35.0F, 35.0F, 35.0F, 35.0F
};

static real32_T DefValue_NearDr_RCI1_mix[] =
{
    35.0F, 35.0F, 35.0F, 35.0F, 35.0F, 36.0F, 35.75F, 35.5F, 35.25F, 35.0F,
    37.0F, 36.5F, 36.0F, 35.5F, 35.0F, 38.0F, 37.25F, 36.5F, 35.75F, 35.0F,
    39.0F, 38.0F, 37.0F, 36.0F, 35.0F
};

static real32_T DefValue_NearDr_RCT1_mix[] =
{
    35.0F, 36.0F, 37.0F, 38.0F, 39.0F, 35.0F, 35.75F, 36.5F, 37.25F, 38.0F,
    35.0F, 35.5F, 36.0F, 36.5F, 37.0F, 35.0F, 35.25F, 35.5F, 35.75F, 36.0F,
    35.0F, 35.0F, 35.0F, 35.0F, 35.0F
};

static real32_T DefValue_NearDr_nv0l_mix[] =
{
    35.0F, 35.0F, 35.0F, 35.0F, 35.0F, 35.0F, 35.25F, 35.5F, 35.75F, 36.0F,
    35.0F, 35.5F, 36.0F, 36.5F, 37.0F, 35.0F, 35.75F, 36.5F, 37.25F, 38.0F,
    35.0F, 36.0F, 37.0F, 38.0F, 39.0F
};

static real32_T DefValue_NearDr_nv0r_mix[] =
{
    44.0F, 43.0F, 42.0F, 41.0F, 40.0F, 43.0F, 42.25F, 41.5F, 40.75F, 40.0F,
    42.0F, 41.5F, 41.0F, 40.5F, 40.0F, 41.0F, 40.75F, 40.5F, 40.25F, 40.0F,
    40.0F, 40.0F, 40.0F, 40.0F, 40.0F
};

static real32_T DefValue_NearDr_nv1l_mix[] =
{
    40.0F, 40.0F, 40.0F, 40.0F, 40.0F, 41.0F, 40.75F, 40.5F, 40.25F, 40.0F,
    42.0F, 41.5F, 41.0F, 40.5F, 40.0F, 43.0F, 42.25F, 41.5F, 40.75F, 40.0F,
    44.0F, 43.0F, 42.0F, 41.0F, 40.0F
};

static real32_T DefValue_NearDr_nv1r_mix[] =
{
    40.0F, 41.0F, 42.0F, 43.0F, 44.0F, 40.0F, 40.75F, 41.5F, 42.25F, 43.0F,
    40.0F, 40.5F, 41.0F, 41.5F, 42.0F, 40.0F, 40.25F, 40.5F, 40.75F, 41.0F,
    40.0F, 40.0F, 40.0F, 40.0F, 40.0F
};

static real_T DefValue_NearFr_PooliirsosCoefficients[] =
{
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
};

static real_T DefValue_NearFr_PooliirnumStages[] =
{
    20.0, 20.0, 20.0, 20.0, 20.0
};

static real32_T DefValue_NearFr_f1_del[] =
{
    0.0F
};

static real32_T DefValue_NearFr_f2_del[] =
{
    0.0F
};

static real32_T DefValue_NearFr_f3_del[] =
{
    0.0F
};

static real32_T DefValue_NearFr_f4_del[] =
{
    0.0F
};

static real32_T DefValue_NearFr_f5_del[] =
{
    0.0F
};

static real32_T DefValue_NearFr_f6_del[] =
{
    0.0F
};

static real32_T DefValue_NearFr_f7_del[] =
{
    0.0F
};

static real_T DefValue_NearFr_PoolIirTunablesosCoefficients[] =
{
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
};

static real_T DefValue_NearFr_PoolIirTunablenumStages[] =
{
    25.0, 25.0, 25.0, 25.0
};

static real32_T DefValue_NearFr_driver_src1[] =
{
    0.0F
};

static real32_T DefValue_NearFr_driver_src2[] =
{
    0.0F
};

static real32_T DefValue_NearFr_driver_src3[] =
{
    0.0F
};

static real32_T DefValue_NearFr_driver_src4[] =
{
    0.0F
};

static real32_T DefValue_NearFr_passenger_src1[] =
{
    0.0F
};

static real32_T DefValue_NearFr_passenger_src2[] =
{
    0.0F
};

static real32_T DefValue_NearFr_passenger_src3[] =
{
    0.0F
};

static real32_T DefValue_NearFr_passenger_src4[] =
{
    0.0F
};

static real_T DefValue_NearFr_RouterMap[] =
{
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0
};

static real32_T DefValue_NearFr_f1_mix[] =
{
    4.0F, 3.0F, 2.0F, 1.0F, 0.0F, 3.0F, 2.25F, 1.5F, 0.75F, 0.0F, 2.0F, 1.5F,
    1.0F, 0.5F, 0.0F, 1.0F, 0.75F, 0.5F, 0.25F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F
};

static real32_T DefValue_NearFr_f2_mix[] =
{
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.75F, 0.5F, 0.25F, 0.0F, 2.0F, 1.5F,
    1.0F, 0.5F, 0.0F, 3.0F, 2.25F, 1.5F, 0.75F, 0.0F, 4.0F, 3.0F, 2.0F, 1.0F,
    0.0F
};

static real32_T DefValue_NearFr_f3_mix[] =
{
    0.0F, 1.0F, 2.0F, 3.0F, 4.0F, 0.0F, 0.75F, 1.5F, 2.25F, 3.0F, 0.0F, 0.5F,
    1.0F, 1.5F, 2.0F, 0.0F, 0.25F, 0.5F, 0.75F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F
};

static real32_T DefValue_NearFr_f4_mix[] =
{
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.25F, 0.5F, 0.75F, 1.0F, 0.0F, 0.5F,
    1.0F, 1.5F, 2.0F, 0.0F, 0.75F, 1.5F, 2.25F, 3.0F, 0.0F, 1.0F, 2.0F, 3.0F,
    4.0F
};

static real32_T DefValue_NearFr_f5_mix[] =
{
    9.0F, 8.0F, 7.0F, 6.0F, 5.0F, 8.0F, 7.25F, 6.5F, 5.75F, 5.0F, 7.0F, 6.5F,
    6.0F, 5.5F, 5.0F, 6.0F, 5.75F, 5.5F, 5.25F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F,
    5.0F
};

static real32_T DefValue_NearFr_f6_mix[] =
{
    5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 6.0F, 5.75F, 5.5F, 5.25F, 5.0F, 7.0F, 6.5F,
    6.0F, 5.5F, 5.0F, 8.0F, 7.25F, 6.5F, 5.75F, 5.0F, 9.0F, 8.0F, 7.0F, 6.0F,
    5.0F
};

static real32_T DefValue_NearFr_f7_mix[] =
{
    5.0F, 6.0F, 7.0F, 8.0F, 9.0F, 5.0F, 5.75F, 6.5F, 7.25F, 8.0F, 5.0F, 5.5F,
    6.0F, 6.5F, 7.0F, 5.0F, 5.25F, 5.5F, 5.75F, 6.0F, 5.0F, 5.0F, 5.0F, 5.0F,
    5.0F
};

static real32_T DefValue_NearFr_LFI0_mix[] =
{
    5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.25F, 5.5F, 5.75F, 6.0F, 5.0F, 5.5F,
    6.0F, 6.5F, 7.0F, 5.0F, 5.75F, 6.5F, 7.25F, 8.0F, 5.0F, 6.0F, 7.0F, 8.0F,
    9.0F
};

static real32_T DefValue_NearFr_LFT0_mix[] =
{
    14.0F, 13.0F, 12.0F, 11.0F, 10.0F, 13.0F, 12.25F, 11.5F, 10.75F, 10.0F,
    12.0F, 11.5F, 11.0F, 10.5F, 10.0F, 11.0F, 10.75F, 10.5F, 10.25F, 10.0F,
    10.0F, 10.0F, 10.0F, 10.0F, 10.0F
};

static real32_T DefValue_NearFr_RFI0_mix[] =
{
    10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 11.0F, 10.75F, 10.5F, 10.25F, 10.0F,
    12.0F, 11.5F, 11.0F, 10.5F, 10.0F, 13.0F, 12.25F, 11.5F, 10.75F, 10.0F,
    14.0F, 13.0F, 12.0F, 11.0F, 10.0F
};

static real32_T DefValue_NearFr_RFT0_mix[] =
{
    10.0F, 11.0F, 12.0F, 13.0F, 14.0F, 10.0F, 10.75F, 11.5F, 12.25F, 13.0F,
    10.0F, 10.5F, 11.0F, 11.5F, 12.0F, 10.0F, 10.25F, 10.5F, 10.75F, 11.0F,
    10.0F, 10.0F, 10.0F, 10.0F, 10.0F
};

static real32_T DefValue_NearFr_LSI0_mix[] =
{
    10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.25F, 10.5F, 10.75F, 11.0F,
    10.0F, 10.5F, 11.0F, 11.5F, 12.0F, 10.0F, 10.75F, 11.5F, 12.25F, 13.0F,
    10.0F, 11.0F, 12.0F, 13.0F, 14.0F
};

static real32_T DefValue_NearFr_LST0_mix[] =
{
    19.0F, 18.0F, 17.0F, 16.0F, 15.0F, 18.0F, 17.25F, 16.5F, 15.75F, 15.0F,
    17.0F, 16.5F, 16.0F, 15.5F, 15.0F, 16.0F, 15.75F, 15.5F, 15.25F, 15.0F,
    15.0F, 15.0F, 15.0F, 15.0F, 15.0F
};

static real32_T DefValue_NearFr_RSI0_mix[] =
{
    15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 16.0F, 15.75F, 15.5F, 15.25F, 15.0F,
    17.0F, 16.5F, 16.0F, 15.5F, 15.0F, 18.0F, 17.25F, 16.5F, 15.75F, 15.0F,
    19.0F, 18.0F, 17.0F, 16.0F, 15.0F
};

static real32_T DefValue_NearFr_RST0_mix[] =
{
    15.0F, 16.0F, 17.0F, 18.0F, 19.0F, 15.0F, 15.75F, 16.5F, 17.25F, 18.0F,
    15.0F, 15.5F, 16.0F, 16.5F, 17.0F, 15.0F, 15.25F, 15.5F, 15.75F, 16.0F,
    15.0F, 15.0F, 15.0F, 15.0F, 15.0F
};

static real32_T DefValue_NearFr_LCI0_mix[] =
{
    15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.25F, 15.5F, 15.75F, 16.0F,
    15.0F, 15.5F, 16.0F, 16.5F, 17.0F, 15.0F, 15.75F, 16.5F, 17.25F, 18.0F,
    15.0F, 16.0F, 17.0F, 18.0F, 19.0F
};

static real32_T DefValue_NearFr_LCT0_mix[] =
{
    24.0F, 23.0F, 22.0F, 21.0F, 20.0F, 23.0F, 22.25F, 21.5F, 20.75F, 20.0F,
    22.0F, 21.5F, 21.0F, 20.5F, 20.0F, 21.0F, 20.75F, 20.5F, 20.25F, 20.0F,
    20.0F, 20.0F, 20.0F, 20.0F, 20.0F
};

static real32_T DefValue_NearFr_RCI0_mix[] =
{
    20.0F, 20.0F, 20.0F, 20.0F, 20.0F, 21.0F, 20.75F, 20.5F, 20.25F, 20.0F,
    22.0F, 21.5F, 21.0F, 20.5F, 20.0F, 23.0F, 22.25F, 21.5F, 20.75F, 20.0F,
    24.0F, 23.0F, 22.0F, 21.0F, 20.0F
};

static real32_T DefValue_NearFr_RCT0_mix[] =
{
    20.0F, 21.0F, 22.0F, 23.0F, 24.0F, 20.0F, 20.75F, 21.5F, 22.25F, 23.0F,
    20.0F, 20.5F, 21.0F, 21.5F, 22.0F, 20.0F, 20.25F, 20.5F, 20.75F, 21.0F,
    20.0F, 20.0F, 20.0F, 20.0F, 20.0F
};

static real32_T DefValue_NearFr_LFI1_mix[] =
{
    20.0F, 20.0F, 20.0F, 20.0F, 20.0F, 20.0F, 20.25F, 20.5F, 20.75F, 21.0F,
    20.0F, 20.5F, 21.0F, 21.5F, 22.0F, 20.0F, 20.75F, 21.5F, 22.25F, 23.0F,
    20.0F, 21.0F, 22.0F, 23.0F, 24.0F
};

static real32_T DefValue_NearFr_LFT1_mix[] =
{
    29.0F, 28.0F, 27.0F, 26.0F, 25.0F, 28.0F, 27.25F, 26.5F, 25.75F, 25.0F,
    27.0F, 26.5F, 26.0F, 25.5F, 25.0F, 26.0F, 25.75F, 25.5F, 25.25F, 25.0F,
    25.0F, 25.0F, 25.0F, 25.0F, 25.0F
};

static real32_T DefValue_NearFr_RFI1_mix[] =
{
    25.0F, 25.0F, 25.0F, 25.0F, 25.0F, 26.0F, 25.75F, 25.5F, 25.25F, 25.0F,
    27.0F, 26.5F, 26.0F, 25.5F, 25.0F, 28.0F, 27.25F, 26.5F, 25.75F, 25.0F,
    29.0F, 28.0F, 27.0F, 26.0F, 25.0F
};

static real32_T DefValue_NearFr_RFT1_mix[] =
{
    25.0F, 26.0F, 27.0F, 28.0F, 29.0F, 25.0F, 25.75F, 26.5F, 27.25F, 28.0F,
    25.0F, 25.5F, 26.0F, 26.5F, 27.0F, 25.0F, 25.25F, 25.5F, 25.75F, 26.0F,
    25.0F, 25.0F, 25.0F, 25.0F, 25.0F
};

static real32_T DefValue_NearFr_LSI1_mix[] =
{
    25.0F, 25.0F, 25.0F, 25.0F, 25.0F, 25.0F, 25.25F, 25.5F, 25.75F, 26.0F,
    25.0F, 25.5F, 26.0F, 26.5F, 27.0F, 25.0F, 25.75F, 26.5F, 27.25F, 28.0F,
    25.0F, 26.0F, 27.0F, 28.0F, 29.0F
};

static real32_T DefValue_NearFr_LST1_mix[] =
{
    34.0F, 33.0F, 32.0F, 31.0F, 30.0F, 33.0F, 32.25F, 31.5F, 30.75F, 30.0F,
    32.0F, 31.5F, 31.0F, 30.5F, 30.0F, 31.0F, 30.75F, 30.5F, 30.25F, 30.0F,
    30.0F, 30.0F, 30.0F, 30.0F, 30.0F
};

static real32_T DefValue_NearFr_RSI1_mix[] =
{
    30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 31.0F, 30.75F, 30.5F, 30.25F, 30.0F,
    32.0F, 31.5F, 31.0F, 30.5F, 30.0F, 33.0F, 32.25F, 31.5F, 30.75F, 30.0F,
    34.0F, 33.0F, 32.0F, 31.0F, 30.0F
};

static real32_T DefValue_NearFr_RST1_mix[] =
{
    30.0F, 31.0F, 32.0F, 33.0F, 34.0F, 30.0F, 30.75F, 31.5F, 32.25F, 33.0F,
    30.0F, 30.5F, 31.0F, 31.5F, 32.0F, 30.0F, 30.25F, 30.5F, 30.75F, 31.0F,
    30.0F, 30.0F, 30.0F, 30.0F, 30.0F
};

static real32_T DefValue_NearFr_LCI1_mix[] =
{
    30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.25F, 30.5F, 30.75F, 31.0F,
    30.0F, 30.5F, 31.0F, 31.5F, 32.0F, 30.0F, 30.75F, 31.5F, 32.25F, 33.0F,
    30.0F, 31.0F, 32.0F, 33.0F, 34.0F
};

static real32_T DefValue_NearFr_LCT1_mix[] =
{
    39.0F, 38.0F, 37.0F, 36.0F, 35.0F, 38.0F, 37.25F, 36.5F, 35.75F, 35.0F,
    37.0F, 36.5F, 36.0F, 35.5F, 35.0F, 36.0F, 35.75F, 35.5F, 35.25F, 35.0F,
    35.0F, 35.0F, 35.0F, 35.0F, 35.0F
};

static real32_T DefValue_NearFr_RCI1_mix[] =
{
    35.0F, 35.0F, 35.0F, 35.0F, 35.0F, 36.0F, 35.75F, 35.5F, 35.25F, 35.0F,
    37.0F, 36.5F, 36.0F, 35.5F, 35.0F, 38.0F, 37.25F, 36.5F, 35.75F, 35.0F,
    39.0F, 38.0F, 37.0F, 36.0F, 35.0F
};

static real32_T DefValue_NearFr_RCT1_mix[] =
{
    35.0F, 36.0F, 37.0F, 38.0F, 39.0F, 35.0F, 35.75F, 36.5F, 37.25F, 38.0F,
    35.0F, 35.5F, 36.0F, 36.5F, 37.0F, 35.0F, 35.25F, 35.5F, 35.75F, 36.0F,
    35.0F, 35.0F, 35.0F, 35.0F, 35.0F
};

static real32_T DefValue_NearFr_nv0l_mix[] =
{
    35.0F, 35.0F, 35.0F, 35.0F, 35.0F, 35.0F, 35.25F, 35.5F, 35.75F, 36.0F,
    35.0F, 35.5F, 36.0F, 36.5F, 37.0F, 35.0F, 35.75F, 36.5F, 37.25F, 38.0F,
    35.0F, 36.0F, 37.0F, 38.0F, 39.0F
};

static real32_T DefValue_NearFr_nv0r_mix[] =
{
    44.0F, 43.0F, 42.0F, 41.0F, 40.0F, 43.0F, 42.25F, 41.5F, 40.75F, 40.0F,
    42.0F, 41.5F, 41.0F, 40.5F, 40.0F, 41.0F, 40.75F, 40.5F, 40.25F, 40.0F,
    40.0F, 40.0F, 40.0F, 40.0F, 40.0F
};

static real32_T DefValue_NearFr_nv1l_mix[] =
{
    40.0F, 40.0F, 40.0F, 40.0F, 40.0F, 41.0F, 40.75F, 40.5F, 40.25F, 40.0F,
    42.0F, 41.5F, 41.0F, 40.5F, 40.0F, 43.0F, 42.25F, 41.5F, 40.75F, 40.0F,
    44.0F, 43.0F, 42.0F, 41.0F, 40.0F
};

static real32_T DefValue_NearFr_nv1r_mix[] =
{
    40.0F, 41.0F, 42.0F, 43.0F, 44.0F, 40.0F, 40.75F, 41.5F, 42.25F, 43.0F,
    40.0F, 40.5F, 41.0F, 41.5F, 42.0F, 40.0F, 40.25F, 40.5F, 40.75F, 41.0F,
    40.0F, 40.0F, 40.0F, 40.0F, 40.0F
};

static real32_T DefValue_NearRampDbPerSample[] =
{
    0.005F
};

static real_T DefValue_NearHpfCutoffFrequency[] =
{
    90.0
};

static real_T DefValue_NearHpfFilterOrder[] =
{
    5.0
};

static real_T DefValue_NearLevelDetectPreEmphasisShelfFiltersosCoefficients[] =
{
    1.5812129081301327, 1.5812129081301327, -3.1340311595034271,
    -3.1340311595034271, 1.5530709413836785, 1.5530709413836785, 1.0, 1.0,
    -1.9773933512222359, -1.9773933512222359, 0.97764604123261956,
    0.97764604123261956
};

static real_T DefValue_NearLevelDetectPreEmphasisShelfFilternumStages[] =
{
    1.0, 1.0
};

static real32_T DefValue_NearLevelDetectSysMaxDbspl[] =
{
    123.0F
};

static real32_T DefValue_NearAnn1LevelDetectFastDecayDbPers[] =
{
    5.0F
};

static real32_T DefValue_NearAnn1LevelDetectHoldMarginDb[] =
{
    6.0F
};

static real32_T DefValue_NearAnn1LevelDetectHoldTimes[] =
{
    3.0F
};

static real32_T DefValue_NearAnn1LevelDetectMaxVolumeDb[] =
{
    0.0F
};

static real32_T DefValue_NearAnn1LevelDetectMinVolumeDb[] =
{
    -80.0F
};

static real32_T DefValue_NearAnn1LevelDetectSlowDecayDbPers[] =
{
    0.1F
};

static real32_T DefValue_NearAnn2LevelDetectFastDecayDbPers[] =
{
    5.0F
};

static real32_T DefValue_NearAnn2LevelDetectHoldMarginDb[] =
{
    6.0F
};

static real32_T DefValue_NearAnn2LevelDetectHoldTimes[] =
{
    3.0F
};

static real32_T DefValue_NearAnn2LevelDetectMaxVolumeDb[] =
{
    0.0F
};

static real32_T DefValue_NearAnn2LevelDetectMinVolumeDb[] =
{
    -80.0F
};

static real32_T DefValue_NearAnn2LevelDetectSlowDecayDbPers[] =
{
    0.1F
};

static real32_T DefValue_NearAnn3LevelDetectFastDecayDbPers[] =
{
    5.0F
};

static real32_T DefValue_NearAnn3LevelDetectHoldMarginDb[] =
{
    6.0F
};

static real32_T DefValue_NearAnn3LevelDetectHoldTimes[] =
{
    3.0F
};

static real32_T DefValue_NearAnn3LevelDetectMaxVolumeDb[] =
{
    0.0F
};

static real32_T DefValue_NearAnn3LevelDetectMinVolumeDb[] =
{
    -80.0F
};

static real32_T DefValue_NearAnn3LevelDetectSlowDecayDbPers[] =
{
    0.1F
};

static real32_T DefValue_NearAnn4LevelDetectFastDecayDbPers[] =
{
    5.0F
};

static real32_T DefValue_NearAnn4LevelDetectHoldMarginDb[] =
{
    6.0F
};

static real32_T DefValue_NearAnn4LevelDetectHoldTimes[] =
{
    3.0F
};

static real32_T DefValue_NearAnn4LevelDetectMaxVolumeDb[] =
{
    0.0F
};

static real32_T DefValue_NearAnn4LevelDetectMinVolumeDb[] =
{
    -80.0F
};

static real32_T DefValue_NearAnn4LevelDetectSlowDecayDbPers[] =
{
    0.1F
};

static real_T DefValue_NearAnn1Ann1NonEntGainCalcVncThresh[] =
{
    0.0
};

static real_T DefValue_NearAnn1Ann1NonEntGainCalcVncSlope[] =
{
    0.4
};

static real_T DefValue_NearAnn1Ann1NonEntGainCalcMaxBoost[] =
{
    18.0
};

static real_T DefValue_NearAnn1Ann1NonEntGainCalcNoiseOverRide[] =
{
    0.0
};

static real_T DefValue_NearAnn1Ann1NonEntGainCalcNoiseOverRideFlag[] =
{
    0.0
};

static real_T DefValue_NearAnn1Ann1NonEntGainCalcBoostOverRide[] =
{
    0.0
};

static real_T DefValue_NearAnn1Ann1NonEntGainCalcBoostOverRideFlag[] =
{
    0.0
};

static real_T DefValue_NearAnn1Ann1NonEntGainCalcVncEnableTuneVar[] =
{
    1.0
};

static real32_T DefValue_NearAnn1Ann1NonEntGainCalcTau[] =
{
    0.1F
};

static real_T DefValue_NearAnn1Ann1NonEntGainCalcMinVncSignal[] =
{
    40.0
};

static real_T DefValue_NearAnn1Ann1NonEntGainCalcMaxSpl[] =
{
    120.0
};

static real_T DefValue_NearAnn1Ann1NonEntVncAppliedTau[] =
{
    0.05
};

static real_T DefValue_NearAnn1Ann1MuteRampTime[] =
{
    100.0
};

static real_T DefValue_NearAnn1Ann1VolumeTable[] =
{
    0.00392156862745098, 0.12549019607843137, 0.25098039215686274,
    0.37647058823529411, 0.50196078431372548, 0.62745098039215685,
    0.75294117647058822, 0.8784313725490196, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, -126.5, -100.0, -90.0, -40.0, -30.0, -20.0, -10.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0
};

static real_T DefValue_NearAnn1Ann1VolumeRampRate[] =
{
    100.0
};

static real_T DefValue_NearAnn1Ann1VolumeRampTime[] =
{
    100.0
};

static real_T DefValue_NearAnn2Ann2NonEntGainCalcVncThresh[] =
{
    0.0
};

static real_T DefValue_NearAnn2Ann2NonEntGainCalcVncSlope[] =
{
    0.4
};

static real_T DefValue_NearAnn2Ann2NonEntGainCalcMaxBoost[] =
{
    18.0
};

static real_T DefValue_NearAnn2Ann2NonEntGainCalcNoiseOverRide[] =
{
    0.0
};

static real_T DefValue_NearAnn2Ann2NonEntGainCalcNoiseOverRideFlag[] =
{
    0.0
};

static real_T DefValue_NearAnn2Ann2NonEntGainCalcBoostOverRide[] =
{
    0.0
};

static real_T DefValue_NearAnn2Ann2NonEntGainCalcBoostOverRideFlag[] =
{
    0.0
};

static real_T DefValue_NearAnn2Ann2NonEntGainCalcVncEnableTuneVar[] =
{
    1.0
};

static real32_T DefValue_NearAnn2Ann2NonEntGainCalcTau[] =
{
    0.1F
};

static real_T DefValue_NearAnn2Ann2NonEntGainCalcMinVncSignal[] =
{
    40.0
};

static real_T DefValue_NearAnn2Ann2NonEntGainCalcMaxSpl[] =
{
    120.0
};

static real_T DefValue_NearAnn2Ann2NonEntVncAppliedTau[] =
{
    0.05
};

static real_T DefValue_NearAnn2Ann2MuteRampTime[] =
{
    100.0
};

static real_T DefValue_NearAnn2Ann2VolumeTable[] =
{
    0.00392156862745098, 0.12549019607843137, 0.25098039215686274,
    0.37647058823529411, 0.50196078431372548, 0.62745098039215685,
    0.75294117647058822, 0.8784313725490196, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, -126.5, -100.0, -90.0, -40.0, -30.0, -20.0, -10.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0
};

static real_T DefValue_NearAnn2Ann2VolumeRampRate[] =
{
    100.0
};

static real_T DefValue_NearAnn2Ann2VolumeRampTime[] =
{
    100.0
};

static real_T DefValue_NearAnn3Ann3NonEntGainCalcVncThresh[] =
{
    0.0
};

static real_T DefValue_NearAnn3Ann3NonEntGainCalcVncSlope[] =
{
    0.4
};

static real_T DefValue_NearAnn3Ann3NonEntGainCalcMaxBoost[] =
{
    18.0
};

static real_T DefValue_NearAnn3Ann3NonEntGainCalcNoiseOverRide[] =
{
    0.0
};

static real_T DefValue_NearAnn3Ann3NonEntGainCalcNoiseOverRideFlag[] =
{
    0.0
};

static real_T DefValue_NearAnn3Ann3NonEntGainCalcBoostOverRide[] =
{
    0.0
};

static real_T DefValue_NearAnn3Ann3NonEntGainCalcBoostOverRideFlag[] =
{
    0.0
};

static real_T DefValue_NearAnn3Ann3NonEntGainCalcVncEnableTuneVar[] =
{
    1.0
};

static real32_T DefValue_NearAnn3Ann3NonEntGainCalcTau[] =
{
    0.1F
};

static real_T DefValue_NearAnn3Ann3NonEntGainCalcMinVncSignal[] =
{
    40.0
};

static real_T DefValue_NearAnn3Ann3NonEntGainCalcMaxSpl[] =
{
    120.0
};

static real_T DefValue_NearAnn3Ann3NonEntVncAppliedTau[] =
{
    0.05
};

static real_T DefValue_NearAnn3Ann3MuteRampTime[] =
{
    100.0
};

static real_T DefValue_NearAnn3Ann3VolumeTable[] =
{
    0.00392156862745098, 0.12549019607843137, 0.25098039215686274,
    0.37647058823529411, 0.50196078431372548, 0.62745098039215685,
    0.75294117647058822, 0.8784313725490196, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, -126.5, -100.0, -90.0, -40.0, -30.0, -20.0, -10.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0
};

static real_T DefValue_NearAnn3Ann3VolumeRampRate[] =
{
    100.0
};

static real_T DefValue_NearAnn3Ann3VolumeRampTime[] =
{
    100.0
};

static real_T DefValue_NearAnn4Ann4NonEntGainCalcVncThresh[] =
{
    0.0
};

static real_T DefValue_NearAnn4Ann4NonEntGainCalcVncSlope[] =
{
    0.4
};

static real_T DefValue_NearAnn4Ann4NonEntGainCalcMaxBoost[] =
{
    18.0
};

static real_T DefValue_NearAnn4Ann4NonEntGainCalcNoiseOverRide[] =
{
    0.0
};

static real_T DefValue_NearAnn4Ann4NonEntGainCalcNoiseOverRideFlag[] =
{
    0.0
};

static real_T DefValue_NearAnn4Ann4NonEntGainCalcBoostOverRide[] =
{
    0.0
};

static real_T DefValue_NearAnn4Ann4NonEntGainCalcBoostOverRideFlag[] =
{
    0.0
};

static real_T DefValue_NearAnn4Ann4NonEntGainCalcVncEnableTuneVar[] =
{
    1.0
};

static real32_T DefValue_NearAnn4Ann4NonEntGainCalcTau[] =
{
    0.1F
};

static real_T DefValue_NearAnn4Ann4NonEntGainCalcMinVncSignal[] =
{
    40.0
};

static real_T DefValue_NearAnn4Ann4NonEntGainCalcMaxSpl[] =
{
    120.0
};

static real_T DefValue_NearAnn4Ann4NonEntVncAppliedTau[] =
{
    0.05
};

static real_T DefValue_NearAnn4Ann4MuteRampTime[] =
{
    100.0
};

static real_T DefValue_NearAnn4Ann4VolumeTable[] =
{
    0.00392156862745098, 0.12549019607843137, 0.25098039215686274,
    0.37647058823529411, 0.50196078431372548, 0.62745098039215685,
    0.75294117647058822, 0.8784313725490196, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, -126.5, -100.0, -90.0, -40.0, -30.0, -20.0, -10.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0
};

static real_T DefValue_NearAnn4Ann4VolumeRampRate[] =
{
    100.0
};

static real_T DefValue_NearAnn4Ann4VolumeRampTime[] =
{
    100.0
};

static real_T DefValue_TestRouterASDRouterEnableAux[] =
{
    0.0
};

static real_T DefValue_TestRouterASDRouterMainSelect[] =
{
    1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0,
    15.0, 16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0
};

static real_T DefValue_TestRouterAuxSelect[] =
{
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0
};

// ----- Dependent translations for each tune variable:
static enum TranslationNumber
    PreAmpMedusaDeciRateWiggleFilterDelaySamples_Dependencies[] =/* '<S630>/Tune Variable4' */
{
    ID_Translation_Model_141_1371,
};

static enum TranslationNumber
    PreAmpMedusaDeciRateNearWiggleFilterDelaySamples_Dependencies[] =/* '<S630>/Tune Variable1' */
{
    ID_Translation_Model_141_1371,
};

static enum TranslationNumber
    PreAmpMedusaHoligramFilterAlignmentDelaySamples_Dependencies[] =/* '<S630>/Tune Variable5' */
{
    ID_Translation_Model_141_1371,
};

static enum TranslationNumber
    PreAmpMedusatailCompEQsosCoefficients_Dependencies[] =/* '<S765>/Tune Variable2' */
{
    ID_Translation_Model_141_345_50_36,
};

static enum TranslationNumber PreAmpMedusatailCompEQnumStages_Dependencies[] =/* '<S765>/Tune Variable1' */
{
    ID_Translation_Model_141_345_50_36,
};

static enum TranslationNumber PreAmpMedusaWiggleFilter_Dependencies[] =/* '<S763>/Tune Variable' */
{
    ID_Translation_Model_141_346_67_18,
};

static enum TranslationNumber
    PreAmpMedusaDeciRateWiggleFilterDelaySamples1_Dependencies[] =/* '<S753>/Tune Variable' */
{
    ID_Translation_Model_141_2888,
};

static enum TranslationNumber
    PreAmpMedusaDeciRateNearWiggleFilterDelaySamples1_Dependencies[] =/* '<S753>/Tune Variable1' */
{
    ID_Translation_Model_141_2888,
};

static enum TranslationNumber
    PreAmpMedusaFullRateMixerBackwardDownmixMax_Dependencies[] =/* '<S776>/Tune Variable' */
{
    ID_Translation_Model_141_2926,
};

static enum TranslationNumber
    PreAmpMedusaFullRateMixerBackwardDownmixThreshold_Dependencies[] =/* '<S777>/Tune Variable' */
{
    ID_Translation_Model_141_2932,
};

static enum TranslationNumber
    PreAmpMedusaFullRateMixerDownmixWeights_CS_Dependencies[] =/* '<S778>/Tune Variable' */
{
    ID_Translation_Model_141_2939,
};

static enum TranslationNumber
    PreAmpMedusaFullRateMixerDownmixWeights_Left_Dependencies[] =/* '<S779>/Tune Variable' */
{
    ID_Translation_Model_141_2947,
};

static enum TranslationNumber
    PreAmpMedusaFullRateMixerDownmixWeights_Right_Dependencies[] =/* '<S780>/Tune Variable' */
{
    ID_Translation_Model_141_2955,
};

static enum TranslationNumber
    PreAmpMedusaFullRateMixerForwardDownmixThreshold_Dependencies[] =/* '<S781>/Tune Variable' */
{
    ID_Translation_Model_141_2962,
};

static enum TranslationNumber
    PreAmpMedusaFullRateMixerForwardDownmixMax_Dependencies[] =/* '<S782>/Tune Variable' */
{
    ID_Translation_Model_141_2968,
};

static enum TranslationNumber
    PreAmpMedusaFullRateMixerDetentLevel_CS_Dependencies[] =/* '<S804>/Tune Variable' */
{
    ID_Translation_Model_141_3372,
};

static enum TranslationNumber
    PreAmpMedusaFullRateMixerDetentLevel_Left_Dependencies[] =/* '<S805>/Tune Variable' */
{
    ID_Translation_Model_141_3380,
};

static enum TranslationNumber
    PreAmpMedusaFullRateMixerDetentLevel_Right_Dependencies[] =/* '<S806>/Tune Variable' */
{
    ID_Translation_Model_141_3388,
};

static enum TranslationNumber
    PreAmpMedusaFullRateMixerInterpolation_Method_Dependencies[] =/* '<S807>/Tune Variable' */
{
    ID_Translation_Model_141_3395,
};

static enum TranslationNumber PreAmpMedusaFullRateMixerMaxLevel_CS_Dependencies[]
    =                                  /* '<S808>/Tune Variable' */
{
    ID_Translation_Model_141_3402,
};

static enum TranslationNumber
    PreAmpMedusaFullRateMixerMaxLevel_Left_Dependencies[] =/* '<S809>/Tune Variable' */
{
    ID_Translation_Model_141_3410,
};

static enum TranslationNumber
    PreAmpMedusaFullRateMixerMaxLevel_Right_Dependencies[] =/* '<S810>/Tune Variable' */
{
    ID_Translation_Model_141_3418,
};

static enum TranslationNumber PreAmpMedusaFullRateMixerMinLevel_CS_Dependencies[]
    =                                  /* '<S811>/Tune Variable' */
{
    ID_Translation_Model_141_3426,
};

static enum TranslationNumber
    PreAmpMedusaFullRateMixerMinLevel_Left_Dependencies[] =/* '<S812>/Tune Variable' */
{
    ID_Translation_Model_141_3434,
};

static enum TranslationNumber
    PreAmpMedusaFullRateMixerMinLevel_Right_Dependencies[] =/* '<S813>/Tune Variable' */
{
    ID_Translation_Model_141_3442,
};

static enum TranslationNumber
    PreAmpMedusaPremixMonoSurroundPhaseAngle_Dependencies[] =/* '<S848>/Tune Variable' */
{
    ID_Translation_Model_141_3495,
};

static enum TranslationNumber PreAmpMedusaPremixBackwardDownmixMax_Dependencies[]
    =                                  /* '<S852>/Tune Variable' */
{
    ID_Translation_Model_141_3596,
};

static enum TranslationNumber
    PreAmpMedusaPremixBackwardDownmixThreshold_Dependencies[] =/* '<S853>/Tune Variable' */
{
    ID_Translation_Model_141_3602,
};

static enum TranslationNumber PreAmpMedusaPremixDownmixWeights_CS_Dependencies[]
    =                                  /* '<S854>/Tune Variable' */
{
    ID_Translation_Model_141_3609,
};

static enum TranslationNumber
    PreAmpMedusaPremixDownmixWeights_Left_Dependencies[] =/* '<S855>/Tune Variable' */
{
    ID_Translation_Model_141_3617,
};

static enum TranslationNumber
    PreAmpMedusaPremixDownmixWeights_Right_Dependencies[] =/* '<S856>/Tune Variable' */
{
    ID_Translation_Model_141_3625,
};

static enum TranslationNumber
    PreAmpMedusaPremixForwardDownmixThreshold_Dependencies[] =/* '<S857>/Tune Variable' */
{
    ID_Translation_Model_141_3632,
};

static enum TranslationNumber PreAmpMedusaPremixForwardDownmixMax_Dependencies[]
    =                                  /* '<S858>/Tune Variable' */
{
    ID_Translation_Model_141_3638,
};

static enum TranslationNumber PreAmpMedusaPremixDetentLevel_CS_Dependencies[] =/* '<S880>/Tune Variable' */
{
    ID_Translation_Model_141_4091,
};

static enum TranslationNumber PreAmpMedusaPremixDetentLevel_Left_Dependencies[] =/* '<S881>/Tune Variable' */
{
    ID_Translation_Model_141_4099,
};

static enum TranslationNumber PreAmpMedusaPremixDetentLevel_Right_Dependencies[]
    =                                  /* '<S882>/Tune Variable' */
{
    ID_Translation_Model_141_4107,
};

static enum TranslationNumber
    PreAmpMedusaPremixInterpolation_Method_Dependencies[] =/* '<S883>/Tune Variable' */
{
    ID_Translation_Model_141_4114,
};

static enum TranslationNumber PreAmpMedusaPremixMaxLevel_CS_Dependencies[] =/* '<S884>/Tune Variable' */
{
    ID_Translation_Model_141_4121,
};

static enum TranslationNumber PreAmpMedusaPremixMaxLevel_Left_Dependencies[] =/* '<S885>/Tune Variable' */
{
    ID_Translation_Model_141_4129,
};

static enum TranslationNumber PreAmpMedusaPremixMaxLevel_Right_Dependencies[] =/* '<S886>/Tune Variable' */
{
    ID_Translation_Model_141_4137,
};

static enum TranslationNumber PreAmpMedusaPremixMinLevel_CS_Dependencies[] =/* '<S887>/Tune Variable' */
{
    ID_Translation_Model_141_4145,
};

static enum TranslationNumber PreAmpMedusaPremixMinLevel_Left_Dependencies[] =/* '<S888>/Tune Variable' */
{
    ID_Translation_Model_141_4153,
};

static enum TranslationNumber PreAmpMedusaPremixMinLevel_Right_Dependencies[] =/* '<S889>/Tune Variable' */
{
    ID_Translation_Model_141_4161,
};

static enum TranslationNumber
    PreAmpMedusaVLSDrvGainsBackwardDownmixMax_Dependencies[] =/* '<S924>/Tune Variable' */
{
    ID_Translation_Model_141_983_182,
};

static enum TranslationNumber
    PreAmpMedusaVLSDrvGainsBackwardDownmixThreshold_Dependencies[] =/* '<S925>/Tune Variable' */
{
    ID_Translation_Model_141_983_188,
};

static enum TranslationNumber
    PreAmpMedusaVLSDrvGainsDownmixWeights_Dependencies[] =/* '<S926>/Tune Variable' */
{
    ID_Translation_Model_141_983_194,
};

static enum TranslationNumber
    PreAmpMedusaVLSDrvGainsForwardDownmixThreshold_Dependencies[] =/* '<S927>/Tune Variable' */
{
    ID_Translation_Model_141_983_200,
};

static enum TranslationNumber
    PreAmpMedusaVLSDrvGainsForwardDownmixMax_Dependencies[] =/* '<S928>/Tune Variable' */
{
    ID_Translation_Model_141_983_206,
};

static enum TranslationNumber PreAmpMedusaVLSDrvGainsDetentLevel_Dependencies[] =/* '<S944>/Tune Variable' */
{
    ID_Translation_Model_141_983_287,
};

static enum TranslationNumber
    PreAmpMedusaVLSDrvGainsInterpolation_Method_Dependencies[] =/* '<S945>/Tune Variable' */
{
    ID_Translation_Model_141_983_293,
};

static enum TranslationNumber PreAmpMedusaVLSDrvGainsMaxLevel_Dependencies[] =/* '<S946>/Tune Variable' */
{
    ID_Translation_Model_141_983_299,
};

static enum TranslationNumber PreAmpMedusaVLSDrvGainsMinLevel_Dependencies[] =/* '<S947>/Tune Variable' */
{
    ID_Translation_Model_141_983_305,
};

static enum TranslationNumber
    PreAmpMedusaVLSPaxGainsBackwardDownmixMax_Dependencies[] =/* '<S962>/Tune Variable' */
{
    ID_Translation_Model_141_984_182,
};

static enum TranslationNumber
    PreAmpMedusaVLSPaxGainsBackwardDownmixThreshold_Dependencies[] =/* '<S963>/Tune Variable' */
{
    ID_Translation_Model_141_984_188,
};

static enum TranslationNumber
    PreAmpMedusaVLSPaxGainsDownmixWeights_Dependencies[] =/* '<S964>/Tune Variable' */
{
    ID_Translation_Model_141_984_194,
};

static enum TranslationNumber
    PreAmpMedusaVLSPaxGainsForwardDownmixThreshold_Dependencies[] =/* '<S965>/Tune Variable' */
{
    ID_Translation_Model_141_984_200,
};

static enum TranslationNumber
    PreAmpMedusaVLSPaxGainsForwardDownmixMax_Dependencies[] =/* '<S966>/Tune Variable' */
{
    ID_Translation_Model_141_984_206,
};

static enum TranslationNumber PreAmpMedusaVLSPaxGainsDetentLevel_Dependencies[] =/* '<S982>/Tune Variable' */
{
    ID_Translation_Model_141_984_287,
};

static enum TranslationNumber
    PreAmpMedusaVLSPaxGainsInterpolation_Method_Dependencies[] =/* '<S983>/Tune Variable' */
{
    ID_Translation_Model_141_984_293,
};

static enum TranslationNumber PreAmpMedusaVLSPaxGainsMaxLevel_Dependencies[] =/* '<S984>/Tune Variable' */
{
    ID_Translation_Model_141_984_299,
};

static enum TranslationNumber PreAmpMedusaVLSPaxGainsMinLevel_Dependencies[] =/* '<S985>/Tune Variable' */
{
    ID_Translation_Model_141_984_305,
};

static enum TranslationNumber
    PreAmpMedusaDRHoligramPoolIirTunableConfigsosCoefficients_Dependencies[] =/* '<S1004>/Tune Variable2' */
{
    ID_Translation_Model_141_472_255_36,
};

static enum TranslationNumber
    PreAmpMedusaDRHoligramPoolIirTunableConfignumStages_Dependencies[] =/* '<S1004>/Tune Variable1' */
{
    ID_Translation_Model_141_472_255_36,
};

static enum TranslationNumber PreAmpMedusaDRHoligramFIRCoeffs_Dependencies[] =/* '<S1003>/Tune Variable' */
{
    ID_Translation_Model_141_472_235,
};

static enum TranslationNumber PreAmpMedusaDRHoligramFIRLengths_Dependencies[] =/* '<S1003>/Tune Variable1' */
{
    ID_Translation_Model_141_472_235,
};

static enum TranslationNumber
    PreAmpMedusaDRHoligramPaddedFIRLengths_Dependencies[] =/* '<S1003>/Tune Variable2' */
{
    ID_Translation_Model_141_472_235,
};

static enum TranslationNumber PreAmpMedusaDRHoligramInputMapping_Dependencies[] =/* '<S1009>/Tune Variable' */
{
    ID_Translation_Model_141_472_239_67_18,
};

static enum TranslationNumber PreAmpMedusaDRHoligramOutputMapping_Dependencies[]
    =                                  /* '<S1010>/Tune Variable' */
{
    ID_Translation_Model_141_472_240_67_18,
};

static enum TranslationNumber
    PreAmpMedusaFRHoligramIirConfigsosCoefficients_Dependencies[] =/* '<S1022>/Tune Variable2' */
{
    ID_Translation_Model_141_473_12_36,
};

static enum TranslationNumber
    PreAmpMedusaFRHoligramIirConfignumStages_Dependencies[] =/* '<S1022>/Tune Variable1' */
{
    ID_Translation_Model_141_473_12_36,
};

static enum TranslationNumber PreAmpMedusaHeadrestCompEQFIRCoeffs_Dependencies[]
    =                                  /* '<S1001>/Tune Variable' */
{
    ID_Translation_Model_141_595_191,
};

static enum TranslationNumber PreAmpMedusaHeadrestCompEQFIRLengths_Dependencies[]
    =                                  /* '<S1001>/Tune Variable1' */
{
    ID_Translation_Model_141_595_191,
};

static enum TranslationNumber
    PreAmpMedusaHeadrestCompEQPaddedFIRLengths_Dependencies[] =/* '<S1001>/Tune Variable2' */
{
    ID_Translation_Model_141_595_191,
};

static enum TranslationNumber
    PreAmpMedusaHeadrestCompEQIirConfigsosCoefficients_Dependencies[] =/* '<S1029>/Tune Variable2' */
{
    ID_Translation_Model_141_595_238_36,
};

static enum TranslationNumber
    PreAmpMedusaHeadrestCompEQIirConfignumStages_Dependencies[] =/* '<S1029>/Tune Variable1' */
{
    ID_Translation_Model_141_595_238_36,
};

static enum TranslationNumber
    PreAmpMedusaNonHeadrestSpeakerDelaySamples_Dependencies[] =/* '<S1034>/Tune Variable1' */
{
    ID_Translation_Model_141_4193,
};

static enum TranslationNumber
    PreAmpMedusaHeadrestDrvSpeakerDelaySamples_Dependencies[] =/* '<S1034>/Tune Variable' */
{
    ID_Translation_Model_141_4193,
};

static enum TranslationNumber
    PreAmpMedusaHeadrestPaxSpeakerDelaySamples_Dependencies[] =/* '<S1034>/Tune Variable4' */
{
    ID_Translation_Model_141_4193,
};

static enum TranslationNumber PreAmpMedusaFRHoligramDelaySamples_Dependencies[] =/* '<S1034>/Tune Variable5' */
{
    ID_Translation_Model_141_4193,
};

static enum TranslationNumber PreAmpMedusaRoutingMap_Dependencies[] =/* '<S1041>/Tune Variable' */
{
    ID_Translation_Model_150_574_67_18,
};

static enum TranslationNumber
    PreAmpVLSXtalkCancellationIIRsosCoefficients_Dependencies[] =/* '<S1164>/Tune Variable2' */
{
    ID_Translation_Model_232_8_34_50_36,
};

static enum TranslationNumber
    PreAmpVLSXtalkCancellationIIRnumStages_Dependencies[] =/* '<S1164>/Tune Variable1' */
{
    ID_Translation_Model_232_8_34_50_36,
};

static enum TranslationNumber PreAmpVLSXtalkCancellationDelay_Dependencies[] =/* '<S1162>/Tune Variable' */
{
    ID_Translation_Model_232_8_36_67_18,
};

static enum TranslationNumber PreAmpVLSGenerationDrvFIRCoeffs_Dependencies[] =/* '<S1159>/Tune Variable' */
{
    ID_Translation_Model_232_11_191,
};

static enum TranslationNumber
    PreAmpVLSGenerationDrvPaddedFIRLengths_Dependencies[] =/* '<S1159>/Tune Variable2' */
{
    ID_Translation_Model_232_11_191,
};

static enum TranslationNumber PreAmpVLSGenerationPaxFIRCoeffs_Dependencies[] =/* '<S1160>/Tune Variable' */
{
    ID_Translation_Model_232_12_191,
};

static enum TranslationNumber
    PreAmpVLSGenerationPaxPaddedFIRLengths_Dependencies[] =/* '<S1160>/Tune Variable2' */
{
    ID_Translation_Model_232_12_191,
};

static enum TranslationNumber PreAmpBassBoostFrequencyHz_Dependencies[] =/* '<S1178>/BoostHz' */
{
    ID_Translation_Model_247_149,
};

static enum TranslationNumber PreAmpBassCutFrequencyHz_Dependencies[] =/* '<S1178>/CutHz' */
{
    ID_Translation_Model_247_153,
};

static enum TranslationNumber PreAmpBassBoostMaximum_dB_Dependencies[] =/* '<S1178>/Boost_dB' */
{
    ID_Translation_Model_247_174,
};

static enum TranslationNumber PreAmpBassCutMaximum_dB_Dependencies[] =/* '<S1178>/Cut_dB' */
{
    ID_Translation_Model_247_176,
};

static enum TranslationNumber PreAmpBassOffset_Dependencies[] =/* '<S1186>/Tune Variable' */
{
    ID_Translation_Model_247_210_67_18,
};

static enum TranslationNumber PreAmpBassramptime_Dependencies[] =/* '<S1187>/Tune Variable' */
{
    ID_Translation_Model_247_229_67_18,
};

static enum TranslationNumber PreAmpBassScale_Dependencies[] =/* '<S1188>/Tune Variable' */
{
    ID_Translation_Model_247_209_67_18,
};

static enum TranslationNumber PreAmpMidrangeBoostFrequencyHz_Dependencies[] =/* '<S1179>/BoostHz' */
{
    ID_Translation_Model_249_47,
};

static enum TranslationNumber PreAmpMidrangeBoostQValue_Dependencies[] =/* '<S1179>/Boost_Q' */
{
    ID_Translation_Model_249_47,
};

static enum TranslationNumber PreAmpMidrangeCutFrequencyHz_Dependencies[] =/* '<S1179>/CutHz' */
{
    ID_Translation_Model_249_48,
};

static enum TranslationNumber PreAmpMidrangeCutQValue_Dependencies[] =/* '<S1179>/Cut_Q' */
{
    ID_Translation_Model_249_48,
};

static enum TranslationNumber PreAmpMidrangeBoostMaximum_dB_Dependencies[] =/* '<S1179>/Boost_dB' */
{
    ID_Translation_Model_249_46,
};

static enum TranslationNumber PreAmpMidrangeCutMaximum_dB_Dependencies[] =/* '<S1179>/Cut_dB' */
{
    ID_Translation_Model_249_49,
};

static enum TranslationNumber PreAmpMidrangeOffset_Dependencies[] =/* '<S1213>/Tune Variable' */
{
    ID_Translation_Model_249_50_67_18,
};

static enum TranslationNumber PreAmpMidrangeRampTime_Dependencies[] =/* '<S1214>/Tune Variable' */
{
    ID_Translation_Model_249_51_67_18,
};

static enum TranslationNumber PreAmpMidrangeScale_Dependencies[] =/* '<S1215>/Tune Variable' */
{
    ID_Translation_Model_249_52_67_18,
};

static enum TranslationNumber PreAmpA_Dependencies[] =/* '<S1239>/Tune Variable' */
{
    ID_Translation_Model_642,
};

static enum TranslationNumber PreAmpG_Dependencies[] =/* '<S1247>/Tune Variable' */
{
    ID_Translation_Model_670_67_18,
};

static enum TranslationNumber PreAmpAnnPred_Dependencies[] =/* '<S1252>/Tune Variable' */
{
    ID_Translation_Model_712,
};

static enum TranslationNumber PreAmpLimiterAttack_Dependencies[] =/* '<S1253>/attackTune' */
{
    ID_Translation_Model_729,
};

static enum TranslationNumber PreAmpLimiterDecay_Dependencies[] =/* '<S1253>/decay tune' */
{
    ID_Translation_Model_730,
};

static enum TranslationNumber PreAmpLimiterMaxAttack_Dependencies[] =/* '<S1253>/maxAttack tune' */
{
    ID_Translation_Model_731,
};

static enum TranslationNumber PreAmpOffset_Dependencies[] =/* '<S1254>/Tune Variable' */
{
    ID_Translation_Model_741,
};

static enum TranslationNumber PreAmpUpperThreshold_Dependencies[] =/* '<S1255>/Tune Variable' */
{
    ID_Translation_Model_747,
};

static enum TranslationNumber PreAmpTrebleBoostFrequencyHz_Dependencies[] =/* '<S1181>/BoostHz' */
{
    ID_Translation_Model_251_149,
};

static enum TranslationNumber PreAmpTrebleCutFrequencyHz_Dependencies[] =/* '<S1181>/CutHz' */
{
    ID_Translation_Model_251_153,
};

static enum TranslationNumber PreAmpTrebleBoostMaximum_dB_Dependencies[] =/* '<S1181>/Boost_dB' */
{
    ID_Translation_Model_251_174,
};

static enum TranslationNumber PreAmpTrebleCutMaximum_dB_Dependencies[] =/* '<S1181>/Cut_dB' */
{
    ID_Translation_Model_251_176,
};

static enum TranslationNumber PreAmpTrebleOffset_Dependencies[] =/* '<S1278>/Tune Variable' */
{
    ID_Translation_Model_251_210_67_18,
};

static enum TranslationNumber PreAmpTrebleramptime_Dependencies[] =/* '<S1279>/Tune Variable' */
{
    ID_Translation_Model_251_229_67_18,
};

static enum TranslationNumber PreAmpTrebleScale_Dependencies[] =/* '<S1280>/Tune Variable' */
{
    ID_Translation_Model_251_209_67_18,
};

static enum TranslationNumber PostProcessLimiterAttack_Dependencies[] =/* '<S1850>/attackTune' */
{
    ID_Translation_Model_1495,
};

static enum TranslationNumber PostProcessLimiterThreshold_Dependencies[] =/* '<S1850>/threshhold tune' */
{
    ID_Translation_Model_1495,
};

static enum TranslationNumber PostProcessLimiterAttack_low_Dependencies[] =/* '<S1850>/attackTune1' */
{
    ID_Translation_Model_1498,
};

static enum TranslationNumber PostProcessLimiterThreshold_low_Dependencies[] =/* '<S1850>/threshhold tune1' */
{
    ID_Translation_Model_1498,
};

static enum TranslationNumber PostProcessLimiterDecay_Dependencies[] =/* '<S1850>/decay tune' */
{
    ID_Translation_Model_1496,
};

static enum TranslationNumber PostProcessLimiterDecay_low_Dependencies[] =/* '<S1850>/decay tune1' */
{
    ID_Translation_Model_1499,
};

static enum TranslationNumber PostProcessLimiterMaxAttack_Dependencies[] =/* '<S1850>/maxAttack tune' */
{
    ID_Translation_Model_1497,
};

static enum TranslationNumber PostProcessLimiterMaxAttack_low_Dependencies[] =/* '<S1850>/maxAttack tune1' */
{
    ID_Translation_Model_1500,
};

static enum TranslationNumber PostProcessMuteRampTime_Dependencies[] =/* '<S1871>/Tune Variable' */
{
    ID_Translation_Model_72_276_67_18,
};

static enum TranslationNumber
    PostProcessPostLimiterEqsosCoefficients_Dependencies[] =/* '<S1876>/Tune Variable2' */
{
    ID_Translation_Model_76_36,
};

static enum TranslationNumber PostProcessPostLimiterEqnumStages_Dependencies[] =/* '<S1876>/Tune Variable1' */
{
    ID_Translation_Model_76_36,
};

static enum TranslationNumber PostProcessSoftClipperYMax_Dependencies[] =/* '<S1880>/ymax TuneVar' */
{
    ID_Translation_Model_1527,
};

static enum TranslationNumber PostProcessSoftClipperXMin_Dependencies[] =/* '<S1880>/xmin TuneVar' */
{
    ID_Translation_Model_1527,
};

static enum TranslationNumber PostProcessSoftClipperYMaxLow_Dependencies[] =/* '<S1880>/ymax TuneVar1' */
{
    ID_Translation_Model_1528,
};

static enum TranslationNumber PostProcessSoftClipperXMinLow_Dependencies[] =/* '<S1880>/xmin TuneVar1' */
{
    ID_Translation_Model_1528,
};

static enum TranslationNumber InputSelectRouterCfgMap_Dependencies[] =/* '<S7>/TuneVarRouterMap' */
{
    ID_Translation_Model_397,
};

static enum TranslationNumber PreAmpMedusaSurroundOn_Dependencies[] =/* '<S598>/TuneVar' */
{
    ID_Translation_Model_141_246_96,
};

static enum TranslationNumber
    PreAmpMedusaBassManagerLeftMixWeights_Dependencies[] =/* '<S605>/LeftMixIns' */
{
    ID_Translation_Model_141_246_96,
};

static enum TranslationNumber
    PreAmpMedusaBassManagerRightMixWeights_Dependencies[] =/* '<S605>/RightMixIns' */
{
    ID_Translation_Model_141_246_96,
};

static enum TranslationNumber
    PreAmpMedusaBassManagerHpfsosCoefficients_Dependencies[] =/* '<S612>/Tune Variable2' */
{
    ID_Translation_Model_141_246_141_36,
};

static enum TranslationNumber PreAmpMedusaBassManagerHpfnumStages_Dependencies[]
    =                                  /* '<S612>/Tune Variable1' */
{
    ID_Translation_Model_141_246_141_36,
};

static enum TranslationNumber
    PreAmpMedusaBassManagerLpfsosCoefficients_Dependencies[] =/* '<S616>/Tune Variable2' */
{
    ID_Translation_Model_141_246_148_36,
};

static enum TranslationNumber PreAmpMedusaBassManagerLpfnumStages_Dependencies[]
    =                                  /* '<S616>/Tune Variable1' */
{
    ID_Translation_Model_141_246_148_36,
};

static enum TranslationNumber PreAmpMedusaBassManagerGainLfe2C_Dependencies[] =/* '<S608>/Tune Variable' */
{
    ID_Translation_Model_141_246_111_67_18,
};

static enum TranslationNumber PreAmpMedusaDummyTune_Dependencies[] =/* '<S625>/Tune Variable' */
{
    ID_Translation_Model_141_1196_67_18,
};

static enum TranslationNumber
    PreAmpMedusaDeciRateFdpLsSmoothCutoff_Dependencies[] =/* '<S639>/Tune Variable3' */
{
    ID_Translation_Model_141_1990,
};

static enum TranslationNumber
    PreAmpMedusaDeciRateFdpSlowPsdSmoothCutoff_Dependencies[] =/* '<S639>/Tune Variable' */
{
    ID_Translation_Model_141_1988,
};

static enum TranslationNumber
    PreAmpMedusaDeciRateFdpFastPsdSmoothCutoff_Dependencies[] =/* '<S639>/Tune Variable1' */
{
    ID_Translation_Model_141_1988,
};

static enum TranslationNumber PreAmpMedusaDeciRateFdpDirectPathSec_Dependencies[]
    =                                  /* '<S639>/Tune Variable2' */
{
    ID_Translation_Model_141_1989,
};

static enum TranslationNumber PreAmpMedusaDeciRateFdpXpMax_Dependencies[] =/* '<S639>/Tune Variable7' */
{
    ID_Translation_Model_141_1560,
};

static enum TranslationNumber PreAmpMedusaDeciRateFdpCoeffsXpMin_Dependencies[] =/* '<S646>/Tune Variable3' */
{
    ID_Translation_Model_141_1560,
};

static enum TranslationNumber
    PreAmpMedusaDeciRateFdpCoeffsESDUpperbounddB_Dependencies[] =/* '<S646>/Tune Variable1' */
{
    ID_Translation_Model_141_1561,
};

static enum TranslationNumber
    PreAmpMedusaDeciRateFdpCoeffsESDLowerbounddB_Dependencies[] =/* '<S646>/Tune Variable2' */
{
    ID_Translation_Model_141_1561,
};

static enum TranslationNumber PreAmpMedusaDeciRateFdpSpumOverwrite_Dependencies[]
    =                                  /* '<S641>/Tune Variable' */
{
    ID_Translation_Model_141_2031_67_18,
};

static enum TranslationNumber
    PreAmpMedusaFullRateFdpLsSmoothCutoff_Dependencies[] =/* '<S666>/Tune Variable3' */
{
    ID_Translation_Model_141_2656,
};

static enum TranslationNumber
    PreAmpMedusaFullRateFdpSlowPsdSmoothCutoff_Dependencies[] =/* '<S666>/Tune Variable' */
{
    ID_Translation_Model_141_2654,
};

static enum TranslationNumber
    PreAmpMedusaFullRateFdpFastPsdSmoothCutoff_Dependencies[] =/* '<S666>/Tune Variable1' */
{
    ID_Translation_Model_141_2654,
};

static enum TranslationNumber PreAmpMedusaFullRateFdpDirectPathSec_Dependencies[]
    =                                  /* '<S666>/Tune Variable2' */
{
    ID_Translation_Model_141_2655,
};

static enum TranslationNumber PreAmpMedusaFullRateFdpXpMax_Dependencies[] =/* '<S666>/Tune Variable7' */
{
    ID_Translation_Model_141_2423,
};

static enum TranslationNumber PreAmpMedusaFullRateFdpCoeffsXpMax_Dependencies[] =/* '<S673>/Tune Variable' */
{
    ID_Translation_Model_141_2423,
};

static enum TranslationNumber PreAmpMedusaFullRateFdpCoeffsXpMin_Dependencies[] =/* '<S673>/Tune Variable3' */
{
    ID_Translation_Model_141_2423,
};

static enum TranslationNumber
    PreAmpMedusaFullRateFdpCoeffsESDUpperbounddB_Dependencies[] =/* '<S673>/Tune Variable1' */
{
    ID_Translation_Model_141_2424,
};

static enum TranslationNumber
    PreAmpMedusaFullRateFdpCoeffsESDLowerbounddB_Dependencies[] =/* '<S673>/Tune Variable2' */
{
    ID_Translation_Model_141_2424,
};

static enum TranslationNumber PreAmpMedusaFullRateFdpSpumOverwrite_Dependencies[]
    =                                  /* '<S668>/Tune Variable' */
{
    ID_Translation_Model_141_2697_67_18,
};

static enum TranslationNumber PreAmpMedusaMonoDetectorLevelCutoff_Dependencies[]
    =                                  /* '<S695>/Tune Variable' */
{
    ID_Translation_Model_141_2783,
};

static enum TranslationNumber
    PreAmpMedusaMonoDetectorLSSmoothCutoff_Dependencies[] =/* '<S695>/Tune Variable1' */
{
    ID_Translation_Model_141_2783,
};

static enum TranslationNumber
    PreAmpMedusaMonoDetectorLSSmoothResetCutoff_Dependencies[] =/* '<S695>/Tune Variable2' */
{
    ID_Translation_Model_141_2783,
};

static enum TranslationNumber PreAmpMedusaMonoDetectorHPFCutoff_Dependencies[] =/* '<S695>/Tune Variable7' */
{
    ID_Translation_Model_141_2787,
};

static enum TranslationNumber PreAmpMedusaMonoDetectorNoiseFloordB_Dependencies[]
    =                                  /* '<S695>/Tune Variable3' */
{
    ID_Translation_Model_141_2784,
};

static enum TranslationNumber
    PreAmpMedusaMonoDetectorLRMatchTolerancedB_Dependencies[] =/* '<S695>/Tune Variable4' */
{
    ID_Translation_Model_141_2785,
};

static enum TranslationNumber
    PreAmpMedusaMonoDetectorThresholdMonoInput_Dependencies[] =/* '<S695>/Tune Variable5' */
{
    ID_Translation_Model_141_2786,
};

static enum TranslationNumber
    PreAmpMedusaMonoDetectorThresholdStereoInput_Dependencies[] =/* '<S695>/Tune Variable6' */
{
    ID_Translation_Model_141_2786,
};

static enum TranslationNumber PreAmpMedusaMonoDetectorEnable_Dependencies[] =/* '<S694>/Tune Variable' */
{
    ID_Translation_Model_141_2808_67_18,
};

static enum TranslationNumber
    PreAmpMedusaSPUMDecayEstPSDSmoothCutoff_Dependencies[] =/* '<S715>/Tune Variable' */
{
    ID_Translation_Model_141_2849,
};

static enum TranslationNumber
    PreAmpMedusaSPUMDecayEstDecaySmoothCutoff_Dependencies[] =/* '<S715>/Tune Variable1' */
{
    ID_Translation_Model_141_2850,
};

static enum TranslationNumber
    PreAmpMedusaSPUMDecayEstFastAttackCutoff_Dependencies[] =/* '<S715>/Tune Variable2' */
{
    ID_Translation_Model_141_2851,
};

static enum TranslationNumber
    PreAmpMedusaSPUMDecayEstSlowAttackCutoff_Dependencies[] =/* '<S715>/Tune Variable3' */
{
    ID_Translation_Model_141_2851,
};

static enum TranslationNumber PreAmpMedusaSPUMDecayEstStepSize_Dependencies[] =/* '<S715>/Tune Variable4' */
{
    ID_Translation_Model_141_2852,
};

static enum TranslationNumber
    PreAmpMedusaSPUMDecayEstDirectPathSec_Dependencies[] =/* '<S715>/Tune Variable5' */
{
    ID_Translation_Model_141_2853,
};

static enum TranslationNumber PreAmpMedusaSPUMDecayEstNoiseFloor_Dependencies[] =/* '<S727>/Tune Variable' */
{
    ID_Translation_Model_141_2865_67_18,
};

static enum TranslationNumber
    PreAmpMedusaSPUMDecayEstOnsetThreshold_Dependencies[] =/* '<S728>/Tune Variable' */
{
    ID_Translation_Model_141_2866_67_18,
};

static enum TranslationNumber
    PreAmpMedusaSPUMDecayEstSlewThreshold_Dependencies[] =/* '<S729>/Tune Variable' */
{
    ID_Translation_Model_141_2867_67_18,
};

static enum TranslationNumber
    PreAmpMedusaSPUMDecayEstHPFsosCoefficients_Dependencies[] =/* '<S748>/Tune Variable2' */
{
    ID_Translation_Model_141_2878_50_36,
};

static enum TranslationNumber PreAmpMedusaSPUMDecayEstHPFnumStages_Dependencies[]
    =                                  /* '<S748>/Tune Variable1' */
{
    ID_Translation_Model_141_2878_50_36,
};

static enum TranslationNumber PreAmpFadeControlBoostDisable_Dependencies[] =/* '<S1068>/Tune Variable' */
{
    ID_Translation_Model_449_67_18,
};

static enum TranslationNumber PreAmpFadeControlEnableSilentExtreme_Dependencies[]
    =                                  /* '<S1069>/Tune Variable' */
{
    ID_Translation_Model_450_67_18,
};

static enum TranslationNumber PreAmpFadeControlTable_Dependencies[] =/* '<S1070>/TuneVarFadeTable' */
{
    ID_Translation_Model_455,
};

static enum TranslationNumber PreAmpFadeControloffset_Dependencies[] =/* '<S1071>/Tune Variable' */
{
    ID_Translation_Model_459_67_18,
};

static enum TranslationNumber PreAmpFadeControlRampTime_Dependencies[] =/* '<S1072>/Tune Variable' */
{
    ID_Translation_Model_460_67_18,
};

static enum TranslationNumber PreAmpFadeRamperDRChannelToRamperMap_Dependencies[]
    =                                  /* '<S1092>/TuneVarChannelRamperMap' */
{
    ID_Translation_Model_175_136_99,
};

static enum TranslationNumber PreAmpFadeRamperDRCutoffHz_Dependencies[] =/* '<S1092>/TuneVarCutoffHz' */
{
    ID_Translation_Model_175_136_98,
};

static enum TranslationNumber PreAmpFadeRamperFRChannelToRamperMap_Dependencies[]
    =                                  /* '<S1099>/TuneVarChannelRamperMap' */
{
    ID_Translation_Model_176_136_99,
};

static enum TranslationNumber PreAmpFadeRamperFRCutoffHz_Dependencies[] =/* '<S1099>/TuneVarCutoffHz' */
{
    ID_Translation_Model_176_136_98,
};

static enum TranslationNumber PreAmpMuteControlRampTime_Dependencies[] =/* '<S1107>/Tune Variable' */
{
    ID_Translation_Model_489_67_18,
};

static enum TranslationNumber
    PreAmpSleepingBeautyDRChannelToRamperMap_Dependencies[] =/* '<S1112>/TuneVarChannelRamperMap' */
{
    ID_Translation_Model_533,
};

static enum TranslationNumber PreAmpSleepingBeautyDROffset_Dependencies[] =/* '<S1114>/Tune Variable' */
{
    ID_Translation_Model_538_67_18,
};

static enum TranslationNumber PreAmpSleepingBeautyDRRampTime_Dependencies[] =/* '<S1115>/Tune Variable' */
{
    ID_Translation_Model_539_67_18,
};

static enum TranslationNumber PreAmpSleepingBeautyDRMutesBass_Dependencies[] =/* '<S1116>/Tune Variable' */
{
    ID_Translation_Model_540_67_18,
};

static enum TranslationNumber PreAmpSleepingBeautyDRTaperGainTable_Dependencies[]
    =                                  /* '<S1117>/Tune Variable' */
{
    ID_Translation_Model_545,
};

static enum TranslationNumber
    PreAmpSleepingBeautyFRChannelToRamperMap_Dependencies[] =/* '<S1135>/TuneVarChannelRamperMap' */
{
    ID_Translation_Model_596,
};

static enum TranslationNumber PreAmpSleepingBeautyFROffset_Dependencies[] =/* '<S1137>/Tune Variable' */
{
    ID_Translation_Model_601_67_18,
};

static enum TranslationNumber PreAmpSleepingBeautyFRRampTime_Dependencies[] =/* '<S1138>/Tune Variable' */
{
    ID_Translation_Model_602_67_18,
};

static enum TranslationNumber PreAmpSleepingBeautyFRMutesBass_Dependencies[] =/* '<S1139>/Tune Variable' */
{
    ID_Translation_Model_603_67_18,
};

static enum TranslationNumber PreAmpSleepingBeautyFRTaperGainTable_Dependencies[]
    =                                  /* '<S1140>/Tune Variable' */
{
    ID_Translation_Model_608,
};

static enum TranslationNumber PreAmpAudiopilotTwoDowngrade_Dependencies[] =/* '<S22>/Tune Variable' */
{
    ID_Translation_Model_117_21_67_18,
};

static enum TranslationNumber PreAmpAudiopilotHvacTable_Dependencies[] =/* '<S28>/Tune Variable' */
{
    ID_Translation_Model_117_1781,
};

static enum TranslationNumber PreAmpAudiopilotAntiZipperRampFreqHz_Dependencies[]
    =                                  /* '<S33>/Tune Variable' */
{
    ID_Translation_Model_117_43_332,
};

static enum TranslationNumber PreAmpAudiopilotBassBpfCenterFreqHz_Dependencies[]
    =                                  /* '<S34>/Tune Variable' */
{
    ID_Translation_Model_117_43_351,
};

static enum TranslationNumber PreAmpAudiopilotBassBpfQ_Dependencies[] =/* '<S34>/Tune Variable1' */
{
    ID_Translation_Model_117_43_351,
};

static enum TranslationNumber
    PreAmpAudiopilotMidrangeLpfCutoffFreqHz_Dependencies[] =/* '<S35>/Tune Variable' */
{
    ID_Translation_Model_117_43_340,
};

static enum TranslationNumber
    PreAmpAudiopilotMidrangeLpfAlignDelaySamples_Dependencies[] =/* '<S46>/Tune Variable' */
{
    ID_Translation_Model_117_43_403,
};

static enum TranslationNumber PreAmpAudiopilotAudiopilotOn_Dependencies[] =/* '<S53>/AudiopilotOn' */
{
    ID_Translation_Model_117_44_721,
    ID_Translation_Model_117_44_722,
    ID_Translation_Model_117_44_723,
    ID_Translation_Model_117_44_894,
    ID_Translation_Model_117_44_736,
    ID_Translation_Model_117_44_895,
};

static enum TranslationNumber PreAmpAudiopilotBassSlope0Dbperdb_Dependencies[] =/* '<S53>/BassSlope0' */
{
    ID_Translation_Model_117_44_721,
};

static enum TranslationNumber
    PreAmpAudiopilotMidrangeSlope0DbPerDb_Dependencies[] =/* '<S53>/MidrangeSlope0' */
{
    ID_Translation_Model_117_44_722,
};

static enum TranslationNumber PreAmpAudiopilotTrebleSlope0DbPerDb_Dependencies[]
    =                                  /* '<S53>/TrebleSlope0' */
{
    ID_Translation_Model_117_44_723,
};

static enum TranslationNumber PreAmpAudiopilotBassSlope1DbPerDb_Dependencies[] =/* '<S53>/BassSlope1' */
{
    ID_Translation_Model_117_44_894,
};

static enum TranslationNumber
    PreAmpAudiopilotMidrangeSlope1DbPerDb_Dependencies[] =/* '<S53>/MidrangeSlope1' */
{
    ID_Translation_Model_117_44_736,
};

static enum TranslationNumber PreAmpAudiopilotTrebleSlope1DbPerDb_Dependencies[]
    =                                  /* '<S53>/TrebleSlope1' */
{
    ID_Translation_Model_117_44_895,
};

static enum TranslationNumber PreAmpAudiopilotBassThresh0Db_Dependencies[] =/* '<S54>/Tune Variable' */
{
    ID_Translation_Model_117_44_469_67_18,
};

static enum TranslationNumber PreAmpAudiopilotBassThresh1Db_Dependencies[] =/* '<S55>/Tune Variable' */
{
    ID_Translation_Model_117_44_470_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotHfNoiseHighBoundDbspl_Dependencies[] =/* '<S56>/Tune Variable' */
{
    ID_Translation_Model_117_44_332_67_18,
};

static enum TranslationNumber PreAmpAudiopilotHfNoiseLowBoundDbspl_Dependencies[]
    =                                  /* '<S57>/Tune Variable' */
{
    ID_Translation_Model_117_44_333_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotLfNoiseHighBoundDbspl_Dependencies[] =/* '<S58>/Tune Variable' */
{
    ID_Translation_Model_117_44_334_67_18,
};

static enum TranslationNumber PreAmpAudiopilotLfNoiseLowBoundDbspl_Dependencies[]
    =                                  /* '<S59>/Tune Variable' */
{
    ID_Translation_Model_117_44_335_67_18,
};

static enum TranslationNumber PreAmpAudiopilotMidrangeThresh0Db_Dependencies[] =/* '<S60>/Tune Variable' */
{
    ID_Translation_Model_117_44_341_67_18,
};

static enum TranslationNumber PreAmpAudiopilotMidrangeThresh1Db_Dependencies[] =/* '<S61>/Tune Variable' */
{
    ID_Translation_Model_117_44_342_67_18,
};

static enum TranslationNumber PreAmpAudiopilotTrebleThresh0Db_Dependencies[] =/* '<S62>/Tune Variable' */
{
    ID_Translation_Model_117_44_484_67_18,
};

static enum TranslationNumber PreAmpAudiopilotTrebleThresh1Db_Dependencies[] =/* '<S63>/Tune Variable' */
{
    ID_Translation_Model_117_44_485_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotBassDownwardThreshDbspl_Dependencies[] =/* '<S122>/Tune Variable' */
{
    ID_Translation_Model_117_44_315_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotBassMaxAudiopilotBoostDb_Dependencies[] =/* '<S123>/Tune Variable' */
{
    ID_Translation_Model_117_44_316_67_18,
};

static enum TranslationNumber PreAmpAudiopilotBassMaxDyneqBoostDb_Dependencies[]
    =                                  /* '<S124>/Tune Variable' */
{
    ID_Translation_Model_117_44_317_67_18,
};

static enum TranslationNumber PreAmpAudiopilotBassMaxTotalBoostDb_Dependencies[]
    =                                  /* '<S125>/Tune Variable' */
{
    ID_Translation_Model_117_44_318_67_18,
};

static enum TranslationNumber PreAmpAudiopilotDownwardExpansionOn_Dependencies[]
    =                                  /* '<S126>/DownwardExpansionOn' */
{
    ID_Translation_Model_117_44_645,
    ID_Translation_Model_117_44_672,
    ID_Translation_Model_117_44_666,
};

static enum TranslationNumber
    PreAmpAudiopilotMidrangeDownwardSlopeDbPerDb_Dependencies[] =/* '<S126>/MidrangeDownwardSlope' */
{
    ID_Translation_Model_117_44_666,
};

static enum TranslationNumber
    PreAmpAudiopilotBassDownwardSlopeDbPerDb_Dependencies[] =/* '<S126>/BassDownwardSlope' */
{
    ID_Translation_Model_117_44_645,
};

static enum TranslationNumber
    PreAmpAudiopilotTrebleDownwardSlopeDbPerDb_Dependencies[] =/* '<S126>/TrebleDownwardSlope' */
{
    ID_Translation_Model_117_44_672,
};

static enum TranslationNumber PreAmpAudiopilotDyneqBassThreshDbspl_Dependencies[]
    =                                  /* '<S127>/Tune Variable' */
{
    ID_Translation_Model_117_44_325_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotDyneqBassSlopeDbPerDb_Dependencies[] =/* '<S128>/DyneqBassSlope' */
{
    ID_Translation_Model_117_44_633,
};

static enum TranslationNumber PreAmpAudiopilotDyneqOn_Dependencies[] =/* '<S128>/DyneqOn' */
{
    ID_Translation_Model_117_44_633,
};

static enum TranslationNumber PreAmpAudiopilotMinSignalLevelDbspl_Dependencies[]
    =                                  /* '<S166>/Tune Variable' */
{
    ID_Translation_Model_117_44_343_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotMidrangeDownwardThreshDbspl_Dependencies[] =/* '<S130>/Tune Variable' */
{
    ID_Translation_Model_117_44_337_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotMidrangeMaxTotalBoostDb_Dependencies[] =/* '<S131>/Tune Variable' */
{
    ID_Translation_Model_117_44_338_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotTrebleDownwardThreshDbspl_Dependencies[] =/* '<S132>/Tune Variable' */
{
    ID_Translation_Model_117_44_913_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotTrebleMaxTotalBoostDb_Dependencies[] =/* '<S133>/Tune Variable' */
{
    ID_Translation_Model_117_44_346_67_18,
};

static enum TranslationNumber PreAmpAudiopilotEnableRampTauS_Dependencies[] =/* '<S187>/Tune Variable' */
{
    ID_Translation_Model_117_44_328,
};

static enum TranslationNumber PreAmpAudiopilotHfNoiseRefPowerMinDb_Dependencies[]
    =                                  /* '<S199>/Tune Variable' */
{
    ID_Translation_Model_117_516_1944,
};

static enum TranslationNumber
    PreAmpAudiopilotHfNoiseImpulseRejectionMinstatAlphaFactor_Dependencies[] =/* '<S210>/Tune Variable' */
{
    ID_Translation_Model_117_516_1707_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotHfNoiseImpulseRejectionMinstatAlphaMin_Dependencies[] =/* '<S211>/Tune Variable' */
{
    ID_Translation_Model_117_516_1708_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotHfNoiseImpulseRejectionMinstatBeta_Dependencies[] =/* '<S220>/Tune Variable' */
{
    ID_Translation_Model_117_516_1732_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotHfNoiseImpulseRejectionMinstatMin_Dependencies[] =/* '<S221>/Tune Variable' */
{
    ID_Translation_Model_117_516_1733_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessHighIndex_Dependencies[] =/* '<S230>/Tune Variable' */
{
    ID_Translation_Model_117_516_1751_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessLowIndex_Dependencies[] =/* '<S231>/Tune Variable' */
{
    ID_Translation_Model_117_516_1752_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessThresh_Dependencies[] =/* '<S232>/Tune Variable' */
{
    ID_Translation_Model_117_516_1753_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotHfNoiseImpulseRejectionMinSearchCoef_Dependencies[] =/* '<S233>/Tune Variable' */
{
    ID_Translation_Model_117_516_1755_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotHfNoiseImpulseRejectionMinSearchMinGain_Dependencies[] =/* '<S234>/Tune Variable' */
{
    ID_Translation_Model_117_516_1754_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotHfNoiseImpulseRejectionSubWinTimeS_Dependencies[] =/* '<S235>/Tune Variable' */
{
    ID_Translation_Model_117_516_1758,
};

static enum TranslationNumber
    PreAmpAudiopilotHfNoiseImpulseRejectionLevelUpdateCoef_Dependencies[] =/* '<S259>/Tune Variable' */
{
    ID_Translation_Model_117_516_1774_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotHfNoiseSlewAttackDbPerS_Dependencies[] =/* '<S264>/Tune Variable' */
{
    ID_Translation_Model_117_516_1789,
};

static enum TranslationNumber
    PreAmpAudiopilotHfNoiseSlewDecayDbPerS_Dependencies[] =/* '<S265>/Tune Variable' */
{
    ID_Translation_Model_117_516_1795,
};

static enum TranslationNumber
    PreAmpAudiopilotHfNoiseSlewThresholdDb_Dependencies[] =/* '<S266>/Tune Variable' */
{
    ID_Translation_Model_117_516_1804_67_18,
};

static enum TranslationNumber PreAmpAudiopilotHfNoiseOffsetDb_Dependencies[] =/* '<S205>/Tune Variable' */
{
    ID_Translation_Model_117_516_1778_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotHfNoisePreprocessAntiAliassosCoefficients_Dependencies[] =/* '<S284>/Tune Variable2' */
{
    ID_Translation_Model_117_516_1849_50_36,
};

static enum TranslationNumber
    PreAmpAudiopilotHfNoisePreprocessAntiAliasnumStages_Dependencies[] =/* '<S284>/Tune Variable1' */
{
    ID_Translation_Model_117_516_1849_50_36,
};

static enum TranslationNumber
    PreAmpAudiopilotHfNoisePreprocessBandpassLowpasssosCoefficients_Dependencies[]
    =                                  /* '<S289>/Tune Variable2' */
{
    ID_Translation_Model_117_516_1847_50_36,
};

static enum TranslationNumber
    PreAmpAudiopilotHfNoisePreprocessBandpassLowpassnumStages_Dependencies[] =/* '<S289>/Tune Variable1' */
{
    ID_Translation_Model_117_516_1847_50_36,
};

static enum TranslationNumber PreAmpAudiopilotHfNoiseRefLatencyMs_Dependencies[]
    =                                  /* '<S293>/Tune Variable' */
{
    ID_Translation_Model_117_516_957,
};

static enum TranslationNumber PreAmpAudiopilotLfNoiseEnergyLpfTauS_Dependencies[]
    =                                  /* '<S297>/Tune Variable' */
{
    ID_Translation_Model_117_517_435,
};

static enum TranslationNumber
    PreAmpAudiopilotLfNoiseImpulseRejectionGamma0TauS_Dependencies[] =/* '<S307>/Tune Variable' */
{
    ID_Translation_Model_117_517_422,
};

static enum TranslationNumber
    PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceFiltTauS_Dependencies[]
    =                                  /* '<S308>/Tune Variable' */
{
    ID_Translation_Model_117_517_415,
};

static enum TranslationNumber
    PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceScale_Dependencies[] =/* '<S309>/Tune Variable' */
{
    ID_Translation_Model_117_517_330_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotLfNoiseImpulseRejectionMusicVarianceScale_Dependencies[] =/* '<S310>/Tune Variable' */
{
    ID_Translation_Model_117_517_331_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVarianceScale_Dependencies[] =/* '<S311>/Tune Variable' */
{
    ID_Translation_Model_117_517_332_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotLfNoiseImpulseRejectionOutputMin_Dependencies[] =/* '<S312>/Tune Variable' */
{
    ID_Translation_Model_117_517_429_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotLfNoiseMicsosCoefficients_Dependencies[] =/* '<S338>/Tune Variable2' */
{
    ID_Translation_Model_117_517_515_50_36,
};

static enum TranslationNumber PreAmpAudiopilotLfNoiseMicnumStages_Dependencies[]
    =                                  /* '<S338>/Tune Variable1' */
{
    ID_Translation_Model_117_517_515_50_36,
};

static enum TranslationNumber
    PreAmpAudiopilotLfNoiseRefsosCoefficients_Dependencies[] =/* '<S343>/Tune Variable2' */
{
    ID_Translation_Model_117_517_516_50_36,
};

static enum TranslationNumber PreAmpAudiopilotLfNoiseRefnumStages_Dependencies[]
    =                                  /* '<S343>/Tune Variable1' */
{
    ID_Translation_Model_117_517_516_50_36,
};

static enum TranslationNumber PreAmpAudiopilotLfNoiseOffsetDb_Dependencies[] =/* '<S300>/Tune Variable' */
{
    ID_Translation_Model_117_517_459_67_18,
};

static enum TranslationNumber PreAmpAudiopilotLfNoiseRefLatencyMs_Dependencies[]
    =                                  /* '<S351>/Tune Variable' */
{
    ID_Translation_Model_117_517_351,
};

static enum TranslationNumber
    PreAmpAudiopilotLfNoiseSlewAttackDbPerS_Dependencies[] =/* '<S357>/Tune Variable' */
{
    ID_Translation_Model_117_517_388,
};

static enum TranslationNumber
    PreAmpAudiopilotLfNoiseSlewDecayDbPerS_Dependencies[] =/* '<S358>/Tune Variable' */
{
    ID_Translation_Model_117_517_397,
};

static enum TranslationNumber
    PreAmpAudiopilotLfNoiseSlewSlowDbPerS_Dependencies[] =/* '<S359>/Tune Variable' */
{
    ID_Translation_Model_117_517_404,
};

static enum TranslationNumber
    PreAmpAudiopilotLfNoiseSlewThresholdDb_Dependencies[] =/* '<S360>/Tune Variable' */
{
    ID_Translation_Model_117_517_270_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotLfNoiseSpeedBoundsAxis_Dependencies[] =/* '<S374>/Tune Variable' */
{
    ID_Translation_Model_117_517_572_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotLfNoiseSpeedBoundsMaxDbspl_Dependencies[] =/* '<S375>/Tune Variable' */
{
    ID_Translation_Model_117_517_573_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotLfNoiseSpeedBoundsMindBSPL_Dependencies[] =/* '<S376>/Tune Variable' */
{
    ID_Translation_Model_117_517_577,
};

static enum TranslationNumber PreAmpAudiopilotLfNoiseSpeedBoundsOn_Dependencies[]
    =                                  /* '<S377>/Tune Variable' */
{
    ID_Translation_Model_117_517_582_67_18,
};

static enum TranslationNumber PreAmpAudiopilotLfNoiseSysMaxDbspl_Dependencies[] =/* '<S303>/Tune Variable' */
{
    ID_Translation_Model_117_517_553_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotRatioUpdateFlagHoldTimeS_Dependencies[] =/* '<S403>/Tune Variable' */
{
    ID_Translation_Model_117_2074,
};

static enum TranslationNumber
    PreAmpAudiopilotRatioUpdateHfNoiseThreshDbspl_Dependencies[] =/* '<S404>/Tune Variable' */
{
    ID_Translation_Model_117_2078_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotRatioUpdateLfNoiseThreshDbspl_Dependencies[] =/* '<S405>/Tune Variable' */
{
    ID_Translation_Model_117_2079_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotRatioUpdateLfNoiseUpdatePeriodS_Dependencies[] =/* '<S406>/Tune Variable' */
{
    ID_Translation_Model_117_2082,
};

static enum TranslationNumber
    PreAmpAudiopilotRatioUpdateLfNoiseUpdateThreshDb_Dependencies[] =/* '<S407>/Tune Variable' */
{
    ID_Translation_Model_117_2086_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotRatioUpdateSpeedUpdateThreshMph_Dependencies[] =/* '<S408>/Tune Variable' */
{
    ID_Translation_Model_117_2087_67_18,
};

static enum TranslationNumber PreAmpAudiopilotRatioEnergyLpfTauS_Dependencies[] =/* '<S398>/Tune Variable' */
{
    ID_Translation_Model_117_2093,
};

static enum TranslationNumber PreAmpAudiopilotRatioHighBoundDb_Dependencies[] =/* '<S399>/Tune Variable' */
{
    ID_Translation_Model_117_2099_67_18,
};

static enum TranslationNumber PreAmpAudiopilotRatioLowBoundDb_Dependencies[] =/* '<S400>/Tune Variable' */
{
    ID_Translation_Model_117_2100_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotRatioSlewAttackDbPerS_Dependencies[] =/* '<S442>/Tune Variable' */
{
    ID_Translation_Model_117_2115,
};

static enum TranslationNumber PreAmpAudiopilotRatioSlewDecayDbPerS_Dependencies[]
    =                                  /* '<S443>/Tune Variable' */
{
    ID_Translation_Model_117_2121,
};

static enum TranslationNumber PreAmpAudiopilotRatioSlewThresholdDb_Dependencies[]
    =                                  /* '<S444>/Tune Variable' */
{
    ID_Translation_Model_117_2125_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotRatioImpulseRejectionGamma0TauS_Dependencies[] =/* '<S455>/Tune Variable' */
{
    ID_Translation_Model_117_2149,
};

static enum TranslationNumber
    PreAmpAudiopilotRatioImpulseRejectionImpulseVarianceLpfTauS_Dependencies[] =/* '<S456>/Tune Variable' */
{
    ID_Translation_Model_117_2155,
};

static enum TranslationNumber
    PreAmpAudiopilotRatioImpulseRejectionImpulseVarianceScale_Dependencies[] =/* '<S457>/Tune Variable' */
{
    ID_Translation_Model_117_2158_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotRatioImpulseRejectionNoiseVarianceScale_Dependencies[] =/* '<S458>/Tune Variable' */
{
    ID_Translation_Model_117_2159_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotLevelDetectFastDecayDbPerS_Dependencies[] =/* '<S477>/Tune Variable' */
{
    ID_Translation_Model_120_196,
};

static enum TranslationNumber
    PreAmpAudiopilotLevelDetectHoldMarginDb_Dependencies[] =/* '<S478>/Tune Variable' */
{
    ID_Translation_Model_120_446,
};

static enum TranslationNumber PreAmpAudiopilotLevelDetectHoldTimeS_Dependencies[]
    =                                  /* '<S479>/Tune Variable' */
{
    ID_Translation_Model_120_203,
};

static enum TranslationNumber
    PreAmpAudiopilotLevelDetectMaxVolumeDb_Dependencies[] =/* '<S480>/Tune Variable' */
{
    ID_Translation_Model_120_122_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotLevelDetectMinVolumeDb_Dependencies[] =/* '<S481>/Tune Variable' */
{
    ID_Translation_Model_120_123_67_18,
};

static enum TranslationNumber
    PreAmpAudiopilotLevelDetectSlowDecayDbPerS_Dependencies[] =/* '<S482>/Tune Variable' */
{
    ID_Translation_Model_120_189,
};

static enum TranslationNumber
    PreAmpDyneqLevelDetectFastDecayDbPerS_Dependencies[] =/* '<S504>/Tune Variable' */
{
    ID_Translation_Model_120_264,
};

static enum TranslationNumber PreAmpDyneqLevelDetectHoldMarginDb_Dependencies[] =/* '<S505>/Tune Variable' */
{
    ID_Translation_Model_120_514,
};

static enum TranslationNumber PreAmpDyneqLevelDetectHoldTimeS_Dependencies[] =/* '<S506>/Tune Variable' */
{
    ID_Translation_Model_120_257,
};

static enum TranslationNumber PreAmpDyneqLevelDetectMaxVolumeDb_Dependencies[] =/* '<S507>/Tune Variable' */
{
    ID_Translation_Model_120_218_67_18,
};

static enum TranslationNumber PreAmpDyneqLevelDetectMinVolumeDb_Dependencies[] =/* '<S508>/Tune Variable' */
{
    ID_Translation_Model_120_219_67_18,
};

static enum TranslationNumber
    PreAmpDyneqLevelDetectSlowDecayDbPerS_Dependencies[] =/* '<S509>/Tune Variable' */
{
    ID_Translation_Model_120_250,
};

static enum TranslationNumber PreAmpLevelDetectLatencyMs_Dependencies[] =/* '<S530>/Tune Variable' */
{
    ID_Translation_Model_120_439,
};

static enum TranslationNumber
    PreAmpLevelDetectPreemphasissosCoefficients_Dependencies[] =/* '<S537>/Tune Variable2' */
{
    ID_Translation_Model_120_422_50_36,
};

static enum TranslationNumber
    PreAmpLevelDetectPreemphasisnumStages_Dependencies[] =/* '<S537>/Tune Variable1' */
{
    ID_Translation_Model_120_422_50_36,
};

static enum TranslationNumber PreAmpLevelDetectSysMaxDbspl_Dependencies[] =/* '<S532>/Tune Variable' */
{
    ID_Translation_Model_120_319_67_18,
};

static enum TranslationNumber PreAmpVolumeCfgTable_Dependencies[] =/* '<S545>/TuneVar_Table' */
{
    ID_Translation_Model_123_280,
};

static enum TranslationNumber PreAmpVolumeCfgmaxgain_Dependencies[] =/* '<S548>/Tune Variable' */
{
    ID_Translation_Model_123_281_67_18,
};

static enum TranslationNumber PreAmpVolumeCfgRampTime_Dependencies[] =/* '<S546>/Tune Variable' */
{
    ID_Translation_Model_123_256_67_18,
};

static enum TranslationNumber PreAmpBalance_CfgChanRampMap_Dependencies[] =/* '<S565>/TuneVarChanRampMap' */
{
    ID_Translation_Model_135_79,
};

static enum TranslationNumber PreAmpBalance_CfgBoostDisable_Dependencies[] =/* '<S567>/Tune Variable' */
{
    ID_Translation_Model_135_81_67_18,
};

static enum TranslationNumber PreAmpBalance_CfgOffset_Dependencies[] =/* '<S568>/Tune Variable' */
{
    ID_Translation_Model_135_83_67_18,
};

static enum TranslationNumber PreAmpBalance_CfgRampTime_Dependencies[] =/* '<S569>/Tune Variable' */
{
    ID_Translation_Model_135_84_67_18,
};

static enum TranslationNumber
    PreAmpBalance_CfgSleepingBeautyMutesBass_Dependencies[] =/* '<S570>/Tune Variable' */
{
    ID_Translation_Model_135_143_67_18,
};

static enum TranslationNumber PreAmpBalance_CfgEnableSilentExtreme_Dependencies[]
    =                                  /* '<S571>/Tune Variable' */
{
    ID_Translation_Model_135_85_67_18,
};

static enum TranslationNumber PreAmpBalance_CfgTable_Dependencies[] =/* '<S572>/TuneVarBalanceTable' */
{
    ID_Translation_Model_135_90,
};

static enum TranslationNumber PreAmpNearWiggleCoeffs_Dependencies[] =/* '<S1049>/Tune Variable' */
{
    ID_Translation_Model_420_67_18,
};

static enum TranslationNumber PreAmpNearDelay_Dependencies[] =/* '<S1050>/Tune Variable' */
{
    ID_Translation_Model_421_67_18,
};

static enum TranslationNumber NearDr_PooliirsosCoefficients_Dependencies[] =/* '<S1313>/Tune Variable2' */
{
    ID_Translation_Model_874_36,
};

static enum TranslationNumber NearDr_PooliirnumStages_Dependencies[] =/* '<S1313>/Tune Variable1' */
{
    ID_Translation_Model_874_36,
};

static enum TranslationNumber NearDr_f1_del_Dependencies[] =/* '<S1317>/Tune Variable' */
{
    ID_Translation_Model_863,
};

static enum TranslationNumber NearDr_f2_del_Dependencies[] =/* '<S1317>/Tune Variable1' */
{
    ID_Translation_Model_863,
};

static enum TranslationNumber NearDr_f3_del_Dependencies[] =/* '<S1317>/Tune Variable2' */
{
    ID_Translation_Model_863,
};

static enum TranslationNumber NearDr_f4_del_Dependencies[] =/* '<S1317>/Tune Variable3' */
{
    ID_Translation_Model_863,
};

static enum TranslationNumber NearDr_f5_del_Dependencies[] =/* '<S1317>/Tune Variable4' */
{
    ID_Translation_Model_863,
};

static enum TranslationNumber NearDr_f6_del_Dependencies[] =/* '<S1317>/Tune Variable5' */
{
    ID_Translation_Model_863,
};

static enum TranslationNumber NearDr_f7_del_Dependencies[] =/* '<S1317>/Tune Variable7' */
{
    ID_Translation_Model_863,
};

static enum TranslationNumber NearDr_PoolIirTunablesosCoefficients_Dependencies[]
    =                                  /* '<S1323>/Tune Variable2' */
{
    ID_Translation_Model_915_36,
};

static enum TranslationNumber NearDr_PoolIirTunablenumStages_Dependencies[] =/* '<S1323>/Tune Variable1' */
{
    ID_Translation_Model_915_36,
};

static enum TranslationNumber NearDr_driver_src1_Dependencies[] =/* '<S1327>/Tune Variable1' */
{
    ID_Translation_Model_903,
};

static enum TranslationNumber NearDr_driver_src2_Dependencies[] =/* '<S1327>/Tune Variable2' */
{
    ID_Translation_Model_903,
};

static enum TranslationNumber NearDr_driver_src3_Dependencies[] =/* '<S1327>/Tune Variable3' */
{
    ID_Translation_Model_903,
};

static enum TranslationNumber NearDr_driver_src4_Dependencies[] =/* '<S1327>/Tune Variable4' */
{
    ID_Translation_Model_903,
};

static enum TranslationNumber NearDr_passenger_src1_Dependencies[] =/* '<S1327>/Tune Variable5' */
{
    ID_Translation_Model_903,
};

static enum TranslationNumber NearDr_passenger_src2_Dependencies[] =/* '<S1327>/Tune Variable7' */
{
    ID_Translation_Model_903,
};

static enum TranslationNumber NearDr_passenger_src3_Dependencies[] =/* '<S1327>/Tune Variable6' */
{
    ID_Translation_Model_903,
};

static enum TranslationNumber NearDr_passenger_src4_Dependencies[] =/* '<S1327>/Tune Variable8' */
{
    ID_Translation_Model_903,
};

static enum TranslationNumber NearDr_RouterMap_Dependencies[] =/* '<S1331>/TuneVarRouterMap' */
{
    ID_Translation_Model_926,
};

static enum TranslationNumber NearDr_f1_mix_Dependencies[] =/* '<S1336>/Tune Variable' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_f2_mix_Dependencies[] =/* '<S1336>/Tune Variable1' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_f3_mix_Dependencies[] =/* '<S1336>/Tune Variable2' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_f4_mix_Dependencies[] =/* '<S1336>/Tune Variable3' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_f5_mix_Dependencies[] =/* '<S1336>/Tune Variable4' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_f6_mix_Dependencies[] =/* '<S1336>/Tune Variable5' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_f7_mix_Dependencies[] =/* '<S1336>/Tune Variable7' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_LFI0_mix_Dependencies[] =/* '<S1337>/Tune Variable' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_LFT0_mix_Dependencies[] =/* '<S1337>/Tune Variable1' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_RFI0_mix_Dependencies[] =/* '<S1337>/Tune Variable2' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_RFT0_mix_Dependencies[] =/* '<S1337>/Tune Variable3' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_LSI0_mix_Dependencies[] =/* '<S1337>/Tune Variable4' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_LST0_mix_Dependencies[] =/* '<S1337>/Tune Variable5' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_RSI0_mix_Dependencies[] =/* '<S1337>/Tune Variable7' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_RST0_mix_Dependencies[] =/* '<S1337>/Tune Variable6' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_LCI0_mix_Dependencies[] =/* '<S1337>/Tune Variable8' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_LCT0_mix_Dependencies[] =/* '<S1337>/Tune Variable9' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_RCI0_mix_Dependencies[] =/* '<S1337>/Tune Variable10' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_RCT0_mix_Dependencies[] =/* '<S1337>/Tune Variable11' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_LFI1_mix_Dependencies[] =/* '<S1338>/Tune Variable' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_LFT1_mix_Dependencies[] =/* '<S1338>/Tune Variable1' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_RFI1_mix_Dependencies[] =/* '<S1338>/Tune Variable2' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_RFT1_mix_Dependencies[] =/* '<S1338>/Tune Variable3' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_LSI1_mix_Dependencies[] =/* '<S1338>/Tune Variable4' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_LST1_mix_Dependencies[] =/* '<S1338>/Tune Variable5' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_RSI1_mix_Dependencies[] =/* '<S1338>/Tune Variable7' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_RST1_mix_Dependencies[] =/* '<S1338>/Tune Variable6' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_LCI1_mix_Dependencies[] =/* '<S1338>/Tune Variable8' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_LCT1_mix_Dependencies[] =/* '<S1338>/Tune Variable9' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_RCI1_mix_Dependencies[] =/* '<S1338>/Tune Variable10' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_RCT1_mix_Dependencies[] =/* '<S1338>/Tune Variable11' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_nv0l_mix_Dependencies[] =/* '<S1339>/Tune Variable' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_nv0r_mix_Dependencies[] =/* '<S1339>/Tune Variable1' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_nv1l_mix_Dependencies[] =/* '<S1339>/Tune Variable2' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearDr_nv1r_mix_Dependencies[] =/* '<S1339>/Tune Variable3' */
{
    ID_Translation_Model_1026,
};

static enum TranslationNumber NearFr_PooliirsosCoefficients_Dependencies[] =/* '<S1350>/Tune Variable2' */
{
    ID_Translation_Model_1063_36,
};

static enum TranslationNumber NearFr_PooliirnumStages_Dependencies[] =/* '<S1350>/Tune Variable1' */
{
    ID_Translation_Model_1063_36,
};

static enum TranslationNumber NearFr_f1_del_Dependencies[] =/* '<S1354>/Tune Variable' */
{
    ID_Translation_Model_1052,
};

static enum TranslationNumber NearFr_f2_del_Dependencies[] =/* '<S1354>/Tune Variable1' */
{
    ID_Translation_Model_1052,
};

static enum TranslationNumber NearFr_f3_del_Dependencies[] =/* '<S1354>/Tune Variable2' */
{
    ID_Translation_Model_1052,
};

static enum TranslationNumber NearFr_f4_del_Dependencies[] =/* '<S1354>/Tune Variable3' */
{
    ID_Translation_Model_1052,
};

static enum TranslationNumber NearFr_f5_del_Dependencies[] =/* '<S1354>/Tune Variable4' */
{
    ID_Translation_Model_1052,
};

static enum TranslationNumber NearFr_f6_del_Dependencies[] =/* '<S1354>/Tune Variable5' */
{
    ID_Translation_Model_1052,
};

static enum TranslationNumber NearFr_f7_del_Dependencies[] =/* '<S1354>/Tune Variable7' */
{
    ID_Translation_Model_1052,
};

static enum TranslationNumber NearFr_PoolIirTunablesosCoefficients_Dependencies[]
    =                                  /* '<S1360>/Tune Variable2' */
{
    ID_Translation_Model_1104_36,
};

static enum TranslationNumber NearFr_PoolIirTunablenumStages_Dependencies[] =/* '<S1360>/Tune Variable1' */
{
    ID_Translation_Model_1104_36,
};

static enum TranslationNumber NearFr_driver_src1_Dependencies[] =/* '<S1364>/Tune Variable1' */
{
    ID_Translation_Model_1092,
};

static enum TranslationNumber NearFr_driver_src2_Dependencies[] =/* '<S1364>/Tune Variable2' */
{
    ID_Translation_Model_1092,
};

static enum TranslationNumber NearFr_driver_src3_Dependencies[] =/* '<S1364>/Tune Variable3' */
{
    ID_Translation_Model_1092,
};

static enum TranslationNumber NearFr_driver_src4_Dependencies[] =/* '<S1364>/Tune Variable4' */
{
    ID_Translation_Model_1092,
};

static enum TranslationNumber NearFr_passenger_src1_Dependencies[] =/* '<S1364>/Tune Variable5' */
{
    ID_Translation_Model_1092,
};

static enum TranslationNumber NearFr_passenger_src2_Dependencies[] =/* '<S1364>/Tune Variable7' */
{
    ID_Translation_Model_1092,
};

static enum TranslationNumber NearFr_passenger_src3_Dependencies[] =/* '<S1364>/Tune Variable6' */
{
    ID_Translation_Model_1092,
};

static enum TranslationNumber NearFr_passenger_src4_Dependencies[] =/* '<S1364>/Tune Variable8' */
{
    ID_Translation_Model_1092,
};

static enum TranslationNumber NearFr_RouterMap_Dependencies[] =/* '<S1368>/TuneVarRouterMap' */
{
    ID_Translation_Model_1115,
};

static enum TranslationNumber NearFr_f1_mix_Dependencies[] =/* '<S1373>/Tune Variable' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_f2_mix_Dependencies[] =/* '<S1373>/Tune Variable1' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_f3_mix_Dependencies[] =/* '<S1373>/Tune Variable2' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_f4_mix_Dependencies[] =/* '<S1373>/Tune Variable3' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_f5_mix_Dependencies[] =/* '<S1373>/Tune Variable4' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_f6_mix_Dependencies[] =/* '<S1373>/Tune Variable5' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_f7_mix_Dependencies[] =/* '<S1373>/Tune Variable7' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_LFI0_mix_Dependencies[] =/* '<S1374>/Tune Variable' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_LFT0_mix_Dependencies[] =/* '<S1374>/Tune Variable1' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_RFI0_mix_Dependencies[] =/* '<S1374>/Tune Variable2' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_RFT0_mix_Dependencies[] =/* '<S1374>/Tune Variable3' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_LSI0_mix_Dependencies[] =/* '<S1374>/Tune Variable4' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_LST0_mix_Dependencies[] =/* '<S1374>/Tune Variable5' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_RSI0_mix_Dependencies[] =/* '<S1374>/Tune Variable7' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_RST0_mix_Dependencies[] =/* '<S1374>/Tune Variable6' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_LCI0_mix_Dependencies[] =/* '<S1374>/Tune Variable8' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_LCT0_mix_Dependencies[] =/* '<S1374>/Tune Variable9' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_RCI0_mix_Dependencies[] =/* '<S1374>/Tune Variable10' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_RCT0_mix_Dependencies[] =/* '<S1374>/Tune Variable11' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_LFI1_mix_Dependencies[] =/* '<S1375>/Tune Variable' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_LFT1_mix_Dependencies[] =/* '<S1375>/Tune Variable1' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_RFI1_mix_Dependencies[] =/* '<S1375>/Tune Variable2' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_RFT1_mix_Dependencies[] =/* '<S1375>/Tune Variable3' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_LSI1_mix_Dependencies[] =/* '<S1375>/Tune Variable4' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_LST1_mix_Dependencies[] =/* '<S1375>/Tune Variable5' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_RSI1_mix_Dependencies[] =/* '<S1375>/Tune Variable7' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_RST1_mix_Dependencies[] =/* '<S1375>/Tune Variable6' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_LCI1_mix_Dependencies[] =/* '<S1375>/Tune Variable8' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_LCT1_mix_Dependencies[] =/* '<S1375>/Tune Variable9' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_RCI1_mix_Dependencies[] =/* '<S1375>/Tune Variable10' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_RCT1_mix_Dependencies[] =/* '<S1375>/Tune Variable11' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_nv0l_mix_Dependencies[] =/* '<S1376>/Tune Variable' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_nv0r_mix_Dependencies[] =/* '<S1376>/Tune Variable1' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_nv1l_mix_Dependencies[] =/* '<S1376>/Tune Variable2' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearFr_nv1r_mix_Dependencies[] =/* '<S1376>/Tune Variable3' */
{
    ID_Translation_Model_1215,
};

static enum TranslationNumber NearRampDbPerSample_Dependencies[] =/* '<S1380>/Tune Variable' */
{
    ID_Translation_Model_831_67_18,
};

static enum TranslationNumber NearHpfCutoffFrequency_Dependencies[] =/* '<S1385>/HpfCutOffTuneVar' */
{
    ID_Translation_Model_1234,
};

static enum TranslationNumber NearHpfFilterOrder_Dependencies[] =/* '<S1385>/HpfOrderTuneVar' */
{
    ID_Translation_Model_1234,
};

static enum TranslationNumber
    NearLevelDetectPreEmphasisShelfFiltersosCoefficients_Dependencies[] =/* '<S1401>/Tune Variable2' */
{
    ID_Translation_Model_1475_36,
};

static enum TranslationNumber
    NearLevelDetectPreEmphasisShelfFilternumStages_Dependencies[] =/* '<S1401>/Tune Variable1' */
{
    ID_Translation_Model_1475_36,
};

static enum TranslationNumber NearLevelDetectSysMaxDbspl_Dependencies[] =/* '<S1400>/Tune Variable' */
{
    ID_Translation_Model_1310_67_18,
};

static enum TranslationNumber NearAnn1LevelDetectFastDecayDbPers_Dependencies[] =/* '<S1409>/Tune Variable' */
{
    ID_Translation_Model_1331,
};

static enum TranslationNumber NearAnn1LevelDetectHoldMarginDb_Dependencies[] =/* '<S1410>/Tune Variable' */
{
    ID_Translation_Model_1338,
};

static enum TranslationNumber NearAnn1LevelDetectHoldTimes_Dependencies[] =/* '<S1411>/Tune Variable' */
{
    ID_Translation_Model_1343,
};

static enum TranslationNumber NearAnn1LevelDetectMaxVolumeDb_Dependencies[] =/* '<S1412>/Tune Variable' */
{
    ID_Translation_Model_1347_67_18,
};

static enum TranslationNumber NearAnn1LevelDetectMinVolumeDb_Dependencies[] =/* '<S1413>/Tune Variable' */
{
    ID_Translation_Model_1348_67_18,
};

static enum TranslationNumber NearAnn1LevelDetectSlowDecayDbPers_Dependencies[] =/* '<S1414>/Tune Variable' */
{
    ID_Translation_Model_1351,
};

static enum TranslationNumber NearAnn2LevelDetectFastDecayDbPers_Dependencies[] =/* '<S1435>/Tune Variable' */
{
    ID_Translation_Model_1368,
};

static enum TranslationNumber NearAnn2LevelDetectHoldMarginDb_Dependencies[] =/* '<S1436>/Tune Variable' */
{
    ID_Translation_Model_1375,
};

static enum TranslationNumber NearAnn2LevelDetectHoldTimes_Dependencies[] =/* '<S1437>/Tune Variable' */
{
    ID_Translation_Model_1380,
};

static enum TranslationNumber NearAnn2LevelDetectMaxVolumeDb_Dependencies[] =/* '<S1438>/Tune Variable' */
{
    ID_Translation_Model_1384_67_18,
};

static enum TranslationNumber NearAnn2LevelDetectMinVolumeDb_Dependencies[] =/* '<S1439>/Tune Variable' */
{
    ID_Translation_Model_1385_67_18,
};

static enum TranslationNumber NearAnn2LevelDetectSlowDecayDbPers_Dependencies[] =/* '<S1440>/Tune Variable' */
{
    ID_Translation_Model_1388,
};

static enum TranslationNumber NearAnn3LevelDetectFastDecayDbPers_Dependencies[] =/* '<S1461>/Tune Variable' */
{
    ID_Translation_Model_1405,
};

static enum TranslationNumber NearAnn3LevelDetectHoldMarginDb_Dependencies[] =/* '<S1462>/Tune Variable' */
{
    ID_Translation_Model_1412,
};

static enum TranslationNumber NearAnn3LevelDetectHoldTimes_Dependencies[] =/* '<S1463>/Tune Variable' */
{
    ID_Translation_Model_1417,
};

static enum TranslationNumber NearAnn3LevelDetectMaxVolumeDb_Dependencies[] =/* '<S1464>/Tune Variable' */
{
    ID_Translation_Model_1421_67_18,
};

static enum TranslationNumber NearAnn3LevelDetectMinVolumeDb_Dependencies[] =/* '<S1465>/Tune Variable' */
{
    ID_Translation_Model_1422_67_18,
};

static enum TranslationNumber NearAnn3LevelDetectSlowDecayDbPers_Dependencies[] =/* '<S1466>/Tune Variable' */
{
    ID_Translation_Model_1425,
};

static enum TranslationNumber NearAnn4LevelDetectFastDecayDbPers_Dependencies[] =/* '<S1487>/Tune Variable' */
{
    ID_Translation_Model_1442,
};

static enum TranslationNumber NearAnn4LevelDetectHoldMarginDb_Dependencies[] =/* '<S1488>/Tune Variable' */
{
    ID_Translation_Model_1449,
};

static enum TranslationNumber NearAnn4LevelDetectHoldTimes_Dependencies[] =/* '<S1489>/Tune Variable' */
{
    ID_Translation_Model_1454,
};

static enum TranslationNumber NearAnn4LevelDetectMaxVolumeDb_Dependencies[] =/* '<S1490>/Tune Variable' */
{
    ID_Translation_Model_1458_67_18,
};

static enum TranslationNumber NearAnn4LevelDetectMinVolumeDb_Dependencies[] =/* '<S1491>/Tune Variable' */
{
    ID_Translation_Model_1459_67_18,
};

static enum TranslationNumber NearAnn4LevelDetectSlowDecayDbPers_Dependencies[] =/* '<S1492>/Tune Variable' */
{
    ID_Translation_Model_1462,
};

static enum TranslationNumber NearAnn1Ann1NonEntGainCalcVncThresh_Dependencies[]
    =                                  /* '<S1517>/Tune Variable' */
{
    ID_Translation_Model_1254_7_67_18,
};

static enum TranslationNumber NearAnn1Ann1NonEntGainCalcVncSlope_Dependencies[] =/* '<S1518>/Tune Variable' */
{
    ID_Translation_Model_1254_8_67_18,
};

static enum TranslationNumber NearAnn1Ann1NonEntGainCalcMaxBoost_Dependencies[] =/* '<S1519>/Tune Variable' */
{
    ID_Translation_Model_1254_9_67_18,
};

static enum TranslationNumber
    NearAnn1Ann1NonEntGainCalcNoiseOverRide_Dependencies[] =/* '<S1520>/Tune Variable' */
{
    ID_Translation_Model_1254_72_67_18,
};

static enum TranslationNumber
    NearAnn1Ann1NonEntGainCalcNoiseOverRideFlag_Dependencies[] =/* '<S1521>/Tune Variable' */
{
    ID_Translation_Model_1254_74_67_18,
};

static enum TranslationNumber
    NearAnn1Ann1NonEntGainCalcBoostOverRide_Dependencies[] =/* '<S1522>/Tune Variable' */
{
    ID_Translation_Model_1254_75_67_18,
};

static enum TranslationNumber
    NearAnn1Ann1NonEntGainCalcBoostOverRideFlag_Dependencies[] =/* '<S1523>/Tune Variable' */
{
    ID_Translation_Model_1254_76_67_18,
};

static enum TranslationNumber
    NearAnn1Ann1NonEntGainCalcVncEnableTuneVar_Dependencies[] =/* '<S1524>/Tune Variable' */
{
    ID_Translation_Model_1254_99_67_18,
};

static enum TranslationNumber NearAnn1Ann1NonEntGainCalcTau_Dependencies[] =/* '<S1525>/tuneVARTau' */
{
    ID_Translation_Model_1254_85,
};

static enum TranslationNumber
    NearAnn1Ann1NonEntGainCalcMinVncSignal_Dependencies[] =/* '<S1562>/Tune Variable' */
{
    ID_Translation_Model_1254_53_67_18,
};

static enum TranslationNumber NearAnn1Ann1NonEntGainCalcMaxSpl_Dependencies[] =/* '<S1563>/Tune Variable' */
{
    ID_Translation_Model_1254_54_67_18,
};

static enum TranslationNumber NearAnn1Ann1NonEntVncAppliedTau_Dependencies[] =/* '<S1573>/tuneVARTau' */
{
    ID_Translation_Model_1255_44,
};

static enum TranslationNumber NearAnn1Ann1MuteRampTime_Dependencies[] =/* '<S1578>/Tune Variable' */
{
    ID_Translation_Model_1257_276_67_18,
};

static enum TranslationNumber NearAnn1Ann1VolumeTable_Dependencies[] =/* '<S1516>/TuneVarVolumeTable' */
{
    ID_Translation_Model_1259_139,
};

static enum TranslationNumber NearAnn1Ann1VolumeRampRate_Dependencies[] =/* '<S1584>/Tune Variable' */
{
    ID_Translation_Model_1259_192_67_18,
};

static enum TranslationNumber NearAnn1Ann1VolumeRampTime_Dependencies[] =/* '<S1585>/Tune Variable' */
{
    ID_Translation_Model_1259_190_67_18,
};

static enum TranslationNumber NearAnn2Ann2NonEntGainCalcVncThresh_Dependencies[]
    =                                  /* '<S1600>/Tune Variable' */
{
    ID_Translation_Model_1265_7_67_18,
};

static enum TranslationNumber NearAnn2Ann2NonEntGainCalcVncSlope_Dependencies[] =/* '<S1601>/Tune Variable' */
{
    ID_Translation_Model_1265_8_67_18,
};

static enum TranslationNumber NearAnn2Ann2NonEntGainCalcMaxBoost_Dependencies[] =/* '<S1602>/Tune Variable' */
{
    ID_Translation_Model_1265_9_67_18,
};

static enum TranslationNumber
    NearAnn2Ann2NonEntGainCalcNoiseOverRide_Dependencies[] =/* '<S1603>/Tune Variable' */
{
    ID_Translation_Model_1265_72_67_18,
};

static enum TranslationNumber
    NearAnn2Ann2NonEntGainCalcNoiseOverRideFlag_Dependencies[] =/* '<S1604>/Tune Variable' */
{
    ID_Translation_Model_1265_74_67_18,
};

static enum TranslationNumber
    NearAnn2Ann2NonEntGainCalcBoostOverRide_Dependencies[] =/* '<S1605>/Tune Variable' */
{
    ID_Translation_Model_1265_75_67_18,
};

static enum TranslationNumber
    NearAnn2Ann2NonEntGainCalcBoostOverRideFlag_Dependencies[] =/* '<S1606>/Tune Variable' */
{
    ID_Translation_Model_1265_76_67_18,
};

static enum TranslationNumber
    NearAnn2Ann2NonEntGainCalcVncEnableTuneVar_Dependencies[] =/* '<S1607>/Tune Variable' */
{
    ID_Translation_Model_1265_99_67_18,
};

static enum TranslationNumber NearAnn2Ann2NonEntGainCalcTau_Dependencies[] =/* '<S1608>/tuneVARTau' */
{
    ID_Translation_Model_1265_85,
};

static enum TranslationNumber
    NearAnn2Ann2NonEntGainCalcMinVncSignal_Dependencies[] =/* '<S1645>/Tune Variable' */
{
    ID_Translation_Model_1265_53_67_18,
};

static enum TranslationNumber NearAnn2Ann2NonEntGainCalcMaxSpl_Dependencies[] =/* '<S1646>/Tune Variable' */
{
    ID_Translation_Model_1265_54_67_18,
};

static enum TranslationNumber NearAnn2Ann2NonEntVncAppliedTau_Dependencies[] =/* '<S1656>/tuneVARTau' */
{
    ID_Translation_Model_1266_44,
};

static enum TranslationNumber NearAnn2Ann2MuteRampTime_Dependencies[] =/* '<S1661>/Tune Variable' */
{
    ID_Translation_Model_1268_276_67_18,
};

static enum TranslationNumber NearAnn2Ann2VolumeTable_Dependencies[] =/* '<S1599>/TuneVarVolumeTable' */
{
    ID_Translation_Model_1270_139,
};

static enum TranslationNumber NearAnn2Ann2VolumeRampRate_Dependencies[] =/* '<S1667>/Tune Variable' */
{
    ID_Translation_Model_1270_192_67_18,
};

static enum TranslationNumber NearAnn2Ann2VolumeRampTime_Dependencies[] =/* '<S1668>/Tune Variable' */
{
    ID_Translation_Model_1270_190_67_18,
};

static enum TranslationNumber NearAnn3Ann3NonEntGainCalcVncThresh_Dependencies[]
    =                                  /* '<S1683>/Tune Variable' */
{
    ID_Translation_Model_1276_7_67_18,
};

static enum TranslationNumber NearAnn3Ann3NonEntGainCalcVncSlope_Dependencies[] =/* '<S1684>/Tune Variable' */
{
    ID_Translation_Model_1276_8_67_18,
};

static enum TranslationNumber NearAnn3Ann3NonEntGainCalcMaxBoost_Dependencies[] =/* '<S1685>/Tune Variable' */
{
    ID_Translation_Model_1276_9_67_18,
};

static enum TranslationNumber
    NearAnn3Ann3NonEntGainCalcNoiseOverRide_Dependencies[] =/* '<S1686>/Tune Variable' */
{
    ID_Translation_Model_1276_72_67_18,
};

static enum TranslationNumber
    NearAnn3Ann3NonEntGainCalcNoiseOverRideFlag_Dependencies[] =/* '<S1687>/Tune Variable' */
{
    ID_Translation_Model_1276_74_67_18,
};

static enum TranslationNumber
    NearAnn3Ann3NonEntGainCalcBoostOverRide_Dependencies[] =/* '<S1688>/Tune Variable' */
{
    ID_Translation_Model_1276_75_67_18,
};

static enum TranslationNumber
    NearAnn3Ann3NonEntGainCalcBoostOverRideFlag_Dependencies[] =/* '<S1689>/Tune Variable' */
{
    ID_Translation_Model_1276_76_67_18,
};

static enum TranslationNumber
    NearAnn3Ann3NonEntGainCalcVncEnableTuneVar_Dependencies[] =/* '<S1690>/Tune Variable' */
{
    ID_Translation_Model_1276_99_67_18,
};

static enum TranslationNumber NearAnn3Ann3NonEntGainCalcTau_Dependencies[] =/* '<S1691>/tuneVARTau' */
{
    ID_Translation_Model_1276_85,
};

static enum TranslationNumber
    NearAnn3Ann3NonEntGainCalcMinVncSignal_Dependencies[] =/* '<S1728>/Tune Variable' */
{
    ID_Translation_Model_1276_53_67_18,
};

static enum TranslationNumber NearAnn3Ann3NonEntGainCalcMaxSpl_Dependencies[] =/* '<S1729>/Tune Variable' */
{
    ID_Translation_Model_1276_54_67_18,
};

static enum TranslationNumber NearAnn3Ann3NonEntVncAppliedTau_Dependencies[] =/* '<S1739>/tuneVARTau' */
{
    ID_Translation_Model_1277_44,
};

static enum TranslationNumber NearAnn3Ann3MuteRampTime_Dependencies[] =/* '<S1744>/Tune Variable' */
{
    ID_Translation_Model_1279_276_67_18,
};

static enum TranslationNumber NearAnn3Ann3VolumeTable_Dependencies[] =/* '<S1682>/TuneVarVolumeTable' */
{
    ID_Translation_Model_1281_139,
};

static enum TranslationNumber NearAnn3Ann3VolumeRampRate_Dependencies[] =/* '<S1750>/Tune Variable' */
{
    ID_Translation_Model_1281_192_67_18,
};

static enum TranslationNumber NearAnn3Ann3VolumeRampTime_Dependencies[] =/* '<S1751>/Tune Variable' */
{
    ID_Translation_Model_1281_190_67_18,
};

static enum TranslationNumber NearAnn4Ann4NonEntGainCalcVncThresh_Dependencies[]
    =                                  /* '<S1766>/Tune Variable' */
{
    ID_Translation_Model_1287_7_67_18,
};

static enum TranslationNumber NearAnn4Ann4NonEntGainCalcVncSlope_Dependencies[] =/* '<S1767>/Tune Variable' */
{
    ID_Translation_Model_1287_8_67_18,
};

static enum TranslationNumber NearAnn4Ann4NonEntGainCalcMaxBoost_Dependencies[] =/* '<S1768>/Tune Variable' */
{
    ID_Translation_Model_1287_9_67_18,
};

static enum TranslationNumber
    NearAnn4Ann4NonEntGainCalcNoiseOverRide_Dependencies[] =/* '<S1769>/Tune Variable' */
{
    ID_Translation_Model_1287_72_67_18,
};

static enum TranslationNumber
    NearAnn4Ann4NonEntGainCalcNoiseOverRideFlag_Dependencies[] =/* '<S1770>/Tune Variable' */
{
    ID_Translation_Model_1287_74_67_18,
};

static enum TranslationNumber
    NearAnn4Ann4NonEntGainCalcBoostOverRide_Dependencies[] =/* '<S1771>/Tune Variable' */
{
    ID_Translation_Model_1287_75_67_18,
};

static enum TranslationNumber
    NearAnn4Ann4NonEntGainCalcBoostOverRideFlag_Dependencies[] =/* '<S1772>/Tune Variable' */
{
    ID_Translation_Model_1287_76_67_18,
};

static enum TranslationNumber
    NearAnn4Ann4NonEntGainCalcVncEnableTuneVar_Dependencies[] =/* '<S1773>/Tune Variable' */
{
    ID_Translation_Model_1287_99_67_18,
};

static enum TranslationNumber NearAnn4Ann4NonEntGainCalcTau_Dependencies[] =/* '<S1774>/tuneVARTau' */
{
    ID_Translation_Model_1287_85,
};

static enum TranslationNumber
    NearAnn4Ann4NonEntGainCalcMinVncSignal_Dependencies[] =/* '<S1811>/Tune Variable' */
{
    ID_Translation_Model_1287_53_67_18,
};

static enum TranslationNumber NearAnn4Ann4NonEntGainCalcMaxSpl_Dependencies[] =/* '<S1812>/Tune Variable' */
{
    ID_Translation_Model_1287_54_67_18,
};

static enum TranslationNumber NearAnn4Ann4NonEntVncAppliedTau_Dependencies[] =/* '<S1822>/tuneVARTau' */
{
    ID_Translation_Model_1288_44,
};

static enum TranslationNumber NearAnn4Ann4MuteRampTime_Dependencies[] =/* '<S1827>/Tune Variable' */
{
    ID_Translation_Model_1290_276_67_18,
};

static enum TranslationNumber NearAnn4Ann4VolumeTable_Dependencies[] =/* '<S1765>/TuneVarVolumeTable' */
{
    ID_Translation_Model_1292_139,
};

static enum TranslationNumber NearAnn4Ann4VolumeRampRate_Dependencies[] =/* '<S1833>/Tune Variable' */
{
    ID_Translation_Model_1292_192_67_18,
};

static enum TranslationNumber NearAnn4Ann4VolumeRampTime_Dependencies[] =/* '<S1834>/Tune Variable' */
{
    ID_Translation_Model_1292_190_67_18,
};

static enum TranslationNumber TestRouterASDRouterEnableAux_Dependencies[] =/* '<S1892>/Tune Variable' */
{
    ID_Translation_Model_291_138_8_67_18,
};

static enum TranslationNumber TestRouterASDRouterMainSelect_Dependencies[] =/* '<S1897>/Tune Variable' */
{
    ID_Translation_Model_291_138_44_67_18,
};

static enum TranslationNumber TestRouterAuxSelect_Dependencies[] =/* '<S1888>/Tune Variable' */
{
    ID_Translation_Model_296_67_18,
};

// ----- Tune variable dispatch table:
static TuneVar_type tune_var_table[] =
{
    {                                  /* '<S630>/Tune Variable4' */
        "PreAmpMedusaDeciRateWiggleFilterDelaySamples", 0, TSS_INT32, 0, sizeof
        (int32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaDeciRateWiggleFilterDelaySamples, 1,
        Model_TranslationEngine64_AlignmentDelay_B.DeciRateWiggleFilterDelaySamples.Size,
        &Model_TranslationEngine64_AlignmentDelay_B.DeciRateWiggleFilterDelaySamples.Value,
        1, PreAmpMedusaDeciRateWiggleFilterDelaySamples_Dependencies
    },

    {                                  /* '<S630>/Tune Variable1' */
        "PreAmpMedusaDeciRateNearWiggleFilterDelaySamples", 0, TSS_INT32, 0,
        sizeof(int32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaDeciRateNearWiggleFilterDelaySamples, 1,
        Model_TranslationEngine64_AlignmentDelay_B.DeciRateNearWiggleFilterDelaySamples.Size,
        &Model_TranslationEngine64_AlignmentDelay_B.DeciRateNearWiggleFilterDelaySamples.Value,
        1, PreAmpMedusaDeciRateNearWiggleFilterDelaySamples_Dependencies
    },

    {                                  /* '<S630>/Tune Variable5' */
        "PreAmpMedusaHoligramFilterAlignmentDelaySamples", 0, TSS_INT32, 0,
        sizeof(int32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaHoligramFilterAlignmentDelaySamples, 1,
        Model_TranslationEngine64_AlignmentDelay_B.HoligramFilterAlignmentDelaySamples.Size,
        &Model_TranslationEngine64_AlignmentDelay_B.HoligramFilterAlignmentDelaySamples.Value,
        1, PreAmpMedusaHoligramFilterAlignmentDelaySamples_Dependencies
    },

    {                                  /* '<S765>/Tune Variable2' */
        "PreAmpMedusatailCompEQsosCoefficients", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 240,
        {
            40,
            6,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusatailCompEQsosCoefficients, 24,
        Model_TranslationEngine64_ExpandTailComponents_B.sosCoefficients.Size,
        Model_TranslationEngine64_ExpandTailComponents_B.sosCoefficients.Value,
        1, PreAmpMedusatailCompEQsosCoefficients_Dependencies
    },

    {                                  /* '<S765>/Tune Variable1' */
        "PreAmpMedusatailCompEQnumStages", 0, TSS_SINGLE, 0, sizeof(real32_T), 4,
        {
            1,
            4,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusatailCompEQnumStages, 4,
        Model_TranslationEngine64_ExpandTailComponents_B.numStages.Size,
        Model_TranslationEngine64_ExpandTailComponents_B.numStages.Value, 1,
        PreAmpMedusatailCompEQnumStages_Dependencies
    },

    {                                  /* '<S763>/Tune Variable' */
        "PreAmpMedusaWiggleFilter", 0, TSS_DOUBLE, 0, sizeof(real_T), 1776,
        {
            444,
            4,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaWiggleFilter, 1776,
        Model_TranslationEngine64_ExpandTailComponents_B.WiggleFilter.Size,
        Model_TranslationEngine64_ExpandTailComponents_B.WiggleFilter.Value, 1,
        PreAmpMedusaWiggleFilter_Dependencies
    },

    {                                  /* '<S753>/Tune Variable' */
        "PreAmpMedusaDeciRateWiggleFilterDelaySamples1", 0, TSS_INT32, 0, sizeof
        (int32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaDeciRateWiggleFilterDelaySamples1, 1,
        Model_TranslationEngine64_Medusa5H1Part3_B.DeciRateWiggleFilterDelaySamples1.Size,
        &Model_TranslationEngine64_Medusa5H1Part3_B.DeciRateWiggleFilterDelaySamples1.Value,
        1, PreAmpMedusaDeciRateWiggleFilterDelaySamples1_Dependencies
    },

    {                                  /* '<S753>/Tune Variable1' */
        "PreAmpMedusaDeciRateNearWiggleFilterDelaySamples1", 0, TSS_INT32, 0,
        sizeof(int32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaDeciRateNearWiggleFilterDelaySamples1, 1,
        Model_TranslationEngine64_Medusa5H1Part3_B.DeciRateNearWiggleFilterDelaySamples1.Size,
        &Model_TranslationEngine64_Medusa5H1Part3_B.DeciRateNearWiggleFilterDelaySamples1.Value,
        1, PreAmpMedusaDeciRateNearWiggleFilterDelaySamples1_Dependencies
    },

    {                                  /* '<S776>/Tune Variable' */
        "PreAmpMedusaFullRateMixerBackwardDownmixMax", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateMixerBackwardDownmixMax, 1,
        Model_TranslationEngine64_Medusa5H1Part3_B.BackwardDownmixMax.Size,
        &Model_TranslationEngine64_Medusa5H1Part3_B.BackwardDownmixMax.Value, 1,
        PreAmpMedusaFullRateMixerBackwardDownmixMax_Dependencies
    },

    {                                  /* '<S777>/Tune Variable' */
        "PreAmpMedusaFullRateMixerBackwardDownmixThreshold", 0, TSS_DOUBLE, 0,
        sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateMixerBackwardDownmixThreshold, 1,
        Model_TranslationEngine64_Medusa5H1Part3_B.BackwardDownmixThreshold.Size,
        &Model_TranslationEngine64_Medusa5H1Part3_B.BackwardDownmixThreshold.Value,
        1, PreAmpMedusaFullRateMixerBackwardDownmixThreshold_Dependencies
    },

    {                                  /* '<S778>/Tune Variable' */
        "PreAmpMedusaFullRateMixerDownmixWeights_CS", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 12,
        {
            2,
            6,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateMixerDownmixWeights_CS, 12,
        Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_CS_c.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_CS_c.Value, 1,
        PreAmpMedusaFullRateMixerDownmixWeights_CS_Dependencies
    },

    {                                  /* '<S779>/Tune Variable' */
        "PreAmpMedusaFullRateMixerDownmixWeights_Left", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 30,
        {
            10,
            3,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateMixerDownmixWeights_Left, 30,
        Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_Left_n.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_Left_n.Value,
        1, PreAmpMedusaFullRateMixerDownmixWeights_Left_Dependencies
    },

    {                                  /* '<S780>/Tune Variable' */
        "PreAmpMedusaFullRateMixerDownmixWeights_Right", 0, TSS_DOUBLE, 0,
        sizeof(real_T), 30,
        {
            10,
            3,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateMixerDownmixWeights_Right, 30,
        Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_Right_d.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_Right_d.Value,
        1, PreAmpMedusaFullRateMixerDownmixWeights_Right_Dependencies
    },

    {                                  /* '<S781>/Tune Variable' */
        "PreAmpMedusaFullRateMixerForwardDownmixThreshold", 0, TSS_DOUBLE, 0,
        sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateMixerForwardDownmixThreshold, 1,
        Model_TranslationEngine64_Medusa5H1Part3_B.ForwardDownmixThreshold.Size,
        &Model_TranslationEngine64_Medusa5H1Part3_B.ForwardDownmixThreshold.Value,
        1, PreAmpMedusaFullRateMixerForwardDownmixThreshold_Dependencies
    },

    {                                  /* '<S782>/Tune Variable' */
        "PreAmpMedusaFullRateMixerForwardDownmixMax", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateMixerForwardDownmixMax, 1,
        Model_TranslationEngine64_Medusa5H1Part3_B.ForwardDownmixMax.Size,
        &Model_TranslationEngine64_Medusa5H1Part3_B.ForwardDownmixMax.Value, 1,
        PreAmpMedusaFullRateMixerForwardDownmixMax_Dependencies
    },

    {                                  /* '<S804>/Tune Variable' */
        "PreAmpMedusaFullRateMixerDetentLevel_CS", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 12,
        {
            2,
            6,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateMixerDetentLevel_CS, 12,
        Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_CS_j.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_CS_j.Value, 1,
        PreAmpMedusaFullRateMixerDetentLevel_CS_Dependencies
    },

    {                                  /* '<S805>/Tune Variable' */
        "PreAmpMedusaFullRateMixerDetentLevel_Left", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 30,
        {
            10,
            3,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateMixerDetentLevel_Left, 30,
        Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_Left_n.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_Left_n.Value, 1,
        PreAmpMedusaFullRateMixerDetentLevel_Left_Dependencies
    },

    {                                  /* '<S806>/Tune Variable' */
        "PreAmpMedusaFullRateMixerDetentLevel_Right", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 30,
        {
            10,
            3,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateMixerDetentLevel_Right, 30,
        Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_Right_c.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_Right_c.Value, 1,
        PreAmpMedusaFullRateMixerDetentLevel_Right_Dependencies
    },

    {                                  /* '<S807>/Tune Variable' */
        "PreAmpMedusaFullRateMixerInterpolation_Method", 0, TSS_DOUBLE, 0,
        sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateMixerInterpolation_Method, 1,
        Model_TranslationEngine64_Medusa5H1Part3_B.Interpolation_Method.Size,
        &Model_TranslationEngine64_Medusa5H1Part3_B.Interpolation_Method.Value,
        1, PreAmpMedusaFullRateMixerInterpolation_Method_Dependencies
    },

    {                                  /* '<S808>/Tune Variable' */
        "PreAmpMedusaFullRateMixerMaxLevel_CS", 0, TSS_DOUBLE, 0, sizeof(real_T),
        12,
        {
            2,
            6,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateMixerMaxLevel_CS, 12,
        Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_CS_b.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_CS_b.Value, 1,
        PreAmpMedusaFullRateMixerMaxLevel_CS_Dependencies
    },

    {                                  /* '<S809>/Tune Variable' */
        "PreAmpMedusaFullRateMixerMaxLevel_Left", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 30,
        {
            10,
            3,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateMixerMaxLevel_Left, 30,
        Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_Left_k.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_Left_k.Value, 1,
        PreAmpMedusaFullRateMixerMaxLevel_Left_Dependencies
    },

    {                                  /* '<S810>/Tune Variable' */
        "PreAmpMedusaFullRateMixerMaxLevel_Right", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 30,
        {
            10,
            3,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateMixerMaxLevel_Right, 30,
        Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_Right_e.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_Right_e.Value, 1,
        PreAmpMedusaFullRateMixerMaxLevel_Right_Dependencies
    },

    {                                  /* '<S811>/Tune Variable' */
        "PreAmpMedusaFullRateMixerMinLevel_CS", 0, TSS_DOUBLE, 0, sizeof(real_T),
        12,
        {
            2,
            6,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateMixerMinLevel_CS, 12,
        Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_CS_m.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_CS_m.Value, 1,
        PreAmpMedusaFullRateMixerMinLevel_CS_Dependencies
    },

    {                                  /* '<S812>/Tune Variable' */
        "PreAmpMedusaFullRateMixerMinLevel_Left", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 30,
        {
            10,
            3,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateMixerMinLevel_Left, 30,
        Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_Left_f.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_Left_f.Value, 1,
        PreAmpMedusaFullRateMixerMinLevel_Left_Dependencies
    },

    {                                  /* '<S813>/Tune Variable' */
        "PreAmpMedusaFullRateMixerMinLevel_Right", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 30,
        {
            10,
            3,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateMixerMinLevel_Right, 30,
        Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_Right_e.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_Right_e.Value, 1,
        PreAmpMedusaFullRateMixerMinLevel_Right_Dependencies
    },

    {                                  /* '<S848>/Tune Variable' */
        "PreAmpMedusaPremixMonoSurroundPhaseAngle", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaPremixMonoSurroundPhaseAngle, 1,
        Model_TranslationEngine64_Medusa5H1Part3_B.PhaseAngle.Size,
        &Model_TranslationEngine64_Medusa5H1Part3_B.PhaseAngle.Value, 1,
        PreAmpMedusaPremixMonoSurroundPhaseAngle_Dependencies
    },

    {                                  /* '<S852>/Tune Variable' */
        "PreAmpMedusaPremixBackwardDownmixMax", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaPremixBackwardDownmixMax, 1,
        Model_TranslationEngine64_Medusa5H1Part3_B.BackwardDownmixMax_h.Size,
        &Model_TranslationEngine64_Medusa5H1Part3_B.BackwardDownmixMax_h.Value,
        1, PreAmpMedusaPremixBackwardDownmixMax_Dependencies
    },

    {                                  /* '<S853>/Tune Variable' */
        "PreAmpMedusaPremixBackwardDownmixThreshold", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaPremixBackwardDownmixThreshold, 1,
        Model_TranslationEngine64_Medusa5H1Part3_B.BackwardDownmixThreshold_f.Size,
        &Model_TranslationEngine64_Medusa5H1Part3_B.BackwardDownmixThreshold_f.Value,
        1, PreAmpMedusaPremixBackwardDownmixThreshold_Dependencies
    },

    {                                  /* '<S854>/Tune Variable' */
        "PreAmpMedusaPremixDownmixWeights_CS", 0, TSS_DOUBLE, 0, sizeof(real_T),
        20,
        {
            2,
            10,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaPremixDownmixWeights_CS, 20,
        Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_CS.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_CS.Value, 1,
        PreAmpMedusaPremixDownmixWeights_CS_Dependencies
    },

    {                                  /* '<S855>/Tune Variable' */
        "PreAmpMedusaPremixDownmixWeights_Left", 0, TSS_DOUBLE, 0, sizeof(real_T),
        77,
        {
            11,
            7,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaPremixDownmixWeights_Left, 77,
        Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_Left.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_Left.Value, 1,
        PreAmpMedusaPremixDownmixWeights_Left_Dependencies
    },

    {                                  /* '<S856>/Tune Variable' */
        "PreAmpMedusaPremixDownmixWeights_Right", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 77,
        {
            11,
            7,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaPremixDownmixWeights_Right, 77,
        Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_Right.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_Right.Value, 1,
        PreAmpMedusaPremixDownmixWeights_Right_Dependencies
    },

    {                                  /* '<S857>/Tune Variable' */
        "PreAmpMedusaPremixForwardDownmixThreshold", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaPremixForwardDownmixThreshold, 1,
        Model_TranslationEngine64_Medusa5H1Part3_B.ForwardDownmixThreshold_o.Size,
        &Model_TranslationEngine64_Medusa5H1Part3_B.ForwardDownmixThreshold_o.Value,
        1, PreAmpMedusaPremixForwardDownmixThreshold_Dependencies
    },

    {                                  /* '<S858>/Tune Variable' */
        "PreAmpMedusaPremixForwardDownmixMax", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaPremixForwardDownmixMax, 1,
        Model_TranslationEngine64_Medusa5H1Part3_B.ForwardDownmixMax_d.Size,
        &Model_TranslationEngine64_Medusa5H1Part3_B.ForwardDownmixMax_d.Value, 1,
        PreAmpMedusaPremixForwardDownmixMax_Dependencies
    },

    {                                  /* '<S880>/Tune Variable' */
        "PreAmpMedusaPremixDetentLevel_CS", 0, TSS_DOUBLE, 0, sizeof(real_T), 20,
        {
            2,
            10,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaPremixDetentLevel_CS, 20,
        Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_CS.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_CS.Value, 1,
        PreAmpMedusaPremixDetentLevel_CS_Dependencies
    },

    {                                  /* '<S881>/Tune Variable' */
        "PreAmpMedusaPremixDetentLevel_Left", 0, TSS_DOUBLE, 0, sizeof(real_T),
        77,
        {
            11,
            7,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaPremixDetentLevel_Left, 77,
        Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_Left.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_Left.Value, 1,
        PreAmpMedusaPremixDetentLevel_Left_Dependencies
    },

    {                                  /* '<S882>/Tune Variable' */
        "PreAmpMedusaPremixDetentLevel_Right", 0, TSS_DOUBLE, 0, sizeof(real_T),
        77,
        {
            11,
            7,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaPremixDetentLevel_Right, 77,
        Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_Right.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_Right.Value, 1,
        PreAmpMedusaPremixDetentLevel_Right_Dependencies
    },

    {                                  /* '<S883>/Tune Variable' */
        "PreAmpMedusaPremixInterpolation_Method", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaPremixInterpolation_Method, 1,
        Model_TranslationEngine64_Medusa5H1Part3_B.Interpolation_Method_l.Size,
        &Model_TranslationEngine64_Medusa5H1Part3_B.Interpolation_Method_l.Value,
        1, PreAmpMedusaPremixInterpolation_Method_Dependencies
    },

    {                                  /* '<S884>/Tune Variable' */
        "PreAmpMedusaPremixMaxLevel_CS", 0, TSS_DOUBLE, 0, sizeof(real_T), 20,
        {
            2,
            10,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaPremixMaxLevel_CS, 20,
        Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_CS.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_CS.Value, 1,
        PreAmpMedusaPremixMaxLevel_CS_Dependencies
    },

    {                                  /* '<S885>/Tune Variable' */
        "PreAmpMedusaPremixMaxLevel_Left", 0, TSS_DOUBLE, 0, sizeof(real_T), 77,
        {
            11,
            7,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaPremixMaxLevel_Left, 77,
        Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_Left.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_Left.Value, 1,
        PreAmpMedusaPremixMaxLevel_Left_Dependencies
    },

    {                                  /* '<S886>/Tune Variable' */
        "PreAmpMedusaPremixMaxLevel_Right", 0, TSS_DOUBLE, 0, sizeof(real_T), 77,
        {
            11,
            7,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaPremixMaxLevel_Right, 77,
        Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_Right.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_Right.Value, 1,
        PreAmpMedusaPremixMaxLevel_Right_Dependencies
    },

    {                                  /* '<S887>/Tune Variable' */
        "PreAmpMedusaPremixMinLevel_CS", 0, TSS_DOUBLE, 0, sizeof(real_T), 20,
        {
            2,
            10,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaPremixMinLevel_CS, 20,
        Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_CS.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_CS.Value, 1,
        PreAmpMedusaPremixMinLevel_CS_Dependencies
    },

    {                                  /* '<S888>/Tune Variable' */
        "PreAmpMedusaPremixMinLevel_Left", 0, TSS_DOUBLE, 0, sizeof(real_T), 77,
        {
            11,
            7,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaPremixMinLevel_Left, 77,
        Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_Left.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_Left.Value, 1,
        PreAmpMedusaPremixMinLevel_Left_Dependencies
    },

    {                                  /* '<S889>/Tune Variable' */
        "PreAmpMedusaPremixMinLevel_Right", 0, TSS_DOUBLE, 0, sizeof(real_T), 77,
        {
            11,
            7,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaPremixMinLevel_Right, 77,
        Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_Right.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_Right.Value, 1,
        PreAmpMedusaPremixMinLevel_Right_Dependencies
    },

    {                                  /* '<S924>/Tune Variable' */
        "PreAmpMedusaVLSDrvGainsBackwardDownmixMax", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaVLSDrvGainsBackwardDownmixMax, 1,
        Model_TranslationEngine64_Medusa5H1Part3_B.BackwardDownmixMax_a.Size,
        &Model_TranslationEngine64_Medusa5H1Part3_B.BackwardDownmixMax_a.Value,
        1, PreAmpMedusaVLSDrvGainsBackwardDownmixMax_Dependencies
    },

    {                                  /* '<S925>/Tune Variable' */
        "PreAmpMedusaVLSDrvGainsBackwardDownmixThreshold", 0, TSS_DOUBLE, 0,
        sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaVLSDrvGainsBackwardDownmixThreshold, 1,
        Model_TranslationEngine64_Medusa5H1Part3_B.BackwardDownmixThreshold_c.Size,
        &Model_TranslationEngine64_Medusa5H1Part3_B.BackwardDownmixThreshold_c.Value,
        1, PreAmpMedusaVLSDrvGainsBackwardDownmixThreshold_Dependencies
    },

    {                                  /* '<S926>/Tune Variable' */
        "PreAmpMedusaVLSDrvGainsDownmixWeights", 0, TSS_DOUBLE, 0, sizeof(real_T),
        12,
        {
            12,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaVLSDrvGainsDownmixWeights, 12,
        Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights.Value, 1,
        PreAmpMedusaVLSDrvGainsDownmixWeights_Dependencies
    },

    {                                  /* '<S927>/Tune Variable' */
        "PreAmpMedusaVLSDrvGainsForwardDownmixThreshold", 0, TSS_DOUBLE, 0,
        sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaVLSDrvGainsForwardDownmixThreshold, 1,
        Model_TranslationEngine64_Medusa5H1Part3_B.ForwardDownmixThreshold_n.Size,
        &Model_TranslationEngine64_Medusa5H1Part3_B.ForwardDownmixThreshold_n.Value,
        1, PreAmpMedusaVLSDrvGainsForwardDownmixThreshold_Dependencies
    },

    {                                  /* '<S928>/Tune Variable' */
        "PreAmpMedusaVLSDrvGainsForwardDownmixMax", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaVLSDrvGainsForwardDownmixMax, 1,
        Model_TranslationEngine64_Medusa5H1Part3_B.ForwardDownmixMax_a.Size,
        &Model_TranslationEngine64_Medusa5H1Part3_B.ForwardDownmixMax_a.Value, 1,
        PreAmpMedusaVLSDrvGainsForwardDownmixMax_Dependencies
    },

    {                                  /* '<S944>/Tune Variable' */
        "PreAmpMedusaVLSDrvGainsDetentLevel", 0, TSS_DOUBLE, 0, sizeof(real_T),
        12,
        {
            12,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaVLSDrvGainsDetentLevel, 12,
        Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel.Value, 1,
        PreAmpMedusaVLSDrvGainsDetentLevel_Dependencies
    },

    {                                  /* '<S945>/Tune Variable' */
        "PreAmpMedusaVLSDrvGainsInterpolation_Method", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaVLSDrvGainsInterpolation_Method, 1,
        Model_TranslationEngine64_Medusa5H1Part3_B.Interpolation_Method_j.Size,
        &Model_TranslationEngine64_Medusa5H1Part3_B.Interpolation_Method_j.Value,
        1, PreAmpMedusaVLSDrvGainsInterpolation_Method_Dependencies
    },

    {                                  /* '<S946>/Tune Variable' */
        "PreAmpMedusaVLSDrvGainsMaxLevel", 0, TSS_DOUBLE, 0, sizeof(real_T), 12,
        {
            12,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaVLSDrvGainsMaxLevel, 12,
        Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel.Value, 1,
        PreAmpMedusaVLSDrvGainsMaxLevel_Dependencies
    },

    {                                  /* '<S947>/Tune Variable' */
        "PreAmpMedusaVLSDrvGainsMinLevel", 0, TSS_DOUBLE, 0, sizeof(real_T), 12,
        {
            12,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaVLSDrvGainsMinLevel, 12,
        Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel.Value, 1,
        PreAmpMedusaVLSDrvGainsMinLevel_Dependencies
    },

    {                                  /* '<S962>/Tune Variable' */
        "PreAmpMedusaVLSPaxGainsBackwardDownmixMax", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaVLSPaxGainsBackwardDownmixMax, 1,
        Model_TranslationEngine64_Medusa5H1Part3_B.BackwardDownmixMax_o.Size,
        &Model_TranslationEngine64_Medusa5H1Part3_B.BackwardDownmixMax_o.Value,
        1, PreAmpMedusaVLSPaxGainsBackwardDownmixMax_Dependencies
    },

    {                                  /* '<S963>/Tune Variable' */
        "PreAmpMedusaVLSPaxGainsBackwardDownmixThreshold", 0, TSS_DOUBLE, 0,
        sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaVLSPaxGainsBackwardDownmixThreshold, 1,
        Model_TranslationEngine64_Medusa5H1Part3_B.BackwardDownmixThreshold_i.Size,
        &Model_TranslationEngine64_Medusa5H1Part3_B.BackwardDownmixThreshold_i.Value,
        1, PreAmpMedusaVLSPaxGainsBackwardDownmixThreshold_Dependencies
    },

    {                                  /* '<S964>/Tune Variable' */
        "PreAmpMedusaVLSPaxGainsDownmixWeights", 0, TSS_DOUBLE, 0, sizeof(real_T),
        12,
        {
            12,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaVLSPaxGainsDownmixWeights, 12,
        Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_k.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_k.Value, 1,
        PreAmpMedusaVLSPaxGainsDownmixWeights_Dependencies
    },

    {                                  /* '<S965>/Tune Variable' */
        "PreAmpMedusaVLSPaxGainsForwardDownmixThreshold", 0, TSS_DOUBLE, 0,
        sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaVLSPaxGainsForwardDownmixThreshold, 1,
        Model_TranslationEngine64_Medusa5H1Part3_B.ForwardDownmixThreshold_h.Size,
        &Model_TranslationEngine64_Medusa5H1Part3_B.ForwardDownmixThreshold_h.Value,
        1, PreAmpMedusaVLSPaxGainsForwardDownmixThreshold_Dependencies
    },

    {                                  /* '<S966>/Tune Variable' */
        "PreAmpMedusaVLSPaxGainsForwardDownmixMax", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaVLSPaxGainsForwardDownmixMax, 1,
        Model_TranslationEngine64_Medusa5H1Part3_B.ForwardDownmixMax_o.Size,
        &Model_TranslationEngine64_Medusa5H1Part3_B.ForwardDownmixMax_o.Value, 1,
        PreAmpMedusaVLSPaxGainsForwardDownmixMax_Dependencies
    },

    {                                  /* '<S982>/Tune Variable' */
        "PreAmpMedusaVLSPaxGainsDetentLevel", 0, TSS_DOUBLE, 0, sizeof(real_T),
        12,
        {
            12,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaVLSPaxGainsDetentLevel, 12,
        Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_e.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_e.Value, 1,
        PreAmpMedusaVLSPaxGainsDetentLevel_Dependencies
    },

    {                                  /* '<S983>/Tune Variable' */
        "PreAmpMedusaVLSPaxGainsInterpolation_Method", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaVLSPaxGainsInterpolation_Method, 1,
        Model_TranslationEngine64_Medusa5H1Part3_B.Interpolation_Method_o.Size,
        &Model_TranslationEngine64_Medusa5H1Part3_B.Interpolation_Method_o.Value,
        1, PreAmpMedusaVLSPaxGainsInterpolation_Method_Dependencies
    },

    {                                  /* '<S984>/Tune Variable' */
        "PreAmpMedusaVLSPaxGainsMaxLevel", 0, TSS_DOUBLE, 0, sizeof(real_T), 12,
        {
            12,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaVLSPaxGainsMaxLevel, 12,
        Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_j.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_j.Value, 1,
        PreAmpMedusaVLSPaxGainsMaxLevel_Dependencies
    },

    {                                  /* '<S985>/Tune Variable' */
        "PreAmpMedusaVLSPaxGainsMinLevel", 0, TSS_DOUBLE, 0, sizeof(real_T), 12,
        {
            12,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaVLSPaxGainsMinLevel, 12,
        Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_m.Size,
        Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_m.Value, 1,
        PreAmpMedusaVLSPaxGainsMinLevel_Dependencies
    },

    {                                  /* '<S1004>/Tune Variable2' */
        "PreAmpMedusaDRHoligramPoolIirTunableConfigsosCoefficients", 0,
        TSS_DOUBLE, 0, sizeof(real_T), 7920,
        {
            1320,
            6,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0,
        DefValue_PreAmpMedusaDRHoligramPoolIirTunableConfigsosCoefficients, 4752,
        Model_TranslationEngine64_Medusa5H1Part4_B.sosCoefficients.Size,
        Model_TranslationEngine64_Medusa5H1Part4_B.sosCoefficients.Value, 1,
        PreAmpMedusaDRHoligramPoolIirTunableConfigsosCoefficients_Dependencies
    },

    {                                  /* '<S1004>/Tune Variable1' */
        "PreAmpMedusaDRHoligramPoolIirTunableConfignumStages", 0, TSS_DOUBLE, 0,
        sizeof(real_T), 66,
        {
            1,
            66,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaDRHoligramPoolIirTunableConfignumStages,
        66, Model_TranslationEngine64_Medusa5H1Part4_B.numStages.Size,
        Model_TranslationEngine64_Medusa5H1Part4_B.numStages.Value, 1,
        PreAmpMedusaDRHoligramPoolIirTunableConfignumStages_Dependencies
    },

    {                                  /* '<S1003>/Tune Variable' */
        "PreAmpMedusaDRHoligramFIRCoeffs", 0, TSS_DOUBLE, 0, sizeof(real_T),
        35112,
        {
            35112,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaDRHoligramFIRCoeffs, 35112,
        Model_TranslationEngine64_Medusa5H1Part4_B.FIRCoeffs.Size,
        Model_TranslationEngine64_Medusa5H1Part4_B.FIRCoeffs.Value, 1,
        PreAmpMedusaDRHoligramFIRCoeffs_Dependencies
    },

    {                                  /* '<S1003>/Tune Variable1' */
        "PreAmpMedusaDRHoligramFIRLengths", 0, TSS_UINT32, 0, sizeof(uint32_T),
        66,
        {
            66,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaDRHoligramFIRLengths, 66,
        Model_TranslationEngine64_Medusa5H1Part4_B.FIRLengths.Size,
        Model_TranslationEngine64_Medusa5H1Part4_B.FIRLengths.Value, 1,
        PreAmpMedusaDRHoligramFIRLengths_Dependencies
    },

    {                                  /* '<S1003>/Tune Variable2' */
        "PreAmpMedusaDRHoligramPaddedFIRLengths", 0, TSS_UINT32, 0, sizeof
        (uint32_T), 66,
        {
            66,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaDRHoligramPaddedFIRLengths, 66,
        Model_TranslationEngine64_Medusa5H1Part4_B.PaddedFIRLengths.Size,
        Model_TranslationEngine64_Medusa5H1Part4_B.PaddedFIRLengths.Value, 1,
        PreAmpMedusaDRHoligramPaddedFIRLengths_Dependencies
    },

    {                                  /* '<S1009>/Tune Variable' */
        "PreAmpMedusaDRHoligramInputMapping", 0, TSS_UINT32, 0, sizeof(uint32_T),
        66,
        {
            66,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaDRHoligramInputMapping, 66,
        Model_TranslationEngine64_Medusa5H1Part4_B.InputMapping.Size,
        Model_TranslationEngine64_Medusa5H1Part4_B.InputMapping.Value, 1,
        PreAmpMedusaDRHoligramInputMapping_Dependencies
    },

    {                                  /* '<S1010>/Tune Variable' */
        "PreAmpMedusaDRHoligramOutputMapping", 0, TSS_UINT32, 0, sizeof(uint32_T),
        18,
        {
            18,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaDRHoligramOutputMapping, 18,
        Model_TranslationEngine64_Medusa5H1Part4_B.OutputMapping.Size,
        Model_TranslationEngine64_Medusa5H1Part4_B.OutputMapping.Value, 1,
        PreAmpMedusaDRHoligramOutputMapping_Dependencies
    },

    {                                  /* '<S1022>/Tune Variable2' */
        "PreAmpMedusaFRHoligramIirConfigsosCoefficients", 0, TSS_DOUBLE, 0,
        sizeof(real_T), 1056,
        {
            176,
            6,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFRHoligramIirConfigsosCoefficients, 1056,
        Model_TranslationEngine64_Medusa5H1Part4_B.sosCoefficients_a.Size,
        Model_TranslationEngine64_Medusa5H1Part4_B.sosCoefficients_a.Value, 1,
        PreAmpMedusaFRHoligramIirConfigsosCoefficients_Dependencies
    },

    {                                  /* '<S1022>/Tune Variable1' */
        "PreAmpMedusaFRHoligramIirConfignumStages", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 22,
        {
            1,
            22,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFRHoligramIirConfignumStages, 22,
        Model_TranslationEngine64_Medusa5H1Part4_B.numStages_j.Size,
        Model_TranslationEngine64_Medusa5H1Part4_B.numStages_j.Value, 1,
        PreAmpMedusaFRHoligramIirConfignumStages_Dependencies
    },

    {                                  /* '<S1001>/Tune Variable' */
        "PreAmpMedusaHeadrestCompEQFIRCoeffs", 0, TSS_DOUBLE, 0, sizeof(real_T),
        6384,
        {
            6384,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaHeadrestCompEQFIRCoeffs, 6384,
        Model_TranslationEngine64_Medusa5H1Part4_B.FIRCoeffs_e.Size,
        Model_TranslationEngine64_Medusa5H1Part4_B.FIRCoeffs_e.Value, 1,
        PreAmpMedusaHeadrestCompEQFIRCoeffs_Dependencies
    },

    {                                  /* '<S1001>/Tune Variable1' */
        "PreAmpMedusaHeadrestCompEQFIRLengths", 0, TSS_DOUBLE, 0, sizeof(real_T),
        12,
        {
            12,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaHeadrestCompEQFIRLengths, 12,
        Model_TranslationEngine64_Medusa5H1Part4_B.FIRLengths_j.Size,
        Model_TranslationEngine64_Medusa5H1Part4_B.FIRLengths_j.Value, 1,
        PreAmpMedusaHeadrestCompEQFIRLengths_Dependencies
    },

    {                                  /* '<S1001>/Tune Variable2' */
        "PreAmpMedusaHeadrestCompEQPaddedFIRLengths", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 12,
        {
            12,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaHeadrestCompEQPaddedFIRLengths, 12,
        Model_TranslationEngine64_Medusa5H1Part4_B.PaddedFIRLengths_f.Size,
        Model_TranslationEngine64_Medusa5H1Part4_B.PaddedFIRLengths_f.Value, 1,
        PreAmpMedusaHeadrestCompEQPaddedFIRLengths_Dependencies
    },

    {                                  /* '<S1029>/Tune Variable2' */
        "PreAmpMedusaHeadrestCompEQIirConfigsosCoefficients", 0, TSS_DOUBLE, 0,
        sizeof(real_T), 1440,
        {
            240,
            6,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaHeadrestCompEQIirConfigsosCoefficients,
        576, Model_TranslationEngine64_Medusa5H1Part4_B.sosCoefficients_d.Size,
        Model_TranslationEngine64_Medusa5H1Part4_B.sosCoefficients_d.Value, 1,
        PreAmpMedusaHeadrestCompEQIirConfigsosCoefficients_Dependencies
    },

    {                                  /* '<S1029>/Tune Variable1' */
        "PreAmpMedusaHeadrestCompEQIirConfignumStages", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 12,
        {
            1,
            12,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaHeadrestCompEQIirConfignumStages, 12,
        Model_TranslationEngine64_Medusa5H1Part4_B.numStages_m.Size,
        Model_TranslationEngine64_Medusa5H1Part4_B.numStages_m.Value, 1,
        PreAmpMedusaHeadrestCompEQIirConfignumStages_Dependencies
    },

    {                                  /* '<S1034>/Tune Variable1' */
        "PreAmpMedusaNonHeadrestSpeakerDelaySamples", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 18,
        {
            1,
            18,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaNonHeadrestSpeakerDelaySamples, 18,
        Model_TranslationEngine64_Medusa5H1Part6_B.NonHeadrestSpeakerDelaySamples.Size,
        Model_TranslationEngine64_Medusa5H1Part6_B.NonHeadrestSpeakerDelaySamples.Value,
        1, PreAmpMedusaNonHeadrestSpeakerDelaySamples_Dependencies
    },

    {                                  /* '<S1034>/Tune Variable' */
        "PreAmpMedusaHeadrestDrvSpeakerDelaySamples", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaHeadrestDrvSpeakerDelaySamples, 1,
        Model_TranslationEngine64_Medusa5H1Part6_B.HeadrestDrvSpeakerDelaySamples.Size,
        &Model_TranslationEngine64_Medusa5H1Part6_B.HeadrestDrvSpeakerDelaySamples.Value,
        1, PreAmpMedusaHeadrestDrvSpeakerDelaySamples_Dependencies
    },

    {                                  /* '<S1034>/Tune Variable4' */
        "PreAmpMedusaHeadrestPaxSpeakerDelaySamples", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaHeadrestPaxSpeakerDelaySamples, 1,
        Model_TranslationEngine64_Medusa5H1Part6_B.HeadrestPaxSpeakerDelaySamples.Size,
        &Model_TranslationEngine64_Medusa5H1Part6_B.HeadrestPaxSpeakerDelaySamples.Value,
        1, PreAmpMedusaHeadrestPaxSpeakerDelaySamples_Dependencies
    },

    {                                  /* '<S1034>/Tune Variable5' */
        "PreAmpMedusaFRHoligramDelaySamples", 0, TSS_DOUBLE, 0, sizeof(real_T),
        22,
        {
            1,
            22,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFRHoligramDelaySamples, 22,
        Model_TranslationEngine64_Medusa5H1Part6_B.FRHoligramDelaySamples.Size,
        Model_TranslationEngine64_Medusa5H1Part6_B.FRHoligramDelaySamples.Value,
        1, PreAmpMedusaFRHoligramDelaySamples_Dependencies
    },

    {                                  /* '<S1041>/Tune Variable' */
        "PreAmpMedusaRoutingMap", 0, TSS_DOUBLE, 0, sizeof(real_T), 24,
        {
            1,
            24,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaRoutingMap, 24,
        Model_TranslationEngine64_MedusaPostHoligram_B.RoutingMap.Size,
        Model_TranslationEngine64_MedusaPostHoligram_B.RoutingMap.Value, 1,
        PreAmpMedusaRoutingMap_Dependencies
    },

    {                                  /* '<S1164>/Tune Variable2' */
        "PreAmpVLSXtalkCancellationIIRsosCoefficients", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1440,
        {
            240,
            6,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpVLSXtalkCancellationIIRsosCoefficients, 768,
        Model_TranslationEngine64_VLS_B.sosCoefficients.Size,
        Model_TranslationEngine64_VLS_B.sosCoefficients.Value, 1,
        PreAmpVLSXtalkCancellationIIRsosCoefficients_Dependencies
    },

    {                                  /* '<S1164>/Tune Variable1' */
        "PreAmpVLSXtalkCancellationIIRnumStages", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 16,
        {
            1,
            16,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpVLSXtalkCancellationIIRnumStages, 16,
        Model_TranslationEngine64_VLS_B.numStages.Size,
        Model_TranslationEngine64_VLS_B.numStages.Value, 1,
        PreAmpVLSXtalkCancellationIIRnumStages_Dependencies
    },

    {                                  /* '<S1162>/Tune Variable' */
        "PreAmpVLSXtalkCancellationDelay", 0, TSS_DOUBLE, 0, sizeof(real_T), 16,
        {
            16,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpVLSXtalkCancellationDelay, 16,
        Model_TranslationEngine64_VLS_B.Delay.Size,
        Model_TranslationEngine64_VLS_B.Delay.Value, 1,
        PreAmpVLSXtalkCancellationDelay_Dependencies
    },

    {                                  /* '<S1159>/Tune Variable' */
        "PreAmpVLSGenerationDrvFIRCoeffs", 0, TSS_DOUBLE, 0, sizeof(real_T),
        5760,
        {
            5760,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpVLSGenerationDrvFIRCoeffs, 5760,
        Model_TranslationEngine64_VLS_B.FIRCoeffs.Size,
        Model_TranslationEngine64_VLS_B.FIRCoeffs.Value, 1,
        PreAmpVLSGenerationDrvFIRCoeffs_Dependencies
    },

    {                                  /* '<S1159>/Tune Variable2' */
        "PreAmpVLSGenerationDrvPaddedFIRLengths", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 20,
        {
            20,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpVLSGenerationDrvPaddedFIRLengths, 20,
        Model_TranslationEngine64_VLS_B.PaddedFIRLengths.Size,
        Model_TranslationEngine64_VLS_B.PaddedFIRLengths.Value, 1,
        PreAmpVLSGenerationDrvPaddedFIRLengths_Dependencies
    },

    {                                  /* '<S1160>/Tune Variable' */
        "PreAmpVLSGenerationPaxFIRCoeffs", 0, TSS_DOUBLE, 0, sizeof(real_T),
        5760,
        {
            5760,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpVLSGenerationPaxFIRCoeffs, 5760,
        Model_TranslationEngine64_VLS_B.FIRCoeffs_l.Size,
        Model_TranslationEngine64_VLS_B.FIRCoeffs_l.Value, 1,
        PreAmpVLSGenerationPaxFIRCoeffs_Dependencies
    },

    {                                  /* '<S1160>/Tune Variable2' */
        "PreAmpVLSGenerationPaxPaddedFIRLengths", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 20,
        {
            20,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpVLSGenerationPaxPaddedFIRLengths, 20,
        Model_TranslationEngine64_VLS_B.PaddedFIRLengths_b.Size,
        Model_TranslationEngine64_VLS_B.PaddedFIRLengths_b.Value, 1,
        PreAmpVLSGenerationPaxPaddedFIRLengths_Dependencies
    },

    {                                  /* '<S1178>/BoostHz' */
        "PreAmpBassBoostFrequencyHz", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpBassBoostFrequencyHz, 1,
        Model_TranslationEngine64_PreAmpPart1_B.BoostFrequencyHz.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.BoostFrequencyHz.Value, 1,
        PreAmpBassBoostFrequencyHz_Dependencies
    },

    {                                  /* '<S1178>/CutHz' */
        "PreAmpBassCutFrequencyHz", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpBassCutFrequencyHz, 1,
        Model_TranslationEngine64_PreAmpPart1_B.CutFrequencyHz.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.CutFrequencyHz.Value, 1,
        PreAmpBassCutFrequencyHz_Dependencies
    },

    {                                  /* '<S1178>/Boost_dB' */
        "PreAmpBassBoostMaximum_dB", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpBassBoostMaximum_dB, 1,
        Model_TranslationEngine64_PreAmpPart1_B.BoostMaximum_dB.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.BoostMaximum_dB.Value, 1,
        PreAmpBassBoostMaximum_dB_Dependencies
    },

    {                                  /* '<S1178>/Cut_dB' */
        "PreAmpBassCutMaximum_dB", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpBassCutMaximum_dB, 1,
        Model_TranslationEngine64_PreAmpPart1_B.CutMaximum_dB.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.CutMaximum_dB.Value, 1,
        PreAmpBassCutMaximum_dB_Dependencies
    },

    {                                  /* '<S1186>/Tune Variable' */
        "PreAmpBassOffset", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpBassOffset, 1,
        Model_TranslationEngine64_PreAmpPart1_B.Offset.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.Offset.Value, 1,
        PreAmpBassOffset_Dependencies
    },

    {                                  /* '<S1187>/Tune Variable' */
        "PreAmpBassramptime", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpBassramptime, 1,
        Model_TranslationEngine64_PreAmpPart1_B.ramptime.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.ramptime.Value, 1,
        PreAmpBassramptime_Dependencies
    },

    {                                  /* '<S1188>/Tune Variable' */
        "PreAmpBassScale", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpBassScale, 1,
        Model_TranslationEngine64_PreAmpPart1_B.Scale.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.Scale.Value, 1,
        PreAmpBassScale_Dependencies
    },

    {                                  /* '<S1179>/BoostHz' */
        "PreAmpMidrangeBoostFrequencyHz", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMidrangeBoostFrequencyHz, 1,
        Model_TranslationEngine64_PreAmpPart1_B.BoostFrequencyHz_o.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.BoostFrequencyHz_o.Value, 1,
        PreAmpMidrangeBoostFrequencyHz_Dependencies
    },

    {                                  /* '<S1179>/Boost_Q' */
        "PreAmpMidrangeBoostQValue", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMidrangeBoostQValue, 1,
        Model_TranslationEngine64_PreAmpPart1_B.BoostQValue.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.BoostQValue.Value, 1,
        PreAmpMidrangeBoostQValue_Dependencies
    },

    {                                  /* '<S1179>/CutHz' */
        "PreAmpMidrangeCutFrequencyHz", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMidrangeCutFrequencyHz, 1,
        Model_TranslationEngine64_PreAmpPart1_B.CutFrequencyHz_p.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.CutFrequencyHz_p.Value, 1,
        PreAmpMidrangeCutFrequencyHz_Dependencies
    },

    {                                  /* '<S1179>/Cut_Q' */
        "PreAmpMidrangeCutQValue", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMidrangeCutQValue, 1,
        Model_TranslationEngine64_PreAmpPart1_B.CutQValue.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.CutQValue.Value, 1,
        PreAmpMidrangeCutQValue_Dependencies
    },

    {                                  /* '<S1179>/Boost_dB' */
        "PreAmpMidrangeBoostMaximum_dB", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMidrangeBoostMaximum_dB, 1,
        Model_TranslationEngine64_PreAmpPart1_B.BoostMaximum_dB_h.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.BoostMaximum_dB_h.Value, 1,
        PreAmpMidrangeBoostMaximum_dB_Dependencies
    },

    {                                  /* '<S1179>/Cut_dB' */
        "PreAmpMidrangeCutMaximum_dB", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMidrangeCutMaximum_dB, 1,
        Model_TranslationEngine64_PreAmpPart1_B.CutMaximum_dB_j.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.CutMaximum_dB_j.Value, 1,
        PreAmpMidrangeCutMaximum_dB_Dependencies
    },

    {                                  /* '<S1213>/Tune Variable' */
        "PreAmpMidrangeOffset", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMidrangeOffset, 1,
        Model_TranslationEngine64_PreAmpPart1_B.Offset_p.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.Offset_p.Value, 1,
        PreAmpMidrangeOffset_Dependencies
    },

    {                                  /* '<S1214>/Tune Variable' */
        "PreAmpMidrangeRampTime", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMidrangeRampTime, 1,
        Model_TranslationEngine64_PreAmpPart1_B.RampTime.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.RampTime.Value, 1,
        PreAmpMidrangeRampTime_Dependencies
    },

    {                                  /* '<S1215>/Tune Variable' */
        "PreAmpMidrangeScale", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMidrangeScale, 1,
        Model_TranslationEngine64_PreAmpPart1_B.Scale_k.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.Scale_k.Value, 1,
        PreAmpMidrangeScale_Dependencies
    },

    {                                  /* '<S1239>/Tune Variable' */
        "PreAmpA", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpA, 1,
        Model_TranslationEngine64_PreAmpPart1_B.A.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.A.Value, 1,
        PreAmpA_Dependencies
    },

    {                                  /* '<S1247>/Tune Variable' */
        "PreAmpG", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpG, 1,
        Model_TranslationEngine64_PreAmpPart1_B.G.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.G.Value, 1,
        PreAmpG_Dependencies
    },

    {                                  /* '<S1252>/Tune Variable' */
        "PreAmpAnnPred", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAnnPred, 1,
        Model_TranslationEngine64_PreAmpPart1_B.AnnPred.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.AnnPred.Value, 1,
        PreAmpAnnPred_Dependencies
    },

    {                                  /* '<S1253>/attackTune' */
        "PreAmpLimiterAttack", 0, TSS_DOUBLE, 0, sizeof(real_T), 32,
        {
            1,
            32,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpLimiterAttack, 32,
        Model_TranslationEngine64_PreAmpPart1_B.Attack.Size,
        Model_TranslationEngine64_PreAmpPart1_B.Attack.Value, 1,
        PreAmpLimiterAttack_Dependencies
    },

    {                                  /* '<S1253>/decay tune' */
        "PreAmpLimiterDecay", 0, TSS_DOUBLE, 0, sizeof(real_T), 32,
        {
            1,
            32,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpLimiterDecay, 32,
        Model_TranslationEngine64_PreAmpPart1_B.Decay.Size,
        Model_TranslationEngine64_PreAmpPart1_B.Decay.Value, 1,
        PreAmpLimiterDecay_Dependencies
    },

    {                                  /* '<S1253>/maxAttack tune' */
        "PreAmpLimiterMaxAttack", 0, TSS_DOUBLE, 0, sizeof(real_T), 32,
        {
            1,
            32,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpLimiterMaxAttack, 32,
        Model_TranslationEngine64_PreAmpPart1_B.MaxAttack.Size,
        Model_TranslationEngine64_PreAmpPart1_B.MaxAttack.Value, 1,
        PreAmpLimiterMaxAttack_Dependencies
    },

    {                                  /* '<S1254>/Tune Variable' */
        "PreAmpOffset", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpOffset, 1,
        Model_TranslationEngine64_PreAmpPart1_B.Offset_c.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.Offset_c.Value, 1,
        PreAmpOffset_Dependencies
    },

    {                                  /* '<S1255>/Tune Variable' */
        "PreAmpUpperThreshold", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpUpperThreshold, 1,
        Model_TranslationEngine64_PreAmpPart1_B.UpperThreshold.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.UpperThreshold.Value, 1,
        PreAmpUpperThreshold_Dependencies
    },

    {                                  /* '<S1181>/BoostHz' */
        "PreAmpTrebleBoostFrequencyHz", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpTrebleBoostFrequencyHz, 1,
        Model_TranslationEngine64_PreAmpPart1_B.BoostFrequencyHz_p.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.BoostFrequencyHz_p.Value, 1,
        PreAmpTrebleBoostFrequencyHz_Dependencies
    },

    {                                  /* '<S1181>/CutHz' */
        "PreAmpTrebleCutFrequencyHz", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpTrebleCutFrequencyHz, 1,
        Model_TranslationEngine64_PreAmpPart1_B.CutFrequencyHz_pm.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.CutFrequencyHz_pm.Value, 1,
        PreAmpTrebleCutFrequencyHz_Dependencies
    },

    {                                  /* '<S1181>/Boost_dB' */
        "PreAmpTrebleBoostMaximum_dB", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpTrebleBoostMaximum_dB, 1,
        Model_TranslationEngine64_PreAmpPart1_B.BoostMaximum_dB_k.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.BoostMaximum_dB_k.Value, 1,
        PreAmpTrebleBoostMaximum_dB_Dependencies
    },

    {                                  /* '<S1181>/Cut_dB' */
        "PreAmpTrebleCutMaximum_dB", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpTrebleCutMaximum_dB, 1,
        Model_TranslationEngine64_PreAmpPart1_B.CutMaximum_dB_e.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.CutMaximum_dB_e.Value, 1,
        PreAmpTrebleCutMaximum_dB_Dependencies
    },

    {                                  /* '<S1278>/Tune Variable' */
        "PreAmpTrebleOffset", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpTrebleOffset, 1,
        Model_TranslationEngine64_PreAmpPart1_B.Offset_cl.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.Offset_cl.Value, 1,
        PreAmpTrebleOffset_Dependencies
    },

    {                                  /* '<S1279>/Tune Variable' */
        "PreAmpTrebleramptime", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpTrebleramptime, 1,
        Model_TranslationEngine64_PreAmpPart1_B.ramptime_h.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.ramptime_h.Value, 1,
        PreAmpTrebleramptime_Dependencies
    },

    {                                  /* '<S1280>/Tune Variable' */
        "PreAmpTrebleScale", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpTrebleScale, 1,
        Model_TranslationEngine64_PreAmpPart1_B.Scale_a.Size,
        &Model_TranslationEngine64_PreAmpPart1_B.Scale_a.Value, 1,
        PreAmpTrebleScale_Dependencies
    },

    {                                  /* '<S1850>/attackTune' */
        "PostProcessLimiterAttack", 0, TSS_DOUBLE, 0, sizeof(real_T), 24,
        {
            1,
            24,
            1,
            1,
            1,
            1,
            1,
        },
        1, 2, 0, DefValue_PostProcessLimiterAttack, 24,
        Model_TranslationEngine64_PostProcess_B.Attack.Size,
        Model_TranslationEngine64_PostProcess_B.Attack.Value, 1,
        PostProcessLimiterAttack_Dependencies
    },

    {                                  /* '<S1850>/threshhold tune' */
        "PostProcessLimiterThreshold", 0, TSS_DOUBLE, 0, sizeof(real_T), 24,
        {
            1,
            24,
            1,
            1,
            1,
            1,
            1,
        },
        1, 2, 0, DefValue_PostProcessLimiterThreshold, 24,
        Model_TranslationEngine64_PostProcess_B.Threshold.Size,
        Model_TranslationEngine64_PostProcess_B.Threshold.Value, 1,
        PostProcessLimiterThreshold_Dependencies
    },

    {                                  /* '<S1850>/attackTune1' */
        "PostProcessLimiterAttack_low", 0, TSS_DOUBLE, 0, sizeof(real_T), 24,
        {
            1,
            24,
            1,
            1,
            1,
            1,
            1,
        },
        1, 2, 0, DefValue_PostProcessLimiterAttack_low, 24,
        Model_TranslationEngine64_PostProcess_B.Attack_low.Size,
        Model_TranslationEngine64_PostProcess_B.Attack_low.Value, 1,
        PostProcessLimiterAttack_low_Dependencies
    },

    {                                  /* '<S1850>/threshhold tune1' */
        "PostProcessLimiterThreshold_low", 0, TSS_DOUBLE, 0, sizeof(real_T), 24,
        {
            1,
            24,
            1,
            1,
            1,
            1,
            1,
        },
        1, 2, 0, DefValue_PostProcessLimiterThreshold_low, 24,
        Model_TranslationEngine64_PostProcess_B.Threshold_low.Size,
        Model_TranslationEngine64_PostProcess_B.Threshold_low.Value, 1,
        PostProcessLimiterThreshold_low_Dependencies
    },

    {                                  /* '<S1850>/decay tune' */
        "PostProcessLimiterDecay", 0, TSS_DOUBLE, 0, sizeof(real_T), 24,
        {
            1,
            24,
            1,
            1,
            1,
            1,
            1,
        },
        1, 2, 0, DefValue_PostProcessLimiterDecay, 24,
        Model_TranslationEngine64_PostProcess_B.Decay.Size,
        Model_TranslationEngine64_PostProcess_B.Decay.Value, 1,
        PostProcessLimiterDecay_Dependencies
    },

    {                                  /* '<S1850>/decay tune1' */
        "PostProcessLimiterDecay_low", 0, TSS_DOUBLE, 0, sizeof(real_T), 24,
        {
            1,
            24,
            1,
            1,
            1,
            1,
            1,
        },
        1, 2, 0, DefValue_PostProcessLimiterDecay_low, 24,
        Model_TranslationEngine64_PostProcess_B.Decay_low.Size,
        Model_TranslationEngine64_PostProcess_B.Decay_low.Value, 1,
        PostProcessLimiterDecay_low_Dependencies
    },

    {                                  /* '<S1850>/maxAttack tune' */
        "PostProcessLimiterMaxAttack", 0, TSS_DOUBLE, 0, sizeof(real_T), 24,
        {
            1,
            24,
            1,
            1,
            1,
            1,
            1,
        },
        1, 2, 0, DefValue_PostProcessLimiterMaxAttack, 24,
        Model_TranslationEngine64_PostProcess_B.MaxAttack.Size,
        Model_TranslationEngine64_PostProcess_B.MaxAttack.Value, 1,
        PostProcessLimiterMaxAttack_Dependencies
    },

    {                                  /* '<S1850>/maxAttack tune1' */
        "PostProcessLimiterMaxAttack_low", 0, TSS_DOUBLE, 0, sizeof(real_T), 24,
        {
            1,
            24,
            1,
            1,
            1,
            1,
            1,
        },
        1, 2, 0, DefValue_PostProcessLimiterMaxAttack_low, 24,
        Model_TranslationEngine64_PostProcess_B.MaxAttack_low.Size,
        Model_TranslationEngine64_PostProcess_B.MaxAttack_low.Value, 1,
        PostProcessLimiterMaxAttack_low_Dependencies
    },

    {                                  /* '<S1871>/Tune Variable' */
        "PostProcessMuteRampTime", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PostProcessMuteRampTime, 1,
        Model_TranslationEngine64_PostProcess_B.RampTime.Size,
        &Model_TranslationEngine64_PostProcess_B.RampTime.Value, 1,
        PostProcessMuteRampTime_Dependencies
    },

    {                                  /* '<S1876>/Tune Variable2' */
        "PostProcessPostLimiterEqsosCoefficients", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 768,
        {
            128,
            6,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PostProcessPostLimiterEqsosCoefficients, 144,
        Model_TranslationEngine64_PostProcess_B.sosCoefficients.Size,
        Model_TranslationEngine64_PostProcess_B.sosCoefficients.Value, 1,
        PostProcessPostLimiterEqsosCoefficients_Dependencies
    },

    {                                  /* '<S1876>/Tune Variable1' */
        "PostProcessPostLimiterEqnumStages", 0, TSS_SINGLE, 0, sizeof(real32_T),
        24,
        {
            1,
            24,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PostProcessPostLimiterEqnumStages, 24,
        Model_TranslationEngine64_PostProcess_B.numStages.Size,
        Model_TranslationEngine64_PostProcess_B.numStages.Value, 1,
        PostProcessPostLimiterEqnumStages_Dependencies
    },

    {                                  /* '<S1880>/ymax TuneVar' */
        "PostProcessSoftClipperYMax", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        1, 2, 0, DefValue_PostProcessSoftClipperYMax, 1,
        Model_TranslationEngine64_PostProcess_B.YMax.Size,
        &Model_TranslationEngine64_PostProcess_B.YMax.Value, 1,
        PostProcessSoftClipperYMax_Dependencies
    },

    {                                  /* '<S1880>/xmin TuneVar' */
        "PostProcessSoftClipperXMin", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        1, 2, 0, DefValue_PostProcessSoftClipperXMin, 1,
        Model_TranslationEngine64_PostProcess_B.XMin.Size,
        &Model_TranslationEngine64_PostProcess_B.XMin.Value, 1,
        PostProcessSoftClipperXMin_Dependencies
    },

    {                                  /* '<S1880>/ymax TuneVar1' */
        "PostProcessSoftClipperYMaxLow", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        1, 2, 0, DefValue_PostProcessSoftClipperYMaxLow, 1,
        Model_TranslationEngine64_PostProcess_B.YMaxLow.Size,
        &Model_TranslationEngine64_PostProcess_B.YMaxLow.Value, 1,
        PostProcessSoftClipperYMaxLow_Dependencies
    },

    {                                  /* '<S1880>/xmin TuneVar1' */
        "PostProcessSoftClipperXMinLow", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        1, 2, 0, DefValue_PostProcessSoftClipperXMinLow, 1,
        Model_TranslationEngine64_PostProcess_B.XMinLow.Size,
        &Model_TranslationEngine64_PostProcess_B.XMinLow.Value, 1,
        PostProcessSoftClipperXMinLow_Dependencies
    },

    {                                  /* '<S7>/TuneVarRouterMap' */
        "InputSelectRouterCfgMap", 0, TSS_DOUBLE, 0, sizeof(real_T), 5,
        {
            1,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        1, 2, 0, DefValue_InputSelectRouterCfgMap, 5,
        Model_TranslationEngine64_B.Map_b.Size,
        Model_TranslationEngine64_B.Map_b.Value, 1,
        InputSelectRouterCfgMap_Dependencies
    },

    {                                  /* '<S598>/TuneVar' */
        "PreAmpMedusaSurroundOn", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaSurroundOn, 1,
        Model_TranslationEngine64_B.SurroundOn.Size,
        &Model_TranslationEngine64_B.SurroundOn.Value, 1,
        PreAmpMedusaSurroundOn_Dependencies
    },

    {                                  /* '<S605>/LeftMixIns' */
        "PreAmpMedusaBassManagerLeftMixWeights", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaBassManagerLeftMixWeights, 1,
        Model_TranslationEngine64_B.LeftMixWeights.Size,
        &Model_TranslationEngine64_B.LeftMixWeights.Value, 1,
        PreAmpMedusaBassManagerLeftMixWeights_Dependencies
    },

    {                                  /* '<S605>/RightMixIns' */
        "PreAmpMedusaBassManagerRightMixWeights", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaBassManagerRightMixWeights, 1,
        Model_TranslationEngine64_B.RightMixWeights.Size,
        &Model_TranslationEngine64_B.RightMixWeights.Value, 1,
        PreAmpMedusaBassManagerRightMixWeights_Dependencies
    },

    {                                  /* '<S612>/Tune Variable2' */
        "PreAmpMedusaBassManagerHpfsosCoefficients", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 36,
        {
            6,
            6,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaBassManagerHpfsosCoefficients, 24,
        Model_TranslationEngine64_B.sosCoefficients_c.Size,
        Model_TranslationEngine64_B.sosCoefficients_c.Value, 1,
        PreAmpMedusaBassManagerHpfsosCoefficients_Dependencies
    },

    {                                  /* '<S612>/Tune Variable1' */
        "PreAmpMedusaBassManagerHpfnumStages", 0, TSS_DOUBLE, 0, sizeof(real_T),
        2,
        {
            1,
            2,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaBassManagerHpfnumStages, 2,
        Model_TranslationEngine64_B.numStages_h.Size,
        Model_TranslationEngine64_B.numStages_h.Value, 1,
        PreAmpMedusaBassManagerHpfnumStages_Dependencies
    },

    {                                  /* '<S616>/Tune Variable2' */
        "PreAmpMedusaBassManagerLpfsosCoefficients", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 36,
        {
            6,
            6,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaBassManagerLpfsosCoefficients, 24,
        Model_TranslationEngine64_B.sosCoefficients_b.Size,
        Model_TranslationEngine64_B.sosCoefficients_b.Value, 1,
        PreAmpMedusaBassManagerLpfsosCoefficients_Dependencies
    },

    {                                  /* '<S616>/Tune Variable1' */
        "PreAmpMedusaBassManagerLpfnumStages", 0, TSS_DOUBLE, 0, sizeof(real_T),
        2,
        {
            1,
            2,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaBassManagerLpfnumStages, 2,
        Model_TranslationEngine64_B.numStages_nz.Size,
        Model_TranslationEngine64_B.numStages_nz.Value, 1,
        PreAmpMedusaBassManagerLpfnumStages_Dependencies
    },

    {                                  /* '<S608>/Tune Variable' */
        "PreAmpMedusaBassManagerGainLfe2C", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaBassManagerGainLfe2C, 1,
        Model_TranslationEngine64_B.GainLfe2C.Size,
        &Model_TranslationEngine64_B.GainLfe2C.Value, 1,
        PreAmpMedusaBassManagerGainLfe2C_Dependencies
    },

    {                                  /* '<S625>/Tune Variable' */
        "PreAmpMedusaDummyTune", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaDummyTune, 1,
        Model_TranslationEngine64_B.DummyTune.Size,
        &Model_TranslationEngine64_B.DummyTune.Value, 1,
        PreAmpMedusaDummyTune_Dependencies
    },

    {                                  /* '<S639>/Tune Variable3' */
        "PreAmpMedusaDeciRateFdpLsSmoothCutoff", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaDeciRateFdpLsSmoothCutoff, 1,
        Model_TranslationEngine64_B.LsSmoothCutoff.Size,
        &Model_TranslationEngine64_B.LsSmoothCutoff.Value, 1,
        PreAmpMedusaDeciRateFdpLsSmoothCutoff_Dependencies
    },

    {                                  /* '<S639>/Tune Variable' */
        "PreAmpMedusaDeciRateFdpSlowPsdSmoothCutoff", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaDeciRateFdpSlowPsdSmoothCutoff, 1,
        Model_TranslationEngine64_B.SlowPsdSmoothCutoff.Size,
        &Model_TranslationEngine64_B.SlowPsdSmoothCutoff.Value, 1,
        PreAmpMedusaDeciRateFdpSlowPsdSmoothCutoff_Dependencies
    },

    {                                  /* '<S639>/Tune Variable1' */
        "PreAmpMedusaDeciRateFdpFastPsdSmoothCutoff", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaDeciRateFdpFastPsdSmoothCutoff, 1,
        Model_TranslationEngine64_B.FastPsdSmoothCutoff.Size,
        &Model_TranslationEngine64_B.FastPsdSmoothCutoff.Value, 1,
        PreAmpMedusaDeciRateFdpFastPsdSmoothCutoff_Dependencies
    },

    {                                  /* '<S639>/Tune Variable2' */
        "PreAmpMedusaDeciRateFdpDirectPathSec", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaDeciRateFdpDirectPathSec, 1,
        Model_TranslationEngine64_B.DirectPathSec.Size,
        &Model_TranslationEngine64_B.DirectPathSec.Value, 1,
        PreAmpMedusaDeciRateFdpDirectPathSec_Dependencies
    },

    {                                  /* '<S639>/Tune Variable7' */
        "PreAmpMedusaDeciRateFdpXpMax", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaDeciRateFdpXpMax, 1,
        Model_TranslationEngine64_B.XpMax.Size,
        &Model_TranslationEngine64_B.XpMax.Value, 1,
        PreAmpMedusaDeciRateFdpXpMax_Dependencies
    },

    {                                  /* '<S646>/Tune Variable3' */
        "PreAmpMedusaDeciRateFdpCoeffsXpMin", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaDeciRateFdpCoeffsXpMin, 1,
        Model_TranslationEngine64_B.XpMin.Size,
        &Model_TranslationEngine64_B.XpMin.Value, 1,
        PreAmpMedusaDeciRateFdpCoeffsXpMin_Dependencies
    },

    {                                  /* '<S646>/Tune Variable1' */
        "PreAmpMedusaDeciRateFdpCoeffsESDUpperbounddB", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaDeciRateFdpCoeffsESDUpperbounddB, 1,
        Model_TranslationEngine64_B.ESDUpperbounddB.Size,
        &Model_TranslationEngine64_B.ESDUpperbounddB.Value, 1,
        PreAmpMedusaDeciRateFdpCoeffsESDUpperbounddB_Dependencies
    },

    {                                  /* '<S646>/Tune Variable2' */
        "PreAmpMedusaDeciRateFdpCoeffsESDLowerbounddB", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaDeciRateFdpCoeffsESDLowerbounddB, 1,
        Model_TranslationEngine64_B.ESDLowerbounddB.Size,
        &Model_TranslationEngine64_B.ESDLowerbounddB.Value, 1,
        PreAmpMedusaDeciRateFdpCoeffsESDLowerbounddB_Dependencies
    },

    {                                  /* '<S641>/Tune Variable' */
        "PreAmpMedusaDeciRateFdpSpumOverwrite", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaDeciRateFdpSpumOverwrite, 1,
        Model_TranslationEngine64_B.SpumOverwrite.Size,
        &Model_TranslationEngine64_B.SpumOverwrite.Value, 1,
        PreAmpMedusaDeciRateFdpSpumOverwrite_Dependencies
    },

    {                                  /* '<S666>/Tune Variable3' */
        "PreAmpMedusaFullRateFdpLsSmoothCutoff", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateFdpLsSmoothCutoff, 1,
        Model_TranslationEngine64_B.LsSmoothCutoff_c.Size,
        &Model_TranslationEngine64_B.LsSmoothCutoff_c.Value, 1,
        PreAmpMedusaFullRateFdpLsSmoothCutoff_Dependencies
    },

    {                                  /* '<S666>/Tune Variable' */
        "PreAmpMedusaFullRateFdpSlowPsdSmoothCutoff", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateFdpSlowPsdSmoothCutoff, 1,
        Model_TranslationEngine64_B.SlowPsdSmoothCutoff_a.Size,
        &Model_TranslationEngine64_B.SlowPsdSmoothCutoff_a.Value, 1,
        PreAmpMedusaFullRateFdpSlowPsdSmoothCutoff_Dependencies
    },

    {                                  /* '<S666>/Tune Variable1' */
        "PreAmpMedusaFullRateFdpFastPsdSmoothCutoff", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateFdpFastPsdSmoothCutoff, 1,
        Model_TranslationEngine64_B.FastPsdSmoothCutoff_j.Size,
        &Model_TranslationEngine64_B.FastPsdSmoothCutoff_j.Value, 1,
        PreAmpMedusaFullRateFdpFastPsdSmoothCutoff_Dependencies
    },

    {                                  /* '<S666>/Tune Variable2' */
        "PreAmpMedusaFullRateFdpDirectPathSec", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateFdpDirectPathSec, 1,
        Model_TranslationEngine64_B.DirectPathSec_p.Size,
        &Model_TranslationEngine64_B.DirectPathSec_p.Value, 1,
        PreAmpMedusaFullRateFdpDirectPathSec_Dependencies
    },

    {                                  /* '<S666>/Tune Variable7' */
        "PreAmpMedusaFullRateFdpXpMax", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateFdpXpMax, 1,
        Model_TranslationEngine64_B.XpMax_c.Size,
        &Model_TranslationEngine64_B.XpMax_c.Value, 1,
        PreAmpMedusaFullRateFdpXpMax_Dependencies
    },

    {                                  /* '<S673>/Tune Variable' */
        "PreAmpMedusaFullRateFdpCoeffsXpMax", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateFdpCoeffsXpMax, 1,
        Model_TranslationEngine64_B.XpMax_ce.Size,
        &Model_TranslationEngine64_B.XpMax_ce.Value, 1,
        PreAmpMedusaFullRateFdpCoeffsXpMax_Dependencies
    },

    {                                  /* '<S673>/Tune Variable3' */
        "PreAmpMedusaFullRateFdpCoeffsXpMin", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateFdpCoeffsXpMin, 1,
        Model_TranslationEngine64_B.XpMin_c.Size,
        &Model_TranslationEngine64_B.XpMin_c.Value, 1,
        PreAmpMedusaFullRateFdpCoeffsXpMin_Dependencies
    },

    {                                  /* '<S673>/Tune Variable1' */
        "PreAmpMedusaFullRateFdpCoeffsESDUpperbounddB", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateFdpCoeffsESDUpperbounddB, 1,
        Model_TranslationEngine64_B.ESDUpperbounddB_b.Size,
        &Model_TranslationEngine64_B.ESDUpperbounddB_b.Value, 1,
        PreAmpMedusaFullRateFdpCoeffsESDUpperbounddB_Dependencies
    },

    {                                  /* '<S673>/Tune Variable2' */
        "PreAmpMedusaFullRateFdpCoeffsESDLowerbounddB", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateFdpCoeffsESDLowerbounddB, 1,
        Model_TranslationEngine64_B.ESDLowerbounddB_k.Size,
        &Model_TranslationEngine64_B.ESDLowerbounddB_k.Value, 1,
        PreAmpMedusaFullRateFdpCoeffsESDLowerbounddB_Dependencies
    },

    {                                  /* '<S668>/Tune Variable' */
        "PreAmpMedusaFullRateFdpSpumOverwrite", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaFullRateFdpSpumOverwrite, 1,
        Model_TranslationEngine64_B.SpumOverwrite_b.Size,
        &Model_TranslationEngine64_B.SpumOverwrite_b.Value, 1,
        PreAmpMedusaFullRateFdpSpumOverwrite_Dependencies
    },

    {                                  /* '<S695>/Tune Variable' */
        "PreAmpMedusaMonoDetectorLevelCutoff", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaMonoDetectorLevelCutoff, 1,
        Model_TranslationEngine64_B.LevelCutoff.Size,
        &Model_TranslationEngine64_B.LevelCutoff.Value, 1,
        PreAmpMedusaMonoDetectorLevelCutoff_Dependencies
    },

    {                                  /* '<S695>/Tune Variable1' */
        "PreAmpMedusaMonoDetectorLSSmoothCutoff", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaMonoDetectorLSSmoothCutoff, 1,
        Model_TranslationEngine64_B.LSSmoothCutoff.Size,
        &Model_TranslationEngine64_B.LSSmoothCutoff.Value, 1,
        PreAmpMedusaMonoDetectorLSSmoothCutoff_Dependencies
    },

    {                                  /* '<S695>/Tune Variable2' */
        "PreAmpMedusaMonoDetectorLSSmoothResetCutoff", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaMonoDetectorLSSmoothResetCutoff, 1,
        Model_TranslationEngine64_B.LSSmoothResetCutoff.Size,
        &Model_TranslationEngine64_B.LSSmoothResetCutoff.Value, 1,
        PreAmpMedusaMonoDetectorLSSmoothResetCutoff_Dependencies
    },

    {                                  /* '<S695>/Tune Variable7' */
        "PreAmpMedusaMonoDetectorHPFCutoff", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaMonoDetectorHPFCutoff, 1,
        Model_TranslationEngine64_B.HPFCutoff.Size,
        &Model_TranslationEngine64_B.HPFCutoff.Value, 1,
        PreAmpMedusaMonoDetectorHPFCutoff_Dependencies
    },

    {                                  /* '<S695>/Tune Variable3' */
        "PreAmpMedusaMonoDetectorNoiseFloordB", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaMonoDetectorNoiseFloordB, 1,
        Model_TranslationEngine64_B.NoiseFloordB.Size,
        &Model_TranslationEngine64_B.NoiseFloordB.Value, 1,
        PreAmpMedusaMonoDetectorNoiseFloordB_Dependencies
    },

    {                                  /* '<S695>/Tune Variable4' */
        "PreAmpMedusaMonoDetectorLRMatchTolerancedB", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaMonoDetectorLRMatchTolerancedB, 1,
        Model_TranslationEngine64_B.LRMatchTolerancedB.Size,
        &Model_TranslationEngine64_B.LRMatchTolerancedB.Value, 1,
        PreAmpMedusaMonoDetectorLRMatchTolerancedB_Dependencies
    },

    {                                  /* '<S695>/Tune Variable5' */
        "PreAmpMedusaMonoDetectorThresholdMonoInput", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaMonoDetectorThresholdMonoInput, 1,
        Model_TranslationEngine64_B.ThresholdMonoInput.Size,
        &Model_TranslationEngine64_B.ThresholdMonoInput.Value, 1,
        PreAmpMedusaMonoDetectorThresholdMonoInput_Dependencies
    },

    {                                  /* '<S695>/Tune Variable6' */
        "PreAmpMedusaMonoDetectorThresholdStereoInput", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaMonoDetectorThresholdStereoInput, 1,
        Model_TranslationEngine64_B.ThresholdStereoInput.Size,
        &Model_TranslationEngine64_B.ThresholdStereoInput.Value, 1,
        PreAmpMedusaMonoDetectorThresholdStereoInput_Dependencies
    },

    {                                  /* '<S694>/Tune Variable' */
        "PreAmpMedusaMonoDetectorEnable", 0, TSS_INT32, 0, sizeof(int32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaMonoDetectorEnable, 1,
        Model_TranslationEngine64_B.Enable.Size,
        &Model_TranslationEngine64_B.Enable.Value, 1,
        PreAmpMedusaMonoDetectorEnable_Dependencies
    },

    {                                  /* '<S715>/Tune Variable' */
        "PreAmpMedusaSPUMDecayEstPSDSmoothCutoff", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaSPUMDecayEstPSDSmoothCutoff, 1,
        Model_TranslationEngine64_B.PSDSmoothCutoff.Size,
        &Model_TranslationEngine64_B.PSDSmoothCutoff.Value, 1,
        PreAmpMedusaSPUMDecayEstPSDSmoothCutoff_Dependencies
    },

    {                                  /* '<S715>/Tune Variable1' */
        "PreAmpMedusaSPUMDecayEstDecaySmoothCutoff", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaSPUMDecayEstDecaySmoothCutoff, 1,
        Model_TranslationEngine64_B.DecaySmoothCutoff.Size,
        &Model_TranslationEngine64_B.DecaySmoothCutoff.Value, 1,
        PreAmpMedusaSPUMDecayEstDecaySmoothCutoff_Dependencies
    },

    {                                  /* '<S715>/Tune Variable2' */
        "PreAmpMedusaSPUMDecayEstFastAttackCutoff", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaSPUMDecayEstFastAttackCutoff, 1,
        Model_TranslationEngine64_B.FastAttackCutoff.Size,
        &Model_TranslationEngine64_B.FastAttackCutoff.Value, 1,
        PreAmpMedusaSPUMDecayEstFastAttackCutoff_Dependencies
    },

    {                                  /* '<S715>/Tune Variable3' */
        "PreAmpMedusaSPUMDecayEstSlowAttackCutoff", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaSPUMDecayEstSlowAttackCutoff, 1,
        Model_TranslationEngine64_B.SlowAttackCutoff.Size,
        &Model_TranslationEngine64_B.SlowAttackCutoff.Value, 1,
        PreAmpMedusaSPUMDecayEstSlowAttackCutoff_Dependencies
    },

    {                                  /* '<S715>/Tune Variable4' */
        "PreAmpMedusaSPUMDecayEstStepSize", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaSPUMDecayEstStepSize, 1,
        Model_TranslationEngine64_B.StepSize.Size,
        &Model_TranslationEngine64_B.StepSize.Value, 1,
        PreAmpMedusaSPUMDecayEstStepSize_Dependencies
    },

    {                                  /* '<S715>/Tune Variable5' */
        "PreAmpMedusaSPUMDecayEstDirectPathSec", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaSPUMDecayEstDirectPathSec, 1,
        Model_TranslationEngine64_B.DirectPathSec_k.Size,
        &Model_TranslationEngine64_B.DirectPathSec_k.Value, 1,
        PreAmpMedusaSPUMDecayEstDirectPathSec_Dependencies
    },

    {                                  /* '<S727>/Tune Variable' */
        "PreAmpMedusaSPUMDecayEstNoiseFloor", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaSPUMDecayEstNoiseFloor, 1,
        Model_TranslationEngine64_B.NoiseFloor.Size,
        &Model_TranslationEngine64_B.NoiseFloor.Value, 1,
        PreAmpMedusaSPUMDecayEstNoiseFloor_Dependencies
    },

    {                                  /* '<S728>/Tune Variable' */
        "PreAmpMedusaSPUMDecayEstOnsetThreshold", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaSPUMDecayEstOnsetThreshold, 1,
        Model_TranslationEngine64_B.OnsetThreshold.Size,
        &Model_TranslationEngine64_B.OnsetThreshold.Value, 1,
        PreAmpMedusaSPUMDecayEstOnsetThreshold_Dependencies
    },

    {                                  /* '<S729>/Tune Variable' */
        "PreAmpMedusaSPUMDecayEstSlewThreshold", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaSPUMDecayEstSlewThreshold, 1,
        Model_TranslationEngine64_B.SlewThreshold.Size,
        &Model_TranslationEngine64_B.SlewThreshold.Value, 1,
        PreAmpMedusaSPUMDecayEstSlewThreshold_Dependencies
    },

    {                                  /* '<S748>/Tune Variable2' */
        "PreAmpMedusaSPUMDecayEstHPFsosCoefficients", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 72,
        {
            12,
            6,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaSPUMDecayEstHPFsosCoefficients, 36,
        Model_TranslationEngine64_B.sosCoefficients_f.Size,
        Model_TranslationEngine64_B.sosCoefficients_f.Value, 1,
        PreAmpMedusaSPUMDecayEstHPFsosCoefficients_Dependencies
    },

    {                                  /* '<S748>/Tune Variable1' */
        "PreAmpMedusaSPUMDecayEstHPFnumStages", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 2,
        {
            1,
            2,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMedusaSPUMDecayEstHPFnumStages, 2,
        Model_TranslationEngine64_B.numStages_e.Size,
        Model_TranslationEngine64_B.numStages_e.Value, 1,
        PreAmpMedusaSPUMDecayEstHPFnumStages_Dependencies
    },

    {                                  /* '<S1068>/Tune Variable' */
        "PreAmpFadeControlBoostDisable", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpFadeControlBoostDisable, 1,
        Model_TranslationEngine64_B.BoostDisable.Size,
        &Model_TranslationEngine64_B.BoostDisable.Value, 1,
        PreAmpFadeControlBoostDisable_Dependencies
    },

    {                                  /* '<S1069>/Tune Variable' */
        "PreAmpFadeControlEnableSilentExtreme", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpFadeControlEnableSilentExtreme, 1,
        Model_TranslationEngine64_B.EnableSilentExtreme.Size,
        &Model_TranslationEngine64_B.EnableSilentExtreme.Value, 1,
        PreAmpFadeControlEnableSilentExtreme_Dependencies
    },

    {                                  /* '<S1070>/TuneVarFadeTable' */
        "PreAmpFadeControlTable", 0, TSS_DOUBLE, 0, sizeof(real_T), 60,
        {
            30,
            2,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpFadeControlTable, 30,
        Model_TranslationEngine64_B.Table.Size,
        Model_TranslationEngine64_B.Table.Value, 1,
        PreAmpFadeControlTable_Dependencies
    },

    {                                  /* '<S1071>/Tune Variable' */
        "PreAmpFadeControloffset", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpFadeControloffset, 1,
        Model_TranslationEngine64_B.offset.Size,
        &Model_TranslationEngine64_B.offset.Value, 1,
        PreAmpFadeControloffset_Dependencies
    },

    {                                  /* '<S1072>/Tune Variable' */
        "PreAmpFadeControlRampTime", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpFadeControlRampTime, 1,
        Model_TranslationEngine64_B.RampTime_bg.Size,
        &Model_TranslationEngine64_B.RampTime_bg.Value, 1,
        PreAmpFadeControlRampTime_Dependencies
    },

    {                                  /* '<S1092>/TuneVarChannelRamperMap' */
        "PreAmpFadeRamperDRChannelToRamperMap", 0, TSS_DOUBLE, 0, sizeof(real_T),
        30,
        {
            1,
            30,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpFadeRamperDRChannelToRamperMap, 30,
        Model_TranslationEngine64_B.ChannelToRamperMap.Size,
        Model_TranslationEngine64_B.ChannelToRamperMap.Value, 1,
        PreAmpFadeRamperDRChannelToRamperMap_Dependencies
    },

    {                                  /* '<S1092>/TuneVarCutoffHz' */
        "PreAmpFadeRamperDRCutoffHz", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpFadeRamperDRCutoffHz, 1,
        Model_TranslationEngine64_B.CutoffHz.Size,
        &Model_TranslationEngine64_B.CutoffHz.Value, 1,
        PreAmpFadeRamperDRCutoffHz_Dependencies
    },

    {                                  /* '<S1099>/TuneVarChannelRamperMap' */
        "PreAmpFadeRamperFRChannelToRamperMap", 0, TSS_DOUBLE, 0, sizeof(real_T),
        22,
        {
            1,
            22,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpFadeRamperFRChannelToRamperMap, 22,
        Model_TranslationEngine64_B.ChannelToRamperMap_g.Size,
        Model_TranslationEngine64_B.ChannelToRamperMap_g.Value, 1,
        PreAmpFadeRamperFRChannelToRamperMap_Dependencies
    },

    {                                  /* '<S1099>/TuneVarCutoffHz' */
        "PreAmpFadeRamperFRCutoffHz", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpFadeRamperFRCutoffHz, 1,
        Model_TranslationEngine64_B.CutoffHz_m.Size,
        &Model_TranslationEngine64_B.CutoffHz_m.Value, 1,
        PreAmpFadeRamperFRCutoffHz_Dependencies
    },

    {                                  /* '<S1107>/Tune Variable' */
        "PreAmpMuteControlRampTime", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpMuteControlRampTime, 1,
        Model_TranslationEngine64_B.RampTime_bq.Size,
        &Model_TranslationEngine64_B.RampTime_bq.Value, 1,
        PreAmpMuteControlRampTime_Dependencies
    },

    {                                  /* '<S1112>/TuneVarChannelRamperMap' */
        "PreAmpSleepingBeautyDRChannelToRamperMap", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 30,
        {
            1,
            30,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpSleepingBeautyDRChannelToRamperMap, 30,
        Model_TranslationEngine64_B.ChannelToRamperMap_f.Size,
        Model_TranslationEngine64_B.ChannelToRamperMap_f.Value, 1,
        PreAmpSleepingBeautyDRChannelToRamperMap_Dependencies
    },

    {                                  /* '<S1114>/Tune Variable' */
        "PreAmpSleepingBeautyDROffset", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpSleepingBeautyDROffset, 1,
        Model_TranslationEngine64_B.Offset.Size,
        &Model_TranslationEngine64_B.Offset.Value, 1,
        PreAmpSleepingBeautyDROffset_Dependencies
    },

    {                                  /* '<S1115>/Tune Variable' */
        "PreAmpSleepingBeautyDRRampTime", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpSleepingBeautyDRRampTime, 1,
        Model_TranslationEngine64_B.RampTime_k.Size,
        &Model_TranslationEngine64_B.RampTime_k.Value, 1,
        PreAmpSleepingBeautyDRRampTime_Dependencies
    },

    {                                  /* '<S1116>/Tune Variable' */
        "PreAmpSleepingBeautyDRMutesBass", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpSleepingBeautyDRMutesBass, 1,
        Model_TranslationEngine64_B.MutesBass.Size,
        &Model_TranslationEngine64_B.MutesBass.Value, 1,
        PreAmpSleepingBeautyDRMutesBass_Dependencies
    },

    {                                  /* '<S1117>/Tune Variable' */
        "PreAmpSleepingBeautyDRTaperGainTable", 0, TSS_DOUBLE, 0, sizeof(real_T),
        60,
        {
            30,
            2,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpSleepingBeautyDRTaperGainTable, 30,
        Model_TranslationEngine64_B.TaperGainTable.Size,
        Model_TranslationEngine64_B.TaperGainTable.Value, 1,
        PreAmpSleepingBeautyDRTaperGainTable_Dependencies
    },

    {                                  /* '<S1135>/TuneVarChannelRamperMap' */
        "PreAmpSleepingBeautyFRChannelToRamperMap", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 22,
        {
            1,
            22,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpSleepingBeautyFRChannelToRamperMap, 22,
        Model_TranslationEngine64_B.ChannelToRamperMap_m.Size,
        Model_TranslationEngine64_B.ChannelToRamperMap_m.Value, 1,
        PreAmpSleepingBeautyFRChannelToRamperMap_Dependencies
    },

    {                                  /* '<S1137>/Tune Variable' */
        "PreAmpSleepingBeautyFROffset", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpSleepingBeautyFROffset, 1,
        Model_TranslationEngine64_B.Offset_l.Size,
        &Model_TranslationEngine64_B.Offset_l.Value, 1,
        PreAmpSleepingBeautyFROffset_Dependencies
    },

    {                                  /* '<S1138>/Tune Variable' */
        "PreAmpSleepingBeautyFRRampTime", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpSleepingBeautyFRRampTime, 1,
        Model_TranslationEngine64_B.RampTime_e.Size,
        &Model_TranslationEngine64_B.RampTime_e.Value, 1,
        PreAmpSleepingBeautyFRRampTime_Dependencies
    },

    {                                  /* '<S1139>/Tune Variable' */
        "PreAmpSleepingBeautyFRMutesBass", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpSleepingBeautyFRMutesBass, 1,
        Model_TranslationEngine64_B.MutesBass_h.Size,
        &Model_TranslationEngine64_B.MutesBass_h.Value, 1,
        PreAmpSleepingBeautyFRMutesBass_Dependencies
    },

    {                                  /* '<S1140>/Tune Variable' */
        "PreAmpSleepingBeautyFRTaperGainTable", 0, TSS_DOUBLE, 0, sizeof(real_T),
        60,
        {
            30,
            2,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpSleepingBeautyFRTaperGainTable, 30,
        Model_TranslationEngine64_B.TaperGainTable_h.Size,
        Model_TranslationEngine64_B.TaperGainTable_h.Value, 1,
        PreAmpSleepingBeautyFRTaperGainTable_Dependencies
    },

    {                                  /* '<S22>/Tune Variable' */
        "PreAmpAudiopilotTwoDowngrade", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotTwoDowngrade, 1,
        Model_TranslationEngine64_B.TwoDowngrade.Size,
        &Model_TranslationEngine64_B.TwoDowngrade.Value, 1,
        PreAmpAudiopilotTwoDowngrade_Dependencies
    },

    {                                  /* '<S28>/Tune Variable' */
        "PreAmpAudiopilotHvacTable", 0, TSS_SINGLE, 0, sizeof(real32_T), 32,
        {
            16,
            2,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotHvacTable, 32,
        Model_TranslationEngine64_B.HvacTable.Size,
        Model_TranslationEngine64_B.HvacTable.Value, 1,
        PreAmpAudiopilotHvacTable_Dependencies
    },

    {                                  /* '<S33>/Tune Variable' */
        "PreAmpAudiopilotAntiZipperRampFreqHz", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotAntiZipperRampFreqHz, 1,
        Model_TranslationEngine64_B.AntiZipperRampFreqHz.Size,
        &Model_TranslationEngine64_B.AntiZipperRampFreqHz.Value, 1,
        PreAmpAudiopilotAntiZipperRampFreqHz_Dependencies
    },

    {                                  /* '<S34>/Tune Variable' */
        "PreAmpAudiopilotBassBpfCenterFreqHz", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotBassBpfCenterFreqHz, 1,
        Model_TranslationEngine64_B.BassBpfCenterFreqHz.Size,
        &Model_TranslationEngine64_B.BassBpfCenterFreqHz.Value, 1,
        PreAmpAudiopilotBassBpfCenterFreqHz_Dependencies
    },

    {                                  /* '<S34>/Tune Variable1' */
        "PreAmpAudiopilotBassBpfQ", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotBassBpfQ, 1,
        Model_TranslationEngine64_B.BassBpfQ.Size,
        &Model_TranslationEngine64_B.BassBpfQ.Value, 1,
        PreAmpAudiopilotBassBpfQ_Dependencies
    },

    {                                  /* '<S35>/Tune Variable' */
        "PreAmpAudiopilotMidrangeLpfCutoffFreqHz", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotMidrangeLpfCutoffFreqHz, 1,
        Model_TranslationEngine64_B.MidrangeLpfCutoffFreqHz.Size,
        &Model_TranslationEngine64_B.MidrangeLpfCutoffFreqHz.Value, 1,
        PreAmpAudiopilotMidrangeLpfCutoffFreqHz_Dependencies
    },

    {                                  /* '<S46>/Tune Variable' */
        "PreAmpAudiopilotMidrangeLpfAlignDelaySamples", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotMidrangeLpfAlignDelaySamples, 1,
        Model_TranslationEngine64_B.MidrangeLpfAlignDelaySamples.Size,
        &Model_TranslationEngine64_B.MidrangeLpfAlignDelaySamples.Value, 1,
        PreAmpAudiopilotMidrangeLpfAlignDelaySamples_Dependencies
    },

    {                                  /* '<S53>/AudiopilotOn' */
        "PreAmpAudiopilotAudiopilotOn", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotAudiopilotOn, 1,
        Model_TranslationEngine64_B.AudiopilotOn.Size,
        &Model_TranslationEngine64_B.AudiopilotOn.Value, 6,
        PreAmpAudiopilotAudiopilotOn_Dependencies
    },

    {                                  /* '<S53>/BassSlope0' */
        "PreAmpAudiopilotBassSlope0Dbperdb", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotBassSlope0Dbperdb, 1,
        Model_TranslationEngine64_B.BassSlope0Dbperdb.Size,
        &Model_TranslationEngine64_B.BassSlope0Dbperdb.Value, 1,
        PreAmpAudiopilotBassSlope0Dbperdb_Dependencies
    },

    {                                  /* '<S53>/MidrangeSlope0' */
        "PreAmpAudiopilotMidrangeSlope0DbPerDb", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotMidrangeSlope0DbPerDb, 1,
        Model_TranslationEngine64_B.MidrangeSlope0DbPerDb.Size,
        &Model_TranslationEngine64_B.MidrangeSlope0DbPerDb.Value, 1,
        PreAmpAudiopilotMidrangeSlope0DbPerDb_Dependencies
    },

    {                                  /* '<S53>/TrebleSlope0' */
        "PreAmpAudiopilotTrebleSlope0DbPerDb", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotTrebleSlope0DbPerDb, 1,
        Model_TranslationEngine64_B.TrebleSlope0DbPerDb.Size,
        &Model_TranslationEngine64_B.TrebleSlope0DbPerDb.Value, 1,
        PreAmpAudiopilotTrebleSlope0DbPerDb_Dependencies
    },

    {                                  /* '<S53>/BassSlope1' */
        "PreAmpAudiopilotBassSlope1DbPerDb", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotBassSlope1DbPerDb, 1,
        Model_TranslationEngine64_B.BassSlope1DbPerDb.Size,
        &Model_TranslationEngine64_B.BassSlope1DbPerDb.Value, 1,
        PreAmpAudiopilotBassSlope1DbPerDb_Dependencies
    },

    {                                  /* '<S53>/MidrangeSlope1' */
        "PreAmpAudiopilotMidrangeSlope1DbPerDb", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotMidrangeSlope1DbPerDb, 1,
        Model_TranslationEngine64_B.MidrangeSlope1DbPerDb.Size,
        &Model_TranslationEngine64_B.MidrangeSlope1DbPerDb.Value, 1,
        PreAmpAudiopilotMidrangeSlope1DbPerDb_Dependencies
    },

    {                                  /* '<S53>/TrebleSlope1' */
        "PreAmpAudiopilotTrebleSlope1DbPerDb", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotTrebleSlope1DbPerDb, 1,
        Model_TranslationEngine64_B.TrebleSlope1DbPerDb.Size,
        &Model_TranslationEngine64_B.TrebleSlope1DbPerDb.Value, 1,
        PreAmpAudiopilotTrebleSlope1DbPerDb_Dependencies
    },

    {                                  /* '<S54>/Tune Variable' */
        "PreAmpAudiopilotBassThresh0Db", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotBassThresh0Db, 1,
        Model_TranslationEngine64_B.BassThresh0Db.Size,
        &Model_TranslationEngine64_B.BassThresh0Db.Value, 1,
        PreAmpAudiopilotBassThresh0Db_Dependencies
    },

    {                                  /* '<S55>/Tune Variable' */
        "PreAmpAudiopilotBassThresh1Db", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotBassThresh1Db, 1,
        Model_TranslationEngine64_B.BassThresh1Db.Size,
        &Model_TranslationEngine64_B.BassThresh1Db.Value, 1,
        PreAmpAudiopilotBassThresh1Db_Dependencies
    },

    {                                  /* '<S56>/Tune Variable' */
        "PreAmpAudiopilotHfNoiseHighBoundDbspl", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotHfNoiseHighBoundDbspl, 1,
        Model_TranslationEngine64_B.HfNoiseHighBoundDbspl.Size,
        &Model_TranslationEngine64_B.HfNoiseHighBoundDbspl.Value, 1,
        PreAmpAudiopilotHfNoiseHighBoundDbspl_Dependencies
    },

    {                                  /* '<S57>/Tune Variable' */
        "PreAmpAudiopilotHfNoiseLowBoundDbspl", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotHfNoiseLowBoundDbspl, 1,
        Model_TranslationEngine64_B.HfNoiseLowBoundDbspl.Size,
        &Model_TranslationEngine64_B.HfNoiseLowBoundDbspl.Value, 1,
        PreAmpAudiopilotHfNoiseLowBoundDbspl_Dependencies
    },

    {                                  /* '<S58>/Tune Variable' */
        "PreAmpAudiopilotLfNoiseHighBoundDbspl", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotLfNoiseHighBoundDbspl, 1,
        Model_TranslationEngine64_B.LfNoiseHighBoundDbspl.Size,
        &Model_TranslationEngine64_B.LfNoiseHighBoundDbspl.Value, 1,
        PreAmpAudiopilotLfNoiseHighBoundDbspl_Dependencies
    },

    {                                  /* '<S59>/Tune Variable' */
        "PreAmpAudiopilotLfNoiseLowBoundDbspl", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotLfNoiseLowBoundDbspl, 1,
        Model_TranslationEngine64_B.LfNoiseLowBoundDbspl.Size,
        &Model_TranslationEngine64_B.LfNoiseLowBoundDbspl.Value, 1,
        PreAmpAudiopilotLfNoiseLowBoundDbspl_Dependencies
    },

    {                                  /* '<S60>/Tune Variable' */
        "PreAmpAudiopilotMidrangeThresh0Db", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotMidrangeThresh0Db, 1,
        Model_TranslationEngine64_B.MidrangeThresh0Db.Size,
        &Model_TranslationEngine64_B.MidrangeThresh0Db.Value, 1,
        PreAmpAudiopilotMidrangeThresh0Db_Dependencies
    },

    {                                  /* '<S61>/Tune Variable' */
        "PreAmpAudiopilotMidrangeThresh1Db", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotMidrangeThresh1Db, 1,
        Model_TranslationEngine64_B.MidrangeThresh1Db.Size,
        &Model_TranslationEngine64_B.MidrangeThresh1Db.Value, 1,
        PreAmpAudiopilotMidrangeThresh1Db_Dependencies
    },

    {                                  /* '<S62>/Tune Variable' */
        "PreAmpAudiopilotTrebleThresh0Db", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotTrebleThresh0Db, 1,
        Model_TranslationEngine64_B.TrebleThresh0Db.Size,
        &Model_TranslationEngine64_B.TrebleThresh0Db.Value, 1,
        PreAmpAudiopilotTrebleThresh0Db_Dependencies
    },

    {                                  /* '<S63>/Tune Variable' */
        "PreAmpAudiopilotTrebleThresh1Db", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotTrebleThresh1Db, 1,
        Model_TranslationEngine64_B.TrebleThresh1Db.Size,
        &Model_TranslationEngine64_B.TrebleThresh1Db.Value, 1,
        PreAmpAudiopilotTrebleThresh1Db_Dependencies
    },

    {                                  /* '<S122>/Tune Variable' */
        "PreAmpAudiopilotBassDownwardThreshDbspl", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotBassDownwardThreshDbspl, 1,
        Model_TranslationEngine64_B.BassDownwardThreshDbspl.Size,
        &Model_TranslationEngine64_B.BassDownwardThreshDbspl.Value, 1,
        PreAmpAudiopilotBassDownwardThreshDbspl_Dependencies
    },

    {                                  /* '<S123>/Tune Variable' */
        "PreAmpAudiopilotBassMaxAudiopilotBoostDb", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotBassMaxAudiopilotBoostDb, 1,
        Model_TranslationEngine64_B.BassMaxAudiopilotBoostDb.Size,
        &Model_TranslationEngine64_B.BassMaxAudiopilotBoostDb.Value, 1,
        PreAmpAudiopilotBassMaxAudiopilotBoostDb_Dependencies
    },

    {                                  /* '<S124>/Tune Variable' */
        "PreAmpAudiopilotBassMaxDyneqBoostDb", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotBassMaxDyneqBoostDb, 1,
        Model_TranslationEngine64_B.BassMaxDyneqBoostDb.Size,
        &Model_TranslationEngine64_B.BassMaxDyneqBoostDb.Value, 1,
        PreAmpAudiopilotBassMaxDyneqBoostDb_Dependencies
    },

    {                                  /* '<S125>/Tune Variable' */
        "PreAmpAudiopilotBassMaxTotalBoostDb", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotBassMaxTotalBoostDb, 1,
        Model_TranslationEngine64_B.BassMaxTotalBoostDb.Size,
        &Model_TranslationEngine64_B.BassMaxTotalBoostDb.Value, 1,
        PreAmpAudiopilotBassMaxTotalBoostDb_Dependencies
    },

    {                                  /* '<S126>/DownwardExpansionOn' */
        "PreAmpAudiopilotDownwardExpansionOn", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotDownwardExpansionOn, 1,
        Model_TranslationEngine64_B.DownwardExpansionOn.Size,
        &Model_TranslationEngine64_B.DownwardExpansionOn.Value, 3,
        PreAmpAudiopilotDownwardExpansionOn_Dependencies
    },

    {                                  /* '<S126>/MidrangeDownwardSlope' */
        "PreAmpAudiopilotMidrangeDownwardSlopeDbPerDb", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotMidrangeDownwardSlopeDbPerDb, 1,
        Model_TranslationEngine64_B.MidrangeDownwardSlopeDbPerDb.Size,
        &Model_TranslationEngine64_B.MidrangeDownwardSlopeDbPerDb.Value, 1,
        PreAmpAudiopilotMidrangeDownwardSlopeDbPerDb_Dependencies
    },

    {                                  /* '<S126>/BassDownwardSlope' */
        "PreAmpAudiopilotBassDownwardSlopeDbPerDb", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotBassDownwardSlopeDbPerDb, 1,
        Model_TranslationEngine64_B.BassDownwardSlopeDbPerDb.Size,
        &Model_TranslationEngine64_B.BassDownwardSlopeDbPerDb.Value, 1,
        PreAmpAudiopilotBassDownwardSlopeDbPerDb_Dependencies
    },

    {                                  /* '<S126>/TrebleDownwardSlope' */
        "PreAmpAudiopilotTrebleDownwardSlopeDbPerDb", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotTrebleDownwardSlopeDbPerDb, 1,
        Model_TranslationEngine64_B.TrebleDownwardSlopeDbPerDb.Size,
        &Model_TranslationEngine64_B.TrebleDownwardSlopeDbPerDb.Value, 1,
        PreAmpAudiopilotTrebleDownwardSlopeDbPerDb_Dependencies
    },

    {                                  /* '<S127>/Tune Variable' */
        "PreAmpAudiopilotDyneqBassThreshDbspl", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotDyneqBassThreshDbspl, 1,
        Model_TranslationEngine64_B.DyneqBassThreshDbspl.Size,
        &Model_TranslationEngine64_B.DyneqBassThreshDbspl.Value, 1,
        PreAmpAudiopilotDyneqBassThreshDbspl_Dependencies
    },

    {                                  /* '<S128>/DyneqBassSlope' */
        "PreAmpAudiopilotDyneqBassSlopeDbPerDb", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotDyneqBassSlopeDbPerDb, 1,
        Model_TranslationEngine64_B.DyneqBassSlopeDbPerDb.Size,
        &Model_TranslationEngine64_B.DyneqBassSlopeDbPerDb.Value, 1,
        PreAmpAudiopilotDyneqBassSlopeDbPerDb_Dependencies
    },

    {                                  /* '<S128>/DyneqOn' */
        "PreAmpAudiopilotDyneqOn", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotDyneqOn, 1,
        Model_TranslationEngine64_B.DyneqOn.Size,
        &Model_TranslationEngine64_B.DyneqOn.Value, 1,
        PreAmpAudiopilotDyneqOn_Dependencies
    },

    {                                  /* '<S166>/Tune Variable' */
        "PreAmpAudiopilotMinSignalLevelDbspl", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotMinSignalLevelDbspl, 1,
        Model_TranslationEngine64_B.MinSignalLevelDbspl.Size,
        &Model_TranslationEngine64_B.MinSignalLevelDbspl.Value, 1,
        PreAmpAudiopilotMinSignalLevelDbspl_Dependencies
    },

    {                                  /* '<S130>/Tune Variable' */
        "PreAmpAudiopilotMidrangeDownwardThreshDbspl", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotMidrangeDownwardThreshDbspl, 1,
        Model_TranslationEngine64_B.MidrangeDownwardThreshDbspl.Size,
        &Model_TranslationEngine64_B.MidrangeDownwardThreshDbspl.Value, 1,
        PreAmpAudiopilotMidrangeDownwardThreshDbspl_Dependencies
    },

    {                                  /* '<S131>/Tune Variable' */
        "PreAmpAudiopilotMidrangeMaxTotalBoostDb", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotMidrangeMaxTotalBoostDb, 1,
        Model_TranslationEngine64_B.MidrangeMaxTotalBoostDb.Size,
        &Model_TranslationEngine64_B.MidrangeMaxTotalBoostDb.Value, 1,
        PreAmpAudiopilotMidrangeMaxTotalBoostDb_Dependencies
    },

    {                                  /* '<S132>/Tune Variable' */
        "PreAmpAudiopilotTrebleDownwardThreshDbspl", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotTrebleDownwardThreshDbspl, 1,
        Model_TranslationEngine64_B.TrebleDownwardThreshDbspl.Size,
        &Model_TranslationEngine64_B.TrebleDownwardThreshDbspl.Value, 1,
        PreAmpAudiopilotTrebleDownwardThreshDbspl_Dependencies
    },

    {                                  /* '<S133>/Tune Variable' */
        "PreAmpAudiopilotTrebleMaxTotalBoostDb", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotTrebleMaxTotalBoostDb, 1,
        Model_TranslationEngine64_B.TrebleMaxTotalBoostDb.Size,
        &Model_TranslationEngine64_B.TrebleMaxTotalBoostDb.Value, 1,
        PreAmpAudiopilotTrebleMaxTotalBoostDb_Dependencies
    },

    {                                  /* '<S187>/Tune Variable' */
        "PreAmpAudiopilotEnableRampTauS", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotEnableRampTauS, 1,
        Model_TranslationEngine64_B.EnableRampTauS.Size,
        &Model_TranslationEngine64_B.EnableRampTauS.Value, 1,
        PreAmpAudiopilotEnableRampTauS_Dependencies
    },

    {                                  /* '<S199>/Tune Variable' */
        "PreAmpAudiopilotHfNoiseRefPowerMinDb", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotHfNoiseRefPowerMinDb, 1,
        Model_TranslationEngine64_B.RefPowerMinDb.Size,
        &Model_TranslationEngine64_B.RefPowerMinDb.Value, 1,
        PreAmpAudiopilotHfNoiseRefPowerMinDb_Dependencies
    },

    {                                  /* '<S210>/Tune Variable' */
        "PreAmpAudiopilotHfNoiseImpulseRejectionMinstatAlphaFactor", 0,
        TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0,
        DefValue_PreAmpAudiopilotHfNoiseImpulseRejectionMinstatAlphaFactor, 1,
        Model_TranslationEngine64_B.MinstatAlphaFactor.Size,
        &Model_TranslationEngine64_B.MinstatAlphaFactor.Value, 1,
        PreAmpAudiopilotHfNoiseImpulseRejectionMinstatAlphaFactor_Dependencies
    },

    {                                  /* '<S211>/Tune Variable' */
        "PreAmpAudiopilotHfNoiseImpulseRejectionMinstatAlphaMin", 0, TSS_SINGLE,
        0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotHfNoiseImpulseRejectionMinstatAlphaMin,
        1, Model_TranslationEngine64_B.MinstatAlphaMin.Size,
        &Model_TranslationEngine64_B.MinstatAlphaMin.Value, 1,
        PreAmpAudiopilotHfNoiseImpulseRejectionMinstatAlphaMin_Dependencies
    },

    {                                  /* '<S220>/Tune Variable' */
        "PreAmpAudiopilotHfNoiseImpulseRejectionMinstatBeta", 0, TSS_SINGLE, 0,
        sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotHfNoiseImpulseRejectionMinstatBeta, 1,
        Model_TranslationEngine64_B.MinstatBeta.Size,
        &Model_TranslationEngine64_B.MinstatBeta.Value, 1,
        PreAmpAudiopilotHfNoiseImpulseRejectionMinstatBeta_Dependencies
    },

    {                                  /* '<S221>/Tune Variable' */
        "PreAmpAudiopilotHfNoiseImpulseRejectionMinstatMin", 0, TSS_SINGLE, 0,
        sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotHfNoiseImpulseRejectionMinstatMin, 1,
        Model_TranslationEngine64_B.MinstatMin.Size,
        &Model_TranslationEngine64_B.MinstatMin.Value, 1,
        PreAmpAudiopilotHfNoiseImpulseRejectionMinstatMin_Dependencies
    },

    {                                  /* '<S230>/Tune Variable' */
        "PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessHighIndex", 0,
        TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0,
        DefValue_PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessHighIndex, 1,
        Model_TranslationEngine64_B.FlatnessHighIndex.Size,
        &Model_TranslationEngine64_B.FlatnessHighIndex.Value, 1,
        PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessHighIndex_Dependencies
    },

    {                                  /* '<S231>/Tune Variable' */
        "PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessLowIndex", 0, TSS_SINGLE,
        0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0,
        DefValue_PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessLowIndex, 1,
        Model_TranslationEngine64_B.FlatnessLowIndex.Size,
        &Model_TranslationEngine64_B.FlatnessLowIndex.Value, 1,
        PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessLowIndex_Dependencies
    },

    {                                  /* '<S232>/Tune Variable' */
        "PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessThresh", 0, TSS_SINGLE,
        0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessThresh,
        1, Model_TranslationEngine64_B.FlatnessThresh.Size,
        &Model_TranslationEngine64_B.FlatnessThresh.Value, 1,
        PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessThresh_Dependencies
    },

    {                                  /* '<S233>/Tune Variable' */
        "PreAmpAudiopilotHfNoiseImpulseRejectionMinSearchCoef", 0, TSS_SINGLE, 0,
        sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotHfNoiseImpulseRejectionMinSearchCoef,
        1, Model_TranslationEngine64_B.MinSearchCoef.Size,
        &Model_TranslationEngine64_B.MinSearchCoef.Value, 1,
        PreAmpAudiopilotHfNoiseImpulseRejectionMinSearchCoef_Dependencies
    },

    {                                  /* '<S234>/Tune Variable' */
        "PreAmpAudiopilotHfNoiseImpulseRejectionMinSearchMinGain", 0, TSS_SINGLE,
        0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0,
        DefValue_PreAmpAudiopilotHfNoiseImpulseRejectionMinSearchMinGain, 1,
        Model_TranslationEngine64_B.MinSearchMinGain.Size,
        &Model_TranslationEngine64_B.MinSearchMinGain.Value, 1,
        PreAmpAudiopilotHfNoiseImpulseRejectionMinSearchMinGain_Dependencies
    },

    {                                  /* '<S235>/Tune Variable' */
        "PreAmpAudiopilotHfNoiseImpulseRejectionSubWinTimeS", 0, TSS_SINGLE, 0,
        sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotHfNoiseImpulseRejectionSubWinTimeS, 1,
        Model_TranslationEngine64_B.SubWinTimeS.Size,
        &Model_TranslationEngine64_B.SubWinTimeS.Value, 1,
        PreAmpAudiopilotHfNoiseImpulseRejectionSubWinTimeS_Dependencies
    },

    {                                  /* '<S259>/Tune Variable' */
        "PreAmpAudiopilotHfNoiseImpulseRejectionLevelUpdateCoef", 0, TSS_SINGLE,
        0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotHfNoiseImpulseRejectionLevelUpdateCoef,
        1, Model_TranslationEngine64_B.LevelUpdateCoef.Size,
        &Model_TranslationEngine64_B.LevelUpdateCoef.Value, 1,
        PreAmpAudiopilotHfNoiseImpulseRejectionLevelUpdateCoef_Dependencies
    },

    {                                  /* '<S264>/Tune Variable' */
        "PreAmpAudiopilotHfNoiseSlewAttackDbPerS", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotHfNoiseSlewAttackDbPerS, 1,
        Model_TranslationEngine64_B.AttackDbPerS.Size,
        &Model_TranslationEngine64_B.AttackDbPerS.Value, 1,
        PreAmpAudiopilotHfNoiseSlewAttackDbPerS_Dependencies
    },

    {                                  /* '<S265>/Tune Variable' */
        "PreAmpAudiopilotHfNoiseSlewDecayDbPerS", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotHfNoiseSlewDecayDbPerS, 1,
        Model_TranslationEngine64_B.DecayDbPerS.Size,
        &Model_TranslationEngine64_B.DecayDbPerS.Value, 1,
        PreAmpAudiopilotHfNoiseSlewDecayDbPerS_Dependencies
    },

    {                                  /* '<S266>/Tune Variable' */
        "PreAmpAudiopilotHfNoiseSlewThresholdDb", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotHfNoiseSlewThresholdDb, 1,
        Model_TranslationEngine64_B.ThresholdDb.Size,
        &Model_TranslationEngine64_B.ThresholdDb.Value, 1,
        PreAmpAudiopilotHfNoiseSlewThresholdDb_Dependencies
    },

    {                                  /* '<S205>/Tune Variable' */
        "PreAmpAudiopilotHfNoiseOffsetDb", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotHfNoiseOffsetDb, 1,
        Model_TranslationEngine64_B.OffsetDb.Size,
        &Model_TranslationEngine64_B.OffsetDb.Value, 1,
        PreAmpAudiopilotHfNoiseOffsetDb_Dependencies
    },

    {                                  /* '<S284>/Tune Variable2' */
        "PreAmpAudiopilotHfNoisePreprocessAntiAliassosCoefficients", 0,
        TSS_SINGLE, 0, sizeof(real32_T), 60,
        {
            10,
            6,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0,
        DefValue_PreAmpAudiopilotHfNoisePreprocessAntiAliassosCoefficients, 60,
        Model_TranslationEngine64_B.sosCoefficients_b0.Size,
        Model_TranslationEngine64_B.sosCoefficients_b0.Value, 1,
        PreAmpAudiopilotHfNoisePreprocessAntiAliassosCoefficients_Dependencies
    },

    {                                  /* '<S284>/Tune Variable1' */
        "PreAmpAudiopilotHfNoisePreprocessAntiAliasnumStages", 0, TSS_SINGLE, 0,
        sizeof(real32_T), 5,
        {
            5,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotHfNoisePreprocessAntiAliasnumStages, 5,
        Model_TranslationEngine64_B.numStages_g.Size,
        Model_TranslationEngine64_B.numStages_g.Value, 1,
        PreAmpAudiopilotHfNoisePreprocessAntiAliasnumStages_Dependencies
    },

    {                                  /* '<S289>/Tune Variable2' */
        "PreAmpAudiopilotHfNoisePreprocessBandpassLowpasssosCoefficients", 0,
        TSS_SINGLE, 0, sizeof(real32_T), 108,
        {
            18,
            6,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0,
        DefValue_PreAmpAudiopilotHfNoisePreprocessBandpassLowpasssosCoefficients,
        108, Model_TranslationEngine64_B.sosCoefficients_jq.Size,
        Model_TranslationEngine64_B.sosCoefficients_jq.Value, 1,
        PreAmpAudiopilotHfNoisePreprocessBandpassLowpasssosCoefficients_Dependencies
    },

    {                                  /* '<S289>/Tune Variable1' */
        "PreAmpAudiopilotHfNoisePreprocessBandpassLowpassnumStages", 0,
        TSS_SINGLE, 0, sizeof(real32_T), 5,
        {
            5,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0,
        DefValue_PreAmpAudiopilotHfNoisePreprocessBandpassLowpassnumStages, 5,
        Model_TranslationEngine64_B.numStages_o.Size,
        Model_TranslationEngine64_B.numStages_o.Value, 1,
        PreAmpAudiopilotHfNoisePreprocessBandpassLowpassnumStages_Dependencies
    },

    {                                  /* '<S293>/Tune Variable' */
        "PreAmpAudiopilotHfNoiseRefLatencyMs", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotHfNoiseRefLatencyMs, 1,
        Model_TranslationEngine64_B.RefLatencyMs.Size,
        &Model_TranslationEngine64_B.RefLatencyMs.Value, 1,
        PreAmpAudiopilotHfNoiseRefLatencyMs_Dependencies
    },

    {                                  /* '<S297>/Tune Variable' */
        "PreAmpAudiopilotLfNoiseEnergyLpfTauS", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotLfNoiseEnergyLpfTauS, 1,
        Model_TranslationEngine64_B.EnergyLpfTauS.Size,
        &Model_TranslationEngine64_B.EnergyLpfTauS.Value, 1,
        PreAmpAudiopilotLfNoiseEnergyLpfTauS_Dependencies
    },

    {                                  /* '<S307>/Tune Variable' */
        "PreAmpAudiopilotLfNoiseImpulseRejectionGamma0TauS", 0, TSS_SINGLE, 0,
        sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotLfNoiseImpulseRejectionGamma0TauS, 1,
        Model_TranslationEngine64_B.Gamma0TauS.Size,
        &Model_TranslationEngine64_B.Gamma0TauS.Value, 1,
        PreAmpAudiopilotLfNoiseImpulseRejectionGamma0TauS_Dependencies
    },

    {                                  /* '<S308>/Tune Variable' */
        "PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceFiltTauS", 0,
        TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0,
        DefValue_PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceFiltTauS,
        1, Model_TranslationEngine64_B.ImpulseVarianceFiltTauS.Size,
        &Model_TranslationEngine64_B.ImpulseVarianceFiltTauS.Value, 1,
        PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceFiltTauS_Dependencies
    },

    {                                  /* '<S309>/Tune Variable' */
        "PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceScale", 0,
        TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0,
        DefValue_PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceScale, 1,
        Model_TranslationEngine64_B.ImpulseVarianceScale.Size,
        &Model_TranslationEngine64_B.ImpulseVarianceScale.Value, 1,
        PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceScale_Dependencies
    },

    {                                  /* '<S310>/Tune Variable' */
        "PreAmpAudiopilotLfNoiseImpulseRejectionMusicVarianceScale", 0,
        TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0,
        DefValue_PreAmpAudiopilotLfNoiseImpulseRejectionMusicVarianceScale, 1,
        Model_TranslationEngine64_B.MusicVarianceScale.Size,
        &Model_TranslationEngine64_B.MusicVarianceScale.Value, 1,
        PreAmpAudiopilotLfNoiseImpulseRejectionMusicVarianceScale_Dependencies
    },

    {                                  /* '<S311>/Tune Variable' */
        "PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVarianceScale", 0,
        TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0,
        DefValue_PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVarianceScale, 1,
        Model_TranslationEngine64_B.NoiseVarianceScale.Size,
        &Model_TranslationEngine64_B.NoiseVarianceScale.Value, 1,
        PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVarianceScale_Dependencies
    },

    {                                  /* '<S312>/Tune Variable' */
        "PreAmpAudiopilotLfNoiseImpulseRejectionOutputMin", 0, TSS_SINGLE, 0,
        sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotLfNoiseImpulseRejectionOutputMin, 1,
        Model_TranslationEngine64_B.OutputMin.Size,
        &Model_TranslationEngine64_B.OutputMin.Value, 1,
        PreAmpAudiopilotLfNoiseImpulseRejectionOutputMin_Dependencies
    },

    {                                  /* '<S338>/Tune Variable2' */
        "PreAmpAudiopilotLfNoiseMicsosCoefficients", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 18,
        {
            3,
            6,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotLfNoiseMicsosCoefficients, 18,
        Model_TranslationEngine64_B.sosCoefficients_p.Size,
        Model_TranslationEngine64_B.sosCoefficients_p.Value, 1,
        PreAmpAudiopilotLfNoiseMicsosCoefficients_Dependencies
    },

    {                                  /* '<S338>/Tune Variable1' */
        "PreAmpAudiopilotLfNoiseMicnumStages", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotLfNoiseMicnumStages, 1,
        Model_TranslationEngine64_B.numStages_ns.Size,
        &Model_TranslationEngine64_B.numStages_ns.Value, 1,
        PreAmpAudiopilotLfNoiseMicnumStages_Dependencies
    },

    {                                  /* '<S343>/Tune Variable2' */
        "PreAmpAudiopilotLfNoiseRefsosCoefficients", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 18,
        {
            3,
            6,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotLfNoiseRefsosCoefficients, 18,
        Model_TranslationEngine64_B.sosCoefficients_a.Size,
        Model_TranslationEngine64_B.sosCoefficients_a.Value, 1,
        PreAmpAudiopilotLfNoiseRefsosCoefficients_Dependencies
    },

    {                                  /* '<S343>/Tune Variable1' */
        "PreAmpAudiopilotLfNoiseRefnumStages", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotLfNoiseRefnumStages, 1,
        Model_TranslationEngine64_B.numStages_ea.Size,
        &Model_TranslationEngine64_B.numStages_ea.Value, 1,
        PreAmpAudiopilotLfNoiseRefnumStages_Dependencies
    },

    {                                  /* '<S300>/Tune Variable' */
        "PreAmpAudiopilotLfNoiseOffsetDb", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotLfNoiseOffsetDb, 1,
        Model_TranslationEngine64_B.OffsetDb_o.Size,
        &Model_TranslationEngine64_B.OffsetDb_o.Value, 1,
        PreAmpAudiopilotLfNoiseOffsetDb_Dependencies
    },

    {                                  /* '<S351>/Tune Variable' */
        "PreAmpAudiopilotLfNoiseRefLatencyMs", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotLfNoiseRefLatencyMs, 1,
        Model_TranslationEngine64_B.RefLatencyMs_l.Size,
        &Model_TranslationEngine64_B.RefLatencyMs_l.Value, 1,
        PreAmpAudiopilotLfNoiseRefLatencyMs_Dependencies
    },

    {                                  /* '<S357>/Tune Variable' */
        "PreAmpAudiopilotLfNoiseSlewAttackDbPerS", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotLfNoiseSlewAttackDbPerS, 1,
        Model_TranslationEngine64_B.AttackDbPerS_i.Size,
        &Model_TranslationEngine64_B.AttackDbPerS_i.Value, 1,
        PreAmpAudiopilotLfNoiseSlewAttackDbPerS_Dependencies
    },

    {                                  /* '<S358>/Tune Variable' */
        "PreAmpAudiopilotLfNoiseSlewDecayDbPerS", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotLfNoiseSlewDecayDbPerS, 1,
        Model_TranslationEngine64_B.DecayDbPerS_p.Size,
        &Model_TranslationEngine64_B.DecayDbPerS_p.Value, 1,
        PreAmpAudiopilotLfNoiseSlewDecayDbPerS_Dependencies
    },

    {                                  /* '<S359>/Tune Variable' */
        "PreAmpAudiopilotLfNoiseSlewSlowDbPerS", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotLfNoiseSlewSlowDbPerS, 1,
        Model_TranslationEngine64_B.SlowDbPerS.Size,
        &Model_TranslationEngine64_B.SlowDbPerS.Value, 1,
        PreAmpAudiopilotLfNoiseSlewSlowDbPerS_Dependencies
    },

    {                                  /* '<S360>/Tune Variable' */
        "PreAmpAudiopilotLfNoiseSlewThresholdDb", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotLfNoiseSlewThresholdDb, 1,
        Model_TranslationEngine64_B.ThresholdDb_j.Size,
        &Model_TranslationEngine64_B.ThresholdDb_j.Value, 1,
        PreAmpAudiopilotLfNoiseSlewThresholdDb_Dependencies
    },

    {                                  /* '<S374>/Tune Variable' */
        "PreAmpAudiopilotLfNoiseSpeedBoundsAxis", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 128,
        {
            128,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotLfNoiseSpeedBoundsAxis, 128,
        Model_TranslationEngine64_B.Axis.Size,
        Model_TranslationEngine64_B.Axis.Value, 1,
        PreAmpAudiopilotLfNoiseSpeedBoundsAxis_Dependencies
    },

    {                                  /* '<S375>/Tune Variable' */
        "PreAmpAudiopilotLfNoiseSpeedBoundsMaxDbspl", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 128,
        {
            128,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotLfNoiseSpeedBoundsMaxDbspl, 128,
        Model_TranslationEngine64_B.MaxDbspl.Size,
        Model_TranslationEngine64_B.MaxDbspl.Value, 1,
        PreAmpAudiopilotLfNoiseSpeedBoundsMaxDbspl_Dependencies
    },

    {                                  /* '<S376>/Tune Variable' */
        "PreAmpAudiopilotLfNoiseSpeedBoundsMindBSPL", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 128,
        {
            128,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotLfNoiseSpeedBoundsMindBSPL, 128,
        Model_TranslationEngine64_B.MindBSPL.Size,
        Model_TranslationEngine64_B.MindBSPL.Value, 1,
        PreAmpAudiopilotLfNoiseSpeedBoundsMindBSPL_Dependencies
    },

    {                                  /* '<S377>/Tune Variable' */
        "PreAmpAudiopilotLfNoiseSpeedBoundsOn", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotLfNoiseSpeedBoundsOn, 1,
        Model_TranslationEngine64_B.On.Size,
        &Model_TranslationEngine64_B.On.Value, 1,
        PreAmpAudiopilotLfNoiseSpeedBoundsOn_Dependencies
    },

    {                                  /* '<S303>/Tune Variable' */
        "PreAmpAudiopilotLfNoiseSysMaxDbspl", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotLfNoiseSysMaxDbspl, 1,
        Model_TranslationEngine64_B.SysMaxDbspl_j.Size,
        &Model_TranslationEngine64_B.SysMaxDbspl_j.Value, 1,
        PreAmpAudiopilotLfNoiseSysMaxDbspl_Dependencies
    },

    {                                  /* '<S403>/Tune Variable' */
        "PreAmpAudiopilotRatioUpdateFlagHoldTimeS", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotRatioUpdateFlagHoldTimeS, 1,
        Model_TranslationEngine64_B.FlagHoldTimeS.Size,
        &Model_TranslationEngine64_B.FlagHoldTimeS.Value, 1,
        PreAmpAudiopilotRatioUpdateFlagHoldTimeS_Dependencies
    },

    {                                  /* '<S404>/Tune Variable' */
        "PreAmpAudiopilotRatioUpdateHfNoiseThreshDbspl", 0, TSS_SINGLE, 0,
        sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotRatioUpdateHfNoiseThreshDbspl, 1,
        Model_TranslationEngine64_B.HfNoiseThreshDbspl.Size,
        &Model_TranslationEngine64_B.HfNoiseThreshDbspl.Value, 1,
        PreAmpAudiopilotRatioUpdateHfNoiseThreshDbspl_Dependencies
    },

    {                                  /* '<S405>/Tune Variable' */
        "PreAmpAudiopilotRatioUpdateLfNoiseThreshDbspl", 0, TSS_SINGLE, 0,
        sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotRatioUpdateLfNoiseThreshDbspl, 1,
        Model_TranslationEngine64_B.LfNoiseThreshDbspl.Size,
        &Model_TranslationEngine64_B.LfNoiseThreshDbspl.Value, 1,
        PreAmpAudiopilotRatioUpdateLfNoiseThreshDbspl_Dependencies
    },

    {                                  /* '<S406>/Tune Variable' */
        "PreAmpAudiopilotRatioUpdateLfNoiseUpdatePeriodS", 0, TSS_SINGLE, 0,
        sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotRatioUpdateLfNoiseUpdatePeriodS, 1,
        Model_TranslationEngine64_B.LfNoiseUpdatePeriodS.Size,
        &Model_TranslationEngine64_B.LfNoiseUpdatePeriodS.Value, 1,
        PreAmpAudiopilotRatioUpdateLfNoiseUpdatePeriodS_Dependencies
    },

    {                                  /* '<S407>/Tune Variable' */
        "PreAmpAudiopilotRatioUpdateLfNoiseUpdateThreshDb", 0, TSS_SINGLE, 0,
        sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotRatioUpdateLfNoiseUpdateThreshDb, 1,
        Model_TranslationEngine64_B.LfNoiseUpdateThreshDb.Size,
        &Model_TranslationEngine64_B.LfNoiseUpdateThreshDb.Value, 1,
        PreAmpAudiopilotRatioUpdateLfNoiseUpdateThreshDb_Dependencies
    },

    {                                  /* '<S408>/Tune Variable' */
        "PreAmpAudiopilotRatioUpdateSpeedUpdateThreshMph", 0, TSS_SINGLE, 0,
        sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotRatioUpdateSpeedUpdateThreshMph, 1,
        Model_TranslationEngine64_B.SpeedUpdateThreshMph.Size,
        &Model_TranslationEngine64_B.SpeedUpdateThreshMph.Value, 1,
        PreAmpAudiopilotRatioUpdateSpeedUpdateThreshMph_Dependencies
    },

    {                                  /* '<S398>/Tune Variable' */
        "PreAmpAudiopilotRatioEnergyLpfTauS", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotRatioEnergyLpfTauS, 1,
        Model_TranslationEngine64_B.EnergyLpfTauS_g.Size,
        &Model_TranslationEngine64_B.EnergyLpfTauS_g.Value, 1,
        PreAmpAudiopilotRatioEnergyLpfTauS_Dependencies
    },

    {                                  /* '<S399>/Tune Variable' */
        "PreAmpAudiopilotRatioHighBoundDb", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotRatioHighBoundDb, 1,
        Model_TranslationEngine64_B.HighBoundDb.Size,
        &Model_TranslationEngine64_B.HighBoundDb.Value, 1,
        PreAmpAudiopilotRatioHighBoundDb_Dependencies
    },

    {                                  /* '<S400>/Tune Variable' */
        "PreAmpAudiopilotRatioLowBoundDb", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotRatioLowBoundDb, 1,
        Model_TranslationEngine64_B.LowBoundDb.Size,
        &Model_TranslationEngine64_B.LowBoundDb.Value, 1,
        PreAmpAudiopilotRatioLowBoundDb_Dependencies
    },

    {                                  /* '<S442>/Tune Variable' */
        "PreAmpAudiopilotRatioSlewAttackDbPerS", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotRatioSlewAttackDbPerS, 1,
        Model_TranslationEngine64_B.AttackDbPerS_o.Size,
        &Model_TranslationEngine64_B.AttackDbPerS_o.Value, 1,
        PreAmpAudiopilotRatioSlewAttackDbPerS_Dependencies
    },

    {                                  /* '<S443>/Tune Variable' */
        "PreAmpAudiopilotRatioSlewDecayDbPerS", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotRatioSlewDecayDbPerS, 1,
        Model_TranslationEngine64_B.DecayDbPerS_f.Size,
        &Model_TranslationEngine64_B.DecayDbPerS_f.Value, 1,
        PreAmpAudiopilotRatioSlewDecayDbPerS_Dependencies
    },

    {                                  /* '<S444>/Tune Variable' */
        "PreAmpAudiopilotRatioSlewThresholdDb", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotRatioSlewThresholdDb, 1,
        Model_TranslationEngine64_B.ThresholdDb_b.Size,
        &Model_TranslationEngine64_B.ThresholdDb_b.Value, 1,
        PreAmpAudiopilotRatioSlewThresholdDb_Dependencies
    },

    {                                  /* '<S455>/Tune Variable' */
        "PreAmpAudiopilotRatioImpulseRejectionGamma0TauS", 0, TSS_SINGLE, 0,
        sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotRatioImpulseRejectionGamma0TauS, 1,
        Model_TranslationEngine64_B.Gamma0TauS_p.Size,
        &Model_TranslationEngine64_B.Gamma0TauS_p.Value, 1,
        PreAmpAudiopilotRatioImpulseRejectionGamma0TauS_Dependencies
    },

    {                                  /* '<S456>/Tune Variable' */
        "PreAmpAudiopilotRatioImpulseRejectionImpulseVarianceLpfTauS", 0,
        TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0,
        DefValue_PreAmpAudiopilotRatioImpulseRejectionImpulseVarianceLpfTauS, 1,
        Model_TranslationEngine64_B.ImpulseVarianceLpfTauS.Size,
        &Model_TranslationEngine64_B.ImpulseVarianceLpfTauS.Value, 1,
        PreAmpAudiopilotRatioImpulseRejectionImpulseVarianceLpfTauS_Dependencies
    },

    {                                  /* '<S457>/Tune Variable' */
        "PreAmpAudiopilotRatioImpulseRejectionImpulseVarianceScale", 0,
        TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0,
        DefValue_PreAmpAudiopilotRatioImpulseRejectionImpulseVarianceScale, 1,
        Model_TranslationEngine64_B.ImpulseVarianceScale_h.Size,
        &Model_TranslationEngine64_B.ImpulseVarianceScale_h.Value, 1,
        PreAmpAudiopilotRatioImpulseRejectionImpulseVarianceScale_Dependencies
    },

    {                                  /* '<S458>/Tune Variable' */
        "PreAmpAudiopilotRatioImpulseRejectionNoiseVarianceScale", 0, TSS_SINGLE,
        0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0,
        DefValue_PreAmpAudiopilotRatioImpulseRejectionNoiseVarianceScale, 1,
        Model_TranslationEngine64_B.NoiseVarianceScale_g.Size,
        &Model_TranslationEngine64_B.NoiseVarianceScale_g.Value, 1,
        PreAmpAudiopilotRatioImpulseRejectionNoiseVarianceScale_Dependencies
    },

    {                                  /* '<S477>/Tune Variable' */
        "PreAmpAudiopilotLevelDetectFastDecayDbPerS", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotLevelDetectFastDecayDbPerS, 1,
        Model_TranslationEngine64_B.FastDecayDbPerS.Size,
        &Model_TranslationEngine64_B.FastDecayDbPerS.Value, 1,
        PreAmpAudiopilotLevelDetectFastDecayDbPerS_Dependencies
    },

    {                                  /* '<S478>/Tune Variable' */
        "PreAmpAudiopilotLevelDetectHoldMarginDb", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotLevelDetectHoldMarginDb, 1,
        Model_TranslationEngine64_B.HoldMarginDb_m.Size,
        &Model_TranslationEngine64_B.HoldMarginDb_m.Value, 1,
        PreAmpAudiopilotLevelDetectHoldMarginDb_Dependencies
    },

    {                                  /* '<S479>/Tune Variable' */
        "PreAmpAudiopilotLevelDetectHoldTimeS", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotLevelDetectHoldTimeS, 1,
        Model_TranslationEngine64_B.HoldTimeS.Size,
        &Model_TranslationEngine64_B.HoldTimeS.Value, 1,
        PreAmpAudiopilotLevelDetectHoldTimeS_Dependencies
    },

    {                                  /* '<S480>/Tune Variable' */
        "PreAmpAudiopilotLevelDetectMaxVolumeDb", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotLevelDetectMaxVolumeDb, 1,
        Model_TranslationEngine64_B.MaxVolumeDb_l.Size,
        &Model_TranslationEngine64_B.MaxVolumeDb_l.Value, 1,
        PreAmpAudiopilotLevelDetectMaxVolumeDb_Dependencies
    },

    {                                  /* '<S481>/Tune Variable' */
        "PreAmpAudiopilotLevelDetectMinVolumeDb", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotLevelDetectMinVolumeDb, 1,
        Model_TranslationEngine64_B.MinVolumeDb_j.Size,
        &Model_TranslationEngine64_B.MinVolumeDb_j.Value, 1,
        PreAmpAudiopilotLevelDetectMinVolumeDb_Dependencies
    },

    {                                  /* '<S482>/Tune Variable' */
        "PreAmpAudiopilotLevelDetectSlowDecayDbPerS", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpAudiopilotLevelDetectSlowDecayDbPerS, 1,
        Model_TranslationEngine64_B.SlowDecayDbPerS.Size,
        &Model_TranslationEngine64_B.SlowDecayDbPerS.Value, 1,
        PreAmpAudiopilotLevelDetectSlowDecayDbPerS_Dependencies
    },

    {                                  /* '<S504>/Tune Variable' */
        "PreAmpDyneqLevelDetectFastDecayDbPerS", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpDyneqLevelDetectFastDecayDbPerS, 1,
        Model_TranslationEngine64_B.FastDecayDbPerS_k.Size,
        &Model_TranslationEngine64_B.FastDecayDbPerS_k.Value, 1,
        PreAmpDyneqLevelDetectFastDecayDbPerS_Dependencies
    },

    {                                  /* '<S505>/Tune Variable' */
        "PreAmpDyneqLevelDetectHoldMarginDb", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpDyneqLevelDetectHoldMarginDb, 1,
        Model_TranslationEngine64_B.HoldMarginDb_ma.Size,
        &Model_TranslationEngine64_B.HoldMarginDb_ma.Value, 1,
        PreAmpDyneqLevelDetectHoldMarginDb_Dependencies
    },

    {                                  /* '<S506>/Tune Variable' */
        "PreAmpDyneqLevelDetectHoldTimeS", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpDyneqLevelDetectHoldTimeS, 1,
        Model_TranslationEngine64_B.HoldTimeS_p.Size,
        &Model_TranslationEngine64_B.HoldTimeS_p.Value, 1,
        PreAmpDyneqLevelDetectHoldTimeS_Dependencies
    },

    {                                  /* '<S507>/Tune Variable' */
        "PreAmpDyneqLevelDetectMaxVolumeDb", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpDyneqLevelDetectMaxVolumeDb, 1,
        Model_TranslationEngine64_B.MaxVolumeDb_e.Size,
        &Model_TranslationEngine64_B.MaxVolumeDb_e.Value, 1,
        PreAmpDyneqLevelDetectMaxVolumeDb_Dependencies
    },

    {                                  /* '<S508>/Tune Variable' */
        "PreAmpDyneqLevelDetectMinVolumeDb", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpDyneqLevelDetectMinVolumeDb, 1,
        Model_TranslationEngine64_B.MinVolumeDb_c.Size,
        &Model_TranslationEngine64_B.MinVolumeDb_c.Value, 1,
        PreAmpDyneqLevelDetectMinVolumeDb_Dependencies
    },

    {                                  /* '<S509>/Tune Variable' */
        "PreAmpDyneqLevelDetectSlowDecayDbPerS", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpDyneqLevelDetectSlowDecayDbPerS, 1,
        Model_TranslationEngine64_B.SlowDecayDbPerS_k.Size,
        &Model_TranslationEngine64_B.SlowDecayDbPerS_k.Value, 1,
        PreAmpDyneqLevelDetectSlowDecayDbPerS_Dependencies
    },

    {                                  /* '<S530>/Tune Variable' */
        "PreAmpLevelDetectLatencyMs", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpLevelDetectLatencyMs, 1,
        Model_TranslationEngine64_B.LatencyMs.Size,
        &Model_TranslationEngine64_B.LatencyMs.Value, 1,
        PreAmpLevelDetectLatencyMs_Dependencies
    },

    {                                  /* '<S537>/Tune Variable2' */
        "PreAmpLevelDetectPreemphasissosCoefficients", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 12,
        {
            2,
            6,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpLevelDetectPreemphasissosCoefficients, 12,
        Model_TranslationEngine64_B.sosCoefficients_ji.Size,
        Model_TranslationEngine64_B.sosCoefficients_ji.Value, 1,
        PreAmpLevelDetectPreemphasissosCoefficients_Dependencies
    },

    {                                  /* '<S537>/Tune Variable1' */
        "PreAmpLevelDetectPreemphasisnumStages", 0, TSS_SINGLE, 0, sizeof
        (real32_T), 2,
        {
            2,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpLevelDetectPreemphasisnumStages, 2,
        Model_TranslationEngine64_B.numStages_nv.Size,
        Model_TranslationEngine64_B.numStages_nv.Value, 1,
        PreAmpLevelDetectPreemphasisnumStages_Dependencies
    },

    {                                  /* '<S532>/Tune Variable' */
        "PreAmpLevelDetectSysMaxDbspl", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpLevelDetectSysMaxDbspl, 1,
        Model_TranslationEngine64_B.SysMaxDbspl_l.Size,
        &Model_TranslationEngine64_B.SysMaxDbspl_l.Value, 1,
        PreAmpLevelDetectSysMaxDbspl_Dependencies
    },

    {                                  /* '<S545>/TuneVar_Table' */
        "PreAmpVolumeCfgTable", 0, TSS_DOUBLE, 0, sizeof(real_T), 16,
        {
            8,
            2,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpVolumeCfgTable, 6,
        Model_TranslationEngine64_B.Table_f.Size,
        Model_TranslationEngine64_B.Table_f.Value, 1,
        PreAmpVolumeCfgTable_Dependencies
    },

    {                                  /* '<S548>/Tune Variable' */
        "PreAmpVolumeCfgmaxgain", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpVolumeCfgmaxgain, 1,
        Model_TranslationEngine64_B.maxgain.Size,
        &Model_TranslationEngine64_B.maxgain.Value, 1,
        PreAmpVolumeCfgmaxgain_Dependencies
    },

    {                                  /* '<S546>/Tune Variable' */
        "PreAmpVolumeCfgRampTime", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpVolumeCfgRampTime, 1,
        Model_TranslationEngine64_B.RampTime_d.Size,
        &Model_TranslationEngine64_B.RampTime_d.Value, 1,
        PreAmpVolumeCfgRampTime_Dependencies
    },

    {                                  /* '<S565>/TuneVarChanRampMap' */
        "PreAmpBalance_CfgChanRampMap", 0, TSS_DOUBLE, 0, sizeof(real_T), 2,
        {
            1,
            2,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpBalance_CfgChanRampMap, 2,
        Model_TranslationEngine64_B.ChanRampMap.Size,
        Model_TranslationEngine64_B.ChanRampMap.Value, 1,
        PreAmpBalance_CfgChanRampMap_Dependencies
    },

    {                                  /* '<S567>/Tune Variable' */
        "PreAmpBalance_CfgBoostDisable", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpBalance_CfgBoostDisable, 1,
        Model_TranslationEngine64_B.BoostDisable_c.Size,
        &Model_TranslationEngine64_B.BoostDisable_c.Value, 1,
        PreAmpBalance_CfgBoostDisable_Dependencies
    },

    {                                  /* '<S568>/Tune Variable' */
        "PreAmpBalance_CfgOffset", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpBalance_CfgOffset, 1,
        Model_TranslationEngine64_B.Offset_f.Size,
        &Model_TranslationEngine64_B.Offset_f.Value, 1,
        PreAmpBalance_CfgOffset_Dependencies
    },

    {                                  /* '<S569>/Tune Variable' */
        "PreAmpBalance_CfgRampTime", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpBalance_CfgRampTime, 1,
        Model_TranslationEngine64_B.RampTime_i.Size,
        &Model_TranslationEngine64_B.RampTime_i.Value, 1,
        PreAmpBalance_CfgRampTime_Dependencies
    },

    {                                  /* '<S570>/Tune Variable' */
        "PreAmpBalance_CfgSleepingBeautyMutesBass", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpBalance_CfgSleepingBeautyMutesBass, 1,
        Model_TranslationEngine64_B.SleepingBeautyMutesBass.Size,
        &Model_TranslationEngine64_B.SleepingBeautyMutesBass.Value, 1,
        PreAmpBalance_CfgSleepingBeautyMutesBass_Dependencies
    },

    {                                  /* '<S571>/Tune Variable' */
        "PreAmpBalance_CfgEnableSilentExtreme", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpBalance_CfgEnableSilentExtreme, 1,
        Model_TranslationEngine64_B.EnableSilentExtreme_f.Size,
        &Model_TranslationEngine64_B.EnableSilentExtreme_f.Value, 1,
        PreAmpBalance_CfgEnableSilentExtreme_Dependencies
    },

    {                                  /* '<S572>/TuneVarBalanceTable' */
        "PreAmpBalance_CfgTable", 0, TSS_DOUBLE, 0, sizeof(real_T), 60,
        {
            30,
            2,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpBalance_CfgTable, 30,
        Model_TranslationEngine64_B.Table_i.Size,
        Model_TranslationEngine64_B.Table_i.Value, 1,
        PreAmpBalance_CfgTable_Dependencies
    },

    {                                  /* '<S1049>/Tune Variable' */
        "PreAmpNearWiggleCoeffs", 0, TSS_DOUBLE, 0, sizeof(real_T), 2048,
        {
            1024,
            2,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpNearWiggleCoeffs, 2048,
        Model_TranslationEngine64_B.NearWiggleCoeffs.Size,
        Model_TranslationEngine64_B.NearWiggleCoeffs.Value, 1,
        PreAmpNearWiggleCoeffs_Dependencies
    },

    {                                  /* '<S1050>/Tune Variable' */
        "PreAmpNearDelay", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_PreAmpNearDelay, 1,
        Model_TranslationEngine64_B.NearDelay.Size,
        &Model_TranslationEngine64_B.NearDelay.Value, 1,
        PreAmpNearDelay_Dependencies
    },

    {                                  /* '<S1313>/Tune Variable2' */
        "NearDr_PooliirsosCoefficients", 0, TSS_DOUBLE, 0, sizeof(real_T), 600,
        {
            100,
            6,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_PooliirsosCoefficients, 600,
        Model_TranslationEngine64_B.sosCoefficients.Size,
        Model_TranslationEngine64_B.sosCoefficients.Value, 1,
        NearDr_PooliirsosCoefficients_Dependencies
    },

    {                                  /* '<S1313>/Tune Variable1' */
        "NearDr_PooliirnumStages", 0, TSS_DOUBLE, 0, sizeof(real_T), 7,
        {
            1,
            7,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_PooliirnumStages, 7,
        Model_TranslationEngine64_B.numStages.Size,
        Model_TranslationEngine64_B.numStages.Value, 1,
        NearDr_PooliirnumStages_Dependencies
    },

    {                                  /* '<S1317>/Tune Variable' */
        "NearDr_f1_del", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_f1_del, 1,
        Model_TranslationEngine64_B.f1_del.Size,
        &Model_TranslationEngine64_B.f1_del.Value, 1, NearDr_f1_del_Dependencies
    },

    {                                  /* '<S1317>/Tune Variable1' */
        "NearDr_f2_del", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_f2_del, 1,
        Model_TranslationEngine64_B.f2_del.Size,
        &Model_TranslationEngine64_B.f2_del.Value, 1, NearDr_f2_del_Dependencies
    },

    {                                  /* '<S1317>/Tune Variable2' */
        "NearDr_f3_del", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_f3_del, 1,
        Model_TranslationEngine64_B.f3_del.Size,
        &Model_TranslationEngine64_B.f3_del.Value, 1, NearDr_f3_del_Dependencies
    },

    {                                  /* '<S1317>/Tune Variable3' */
        "NearDr_f4_del", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_f4_del, 1,
        Model_TranslationEngine64_B.f4_del.Size,
        &Model_TranslationEngine64_B.f4_del.Value, 1, NearDr_f4_del_Dependencies
    },

    {                                  /* '<S1317>/Tune Variable4' */
        "NearDr_f5_del", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_f5_del, 1,
        Model_TranslationEngine64_B.f5_del.Size,
        &Model_TranslationEngine64_B.f5_del.Value, 1, NearDr_f5_del_Dependencies
    },

    {                                  /* '<S1317>/Tune Variable5' */
        "NearDr_f6_del", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_f6_del, 1,
        Model_TranslationEngine64_B.f6_del.Size,
        &Model_TranslationEngine64_B.f6_del.Value, 1, NearDr_f6_del_Dependencies
    },

    {                                  /* '<S1317>/Tune Variable7' */
        "NearDr_f7_del", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_f7_del, 1,
        Model_TranslationEngine64_B.f7_del.Size,
        &Model_TranslationEngine64_B.f7_del.Value, 1, NearDr_f7_del_Dependencies
    },

    {                                  /* '<S1323>/Tune Variable2' */
        "NearDr_PoolIirTunablesosCoefficients", 0, TSS_DOUBLE, 0, sizeof(real_T),
        600,
        {
            100,
            6,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_PoolIirTunablesosCoefficients, 600,
        Model_TranslationEngine64_B.sosCoefficients_i.Size,
        Model_TranslationEngine64_B.sosCoefficients_i.Value, 1,
        NearDr_PoolIirTunablesosCoefficients_Dependencies
    },

    {                                  /* '<S1323>/Tune Variable1' */
        "NearDr_PoolIirTunablenumStages", 0, TSS_DOUBLE, 0, sizeof(real_T), 4,
        {
            1,
            4,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_PoolIirTunablenumStages, 4,
        Model_TranslationEngine64_B.numStages_m.Size,
        Model_TranslationEngine64_B.numStages_m.Value, 1,
        NearDr_PoolIirTunablenumStages_Dependencies
    },

    {                                  /* '<S1327>/Tune Variable1' */
        "NearDr_driver_src1", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_driver_src1, 1,
        Model_TranslationEngine64_B.driver_src1.Size,
        &Model_TranslationEngine64_B.driver_src1.Value, 1,
        NearDr_driver_src1_Dependencies
    },

    {                                  /* '<S1327>/Tune Variable2' */
        "NearDr_driver_src2", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_driver_src2, 1,
        Model_TranslationEngine64_B.driver_src2.Size,
        &Model_TranslationEngine64_B.driver_src2.Value, 1,
        NearDr_driver_src2_Dependencies
    },

    {                                  /* '<S1327>/Tune Variable3' */
        "NearDr_driver_src3", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_driver_src3, 1,
        Model_TranslationEngine64_B.driver_src3.Size,
        &Model_TranslationEngine64_B.driver_src3.Value, 1,
        NearDr_driver_src3_Dependencies
    },

    {                                  /* '<S1327>/Tune Variable4' */
        "NearDr_driver_src4", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_driver_src4, 1,
        Model_TranslationEngine64_B.driver_src4.Size,
        &Model_TranslationEngine64_B.driver_src4.Value, 1,
        NearDr_driver_src4_Dependencies
    },

    {                                  /* '<S1327>/Tune Variable5' */
        "NearDr_passenger_src1", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_passenger_src1, 1,
        Model_TranslationEngine64_B.passenger_src1.Size,
        &Model_TranslationEngine64_B.passenger_src1.Value, 1,
        NearDr_passenger_src1_Dependencies
    },

    {                                  /* '<S1327>/Tune Variable7' */
        "NearDr_passenger_src2", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_passenger_src2, 1,
        Model_TranslationEngine64_B.passenger_src2.Size,
        &Model_TranslationEngine64_B.passenger_src2.Value, 1,
        NearDr_passenger_src2_Dependencies
    },

    {                                  /* '<S1327>/Tune Variable6' */
        "NearDr_passenger_src3", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_passenger_src3, 1,
        Model_TranslationEngine64_B.passenger_src3.Size,
        &Model_TranslationEngine64_B.passenger_src3.Value, 1,
        NearDr_passenger_src3_Dependencies
    },

    {                                  /* '<S1327>/Tune Variable8' */
        "NearDr_passenger_src4", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_passenger_src4, 1,
        Model_TranslationEngine64_B.passenger_src4.Size,
        &Model_TranslationEngine64_B.passenger_src4.Value, 1,
        NearDr_passenger_src4_Dependencies
    },

    {                                  /* '<S1331>/TuneVarRouterMap' */
        "NearDr_RouterMap", 0, TSS_DOUBLE, 0, sizeof(real_T), 18,
        {
            1,
            18,
            1,
            1,
            1,
            1,
            1,
        },
        1, 2, 0, DefValue_NearDr_RouterMap, 18,
        Model_TranslationEngine64_B.Map.Size,
        Model_TranslationEngine64_B.Map.Value, 1, NearDr_RouterMap_Dependencies
    },

    {                                  /* '<S1336>/Tune Variable' */
        "NearDr_f1_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_f1_mix, 25,
        Model_TranslationEngine64_B.f1_mix.Size,
        Model_TranslationEngine64_B.f1_mix.Value, 1, NearDr_f1_mix_Dependencies
    },

    {                                  /* '<S1336>/Tune Variable1' */
        "NearDr_f2_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_f2_mix, 25,
        Model_TranslationEngine64_B.f2_mix.Size,
        Model_TranslationEngine64_B.f2_mix.Value, 1, NearDr_f2_mix_Dependencies
    },

    {                                  /* '<S1336>/Tune Variable2' */
        "NearDr_f3_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_f3_mix, 25,
        Model_TranslationEngine64_B.f3_mix.Size,
        Model_TranslationEngine64_B.f3_mix.Value, 1, NearDr_f3_mix_Dependencies
    },

    {                                  /* '<S1336>/Tune Variable3' */
        "NearDr_f4_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_f4_mix, 25,
        Model_TranslationEngine64_B.f4_mix.Size,
        Model_TranslationEngine64_B.f4_mix.Value, 1, NearDr_f4_mix_Dependencies
    },

    {                                  /* '<S1336>/Tune Variable4' */
        "NearDr_f5_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_f5_mix, 25,
        Model_TranslationEngine64_B.f5_mix.Size,
        Model_TranslationEngine64_B.f5_mix.Value, 1, NearDr_f5_mix_Dependencies
    },

    {                                  /* '<S1336>/Tune Variable5' */
        "NearDr_f6_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_f6_mix, 25,
        Model_TranslationEngine64_B.f6_mix.Size,
        Model_TranslationEngine64_B.f6_mix.Value, 1, NearDr_f6_mix_Dependencies
    },

    {                                  /* '<S1336>/Tune Variable7' */
        "NearDr_f7_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_f7_mix, 25,
        Model_TranslationEngine64_B.f7_mix.Size,
        Model_TranslationEngine64_B.f7_mix.Value, 1, NearDr_f7_mix_Dependencies
    },

    {                                  /* '<S1337>/Tune Variable' */
        "NearDr_LFI0_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_LFI0_mix, 25,
        Model_TranslationEngine64_B.LFI0_mix.Size,
        Model_TranslationEngine64_B.LFI0_mix.Value, 1,
        NearDr_LFI0_mix_Dependencies
    },

    {                                  /* '<S1337>/Tune Variable1' */
        "NearDr_LFT0_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_LFT0_mix, 25,
        Model_TranslationEngine64_B.LFT0_mix.Size,
        Model_TranslationEngine64_B.LFT0_mix.Value, 1,
        NearDr_LFT0_mix_Dependencies
    },

    {                                  /* '<S1337>/Tune Variable2' */
        "NearDr_RFI0_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_RFI0_mix, 25,
        Model_TranslationEngine64_B.RFI0_mix.Size,
        Model_TranslationEngine64_B.RFI0_mix.Value, 1,
        NearDr_RFI0_mix_Dependencies
    },

    {                                  /* '<S1337>/Tune Variable3' */
        "NearDr_RFT0_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_RFT0_mix, 25,
        Model_TranslationEngine64_B.RFT0_mix.Size,
        Model_TranslationEngine64_B.RFT0_mix.Value, 1,
        NearDr_RFT0_mix_Dependencies
    },

    {                                  /* '<S1337>/Tune Variable4' */
        "NearDr_LSI0_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_LSI0_mix, 25,
        Model_TranslationEngine64_B.LSI0_mix.Size,
        Model_TranslationEngine64_B.LSI0_mix.Value, 1,
        NearDr_LSI0_mix_Dependencies
    },

    {                                  /* '<S1337>/Tune Variable5' */
        "NearDr_LST0_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_LST0_mix, 25,
        Model_TranslationEngine64_B.LST0_mix.Size,
        Model_TranslationEngine64_B.LST0_mix.Value, 1,
        NearDr_LST0_mix_Dependencies
    },

    {                                  /* '<S1337>/Tune Variable7' */
        "NearDr_RSI0_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_RSI0_mix, 25,
        Model_TranslationEngine64_B.RSI0_mix.Size,
        Model_TranslationEngine64_B.RSI0_mix.Value, 1,
        NearDr_RSI0_mix_Dependencies
    },

    {                                  /* '<S1337>/Tune Variable6' */
        "NearDr_RST0_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_RST0_mix, 25,
        Model_TranslationEngine64_B.RST0_mix.Size,
        Model_TranslationEngine64_B.RST0_mix.Value, 1,
        NearDr_RST0_mix_Dependencies
    },

    {                                  /* '<S1337>/Tune Variable8' */
        "NearDr_LCI0_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_LCI0_mix, 25,
        Model_TranslationEngine64_B.LCI0_mix.Size,
        Model_TranslationEngine64_B.LCI0_mix.Value, 1,
        NearDr_LCI0_mix_Dependencies
    },

    {                                  /* '<S1337>/Tune Variable9' */
        "NearDr_LCT0_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_LCT0_mix, 25,
        Model_TranslationEngine64_B.LCT0_mix.Size,
        Model_TranslationEngine64_B.LCT0_mix.Value, 1,
        NearDr_LCT0_mix_Dependencies
    },

    {                                  /* '<S1337>/Tune Variable10' */
        "NearDr_RCI0_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_RCI0_mix, 25,
        Model_TranslationEngine64_B.RCI0_mix.Size,
        Model_TranslationEngine64_B.RCI0_mix.Value, 1,
        NearDr_RCI0_mix_Dependencies
    },

    {                                  /* '<S1337>/Tune Variable11' */
        "NearDr_RCT0_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_RCT0_mix, 25,
        Model_TranslationEngine64_B.RCT0_mix.Size,
        Model_TranslationEngine64_B.RCT0_mix.Value, 1,
        NearDr_RCT0_mix_Dependencies
    },

    {                                  /* '<S1338>/Tune Variable' */
        "NearDr_LFI1_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_LFI1_mix, 25,
        Model_TranslationEngine64_B.LFI1_mix.Size,
        Model_TranslationEngine64_B.LFI1_mix.Value, 1,
        NearDr_LFI1_mix_Dependencies
    },

    {                                  /* '<S1338>/Tune Variable1' */
        "NearDr_LFT1_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_LFT1_mix, 25,
        Model_TranslationEngine64_B.LFT1_mix.Size,
        Model_TranslationEngine64_B.LFT1_mix.Value, 1,
        NearDr_LFT1_mix_Dependencies
    },

    {                                  /* '<S1338>/Tune Variable2' */
        "NearDr_RFI1_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_RFI1_mix, 25,
        Model_TranslationEngine64_B.RFI1_mix.Size,
        Model_TranslationEngine64_B.RFI1_mix.Value, 1,
        NearDr_RFI1_mix_Dependencies
    },

    {                                  /* '<S1338>/Tune Variable3' */
        "NearDr_RFT1_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_RFT1_mix, 25,
        Model_TranslationEngine64_B.RFT1_mix.Size,
        Model_TranslationEngine64_B.RFT1_mix.Value, 1,
        NearDr_RFT1_mix_Dependencies
    },

    {                                  /* '<S1338>/Tune Variable4' */
        "NearDr_LSI1_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_LSI1_mix, 25,
        Model_TranslationEngine64_B.LSI1_mix.Size,
        Model_TranslationEngine64_B.LSI1_mix.Value, 1,
        NearDr_LSI1_mix_Dependencies
    },

    {                                  /* '<S1338>/Tune Variable5' */
        "NearDr_LST1_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_LST1_mix, 25,
        Model_TranslationEngine64_B.LST1_mix.Size,
        Model_TranslationEngine64_B.LST1_mix.Value, 1,
        NearDr_LST1_mix_Dependencies
    },

    {                                  /* '<S1338>/Tune Variable7' */
        "NearDr_RSI1_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_RSI1_mix, 25,
        Model_TranslationEngine64_B.RSI1_mix.Size,
        Model_TranslationEngine64_B.RSI1_mix.Value, 1,
        NearDr_RSI1_mix_Dependencies
    },

    {                                  /* '<S1338>/Tune Variable6' */
        "NearDr_RST1_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_RST1_mix, 25,
        Model_TranslationEngine64_B.RST1_mix.Size,
        Model_TranslationEngine64_B.RST1_mix.Value, 1,
        NearDr_RST1_mix_Dependencies
    },

    {                                  /* '<S1338>/Tune Variable8' */
        "NearDr_LCI1_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_LCI1_mix, 25,
        Model_TranslationEngine64_B.LCI1_mix.Size,
        Model_TranslationEngine64_B.LCI1_mix.Value, 1,
        NearDr_LCI1_mix_Dependencies
    },

    {                                  /* '<S1338>/Tune Variable9' */
        "NearDr_LCT1_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_LCT1_mix, 25,
        Model_TranslationEngine64_B.LCT1_mix.Size,
        Model_TranslationEngine64_B.LCT1_mix.Value, 1,
        NearDr_LCT1_mix_Dependencies
    },

    {                                  /* '<S1338>/Tune Variable10' */
        "NearDr_RCI1_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_RCI1_mix, 25,
        Model_TranslationEngine64_B.RCI1_mix.Size,
        Model_TranslationEngine64_B.RCI1_mix.Value, 1,
        NearDr_RCI1_mix_Dependencies
    },

    {                                  /* '<S1338>/Tune Variable11' */
        "NearDr_RCT1_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_RCT1_mix, 25,
        Model_TranslationEngine64_B.RCT1_mix.Size,
        Model_TranslationEngine64_B.RCT1_mix.Value, 1,
        NearDr_RCT1_mix_Dependencies
    },

    {                                  /* '<S1339>/Tune Variable' */
        "NearDr_nv0l_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_nv0l_mix, 25,
        Model_TranslationEngine64_B.nv0l_mix.Size,
        Model_TranslationEngine64_B.nv0l_mix.Value, 1,
        NearDr_nv0l_mix_Dependencies
    },

    {                                  /* '<S1339>/Tune Variable1' */
        "NearDr_nv0r_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_nv0r_mix, 25,
        Model_TranslationEngine64_B.nv0r_mix.Size,
        Model_TranslationEngine64_B.nv0r_mix.Value, 1,
        NearDr_nv0r_mix_Dependencies
    },

    {                                  /* '<S1339>/Tune Variable2' */
        "NearDr_nv1l_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_nv1l_mix, 25,
        Model_TranslationEngine64_B.nv1l_mix.Size,
        Model_TranslationEngine64_B.nv1l_mix.Value, 1,
        NearDr_nv1l_mix_Dependencies
    },

    {                                  /* '<S1339>/Tune Variable3' */
        "NearDr_nv1r_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearDr_nv1r_mix, 25,
        Model_TranslationEngine64_B.nv1r_mix.Size,
        Model_TranslationEngine64_B.nv1r_mix.Value, 1,
        NearDr_nv1r_mix_Dependencies
    },

    {                                  /* '<S1350>/Tune Variable2' */
        "NearFr_PooliirsosCoefficients", 0, TSS_DOUBLE, 0, sizeof(real_T), 600,
        {
            100,
            6,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_PooliirsosCoefficients, 600,
        Model_TranslationEngine64_B.sosCoefficients_o.Size,
        Model_TranslationEngine64_B.sosCoefficients_o.Value, 1,
        NearFr_PooliirsosCoefficients_Dependencies
    },

    {                                  /* '<S1350>/Tune Variable1' */
        "NearFr_PooliirnumStages", 0, TSS_DOUBLE, 0, sizeof(real_T), 5,
        {
            1,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_PooliirnumStages, 5,
        Model_TranslationEngine64_B.numStages_n.Size,
        Model_TranslationEngine64_B.numStages_n.Value, 1,
        NearFr_PooliirnumStages_Dependencies
    },

    {                                  /* '<S1354>/Tune Variable' */
        "NearFr_f1_del", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_f1_del, 1,
        Model_TranslationEngine64_B.f1_del_p.Size,
        &Model_TranslationEngine64_B.f1_del_p.Value, 1,
        NearFr_f1_del_Dependencies
    },

    {                                  /* '<S1354>/Tune Variable1' */
        "NearFr_f2_del", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_f2_del, 1,
        Model_TranslationEngine64_B.f2_del_c.Size,
        &Model_TranslationEngine64_B.f2_del_c.Value, 1,
        NearFr_f2_del_Dependencies
    },

    {                                  /* '<S1354>/Tune Variable2' */
        "NearFr_f3_del", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_f3_del, 1,
        Model_TranslationEngine64_B.f3_del_b.Size,
        &Model_TranslationEngine64_B.f3_del_b.Value, 1,
        NearFr_f3_del_Dependencies
    },

    {                                  /* '<S1354>/Tune Variable3' */
        "NearFr_f4_del", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_f4_del, 1,
        Model_TranslationEngine64_B.f4_del_p.Size,
        &Model_TranslationEngine64_B.f4_del_p.Value, 1,
        NearFr_f4_del_Dependencies
    },

    {                                  /* '<S1354>/Tune Variable4' */
        "NearFr_f5_del", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_f5_del, 1,
        Model_TranslationEngine64_B.f5_del_b.Size,
        &Model_TranslationEngine64_B.f5_del_b.Value, 1,
        NearFr_f5_del_Dependencies
    },

    {                                  /* '<S1354>/Tune Variable5' */
        "NearFr_f6_del", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_f6_del, 1,
        Model_TranslationEngine64_B.f6_del_n.Size,
        &Model_TranslationEngine64_B.f6_del_n.Value, 1,
        NearFr_f6_del_Dependencies
    },

    {                                  /* '<S1354>/Tune Variable7' */
        "NearFr_f7_del", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_f7_del, 1,
        Model_TranslationEngine64_B.f7_del_c.Size,
        &Model_TranslationEngine64_B.f7_del_c.Value, 1,
        NearFr_f7_del_Dependencies
    },

    {                                  /* '<S1360>/Tune Variable2' */
        "NearFr_PoolIirTunablesosCoefficients", 0, TSS_DOUBLE, 0, sizeof(real_T),
        600,
        {
            100,
            6,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_PoolIirTunablesosCoefficients, 600,
        Model_TranslationEngine64_B.sosCoefficients_j.Size,
        Model_TranslationEngine64_B.sosCoefficients_j.Value, 1,
        NearFr_PoolIirTunablesosCoefficients_Dependencies
    },

    {                                  /* '<S1360>/Tune Variable1' */
        "NearFr_PoolIirTunablenumStages", 0, TSS_DOUBLE, 0, sizeof(real_T), 4,
        {
            1,
            4,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_PoolIirTunablenumStages, 4,
        Model_TranslationEngine64_B.numStages_c.Size,
        Model_TranslationEngine64_B.numStages_c.Value, 1,
        NearFr_PoolIirTunablenumStages_Dependencies
    },

    {                                  /* '<S1364>/Tune Variable1' */
        "NearFr_driver_src1", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_driver_src1, 1,
        Model_TranslationEngine64_B.driver_src1_l.Size,
        &Model_TranslationEngine64_B.driver_src1_l.Value, 1,
        NearFr_driver_src1_Dependencies
    },

    {                                  /* '<S1364>/Tune Variable2' */
        "NearFr_driver_src2", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_driver_src2, 1,
        Model_TranslationEngine64_B.driver_src2_p.Size,
        &Model_TranslationEngine64_B.driver_src2_p.Value, 1,
        NearFr_driver_src2_Dependencies
    },

    {                                  /* '<S1364>/Tune Variable3' */
        "NearFr_driver_src3", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_driver_src3, 1,
        Model_TranslationEngine64_B.driver_src3_l.Size,
        &Model_TranslationEngine64_B.driver_src3_l.Value, 1,
        NearFr_driver_src3_Dependencies
    },

    {                                  /* '<S1364>/Tune Variable4' */
        "NearFr_driver_src4", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_driver_src4, 1,
        Model_TranslationEngine64_B.driver_src4_c.Size,
        &Model_TranslationEngine64_B.driver_src4_c.Value, 1,
        NearFr_driver_src4_Dependencies
    },

    {                                  /* '<S1364>/Tune Variable5' */
        "NearFr_passenger_src1", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_passenger_src1, 1,
        Model_TranslationEngine64_B.passenger_src1_p.Size,
        &Model_TranslationEngine64_B.passenger_src1_p.Value, 1,
        NearFr_passenger_src1_Dependencies
    },

    {                                  /* '<S1364>/Tune Variable7' */
        "NearFr_passenger_src2", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_passenger_src2, 1,
        Model_TranslationEngine64_B.passenger_src2_j.Size,
        &Model_TranslationEngine64_B.passenger_src2_j.Value, 1,
        NearFr_passenger_src2_Dependencies
    },

    {                                  /* '<S1364>/Tune Variable6' */
        "NearFr_passenger_src3", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_passenger_src3, 1,
        Model_TranslationEngine64_B.passenger_src3_l.Size,
        &Model_TranslationEngine64_B.passenger_src3_l.Value, 1,
        NearFr_passenger_src3_Dependencies
    },

    {                                  /* '<S1364>/Tune Variable8' */
        "NearFr_passenger_src4", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_passenger_src4, 1,
        Model_TranslationEngine64_B.passenger_src4_f.Size,
        &Model_TranslationEngine64_B.passenger_src4_f.Value, 1,
        NearFr_passenger_src4_Dependencies
    },

    {                                  /* '<S1368>/TuneVarRouterMap' */
        "NearFr_RouterMap", 0, TSS_DOUBLE, 0, sizeof(real_T), 18,
        {
            1,
            18,
            1,
            1,
            1,
            1,
            1,
        },
        1, 2, 0, DefValue_NearFr_RouterMap, 18,
        Model_TranslationEngine64_B.Map_k.Size,
        Model_TranslationEngine64_B.Map_k.Value, 1,
        NearFr_RouterMap_Dependencies
    },

    {                                  /* '<S1373>/Tune Variable' */
        "NearFr_f1_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_f1_mix, 25,
        Model_TranslationEngine64_B.f1_mix_f.Size,
        Model_TranslationEngine64_B.f1_mix_f.Value, 1,
        NearFr_f1_mix_Dependencies
    },

    {                                  /* '<S1373>/Tune Variable1' */
        "NearFr_f2_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_f2_mix, 25,
        Model_TranslationEngine64_B.f2_mix_i.Size,
        Model_TranslationEngine64_B.f2_mix_i.Value, 1,
        NearFr_f2_mix_Dependencies
    },

    {                                  /* '<S1373>/Tune Variable2' */
        "NearFr_f3_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_f3_mix, 25,
        Model_TranslationEngine64_B.f3_mix_g.Size,
        Model_TranslationEngine64_B.f3_mix_g.Value, 1,
        NearFr_f3_mix_Dependencies
    },

    {                                  /* '<S1373>/Tune Variable3' */
        "NearFr_f4_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_f4_mix, 25,
        Model_TranslationEngine64_B.f4_mix_i.Size,
        Model_TranslationEngine64_B.f4_mix_i.Value, 1,
        NearFr_f4_mix_Dependencies
    },

    {                                  /* '<S1373>/Tune Variable4' */
        "NearFr_f5_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_f5_mix, 25,
        Model_TranslationEngine64_B.f5_mix_g.Size,
        Model_TranslationEngine64_B.f5_mix_g.Value, 1,
        NearFr_f5_mix_Dependencies
    },

    {                                  /* '<S1373>/Tune Variable5' */
        "NearFr_f6_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_f6_mix, 25,
        Model_TranslationEngine64_B.f6_mix_g.Size,
        Model_TranslationEngine64_B.f6_mix_g.Value, 1,
        NearFr_f6_mix_Dependencies
    },

    {                                  /* '<S1373>/Tune Variable7' */
        "NearFr_f7_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_f7_mix, 25,
        Model_TranslationEngine64_B.f7_mix_c.Size,
        Model_TranslationEngine64_B.f7_mix_c.Value, 1,
        NearFr_f7_mix_Dependencies
    },

    {                                  /* '<S1374>/Tune Variable' */
        "NearFr_LFI0_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_LFI0_mix, 25,
        Model_TranslationEngine64_B.LFI0_mix_i.Size,
        Model_TranslationEngine64_B.LFI0_mix_i.Value, 1,
        NearFr_LFI0_mix_Dependencies
    },

    {                                  /* '<S1374>/Tune Variable1' */
        "NearFr_LFT0_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_LFT0_mix, 25,
        Model_TranslationEngine64_B.LFT0_mix_o.Size,
        Model_TranslationEngine64_B.LFT0_mix_o.Value, 1,
        NearFr_LFT0_mix_Dependencies
    },

    {                                  /* '<S1374>/Tune Variable2' */
        "NearFr_RFI0_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_RFI0_mix, 25,
        Model_TranslationEngine64_B.RFI0_mix_c.Size,
        Model_TranslationEngine64_B.RFI0_mix_c.Value, 1,
        NearFr_RFI0_mix_Dependencies
    },

    {                                  /* '<S1374>/Tune Variable3' */
        "NearFr_RFT0_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_RFT0_mix, 25,
        Model_TranslationEngine64_B.RFT0_mix_n.Size,
        Model_TranslationEngine64_B.RFT0_mix_n.Value, 1,
        NearFr_RFT0_mix_Dependencies
    },

    {                                  /* '<S1374>/Tune Variable4' */
        "NearFr_LSI0_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_LSI0_mix, 25,
        Model_TranslationEngine64_B.LSI0_mix_d.Size,
        Model_TranslationEngine64_B.LSI0_mix_d.Value, 1,
        NearFr_LSI0_mix_Dependencies
    },

    {                                  /* '<S1374>/Tune Variable5' */
        "NearFr_LST0_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_LST0_mix, 25,
        Model_TranslationEngine64_B.LST0_mix_n.Size,
        Model_TranslationEngine64_B.LST0_mix_n.Value, 1,
        NearFr_LST0_mix_Dependencies
    },

    {                                  /* '<S1374>/Tune Variable7' */
        "NearFr_RSI0_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_RSI0_mix, 25,
        Model_TranslationEngine64_B.RSI0_mix_j.Size,
        Model_TranslationEngine64_B.RSI0_mix_j.Value, 1,
        NearFr_RSI0_mix_Dependencies
    },

    {                                  /* '<S1374>/Tune Variable6' */
        "NearFr_RST0_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_RST0_mix, 25,
        Model_TranslationEngine64_B.RST0_mix_c.Size,
        Model_TranslationEngine64_B.RST0_mix_c.Value, 1,
        NearFr_RST0_mix_Dependencies
    },

    {                                  /* '<S1374>/Tune Variable8' */
        "NearFr_LCI0_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_LCI0_mix, 25,
        Model_TranslationEngine64_B.LCI0_mix_c.Size,
        Model_TranslationEngine64_B.LCI0_mix_c.Value, 1,
        NearFr_LCI0_mix_Dependencies
    },

    {                                  /* '<S1374>/Tune Variable9' */
        "NearFr_LCT0_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_LCT0_mix, 25,
        Model_TranslationEngine64_B.LCT0_mix_k.Size,
        Model_TranslationEngine64_B.LCT0_mix_k.Value, 1,
        NearFr_LCT0_mix_Dependencies
    },

    {                                  /* '<S1374>/Tune Variable10' */
        "NearFr_RCI0_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_RCI0_mix, 25,
        Model_TranslationEngine64_B.RCI0_mix_a.Size,
        Model_TranslationEngine64_B.RCI0_mix_a.Value, 1,
        NearFr_RCI0_mix_Dependencies
    },

    {                                  /* '<S1374>/Tune Variable11' */
        "NearFr_RCT0_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_RCT0_mix, 25,
        Model_TranslationEngine64_B.RCT0_mix_o.Size,
        Model_TranslationEngine64_B.RCT0_mix_o.Value, 1,
        NearFr_RCT0_mix_Dependencies
    },

    {                                  /* '<S1375>/Tune Variable' */
        "NearFr_LFI1_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_LFI1_mix, 25,
        Model_TranslationEngine64_B.LFI1_mix_b.Size,
        Model_TranslationEngine64_B.LFI1_mix_b.Value, 1,
        NearFr_LFI1_mix_Dependencies
    },

    {                                  /* '<S1375>/Tune Variable1' */
        "NearFr_LFT1_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_LFT1_mix, 25,
        Model_TranslationEngine64_B.LFT1_mix_e.Size,
        Model_TranslationEngine64_B.LFT1_mix_e.Value, 1,
        NearFr_LFT1_mix_Dependencies
    },

    {                                  /* '<S1375>/Tune Variable2' */
        "NearFr_RFI1_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_RFI1_mix, 25,
        Model_TranslationEngine64_B.RFI1_mix_b.Size,
        Model_TranslationEngine64_B.RFI1_mix_b.Value, 1,
        NearFr_RFI1_mix_Dependencies
    },

    {                                  /* '<S1375>/Tune Variable3' */
        "NearFr_RFT1_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_RFT1_mix, 25,
        Model_TranslationEngine64_B.RFT1_mix_e.Size,
        Model_TranslationEngine64_B.RFT1_mix_e.Value, 1,
        NearFr_RFT1_mix_Dependencies
    },

    {                                  /* '<S1375>/Tune Variable4' */
        "NearFr_LSI1_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_LSI1_mix, 25,
        Model_TranslationEngine64_B.LSI1_mix_p.Size,
        Model_TranslationEngine64_B.LSI1_mix_p.Value, 1,
        NearFr_LSI1_mix_Dependencies
    },

    {                                  /* '<S1375>/Tune Variable5' */
        "NearFr_LST1_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_LST1_mix, 25,
        Model_TranslationEngine64_B.LST1_mix_m.Size,
        Model_TranslationEngine64_B.LST1_mix_m.Value, 1,
        NearFr_LST1_mix_Dependencies
    },

    {                                  /* '<S1375>/Tune Variable7' */
        "NearFr_RSI1_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_RSI1_mix, 25,
        Model_TranslationEngine64_B.RSI1_mix_m.Size,
        Model_TranslationEngine64_B.RSI1_mix_m.Value, 1,
        NearFr_RSI1_mix_Dependencies
    },

    {                                  /* '<S1375>/Tune Variable6' */
        "NearFr_RST1_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_RST1_mix, 25,
        Model_TranslationEngine64_B.RST1_mix_p.Size,
        Model_TranslationEngine64_B.RST1_mix_p.Value, 1,
        NearFr_RST1_mix_Dependencies
    },

    {                                  /* '<S1375>/Tune Variable8' */
        "NearFr_LCI1_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_LCI1_mix, 25,
        Model_TranslationEngine64_B.LCI1_mix_i.Size,
        Model_TranslationEngine64_B.LCI1_mix_i.Value, 1,
        NearFr_LCI1_mix_Dependencies
    },

    {                                  /* '<S1375>/Tune Variable9' */
        "NearFr_LCT1_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_LCT1_mix, 25,
        Model_TranslationEngine64_B.LCT1_mix_l.Size,
        Model_TranslationEngine64_B.LCT1_mix_l.Value, 1,
        NearFr_LCT1_mix_Dependencies
    },

    {                                  /* '<S1375>/Tune Variable10' */
        "NearFr_RCI1_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_RCI1_mix, 25,
        Model_TranslationEngine64_B.RCI1_mix_k.Size,
        Model_TranslationEngine64_B.RCI1_mix_k.Value, 1,
        NearFr_RCI1_mix_Dependencies
    },

    {                                  /* '<S1375>/Tune Variable11' */
        "NearFr_RCT1_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_RCT1_mix, 25,
        Model_TranslationEngine64_B.RCT1_mix_n.Size,
        Model_TranslationEngine64_B.RCT1_mix_n.Value, 1,
        NearFr_RCT1_mix_Dependencies
    },

    {                                  /* '<S1376>/Tune Variable' */
        "NearFr_nv0l_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_nv0l_mix, 25,
        Model_TranslationEngine64_B.nv0l_mix_i.Size,
        Model_TranslationEngine64_B.nv0l_mix_i.Value, 1,
        NearFr_nv0l_mix_Dependencies
    },

    {                                  /* '<S1376>/Tune Variable1' */
        "NearFr_nv0r_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_nv0r_mix, 25,
        Model_TranslationEngine64_B.nv0r_mix_j.Size,
        Model_TranslationEngine64_B.nv0r_mix_j.Value, 1,
        NearFr_nv0r_mix_Dependencies
    },

    {                                  /* '<S1376>/Tune Variable2' */
        "NearFr_nv1l_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_nv1l_mix, 25,
        Model_TranslationEngine64_B.nv1l_mix_j.Size,
        Model_TranslationEngine64_B.nv1l_mix_j.Value, 1,
        NearFr_nv1l_mix_Dependencies
    },

    {                                  /* '<S1376>/Tune Variable3' */
        "NearFr_nv1r_mix", 0, TSS_SINGLE, 0, sizeof(real32_T), 25,
        {
            5,
            5,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearFr_nv1r_mix, 25,
        Model_TranslationEngine64_B.nv1r_mix_n.Size,
        Model_TranslationEngine64_B.nv1r_mix_n.Value, 1,
        NearFr_nv1r_mix_Dependencies
    },

    {                                  /* '<S1380>/Tune Variable' */
        "NearRampDbPerSample", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearRampDbPerSample, 1,
        Model_TranslationEngine64_B.RampDbPerSample.Size,
        &Model_TranslationEngine64_B.RampDbPerSample.Value, 1,
        NearRampDbPerSample_Dependencies
    },

    {                                  /* '<S1385>/HpfCutOffTuneVar' */
        "NearHpfCutoffFrequency", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearHpfCutoffFrequency, 1,
        Model_TranslationEngine64_B.HpfCutoffFrequency.Size,
        &Model_TranslationEngine64_B.HpfCutoffFrequency.Value, 1,
        NearHpfCutoffFrequency_Dependencies
    },

    {                                  /* '<S1385>/HpfOrderTuneVar' */
        "NearHpfFilterOrder", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearHpfFilterOrder, 1,
        Model_TranslationEngine64_B.HpfFilterOrder.Size,
        &Model_TranslationEngine64_B.HpfFilterOrder.Value, 1,
        NearHpfFilterOrder_Dependencies
    },

    {                                  /* '<S1401>/Tune Variable2' */
        "NearLevelDetectPreEmphasisShelfFiltersosCoefficients", 0, TSS_DOUBLE, 0,
        sizeof(real_T), 12,
        {
            2,
            6,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearLevelDetectPreEmphasisShelfFiltersosCoefficients,
        12, Model_TranslationEngine64_B.sosCoefficients_ih.Size,
        Model_TranslationEngine64_B.sosCoefficients_ih.Value, 1,
        NearLevelDetectPreEmphasisShelfFiltersosCoefficients_Dependencies
    },

    {                                  /* '<S1401>/Tune Variable1' */
        "NearLevelDetectPreEmphasisShelfFilternumStages", 0, TSS_DOUBLE, 0,
        sizeof(real_T), 2,
        {
            2,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearLevelDetectPreEmphasisShelfFilternumStages, 2,
        Model_TranslationEngine64_B.numStages_cf.Size,
        Model_TranslationEngine64_B.numStages_cf.Value, 1,
        NearLevelDetectPreEmphasisShelfFilternumStages_Dependencies
    },

    {                                  /* '<S1400>/Tune Variable' */
        "NearLevelDetectSysMaxDbspl", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearLevelDetectSysMaxDbspl, 1,
        Model_TranslationEngine64_B.SysMaxDbspl.Size,
        &Model_TranslationEngine64_B.SysMaxDbspl.Value, 1,
        NearLevelDetectSysMaxDbspl_Dependencies
    },

    {                                  /* '<S1409>/Tune Variable' */
        "NearAnn1LevelDetectFastDecayDbPers", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn1LevelDetectFastDecayDbPers, 1,
        Model_TranslationEngine64_B.FastDecayDbPers.Size,
        &Model_TranslationEngine64_B.FastDecayDbPers.Value, 1,
        NearAnn1LevelDetectFastDecayDbPers_Dependencies
    },

    {                                  /* '<S1410>/Tune Variable' */
        "NearAnn1LevelDetectHoldMarginDb", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn1LevelDetectHoldMarginDb, 1,
        Model_TranslationEngine64_B.HoldMarginDb.Size,
        &Model_TranslationEngine64_B.HoldMarginDb.Value, 1,
        NearAnn1LevelDetectHoldMarginDb_Dependencies
    },

    {                                  /* '<S1411>/Tune Variable' */
        "NearAnn1LevelDetectHoldTimes", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn1LevelDetectHoldTimes, 1,
        Model_TranslationEngine64_B.HoldTimes.Size,
        &Model_TranslationEngine64_B.HoldTimes.Value, 1,
        NearAnn1LevelDetectHoldTimes_Dependencies
    },

    {                                  /* '<S1412>/Tune Variable' */
        "NearAnn1LevelDetectMaxVolumeDb", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn1LevelDetectMaxVolumeDb, 1,
        Model_TranslationEngine64_B.MaxVolumeDb.Size,
        &Model_TranslationEngine64_B.MaxVolumeDb.Value, 1,
        NearAnn1LevelDetectMaxVolumeDb_Dependencies
    },

    {                                  /* '<S1413>/Tune Variable' */
        "NearAnn1LevelDetectMinVolumeDb", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn1LevelDetectMinVolumeDb, 1,
        Model_TranslationEngine64_B.MinVolumeDb.Size,
        &Model_TranslationEngine64_B.MinVolumeDb.Value, 1,
        NearAnn1LevelDetectMinVolumeDb_Dependencies
    },

    {                                  /* '<S1414>/Tune Variable' */
        "NearAnn1LevelDetectSlowDecayDbPers", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn1LevelDetectSlowDecayDbPers, 1,
        Model_TranslationEngine64_B.SlowDecayDbPers.Size,
        &Model_TranslationEngine64_B.SlowDecayDbPers.Value, 1,
        NearAnn1LevelDetectSlowDecayDbPers_Dependencies
    },

    {                                  /* '<S1435>/Tune Variable' */
        "NearAnn2LevelDetectFastDecayDbPers", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn2LevelDetectFastDecayDbPers, 1,
        Model_TranslationEngine64_B.FastDecayDbPers_i.Size,
        &Model_TranslationEngine64_B.FastDecayDbPers_i.Value, 1,
        NearAnn2LevelDetectFastDecayDbPers_Dependencies
    },

    {                                  /* '<S1436>/Tune Variable' */
        "NearAnn2LevelDetectHoldMarginDb", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn2LevelDetectHoldMarginDb, 1,
        Model_TranslationEngine64_B.HoldMarginDb_i.Size,
        &Model_TranslationEngine64_B.HoldMarginDb_i.Value, 1,
        NearAnn2LevelDetectHoldMarginDb_Dependencies
    },

    {                                  /* '<S1437>/Tune Variable' */
        "NearAnn2LevelDetectHoldTimes", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn2LevelDetectHoldTimes, 1,
        Model_TranslationEngine64_B.HoldTimes_c.Size,
        &Model_TranslationEngine64_B.HoldTimes_c.Value, 1,
        NearAnn2LevelDetectHoldTimes_Dependencies
    },

    {                                  /* '<S1438>/Tune Variable' */
        "NearAnn2LevelDetectMaxVolumeDb", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn2LevelDetectMaxVolumeDb, 1,
        Model_TranslationEngine64_B.MaxVolumeDb_f.Size,
        &Model_TranslationEngine64_B.MaxVolumeDb_f.Value, 1,
        NearAnn2LevelDetectMaxVolumeDb_Dependencies
    },

    {                                  /* '<S1439>/Tune Variable' */
        "NearAnn2LevelDetectMinVolumeDb", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn2LevelDetectMinVolumeDb, 1,
        Model_TranslationEngine64_B.MinVolumeDb_m.Size,
        &Model_TranslationEngine64_B.MinVolumeDb_m.Value, 1,
        NearAnn2LevelDetectMinVolumeDb_Dependencies
    },

    {                                  /* '<S1440>/Tune Variable' */
        "NearAnn2LevelDetectSlowDecayDbPers", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn2LevelDetectSlowDecayDbPers, 1,
        Model_TranslationEngine64_B.SlowDecayDbPers_f.Size,
        &Model_TranslationEngine64_B.SlowDecayDbPers_f.Value, 1,
        NearAnn2LevelDetectSlowDecayDbPers_Dependencies
    },

    {                                  /* '<S1461>/Tune Variable' */
        "NearAnn3LevelDetectFastDecayDbPers", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn3LevelDetectFastDecayDbPers, 1,
        Model_TranslationEngine64_B.FastDecayDbPers_h.Size,
        &Model_TranslationEngine64_B.FastDecayDbPers_h.Value, 1,
        NearAnn3LevelDetectFastDecayDbPers_Dependencies
    },

    {                                  /* '<S1462>/Tune Variable' */
        "NearAnn3LevelDetectHoldMarginDb", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn3LevelDetectHoldMarginDb, 1,
        Model_TranslationEngine64_B.HoldMarginDb_p.Size,
        &Model_TranslationEngine64_B.HoldMarginDb_p.Value, 1,
        NearAnn3LevelDetectHoldMarginDb_Dependencies
    },

    {                                  /* '<S1463>/Tune Variable' */
        "NearAnn3LevelDetectHoldTimes", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn3LevelDetectHoldTimes, 1,
        Model_TranslationEngine64_B.HoldTimes_j.Size,
        &Model_TranslationEngine64_B.HoldTimes_j.Value, 1,
        NearAnn3LevelDetectHoldTimes_Dependencies
    },

    {                                  /* '<S1464>/Tune Variable' */
        "NearAnn3LevelDetectMaxVolumeDb", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn3LevelDetectMaxVolumeDb, 1,
        Model_TranslationEngine64_B.MaxVolumeDb_i.Size,
        &Model_TranslationEngine64_B.MaxVolumeDb_i.Value, 1,
        NearAnn3LevelDetectMaxVolumeDb_Dependencies
    },

    {                                  /* '<S1465>/Tune Variable' */
        "NearAnn3LevelDetectMinVolumeDb", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn3LevelDetectMinVolumeDb, 1,
        Model_TranslationEngine64_B.MinVolumeDb_g.Size,
        &Model_TranslationEngine64_B.MinVolumeDb_g.Value, 1,
        NearAnn3LevelDetectMinVolumeDb_Dependencies
    },

    {                                  /* '<S1466>/Tune Variable' */
        "NearAnn3LevelDetectSlowDecayDbPers", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn3LevelDetectSlowDecayDbPers, 1,
        Model_TranslationEngine64_B.SlowDecayDbPers_l.Size,
        &Model_TranslationEngine64_B.SlowDecayDbPers_l.Value, 1,
        NearAnn3LevelDetectSlowDecayDbPers_Dependencies
    },

    {                                  /* '<S1487>/Tune Variable' */
        "NearAnn4LevelDetectFastDecayDbPers", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn4LevelDetectFastDecayDbPers, 1,
        Model_TranslationEngine64_B.FastDecayDbPers_p.Size,
        &Model_TranslationEngine64_B.FastDecayDbPers_p.Value, 1,
        NearAnn4LevelDetectFastDecayDbPers_Dependencies
    },

    {                                  /* '<S1488>/Tune Variable' */
        "NearAnn4LevelDetectHoldMarginDb", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn4LevelDetectHoldMarginDb, 1,
        Model_TranslationEngine64_B.HoldMarginDb_e.Size,
        &Model_TranslationEngine64_B.HoldMarginDb_e.Value, 1,
        NearAnn4LevelDetectHoldMarginDb_Dependencies
    },

    {                                  /* '<S1489>/Tune Variable' */
        "NearAnn4LevelDetectHoldTimes", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn4LevelDetectHoldTimes, 1,
        Model_TranslationEngine64_B.HoldTimes_k.Size,
        &Model_TranslationEngine64_B.HoldTimes_k.Value, 1,
        NearAnn4LevelDetectHoldTimes_Dependencies
    },

    {                                  /* '<S1490>/Tune Variable' */
        "NearAnn4LevelDetectMaxVolumeDb", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn4LevelDetectMaxVolumeDb, 1,
        Model_TranslationEngine64_B.MaxVolumeDb_k.Size,
        &Model_TranslationEngine64_B.MaxVolumeDb_k.Value, 1,
        NearAnn4LevelDetectMaxVolumeDb_Dependencies
    },

    {                                  /* '<S1491>/Tune Variable' */
        "NearAnn4LevelDetectMinVolumeDb", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn4LevelDetectMinVolumeDb, 1,
        Model_TranslationEngine64_B.MinVolumeDb_a.Size,
        &Model_TranslationEngine64_B.MinVolumeDb_a.Value, 1,
        NearAnn4LevelDetectMinVolumeDb_Dependencies
    },

    {                                  /* '<S1492>/Tune Variable' */
        "NearAnn4LevelDetectSlowDecayDbPers", 0, TSS_SINGLE, 0, sizeof(real32_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn4LevelDetectSlowDecayDbPers, 1,
        Model_TranslationEngine64_B.SlowDecayDbPers_k.Size,
        &Model_TranslationEngine64_B.SlowDecayDbPers_k.Value, 1,
        NearAnn4LevelDetectSlowDecayDbPers_Dependencies
    },

    {                                  /* '<S1517>/Tune Variable' */
        "NearAnn1Ann1NonEntGainCalcVncThresh", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn1Ann1NonEntGainCalcVncThresh, 1,
        Model_TranslationEngine64_B.VncThresh.Size,
        &Model_TranslationEngine64_B.VncThresh.Value, 1,
        NearAnn1Ann1NonEntGainCalcVncThresh_Dependencies
    },

    {                                  /* '<S1518>/Tune Variable' */
        "NearAnn1Ann1NonEntGainCalcVncSlope", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn1Ann1NonEntGainCalcVncSlope, 1,
        Model_TranslationEngine64_B.VncSlope.Size,
        &Model_TranslationEngine64_B.VncSlope.Value, 1,
        NearAnn1Ann1NonEntGainCalcVncSlope_Dependencies
    },

    {                                  /* '<S1519>/Tune Variable' */
        "NearAnn1Ann1NonEntGainCalcMaxBoost", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn1Ann1NonEntGainCalcMaxBoost, 1,
        Model_TranslationEngine64_B.MaxBoost.Size,
        &Model_TranslationEngine64_B.MaxBoost.Value, 1,
        NearAnn1Ann1NonEntGainCalcMaxBoost_Dependencies
    },

    {                                  /* '<S1520>/Tune Variable' */
        "NearAnn1Ann1NonEntGainCalcNoiseOverRide", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn1Ann1NonEntGainCalcNoiseOverRide, 1,
        Model_TranslationEngine64_B.NoiseOverRide.Size,
        &Model_TranslationEngine64_B.NoiseOverRide.Value, 1,
        NearAnn1Ann1NonEntGainCalcNoiseOverRide_Dependencies
    },

    {                                  /* '<S1521>/Tune Variable' */
        "NearAnn1Ann1NonEntGainCalcNoiseOverRideFlag", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn1Ann1NonEntGainCalcNoiseOverRideFlag, 1,
        Model_TranslationEngine64_B.NoiseOverRideFlag.Size,
        &Model_TranslationEngine64_B.NoiseOverRideFlag.Value, 1,
        NearAnn1Ann1NonEntGainCalcNoiseOverRideFlag_Dependencies
    },

    {                                  /* '<S1522>/Tune Variable' */
        "NearAnn1Ann1NonEntGainCalcBoostOverRide", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn1Ann1NonEntGainCalcBoostOverRide, 1,
        Model_TranslationEngine64_B.BoostOverRide.Size,
        &Model_TranslationEngine64_B.BoostOverRide.Value, 1,
        NearAnn1Ann1NonEntGainCalcBoostOverRide_Dependencies
    },

    {                                  /* '<S1523>/Tune Variable' */
        "NearAnn1Ann1NonEntGainCalcBoostOverRideFlag", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn1Ann1NonEntGainCalcBoostOverRideFlag, 1,
        Model_TranslationEngine64_B.BoostOverRideFlag.Size,
        &Model_TranslationEngine64_B.BoostOverRideFlag.Value, 1,
        NearAnn1Ann1NonEntGainCalcBoostOverRideFlag_Dependencies
    },

    {                                  /* '<S1524>/Tune Variable' */
        "NearAnn1Ann1NonEntGainCalcVncEnableTuneVar", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn1Ann1NonEntGainCalcVncEnableTuneVar, 1,
        Model_TranslationEngine64_B.VncEnableTuneVar.Size,
        &Model_TranslationEngine64_B.VncEnableTuneVar.Value, 1,
        NearAnn1Ann1NonEntGainCalcVncEnableTuneVar_Dependencies
    },

    {                                  /* '<S1525>/tuneVARTau' */
        "NearAnn1Ann1NonEntGainCalcTau", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn1Ann1NonEntGainCalcTau, 1,
        Model_TranslationEngine64_B.Tau.Size,
        &Model_TranslationEngine64_B.Tau.Value, 1,
        NearAnn1Ann1NonEntGainCalcTau_Dependencies
    },

    {                                  /* '<S1562>/Tune Variable' */
        "NearAnn1Ann1NonEntGainCalcMinVncSignal", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn1Ann1NonEntGainCalcMinVncSignal, 1,
        Model_TranslationEngine64_B.MinVncSignal.Size,
        &Model_TranslationEngine64_B.MinVncSignal.Value, 1,
        NearAnn1Ann1NonEntGainCalcMinVncSignal_Dependencies
    },

    {                                  /* '<S1563>/Tune Variable' */
        "NearAnn1Ann1NonEntGainCalcMaxSpl", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn1Ann1NonEntGainCalcMaxSpl, 1,
        Model_TranslationEngine64_B.MaxSpl.Size,
        &Model_TranslationEngine64_B.MaxSpl.Value, 1,
        NearAnn1Ann1NonEntGainCalcMaxSpl_Dependencies
    },

    {                                  /* '<S1573>/tuneVARTau' */
        "NearAnn1Ann1NonEntVncAppliedTau", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn1Ann1NonEntVncAppliedTau, 1,
        Model_TranslationEngine64_B.Tau_k.Size,
        &Model_TranslationEngine64_B.Tau_k.Value, 1,
        NearAnn1Ann1NonEntVncAppliedTau_Dependencies
    },

    {                                  /* '<S1578>/Tune Variable' */
        "NearAnn1Ann1MuteRampTime", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn1Ann1MuteRampTime, 1,
        Model_TranslationEngine64_B.RampTime.Size,
        &Model_TranslationEngine64_B.RampTime.Value, 1,
        NearAnn1Ann1MuteRampTime_Dependencies
    },

    {                                  /* '<S1516>/TuneVarVolumeTable' */
        "NearAnn1Ann1VolumeTable", 0, TSS_DOUBLE, 0, sizeof(real_T), 32,
        {
            16,
            2,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn1Ann1VolumeTable, 16,
        Model_TranslationEngine64_B.Table_l.Size,
        Model_TranslationEngine64_B.Table_l.Value, 1,
        NearAnn1Ann1VolumeTable_Dependencies
    },

    {                                  /* '<S1584>/Tune Variable' */
        "NearAnn1Ann1VolumeRampRate", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn1Ann1VolumeRampRate, 1,
        Model_TranslationEngine64_B.RampRate.Size,
        &Model_TranslationEngine64_B.RampRate.Value, 1,
        NearAnn1Ann1VolumeRampRate_Dependencies
    },

    {                                  /* '<S1585>/Tune Variable' */
        "NearAnn1Ann1VolumeRampTime", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn1Ann1VolumeRampTime, 1,
        Model_TranslationEngine64_B.RampTime_g.Size,
        &Model_TranslationEngine64_B.RampTime_g.Value, 1,
        NearAnn1Ann1VolumeRampTime_Dependencies
    },

    {                                  /* '<S1600>/Tune Variable' */
        "NearAnn2Ann2NonEntGainCalcVncThresh", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn2Ann2NonEntGainCalcVncThresh, 1,
        Model_TranslationEngine64_B.VncThresh_g.Size,
        &Model_TranslationEngine64_B.VncThresh_g.Value, 1,
        NearAnn2Ann2NonEntGainCalcVncThresh_Dependencies
    },

    {                                  /* '<S1601>/Tune Variable' */
        "NearAnn2Ann2NonEntGainCalcVncSlope", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn2Ann2NonEntGainCalcVncSlope, 1,
        Model_TranslationEngine64_B.VncSlope_l.Size,
        &Model_TranslationEngine64_B.VncSlope_l.Value, 1,
        NearAnn2Ann2NonEntGainCalcVncSlope_Dependencies
    },

    {                                  /* '<S1602>/Tune Variable' */
        "NearAnn2Ann2NonEntGainCalcMaxBoost", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn2Ann2NonEntGainCalcMaxBoost, 1,
        Model_TranslationEngine64_B.MaxBoost_j.Size,
        &Model_TranslationEngine64_B.MaxBoost_j.Value, 1,
        NearAnn2Ann2NonEntGainCalcMaxBoost_Dependencies
    },

    {                                  /* '<S1603>/Tune Variable' */
        "NearAnn2Ann2NonEntGainCalcNoiseOverRide", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn2Ann2NonEntGainCalcNoiseOverRide, 1,
        Model_TranslationEngine64_B.NoiseOverRide_k.Size,
        &Model_TranslationEngine64_B.NoiseOverRide_k.Value, 1,
        NearAnn2Ann2NonEntGainCalcNoiseOverRide_Dependencies
    },

    {                                  /* '<S1604>/Tune Variable' */
        "NearAnn2Ann2NonEntGainCalcNoiseOverRideFlag", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn2Ann2NonEntGainCalcNoiseOverRideFlag, 1,
        Model_TranslationEngine64_B.NoiseOverRideFlag_h.Size,
        &Model_TranslationEngine64_B.NoiseOverRideFlag_h.Value, 1,
        NearAnn2Ann2NonEntGainCalcNoiseOverRideFlag_Dependencies
    },

    {                                  /* '<S1605>/Tune Variable' */
        "NearAnn2Ann2NonEntGainCalcBoostOverRide", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn2Ann2NonEntGainCalcBoostOverRide, 1,
        Model_TranslationEngine64_B.BoostOverRide_n.Size,
        &Model_TranslationEngine64_B.BoostOverRide_n.Value, 1,
        NearAnn2Ann2NonEntGainCalcBoostOverRide_Dependencies
    },

    {                                  /* '<S1606>/Tune Variable' */
        "NearAnn2Ann2NonEntGainCalcBoostOverRideFlag", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn2Ann2NonEntGainCalcBoostOverRideFlag, 1,
        Model_TranslationEngine64_B.BoostOverRideFlag_d.Size,
        &Model_TranslationEngine64_B.BoostOverRideFlag_d.Value, 1,
        NearAnn2Ann2NonEntGainCalcBoostOverRideFlag_Dependencies
    },

    {                                  /* '<S1607>/Tune Variable' */
        "NearAnn2Ann2NonEntGainCalcVncEnableTuneVar", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn2Ann2NonEntGainCalcVncEnableTuneVar, 1,
        Model_TranslationEngine64_B.VncEnableTuneVar_j.Size,
        &Model_TranslationEngine64_B.VncEnableTuneVar_j.Value, 1,
        NearAnn2Ann2NonEntGainCalcVncEnableTuneVar_Dependencies
    },

    {                                  /* '<S1608>/tuneVARTau' */
        "NearAnn2Ann2NonEntGainCalcTau", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn2Ann2NonEntGainCalcTau, 1,
        Model_TranslationEngine64_B.Tau_p.Size,
        &Model_TranslationEngine64_B.Tau_p.Value, 1,
        NearAnn2Ann2NonEntGainCalcTau_Dependencies
    },

    {                                  /* '<S1645>/Tune Variable' */
        "NearAnn2Ann2NonEntGainCalcMinVncSignal", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn2Ann2NonEntGainCalcMinVncSignal, 1,
        Model_TranslationEngine64_B.MinVncSignal_d.Size,
        &Model_TranslationEngine64_B.MinVncSignal_d.Value, 1,
        NearAnn2Ann2NonEntGainCalcMinVncSignal_Dependencies
    },

    {                                  /* '<S1646>/Tune Variable' */
        "NearAnn2Ann2NonEntGainCalcMaxSpl", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn2Ann2NonEntGainCalcMaxSpl, 1,
        Model_TranslationEngine64_B.MaxSpl_d.Size,
        &Model_TranslationEngine64_B.MaxSpl_d.Value, 1,
        NearAnn2Ann2NonEntGainCalcMaxSpl_Dependencies
    },

    {                                  /* '<S1656>/tuneVARTau' */
        "NearAnn2Ann2NonEntVncAppliedTau", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn2Ann2NonEntVncAppliedTau, 1,
        Model_TranslationEngine64_B.Tau_gb.Size,
        &Model_TranslationEngine64_B.Tau_gb.Value, 1,
        NearAnn2Ann2NonEntVncAppliedTau_Dependencies
    },

    {                                  /* '<S1661>/Tune Variable' */
        "NearAnn2Ann2MuteRampTime", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn2Ann2MuteRampTime, 1,
        Model_TranslationEngine64_B.RampTime_n.Size,
        &Model_TranslationEngine64_B.RampTime_n.Value, 1,
        NearAnn2Ann2MuteRampTime_Dependencies
    },

    {                                  /* '<S1599>/TuneVarVolumeTable' */
        "NearAnn2Ann2VolumeTable", 0, TSS_DOUBLE, 0, sizeof(real_T), 32,
        {
            16,
            2,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn2Ann2VolumeTable, 16,
        Model_TranslationEngine64_B.Table_o.Size,
        Model_TranslationEngine64_B.Table_o.Value, 1,
        NearAnn2Ann2VolumeTable_Dependencies
    },

    {                                  /* '<S1667>/Tune Variable' */
        "NearAnn2Ann2VolumeRampRate", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn2Ann2VolumeRampRate, 1,
        Model_TranslationEngine64_B.RampRate_o.Size,
        &Model_TranslationEngine64_B.RampRate_o.Value, 1,
        NearAnn2Ann2VolumeRampRate_Dependencies
    },

    {                                  /* '<S1668>/Tune Variable' */
        "NearAnn2Ann2VolumeRampTime", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn2Ann2VolumeRampTime, 1,
        Model_TranslationEngine64_B.RampTime_b.Size,
        &Model_TranslationEngine64_B.RampTime_b.Value, 1,
        NearAnn2Ann2VolumeRampTime_Dependencies
    },

    {                                  /* '<S1683>/Tune Variable' */
        "NearAnn3Ann3NonEntGainCalcVncThresh", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn3Ann3NonEntGainCalcVncThresh, 1,
        Model_TranslationEngine64_B.VncThresh_h.Size,
        &Model_TranslationEngine64_B.VncThresh_h.Value, 1,
        NearAnn3Ann3NonEntGainCalcVncThresh_Dependencies
    },

    {                                  /* '<S1684>/Tune Variable' */
        "NearAnn3Ann3NonEntGainCalcVncSlope", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn3Ann3NonEntGainCalcVncSlope, 1,
        Model_TranslationEngine64_B.VncSlope_c.Size,
        &Model_TranslationEngine64_B.VncSlope_c.Value, 1,
        NearAnn3Ann3NonEntGainCalcVncSlope_Dependencies
    },

    {                                  /* '<S1685>/Tune Variable' */
        "NearAnn3Ann3NonEntGainCalcMaxBoost", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn3Ann3NonEntGainCalcMaxBoost, 1,
        Model_TranslationEngine64_B.MaxBoost_k.Size,
        &Model_TranslationEngine64_B.MaxBoost_k.Value, 1,
        NearAnn3Ann3NonEntGainCalcMaxBoost_Dependencies
    },

    {                                  /* '<S1686>/Tune Variable' */
        "NearAnn3Ann3NonEntGainCalcNoiseOverRide", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn3Ann3NonEntGainCalcNoiseOverRide, 1,
        Model_TranslationEngine64_B.NoiseOverRide_e.Size,
        &Model_TranslationEngine64_B.NoiseOverRide_e.Value, 1,
        NearAnn3Ann3NonEntGainCalcNoiseOverRide_Dependencies
    },

    {                                  /* '<S1687>/Tune Variable' */
        "NearAnn3Ann3NonEntGainCalcNoiseOverRideFlag", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn3Ann3NonEntGainCalcNoiseOverRideFlag, 1,
        Model_TranslationEngine64_B.NoiseOverRideFlag_e.Size,
        &Model_TranslationEngine64_B.NoiseOverRideFlag_e.Value, 1,
        NearAnn3Ann3NonEntGainCalcNoiseOverRideFlag_Dependencies
    },

    {                                  /* '<S1688>/Tune Variable' */
        "NearAnn3Ann3NonEntGainCalcBoostOverRide", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn3Ann3NonEntGainCalcBoostOverRide, 1,
        Model_TranslationEngine64_B.BoostOverRide_e.Size,
        &Model_TranslationEngine64_B.BoostOverRide_e.Value, 1,
        NearAnn3Ann3NonEntGainCalcBoostOverRide_Dependencies
    },

    {                                  /* '<S1689>/Tune Variable' */
        "NearAnn3Ann3NonEntGainCalcBoostOverRideFlag", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn3Ann3NonEntGainCalcBoostOverRideFlag, 1,
        Model_TranslationEngine64_B.BoostOverRideFlag_c.Size,
        &Model_TranslationEngine64_B.BoostOverRideFlag_c.Value, 1,
        NearAnn3Ann3NonEntGainCalcBoostOverRideFlag_Dependencies
    },

    {                                  /* '<S1690>/Tune Variable' */
        "NearAnn3Ann3NonEntGainCalcVncEnableTuneVar", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn3Ann3NonEntGainCalcVncEnableTuneVar, 1,
        Model_TranslationEngine64_B.VncEnableTuneVar_i.Size,
        &Model_TranslationEngine64_B.VncEnableTuneVar_i.Value, 1,
        NearAnn3Ann3NonEntGainCalcVncEnableTuneVar_Dependencies
    },

    {                                  /* '<S1691>/tuneVARTau' */
        "NearAnn3Ann3NonEntGainCalcTau", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn3Ann3NonEntGainCalcTau, 1,
        Model_TranslationEngine64_B.Tau_c.Size,
        &Model_TranslationEngine64_B.Tau_c.Value, 1,
        NearAnn3Ann3NonEntGainCalcTau_Dependencies
    },

    {                                  /* '<S1728>/Tune Variable' */
        "NearAnn3Ann3NonEntGainCalcMinVncSignal", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn3Ann3NonEntGainCalcMinVncSignal, 1,
        Model_TranslationEngine64_B.MinVncSignal_e.Size,
        &Model_TranslationEngine64_B.MinVncSignal_e.Value, 1,
        NearAnn3Ann3NonEntGainCalcMinVncSignal_Dependencies
    },

    {                                  /* '<S1729>/Tune Variable' */
        "NearAnn3Ann3NonEntGainCalcMaxSpl", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn3Ann3NonEntGainCalcMaxSpl, 1,
        Model_TranslationEngine64_B.MaxSpl_l.Size,
        &Model_TranslationEngine64_B.MaxSpl_l.Value, 1,
        NearAnn3Ann3NonEntGainCalcMaxSpl_Dependencies
    },

    {                                  /* '<S1739>/tuneVARTau' */
        "NearAnn3Ann3NonEntVncAppliedTau", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn3Ann3NonEntVncAppliedTau, 1,
        Model_TranslationEngine64_B.Tau_j.Size,
        &Model_TranslationEngine64_B.Tau_j.Value, 1,
        NearAnn3Ann3NonEntVncAppliedTau_Dependencies
    },

    {                                  /* '<S1744>/Tune Variable' */
        "NearAnn3Ann3MuteRampTime", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn3Ann3MuteRampTime, 1,
        Model_TranslationEngine64_B.RampTime_j.Size,
        &Model_TranslationEngine64_B.RampTime_j.Value, 1,
        NearAnn3Ann3MuteRampTime_Dependencies
    },

    {                                  /* '<S1682>/TuneVarVolumeTable' */
        "NearAnn3Ann3VolumeTable", 0, TSS_DOUBLE, 0, sizeof(real_T), 32,
        {
            16,
            2,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn3Ann3VolumeTable, 16,
        Model_TranslationEngine64_B.Table_a.Size,
        Model_TranslationEngine64_B.Table_a.Value, 1,
        NearAnn3Ann3VolumeTable_Dependencies
    },

    {                                  /* '<S1750>/Tune Variable' */
        "NearAnn3Ann3VolumeRampRate", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn3Ann3VolumeRampRate, 1,
        Model_TranslationEngine64_B.RampRate_b.Size,
        &Model_TranslationEngine64_B.RampRate_b.Value, 1,
        NearAnn3Ann3VolumeRampRate_Dependencies
    },

    {                                  /* '<S1751>/Tune Variable' */
        "NearAnn3Ann3VolumeRampTime", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn3Ann3VolumeRampTime, 1,
        Model_TranslationEngine64_B.RampTime_h.Size,
        &Model_TranslationEngine64_B.RampTime_h.Value, 1,
        NearAnn3Ann3VolumeRampTime_Dependencies
    },

    {                                  /* '<S1766>/Tune Variable' */
        "NearAnn4Ann4NonEntGainCalcVncThresh", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn4Ann4NonEntGainCalcVncThresh, 1,
        Model_TranslationEngine64_B.VncThresh_a.Size,
        &Model_TranslationEngine64_B.VncThresh_a.Value, 1,
        NearAnn4Ann4NonEntGainCalcVncThresh_Dependencies
    },

    {                                  /* '<S1767>/Tune Variable' */
        "NearAnn4Ann4NonEntGainCalcVncSlope", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn4Ann4NonEntGainCalcVncSlope, 1,
        Model_TranslationEngine64_B.VncSlope_j.Size,
        &Model_TranslationEngine64_B.VncSlope_j.Value, 1,
        NearAnn4Ann4NonEntGainCalcVncSlope_Dependencies
    },

    {                                  /* '<S1768>/Tune Variable' */
        "NearAnn4Ann4NonEntGainCalcMaxBoost", 0, TSS_DOUBLE, 0, sizeof(real_T),
        1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn4Ann4NonEntGainCalcMaxBoost, 1,
        Model_TranslationEngine64_B.MaxBoost_a.Size,
        &Model_TranslationEngine64_B.MaxBoost_a.Value, 1,
        NearAnn4Ann4NonEntGainCalcMaxBoost_Dependencies
    },

    {                                  /* '<S1769>/Tune Variable' */
        "NearAnn4Ann4NonEntGainCalcNoiseOverRide", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn4Ann4NonEntGainCalcNoiseOverRide, 1,
        Model_TranslationEngine64_B.NoiseOverRide_b.Size,
        &Model_TranslationEngine64_B.NoiseOverRide_b.Value, 1,
        NearAnn4Ann4NonEntGainCalcNoiseOverRide_Dependencies
    },

    {                                  /* '<S1770>/Tune Variable' */
        "NearAnn4Ann4NonEntGainCalcNoiseOverRideFlag", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn4Ann4NonEntGainCalcNoiseOverRideFlag, 1,
        Model_TranslationEngine64_B.NoiseOverRideFlag_l.Size,
        &Model_TranslationEngine64_B.NoiseOverRideFlag_l.Value, 1,
        NearAnn4Ann4NonEntGainCalcNoiseOverRideFlag_Dependencies
    },

    {                                  /* '<S1771>/Tune Variable' */
        "NearAnn4Ann4NonEntGainCalcBoostOverRide", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn4Ann4NonEntGainCalcBoostOverRide, 1,
        Model_TranslationEngine64_B.BoostOverRide_o.Size,
        &Model_TranslationEngine64_B.BoostOverRide_o.Value, 1,
        NearAnn4Ann4NonEntGainCalcBoostOverRide_Dependencies
    },

    {                                  /* '<S1772>/Tune Variable' */
        "NearAnn4Ann4NonEntGainCalcBoostOverRideFlag", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn4Ann4NonEntGainCalcBoostOverRideFlag, 1,
        Model_TranslationEngine64_B.BoostOverRideFlag_f.Size,
        &Model_TranslationEngine64_B.BoostOverRideFlag_f.Value, 1,
        NearAnn4Ann4NonEntGainCalcBoostOverRideFlag_Dependencies
    },

    {                                  /* '<S1773>/Tune Variable' */
        "NearAnn4Ann4NonEntGainCalcVncEnableTuneVar", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn4Ann4NonEntGainCalcVncEnableTuneVar, 1,
        Model_TranslationEngine64_B.VncEnableTuneVar_f.Size,
        &Model_TranslationEngine64_B.VncEnableTuneVar_f.Value, 1,
        NearAnn4Ann4NonEntGainCalcVncEnableTuneVar_Dependencies
    },

    {                                  /* '<S1774>/tuneVARTau' */
        "NearAnn4Ann4NonEntGainCalcTau", 0, TSS_SINGLE, 0, sizeof(real32_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn4Ann4NonEntGainCalcTau, 1,
        Model_TranslationEngine64_B.Tau_g.Size,
        &Model_TranslationEngine64_B.Tau_g.Value, 1,
        NearAnn4Ann4NonEntGainCalcTau_Dependencies
    },

    {                                  /* '<S1811>/Tune Variable' */
        "NearAnn4Ann4NonEntGainCalcMinVncSignal", 0, TSS_DOUBLE, 0, sizeof
        (real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn4Ann4NonEntGainCalcMinVncSignal, 1,
        Model_TranslationEngine64_B.MinVncSignal_j.Size,
        &Model_TranslationEngine64_B.MinVncSignal_j.Value, 1,
        NearAnn4Ann4NonEntGainCalcMinVncSignal_Dependencies
    },

    {                                  /* '<S1812>/Tune Variable' */
        "NearAnn4Ann4NonEntGainCalcMaxSpl", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn4Ann4NonEntGainCalcMaxSpl, 1,
        Model_TranslationEngine64_B.MaxSpl_b.Size,
        &Model_TranslationEngine64_B.MaxSpl_b.Value, 1,
        NearAnn4Ann4NonEntGainCalcMaxSpl_Dependencies
    },

    {                                  /* '<S1822>/tuneVARTau' */
        "NearAnn4Ann4NonEntVncAppliedTau", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn4Ann4NonEntVncAppliedTau, 1,
        Model_TranslationEngine64_B.Tau_i.Size,
        &Model_TranslationEngine64_B.Tau_i.Value, 1,
        NearAnn4Ann4NonEntVncAppliedTau_Dependencies
    },

    {                                  /* '<S1827>/Tune Variable' */
        "NearAnn4Ann4MuteRampTime", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn4Ann4MuteRampTime, 1,
        Model_TranslationEngine64_B.RampTime_bw.Size,
        &Model_TranslationEngine64_B.RampTime_bw.Value, 1,
        NearAnn4Ann4MuteRampTime_Dependencies
    },

    {                                  /* '<S1765>/TuneVarVolumeTable' */
        "NearAnn4Ann4VolumeTable", 0, TSS_DOUBLE, 0, sizeof(real_T), 32,
        {
            16,
            2,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn4Ann4VolumeTable, 16,
        Model_TranslationEngine64_B.Table_n.Size,
        Model_TranslationEngine64_B.Table_n.Value, 1,
        NearAnn4Ann4VolumeTable_Dependencies
    },

    {                                  /* '<S1833>/Tune Variable' */
        "NearAnn4Ann4VolumeRampRate", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn4Ann4VolumeRampRate, 1,
        Model_TranslationEngine64_B.RampRate_l.Size,
        &Model_TranslationEngine64_B.RampRate_l.Value, 1,
        NearAnn4Ann4VolumeRampRate_Dependencies
    },

    {                                  /* '<S1834>/Tune Variable' */
        "NearAnn4Ann4VolumeRampTime", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_NearAnn4Ann4VolumeRampTime, 1,
        Model_TranslationEngine64_B.RampTime_h0.Size,
        &Model_TranslationEngine64_B.RampTime_h0.Value, 1,
        NearAnn4Ann4VolumeRampTime_Dependencies
    },

    {                                  /* '<S1892>/Tune Variable' */
        "TestRouterASDRouterEnableAux", 0, TSS_DOUBLE, 0, sizeof(real_T), 1,
        {
            1,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_TestRouterASDRouterEnableAux, 1,
        Model_TranslationEngine64_B.EnableAux.Size,
        &Model_TranslationEngine64_B.EnableAux.Value, 1,
        TestRouterASDRouterEnableAux_Dependencies
    },

    {                                  /* '<S1897>/Tune Variable' */
        "TestRouterASDRouterMainSelect", 0, TSS_DOUBLE, 0, sizeof(real_T), 24,
        {
            24,
            1,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_TestRouterASDRouterMainSelect, 24,
        Model_TranslationEngine64_B.MainSelect.Size,
        Model_TranslationEngine64_B.MainSelect.Value, 1,
        TestRouterASDRouterMainSelect_Dependencies
    },

    {                                  /* '<S1888>/Tune Variable' */
        "TestRouterAuxSelect", 0, TSS_DOUBLE, 0, sizeof(real_T), 24,
        {
            1,
            24,
            1,
            1,
            1,
            1,
            1,
        },
        0, 2, 0, DefValue_TestRouterAuxSelect, 24,
        Model_TranslationEngine64_B.AuxSelect.Size,
        Model_TranslationEngine64_B.AuxSelect.Value, 1,
        TestRouterAuxSelect_Dependencies
    },
};

// Share table in a public interface for use by top-model
void* Model_TranslationEngine64_tune_var_table = tune_var_table;
int Model_TranslationEngine64_tune_var_table_count = sizeof(tune_var_table) /
    sizeof(TuneVar_type);

//

// -----------------------------------------------------
// Error reporting system: Local storage
static char tuneVarErrorBuffer[500];
static int tuneVarErrorCharsUsed = 0;

// forward declare local functions
static void ErrorVPrintf(const char* formatString, va_list args);
static void ErrorPrintf(const char* formatString, ...);

// Internal use print to error buffer
static void ErrorVPrintf(const char* formatString, va_list args)
{
    char* buffer = &tuneVarErrorBuffer[tuneVarErrorCharsUsed];
    int bufferSize = sizeof(tuneVarErrorBuffer) - tuneVarErrorCharsUsed;
    if (bufferSize)
    {
        int charsPrinted = vsnprintf(
            buffer, bufferSize, formatString, args);
        tuneVarErrorCharsUsed += charsPrinted;
    }
}

// Internal use print to error buffer
static void ErrorPrintf(const char* formatString, ...)
{
    va_list args;
    va_start(args, formatString);
    ErrorVPrintf(formatString, args);
    va_end(args);
}

// checks for string equality without regards to case
// returns 1 if lowercase strings are equal, 0 otherwise
static int insensitiveStrcmp(const char* A, const char* B)
{
    int i;
    for (i = 0; *A && *B; i++)
    {
        if (tolower(*A++) != tolower(*B++))
        {
            return 0;
        }
    }

    return (*A == *B);
}

static int GetColMajorIndex(TuneVar_type* aRecord, int rowMajorIndexIn)
{
    int colMajorIndex = -1;
    int maxElementIndex = aRecord->width;
    int d;
    if (rowMajorIndexIn >= maxElementIndex)
    {
        return -1;
    }

    // Determine position of this element (zero-based) in each dimension
    // using the current TuneVar size set above by "SetTuneVariableSize"
    // and the row-major index provided.
    if (aRecord->string_parse)
    {
        // STRING PARSING
        // each token is a full row, so TuneVar is just a list of strings
        // TODO: THIS NEEDS MULTI-DIM REWORKING. ONLY SUPPORTS LIST OF STRINGS.
        maxElementIndex = aRecord->width / aRecord->max_size[1];// get max rows
        if (rowMajorIndexIn >= maxElementIndex)
        {
            // do not allow the current row position to exceed maximum
            colMajorIndex = -1;
        }
        else
        {
            // For string_parse use, the column-major index is the row number!
            colMajorIndex = rowMajorIndexIn;
        }
    }
    else
    {
        // NORMAL NUMERIC PARSING
        // Find each dimension's position: divide index by total size of lower dims
        // and mod by the max for the dimension itself. For row-major indexes,
        // it's actually the second dimension (dim 1 aka columns) that comes first.
        int thisPos[MAX_TUNEVAR_DIM] =
        {
            0
        };

        int lowerDimsSize[MAX_TUNEVAR_DIM] =
        {
            0
        };

        // The first three dimensions take a little work to line up due to the permuation
        // of dim0 & dim1 (rows and columns)
        lowerDimsSize[1] = 1;
                    // in a text file, columns are the first dimension to change
        lowerDimsSize[0] = ((int)aRecord->current_dims[1]);// ... then rows
        lowerDimsSize[2] = lowerDimsSize[0] * ((int)aRecord->current_dims[0]);// ... and so on
        for (d = 3; d < aRecord->num_dims; d++)
        {
            lowerDimsSize[d] = lowerDimsSize[d-1] * ((int)aRecord->
                current_dims[d-1]);
        }

        // Now that the lower dimension sizes are set up, we can spin through to get positions:
        for (d = 0; d < aRecord->num_dims; d++)
        {
            thisPos[d] = (rowMajorIndexIn / lowerDimsSize[d]) % ((int)
                aRecord->current_dims[d]);
        }

        // to convert to col-major (for storage) recalculate the lower dims sizes with 2 changes
        // the row is now the dimension that matches 1-to-1 with overall index (i.e. first dim)
        // and the dimensions are based on maximum sizes instead of current sizes because the buffer
        // always works with maximal size allocated:
        lowerDimsSize[0] = 1;
        lowerDimsSize[1] = aRecord->max_size[0];
        for (d = 2; d < aRecord->num_dims; d++)
        {
            lowerDimsSize[d] = lowerDimsSize[d-1] * aRecord->max_size[d-1];
        }

        // ... then spin through to calculate overall col-based index
        colMajorIndex = 0;
        for (d = 0; d < aRecord->num_dims; d++)
        {
            colMajorIndex += thisPos[d] * lowerDimsSize[d];
        }
    }

    return colMajorIndex;
}

static TuneVar_type* GetTuneVarRecord(TranslateEngineIterator iteratorIn)
{
    if ((iteratorIn.model < 0) || (iteratorIn.model >= numTranslationRoots))
    {
        return 0;                      // model out of range
    }

    TranslationRoot* theRoot = translationRoots[iteratorIn.model];
    if ((iteratorIn.index < 0) || (iteratorIn.index >= *theRoot->tunevar_count))
    {
        return 0;                      // index out of range for specified model
    }

    TuneVar_type* theTable = *(TuneVar_type**)theRoot->tunevar_table;
    return &theTable[iteratorIn.index];
}

/*******************************************************/
/************  PUBLIC FUNCTIONS ************************/
/*******************************************************/

// Return a tune variable iterator if name is recognized, INVALID_TRANSLATE_ITERATOR otherwise
TranslateEngineIterator RecognizeTuneVariable(const char* variableName)
{
    TranslateEngineIterator retVal = INVALID_TRANSLATE_ITERATOR;
    TranslateEngineIterator iterator;
    TuneVar_type* theVar = 0;
    TuneVar_type* aRecord;

    // Loop through table searching for a variable name match
    int m;
    for (m = 0; (m < numTranslationRoots) && (theVar == 0); m++)
    {
        iterator.model = m;
        iterator.index = 0;
        for (aRecord = GetTuneVarRecord(iterator); aRecord;
             aRecord = GetTuneVarRecord(iterator))
        {
            if (insensitiveStrcmp(variableName, aRecord->name))
            {
                // Found it!
                theVar = aRecord;
                retVal = iterator;
                break;
            }

            iterator.index++;
        }
    }

    // If a variable was found, trigger all the flags announcing its arrival
    if (theVar)
    {
        theVar->sightings_count++;
        int tIdx;
        TranslateEngineIterator transItr;
        transItr.model = retVal.model;
        for (tIdx = 0; tIdx < theVar->translation_count; tIdx++)
        {
            transItr.index = theVar->translations[tIdx];
            TouchTranslation(transItr);
        }
    }
    else
    {
        // variable was *not* found. generate error string
        ErrorPrintf("Error: Unrecognized TuneVar [%s]\n", variableName);
    }

    return retVal;
}

// Reset all TuneVar sighting counts to zero
void ClearAllTuneSightings()
{
    TranslateEngineIterator iterator;
    TuneVar_type* aRecord = 0;
    int m;
    for (m = 0; m < numTranslationRoots; m++)
    {
        iterator.model = m;
        iterator.index = 0;
        for (aRecord = GetTuneVarRecord(iterator); aRecord;
             aRecord = GetTuneVarRecord(iterator))
        {
            aRecord->sightings_count = 0;
            iterator.index++;
        }
    }
}

// Return count of how many times the specified TuneVar has been seen
int GetTuneVarSightings(TranslateEngineIterator tuneVarNumberIn)
{
    int sightings = 0;
    TuneVar_type* aRecord = GetTuneVarRecord(tuneVarNumberIn);
    if (aRecord)
    {
        sightings = aRecord->sightings_count;
    }

    return sightings;
}

// Return TuneVar name (or NULL if bad number)
const char* GetTuneVarName(TranslateEngineIterator tuneVarNumberIn)
{
    const char* name = 0;
    TuneVar_type* aRecord = GetTuneVarRecord(tuneVarNumberIn);
    if (aRecord)
    {
        name = aRecord->name;
    }

    return name;
}

const char* GetFirstTuneVarName(TranslateEngineIterator* tuneVarNumberIn)
{
    if (!tuneVarNumberIn)
        return 0;
    tuneVarNumberIn->model = 0;
    tuneVarNumberIn->index = 0;
    const char* aName = GetTuneVarName(*tuneVarNumberIn);
    if (aName == 0)
    {
        // First model had none. Try next:
        return GetNextTuneVarName(tuneVarNumberIn);
    }

    return aName;
}

const char* GetNextTuneVarName(TranslateEngineIterator* tuneVarNumberIn)
{
    if (!tuneVarNumberIn)
        return 0;

    // Check for next name in current model
    tuneVarNumberIn->index++;
    const char* aName = GetTuneVarName(*tuneVarNumberIn);

    // If no more - try the next model
    if (0 == aName)
    {
        // Name not found - so try the next model(s)
        tuneVarNumberIn->index = 0;
        while ((0 == aName) && (++(tuneVarNumberIn->model) < numTranslationRoots))
        {
            // name not found - so try the next model
            aName = GetTuneVarName(*tuneVarNumberIn);
        }
    }

    return aName;
}

// Set incoming TuneVar size - required for all TuneVars to account
// for variable size TuneVars and conversion from row-major to
// column-major storage indexing.
// Returns 0 for OK, 1 for error (does not set translation error state)
// ... but DOES set TuneVar error messages
int SetTuneVariableSize(TranslateEngineIterator tuneVarNumberIn, int countIn)
{
    const int errorCode = 1;
    int retVal = 0;

    // bail if provided number is not within the table
    TuneVar_type* aRecord = GetTuneVarRecord(tuneVarNumberIn);
    if (0 == aRecord)
        return errorCode;

    // otherwise, fetch the record, get maximum possible size, and clear storage
    int maxElementIndex = aRecord->width;
    memset(aRecord->value_ptr, 0, aRecord->element_bytes * maxElementIndex);

    // Determine input dimensions based on element count and the variable dimension
    // First reset all dimensions to max and find the quanta of elements:
    int elementQuanta = 1;
    for (int d = 0; d < aRecord->num_dims; d++)
    {
        aRecord->current_dims[d] = aRecord->max_size[d];
        if (d != aRecord->variable_dim)
        {
            elementQuanta *= aRecord->max_size[d];
        }
    }

    if (aRecord->string_parse)
    {
        // -------------- STRING PARSE SIZING ---------------
        // This is a string_parse TuneVar: each element (i.e. token) is a whole row
        maxElementIndex = aRecord->width / aRecord->max_size[1];// get max rows
        if (countIn > maxElementIndex)
        {
            // emit error - too much data here!
            ErrorPrintf(
                        "Error: TuneVar %s parses as a string and accepts only %d words. Ignoring %d extra words\n",
                        aRecord->name, maxElementIndex, countIn -
                        maxElementIndex);

            // NOTE: this error does *not* set the translation error state.
            retVal = errorCode;

            // enforce maximum size regardless of how much data provided
            // extra data will be ignored
            countIn = maxElementIndex;
        }

        // Determine the variable dimension, but not if it's columns
        // ... because the columns are always maxed out (copied above)
        if (aRecord->variable_dim != 1 && aRecord->variable_dim <
                aRecord->num_dims)
        {
            // take columns out of the picture:
            elementQuanta = elementQuanta / aRecord->max_size[1];

            // and calculate the variable dimension from what's left
            aRecord->current_dims[aRecord->variable_dim] = (int)((countIn) /
                elementQuanta);
        }

        // and record current width ("string parse" always fills full rows)
        aRecord->current_width = countIn * aRecord->max_size[1];
    }
    else
    {
        // -------------- NORMAL NUMERIC SIZING ---------------
        if (countIn > maxElementIndex)
        {
            // emit error - too much data here!
            ErrorPrintf(
                        "Error: TuneVar %s accepts only %d elements. Encountered %d extra elements\n",
                        aRecord->name, maxElementIndex, countIn -
                        maxElementIndex);

            // NOTE: this error does *not* set the translation error state.
            retVal = errorCode;

            // enforce maximum size regardless of how much data provided
            // extra data will be ignored
            countIn = maxElementIndex;
        }

        // Warn if the count does not fill out an even quanta
        // ... and then expand the count to an even quanta
        int extraNeeded = (elementQuanta - (countIn % elementQuanta)) %
            elementQuanta;
        if (extraNeeded)
        {
            // emit an error - not enough data here!
            ErrorPrintf(
                        "Error: TuneVar %s only accepts multiples of %d elements. Adding %d extra zeros to complete last grouping.\n",
                        aRecord->name, elementQuanta, extraNeeded);
            countIn = countIn + extraNeeded;

            // NOTE: this error does *not* set the translation error state. (so it's a warning I suppose)
            retVal = errorCode;
        }

        // Determine the variable dimension
        if (aRecord->variable_dim < aRecord->num_dims)
        {
            aRecord->current_dims[aRecord->variable_dim] = countIn /
                elementQuanta;
        }

        // and record current width
        aRecord->current_width = countIn;
    }

    return retVal;
}

// Set a single value of the tune variable. Provide total count of
// values in addition to the index of current value to set. The index
// traverses the TuneVar storage in row-major organization which is
// typical for C language matrix storage (i.e. same as the way a matrix
// is represented in a text file... listing out each row contiguously).
// Returns 0 for OK, 1 for error (does not set translation error state)
// ... but DOES set TuneVar error messages
int SetTuneVariableElement(TranslateEngineIterator tuneVarNumberIn, int
    rowMajorIndexIn, const char* stringElementValueIn)
{
    // By default, MATLAB/Simulink-generated code accesses data storage
    // in column major format where the matrix walks down through each
    // column first. This is different from standard C language and
    // from the rowMajorIndexIn assumptions for this function signature.
    const int errorCode = 1;
    int retVal = 0;

    // bail if provided number is not within the table
    TuneVar_type* aRecord = GetTuneVarRecord(tuneVarNumberIn);
    if (0 == aRecord)
        return errorCode;
    int colMajorIndex = GetColMajorIndex(aRecord, rowMajorIndexIn);
    if (colMajorIndex < 0)
    {
        // Error string should have been registered in SetTuneVariableSize above.
        // Just return the error code
        return errorCode;
    }

    // parse the value string, placing numeric value into the TuneVar
    SimulinkDatatypeId dTypeId = aRecord->dtype_id;
    void* valPtr = aRecord->value_ptr;
    switch (dTypeId)
    {
      case TSS_DOUBLE:
        sscanf(stringElementValueIn, "%lf",&((double*) valPtr)[colMajorIndex]);
        break;

      case TSS_SINGLE:
        sscanf(stringElementValueIn, "%f", &((float*) valPtr)[colMajorIndex]);
        break;

      case TSS_INT8:
        sscanf(stringElementValueIn, "%hhi", &((int8_T*) valPtr)[colMajorIndex]);
        break;

      case TSS_UINT8:
        if (aRecord->string_parse)
        {
            // Perform string parsing of element value... a single
            // ... string token contains all elements
            int strLength = (int)strlen(stringElementValueIn);
            int cols = aRecord->max_size[1];
            if (strLength > cols)
            {
                strLength = cols;
                ErrorPrintf(
                            "Error: TuneVar %s accepts only %d characters. Encountered extra characters [%s]\n",
                            aRecord->name, cols, (char*)
                            &stringElementValueIn[cols]);

                // NOTE: this error does *not* set the translation error state.
                retVal = errorCode;    // return error code... string too long
            }

            // OK... just copy it in but use column-major layout
            // Note that for string_parse, colMajorIndex == rowMajorIndex == index-of-input-token
            char* destChar = (char*)valPtr;
            for (int c=0; c < strLength; c++)
            {
                destChar[(c * aRecord->max_size[0]) + colMajorIndex] =
                    stringElementValueIn[c];
            }
        }
        else
        {
            // "Normal" numeric parsing of element value
            sscanf(stringElementValueIn, "%hhu", &((uint8_T*) valPtr)
                   [colMajorIndex]);
        }
        break;

      case TSS_INT16:
        sscanf(stringElementValueIn, "%hi", &((int16_T*) valPtr)[colMajorIndex]);
        break;

      case TSS_UINT16:
        sscanf(stringElementValueIn, "%hu", &((uint16_T*)valPtr)[colMajorIndex]);
        break;

      case TSS_INT32:
        sscanf(stringElementValueIn, "%i", &((int32_T*) valPtr)[colMajorIndex]);
        break;

      case TSS_UINT32:
        sscanf(stringElementValueIn, "%u", &((uint32_T*)valPtr)[colMajorIndex]);
        break;

      case TSS_BOOLEAN:
        sscanf(stringElementValueIn, "%hhi", &((int8_T*)valPtr)[colMajorIndex]);
        break;
    }

    return retVal;
}

// Retrieve reported error strings
const char* GetTuneVarErrorStrings()
{
    return &tuneVarErrorBuffer[0];
}

// Clear error state (external function)
void ClearTuneVarErrorStrings()
{
    tuneVarErrorBuffer[0] = 0;
    tuneVarErrorCharsUsed = 0;
}

// assumed: used,returnBuffer,remaining,aRecord->value_ptr,colMajorIndex
#define TYPED_PRINT(STYPE,FMTSTR)      {STYPE srcVal = ((STYPE*)aRecord->value_ptr)[colMajorIndex]; used=snprintf(&(returnBuffer[retUsed]),remaining,FMTSTR,srcVal);}

// returns space delimited list of elements
// sets TuneVar error strings upon error
int PrintTuneVarToBuffer(TranslateEngineIterator tuneVarNumberIn, char
    * returnBuffer, int returnBufferSize)
{
    int failDetected = 0;
    int retUsed = 0;
    int used = 0;                // characters used in the print of each element
    int remaining = returnBufferSize; // amount remaining to use in returnBuffer

    // bail if provided number is not within the table
    TuneVar_type* aRecord = GetTuneVarRecord(tuneVarNumberIn);
    if (0 == aRecord)
        return 0;
    int elemsOut = aRecord->current_width;
    if ((aRecord->dtype_id == TSS_UINT8) && aRecord->string_parse)
    {
        elemsOut = aRecord->current_width / aRecord->max_size[1];
    }

    // loop through current width in ROW-MAJOR order
    for (int i=0; i < elemsOut; i++)
    {
        // Start print of new element
        used = 0;
        int colMajorIndex = GetColMajorIndex(aRecord, i);
        if (colMajorIndex < 0)
            break;

        // output the element!
        switch (aRecord->dtype_id)
        {
          case TSS_DOUBLE :
            TYPED_PRINT(real64_T ," %.17g" );
            break;

          case TSS_SINGLE :
            TYPED_PRINT(real32_T ," %.9g" );
            break;

          case TSS_INT8 :
            TYPED_PRINT(int8_T ," %i" );
            break;

          case TSS_UINT8 :
            if (aRecord->string_parse)
            {
                // Copy out character-at-a-time using column-major layout
                // Note that for string_parse, colMajorIndex == rowMajorIndex == index-of-token
                int strLength = aRecord->max_size[1];
                char* destChar = (char*)&(returnBuffer[retUsed]);

                // keep track of this word, but leave room for a terminator
                int tempRemaining = remaining ? (remaining - 1) : 0;

                // add a space between values
                used++;
                if (tempRemaining)
                {
                    *destChar++ = ' ';
                    tempRemaining--;
                }

                // pour in a single row
                for (int c=0; c < strLength; c++)
                {
                    char* srcChar = &((char*)aRecord->value_ptr)[ c *
                        aRecord->max_size[0] + colMajorIndex ];
                    if (*srcChar)
                    {
                        used++;
                        if (tempRemaining)
                        {
                            *destChar++ = *srcChar;
                            tempRemaining--;
                        }
                    }
                }

                // terminate, but leave everything sitting on the terminator
                if (remaining)
                {
                    *destChar = 0;
                }
            }
            else
                TYPED_PRINT(uint8_T ," %u" );
            break;

          case TSS_INT16 :
            TYPED_PRINT(int16_T ," %i" );
            break;

          case TSS_UINT16 :
            TYPED_PRINT(uint16_T ," %u" );
            break;

          case TSS_INT32 :
            TYPED_PRINT(int32_T ," %i" );
            break;

          case TSS_UINT32 :
            TYPED_PRINT(uint32_T ," %u" );
            break;

          case TSS_BOOLEAN :
            TYPED_PRINT(int8_T ," %i" );
            break;

          default:
            ErrorPrintf("Bad TuneVar Type %s=%i",aRecord->name,aRecord->dtype_id);
            break;
        }

        // keep track of buffer usage, but don't let remaining size go negative
        retUsed += used;
        remaining -= used;
        remaining = (remaining < 0) ? 0 : remaining;
        if (used <= 0)
        {
            // Older implementations of snprintf only give failure
            // (instead of indicating how many bytes would be needed)
            failDetected = 1;
        }
    }

    if (failDetected)
    {
        // For old implementations of snprintf, this is what you get
        ErrorPrintf("Error: Translation engine return buffer is too small for TuneVar.\n");
    }
    else if (retUsed >= returnBufferSize)
    {
        // For C99 compliant snprintf, the error is more helpful:
        ErrorPrintf("Error: Return buffer requires %d bytes, but only %d provided\n",
                    retUsed, returnBufferSize);
    }

    return retUsed;
}

// Load default values for all TuneVars
void LoadAllTuneVarDefaults(void)
{
    TranslateEngineIterator iterator;
    TuneVar_type* aRecord = 0;

    // Loop through all TuneVars
    int m;
    for (m = 0; m < numTranslationRoots; m++)
    {
        iterator.model = m;
        iterator.index = 0;
        for (aRecord = GetTuneVarRecord(iterator); aRecord;
             aRecord = GetTuneVarRecord(iterator))
        {
            // clear out the current value
            int bufferSize = aRecord->element_bytes * aRecord->width;
            memset(aRecord->value_ptr, 0, bufferSize);

            // set the size of the value
            SetTuneVariableSize(iterator, aRecord->default_width);

            // copy in the actual default value itself
            memcpy(aRecord->value_ptr, aRecord->default_value, bufferSize);

            // Fully register that this TuneVar is seen/modified
            RecognizeTuneVariable(aRecord->name);

            // move on to next tunevar
            iterator.index++;
        }
    }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
