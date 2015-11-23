# See README.txt.

.PHONY: all clean

all: test_student_cpp

protoc_middleman: student.proto
	protoc --cpp_out=. student.proto
	@touch protoc_middleman

test_student_cpp: test_student.cc protoc_middleman
	pkg-config --cflags protobuf  # fails if protobuf is not installed
	c++ -g test_student.cc student.pb.cc -I../../coz-master/include -ldl -o test_student_cpp `pkg-config --cflags --libs protobuf`

clean: 
	@rm test_student_cpp mystu
