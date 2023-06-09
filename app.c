#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "watch.h"

char wordle_bank[365][7] = {
    "rapid",
    "untie",
    "opium",
    "minim",
    "stein",
    "rally",
    "conch",
    "floss",
    "abled",
    "noble",
    "rivet",
    "flair",
    "perch",
    "swoon",
    "dealt",
    "equal",
    "posse",
    "blitz",
    "drain",
    "gumbo",
    "mammy",
    "joint",
    "blend",
    "shaft",
    "sweet",
    "frill",
    "taboo",
    "niece",
    "learn",
    "jazzy",
    "brisk",
    "wreak",
    "mulch",
    "scram",
    "bluff",
    "worth",
    "igloo",
    "salon",
    "rebut",
    "royal",
    "wrong",
    "amend",
    "dunce",
    "horse",
    "weigh",
    "moist",
    "spend",
    "scarf",
    "crust",
    "loyal",
    "evade",
    "boxer",
    "crowd",
    "amply",
    "never",
    "pence",
    "usual",
    "surly",
    "missy",
    "merge",
    "ovoid",
    "cagey",
    "snipe",
    "rumor",
    "aback",
    "agate",
    "hoist",
    "axial",
    "stove",
    "aunty",
    "dowel",
    "swamp",
    "nasal",
    "cedar",
    "rogue",
    "palsy",
    "tight",
    "rajah",
    "clump",
    "loose",
    "roach",
    "drown",
    "forty",
    "hotel",
    "river",
    "value",
    "smock",
    "agony",
    "cease",
    "vegan",
    "elude",
    "whisk",
    "testy",
    "flunk",
    "enemy",
    "geese",
    "iliac",
    "alter",
    "spice",
    "tramp",
    "tiger",
    "drawn",
    "molar",
    "tweed",
    "abort",
    "tapir",
    "fiery",
    "forth",
    "limit",
    "dopey",
    "fruit",
    "utter",
    "bathe",
    "guest",
    "queen",
    "solve",
    "slain",
    "kiosk",
    "stilt",
    "north",
    "torso",
    "maxim",
    "rigor",
    "laugh",
    "skirt",
    "rebus",
    "quail",
    "cover",
    "minty",
    "rehab",
    "token",
    "femur",
    "dutch",
    "burly",
    "proof",
    "expel",
    "quoth",
    "sheer",
    "fauna",
    "guide",
    "gloss",
    "bride",
    "badly",
    "mercy",
    "tough",
    "scoop",
    "taken",
    "coach",
    "tonic",
    "blond",
    "terse",
    "woman",
    "empty",
    "orbit",
    "slate",
    "belle",
    "going",
    "mayor",
    "scree",
    "gnash",
    "whoop",
    "vital",
    "sheet",
    "fizzy",
    "crane",
    "copse",
    "could",
    "slung",
    "hence",
    "exalt",
    "sneak",
    "icing",
    "spire",
    "cacao",
    "ninny",
    "mucus",
    "agree",
    "prize",
    "round",
    "gloat",
    "tweak",
    "heron",
    "straw",
    "arise",
    "diver",
    "print",
    "tumor",
    "scamp",
    "price",
    "grove",
    "loopy",
    "clasp",
    "inane",
    "shear",
    "pesto",
    "dolly",
    "sprig",
    "robot",
    "hydro",
    "prior",
    "actor",
    "pupil",
    "blimp",
    "wrist",
    "skier",
    "error",
    "decay",
    "began",
    "chick",
    "haunt",
    "aware",
    "stern",
    "roomy",
    "snide",
    "chard",
    "rigid",
    "pesky",
    "burst",
    "borne",
    "lager",
    "unity",
    "older",
    "wryly",
    "truly",
    "panic",
    "drift",
    "youth",
    "ralph",
    "ovine",
    "gruff",
    "pivot",
    "brain",
    "vicar",
    "puree",
    "match",
    "splat",
    "enact",
    "rural",
    "sally",
    "along",
    "giddy",
    "doubt",
    "agora",
    "feign",
    "singe",
    "pilot",
    "flier",
    "myrrh",
    "preen",
    "hefty",
    "hedge",
    "sooth",
    "robin",
    "mealy",
    "hussy",
    "reuse",
    "rotor",
    "edict",
    "chaos",
    "black",
    "troll",
    "admit",
    "suing",
    "bingo",
    "ripen",
    "quiet",
    "child",
    "hyena",
    "trove",
    "cheap",
    "savvy",
    "drama",
    "adapt",
    "avian",
    "mover",
    "gaudy",
    "wheat",
    "kneel",
    "plump",
    "dread",
    "chute",
    "witty",
    "alien",
    "lumpy",
    "bloke",
    "tempo",
    "spilt",
    "early",
    "gully",
    "latte",
    "froze",
    "fatty",
    "drunk",
    "sissy",
    "taste",
    "lowly",
    "extol",
    "elegy",
    "altar",
    "truer",
    "quite",
    "slunk",
    "humph",
    "tonal",
    "swept",
    "freak",
    "radar",
    "arrow",
    "beard",
    "pudgy",
    "grope",
    "nanny",
    "dowdy",
    "hoard",
    "bushy",
    "reset",
    "video",
    "goose",
    "stony",
    "paper",
    "scrub",
    "tulle",
    "fancy",
    "march",
    "fight",
    "ensue",
    "disco",
    "baler",
    "crack",
    "paler",
    "eerie",
    "plunk",
    "locus",
    "dicey",
    "leant",
    "timid",
    "trite",
    "stead",
    "shade",
    "bribe",
    "buddy",
    "login",
    "money",
    "quick",
    "exult",
    "stock",
    "spent",
    "fluff",
    "cloud",
    "irony",
    "sperm",
    "incur",
    "serve",
    "tatty",
    "flare",
    "grief",
    "cream",
    "touch",
    "pleat",
    "siege",
    "bitty",
    "peril",
    "juror",
    "colon"
};

typedef struct ApplicationState {
    bool play;
    bool guess_response;
    bool guess_response_has_looped;
    uint8_t wordle_remaining_plays;
    char wordle_guess[7];
    char wordle_answer[7];
    char wordle_guess_response[7];
    uint8_t cursor_position;
} ApplicationState;

void cb_alarm_pressed(void);
void cb_mode_pressed(void);
void initialize_new_game(void);
void announce_win(void);
void announce_failure(void);
bool check_for_answer(void);
void display_guess_response(void);
uint8_t character_wordle_answer_count(char compare_string[7], char wordle_guess_char);
uint16_t generate_random_number(void);

ApplicationState application_state;

const BuzzerNote wordle_win_beep[] = {
    BUZZER_NOTE_G4,
    BUZZER_NOTE_REST,
    BUZZER_NOTE_G4,
    BUZZER_NOTE_C5,
    BUZZER_NOTE_B4,

    BUZZER_NOTE_C5,
    BUZZER_NOTE_B4,
    BUZZER_NOTE_G4,
    BUZZER_NOTE_A4
};

const BuzzerNote wordle_fail_beep[] = {
    BUZZER_NOTE_D4,
    BUZZER_NOTE_C4SHARP_D4FLAT,
    BUZZER_NOTE_C4,
    BUZZER_NOTE_B3
};

const uint16_t wordle_win_beep_durations[] = {
    200,
    50,
    200,
    200,
    200,

    200,
    200,
    200,
    200
};

void cb_alarm_pressed(void) {
    if (!application_state.play) {
        initialize_new_game();
    } else {
        if (application_state.guess_response) {
            application_state.guess_response = false;
            application_state.guess_response_has_looped = false;
        } else {
            if (application_state.cursor_position == 5) {
                if (check_for_answer()) {
                    announce_win();
                } else {
                    if (application_state.wordle_remaining_plays == 1) {
                        announce_failure();
                    } else {
                        application_state.guess_response = true;
                    }
                    application_state.wordle_remaining_plays--;
                    application_state.cursor_position = 1;
                }
            } else {
                application_state.cursor_position++;
            }
        }
    }
}

void cb_mode_pressed(void) {
    if ((application_state.wordle_guess[application_state.cursor_position] == 90) || (application_state.wordle_guess[application_state.cursor_position] == 32)) {
        application_state.wordle_guess[application_state.cursor_position] = 65;
    } else {
        application_state.wordle_guess[application_state.cursor_position]++;
    }
}

void initialize_new_game(void) {
    strcpy(application_state.wordle_guess, "      ");
    application_state.play = true;
    application_state.guess_response = false;
    application_state.guess_response_has_looped = false;
    application_state.cursor_position = 1;
    application_state.wordle_remaining_plays = 6;
    strcpy(application_state.wordle_answer, strcat(" ", "shine"));
}

void announce_win(void) {
    application_state.play = false;

    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 5; j++) {
            watch_buzzer_play_note(wordle_win_beep[j], wordle_win_beep_durations[j]);
        }
    }

    for(size_t i = 5, count = sizeof(wordle_win_beep) / sizeof(wordle_win_beep[0]); i < count; i++) {
        watch_buzzer_play_note(wordle_win_beep[i], wordle_win_beep_durations[i]);
    }
}

void announce_failure(void) {
    application_state.play = false;
    strcpy(application_state.wordle_guess, application_state.wordle_answer);

    for(size_t i = 0, count = sizeof(wordle_fail_beep) / sizeof(wordle_fail_beep[0]); i < count; i++) {
        watch_buzzer_play_note(wordle_fail_beep[i], 300);
    }
}

bool check_for_answer(void) {
    char wordle_guess_to_lower[7];

    wordle_guess_to_lower[0] = ' ';
    for (size_t i = 1; i < sizeof(wordle_guess_to_lower); i++) {
        wordle_guess_to_lower[i] = tolower(application_state.wordle_guess[i]);
    }

    if (strcmp(wordle_guess_to_lower, application_state.wordle_answer) == 0) {
        return true;
    } else {
        application_state.wordle_guess_response[0] = ' ';
        for (size_t i = 1; i < sizeof(wordle_guess_to_lower); i++) {
            if (wordle_guess_to_lower[i] == application_state.wordle_answer[i]) {
                application_state.wordle_guess_response[i] = application_state.wordle_guess[i];
            } else {
                application_state.wordle_guess_response[i] = ' ';
            }
        }

        for (size_t i = 1; i < sizeof(wordle_guess_to_lower); i++) {
            if (strchr(application_state.wordle_answer, wordle_guess_to_lower[i])) {
                if ((strchr(application_state.wordle_guess_response, application_state.wordle_guess[i])) || (strchr(application_state.wordle_guess_response, wordle_guess_to_lower[i]))) {
                    uint8_t char_wordle_answer_count = character_wordle_answer_count(application_state.wordle_answer, wordle_guess_to_lower[i]);
                    if ((char_wordle_answer_count > 1) && (application_state.wordle_guess_response[i] == ' ') && (character_wordle_answer_count(application_state.wordle_guess_response, wordle_guess_to_lower[i]) < char_wordle_answer_count)) {
                        application_state.wordle_guess_response[i] = wordle_guess_to_lower[i];
                    }
                } else {
                    application_state.wordle_guess_response[i] = wordle_guess_to_lower[i];
                }
            }
        }
        return false;
    }
}

uint8_t character_wordle_answer_count(char compare_string[7], char wordle_guess_char) {
    uint8_t char_count = 0;

    for (size_t i = 1; i < 7; i++) {
        if (tolower(compare_string[i]) == wordle_guess_char) {
            char_count++;
        }
    }

    return char_count;
}

uint16_t generate_random_number(void) {
    srand(time(0));
    return ((rand() % (364 - 1)) + 1);
}

void app_init(void) {
    memset(&application_state, 0, sizeof(application_state));
    
    application_state.play = false;
    application_state.guess_response = false;
    strcpy(application_state.wordle_guess, "Wordle");
}

void display_guess_response(void) {
    char wordle_guess_response_oops_all_uppercase[7];
    wordle_guess_response_oops_all_uppercase[0] = ' ';

    if (application_state.guess_response_has_looped) {
        for (size_t i = 1; i < sizeof(application_state.wordle_guess_response); i++) {
            if (isupper(application_state.wordle_guess_response[i])) {
                wordle_guess_response_oops_all_uppercase[i] = application_state.wordle_guess_response[i];
            } else {
                wordle_guess_response_oops_all_uppercase[i] = ' ';
            }
        }

        watch_display_string(wordle_guess_response_oops_all_uppercase, 4);

        application_state.guess_response_has_looped = false;
    } else {
        for (size_t i = 1; i < sizeof(application_state.wordle_guess_response); i++) {
            if (islower(application_state.wordle_guess_response[i])) {
                wordle_guess_response_oops_all_uppercase[i] = toupper(application_state.wordle_guess_response[i]);
            } else {
                wordle_guess_response_oops_all_uppercase[i] = application_state.wordle_guess_response[i];
            }
        }
        watch_display_string(wordle_guess_response_oops_all_uppercase, 4);

        application_state.guess_response_has_looped = true;
    }
}

void app_wake_from_backup(void) {
}

void app_setup(void) {
    watch_enable_external_interrupts();
    watch_register_extwake_callback(BTN_ALARM, cb_alarm_pressed, INTERRUPT_TRIGGER_RISING);
    watch_register_interrupt_callback(BTN_MODE, cb_mode_pressed, INTERRUPT_TRIGGER_RISING);

    watch_enable_display();

    watch_enable_buzzer();
}

void app_prepare_for_standby(void) {
}

void app_wake_from_standby(void) {
}

bool app_loop(void) {
    char wordle_plays_display[3];
    char cursor_position_display[3];

    sprintf(cursor_position_display, "%d", application_state.cursor_position);
    watch_display_string(cursor_position_display, 0);

    sprintf(wordle_plays_display, "%d", application_state.wordle_remaining_plays);
    watch_display_string(wordle_plays_display, 3);

    if (application_state.guess_response) {
        display_guess_response();
        sleep(1);
    } else {
        watch_display_string(application_state.wordle_guess, 4);
    }

    return !application_state.guess_response;
}
