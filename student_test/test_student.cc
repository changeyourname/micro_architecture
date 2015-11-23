// See README.txt for information and build instructions.

#include <iostream>
#include <fstream>
#include <string>
#include "student.pb.h"
//#define MAX_PERSONS 6
#define MAX_STUDENT 5000
#define MAX_ITERATION 1
//#define MAX_ITERATION 1000000
//#include "coz.h"
using namespace std;

// This function fills in a Person message based on user input.
void PromptForStudent1(test::Student* student, FILE* inFile) {
  //cout << "Enter person ID number: ";
  int id;
  string name;
  string phone;
  float gpa;
  fscanf(inFile,"%d%s%s%f", &id, name, phone, &gpa);
  student->set_id(id);
  //inFile.ignore(256, '\n');

  //cout << "Enter name: ";
  //getline(inFile, *student->mutable_name());
  //string name;
  //name = "xiaoweiw";
  //getline(inFile, name);
  if (!name.empty()) {
    student->set_name(name);
  }

  //cout << "Enter email address (blank for none): ";
  //string phone;
  //phone = "7347782132";
  //getline(inFile, phone);
  if (!phone.empty()) {
    student->set_phone(phone);
  }

  //float gpa;
  //inFile >> gpa;
  //gpa = 3.9;
  student->set_gpa(gpa);

}

// This function fills in a Person message based on user input.
void PromptForStudent(test::Student* student, fstream& inFile) {
  //cout << "Enter person ID number: ";
  int id;
  id = 4001;
  //inFile >> id;
  student->set_id(id);
  inFile.ignore(256, '\n');

  //cout << "Enter name: ";
  //getline(inFile, *student->mutable_name());
  string name;
  name = "xiaoweiw";
  //getline(inFile, name);
  if (!name.empty()) {
    student->set_name(name);
  }

  //cout << "Enter email address (blank for none): ";
  string phone;
  phone = "7347782132";
  //getline(inFile, phone);
  if (!phone.empty()) {
    student->set_phone(phone);
  }

  float gpa;
  //inFile >> gpa;
  gpa = 3.9;
  student->set_gpa(gpa);

}

// Main function:  Reads the entire address book from a file,
//   adds one person based on user input, then writes it back out to the same
//   file.
int main(int argc, char* argv[]) {
  // Verify that the version of the library that we linked against is
  // compatible with the version of the headers we compiled against.
  GOOGLE_PROTOBUF_VERIFY_VERSION;

/*  if (argc != 2) {
    cerr << "Usage:  " << argv[0] << " STUDENT_FILE" << endl;
    return -1;
  }
  */

  test::Student student[MAX_STUDENT];
  //tutorial::AddressBook address_book;

 // {
 //   // Read the existing address book.
 //   fstream input(argv[1], ios::in | ios::binary);
 //   if (!input) {
 //     cout << argv[1] << ": File not found.  Creating a new file." << endl;
 //   } else if (!address_book.ParseFromIstream(&input)) {
 //     cerr << "Failed to parse address book." << endl;
 //     return -1;
 //   }
 // }

  // Read from self defined file
  fstream inFile("student_data.txt", ios::in);
  //FILE* inFile = fopen("student_data.txt", "r"); 
 
  // Add some addresses.
  for (int i = 0; i < MAX_STUDENT; ++i) {
    PromptForStudent(&student[i], inFile);
  }

  //PromptForStudent(&student, inFile);
  
  {
    // Write the new address book back to disk.
    //fstream output(argv[1], ios::out | ios::trunc | ios::binary);
    fstream output("mystu", ios::out | ios::trunc | ios::binary);
    // For profiling reason, loop the program
    for (int i = 0; i < MAX_STUDENT; ++i) {
      //COZ_BEGIN("serialize")
      
      
      for (int j = 0; j < MAX_ITERATION; ++j) { 
        if (!student[i].SerializeToOstream(&output)) {
          cerr << "Failed to write student data." << endl;
          return -1;
        }
        //COZ_PROGRESS
      //COZ_END("serialize")
      }
      //COZ_PROGRESS
    }
  }

  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}
