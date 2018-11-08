{\rtf1\ansi\ansicpg1252\cocoartf1561\cocoasubrtf600
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;\red0\green0\blue0;}
{\*\expandedcolortbl;;\cssrgb\c0\c0\c0;}
\margl1440\margr1440\vieww15540\viewh10800\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 README \
\
EE312 HW #6- Go Fish\
Sarah Bi, Mayna Nguyen\
sb48785, mhn436 \
==========================\
\
This directory  contains the necessary file to run a simple Go Fish game. \cf2 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 This is a two player game and 7 cards are dealt to each player at the beginning of the game. The remaining card pack is placed between the players.\
\
\pard\pardeftab720\sl280\sa240\partightenfactor0
\cf2 The player whose turn it is to play asks another player for their cards of a particular rank. For example, "Agatha, do you have any threes?". A player may only ask for a rank of which they already hold at least one card. The recipient of the request must then hand over a card of that rank. If the player who was asked has no cards of that rank, they say "Go fish", and the asking player draws the top card from the pack. The turn then passes to the other player (i.e. the turn ends when a player either gets a card or draws a card). \
When one player has two of the same cards of a given rank, they form a\'a0
\i pair
\i0 , and the cards are placed face up on the table. The game ends when all twenty-six books are formed, and the player who won the most books wins.\
If the player whose turn it is has no cards left in hand, the game is not over, but they simply draw the top card from the pack and the turn passes to the other player.\
The results are outputted in a text file named Go_Fish.txt.\
}