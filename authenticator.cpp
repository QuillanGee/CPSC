/// @authenticator.cpp <authenticator>
/// @brief <Compares authenticator code with message code>
/// @author <Quillan Gee>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
  //authenticator code
  const char k_cAuthenticatorCodeCharacter1 = 'E';
  const char k_cAuthenticatorCodeCharacter2 = 'C';
  const char k_cAuthenticatorCodeCharacter3 = 'A';

  //three chars that the user enters
  char firstLetter;
  char secondLetter;
  char thirdLetter;

  //getting the input for the authenticator code
  cout << "Enter the first letter of the code: " << endl;
  cin >> firstLetter;
  cout << "Enter the second letter of the code" << endl;
  cin >> secondLetter;
  cout << "Enter the third letter of the code" << endl;
  cin >> thirdLetter;

  //declaring and initializing the strings for each code (basically adding the chars to a string)
  string authenticatorCode = authenticatorCode + k_cAuthenticatorCodeCharacter1 + k_cAuthenticatorCodeCharacter2 +k_cAuthenticatorCodeCharacter3;
  string userInputCode = userInputCode + firstLetter + secondLetter + thirdLetter;

  //displaying each code
  cout << "Authenticator code: " << authenticatorCode << endl;
  cout << "Message code: " << userInputCode << endl;
  cout << endl;
  //seeing if the char's match
  if((k_cAuthenticatorCodeCharacter1 == firstLetter) && (k_cAuthenticatorCodeCharacter2 == secondLetter) && (k_cAuthenticatorCodeCharacter3 == thirdLetter)){
    cout << "Message is authentic" << endl;
  }
  else{
    cout << "Message is invalid" << endl;
  }

  //double chekcing if code is correct by comparing the strings
  if (authenticatorCode == userInputCode){
    cout << "Concurrence: message is authentic." << endl;
  }
  else{
    cout << "Concurrence: message is invalid." << endl;
  }
  cout << endl;


  cout << "Characterization of Message Code" << endl;
  cout << "--------------------------------" << endl;
  //uses check sum to test whether the messages are the same
  const int k_iValidCodeChecksum = 5;
  int messageCheckSum = (int(firstLetter) + int(secondLetter) + int(thirdLetter))%7;

  //output checksum values
  if(k_iValidCodeChecksum == messageCheckSum){
    cout << "Message code checksum is valid: " << messageCheckSum << endl;
  }
  else{
    cout << "Message code checksum is invalid: " << messageCheckSum << "; expected: " << k_iValidCodeChecksum << endl;
  }

  //output ASCII values of message code
  int sumASCII = int(firstLetter) + int(secondLetter) + int(thirdLetter);
  cout << "ASCII Values of Message Code Characters: " << int(firstLetter) << "," << int(secondLetter) << "," << int(thirdLetter) << endl;
  cout << "Sum of ASCII values for Message Code Characters: " << sumASCII << endl;

  //comparing each letter and displaying the result
  if(k_cAuthenticatorCodeCharacter1 != firstLetter){
    cout << "First characters do not match: Message: " << firstLetter << " Authenticator: " << k_cAuthenticatorCodeCharacter1 << endl;
  }
  if(k_cAuthenticatorCodeCharacter2 != secondLetter){
    cout << "First characters do not match: Message: " << secondLetter << " Authenticator: " << k_cAuthenticatorCodeCharacter2 << endl;
  }
  if(k_cAuthenticatorCodeCharacter3 != thirdLetter){
    cout << "First characters do not match: Message: " << thirdLetter << " Authenticator: " << k_cAuthenticatorCodeCharacter3 << endl;
  }

  //comparing lexicographically values of the message and authenticator strings
  if(authenticatorCode>userInputCode){
    cout << "Message code (" << userInputCode << ") is lexicographically less than Authenticator code (" << authenticatorCode << ")" << endl;
  }
  if(authenticatorCode<userInputCode){
    cout << "Message code (" << userInputCode << ") is lexicographically greater than Authenticator code (" << authenticatorCode << ")" << endl;
  }
}
