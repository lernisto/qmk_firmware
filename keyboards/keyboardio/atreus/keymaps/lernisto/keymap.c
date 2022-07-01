#include QMK_KEYBOARD_H


/*
 TODO
I want a hybrid between OSL and TT.
	If I tap the layer key once, it activates the layer for one key, like OSL
	If I tap the layer key twice, it activates the layer until it is deactivated through some other mechanism.
	If I hold the layer key, it acts like MO.
*/
#define TLL(x) TT(x)

enum layer_names {
	_BASE,
	_EXTEND,
	_FUNCTION,
    _SYMNUM,
    //_UNISYM,
	_MOUSE,
};

#define PKC_UNDO G(KC_Z)
#define PKC_CUT G(KC_X)
#define PKC_COPY G(KC_C)
#define PKC_PSTE G(KC_V)
/*TODO replace the unicode mode keys with more general platform selection
e.g. Mac mode sends G(KC_Z) for undo, while Linux and Windows modes send C(KC_Z)
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT(
		         KC_Q,            KC_C,            KC_L,           KC_M,       KC_K,                                               KC_B,           KC_F,          KC_U,  KC_COMM,   KC_SCLN,
		         KC_I,            KC_S,    LALT_T(KC_R),   LGUI_T(KC_T),       KC_G,                                               KC_P,   RGUI_T(KC_N),  RALT_T(KC_E),   KC_A,      KC_O,
		         KC_Y,            KC_V,            KC_W,           KC_D,       KC_X,          KC_Z,             KC_BSLS,           KC_J,           KC_H,       KC_MINS,   KC_DOT,   KC_QUOT,
       LCTL_T(KC_ESC),  TLL(_FUNCTION),         XXXXXXX,   TLL(_EXTEND), OSM(MOD_LSFT),    KC_BSPC,              KC_TAB,  MEH_T(KC_SPC),   TLL(_SYMNUM),       KC_SLSH,   KC_GRV,   RCTL_T(KC_ENT)
		),
	[_EXTEND] = LAYOUT(
			   KC_INS,       UC_M_MA,       UC_M_LN,       UC_M_WC,  KC_APP,                                KC_PGUP,  KC_HOME,     KC_UP,    KC_END,   G(KC_PLUS),
		OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL),  KC_RALT,                                KC_PGDN,  KC_LEFT,   KC_DOWN,   KC_RGHT,  G(KC_MINS),
			 PKC_UNDO,       PKC_CUT,      PKC_COPY,      PKC_PSTE,  KC_LGUI,  KC_DEL,        KC_PSCR, /*?*/KC_RGUI,  KC_CAPS,    KC_LOCK,TG(_MOUSE),     G(KC_0),  // KC_LOCK useful for locking SHIFT to select stuff
		      _______,       _______,   TG(_EXTEND),       _______,  _______,  _______,          _______,    _______,   _______,  KC_LSFT,   _______, _______
	),
	[_FUNCTION] = LAYOUT(
			  KC_MUTE,       KC_VOLD,       KC_VOLU,       KC_MPLY,  KC_BRIU,                               KC_F12,    KC_F7,     KC_F8,    KC_F9,  KC_F15,
		OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL),  KC_BRID,                               KC_F11,    KC_F4,     KC_F5,    KC_F6,  KC_F14,
			  KC_SLCK,       KC_PAUS,       KC_MPRV,       KC_MNXT,  KC_STOP,  KC_DEL,           XXXXXXX,   KC_F10,    KC_F1,     KC_F2,    KC_F3, KC_F13,
		      _______,       _______, TG(_FUNCTION),       _______,  _______,  _______,          _______,  _______,   _______,     _______,   _______, _______
	),
	[_SYMNUM] = LAYOUT(
			    KC_EXLM,         KC_AT,      KC_HASH,        KC_DLR,  KC_PERC,                                 KC_PSLS,    KC_P7,      KC_P8,    KC_P9,  KC_PPLS,
                KC_ASTR,        KC_EQL,      KC_LCBR,       KC_LPRN,  KC_LBRC,                                 KC_PAST,    KC_P4,      KC_P5,    KC_P6,  KC_PMNS,
                KC_CIRC,       KC_AMPR,      KC_RCBR,       KC_RPRN,  KC_RBRC,   KC_DEL,           XXXXXXX,    KC_PCMM,    KC_P1,      KC_P2,    KC_P3,  KC_PEQL,
                _______,       _______,   TG(_SYMNUM),       _______,  _______,   _______,         _______,    _______,  _______,      KC_P0,  KC_PDOT,  RCTL_T(KC_PENT)
        ),
        /*
    [_UNISYM] = LAYOUT(
                _______,      _______,       _______,       _______,  _______,                               _______,     _______,    _______,     _______,    _______,
                _______,      _______,       _______,       _______,  _______,                               _______,     _______,    _______,     _______,    _______,
                _______,      _______,       _______,       _______,  _______,   _______,          _______,  _______,     _______,    _______,     _______,    _______,
                _______,       _______,  TG(_UNISYM),       _______,  _______,   _______,          _______,     _______,    _______,     _______,    _______,     _______
        ),
        */
    [_MOUSE] = LAYOUT(
                KC_ACL0,      KC_WH_L,       KC_MS_U,       KC_WH_R,  KC_WH_U,                               _______,     _______,    _______,     _______,    _______,
                KC_ACL1,      KC_MS_L,       KC_MS_D,       KC_MS_R,  KC_WH_D,                               _______,     _______,    _______,     _______,    _______,
                KC_ACL2,      KC_BTN4,       KC_BTN1,       KC_BTN2,  KC_BTN3,   KC_BTN5,          XXXXXXX,  _______,     _______,    _______,     _______,    _______,
                _______,      _______,    TG(_MOUSE),       _______,  _______,   _______,          _______,     _______,    _______,     _______,    _______,     _______
        ),

};




/*
testing
testing



effort: 3
3.1 2.5 2.0 2.2 3.2        3.2 2.2 2.0 2.4 3.0
1.7 1.4 1.1 1.0 2.9        2.9 1.0 1.1 1.3 1.6
3.3 2.7 2.3 1.6 3.0        3.0 1.6 2.3 2.6 3.2
penalties:
 2.5  3.0  4.0  #same-finger
 0.5  1.0  1.5  #pinky-ring
 0.1  0.2  0.3  #ring-middle
-0.2 -0.1  0.0  #middle-index
fingers: 3
0 1 2 3 3     6 6 7 8 9
0 1 2 3 3     6 6 7 8 9
0 1 2 3 3 3 6 6 6 7 8 9
type:
atreus44


qwertyuiop
asdfg hjkl;
zxcvb'\nm,./

qwfpbjlyu;
asrtg  mneio
'xcdvz\kh,./

## Colemak + arsti = rstia

QWFPBJLUY;[]
RSTIGMNEAO'
ZXCDVKH,./
Finger Frequency


finger 0 	5.63%	 finger 9 	9.09%
finger 1 	8.52%	 finger 8 	10.89%
finger 2 	12.85%	 finger 7 	16.38%
finger 3 	16.73%	 finger 6 	19.91%
total L 	43.73%	total R 	56.27%

Finger Bigram Frequency
finger 0 	0.002%	 finger 9 	0.196%
finger 1 	0.078%	 finger 8 	0.433%
finger 2 	0.357%	 finger 7 	0.544%
finger 3 	1.809%	 finger 6 	0.443%

total	3.861%

Top Same-Finger Bigrams
finger 7 	E, 	0.397%
finger 3 	ID 	0.384%
finger 3 	DI 	0.333%
finger 8 	AY 	0.309%
finger 3 	IG 	0.259%

Top Neighbour-Finger Bigrams
finger 1-2 	ST 	0.944%
finger 7-8 	EA 	0.767%
finger 8-9 	YO 	0.480%
finger 0-1 	RS 	0.357%
finger 7-8 	E. 	0.243%

Finger Effort
 	base	s-bigrams	n-bigrams	total
finger 0 	0.092	0.000	0.002	0.095
finger 1 	0.141	0.002	0.002	0.145
finger 2 	0.187	0.011	-0.004	0.194
finger 3 	0.299	0.052		0.351
finger 6 	0.349	0.014		0.363
finger 7 	0.227	0.017	-0.014	0.230
finger 8 	0.180	0.014	0.003	0.197
finger 9 	0.178	0.006	0.010	0.194
total * 	1.655	 0.116	 -0.001	 1.770


## Colemak-dh + aioy=iayo
1234567890-=
QWFPBJLUO;[]
IRSTGMNEAY'
ZXCDVKH,./

Finger Frequency
finger 0 	6.76%	 finger 9 	3.72%
finger 1 	8.03%	 finger 8 	16.25%
finger 2 	10.30%	 finger 7 	16.38%
finger 3 	18.64%	 finger 6 	19.91%
total L 	43.73%	total R 	56.27%

Finger Bigram Frequency
finger 0 	0.040%	 finger 9 	0.247%
finger 1 	0.046%	 finger 8 	0.123%
finger 2 	0.120%	 finger 7 	0.544%
finger 3 	0.152%	 finger 6 	0.443%
total	1.713%

Top Same-Finger Bigrams
finger 7 	E, 	0.397%
finger 6 	KN 	0.105%
finger 7 	UE 	0.104%
finger 9 	?" 	0.098%
finger 2 	SC 	0.096%


Top Neighbour-Finger Bigrams
finger 8-7 	OU 	1.442%
finger 7-8 	EA 	0.767%
finger 1-0 	RI 	0.528%
finger 1-0 	WI 	0.493%
finger 9-8 	YO 	0.480%


Finger Effort
 	base	s-bigrams	n-bigrams	total
finger 0 	0.110	0.001	0.010	0.121
finger 1 	0.135	0.001	0.001	0.138
finger 2 	0.159	0.004	-0.003	0.160
finger 3 	0.318	0.004		0.323
finger 6 	0.349	0.014		0.363
finger 7 	0.227	0.017	-0.014	0.230
finger 8 	0.309	0.004	0.003	0.317
finger 9 	0.092	0.007	0.011	0.111
total * 	1.701	 0.052	 0.009	 1.762


## Colemak-dh + AI=IA
1234567890-=
QWFPBJLUO;[]
ISRTGMNEAY'
ZXCDVKH,./

Finger Frequency
finger 0 	6.76%	 finger 9 	3.72%
finger 1 	8.52%	 finger 8 	16.25%
finger 2 	9.81%	 finger 7 	16.38%
finger 3 	18.64%	 finger 6 	19.91%
total L 	43.73%	total R 	56.27%

Finger Bigram Frequency
finger 0 	0.040%	 finger 9 	0.247%
finger 1 	0.078%	 finger 8 	0.123%
finger 2 	0.453%	 finger 7 	0.544%
finger 3 	0.152%	 finger 6 	0.443%
total	2.078%

Top Same-Finger Bigrams
finger 7 	E, 	0.397%
finger 2 	FR 	0.204%
finger 2 	CR 	0.132%
finger 6 	KN 	0.105%
finger 7 	UE 	0.104%

Top Neighbour-Finger Bigrams
finger 8-7 	OU 	1.442%
finger 0-1 	IS 	1.057%
finger 7-8 	EA 	0.767%
finger 1-0 	WI 	0.493%
finger 9-8 	YO 	0.480%


Finger Effort
 	base	s-bigrams	n-bigrams	total
finger 0 	0.110	0.001	0.013	0.124
finger 1 	0.141	0.002	0.001	0.144
finger 2 	0.154	0.014	-0.003	0.165
finger 3 	0.318	0.004		0.323
finger 6 	0.349	0.014		0.363
finger 7 	0.227	0.017	-0.014	0.230
finger 8 	0.309	0.004	0.003	0.317
finger 9 	0.092	0.007	0.011	0.111
total * 	1.702	 0.063	 0.012	 1.777

here we go testing this keyboard.
(e{[]})
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
      KC_Y,                KC_C,                KC_L,                 KC_M,             KC_K,    						               KC_Z,             KC_F,              KC_U,   TD(DANCE_2),  KC_BSPC,
      KC_I,                KC_S,    MT(MOD_LALT,KC_R),   MT(MOD_LGUI,KC_T),             KC_G,                                          KC_P, MT(MOD_RGUI,KC_N), MT(MOD_RALT,KC_E),         KC_A,     KC_O,
      KC_Q,                KC_V,                KC_W,                 KC_D,             KC_J,     						               KC_B,             KC_H,        TD(DANCE_3),  TD(DANCE_1),     KC_X,
  		    					                                        MT(MOD_MEH,KC_SPACE),  OSM(MOD_LSFT),           OSM(MOD_RCTL), TO(1)
  ),

  [1] = LAYOUT(
    KC_ESCAPE,            KC_AT,          LSFT(KC_3),            TD(DANCE_31),         KC_PERC,                                       KC_CIRC,       KC_AMPR,        KC_ASTR,    KC_SCOLON,  KC_BSPC,
    KC_TAB,              KC_EQL,   LALT(KC_RBRACKET), LALT(LSFT(KC_RBRACKET)),    TD(DANCE_32),                                  TD(BKSL_HME), LSFT(KC_LBRC),  LSFT(KC_RBRC), TD(PIPE_END), KC_ENTER,
    KC_TILD,       TD(DANCE_33),   LALT(KC_LBRACKET), LALT(LSFT(KC_LBRACKET)),         KC_DQUO,                                       KC_LBRC,       KC_LPRN,        KC_RPRN,      KC_RBRC,    TO(3),
                                                                                         TO(0),  OSM(MOD_LSFT),              KC_RALT ,   TO(2)
  ),

  [2] = LAYOUT(
    KC_ESCAPE,          KC_MPY,             KC_MPRV,                  KC_MNXT,   LSFT(KC_MINS),                                       KC_MINS,          KC_7,            KC_8,       KC_9,    _______,
    KC_TAB,            _______,             KC_VOLD,                  KC_VOLU,    LSFT(KC_EQL),                                        KC_EQL,          KC_4,            KC_5,       KC_6,   KC_ENTER,
    RESET,      KC_KP_ASTERISK,  KC_BRIGHTNESS_DOWN,         KC_BRIGHTNESS_UP,       KC_KP_DOT,                                          KC_0,          KC_1,            KC_2,       KC_3,    _______,
	                                                                                     TO(0), KC_LGUI,                           KC_RALT ,TO(2)
  ),

  [3] = LAYOUT(
  TD(DANCE_54),  KC_MS_WH_LEFT,            KC_MS_UP,           KC_MS_WH_RIGHT,    TD(DANCE_55),                                 LGUI(KC_LBRACKET),    LCTL(LSFT(KC_TAB)),RCTL(KC_TAB),   LGUI(KC_RBRACKET),_______,
  TD(DANCE_56),     KC_MS_LEFT,          KC_MS_DOWN,              KC_MS_RIGHT,    MT(MOD_LGUI,KC_DEL),                                TD(DANCE_60),   MT(MOD_RGUI,KC_DOWN), MT(MOD_RALT,KC_UP),   TD(DANCE_63),   KC_ENTER,
  TD(DANCE_58),     KC_MS_BTN2,         KC_MS_WH_UP,            KC_MS_WH_DOWN,         _______,                                         KC_MS_BTN1,       KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,   XXXXXXX,
                                                                                        TO(0),_______,                    KC_RALT,            TO(1)
  )
};

*/
