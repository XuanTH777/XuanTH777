#include <iostream> 
#include <string> 
using namespace std;

// Function to generate the key for encryption/decryption 

string generateKey(const string& plaintext, const string& keyword) {

    string key = "";

    int j = 0;

    // Generate key by repeating the keyword to match the length of the plaintext 

    for (int i = 0; i < plaintext.length(); i++) {

        if (isalpha(plaintext[i])) {

            key += keyword[j];  // Append the current character from the keyword 

            j++;

            if (j == keyword.length()) {

                j = 0;  // Reset to the start of the keyword if it ends 
            }

        }
        else {
            key += ' ';  // Skip spaces in the key where they appear in plaintext 
        }
    }
    return key;
}


// Function to encrypt the plaintext 

string encryptVigenere(const string& plaintext, const string& keyword) {

    string key = generateKey(plaintext, keyword);

    string ciphertext = "";

    for (int i = 0; i < plaintext.length(); i++) {

        if (isalpha(plaintext[i])) {

            // Calculate shift based on the key character 

            char shift = tolower(key[i]) - 'a';

            // Encrypt alphabetic characters 

            if (isupper(plaintext[i])) {

                ciphertext += (plaintext[i] + shift - 'A') % 26 + 'A';

            }
            else {

                ciphertext += (plaintext[i] + shift - 'a') % 26 + 'a';
            }
        }
        else {
            ciphertext += plaintext[i];  // Leave non-alphabetical characters unchanged 
        }
    }
    return ciphertext;

}


// Function to decrypt the ciphertext 

string decryptVigenere(const string& ciphertext, const string& keyword) {

    string key = generateKey(ciphertext, keyword);

    string plaintext = "";


    for (int i = 0; i < ciphertext.length(); i++) {

        if (isalpha(ciphertext[i])) {

            // Calculate shift based on the key character 

            char shift = tolower(key[i]) - 'a';

            // Decrypt alphabetic characters 

            if (isupper(ciphertext[i])) {

                plaintext += (ciphertext[i] - shift - 'A' + 26) % 26 + 'A';

            }
            else {

                plaintext += (ciphertext[i] - shift - 'a' + 26) % 26 + 'a';
            }
        }
        else {

            plaintext += ciphertext[i];  // Leave non-alphabetical characters unchanged 
        }

    }

    return plaintext;

}

int main() {

    string plaintext, keyword, encrypted;

    cout << "Enter a message to encrypt: ";

    getline(cin, plaintext);

    cout << "Enter the keyword: ";

    getline(cin, keyword);

    // Encrypt the message 
    cout << "Encrypted: " << encryptVigenere(plaintext, keyword) << endl << endl;



    cout << "Enter a message to decrypt: ";

    getline(cin, encrypted);

    cout << "Enter the key word: ";

    getline(cin, keyword);

    // Decrypt the message 
    cout << "Decrypted: " << decryptVigenere(encrypted, keyword) << endl;

    return 0;

}