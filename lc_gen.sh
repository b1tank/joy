echo "EXAMPLE: ./lc_gen.sh cpp graph 133_clone-graph"
sed "s/__filename__/$3/g" template.$1 > "$2/$3.$1"