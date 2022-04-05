CC=gcc

OBS=files.c BFS.c graph.c main.c path_search.c utils.c

build: bindir
	$(CC) $(OBS) --std=c90 -obin/graph

bindir:
	@mkdir -p bin

testdir:
	@mkdir -p bin/tests

test-all: test-format test-nspoj test-spoj test-ujemny


test-spoj: build testdir
	@-bin/graph -c -p 0 89 --src bin/tests/test-spoj.graph > bin/tests/test-spoj.result 2>&1
	@res=$$(diff bin/tests/test-spoj.exp-result bin/tests/test-spoj.result);\
	if [ -z "$$res" ];\
		then\
		  echo "Test test-spoj: OK";\
		else\
		  echo "Test test-spoj: BLAD!  Szczegoly:";\
		  echo $$res ;\
		fi\

test-nspoj: build testdir
	@-bin/graph -p 0 89 --src bin/tests/test-nspoj.graph > bin/tests/test-nspoj.result 2>&1
	@res=$$(diff bin/tests/test-nspoj.exp-result bin/tests/test-nspoj.result);\
	if [ -z "$$res" ];\
		then\
		  echo "Test test-nspoj: OK";\
		else\
		  echo "Test test-nspoj: BLAD!  Szczegoly:";\
		  echo $$res ;\
		fi\

test-ujemny: build testdir
	@-bin/graph -g 0 -10 --src bin/tests/test-ujemny.graph > bin/tests/test-ujemny.result 2>&1
	@res=$$(diff bin/tests/test-ujemny.exp-result bin/tests/test-ujemny.result);\
	if [ -z "$$res" ];\
		then\
		  echo "Test test-ujemny: OK";\
		else\
		  echo "Test test-ujemny: BLAD!  Szczegoly:";\
		  echo $$res ;\
		fi\

test-format: build testdir
	@-bin/graph -s --src bin/tests/test-format.graph > bin/tests/test-format.result 2>&1
	@res=$$(diff bin/tests/test-format.exp-result bin/tests/test-format.result);\
	if [ -z "$$res" ];\
		then\
		  echo "Test test-format: OK";\
		else\
		  echo "Test test-format: BLAD!  Szczegoly:";\
		  echo $$res ;\
		fi\

