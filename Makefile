forky: forky.c \
		pattern1.c pattern2.c pattern3.c \
		pattern1.h pattern2.h pattern3.h
	gcc -o forky forky.c pattern1.c pattern2.c pattern3.c

results: forky
	(echo "Pattern 1:"; ./forky 1 $$((RANDOM % 15 + 5)); \
	echo; \
	echo "Pattern 2:"; ./forky 2 $$((RANDOM % 15 + 5)); \
	echo; \
	echo "Pattern 3:"; ./forky 3 $$((RANDOM % 20 + 5))) > results.txt

clean:
	rm -f forky
