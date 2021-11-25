
static const uint8 left_90[64] =
    {
	7, 15, 23, 31, 39, 47, 55, 63,
	6, 14, 22, 30, 38, 46, 54, 62,
	5, 13, 21, 29, 37, 45, 53, 61,
	4, 12, 20, 28, 36, 44, 52, 60,
	3, 11, 19, 27, 35, 43, 51, 59,
	2, 10, 18, 26, 34, 42, 50, 58,
	1, 9, 17, 25, 33, 41, 49, 57,
	0, 8, 16, 24, 32, 40, 48, 56
    };

static const uint8 left_45[64] =
    {
	0, 2, 5, 9, 14, 20, 27, 35,
	1, 4, 8, 13, 19, 26, 34, 42,
	3, 7, 12, 18, 25, 33, 41, 48,
	6, 11, 17, 24, 32, 40, 47, 53,
	10, 16, 23, 31, 39, 46, 52, 57,
	15, 22, 30, 38, 45, 51, 56, 60,
	21, 29, 37, 44, 50, 55, 59, 62,
	28, 36, 43, 49, 54, 58, 61, 63
    };

static const uint8 right_45[64] =
    {
	28, 21, 15, 10, 6, 3, 1, 0,
	36, 29, 22, 16, 11, 7, 4, 2,
	43, 37, 30, 23, 17, 12, 8, 5,
	49, 44, 38, 31, 24, 18, 13, 9,
	54, 50, 45, 39, 32, 25, 19, 14,
	58, 55, 51, 46, 40, 33, 26, 20,
	61, 59, 56, 52, 47, 41, 34, 27,
	63, 62, 60, 57, 53, 48, 42, 35
    };

static const int shift[64] =
    {
    1, 2, 2, 4, 4, 4, 7, 7,
	7, 7, 11, 11, 11, 11, 11, 16,
	16, 16, 16, 16, 16, 22, 22, 22,
	22, 22, 22, 22, 29, 29, 29, 29,
	29, 29, 29, 29, 37, 37, 37, 37,
	37, 37, 37, 44, 44, 44, 44, 44,
	44, 50, 50, 50, 50, 50, 55, 55,
	55, 55, 59, 59, 59, 62, 62, 64
    };

static const uint64 castle_table[64] =
    {
    Kkq, KQkq, KQkq, KQkq, kq, KQkq, KQkq, Qkq,
	KQkq, KQkq, KQkq, KQkq, KQkq, KQkq, KQkq, KQkq,
	KQkq, KQkq, KQkq, KQkq, KQkq, KQkq, KQkq, KQkq,
	KQkq, KQkq, KQkq, KQkq, KQkq, KQkq, KQkq, KQkq,
	KQkq, KQkq, KQkq, KQkq, KQkq, KQkq, KQkq, KQkq,
	KQkq, KQkq, KQkq, KQkq, KQkq, KQkq, KQkq, KQkq,
	KQkq, KQkq, KQkq, KQkq, KQkq, KQkq, KQkq, KQkq,
	KQk, KQkq, KQkq, KQkq, KQ, KQkq, KQkq, KQq
    };


static const uint8 trapped_bishop_squares[64] =
    {
    0x00, C2, 0x00, 0x00, 0x00, 0x00, F2, 0x00,
	B3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, G3,
	B4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, G4,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	B5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, G5,
	B6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, G6,
	0x00, C7, 0x00, 0x00, 0x00, 0x00, F7, 0x00
    };

static const uint8 trapped_bishop_squares_protected[64] =
    {
    0x00, D1, 0x00, 0x00, 0x00, 0x00, E1, 0x00,
	C2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, F2,
	C3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, F3,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	C6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, F6,
	C7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, F7,
	0x00, D8, 0x00, 0x00, 0x00, 0x00, E8, 0x00
    };

static const uint64 rank_table[8] =
    {
    0x00000000000000ff, 0x000000000000ff00, 0x0000000000ff0000, 0x00000000ff000000,
	0x000000ff00000000, 0x0000ff0000000000, 0x00ff000000000000, 0xff00000000000000
    };

static const uint64 file_table[8] =
    {
    0x0101010101010101, 0x0202020202020202, 0x0404040404040404, 0x0808080808080808,
	0x1010101010101010, 0x2020202020202020, 0x4040404040404040, 0x8080808080808080
    };

static const uint32 material_values[16] =
    {
    0, ((0 & 0xff) | (0x1440 << 8)), ((1 & 0xff) | (0x240 << 8)), 0, ((1 & 0xff) | (0x24 << 8)),
	((1 & 0xff) | (0x48 << 8)), ((3 & 0xff) | (0x04 << 8)), ((6 & 0xff) | (0x1 << 8)), 0,
	((0 & 0xff) | (0xb640 << 8)), ((1 & 0xff) | (0x6c0 << 8)), 0, ((1 & 0xff) | (0x90 << 8)),
	((1 & 0xff) | (0x120 << 8)), ((3 & 0xff) | (0xc << 8)), ((6 & 0xff) | (0x2 << 8))
    };

static const uint64 trapped_rook_squares[64] =
    {
    0, (((uint64)1) << (A1)) | (((uint64)1) << (A2)), (((uint64)1) << (A1)) | (((uint64)1) << (A2)) | (((uint64)1) << (B1)) | (((uint64)1) << (B2)), 0,
	0, (((uint64)1) << (H1)) | (((uint64)1) << (H2)) | (((uint64)1) << (G1)) | (((uint64)1) << (G2)), (((uint64)1) << (H1)) | (((uint64)1) << (H2)), 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, (((uint64)1) << (A8)) | (((uint64)1) << (A7)), (((uint64)1) << (A8)) | (((uint64)1) << (A7)) | (((uint64)1) << (B8)) | (((uint64)1) << (B7)), 0,
	0, (((uint64)1) << (H8)) | (((uint64)1) << (H7)) | (((uint64)1) << (G8)) | (((uint64)1) << (G7)), (((uint64)1) << (H8)) | (((uint64)1) << (H7)), 0
    };

static const uint32 white_bishop_xray[16] =
    {
	0, 196613, 196613, 196613,
	0, 0, 196613, 0,
	0, 131077, 131077, 0,
	0, 0, 983065, 655380
    };

static const uint32 black_bishop_xray[16] =
    {
	0, 131077, 131077, 0,
	0, 0, 983065, 655380,
	0, 196613, 196613, 196613,
	0, 0, 196613, 0
    };

static const uint32 white_rook_xray[16] =
    {
	0, 0, 196613, 196613,
	196613, 196613, 0, 0,
	0, 131077, 131077, 0,
	131077, 131077, 0, 655380
    };

static const uint32 black_rook_xray[16] =
    {
	0, 131077, 131077, 0,
	131077, 131077, 0, 655380,
	0, 0, 196613, 196613,
	196613, 196613, 0, 0
    };

static const uint32 white_queen_xray_diagonal[16] =
    {
	0, 65538, 131076, 131076,
	0, 0, 131076, 0,
	0, 0, 131077, 0,
	0, 0, 131077, 0
    };

static const uint32 black_queen_xray_diagonal[16] =
    {
 	0, 0, 131077, 0,
	0, 0, 131077, 0,
	0, 65538, 131076, 131076,
	0, 0, 131076, 0
    };

static const uint32 white_queen_xray_orthogonal[16] =
    {
	0, 0, 131076, 131076,
	131076, 131076, 0, 0,
	0, 0, 131077, 0,
	131077, 131077, 0, 0
    };

static const uint32 black_queen_xray_orthogonal[16] =
    {
	0, 0, 131077, 0,
	131077, 131077, 0, 0,
	0, 0, 131076, 131076,
	131076, 131076, 0, 0
    };

static const int see_value[16] =
    {
    0, value_pawn, value_knight, 12345678, value_bishop, value_bishop, value_rook, value_queen,
	0, value_pawn, value_knight, 12345678, value_bishop, value_bishop, value_rook, value_queen
    };

static const uint32 king_danger_weight[16] =
    {
    0, 1, 4, 9, 16, 25, 36, 49, 50, 50, 50, 50, 50, 50, 50, 50
    };

static const uint32 queen_rank_endgame_value[8] =
    {
	0, 0, 0, 327685, 655370, 1310740, 2621480, 0
    };

static const uint64 rook_traps_king[8] =
    {
    0x0202020202020202, 0, 0, 0, 0, 0, 0, 0x4040404040404040
    };

static const uint64 white_en_passant_table[8] =
    {
    (((uint64)1) << (B4)) | (((uint64)1) << (B4)), (((uint64)1) << (A4)) | (((uint64)1) << (C4)),
	(((uint64)1) << (B4)) | (((uint64)1) << (D4)), (((uint64)1) << (C4)) | (((uint64)1) << (E4)),
	(((uint64)1) << (D4)) | (((uint64)1) << (F4)), (((uint64)1) << (E4)) | (((uint64)1) << (G4)),
	(((uint64)1) << (F4)) | (((uint64)1) << (H4)), (((uint64)1) << (G4)) | (((uint64)1) << (G4))
    };

static const uint64 black_en_passant_table[8] =
    {
    (((uint64)1) << (B5)) | (((uint64)1) << (B5)), (((uint64)1) << (A5)) | (((uint64)1) << (C5)),
	(((uint64)1) << (B5)) | (((uint64)1) << (D5)), (((uint64)1) << (C5)) | (((uint64)1) << (E5)),
	(((uint64)1) << (D5)) | (((uint64)1) << (F5)), (((uint64)1) << (E5)) | (((uint64)1) << (G5)),
	(((uint64)1) << (F5)) | (((uint64)1) << (H5)), (((uint64)1) << (G5)) | (((uint64)1) << (G5))
    };

static const int promotions_white[8] =
    {
    0, 0, 0, 0, white_knight, white_king_bishop, white_rook, white_queen
    };

static const int promotions_black[8] =
    {
    0, 0, 0, 0, black_knight, black_queen_bishop, black_rook, black_queen
    };

static const uint8 opposing_pawns_multiplier[9] =
    {
    6, 5, 4, 3, 2, 1, 0, 0, 0
    };

static const uint8 pawn_count_multiplier[9] =
    {
    6, 5, 4, 3, 2, 1, 0, 0, 0
    };

static const int jumps[8] =
    {
    6, 10, 15, 17, -6, -10, -15, -17
    };

static const uint8 blocked_pawn[64] =
    {
    0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 2, 2, 2, 2, 1, 1,
	1, 2, 3, 3, 3, 3, 2, 1,
	1, 2, 3, 5, 5, 3, 2, 1,
	1, 2, 3, 5, 5, 3, 2, 1,
	1, 2, 3, 3, 3, 3, 2, 1,
	1, 1, 2, 2, 2, 2, 1, 1,
	0, 0, 0, 0, 0, 0, 0, 0
    };

static const sint32 passed_pawn_value[8] =
    {
	0, 0, 0, 655370, 1310745, 2621490, 3932235, 0
    };

static const sint32 outside_passed_pawn_value[8] =
    {
	0, 0, 0, 0, 131077, 327690, 655380, 0
    };

static const sint32 protected_passed_pawn_value[8] =
    {
	0, 0, 0, 0, 327690, 655375, 983065, 0
    };

static const sint32 connected_passed_pawn_value[8] =
    {
	0, 0, 0, 0, 327690, 655375, 1310750, 0
    };

static const sint32 candidate_passed_pawn_value[8] =
    {
	0, 0, 0, 327685, 655372, 1310745, 0, 0
    };

static const uint32 my_passed_pawn_clear_value[8] =
    {
	0, 0, 0, 0, 0, 196613, 327690, 0
    };

static const uint32 opp_passed_pawn_clear_value[8] =
    {
	0, 0, 0, 0, 327690, 983070, 1638450
    };

static const uint32 passed_pawn_is_mobile_value[8] =
    {
	0, 0, 0, 65538, 131075, 196613, 327690, 0
    };

static const uint32 passed_pawn_is_free_value[8] =
    {
	0, 0, 0, 0, 327690, 655380, 1310760
    };

static const sint32 my_king_pawn_distance[8] =
    {
    0, 0, 0, 1, 2, 3, 5, 0
    };

static const sint32 opp_king_pawn_distance[8] =
    {
    0, 0, 0, 2, 4, 6, 10, 0
    };

static const uint8 aa_shelter[8] =
    {
    30, 0, 5, 15, 20, 25, 25, 25
    };

static const uint8 ab_shelter[8] =
    {
    55, 0, 15, 40, 50, 55, 55, 55
    };

static const uint8 ac_shelter[8] =
    {
    30, 0, 10, 20, 25, 30, 30, 30
    };

static const uint8 aa_storm[8] =
    {
    5, 0, 35, 15, 5, 0, 0, 0
    };

static const uint8 ab_storm[8] =
    {
    10, 0, 50, 20, 10, 0, 0, 0
    };

static const uint8 ac_storm[8] =
    {
    10, 0, 50, 20, 10, 0, 0, 0
    };

static const uint8 ba_shelter[8] =
    {
    30, 0, 5, 15, 20, 25, 25, 25
    };

static const uint8 bb_shelter[8] =
    {
    55, 0, 15, 40, 50, 55, 55, 55
    };

static const uint8 bc_shelter[8] =
    {
    30, 0, 10, 20, 25, 30, 30, 30
    };

static const uint8 ba_storm[8] =
    {
    5, 0, 35, 15, 5, 0, 0, 0
    };

static const uint8 bb_storm[8] =
    {
    10, 0, 50, 20, 10, 0, 0, 0
    };

static const uint8 bc_storm[8] =
    {
    10, 0, 50, 20, 10, 0, 0, 0
    };

static const uint8 cb_shelter[8] =
    {
    30, 0, 5, 15, 20, 25, 25, 25
    };

static const uint8 cc_shelter[8] =
    {
    55, 0, 15, 40, 50, 55, 55, 55
    };

static const uint8 cd_shelter[8] =
    {
    30, 0, 10, 20, 25, 30, 30, 30
    };

static const uint8 cb_storm[8] =
    {
    5, 0, 35, 15, 5, 0, 0, 0
    };

static const uint8 cc_storm[8] =
    {
    10, 0, 50, 20, 10, 0, 0, 0
    };

static const uint8 cd_storm[8] =
    {
    10, 0, 50, 20, 10, 0, 0, 0
    };

static const uint8 dc_shelter[8] =
    {
    30, 0, 5, 15, 20, 25, 25, 25
    };

static const uint8 dd_shelter[8] =
    {
    55, 0, 15, 40, 50, 55, 55, 55
    };

static const uint8 de_shelter[8] =
    {
    30, 0, 10, 20, 25, 30, 30, 30
    };

static const uint8 dc_storm[8] =
    {
    5, 0, 35, 15, 5, 0, 0, 0
    };

static const uint8 dd_storm[8] =
    {
    10, 0, 50, 20, 10, 0, 0, 0
    };

static const uint8 de_storm[8] =
    {
    10, 0, 50, 20, 10, 0, 0, 0
    };

static const uint8 shelter_diag_a[8] =
    {
    10, 0, 2, 4, 6, 8, 10, 10
    };

static const uint8 shelter_diag_b[8] =
    {
    8, 0, 2, 4, 6, 7, 8, 8
    };

static const uint8 shelter_diag_c[8] =
    {
    6, 0, 2, 3, 4, 5, 6, 6
    };

static const uint8 shelter_diag_d[8] =
    {
    4, 0, 1, 2, 3, 4, 4, 4
    };

static const int PST[16][64] =
	{
	{ // Dummy
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0
	},
	{ // white pawn
	0, 0, 0, 0, 0, 0, 0, 0, 
	-1507335, -720905, -327691, 131059, 131059, -327691, -720905, -1507335, 
	-1441799, -655369, -262155, 196595, 196595, -262155, -655369, -1441799, 
	-1376262, -589832, -196618, 262132, 262132, -196618, -589832, -1376262, 
	-1245189, -458759, -65545, 393205, 393205, -65545, -458759, -1245189, 
	-1179652, -393222, -8, 458742, 458742, -8, -393222, -1179652, 
	-1114114, -327684, 65530, 524280, 524280, 65530, -327684, -1114114,
	0, 0, 0, 0, 0, 0, 0, 0
	},
	{ // wite knight
	-3801110, -2752529, -2031628, -1769481, -1769481, -2031628, -2752529, -3801110, 
	-2359311, -1310728, -589828, -327682, -327682, -589828, -1310728, -2359311, 
	-1310730, -262148, 458753, 720899, 720899, 458753, -262148, -1310730, 
	-720902, 327679, 1048580, 1310728, 1310728, 1048580, 327679, -720902, 
	-327684, 720897, 1441798, 1703946, 1703946, 1441798, 720897, -327684, 
	-458755, 589827, 1310728, 1572874, 1572874, 1310728, 589827, -458755, 
	-1048584, -1, 720899, 983045, 983045, 720899, -1, -1048584, 
	-7864335, -1376266, -655365, -393218, -393218, -655365, -1376266, -7864335
	},
	{ // white king
	2883511, 3211214, 1245150, -65564, -65564, 1245150, 3211214, 2883511, 
	2686936, 3014641, 1048573, -262141, -262141, 1048573, 3014641, 2686936, 
	2490339, 2818040, 851975, -458739, -458739, 851975, 2818040, 2490339, 
	2293737, 2621438, 655373, -655338, -655338, 655373, 2621438, 2293737, 
	1966062, 2293763, 327698, -983013, -983013, 327698, 2293763, 1966062, 
	1638376, 1966077, 12, -1310702, -1310702, 12, 1966077, 1638376, 
	983005, 1310710, -655358, -1966072, -1966072, -655358, 1310710, 983005, 
	327627, 655330, -1310734, -2621448, -2621448, -1310734, 655330, 327627 
	},
	{ // white king bishop
	-458752, -524289, -720898, -851970, -851970, -720898, -524289, -458752, 
	-196609, 196609, 0, -131072, -131072, 0, 196609, -196609, 
	-393218, 0, 458755, 393218, 393218, 458755, 0, -393218, 
	-524290, -131072, 393218, 983045, 983045, 393218, -131072, -524290, 
	-524290, -131072, 393218, 983045, 983045, 393218, -131072, -524290, 
	-393218, 0, 458755, 393218, 393218, 458755, 0, -393218, 
	-196609, 196609, 0, -131072, -131072, 0, 196609, -196609, 
	-131072, -196609, -393218, -524290, -524290, -393218, -196609, -131072
	},
	{ // white queen bishop
	-458752, -524289, -720898, -851970, -851970, -720898, -524289, -458752, 
	-196609, 196609, 0, -131072, -131072, 0, 196609, -196609, 
	-393218, 0, 458755, 393218, 393218, 458755, 0, -393218, 
	-524290, -131072, 393218, 983045, 983045, 393218, -131072, -524290, 
	-524290, -131072, 393218, 983045, 983045, 393218, -131072, -524290, 
	-393218, 0, 458755, 393218, 393218, 458755, 0, -393218, 
	-196609, 196609, 0, -131072, -131072, 0, 196609, -196609, 
	-131072, -196609, -393218, -524290, -524290, -393218, -196609, -131072
	},
	{ // white rook
	-262144, 0, 262144, 524288, 524288, 262144, 0, -262144, 
	-262144, 0, 262144, 524288, 524288, 262144, 0, -262144, 
	-262144, 0, 262144, 524288, 524288, 262144, 0, -262144, 
	-262144, 0, 262144, 524288, 524288, 262144, 0, -262144, 
	-262143, 1, 262145, 524289, 524289, 262145, 1, -262143, 
	-262143, 1, 262145, 524289, 524289, 262145, 1, -262143, 
	-262143, 1, 262145, 524289, 524289, 262145, 1, -262143, 
	-262146, -2, 262142, 524286, 524286, 262142, -2, -262146
	},
	{ // white queen
	-1048591, -786442, -589832, -458759, -458759, -589832, -786442, -1048591, 
	-458762, -65541, 65533, 196606, 196606, 65533, -65541, -458762, 
	-262152, 65533, 327680, 393218, 393218, 327680, 65533, -262152, 
	-131079, 196606, 393218, 589829, 589829, 393218, 196606, -131079, 
	-131079, 196606, 393218, 589829, 589829, 393218, 196606, -131079, 
	-262152, 65533, 327680, 393218, 393218, 327680, 65533, -262152, 
	-458762, -65541, 65533, 196606, 196606, 65533, -65541, -458762, 
	-720911, -458762, -262152, -131079, -131079, -262152, -458762, -720911
	},
	{ // dummy
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	},
	{ // black pawn
	0, 0, 0, 0, 0, 0, 0, 0, 
	1114114, 327684, -65530, -524280, -524280, -65530, 327684, 1114114, 
	1179652, 393222, 8, -458742, -458742, 8, 393222, 1179652, 
	1245189, 458759, 65545, -393205, -393205, 65545, 458759, 1245189, 
	1376262, 589832, 196618, -262132, -262132, 196618, 589832, 1376262, 
	1441799, 655369, 262155, -196595, -196595, 262155, 655369, 1441799, 
	1507335, 720905, 327691, -131059, -131059, 327691, 720905, 1507335,
	0, 0, 0, 0, 0, 0, 0, 0
	},
	{ // back knight
	7864335, 1376266, 655365, 393218, 393218, 655365, 1376266, 7864335, 
	1048584, 1, -720899, -983045, -983045, -720899, 1, 1048584, 
	458755, -589827, -1310728, -1572874, -1572874, -1310728, -589827, 458755, 
	327684, -720897, -1441798, -1703946, -1703946, -1441798, -720897, 327684, 
	720902, -327679, -1048580, -1310728, -1310728, -1048580, -327679, 720902, 
	1310730, 262148, -458753, -720899, -720899, -458753, 262148, 1310730, 
	2359311, 1310728, 589828, 327682, 327682, 589828, 1310728, 2359311, 
	3801110, 2752529, 2031628, 1769481, 1769481, 2031628, 2752529, 3801110
	},
	{ // black king
	-327627, -655330, 1310734, 2621448, 2621448, 1310734, -655330, -327627, 
	-983005, -1310710, 655358, 1966072, 1966072, 655358, -1310710, -983005, 
	-1638376, -1966077, -12, 1310702, 1310702, -12, -1966077, -1638376, 
	-1966062, -2293763, -327698, 983013, 983013, -327698, -2293763, -1966062, 
	-2293737, -2621438, -655373, 655338, 655338, -655373, -2621438, -2293737, 
	-2490339, -2818040, -851975, 458739, 458739, -851975, -2818040, -2490339, 
	-2686936, -3014641, -1048573, 262141, 262141, -1048573, -3014641, -2686936, 
	-2883511, -3211214, -1245150, 65564, 65564, -1245150, -3211214, -2883511
	},
	{ // black queen bishop
	131072, 196609, 393218, 524290, 524290, 393218, 196609, 131072, 
	196609, -196609, 0, 131072, 131072, 0, -196609, 196609, 
	393218, 0, -458755, -393218, -393218, -458755, 0, 393218, 
	524290, 131072, -393218, -983045, -983045, -393218, 131072, 524290, 
	524290, 131072, -393218, -983045, -983045, -393218, 131072, 524290, 
	393218, 0, -458755, -393218, -393218, -458755, 0, 393218, 
	196609, -196609, 0, 131072, 131072, 0, -196609, 196609, 
	458752, 524289, 720898, 851970, 851970, 720898, 524289, 458752
	},
	{ // back king bishop
	131072, 196609, 393218, 524290, 524290, 393218, 196609, 131072, 
	196609, -196609, 0, 131072, 131072, 0, -196609, 196609, 
	393218, 0, -458755, -393218, -393218, -458755, 0, 393218, 
	524290, 131072, -393218, -983045, -983045, -393218, 131072, 524290, 
	524290, 131072, -393218, -983045, -983045, -393218, 131072, 524290, 
	393218, 0, -458755, -393218, -393218, -458755, 0, 393218, 
	196609, -196609, 0, 131072, 131072, 0, -196609, 196609, 
	458752, 524289, 720898, 851970, 851970, 720898, 524289, 458752
	},
	{ // back rook
	262146, 2, -262142, -524286, -524286, -262142, 2, 262146, 
	262143, -1, -262145, -524289, -524289, -262145, -1, 262143, 
	262143, -1, -262145, -524289, -524289, -262145, -1, 262143, 
	262143, -1, -262145, -524289, -524289, -262145, -1, 262143, 
	262144, 0, -262144, -524288, -524288, -262144, 0, 262144, 
	262144, 0, -262144, -524288, -524288, -262144, 0, 262144, 
	262144, 0, -262144, -524288, -524288, -262144, 0, 262144, 
	262144, 0, -262144, -524288, -524288, -262144, 0, 262144
	},
	{ // black queen
	720911, 458762, 262152, 131079, 131079, 262152, 458762, 720911, 
	458762, 65541, -65533, -196606, -196606, -65533, 65541, 458762, 
	262152, -65533, -327680, -393218, -393218, -327680, -65533, 262152, 
	131079, -196606, -393218, -589829, -589829, -393218, -196606, 131079, 
	131079, -196606, -393218, -589829, -589829, -393218, -196606, 131079, 
	262152, -65533, -327680, -393218, -393218, -327680, -65533, 262152, 
	458762, 65541, -65533, -196606, -196606, -65533, 65541, 458762, 
	1048591, 786442, 589832, 458759, 458759, 589832, 786442, 1048591
	},
	};

