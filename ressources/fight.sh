player=("champely" "abanlin" "carli" "grati" "hcao" "superjeannot")
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
	echo "Creations des dossiers de trace de ${player[$i]}"
	rm -rf ${player[$i]};
	mkdir -p ${player[$i]};
	mkdir -p ${player[$i]}/f0;
	mkdir -p ${player[$i]}/f1;
	mkdir -p ${player[$i]}/f2;
	for((file=0; file<3; file++))
	do
		echo "lancement des combats sur ${maps[$file]} contre ${player[$i]}"
		for((game=0; game<1; game++))
		do
			./filler_vm -f ${maps[$file]} -p1 ./player/piquerue.filler -p2 ./player/${player[$i]}.filler > ${player[$i]}/${srcs[$file]}/${trace[$game]} &
		done
	done
	echo "";
done
echo "Les combats sont lance, faites ps afin de verifier que tous les combats sont terminer."
