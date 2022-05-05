
all: qmake

qmake: 
	cd src;\
	qmake;\
	make;\
	cd ..;
# TODO: Add to be removed .vscode and gitignore
clean:
	rm -rf build-CPP_Project-Desktop-Debug;\
	rm -rf build-CPP_Project-Desktop-Debug;\
	cd src/;\
	rm CPP_Project;\
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

run:
	cd src/;\
	./CPP_Project;\
	cd ..;

pack:
	zip -r  n-xzimol04-xholan11.zip ../CPP_Project