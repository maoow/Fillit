# Fillit
program fillit as 42 project.
#

##  Name
    fillit - organized tetriminos and output the map

##  Synopsys
    ./fillit source_file
  
##  Description
     The fillit program take a list of tetriminos and organized them
     in the optimal space disposition to fill the smallest square using
     all tetriminos.
       
##  Format of the tetriminos list
     The tetriminos list should be a file of 1 >= x >= 26 tetriminos
     seperated by an empty line.
     every tetrimino should be composed of 4 EOL terminated lines of 4
     chars, the tetrimino is composed of 4 squares symbolised by '#' 
     and 12 empty spaces symbolised by '.'.
     
 ###    example of a well formated tetriminos:
        ###.
        .#..
        ....
        ....
      
##  Output
    if the source_file is well formated, the program will output
    the optimal disposition on the standard output, the 1st tetrimino
    will be identified by the 'A' letter, the 2nd by a 'B' ...
    
###    example:
    $> cat source_file | cat -e
    ...#$
    ...#$
    ...#$
    ...#$
    $
    ....$
    ....$
    ....$
    ####$
    $
    .###$
    ...#$
    ....$
    ....$
    $
    ....$
    ..##$
    .##.$
    ....$
    $
    ....$
    .##.$
    .##.$
    ....$
    $
    ....$
    ....$
    ##..$
    .##.$
    $
    ##..$
    .#..$
    .#..$
    ....$
    $
    ....$
    ###.$
    .#..$
    ....$
    $> ./fillit source_file | cat -e
    ABBBB.$
    ACCCEE$
    AFFCEE$
    A.FFGG$
    HHHDDG$
    .HDD.G$
    $>
                                
