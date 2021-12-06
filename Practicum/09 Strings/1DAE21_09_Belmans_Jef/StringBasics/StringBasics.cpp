#include "pch.h"


int main()
{
    string gotunberg{ "One morning, when Gregor Samsa woke from troubled dreams, he found himself transformed in his bed into a horrible vermin.He lay on his armour - like back, and if he lifted his head a little he could see his brown belly, slightly domedand divided by arches into stiff sections.The bedding washardly able to cover itand seemed ready to slide off any moment.His manylegs, pitifully thin compared with the size of the rest of him, waved about helplessly as he looked." };
    cout << "-- Explore string class --" << endl;
    cout << gotunberg << endl << endl;
    cout << "Size: " << gotunberg.size() << endl;
    cout << "Length : " << gotunberg.length() << endl << endl;

    for (int i = 0; i < gotunberg.size(); i++)
    {
        cout << gotunberg.c_str()[i] << "_";
    }

    cout << endl << endl;
    cout << "Capacity: " << gotunberg.capacity() << endl << endl;

    cout << "First character using []: " << gotunberg[0] << endl;
    cout << "Last character using []: " << gotunberg[gotunberg.size() - 1] << endl;
    cout << "First character using at: " << gotunberg.at(0) << endl;
    cout << "Last character using at: " << gotunberg.at(gotunberg.size() - 1) << endl << endl;

    string userInput{};

    cout << "The string to search for in the above text? ";
    cin >> userInput;

    cout << "Occurances of '" << userInput << "' at: " << endl;
    size_t pos{ gotunberg.find(userInput) };
    while (pos != string::npos)
    {
        cout << pos << " ";
        pos = gotunberg.find(userInput, pos + 1);
    }

    cout << endl << "In reverse order:" << endl;
    pos = gotunberg.rfind(userInput);
    while (pos != string::npos)
    {
        cout << pos << " ";
        pos = gotunberg.rfind(userInput, pos - 1);
    }

    string replacedStr{ gotunberg };
    cout << endl << "The string you want to replace with * in the above text?";
    cin >> userInput;

    pos = gotunberg.find(userInput);
    while (pos != string::npos)
    {
        for (size_t i = 0; i < userInput.length(); i++)
        {
            replacedStr.replace(pos + i, 1, "*");
        }
        
        pos = gotunberg.find(userInput, pos + 1);
    }

    cout << endl << replacedStr << endl << endl;

    replacedStr = gotunberg;
    cout << "The string you want to erase from the above text? ";
    cin >> userInput;

    pos = replacedStr.find(userInput);
    while (pos != string::npos)
    {
        replacedStr.erase(pos, userInput.length());
        pos = replacedStr.find(userInput, pos + 1);
    }

    cout << replacedStr << endl << endl;
    
    cout << "Size: " << replacedStr.size() << endl;
    cout << "Length: " << replacedStr.length() << endl;
    cout << "Capacity: " << replacedStr.capacity() << endl;
}