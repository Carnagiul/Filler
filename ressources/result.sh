player=("champely" "abandlin" "carli" "grati" "hcao" "superjeannot")
#player=("carli")
#player[2]=carli
#player[3]=grati
#player[4]=hcao
#player[5]=superjeannot
trace=("0.trace" "1.trace" "2.trace" "3.trace" "4.trace")
maps=("./maps/map00" "./maps/map01" "./maps/map02")
srcs=("f0" "f1" "f2")

for ((i=0; i<${#player[@]}; i++))
do
	for((file=0; file<3; file++))
	do
		echo "Resultats des combats contre ${player[$i]} sur la map ${maps[$file]}"
		for((game=0; game<5; game++))
		do
			cat ${player[$i]}/${srcs[$file]}/${trace[$game]} | tail -2 | awk 'BEGIN { cpt=1}  NR == 1 { CHAINE=$4 }  $4 > CHAINE { cpt++ } END { if ( NR != cpt ) { print "GAGNER" } else { print "PERDU" }}'
		done
		echo "";
	done
	echo "";
done
echo "Fin des resultats"
