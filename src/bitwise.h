#ifndef BITWISE_H
#define BITWISE_H

// Using macros for ease of use, can also use inline functons, but I don't see the point.

/*
 * From (Position): 6 bits (2^6 == 64) possibilities
 * To (Position): same as above
 * Captured piece, if any: 4 bits (16) possibilities
 * Promoted to, if any: 4 bits (16) possibilities
 * en passant flag: 1 bit
 * pawn starting move flag: 1 bit
 * castle move flag: 1 bit
 *
 *	0000 0000 0000 0000 0011 1111 -> From square position (0x3F)
 *	0000 0000 0000 1111 1100 0000 -> To square position (>> 6 0xFB)
 *	0000 0000 1111 0000 0000 0000 -> captured piece, if any (>> 12 0xF)
 *	0000 1111 0000 0000 0000 0000 -> if prmoted, what to? (>> 16 0xF)
 *	0001 0000 0000 0000 0000 0000 -> en passant (0x100000)
 *	0010 0000 0000 0000 0000 0000 -> pawn starting move (0x200000)
 *	0100 0000 0000 0000 0000 0000 -> castle move (0x400000)
 * */

#define FROMSQ(m) ((m) & 0x3f)
#define TOSQ(m) ((m>>6) & 0x3f)

#endif
