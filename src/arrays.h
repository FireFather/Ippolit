#pragma once
#include "struct.h"
inline char string_1[64];
inline char string_2[64];
inline char start_position[80] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

inline int line_turn[4][64];
inline int length[64];
inline int where[64];
inline int left_54[64];
inline int right_54[64];
inline int left_09[64];

inline uint8_t xray_table[64];

inline int8_t direction[64][64];
inline int16_t max_increase[16][07777];
inline uint32_t capture_value[16][16];

inline uint16_t history_table[16][64];
inline uint64_t stack[1024];
inline uint64_t eval_hash[0x8000];

inline uint64_t square_set[64];
inline uint64_t square_clear[64];

inline uint64_t non_diagonal[64];
inline uint64_t non_orthogonal[64];
inline uint64_t orthogonal[64];
inline uint64_t diagonal[64];
inline uint64_t diagonal_and_orthogonal[64];

inline uint64_t open_file_white[64];
inline uint64_t open_file_black[64];

inline uint64_t passed_pawn_white[64];
inline uint64_t passed_pawn_black[64];
inline uint64_t pawn_protected_white[64];
inline uint64_t pawn_protected_black[64];
inline uint64_t pawn_isolated_black[64];
inline uint64_t pawn_isolated_white[64];
inline uint64_t passed_pawn_connected[64];

inline uint64_t in_front_white[8];
inline uint64_t not_in_front_white[8];
inline uint64_t in_front_black[8];
inline uint64_t not_in_front_black[8];

inline uint64_t files_left[8];
inline uint64_t files_right[8];

inline uint64_t west_one[64];
inline uint64_t east_one[64];
inline uint64_t west_two[64];
inline uint64_t east_two[64];
inline uint64_t nudging[64];

inline uint64_t diagonal_length[64];
inline uint64_t files_isolated[8];
inline uint64_t table_gain[64];

inline uint64_t quadrant_white_wtm[64];
inline uint64_t quadrant_black_wtm[64];
inline uint64_t quadrant_white_btm[64];
inline uint64_t quadrant_black_btm[64];
inline uint64_t shepherd_white[64];
inline uint64_t shepherd_black[64];

inline uint64_t interposition_table[64][64];
inline uint64_t evasion_table[64][64];

inline uint64_t left_90_set[64];
inline uint64_t left_45_set[64];
inline uint64_t right_45_set[64];
inline uint64_t left_90_clear[64];
inline uint64_t left_45_clear[64];
inline uint64_t right_45_clear[64];

inline uint64_t rand_hash_castle[16];
inline uint64_t rand_hash_table[16][64];
inline uint64_t rand_hash_en_passant[8];
inline uint64_t rand_hash_white_to_move;

inline uint64_t attack_knight[64];
inline uint64_t attack_king[64];
inline uint64_t attack_pawn_white[64];
inline uint64_t attack_pawn_black[64];
inline uint64_t bitboard_line_obscured[4][64][64];

inline type_position root_position[1024];
inline type_pv_hash pv_hash_table[65536];

inline type_material material_table[419904];
inline type_shelter_storm shelter_storm[8];

inline type_move_list root_move_list[256];
