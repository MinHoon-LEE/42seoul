VAR1="$1"
curl -s $VAR1 | grep "href" | cut -d">" -f2 | cut -d'"' -f2

