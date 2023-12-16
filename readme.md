# Overview
ChessMaster2023 is a chess engine written in C++. It supports both Winboard and UCI and has its own console interface. 

The engine is based on my old project (that I have never published), some of the auxiliary functions (mostly move generation, the magic bitboards) are based on [Stockfish](https://github.com/official-stockfish/Stockfish/tree/master).

The engine is developed as a hobby.

## Features
* Search:
1) NegaMax with Alpha-Beta
2) Quiescence search

* Static evaluation:
1) Material
2) Piece-Square Tables
3) Tempo

## Engine power
(This is an early version of engine, so its power is low)

ChessMaster was tested in a tournament against several other engines from CCRL
with time control 0:1+1.

Estimated elo: 1570 (computed with Bayeselo).

_The engine is expected to reach at least 2100 elo by the first release - such was the
rating of the original engine of mine._

## Contents
* ChessMaster2023/ - the source files
* ChessMaster2023.sln - Visual Studio Solution
* ChessMaster2023.exe - executable for Windows
* Makefile - can be used to build the engine with GCC
* changelog.txt - the history of versions
* LICENSE - the license (GNU GPL)


# Building
The project is made in Visual Studio and fully supports MSVC, for MSVC there is a VS solution file. Also, GNU GCC is supported.
To build with GCC, a Makefile is provided.

# Roadmap
The features that are supposed to be implemented by the future versions (most of which were implemented in the old ChessMaster of mine):

* 0.3) Move ordering (SEE, hash tables, history heuristic, killer moves, etc...)
* 0.4) Pawns update (passed pawns, candidates, pawn structure, pawn blockade, backward pawns, 
	 double pawns, isolated pawns, fakers?, connected pawns, hanging pawns,
	 pawn islands, holes, pawn majority, pawn race, weak pawns, dispertion/distotrion...)
* 0.5) Extensions (single move extension, check extension, capture/recapture extension,
	 passed pawn extension, PV extension, singular extension...)
* 0.6) Prunings and reductions (futility pruning, nullmove pruning, razoring, LMR, aspiration window,
	 mate distance pruning, multi-cut, probcut, history leaf pruning...)
* 0.7) Miscelaneous small updates:
* 0.7.0) Separate evaluations for specific endgames
* 0.7.1) Evaluation for material combinations
* 0.7.2) Internal Iterative Deepening
* 0.8) Pieces update (mobility, space, connectivity, center control, trapped pieces...)
* 0.8.1) Knights and bishops (outposts, bad bishop, fianchetto, color weakness
* 0.8.2) Rooks and queens (rook on (semi)open file, rook behind a passed, rook on seventh rank,
	   paired rooks, queens penalty for early development, tropism?)
* 0.9) King update (mate at a glance, pins/x-rays, castlings (rights), pawn shield, pawn storm, tropism,
	 virtual mobility, scaling with material, king zone attack, square control in king zone, king pawn tropism)
* 0.10) General endgame evaluation and search improvement, parallel search
* 1.0) Final improvements before the first release: some small additions, optimization, bugs fixing...)
* 1.1) Evaluation weights search via learning
* 1.2) ???


# License
ChessMaster is distributed under [GNU General Public License](https://www.gnu.org/licenses/).
