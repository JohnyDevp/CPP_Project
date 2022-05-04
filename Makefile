
all: qmake

qmake: 
	cd src;\
	qmake;\
	make;\
	cd ..;

clean:
	cd src/;\
	rm -rf ui_*;\
	rm -rf moc_*;\
	rm -rf *.o;\
	rm -rf .qmake.stash ;\
	cd ..; \
	cd docs/;\
	rm -rf html;\
	cd ..;

doxygen:
	cd docs/;\
	doxygen Doxyfile;\
	cd ..;

