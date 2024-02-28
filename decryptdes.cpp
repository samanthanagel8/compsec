#include <iostream>
#include <string>
#include <vector>
#include <bitset>

// Define various arrays
int substitutionBoxes[8][4][16] = {
    { // S1 //
        {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
        {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
        {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
        {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
    },
    { // S2 //
        {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
        {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
        {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
        {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9},
    },
    { // S3 //
        {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
        {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
        {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
        {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}
    },
    { // S4 //
        {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
        {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
        {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
        {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}
    },
    { // S5 //
        {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
        {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
        {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
        {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}
    },
    { // S6 //
        {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
        {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
        {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
        {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}
    },
    { // S7 //
        {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
        {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
        {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
        {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}
    },
    { // S8 //
        {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
        {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
        {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
        {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}
    }
};

int permutationChoice1[56] = {
    57, 49, 41, 33, 25, 17, 9,
    1, 58, 50, 42, 34, 26, 18,
    10, 2, 59, 51, 43, 35, 27,
    19, 11, 3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15,
    7, 62, 54, 46, 38, 30, 22,
    14, 6, 61, 53, 45, 37, 29,
    21, 13, 5, 28, 20, 12, 4
};

int permutationChoice2[48] = {
    14, 17, 11, 24, 1, 5,
    3, 28, 15, 6, 21, 10,
    23, 19, 12, 4, 26, 8,
    16, 7, 27, 20, 13, 2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32
};

int initialPermutation[64] = {
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17, 9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7
};

int expansionTable[48] = {
    32, 1, 2, 3, 4, 5,
    4, 5, 6, 7, 8, 9,
    8, 9, 10, 11, 12, 13,
    12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21,
    20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29,
    28, 29, 30, 31, 32, 1
};

int permutation[32] = {
    16, 7, 20, 21,
    29, 12, 28, 17,
    1, 15, 23, 26,
    5, 18, 31, 10,
    2, 8, 24, 14,
    32, 27, 3, 9,
    19, 13, 30, 6,
    22, 11, 4, 25
};

int inverseInitialPermutation[64] = {
    40, 8, 48, 16, 56, 24, 64, 32,
    39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30,
    37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28,
    35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26,
    33, 1, 41, 9, 49, 17, 57, 25
};

// This function permutes the input string based on the permutation passed into it. Permutation tables are listed above
// This will return the string after permutation
std::string permute(const std::string& input, const int* table, int n) {
    std::string perm = ""; // Initialize empty string
    for(int i = 0; i < n; i++) { // Iterate thru table
        perm += input[table[i] - 1]; // // Append character from input string at index specified by the permutation table
    }
    return perm;
}

// This performs the XOR between strings
std::string xOr(const std::string& string_1, const std::string& string_2) {
    std::string xOr_out = "";
    for (size_t i = 0; i < string_1.size(); i++) {
		if (string_1[i] == string_2[i]) { // If bits are equal, put a 0
			xOr_out = xOr_out + '0';
		} else {
        	xOr_out = xOr_out + '1'; // Else, put a 1
//result += (a[i] == b[i] ? '0' : '1');
    	}
	}
    return xOr_out;
}

// Reference: https://www.geeksforgeeks.org/feistel-cipher/
std::string feistel(const std::string& rightHalf, const std::string& roundKey) {
    // Expand right half using expansion table
    std::string expandRight = permute(rightHalf, expansionTable, 48);
    
    // XOR the expanded right half
	std::string xOr_out = xOr(expandRight, roundKey);
    
    // Substitution w/ S-box
    std::string subBoxResult = "";
    for (int i = 0; i < 8; i++) {
		// Calculate row and column indices
        int row = 2 * (xOr_out[i*6] - '0') + (xOr_out[i*6 + 5] - '0');
        int col = 8 * (xOr_out[i*6 + 1] - '0') + 4 * (xOr_out[i*6 + 2] - '0') + 2 * (xOr_out[i*6 + 3] - '0') + (xOr_out[i*6 + 4] - '0');
        // Get value from S-box and convert to binary string
		int sBoxValue = substitutionBoxes[i][row][col];
        subBoxResult += std::bitset<4>(sBoxValue).to_string();
    }
    
    // Permute S-box using permutation table
    std::string result = permute(subBoxResult, permutation, 32);
    return result;
}

std::string shiftLeft(const std::string& key, int shifts) {
	// Do left cifcular shift by the 'shifts' positions
    std::string shift_string = key.substr(shifts) + key.substr(0, shifts);
    return shift_string;
}

// Function to generate round keys from initial key
std::vector<std::string> generateRK(const std::string& key) {
    
	std::vector<std::string> keys;
    
    // Permute using PC-1 table
    std::string permKey = permute(key, permutationChoice1, 56);
    
    // Left half of permuted key
	std::string leftHalf = permKey.substr(0, 28);
    std::string rightHalf = permKey.substr(28, 28);
    
    // Array for shift schedule
    int shifts[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
    
    // Generate the round keys
	for(int iter = 0; iter < 16; iter++) {
        leftHalf = shiftLeft(leftHalf, shifts[iter]);
        rightHalf = shiftLeft(rightHalf, shifts[iter]);
        
        // Combine the two halves
        std::string bothHalf = leftHalf + rightHalf;
		// Permuute combined using PC2
        std::string roundK = permute(bothHalf, permutationChoice2, 48);
        // Store keys in vector
		keys.push_back(roundK);
        
		// Print the round key
        std::cout << "Round " << (iter+1) << " Key: " << roundK << std::endl;
    }
    
    return keys;
}


// This function converts the binary strings to ASCII characters
// This will return the converted string
std::string convertString(const std::string& binary) {
    std::string ascii_text = ""; // Initialize empty string
    // Iterate in chunks of 8 bits
	for(size_t i = 0; i < binary.size(); i += 8) {
        int val = std::stoi(binary.substr(i, 8), nullptr, 2);
        ascii_text += static_cast<char>(val); // Convert int val to ASCII and append it to string
    }
    return ascii_text;
}

// Decrypt using DES algorithm
// Reference: https://www.educative.io/answers/how-to-implement-the-des-algorithm-in-cpp
std::string decrypt(const std::string& ciphertext, const std::vector<std::string>& roundKeys) {
    // Permute ciphertext using initial permutation table
	std::string permutedCipherText = permute(ciphertext, initialPermutation, 64);
    
    std::string leftHalf = permutedCipherText.substr(0, 32);
    std::string rightHalf = permutedCipherText.substr(32, 32);
    
    // Decrypt for 16 rounds
    for (int round = 15; round >= 0; round--) {
		// Call feistel function to right half
        std::string rightExpanded = feistel(rightHalf, roundKeys[round]);
		// Perform XOR between left half and output
        std::string newRightHalf = xOr(leftHalf, rightExpanded);
        // Update both halves for next round
		leftHalf = rightHalf;
        rightHalf = newRightHalf;

		// Output the right and left halves for each round
        std::cout << "Round " << 16 - round << " Left: " << leftHalf << " Right: " << rightHalf << std::endl;
    }
    
	// Combine the halves
    std::string bothHalf = rightHalf + leftHalf;
	
	// Final permutation using inverse initial permutation
    std::string decryption = permute(bothHalf, inverseInitialPermutation, 64);
    
	// Convert decryption to text
    return convertString(decryption);
}


// This function permutes the input string based on the permutation passed into it. Permutation tables are listed above
int main() {
    // Initialize key string
	std::string key = "0100110001001111010101100100010101000011010100110100111001000100";

	// Initialize cipher string
    std::string cipherText = "1100101011101101101000100110010101011111101101110011100001110011";
    
	// Generate the round keys
    std::vector<std::string> roundK = generateRK(key);
    
    // Decrypt the cipher text using the generated round keys
	std::string decryption = decrypt(cipherText, roundK);
    
    // Print the message
	std::cout << "Message: " << decryption << std::endl;
    
    return 0;
}

