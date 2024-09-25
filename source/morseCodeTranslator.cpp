#include <iostream>
#include <getopt.h>
#include <string>
#include <fstream>

using namespace std;

// Implement functions as needed to:
// Convert a string of text to Morse code
// Convert Morse code to text
// Handle the following character sets:
// Uppercase and lowercase letters (A-Z, a-z)
// Numbers (0-9)
// Basic punctuation (.,?'!/()&:;=+-_"$@)
// Use standard Morse code conventions:
// Separate letters with a space
// Separate words with a forward slash (/)
// Represent dots with periods (.) and dashes with hyphens (-)
// Implement input validation:
// For text input, only accept valid characters (letters, numbers, and supported punctuation)
// For Morse input, only accept valid Morse code characters (dots, dashes, spaces, and forward slashes)
// Create a user interface (can be command-line or GUI) that allows the user to:
// Choose between text-to-Morse and Morse-to-text conversion
// Input their message (via reading in a file or manually typing it into the CLI or GUI)
// View the converted output
// Save the output to a file
// Implement error handling for invalid inputs


std::string textToMorse(char c)
{

    std::string morseTable[128]{
        "",		// 0	NUL
        "",		// 1	SOH
        "",		// 2	STX
        "",		// 3	ETX
        "",		// 4	EOT
        "",		// 5	ENQ
        "",		// 6	ACK
        "",		// 7	BEL
        "",		// 8	BS
        "",		// 9	HT
        ".-.-",		// 10	LF
        "",		// 11	VT
        "",		// 12	FF
        "",		// 13	CR
        "",		// 14	SO
        "",		// 15	SI
        "",		// 16	DLE
        "",		// 17	DC1
        "",		// 18	DC2
        "",		// 19	DC3
        "",		// 20	DC4
        "",		// 21	NAK
        "",		// 22	SYN
        "",		// 23	ETB
        "",		// 24	CAN
        "",		// 25	EM
        "",		// 26	SUB
        "",		// 27	ESC
        "",		// 28	FS
        "",		// 29	GS
        "",		// 30	RS
        "",		// 31	US
        "/",		// 32	SP
        "-.-.--",		// 33	!
        ".-..-.",		// 34	"
        "",		// 35	#
        "",		// 36	$
        "",		// 37	%
        ".-...",		// 38	&
        ".----.",		// 39	'
        "-.--.",		// 40	(
        "-.--.-",		// 41	)
        "",		// 42	*
        ".-.-.",		// 43	+
        "--..--",		// 44	,
        "-....-",		// 45	-
        ".-.-.-",		// 46	.
        "-..-.",		// 47	/
        "-----",		// 48	0
        ".----",		// 49	1
        "..---",		// 50	2
        "...--",		// 51	3
        "....-",		// 52	4
        ".....",		// 53	5
        "-....",		// 54	6
        "--...",		// 55	7
        "---..",		// 56	8
        "----.",		// 57	9
        "---...",		// 58	:
        "",		// 59	;
        "",		// 60	<
        "-...-",		// 61	=
        "",		// 62	>
        "..--..",		// 63	?
        ".--.-.",		// 64	@
        ".-",		// 65	A
        "-...",		// 66	B
        "-.-.",		// 67	C
        "-..",		// 68	D
        ".",		// 69	E
        "..-.",		// 70	F
        "--.",		// 71	G
        "....",		// 72	H
        "..",		// 73	I
        ".---",		// 74	J
        "-.-",		// 75	K
        ".-..",		// 76	L
        "--",		// 77	M
        "-.",		// 78	N
        "---",		// 79	O
        ".--.",		// 80	P
        "--.-",		// 81	Q
        ".-.",		// 82	R
        "...",		// 83	S
        "-",		// 84	T
        "..-",		// 85	U
        "...-",		// 86	V
        ".--",		// 87	W
        "-..-",		// 88	X
        "-.--",		// 89	Y
        "--..",		// 90	Z
        "",		// 91	[
        "",		// 92   "\"
        "",		// 93	]
        "",		// 94	^
        "",		// 95	_
        "",		// 96	`
                ".-",
        "-...",
        "-.-.",
        "-..",
        ".",
        "..-.",
        "--.",
        "....",
        "..",
        ".---",
        "-.-",
        ".-..",
        "--",
        "-.",
        "---",
        ".--.",
        "--.-",
        ".-.",
        "...",
        "-",
        "..-",
        "...-",
        ".--",
        "-..-",
        "-.--",
        "--..",
        "",		// 123	{
        "",		// 124	|
        "",		// 125	}
        "",		// 126	~
        ""		// 127	DEL
    };
    // if (!encrypt)
    // {
    //     shift = shift * -1;
    // }
    std::cout << (int)c << " " ;
    if (morseTable[(int)c] != "")
    {
        std::cout << c << " = " << morseTable[(int)c] << std::endl;
        return morseTable[(int)c];
    }
    else
    {
        // std::string foo = str(c);
        // return str(c);
        std::cout << c << " = " << morseTable[(int)c] << std::endl;
        return std::string(1, c);
    }
    return "ERROR";
}

int main(int argc, char* argv[])
{
    int opt{-1};
    bool verbose{false}, interactive{false};
    std::string source{""}, destination{""};

    // Define long options alongside short options
    struct option long_options[] =
    {
        {"help",        no_argument,       0, 'h'},
        {"verbose",     no_argument,       0, 'v'},
        {"interactive", no_argument,       0, 'i'},
        {"source_file", required_argument,       0, 's'},
        {"out_file",    required_argument,       0, 'o'},
        {"to_text",            no_argument,       0, 't'},
        {0,         0,                 0,  0 }
    };

    // Parse options using getopt_long
    while ((opt = getopt_long(argc, argv, "hvisot", long_options, nullptr)) != -1)
    {
        switch (opt)
        {
            case 'h':
                std::cout << "Usage: mctranslator [options] SOURCE DEST\n"
                          << "Options:\n"
                          << "  -h, --help     Show this help message\n"
                          << "TODO\n";
                return 0;
            case 'v':
                verbose = true;
                break;
            case 'i':
                interactive = true;
                break;
            case 's':
                
                break;
            case 'o':
                
                break;
            case 't':
                
                break;
            default:
                std::cerr << "Unknown option: " << opt << std::endl;
                return 1;
        }
    }

    if (optind < argc)
    {
        source = argv[optind];
        if (optind + 1 < argc)
        {
            destination = argv[optind + 1];
        }
        
    }

    std::cout << "source=" << source << std::endl;
    std::cout << "destination=" << destination << std::endl;

    std::ifstream inputFile (source);
    std::ofstream outputFile (destination);

    if (inputFile.is_open() && outputFile.is_open())
    {
        std::string line;
        while ( getline (inputFile,line) )
        {
            for ( std::string::iterator it=line.begin(); it!=line.end(); ++it)
            {
                std::cout << (int)*it << " = " << *it << "    ";
                outputFile << textToMorse(*it);
            }
            outputFile << std::endl;
        }
        inputFile.close();
        outputFile.close();
    }
    else std::cout << "Unable to open file";



    return 0;
}



#include <iostream>
#include <fstream>



// char convert(char c, int shift, bool encrypt)
// {
//     if (!encrypt)
//     {
//         shift = shift * -1;
//     }
    
//     if (c >= 97 && c <= 122)
//     {
//         return char((((c - 97 + shift) % 26) + 26) % 26 + 97);
//     }
//     else if (c >= 65 && c <= 90)
//     {
//         return char((((c - 65 + shift) % 26) + 26) % 26 + 65);
//     }
//     else
//     {
//         return char(c);
//     }
// }



// // ccipher 
// int main(int argc, char* argv[])
// {
//     // initialize arguments
//     std::string mode{argv[1]};
//     int shift{atoi(argv[2])};
//     std::string source{argv[3]};
//     std::string destination{argv[4]};

//     std::ifstream inputFile (source);
//     std::ofstream outputFile (destination);

//     bool encrypt{true};

//     if (mode != "encrypt")
//     {
//         encrypt = false;
//     }
    
//     if (mode == "brute-force")
//     {
//         if (inputFile.is_open())
//         {
//             std::string line;

//             for (size_t i = 1; i < 26; i++)
//             {
//                 std::cout << "key=" << i << std::endl;
//                 while ( getline (inputFile,line) )
//                 {
//                     for ( std::string::iterator it=line.begin(); it!=line.end(); ++it)
//                     {
//                         std::cout << convert(*it, i, encrypt);
//                     }
//                     std::cout << std::endl;
//                 }
//                 inputFile.clear();
//                 inputFile.seekg(0, inputFile.beg);
//             }
//             inputFile.close();
//         }
//         else std::cout << "Unable to open file";
//     }
//     else if (inputFile.is_open() && outputFile.is_open())
//     {
//         std::string line;
//         while ( getline (inputFile,line) )
//         {
//             for ( std::string::iterator it=line.begin(); it!=line.end(); ++it)
//             {
//                 outputFile << convert(*it, shift, encrypt);
//             }
//             outputFile << std::endl;
//         }
//         inputFile.close();
//         outputFile.close();
//     }
//     else std::cout << "Unable to open file";

// 	return 0; 
// }
