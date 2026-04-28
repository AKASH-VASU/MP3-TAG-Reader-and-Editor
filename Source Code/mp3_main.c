/*
Name : V.Akash
Regd_No: 25048_039
Project Name: MP3 Tag Reader and Editor
Start Date: 14 Apr 2026
End Date: 16 Apr 2026
*/
#include "mp3_header.h"

int main(int argc, char *argv[])
{
    
    struct MP3 mp3;
    
    int ret = validate_cla(argc,argv,&mp3);
    if(ret == VIEW)
     {
        mp3.mp3_filename = argv[argc-1];
	    view(&mp3);

     }
     else if(ret == EDIT)
     {
        mp3.mp3_filename = argv[argc-1];
        edit(&mp3,argc,argv);
     }

    return 0;

}


/*
Description: 
## 1.Introduction :

The MP3 Tag Reader and Editor is a C-based application used to read and modify 
metadata of MP3 files that follow the ID3v2.3 format. It allows users to view 
and edit details like title, artist, album, year, genre, and comments.

## 2. Objective
To implement file handling in C
To understand MP3 metadata (ID3 tags)
To perform reading and editing of binary file data

## 3. Features

View Mode (-v)

Displays:

Title
Artist
Album
Year
Content (Genre)
Comment
Edit Mode (-e)

Modify specific fields:

-t → Title
-a → Artist
-A → Album
-y → Year
-m → Content
-c → Comment

## 4. Working Principle
The program reads the ID3 header and validates the MP3 file
Extracts metadata from frames like TIT2, TPE1, etc.
In edit mode:
Creates a temporary file
Updates selected tag
Copies remaining data
Replaces original file

## 5. Structure Used

struct MP3
{
    char *mp3_filename;
    FILE *org_mp3_fptr;
    FILE *dup_mp3_fptr;
};

## 6. Key Concepts
Binary file handling (fread, fwrite)
Command-line arguments
Dynamic memory allocation
Endianness conversion
String processing

## 7. Usage
View:
./a.out -v sample.mp3
Edit:
./a.out -e -t "New Title" sample.mp3

## 8. Advantages
Simple and efficient
No external libraries required
Direct metadata manipulation

## 9. Limitations
Supports only ID3v2.3
Limited number of tags
Command-line based

## 10. Conclusion
This project demonstrates how to read and edit MP3 metadata using C, helping 
in understanding file structures, binary data handling, and real-world 
application development.
*/