var searchData=
[
  ['setup_5fsolution_5flist_0',['setup_solution_list',['../default_8c.html#a8cf6393d12a3398e7a079faec723a592',1,'setup_solution_list():&#160;default.c'],['../aoc_8h.html#a8cf6393d12a3398e7a079faec723a592',1,'setup_solution_list():&#160;default.c']]],
  ['solution_1',['SOLUTION',['../1_8c.html#a3fce26e89ac8310f7addc60e85769604',1,'SOLUTION(1, {.cmd=&quot;--historian-hysteria&quot;,.description=&quot;The Chief Historian is always present for the big Christmas\r\n&quot; &quot;sleigh launch, but nobody has seen him in months! Last anyon\r\n&quot; &quot;e heard, he was visiting locations that are historically sig\r\n&quot; &quot;nificant to the North Pole; a group of Senior Historians has\r\n&quot; &quot; asked you to accompany them as they check the places they t\r\n&quot; &quot;hink he was most likely to visit.\r\n&quot; &quot;\r\n&quot; &quot;As each location is checked, they will mark it on their list\r\n&quot; &quot; with a star. They figure the Chief Historian must be in one\r\n&quot; &quot; of the first fifty places they&apos;ll look, so in order to save\r\n&quot; &quot; Christmas, you need to help them get fifty stars on their l\r\n&quot; &quot;ist before Santa takes off on December 25th.\r\n&quot; &quot;\r\n&quot; &quot;Collect stars by solving puzzles. Two puzzles will be made a\r\n&quot; &quot;vailable on each day in the Advent calendar; the second puzz\r\n&quot; &quot;le is unlocked when you complete the first. Each puzzle gran\r\n&quot; &quot;ts one star. Good luck!\r\n&quot; &quot;\r\n&quot; &quot;You haven&apos;t even left yet and the group of Elvish Senior His\r\n&quot; &quot;torians has already hit a problem: their list of locations t\r\n&quot; &quot;o check is currently empty. Eventually, someone decides that\r\n&quot; &quot; the best place to check first would be the Chief Historian&apos;\r\n&quot; &quot;s office.\r\n&quot; &quot;\r\n&quot; &quot;Upon pouring into the office, everyone confirms that the Chi\r\n&quot; &quot;ef Historian is indeed nowhere to be found. Instead, the Elv\r\n&quot; &quot;es discover an assortment of notes and lists of historically\r\n&quot; &quot; significant locations! This seems to be the planning the Ch\r\n&quot; &quot;ief Historian was doing before he left. Perhaps these notes\r\n&quot; &quot;can be used to determine which locations to search?\r\n&quot; &quot;\r\n&quot; &quot;Throughout the Chief&apos;s office, the historically significant\r\n&quot; &quot;locations are listed not by name but by a unique number call\r\n&quot; &quot;ed the location ID. To make sure they don&apos;t miss anything, T\r\n&quot; &quot;he Historians split into two groups, each searching the offi\r\n&quot; &quot;ce and trying to create their own complete list of location\r\n&quot; &quot;IDs.\r\n&quot; &quot;\r\n&quot; &quot;There&apos;s just one problem: by holding the two lists up side b\r\n&quot; &quot;y side (your puzzle input), it quickly becomes clear that th\r\n&quot; &quot;e lists aren&apos;t very similar. Maybe you can help The Historia\r\n&quot; &quot;ns reconcile their lists?\r\n&quot; &quot;\r\n&quot; &quot;For example:\r\n&quot; &quot;\r\n&quot; &quot;3   4\r\n&quot; &quot;4   3\r\n&quot; &quot;2   5\r\n&quot; &quot;1   3\r\n&quot; &quot;3   9\r\n&quot; &quot;3   3\r\n&quot; &quot;\r\n&quot; &quot;Maybe the lists are only off by a small amount! To find out,\r\n&quot; &quot; pair up the numbers and measure how far apart they are. Pai\r\n&quot; &quot;r up the smallest number in the left list with the smallest\r\n&quot; &quot;number in the right list, then the second-smallest left numb\r\n&quot; &quot;er with the second-smallest right number, and so on.\r\n&quot; &quot;\r\n&quot; &quot;Within each pair, figure out how far apart the two numbers a\r\n&quot; &quot;re; you&apos;ll need to add up all of those distances. For exampl\r\n&quot; &quot;e, if you pair up a 3 from the left list with a 7 from the r\r\n&quot; &quot;ight list, the distance apart is 4; if you pair up a 9 with\r\n&quot; &quot;a 3, the distance apart is 6.\r\n&quot; &quot;\r\n&quot; &quot;In the example list above, the pairs and distances would be\r\n&quot; &quot;as follows:\r\n&quot; &quot;\r\n&quot; &quot;    The smallest number in the left list is 1, and the small\r\n&quot; &quot;est number in the right list is 3. The distance between them\r\n&quot; &quot; is 2.\r\n&quot; &quot;    The second-smallest number in the left list is 2, and th\r\n&quot; &quot;e second-smallest number in the right list is another 3. The\r\n&quot; &quot; distance between them is 1.\r\n&quot; &quot;    The third-smallest number in both lists is 3, so the dis\r\n&quot; &quot;tance between them is 0.\r\n&quot; &quot;    The next numbers to pair up are 3 and 4, a distance of 1\r\n&quot; &quot;.\r\n&quot; &quot;    The fifth-smallest numbers in each list are 3 and 5, a d\r\n&quot; &quot;istance of 2.\r\n&quot; &quot;    Finally, the largest number in the left list is 4, while\r\n&quot; &quot; the largest number in the right list is 9; these are a dist\r\n&quot; &quot;ance 5 apart.\r\n&quot; &quot;\r\n&quot; &quot;To find the total distance between the left list and the rig\r\n&quot; &quot;ht list, add up the distances between all of the pairs you f\r\n&quot; &quot;ound. In the example above, this is 2 + 1 + 0 + 1 + 2 + 5, a\r\n&quot; &quot; total distance of 11!\r\n&quot; &quot;\r\n&quot; &quot;Your actual left and right lists contain many location IDs.\r\n&quot; &quot;What is the total distance between your lists?\r\n&quot; &quot;\r\n&quot; &quot;--- Part Two ---\r\n&quot; &quot;\r\n&quot; &quot;Your analysis only confirmed what everyone feared: the two l\r\n&quot; &quot;ists of location IDs are indeed very different.\r\n&quot; &quot;\r\n&quot; &quot;Or are they?\r\n&quot; &quot;\r\n&quot; &quot;The Historians can&apos;t agree on which group made the mistakes\r\n&quot; &quot;or how to read most of the Chief&apos;s handwriting, but in the c\r\n&quot; &quot;ommotion you notice an interesting detail: a lot of location\r\n&quot; &quot; IDs appear in both lists! Maybe the other numbers aren&apos;t lo\r\n&quot; &quot;cation IDs at all but rather misinterpreted handwriting.\r\n&quot; &quot;\r\n&quot; &quot;This time, you&apos;ll need to figure out exactly how often each\r\n&quot; &quot;number from the left list appears in the right list. Calcula\r\n&quot; &quot;te a total similarity score by adding up each number in the\r\n&quot; &quot;left list after multiplying it by the number of times that n\r\n&quot; &quot;umber appears in the right list.\r\n&quot; &quot;\r\n&quot; &quot;Here are the same example lists again:\r\n&quot; &quot;\r\n&quot; &quot;3   4\r\n&quot; &quot;4   3\r\n&quot; &quot;2   5\r\n&quot; &quot;1   3\r\n&quot; &quot;3   9\r\n&quot; &quot;3   3\r\n&quot; &quot;\r\n&quot; &quot;For these example lists, here is the process of finding the\r\n&quot; &quot;similarity score:\r\n&quot; &quot;\r\n&quot; &quot;    The first number in the left list is 3. It appears in th\r\n&quot; &quot;e right list three times, so the similarity score increases\r\n&quot; &quot;by 3 * 3 = 9.\r\n&quot; &quot;    The second number in the left list is 4. It appears in t\r\n&quot; &quot;he right list once, so the similarity score increases by 4 *\r\n&quot; &quot; 1 = 4.\r\n&quot; &quot;    The third number in the left list is 2. It does not appe\r\n&quot; &quot;ar in the right list, so the similarity score does not incre\r\n&quot; &quot;ase (2 * 0 = 0).\r\n&quot; &quot;    The fourth number, 1, also does not appear in the right\r\n&quot; &quot;list.\r\n&quot; &quot;    The fifth number, 3, appears in the right list three tim\r\n&quot; &quot;es; the similarity score increases by 9.\r\n&quot; &quot;    The last number, 3, appears in the right list three time\r\n&quot; &quot;s; the similarity score again increases by 9.\r\n&quot; &quot;\r\n&quot; &quot;So, for these example lists, the similarity score at the end\r\n&quot; &quot; of this process is 31 (9 + 4 + 0 + 0 + 9 + 9).\r\n&quot; &quot;\r\n&quot; &quot;Once again consider your left and right lists. What is their\r\n&quot; &quot; similarity score?\r\n&quot;,.run=run}):&#160;1.c'],['../2_8c.html#a11bd7c61429442cb9c53605233e5c122',1,'SOLUTION(2, {.cmd=&quot;--red-nosed-reports&quot;,.description=&quot;Fortunately, the first location The Historians want to searc\r\n&quot; &quot;h isn&apos;t a long walk from the Chief Historian&apos;s office.\r\n&quot; &quot;\r\n&quot; &quot;While the Red-Nosed Reindeer nuclear fusion/fission plant ap\r\n&quot; &quot;pears to contain no sign of the Chief Historian, the enginee\r\n&quot; &quot;rs there run up to you as soon as they see you. Apparently,\r\n&quot; &quot;they still talk about the time Rudolph was saved through mol\r\n&quot; &quot;ecular synthesis from a single electron.\r\n&quot; &quot;\r\n&quot; &quot;They&apos;re quick to add that - since you&apos;re already here - they\r\n&quot; &quot;&apos;d really appreciate your help analyzing some unusual data f\r\n&quot; &quot;rom the Red-Nosed reactor. You turn to check if The Historia\r\n&quot; &quot;ns are waiting for you, but they seem to have already divide\r\n&quot; &quot;d into groups that are currently searching every corner of t\r\n&quot; &quot;he facility. You offer to help with the unusual data.\r\n&quot; &quot;\r\n&quot; &quot;The unusual data (your puzzle input) consists of many report\r\n&quot; &quot;s, one report per line. Each report is a list of numbers cal\r\n&quot; &quot;led levels that are separated by spaces. For example:\r\n&quot; &quot;\r\n&quot; &quot;7 6 4 2 1\r\n&quot; &quot;1 2 7 8 9\r\n&quot; &quot;9 7 6 2 1\r\n&quot; &quot;1 3 2 4 5\r\n&quot; &quot;8 6 4 4 1\r\n&quot; &quot;1 3 6 7 9\r\n&quot; &quot;\r\n&quot; &quot;This example data contains six reports each containing five\r\n&quot; &quot;levels.\r\n&quot; &quot;\r\n&quot; &quot;The engineers are trying to figure out which reports are saf\r\n&quot; &quot;e. The Red-Nosed reactor safety systems can only tolerate le\r\n&quot; &quot;vels that are either gradually increasing or gradually decre\r\n&quot; &quot;asing. So, a report only counts as safe if both of the follo\r\n&quot; &quot;wing are true:\r\n&quot; &quot;\r\n&quot; &quot;    The levels are either all increasing or all decreasing.\r\n&quot; &quot;    Any two adjacent levels differ by at least one and at mo\r\n&quot; &quot;st three.\r\n&quot; &quot;\r\n&quot; &quot;In the example above, the reports can be found safe or unsaf\r\n&quot; &quot;e by checking those rules:\r\n&quot; &quot;\r\n&quot; &quot;    7 6 4 2 1: Safe because the levels are all decreasing by\r\n&quot; &quot; 1 or 2.\r\n&quot; &quot;    1 2 7 8 9: Unsafe because 2 7 is an increase of 5.\r\n&quot; &quot;    9 7 6 2 1: Unsafe because 6 2 is a decrease of 4.\r\n&quot; &quot;    1 3 2 4 5: Unsafe because 1 3 is increasing but 3 2 is d\r\n&quot; &quot;ecreasing.\r\n&quot; &quot;    8 6 4 4 1: Unsafe because 4 4 is neither an increase or\r\n&quot; &quot;a decrease.\r\n&quot; &quot;    1 3 6 7 9: Safe because the levels are all increasing by\r\n&quot; &quot; 1, 2, or 3.\r\n&quot; &quot;\r\n&quot; &quot;So, in this example, 2 reports are safe.\r\n&quot; &quot;\r\n&quot; &quot;Analyze the unusual data from the engineers. How many report\r\n&quot; &quot;s are safe?\r\n&quot; &quot;\r\n&quot; &quot;--- Part Two ---\r\n&quot; &quot;\r\n&quot; &quot;The engineers are surprised by the low number of safe report\r\n&quot; &quot;s until they realize they forgot to tell you about the Probl\r\n&quot; &quot;em Dampener.\r\n&quot; &quot;\r\n&quot; &quot;The Problem Dampener is a reactor-mounted module that lets t\r\n&quot; &quot;he reactor safety systems tolerate a single bad level in wha\r\n&quot; &quot;t would otherwise be a safe report. It&apos;s like the bad level\r\n&quot; &quot;never happened!\r\n&quot; &quot;\r\n&quot; &quot;Now, the same rules apply as before, except if removing a si\r\n&quot; &quot;ngle level from an unsafe report would make it safe, the rep\r\n&quot; &quot;ort instead counts as safe.\r\n&quot; &quot;\r\n&quot; &quot;More of the above example&apos;s reports are now safe:\r\n&quot; &quot;\r\n&quot; &quot;    7 6 4 2 1: Safe without removing any level.\r\n&quot; &quot;    1 2 7 8 9: Unsafe regardless of which level is removed.\r\n&quot; &quot;    9 7 6 2 1: Unsafe regardless of which level is removed.\r\n&quot; &quot;    1 3 2 4 5: Safe by removing the second level, 3.\r\n&quot; &quot;    8 6 4 4 1: Safe by removing the third level, 4.\r\n&quot; &quot;    1 3 6 7 9: Safe without removing any level.\r\n&quot; &quot;\r\n&quot; &quot;Thanks to the Problem Dampener, 4 reports are actually safe!\r\n&quot; &quot;\r\n&quot; &quot;Update your analysis by handling situations where the Proble\r\n&quot; &quot;m Dampener can remove a single level from unsafe reports. Ho\r\n&quot; &quot;w many reports are now safe?\r\n&quot;,.run=run}):&#160;2.c'],['../3_8c.html#a8095da577f57388004e1429d002cb9a2',1,'SOLUTION(3, {.cmd=&quot;--mull-it-over&quot;,.description=&quot;\&quot;Our computers are having issues, so I have no idea if we ha\r\n&quot; &quot;ve any Chief Historians in stock! You&apos;re welcome to check th\r\n&quot; &quot;e warehouse, though,\&quot; says the mildly flustered shopkeeper a\r\n&quot; &quot;t the North Pole Toboggan Rental Shop. The Historians head o\r\n&quot; &quot;ut to take a look.\r\n&quot; &quot;\r\n&quot; &quot;The shopkeeper turns to you. \&quot;Any chance you can see why our\r\n&quot; &quot; computers are having issues again?\&quot;\r\n&quot; &quot;\r\n&quot; &quot;The computer appears to be trying to run a program, but its\r\n&quot; &quot;memory (your puzzle input) is corrupted. All of the instruct\r\n&quot; &quot;ions have been jumbled up!\r\n&quot; &quot;\r\n&quot; &quot;It seems like the goal of the program is just to multiply so\r\n&quot; &quot;me numbers. It does that with instructions like mul(X,Y), wh\r\n&quot; &quot;ere X and Y are each 1-3 digit numbers. For instance, mul(44\r\n&quot; &quot;,46) multiplies 44 by 46 to get a result of 2024. Similarly,\r\n&quot; &quot; mul(123,4) would multiply 123 by 4.\r\n&quot; &quot;\r\n&quot; &quot;However, because the program&apos;s memory has been corrupted, th\r\n&quot; &quot;ere are also many invalid characters that should be ignored,\r\n&quot; &quot; even if they look like part of a mul instruction. Sequences\r\n&quot; &quot; like mul(4*, mul(6,9!, ?(12,34), or mul ( 2 , 4 ) do nothin\r\n&quot; &quot;g.\r\n&quot; &quot;\r\n&quot; &quot;For example, consider the following section of corrupted mem\r\n&quot; &quot;ory:\r\n&quot; &quot;\r\n&quot; &quot;xmul(2,4)%&amp;mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,\r\n&quot; &quot;8)mul(8,5))\r\n&quot; &quot;\r\n&quot; &quot;Only the four highlighted sections are real mul instructions\r\n&quot; &quot;. Adding up the result of each instruction produces 161 (2*4\r\n&quot; &quot; + 5*5 + 11*8 + 8*5).\r\n&quot; &quot;\r\n&quot; &quot;Scan the corrupted memory for uncorrupted mul instructions.\r\n&quot; &quot;What do you get if you add up all of the results of the mult\r\n&quot; &quot;iplications?\r\n&quot; &quot;\r\n&quot; &quot;--- Part Two ---\r\n&quot; &quot;\r\n&quot; &quot;As you scan through the corrupted memory, you notice that so\r\n&quot; &quot;me of the conditional statements are also still intact. If y\r\n&quot; &quot;ou handle some of the uncorrupted conditional statements in\r\n&quot; &quot;the program, you might be able to get an even more accurate\r\n&quot; &quot;result.\r\n&quot; &quot;\r\n&quot; &quot;There are two new instructions you&apos;ll need to handle:\r\n&quot; &quot;\r\n&quot; &quot;    The do() instruction enables future mul instructions.\r\n&quot; &quot;    The don&apos;t() instruction disables future mul instructions\r\n&quot; &quot;.\r\n&quot; &quot;\r\n&quot; &quot;Only the most recent do() or don&apos;t() instruction applies. At\r\n&quot; &quot; the beginning of the program, mul instructions are enabled.\r\n&quot; &quot;\r\n&quot; &quot;For example:\r\n&quot; &quot;\r\n&quot; &quot;xmul(2,4)&amp;mul[3,7]!^don&apos;t()_mul(5,5)+mul(32,64](mul(11,8)und\r\n&quot; &quot;o()?mul(8,5))\r\n&quot; &quot;\r\n&quot; &quot;This corrupted memory is similar to the example from before,\r\n&quot; &quot; but this time the mul(5,5) and mul(11,8) instructions are d\r\n&quot; &quot;isabled because there is a don&apos;t() instruction before them.\r\n&quot; &quot;The other mul instructions function normally, including the\r\n&quot; &quot;one at the end that gets re-enabled by a do() instruction.\r\n&quot; &quot;\r\n&quot; &quot;This time, the sum of the results is 48 (2*4 + 8*5).\r\n&quot; &quot;\r\n&quot; &quot;Handle the new instructions; what do you get if you add up a\r\n&quot; &quot;ll of the results of just the enabled multiplications?\r\n&quot;,.run=run}):&#160;3.c'],['../4_8c.html#a719dc8aa42a4f1976e19445f93f8f0d2',1,'SOLUTION(4, {.cmd=&quot;--ceres-search&quot;,.description=&quot;\&quot;Looks like the Chief&apos;s not here. Next!\&quot; One of The Historia\r\n&quot; &quot;ns pulls out a device and pushes the only button on it. Afte\r\n&quot; &quot;r a brief flash, you recognize the interior of the Ceres mon\r\n&quot; &quot;itoring station!\r\n&quot; &quot;\r\n&quot; &quot;As the search for the Chief continues, a small Elf who lives\r\n&quot; &quot; on the station tugs on your shirt; she&apos;d like to know if yo\r\n&quot; &quot;u could help her with her word search (your puzzle input). S\r\n&quot; &quot;he only has to find one word: XMAS.\r\n&quot; &quot;\r\n&quot; &quot;This word search allows words to be horizontal, vertical, di\r\n&quot; &quot;agonal, written backwards, or even overlapping other words.\r\n&quot; &quot;It&apos;s a little unusual, though, as you don&apos;t merely need to f\r\n&quot; &quot;ind one instance of XMAS - you need to find all of them. Her\r\n&quot; &quot;e are a few ways XMAS might appear, where irrelevant charact\r\n&quot; &quot;ers have been replaced with .:\r\n&quot; &quot;\r\n&quot; &quot;..X...\r\n&quot; &quot;.SAMX.\r\n&quot; &quot;.A..A.\r\n&quot; &quot;XMAS.S\r\n&quot; &quot;.X....\r\n&quot; &quot;\r\n&quot; &quot;The actual word search will be full of letters instead. For\r\n&quot; &quot;example:\r\n&quot; &quot;\r\n&quot; &quot;MMMSXXMASM\r\n&quot; &quot;MSAMXMSMSA\r\n&quot; &quot;AMXSXMAAMM\r\n&quot; &quot;MSAMASMSMX\r\n&quot; &quot;XMASAMXAMM\r\n&quot; &quot;XXAMMXXAMA\r\n&quot; &quot;SMSMSASXSS\r\n&quot; &quot;SAXAMASAAA\r\n&quot; &quot;MAMMMXMMMM\r\n&quot; &quot;MXMXAXMASX\r\n&quot; &quot;\r\n&quot; &quot;In this word search, XMAS occurs a total of 18 times; here&apos;s\r\n&quot; &quot; the same word search again, but where letters not involved\r\n&quot; &quot;in any XMAS have been replaced with .:\r\n&quot; &quot;\r\n&quot; &quot;....XXMAS.\r\n&quot; &quot;.SAMXMS...\r\n&quot; &quot;...S..A...\r\n&quot; &quot;..A.A.MS.X\r\n&quot; &quot;XMASAMX.MM\r\n&quot; &quot;X.....XA.A\r\n&quot; &quot;S.S.S.S.SS\r\n&quot; &quot;.A.A.A.A.A\r\n&quot; &quot;..M.M.M.MM\r\n&quot; &quot;.X.X.XMASX\r\n&quot; &quot;\r\n&quot; &quot;Take a look at the little Elf&apos;s word search. How many times\r\n&quot; &quot;does XMAS appear?\r\n&quot; &quot;\r\n&quot; &quot;--- Part Two ---\r\n&quot; &quot;\r\n&quot; &quot;The Elf looks quizzically at you. Did you misunderstand the\r\n&quot; &quot;assignment?\r\n&quot; &quot;\r\n&quot; &quot;Looking for the instructions, you flip over the word search\r\n&quot; &quot;to find that this isn&apos;t actually an XMAS puzzle; it&apos;s an X-M\r\n&quot; &quot;AS puzzle in which you&apos;re supposed to find two MAS in the sh\r\n&quot; &quot;ape of an X. One way to achieve that is like this:\r\n&quot; &quot;\r\n&quot; &quot;M.S\r\n&quot; &quot;.A.\r\n&quot; &quot;M.S\r\n&quot; &quot;\r\n&quot; &quot;Irrelevant characters have again been replaced with . in the\r\n&quot; &quot; above diagram. Within the X, each MAS can be written forwar\r\n&quot; &quot;ds or backwards.\r\n&quot; &quot;\r\n&quot; &quot;Here&apos;s the same example from before, but this time all of th\r\n&quot; &quot;e X-MASes have been kept instead:\r\n&quot; &quot;\r\n&quot; &quot;.M.S......\r\n&quot; &quot;..A..MSMS.\r\n&quot; &quot;.M.S.MAA..\r\n&quot; &quot;..A.ASMSM.\r\n&quot; &quot;.M.S.M....\r\n&quot; &quot;..........\r\n&quot; &quot;S.S.S.S.S.\r\n&quot; &quot;.A.A.A.A..\r\n&quot; &quot;M.M.M.M.M.\r\n&quot; &quot;..........\r\n&quot; &quot;\r\n&quot; &quot;In this example, an X-MAS appears 9 times.\r\n&quot; &quot;\r\n&quot; &quot;Flip the word search from the instructions back over to the\r\n&quot; &quot;word search side and try again. How many times does an X-MAS\r\n&quot; &quot; appear?\r\n&quot;,.run=run}):&#160;4.c'],['../5_8c.html#aa3166d88e581ba0b25409d873d54716d',1,'SOLUTION(5, {.cmd=&quot;--print-queue&quot;,.description=&quot;Satisfied with their search on Ceres, the squadron of schola\r\n&quot; &quot;rs suggests subsequently scanning the stationery stacks of s\r\n&quot; &quot;ub-basement 17.\r\n&quot; &quot;\r\n&quot; &quot;The North Pole printing department is busier than ever this\r\n&quot; &quot;close to Christmas, and while The Historians continue their\r\n&quot; &quot;search of this historically significant facility, an Elf ope\r\n&quot; &quot;rating a very familiar printer beckons you over.\r\n&quot; &quot;\r\n&quot; &quot;The Elf must recognize you, because they waste no time expla\r\n&quot; &quot;ining that the new sleigh launch safety manual updates won&apos;t\r\n&quot; &quot; print correctly. Failure to update the safety manuals would\r\n&quot; &quot; be dire indeed, so you offer your services.\r\n&quot; &quot;\r\n&quot; &quot;Safety protocols clearly indicate that new pages for the saf\r\n&quot; &quot;ety manuals must be printed in a very specific order. The no\r\n&quot; &quot;tation X|Y means that if both page number X and page number\r\n&quot; &quot;Y are to be produced as part of an update, page number X mus\r\n&quot; &quot;t be printed at some point before page number Y.\r\n&quot; &quot;\r\n&quot; &quot;The Elf has for you both the page ordering rules and the pag\r\n&quot; &quot;es to produce in each update (your puzzle input), but can&apos;t\r\n&quot; &quot;figure out whether each update has the pages in the right or\r\n&quot; &quot;der.\r\n&quot; &quot;\r\n&quot; &quot;For example:\r\n&quot; &quot;\r\n&quot; &quot;47|53\r\n&quot; &quot;97|13\r\n&quot; &quot;97|61\r\n&quot; &quot;97|47\r\n&quot; &quot;75|29\r\n&quot; &quot;61|13\r\n&quot; &quot;75|53\r\n&quot; &quot;29|13\r\n&quot; &quot;97|29\r\n&quot; &quot;53|29\r\n&quot; &quot;61|53\r\n&quot; &quot;97|53\r\n&quot; &quot;61|29\r\n&quot; &quot;47|13\r\n&quot; &quot;75|47\r\n&quot; &quot;97|75\r\n&quot; &quot;47|61\r\n&quot; &quot;75|61\r\n&quot; &quot;47|29\r\n&quot; &quot;75|13\r\n&quot; &quot;53|13\r\n&quot; &quot;\r\n&quot; &quot;75,47,61,53,29\r\n&quot; &quot;97,61,53,29,13\r\n&quot; &quot;75,29,13\r\n&quot; &quot;75,97,47,61,53\r\n&quot; &quot;61,13,29\r\n&quot; &quot;97,13,75,29,47\r\n&quot; &quot;\r\n&quot; &quot;The first section specifies the page ordering rules, one per\r\n&quot; &quot; line. The first rule, 47|53, means that if an update includ\r\n&quot; &quot;es both page number 47 and page number 53, then page number\r\n&quot; &quot;47 must be printed at some point before page number 53. (47\r\n&quot; &quot;doesn&apos;t necessarily need to be immediately before 53; other\r\n&quot; &quot;pages are allowed to be between them.)\r\n&quot; &quot;\r\n&quot; &quot;The second section specifies the page numbers of each update\r\n&quot; &quot;. Because most safety manuals are different, the pages neede\r\n&quot; &quot;d in the updates are different too. The first update, 75,47,\r\n&quot; &quot;61,53,29, means that the update consists of page numbers 75,\r\n&quot; &quot; 47, 61, 53, and 29.\r\n&quot; &quot;\r\n&quot; &quot;To get the printers going as soon as possible, start by iden\r\n&quot; &quot;tifying which updates are already in the right order.\r\n&quot; &quot;\r\n&quot; &quot;In the above example, the first update (75,47,61,53,29) is i\r\n&quot; &quot;n the right order:\r\n&quot; &quot;\r\n&quot; &quot;    75 is correctly first because there are rules that put e\r\n&quot; &quot;ach other page after it: 75|47, 75|61, 75|53, and 75|29.\r\n&quot; &quot;    47 is correctly second because 75 must be before it (75|\r\n&quot; &quot;47) and every other page must be after it according to 47|61\r\n&quot; &quot;, 47|53, and 47|29.\r\n&quot; &quot;    61 is correctly in the middle because 75 and 47 are befo\r\n&quot; &quot;re it (75|61 and 47|61) and 53 and 29 are after it (61|53 an\r\n&quot; &quot;d 61|29).\r\n&quot; &quot;    53 is correctly fourth because it is before page number\r\n&quot; &quot;29 (53|29).\r\n&quot; &quot;    29 is the only page left and so is correctly last.\r\n&quot; &quot;\r\n&quot; &quot;Because the first update does not include some page numbers,\r\n&quot; &quot; the ordering rules involving those missing page numbers are\r\n&quot; &quot; ignored.\r\n&quot; &quot;\r\n&quot; &quot;The second and third updates are also in the correct order a\r\n&quot; &quot;ccording to the rules. Like the first update, they also do n\r\n&quot; &quot;ot include every page number, and so only some of the orderi\r\n&quot; &quot;ng rules apply - within each update, the ordering rules that\r\n&quot; &quot; involve missing page numbers are not used.\r\n&quot; &quot;\r\n&quot; &quot;The fourth update, 75,97,47,61,53, is not in the correct ord\r\n&quot; &quot;er: it would print 75 before 97, which violates the rule 97|\r\n&quot; &quot;75.\r\n&quot; &quot;\r\n&quot; &quot;The fifth update, 61,13,29, is also not in the correct order\r\n&quot; &quot;, since it breaks the rule 29|13.\r\n&quot; &quot;\r\n&quot; &quot;The last update, 97,13,75,29,47, is not in the correct order\r\n&quot; &quot; due to breaking several rules.\r\n&quot; &quot;\r\n&quot; &quot;For some reason, the Elves also need to know the middle page\r\n&quot; &quot; number of each update being printed. Because you are curren\r\n&quot; &quot;tly only printing the correctly-ordered updates, you will ne\r\n&quot; &quot;ed to find the middle page number of each correctly-ordered\r\n&quot; &quot;update. In the above example, the correctly-ordered updates\r\n&quot; &quot;are:\r\n&quot; &quot;\r\n&quot; &quot;75,47,61,53,29\r\n&quot; &quot;97,61,53,29,13\r\n&quot; &quot;75,29,13\r\n&quot; &quot;\r\n&quot; &quot;These have middle page numbers of 61, 53, and 29 respectivel\r\n&quot; &quot;y. Adding these page numbers together gives 143.\r\n&quot; &quot;\r\n&quot; &quot;Of course, you&apos;ll need to be careful: the actual list of pag\r\n&quot; &quot;e ordering rules is bigger and more complicated than the abo\r\n&quot; &quot;ve example.\r\n&quot; &quot;\r\n&quot; &quot;Determine which updates are already in the correct order. Wh\r\n&quot; &quot;at do you get if you add up the middle page number from thos\r\n&quot; &quot;e correctly-ordered updates?\r\n&quot; &quot;\r\n&quot; &quot;--- Part Two ---\r\n&quot; &quot;\r\n&quot; &quot;While the Elves get to work printing the correctly-ordered u\r\n&quot; &quot;pdates, you have a little time to fix the rest of them.\r\n&quot; &quot;\r\n&quot; &quot;For each of the incorrectly-ordered updates, use the page or\r\n&quot; &quot;dering rules to put the page numbers in the right order. For\r\n&quot; &quot; the above example, here are the three incorrectly-ordered u\r\n&quot; &quot;pdates and their correct orderings:\r\n&quot; &quot;\r\n&quot; &quot;    75,97,47,61,53 becomes 97,75,47,61,53.\r\n&quot; &quot;    61,13,29 becomes 61,29,13.\r\n&quot; &quot;    97,13,75,29,47 becomes 97,75,47,29,13.\r\n&quot; &quot;\r\n&quot; &quot;After taking only the incorrectly-ordered updates and orderi\r\n&quot; &quot;ng them correctly, their middle page numbers are 47, 29, and\r\n&quot; &quot; 47. Adding these together produces 123.\r\n&quot; &quot;\r\n&quot; &quot;Find the updates which are not in the correct order. What do\r\n&quot; &quot; you get if you add up the middle page numbers after correct\r\n&quot; &quot;ly ordering just those updates?\r\n&quot;,.run=run}):&#160;5.c'],['../default_8c.html#ad589db971007fb18aa07bf5dbb709de1',1,'SOLUTION(6, {0}):&#160;default.c'],['../default_8c.html#ad164b8be549ff08e5fe525607c8d19e3',1,'SOLUTION(7, {0}):&#160;default.c'],['../default_8c.html#ab6f01b1d0a61813cb614b6ada152ec54',1,'SOLUTION(8, {0}):&#160;default.c'],['../default_8c.html#abfc76ca10132de3660b4ec08d0e91050',1,'SOLUTION(9, {0}):&#160;default.c'],['../default_8c.html#a714238901149964f8262d39466000fef',1,'SOLUTION(10, {0}):&#160;default.c'],['../default_8c.html#ad76c830d710a7912f8258db63e4db0bc',1,'SOLUTION(11, {0}):&#160;default.c'],['../default_8c.html#a20961cbc1cfeb8d4924820cbfb2fc68f',1,'SOLUTION(12, {0}):&#160;default.c'],['../default_8c.html#a9863c73d4471e6ca920cef51713caefb',1,'SOLUTION(13, {0}):&#160;default.c'],['../default_8c.html#a2894156bf9580fffc0543cd45af4ab8d',1,'SOLUTION(14, {0}):&#160;default.c'],['../default_8c.html#ae00876b4706efcaba6f9a9f8913eb289',1,'SOLUTION(15, {0}):&#160;default.c'],['../default_8c.html#ab82f057f51d67df0fa77ad0db2f6d728',1,'SOLUTION(16, {0}):&#160;default.c'],['../default_8c.html#af6981f688ccab7e42a15f55d7ab86d69',1,'SOLUTION(17, {0}):&#160;default.c'],['../default_8c.html#a6ae52c034e471d29b57aefadfb4eeb2e',1,'SOLUTION(18, {0}):&#160;default.c'],['../default_8c.html#a47f4721d8d2d56a7035a6f7a7ae13183',1,'SOLUTION(19, {0}):&#160;default.c'],['../default_8c.html#a3c67d9881af0df85c85188280648d3b1',1,'SOLUTION(20, {0}):&#160;default.c'],['../default_8c.html#acb6f5e4968280d7477b69570dafff99a',1,'SOLUTION(21, {0}):&#160;default.c'],['../default_8c.html#a086073ce3ec148568a25207df6476088',1,'SOLUTION(22, {0}):&#160;default.c'],['../default_8c.html#a486a8313462c2226959e684207145913',1,'SOLUTION(23, {0}):&#160;default.c'],['../default_8c.html#af091d5f5ee0987860a0555fe223de737',1,'SOLUTION(24, {0}):&#160;default.c'],['../default_8c.html#a66831671dce7b5ddae48887f74245f09',1,'SOLUTION(25, {0}):&#160;default.c']]],
  ['sort_5flist_2',['sort_list',['../5_8c.html#a9bd39aadbc075c89a4df0ace96bf0998',1,'5.c']]],
  ['sortl_3',['sortl',['../util_8c.html#a14bd4f5ee95b2004b49a706d6db4cea2',1,'sortl(long *arr, int n):&#160;util.c'],['../util_8h.html#a14bd4f5ee95b2004b49a706d6db4cea2',1,'sortl(long *arr, int n):&#160;util.c']]],
  ['swapl_4',['swapl',['../util_8c.html#a9ec50cbe0735fc65f2eff87afe8582a6',1,'swapl(long *a, long *b):&#160;util.c'],['../util_8h.html#a9ec50cbe0735fc65f2eff87afe8582a6',1,'swapl(long *a, long *b):&#160;util.c']]]
];
