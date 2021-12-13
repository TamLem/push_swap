#!/bin/bash

rb=$(cat instructions.txt | grep -w "rb" | wc -l)
rrb=$(cat instructions.txt | grep -w "rrb" | wc -l)
ra=$(cat instructions.txt | grep -w "ra" | wc -l)
rra=$(cat instructions.txt | grep -w "rra" | wc -l)
rr=$(cat instructions.txt | grep -w "rr" | wc -l)
rrr=$(cat instructions.txt | grep -w rrr | wc -l)
pa=$(cat instructions.txt | grep -w pa | wc -l)
pb=$(cat instructions.txt | grep -w pb | wc -l)
total=$(cat instructions.txt | wc -l)

echo -e "rb 	$rb"
echo -e "rrb	$rrb"
echo -e "ra 	$ra"
echo -e "rra 	$rra"
echo -e "rr 	$rr"
echo -e "rrr	$rrr"
echo -e "pa	$pa"
echo -e "pb	$pb"
echo "---------------------------"
echo -e "Total - $total"