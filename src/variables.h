#pragma once
#include <setjmp.h>

inline jmp_buf jbuf;

inline uint8_t jump_ok;
inline uint8_t move_easy;
inline uint8_t bad_move;
inline uint8_t move_battle;
inline uint8_t analysis_mode;
inline uint8_t stop_flag;
inline uint8_t new_game;

inline uint32_t hash_size = 256;
inline uint32_t best_move;
inline uint32_t ponder_move;

inline int previous_depth;
inline int ok_immediate;
inline int stack_height;
inline int best_score;
inline int best_score_previous;
inline int best_depth;
inline int depth_limit;

inline uint64_t clock_start;
inline uint64_t hash_mask;
inline uint64_t age;
inline uint64_t nodes_white;
inline uint64_t nodes_black;
inline uint64_t nodes_null;
inline uint64_t randkey = 1;
inline uint64_t previous_info;

inline int64_t battle_time;
inline int64_t easy_time;
inline int64_t normal_time;
inline int64_t absolute_time;
inline int64_t trouble_time;
inline int64_t increment_time;

inline type_position* position;
inline type_board board;

inline type_hash* hash_table;
inline type_pawn_hash* pawn_hash_table;
