#export FT_NBR1=\\\'?\"\\\"\'\\
#export FT_NBR2=rcrdmddd

#export FT_NBR1=\\\"\\\"\!\\\"\\\"\!\\\"\\\"\!\\\"\\\"\!\\\"\\\"\!\\\"\\\"
#export FT_NBR2=dcrcmcmooododmrrrmorcmcrmomo

echo $FT_NBR1 + $FT_NBR2 \
  | tr "'"'\\"?!mrdoc' '0123401234' \
  | xargs echo "ibase=5;obase=23;" | bc | tr '0123456789ABC' 'gtaio luSnemf'

# echo $FT_NBR1 + $FT_NBR2 | tr "'" 0 | tr "\\" 1 | tr '"' 2 | tr "?!" 34 | tr "mrdoc" 01234 | xargs echo "ibase=5; obase=23;" | bc | tr 0123456789ABC "gtaio luSnemf"
