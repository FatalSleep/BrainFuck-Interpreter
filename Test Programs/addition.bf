[-][BrainFuck program for adding two cells z equals x plus y]
[-][Below is the uncommented BrainFuck Addition Source Code!]
[-][++++ [>+++++<-]+++++[>>++++++++++<<-]>[>+<-]>.,         ]
[-][End result is #2(50) += #1(20) and #0 and #1 equal 0    ]

++++ [>+++++<-]			Set cell #0 to 4 then add  5 to cell #1 until cell #0 decrements to 0 and end cell is #0
+++++[>>++++++++++<<-]		Set cell #0 to 5 then add 10 to cell #2 until cell #0 decrements to 0 and end cell is #0
>[>+<-]				Increment cell #2 until cell #1 decrements to 0 and end cell is #1
>.,				Move from cell #1 to cell #2 then output the data at cell #2 and wait and end cell is #2
