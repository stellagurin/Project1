OBJS = UnsortedListDriver.o UnsortedList.o Student.o
COMPILE = g++ -g -c -std=gnu++0x -o $@

.PHONY: run

UnsortedListDriver:	$(OBJS)
					g++ -o $@ $(OBJS)

UnsortedListDriver.o:	UnsortedListDriver.cpp
						$(COMPILE) UnsortedListDriver.cpp

UnsortedList.o:	UnsortedList.h UnsortedList.cpp
				$(COMPILE) UnsortedList.cpp

Student.o:	Student.h Student.cpp
			$(COMPILE) Student.cpp

run:	$ UnsortedListDriver
		./$ UnsortedListDriver

clean:
		$(RM) $(OBJS)

cleanall:	clean
			$(RM) UnsortedListDriver
