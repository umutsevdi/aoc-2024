
#include "aoc.h"
#include "util.h"

static void run(char* argv);
SOLUTION(
    1,
    {.cmd = "--historian-hysteria",
     .description =
         "The Chief Historian is always present for the big Christmas\r\n"
         "sleigh launch, but nobody has seen him in months! Last anyone\r\n"
         "heard, he was visiting locations that are historically\r\n"
         "significant to the North Pole; a group of Senior Historians has\r\n"
         "asked you to accompany them as they check the places they think\r\n"
         "he was most likely to visit.\r\n"
         "\r\n"
         "As each location is checked, they will mark it on their list\r\n"
         "with a star. They figure the Chief Historian must be in one\r\n"
         "of the first fifty places they'll look, so in order to save\r\n"
         "Christmas, you need to help them get fifty stars on their list\r\n"
         "before Santa takes off on December 25th.\r\n"
         "\r\n"
         "Collect stars by solving puzzles. Two puzzles will be made\r\n"
         "available on each day in the Advent calendar; the second\r\n"
         "puzzle is unlocked when you complete the first. Each puzzle\r\n"
         "grants one star. Good luck!\r\n"
         "\r\n"
         "You haven't even left yet and the group of Elvish Senior\r\n"
         "Historians has already hit a problem: their list of locations\r\n"
         "to check is currently empty. Eventually, someone decides that\r\n"
         "the best place to check first would be the Chief\r\n"
         "Historian's office.\r\n"
         "\r\n"
         "Upon pouring into the office, everyone confirms that the\r\n"
         "Chief Historian is indeed nowhere to be found. Instead, the\r\n"
         "Elves discover an assortment of notes and lists of historically\r\n"
         "significant locations! This seems to be the planning the \r\n"
         "Chief Historian was doing before he left. Perhaps these\r\n"
         "notes can be used to determine which locations to search?\r\n"
         "\r\n"
         "Throughout the Chief's office, the historically significant\r\n"
         "locations are listed not by name but by a unique number called\r\n"
         "the location ID. To make sure they don't miss anything,\r\n"
         "The Historians split into two groups, each searching the office \r\n"
         "and trying to create their own complete list of location IDs.\r\n"
         "\r\n"
         "There's just one problem: by holding the two lists up side\r\n"
         "by side (your puzzle input), it quickly becomes clear that \r\n"
         "the lists aren't very similar. Maybe you can help The\r\n"
         "Historians reconcile their lists?\r\n",
     .run = run});

static void run(char* input) { printf("Received %s\r\n", input); }
