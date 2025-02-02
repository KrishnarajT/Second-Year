// You will be given a string as input and you have to find the resulting hamming code to be sent.
// Also check which bit if flipped after flipping it.

#include <iostream>
#include <cmath>

using namespace std;

unsigned long int m;
int r_array[20][20];
int r_val = 0;     // value of r, or number of bits of r that need to be put in.
int error_bit = 0; // the bit that was changed by the user and detected by program.

void display_r()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cout << r_array[i][j] << " ";
        }
        cout << endl;
    }
}

// Returns the length of the resulting hamming code
int calc_length(string input)
{
    //  2^r_array > m + r_array + 1
    m = input.length();
    int r = 0;
    for (int i = 0; i < 10; i++)
    {
        if (pow(2, i) >= int(m) + i + 1)
        {
            r = i;
            break;
        }
    }
    ::r_val = r;
    return int(m) + r;
}

// Converts Binary array into decimal
void convert_binary_to_decimal(bool parity[])
{
    int decimal = 0;
    for (int i = 0; i < ::r_val; i++)
    {
        if (parity[i])
        {
            decimal += pow(2, i);
        }
    }
    if (decimal)
    {
        ::error_bit = decimal;
    }
}

// Fills the values with r_array in the 2d array
void fill_r_values(int hamming_len)
{
    int count;
    bool should_add;
    for (int k = 0; k < hamming_len; k++)
    {
        count = 0;
        should_add = false;
        for (int i = 0, j = 1; i <= hamming_len; i++)
        {
            if (count == pow(2, k))
            {
                count = 0;
                should_add = !should_add; // flips it
            }

            if (should_add)
            {
                r_array[k][j] = i;
                j++;
            }
            count++;
        }
    }
}

// Fills the first column of the r_array table, to 1 or 0 for maintaining even parity.
void fill_r_parity(int hamming_len, const bool hamming[])
{
    int count;
    bool parity;
    for (int i = 0; i < ::r_val; i++)
    {
        // check parity
        count = 0;
        for (int j = 2; j <= (hamming_len / 2) + 1; j++)
        {
            hamming[r_array[i][j] - 1] ? count++ : count;
        }
        parity = count % 2 != 0; // if number of 1's is even
        r_array[i][0] = parity;  // assign parity bit
    }
}

// Fills the hamming array by looking at the parity r_array bits from the r_array array.
void fill_hamming(int hamming_len, bool hamming[])
{
    int k = 0;
    for (int j = 0; j < hamming_len; j++)
    {
        if (j == pow(2, k) - 1)
        {
            hamming[j] = r_array[k][0];
            k++;
        }
    }
}

void display_hamming(int hamming_len, bool hamming[])
{
    for (int i = hamming_len - 1; i >= 0; i--)
    {
        cout << hamming[i];
    }
    cout << endl;
}

// This function does the entire error correction, and prints the process as well
void detect_errors(int hamming_len, bool hamming[50])
{
    int count;
    bool parity[::r_val];

    // Display new hamming code with flipped bit, and the old one as well.

    // Deduce values of r_array from the new hamming code

    // from the previous r_array table that we already have,
    for (int i = 0; i < ::r_val; i++)
    {
        // check parity
        count = 0;
        for (int j = 1; j <= hamming_len / 2 + 1; j++)
        {
            hamming[r_array[i][j] - 1] ? count++ : count;
        }
        parity[i] = count % 2 != 0; // if number of 1's is even
    }
    // converted parity bits to decimal, and then find the flipped bit
    convert_binary_to_decimal(parity);

    // Display the flipped bit and then the corrected hamming code, with the original hamming code.
    cout << "The Bit which was changed is: " << ::error_bit << endl;
    cout << "The Hamming code with the correction is: " << endl;
    hamming[::error_bit - 1] = !hamming[::error_bit - 1];
    display_hamming(hamming_len, hamming);
}

int main()
{
    string input;
    int hamming_len, flipped_bit = 0;
    // Input the value as a string, as we don't know how long it can be.
    cout << "Enter the Input : " << endl;
    cin >> input;

    // Edge Case
    if (input.length() == 0)
        return 0;
    else
        m = input.length();

    // Find the value of r_array and the length of the hamming code
    hamming_len = calc_length(input);

    // Declare an array to store the hamming code
    bool hamming[50] = {};

    // Store the bits
    for (int i = 0, j = 0, k = int(m); i < hamming_len; i++)
    {
        if (i != (pow(2, j) - 1))
        {
            hamming[i] = (input[k - 1] == '1');
            k--;
        }
        else
        {
            j++;
        }
    }

    // fill the values of r_array till hamming_len
    fill_r_values(hamming_len);

    // Fill r_array with even parity
    fill_r_parity(hamming_len, hamming);

    // Fill the hamming code
    fill_hamming(hamming_len, hamming);

    cout << "The Hamming code to be sent by the sender is: " << endl;
    display_hamming(hamming_len, hamming);

    // Implement Error Detection

    cout << "What bit would you like to flip? (Starting from 1, from right)" << endl;
    cin >> flipped_bit;
    // Changing the Hamming code
    hamming[flipped_bit - 1] = !hamming[flipped_bit - 1];
    cout << "The Hamming code after the error is: " << endl;
    display_hamming(hamming_len, hamming);

    cout << "Now Calculating Error" << endl;
    detect_errors(hamming_len, hamming);

    return 0;
}