#include <iostream>
#include <unordered_map>
#include <string>
#include <locale>
#include <codecvt>

using namespace std;

wstring morseToText(const wstring& morse) {
    unordered_map<wstring, wchar_t> textMap = {
        {L".-", L'А'}, {L"-...", L'Б'}, {L".--", L'В'}, {L"--.", L'Г'}, {L"-..", L'Д'},
        {L".", L'Е'}, {L"...-", L'Ж'}, {L"--..", L'З'}, {L"..", L'И'}, {L".---", L'Й'},
        {L"-.-", L'К'}, {L".-..", L'Л'}, {L"--", L'М'}, {L"-.", L'Н'}, {L"---", L'О'},
        {L".--.", L'П'}, {L".-.", L'Р'}, {L"...", L'С'}, {L"-", L'Т'},
        {L"..-", L'У'}, {L"..-.", L'Ф'}, {L"....", L'Х'}, {L"-.-.", L'Ц'}, {L"---.", L'Ч'},
        {L"----", L'Ш'}, {L"--.-", L'Щ'}, {L".--.-.", L'Ъ'}, {L"-.--", L'Ы'},
        {L"-..-", L'Ь'}, {L"..-..", L'Э'}, {L"..--", L'Ю'}, {L".-.-", L'Я'}
    };

    wstring text = L"";
    wstring currentMorse = L"";
    for (wchar_t ch : morse) {
        if (ch == ' ') {
            if (!currentMorse.empty()) {
                text += textMap[currentMorse];
                currentMorse.clear();
            }
            continue;
        } else if (ch == '/') {
            text += ' ';
            continue;
        }
        currentMorse += ch;
    }

    if (!currentMorse.empty()) {
        text += textMap[currentMorse];
    }

    return text;
}

int main() {

    locale::global(locale("ru_RU.UTF-8"));
    wcout.imbue(locale());

        wstring morse;
        wcout << L"Введите текст в азбуке Морзе: ";
        getline(wcin, morse);
        wstring text = morseToText(morse);
        wcout << L"Текст на русском: " << text << endl;

    return 0;
}