CFLAGS = -std=c++11 -g
objects = main.o View.o AlbumCreator.o PhotoGram.o MediaFactory.o Criteria.o Album.o Photo.o Date.o

a4: $(objects)
	g++ $(CFLAGS) -o a4 $(objects)

main.o: main.cc
	g++ $(CFLAGS) -c main.cc 

View.o: View.h View.cc 
	g++ $(CFLAGS) -c View.cc

AlbumCreator.o: AlbumCreator.h AlbumCreator.cc 
	g++ $(CFLAGS) -c AlbumCreator.cc

PhotoGram.o: PhotoGram.h PhotoGram.cc
	g++ $(CFLAGS) -c PhotoGram.cc

MediaFactory.o: MediaFactory.h MediaFactory.cc
	g++ $(CFLAGS) -c MediaFactory.cc

Criteria.o: Criteria.cc Criteria.h
	g++ $(CFLAGS) -c Criteria.cc

Album.o: Album.cc Album.h
	g++ $(CFLAGS) -c Album.cc
	
Photo.o: Photo.cc Photo.h 
	g++ $(CFLAGS) -c Photo.cc

Date.o: Date.cc Date.h 
	g++ $(CFLAGS) -c Date.cc

clean:
	rm -f a4 *.o	