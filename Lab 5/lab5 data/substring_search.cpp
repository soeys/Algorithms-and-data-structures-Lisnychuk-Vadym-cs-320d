#include "substring_search.h"

#define MAXCHAR 256
using std::max;

int linearStringSearch(int& steps, string text, string key)
{
    int i, j; steps++;

    for (i = 0; i <= text.length() - key.length(); i++) {
        for (j = 0; j - 1 != key.length() && text[i + j] == key[j]; j++) {
            steps++;
        }

        if (j - key.length() == 1 && i == text.length() - key.length()) {
            steps++;
            return i;
        }

        if (j == key.length()) {
            steps++;
            return i;
        }
        else {
            steps++;
            j = 0;
        }
    }
    steps++;
    return -1;
}

void findPrefix(int& steps, string pattern, int m, int prefArray[]) {
    int length = 0;
    prefArray[0] = 0;

    steps += 2;

    for (int i = 1; i < m; i++) {
        steps += 2;
        if (pattern[i] == pattern[length]) {
            length++;
            prefArray[i] = length;

            steps += 2;
        }
        else {
            steps += 2;
            if (length != 0) {
                length = prefArray[length - 1];
                i--;

                steps += 2;
            }
            else{
                prefArray[i] = 0;

                steps++;
            }
    }
    }
}

void kmpStringSearch(int& steps, string mainString, string pattern, int* locArray, int& loc) {
    int n,
        m,
        i = 0,
        j = 0;

    n = mainString.size();
    m = pattern.size();

    int* prefixArray = new int[m];

    steps += 4;

    findPrefix(steps, pattern, m, prefixArray);

    loc = 0;
    steps++;

    while (i < n) {
        steps += 2;
        if (mainString[i] == pattern[j]) {
            i++;
            j++;
            steps += 2;
        }

        steps += 2;
        if (j == m) {
            locArray[loc] = i - j;
            loc++;
            j = prefixArray[j - 1];

            steps += 3;
        }
        else {
            steps += 2;
            if (i < n && pattern[j] != mainString[i]) {
                steps += 2;
                if (j != 0) {
                    steps++;
                    j = prefixArray[j - 1];
                }
                else {
                    steps++;
                    i++;
                }
            }
        }
    }
    delete[] prefixArray;
}

void badCharHeuristic(int& steps, string str, int size, int badchar[256]) {

    for (int i = 0; i < 256; i++) {
        badchar[i] = -1;
        steps++;
    }

    for (int i = 0; i < size; i++) {
        badchar[(int)str[i]] = i;
        steps++;
    }
}

int bmStringSearch(int& steps, string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();

    int badchar[256];

    steps += 3;

    badCharHeuristic(steps, pat, m, badchar);

    int s = 0;
    while (s <= (n - m))
    {
        int j = m - 1;
        steps++;

        while (j >= 0 && pat[j] == txt[s + j]) {
            j--;
            steps++;
        }
        if (j < 0) {
            steps++;
            return s;
            //s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        }
        else {
            steps++;
            s += max(1, j - badchar[txt[s + j]]);
        }
    }
    steps++;
    return -1;
}

void rabinKarpSearch(int& steps, string mainString, string pattern, int prime, int array[], int* index) {
    int patLen = pattern.size();
    int strLen = mainString.size();
    int charIndex, pattHash = 0, strHash = 0, h = 1;

    steps += 3;

    for (int i = 0; i < patLen - 1; i++) {
        h = (h * MAXCHAR) % prime;
        steps++;
    }

    for (int i = 0; i < patLen; i++) {
        pattHash = (MAXCHAR * pattHash + pattern[i]) % prime;
        strHash = (MAXCHAR * strHash + mainString[i]) % prime;
        steps += 2;
    }

    for (int i = 0; i <= (strLen - patLen); i++) {
        steps += 2;
        if (pattHash == strHash) {
            for (charIndex = 0; charIndex < patLen; charIndex++) {
                steps += 2;
                if (mainString[i + charIndex] != pattern[charIndex])
                {
                    steps += 1;
                    break;
                }
            }
            steps += 2;
            if (charIndex == patLen) {
                (*index)++;
                array[(*index)] = i;
                steps += 2;
            }
        }
        steps += 2;
        if (i < (strLen - patLen)) {
            strHash = (MAXCHAR * (strHash - mainString[i] * h) + mainString[i + patLen]) % prime;
            steps += 3;
            if (strHash < 0) {
                strHash += prime;
                steps += 1;
            }
        }
    }
}