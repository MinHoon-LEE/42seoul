#git status --ignored -s | grep "!!" | cut -c -4
git ls-files -o -i --exclude-standard
#git file -i -o --exclude 
