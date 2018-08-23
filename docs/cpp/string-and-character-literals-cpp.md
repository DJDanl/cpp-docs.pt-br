---
title: Cadeia de caracteres e literais de caracteres (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- R
dev_langs:
- C++
helpviewer_keywords:
- L constant
- escape sequences
- Null strings, null-terminated strings
- literal strings, C++
- Null strings
- string literals, syntax
- string literals
- literal strings
- strings [C++], string literals
- NULL, character constant
- wide characters, strings
ms.assetid: 61de8f6f-2714-4e7b-86b6-a3f885d3b9df
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0a3a3fa5d6e9836f7de949d4c13ec19f90dbcb02
ms.sourcegitcommit: b92ca0b74f0b00372709e81333885750ba91f90e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/16/2018
ms.locfileid: "42572807"
---
# <a name="string-and-character-literals--c"></a>Cadeia de caracteres e literais de caracteres (C++)
C++ oferece suporte a vários tipos de cadeia de caracteres e caracteres e fornece modos para expressar valores literais de cada um desses tipos. No seu código-fonte, é possível expressar o conteúdo de seu literais de caracteres e cadeia de caracteres usando um conjunto de caracteres. Nomes de caracteres universais e caracteres de escape permitem expressar qualquer cadeia de caracteres usando apenas o conjunto de caracteres de origem básicos. Uma cadeia de caracteres bruta literal permite que você evite usar caracteres de escape e pode ser usada para expressar todos os tipos de literais de cadeia de caracteres. Você também pode criar literais de std:: String sem ter que executar etapas de conversão ou extra construção.  
  
```cpp  
#include <string>  
using namespace std::string_literals; // enables s-suffix for std::string literals  
  
int main()  
{  
    // Character literals  
    auto c0 =   'A'; // char  
    auto c1 = u8'A'; // char  
    auto c2 =  L'A'; // wchar_t  
    auto c3 =  u'A'; // char16_t  
    auto c4 =  U'A'; // char32_t  
  
    // String literals  
    auto s0 =   "hello"; // const char*  
    auto s1 = u8"hello"; // const char*, encoded as UTF-8  
    auto s2 =  L"hello"; // const wchar_t*  
    auto s3 =  u"hello"; // const char16_t*, encoded as UTF-16  
    auto s4 =  U"hello"; // const char32_t*, encoded as UTF-32  
  
    // Raw string literals containing unescaped \ and "  
    auto R0 =   R"("Hello \ world")"; // const char*  
    auto R1 = u8R"("Hello \ world")"; // const char*, encoded as UTF-8  
    auto R2 =  LR"("Hello \ world")"; // const wchar_t*  
    auto R3 =  uR"("Hello \ world")"; // const char16_t*, encoded as UTF-16  
    auto R4 =  UR"("Hello \ world")"; // const char32_t*, encoded as UTF-32  
  
    // Combining string literals with standard s-suffix  
    auto S0 =   "hello"s; // std::string  
    auto S1 = u8"hello"s; // std::string  
    auto S2 =  L"hello"s; // std::wstring  
    auto S3 =  u"hello"s; // std::u16string  
    auto S4 =  U"hello"s; // std::u32string  
  
    // Combining raw string literals with standard s-suffix  
    auto S5 =   R"("Hello \ world")"s; // std::string from a raw const char*  
    auto S6 = u8R"("Hello \ world")"s; // std::string from a raw const char*, encoded as UTF-8  
    auto S7 =  LR"("Hello \ world")"s; // std::wstring from a raw const wchar_t*  
    auto S8 =  uR"("Hello \ world")"s; // std::u16string from a raw const char16_t*, encoded as UTF-16  
    auto S9 =  UR"("Hello \ world")"s; // std::u32string from a raw const char32_t*, encoded as UTF-32  
}  
```  
  
 Literais de cadeia de caracteres não podem ter nenhum prefixo, ou `u8`, `L`, `u`, e `U` prefixos para denotar restringir caractere (byte único ou vários byte), o caractere UTF-8, largo (UCS-2 ou UTF-16), o UTF-16 e codificações UTF-32, respectivamente. Um literal de cadeia bruto pode ter `R`, `u8R`, `LR`, `uR` e `UR` prefixos para os equivalentes de versão bruta essas codificações.  Para criar valores temporários ou estático std:: String, você pode usar literais de cadeia de caracteres ou literais de cadeia de caracteres bruta com um `s` sufixo. Para obter mais informações, consulte a seção de literais de cadeia de caracteres abaixo. Para obter mais informações sobre o caractere de origem básicos definido, nomes de caracteres universais e uso de caracteres de páginas de código estendidas em seu código-fonte, consulte [conjuntos de caracteres](../cpp/character-sets.md).  
  
## <a name="character-literals"></a>Literais de caracteres  
 Um *literal de caractere* é composto de uma constante de caractere. Ele é representado pelo caractere entre aspas simples. Há cinco tipos de literais de caracteres:  
  
-   Literais de caractere comum do tipo **char**, por exemplo `'a'`  
  
-   Literais de caracteres UTF-8, do tipo **char**, por exemplo `u8'a'`  
  
-   Literais de caractere largo do tipo `wchar_t`, por exemplo `L'a'`  
  
-   Literais de caractere UTF-16 do tipo `char16_t`, por exemplo `u'a'`  
  
-   Literais de caractere UTF-32 do tipo `char32_t`, por exemplo `U'a'`  
  
 O caractere usado para um literal de caractere pode ser qualquer caractere, exceto caracteres reservados barra invertida ('\\'), aspas simples (') ou nova linha. Caracteres reservados podem ser especificados usando uma sequência de escape. Caracteres podem ser especificados por meio de nomes de caractere universal, desde que o tipo é grande o suficiente para conter o caractere.  
  
### <a name="encoding"></a>Codificando  
 Literais de caracteres são codificados de forma diferente com base em seu prefixo.  
  
-   Um caractere literal sem um prefixo é um literal de caractere comum. Sequência de escape que contém um único caractere, o valor de um literal de caractere comum ou nome de caractere universal que pode ser representado no conjunto de caracteres de execução tem um valor igual ao valor numérico de sua codificação no conjunto de caracteres de execução. Um literal de caractere comum que contém mais de um caractere, a sequência de escape ou o nome de caractere universal é uma *literal de caractere múltiplo*. Um literal de multicaracteres ou um literal de caractere comum que não pode ser representado no conjunto de caracteres de execução é condicionalmente com suporte, tem o tipo int, e seu valor é definido pela implementação.  
  
-   Um literal de caractere que começa com o prefixo L é um literal de caractere largo. O valor de um literal de caractere largo que contém um único caractere, uma sequência de escape ou um nome de caractere universal tem um valor igual ao valor numérico de sua codificação no execução wide-conjunto de caracteres, a menos que o literal de caractere não tem representação conjunto de caractere largo de execução, no caso, o valor é definido pela implementação. O valor de um literal de caractere largo que contém vários caracteres, sequências de escape ou nomes de caracteres universais é definido pela implementação.  
  
-   Um literal de caractere que começa com o prefixo u8 é um literal de caractere UTF-8. Sequência de escape que contém um único caractere, o valor de um literal de caractere UTF-8 ou o nome de caractere universal tem um valor igual a seu valor de ponto de código ISO 10646 se ele pode ser representado por uma única unidade de código UTF-8 (correspondentes aos controles C0 e Latim básico Bloco de Unicode). Se o valor não pode ser representado por uma única unidade de código UTF-8, o programa está mal formado. Um caractere UTF-8 literal contendo mais de um caractere, sequência de escape ou nome de caractere universal está mal formado.  
  
-   Um literal de caractere que começa com o prefixo de u é um literal de caractere UTF-16. Sequência de escape que contém um único caractere, o valor de um literal de caractere UTF-16 ou nome de caractere universal tem um valor igual a seu valor de ponto de código ISO 10646 se ele pode ser representado por uma única unidade de código UTF-16 (correspondente ao plano multilíngue básico ). Se o valor não pode ser representado por uma única unidade de código UTF-16, o programa está mal formado. Um caractere UTF-16 literal contendo mais de um caractere, sequência de escape ou nome de caractere universal está mal formado.  
  
-   Um literal de caractere que começa com o prefixo de U é um literal de caractere UTF-32. Sequência de escape que contém um único caractere, o valor de um literal de caractere UTF-32 ou nome de caractere universal não tem um valor igual a seu valor de ponto de código ISO 10646. Um caractere UTF-8 literal contendo mais de um caractere, sequência de escape ou nome de caractere universal está mal formado.  
  
###  <a name="bkmk_Escape"></a> Sequências de escape  
 Há três tipos de sequências de escape: simples, octais e hexadecimais. As sequências de escape podem ser qualquer uma das seguintes:  
  
|Valor|Sequência de escape|Valor|Sequência de escape|  
|-----------|---------------------|-----------|---------------------|  
|nova linha|\n|barra invertida|\\\|  
|tabulação horizontal|\t|ponto de interrogação|? ou \\?|  
|tabulação vertical|\v|aspas simples|\\'|  
|backspace|\b|aspas duplas|\\"|  
|retorno de carro|\r|o caractere nulo|\0|  
|avanço de página|\f|octal|\ooo|  
|alerta (sino)|\a|hexadecimal|\xhhh|  
  
 O código a seguir mostra alguns exemplos de caracteres de escape usando literais de caractere comum. A mesma sintaxe de sequência de escape é válida para os outros tipos de literal de caractere.  
  
```cpp  
#include <iostream>  
using namespace std;  
  
int main() {  
    char newline = '\n';  
    char tab = '\t';  
    char backspace = '\b';  
    char backslash = '\\';  
    char nullChar = '\0';  
  
    cout << "Newline character: " << newline << "ending" << endl; // Newline character:  
                                                                  //  ending  
    cout << "Tab character: " << tab << "ending" << endl; // Tab character : ending  
    cout << "Backspace character: " << backspace << "ending" << endl; // Backspace character : ending  
    cout << "Backslash character: " << backslash << "ending" << endl; // Backslash character : \ending  
    cout << "Null character: " << nullChar << "ending" << endl; //Null character:  ending  
}  
```  
  
 **Seção específica da Microsoft**  
  
 Para criar um valor de um literal de caractere comum (aqueles sem um prefixo), o compilador converte o caractere ou cadeia de caracteres entre aspas em valores de 8 bits em um inteiro de 32 bits. Vários caracteres no literal preencher bytes correspondentes, conforme a necessidade de ordem superior de ordem inferior. Para criar uma **char** valor, o compilador usa o byte de ordem inferior. Para criar uma **wchar_t** ou `char16_t` valor, o compilador usa a palavra de ordem inferior. O compilador avisa que o resultado será truncado se todos os bits são definidos acima do byte atribuído ou word.  
  
```cpp  
char c0    = 'abcd';    // C4305, C4309, truncates to 'd'  
wchar_t w0 = 'abcd';    // C4305, C4309, truncates to '\x6364'  
```  
  
 Uma sequência de escape octal é uma barra invertida seguida por uma sequência de até 3 dígitos octais. O comportamento de uma sequência de escape octal que parece conter mais de três dígitos é tratado como uma sequência de 3 dígitos octa seguida por dígitos subsequentes como caracteres; Isso pode gerar resultados surpreendentes. Por exemplo:  
  
```cpp  
char c1 = '\100';   // '@'  
char c2 = '\1000';  // C4305, C4309, truncates to '0'   
```  
  
 Sequências de escape que parecem conter caracteres não octais são avaliadas como uma octal sequência até o último caractere octal, seguido pelos caracteres restantes. Por exemplo:  
  
```cpp  
char c3 = '\009';   // '9'  
char c4 = '\089';   // C4305, C4309, truncates to '9'  
char c5 = '\qrs';   // C4129, C4305, C4309, truncates to 's'  
```  
  
 Uma sequência de escape hexadecimal é uma barra invertida, seguida pelo caractere `x`, seguido por uma sequência de dígitos hexadecimais. Uma sequência de escape que não contém nenhum dígito hexadecimal causa o erro do compilador C2153: "literais hexadecimais devem possuir pelo menos um dígito hex". Zeros à esquerda são ignorados. Uma sequência de escape que parece ter caracteres hexadecimal e não hexadecimais é avaliada como uma sequência de escape hexadecimal até o último caractere hexadecimal, seguido pelos caracteres não hexadecimal.   Em um caractere comum ou o prefixo de u8 literal, o valor hexadecimal mais alto é 0xFF. Em um L-o prefixo ou o prefixo de u literal de caractere largo, o valor hexadecimal mais alto é 0xFFFF. Em um prefixado por U literal de caractere largo, o valor hexadecimal mais alto é 0xFFFFFFFF.  
  
```cpp  
char c6 = '\x0050'; // 'P'  
char c7 = '\x0pqr'; // C4305, C4309, truncates to 'r'  
```  
  
 Se um literal de caractere largo prefixadas com `L` contém mais de um caractere, o valor é obtido a partir do primeiro caractere. Os caracteres subsequentes são ignorados, ao contrário do comportamento do literal de caractere comum equivalente.  
  
```cpp  
wchar_t w1 = L'\100';   // L'@'  
wchar_t w2 = L'\1000';  // C4066 L'@', 0 ignored   
wchar_t w3 = L'\009';   // C4066 L'\0', 9 ignored  
wchar_t w4 = L'\089';   // C4066 L'\0', 89 ignored  
wchar_t w5 = L'\qrs';   // C4129, C4066 L'q' escape, rs ignored  
wchar_t w6 = L'\x0050'; // L'P'  
wchar_t w7 = L'\x0pqr'; // C4066 L'\0', pqr ignored  
```  
  
 **Fim da seção específica da Microsoft**  
  
 O caractere de barra invertida (\\) é um caractere de continuação de linha quando ele é colocado no final de uma linha. Se desejar que um caractere de barra invertida seja exibido como uma literal de caractere, você deve digitar duas barras invertidas em uma linha (`\\`). Para obter mais informações sobre o caractere de continuação de linha, consulte [fases de conversão](../preprocessor/phases-of-translation.md).  
  
###  <a name="bkmk_UCN"></a> Nomes de caracteres universais  
 Em literais de caracteres e literais de cadeia de caracteres nativo (não bruto), qualquer caractere pode ser representado por um nome de caractere universal.  Nomes de caracteres universais são formados por um prefixo que \u seguido por um ponto de código Unicode de oito dígitos, ou por um \u prefixo seguido por um ponto de código Unicode com quatro dígitos. Todos os quatro ou oito dígitos, respectivamente, devem estar presentes para fazer um nome de caractere universal bem formado.  
  
```cpp  
char u1 = 'A';          // 'A'  
char u2 = '\101';       // octal, 'A'   
char u3 = '\x41';       // hexadecimal, 'A'  
char u4 = '\u0041';     // \u UCN 'A'  
char u5 = '\U00000041'; // \U UCN 'A'  
```  
  
 **Pares substitutos**  
  
 Nomes de caractere universal não é possível codificar valores no intervalo de ponto de código substituto u+D800 DFFF. Para pares substitutos de Unicode, especifique o nome de caractere universal usando `\UNNNNNNNN`, onde NNNNNNNN é o ponto de código de oito dígitos do caractere. O compilador gera um par substituto, se necessário.  
  
 No c++03, a linguagem somente permitido a um subconjunto de caracteres a ser representado por seus nomes de caractere universal e permitidos alguns nomes de caractere universal que, na verdade, não representam caracteres Unicode válidos. Isso foi corrigido o padrão c++11. No c++11, identificadores e literais de caracteres e cadeia de caracteres podem usar nomes de caracteres universais.  Para obter mais informações sobre nomes de caracteres universais, consulte [conjuntos de caracteres](../cpp/character-sets.md). Para obter mais informações sobre Unicode, consulte [Unicode](http://msdn.microsoft.com/library/dd374081\(v=vs.85\).aspx). Para obter mais informações sobre pares substitutos, consulte [pares substitutos e caracteres suplementares](/windows/desktop/Intl/surrogates-and-supplementary-characters).  
  
## <a name="string-literals"></a>Literais de cadeia de caracteres  
 Uma literal de cadeia de caracteres representa uma sequência de caracteres que, juntos, formam uma cadeia de caracteres terminada em nulo. Os caracteres devem ser incluídos entre aspas duplas. Existem os seguintes tipos de literais de cadeias de caracteres:  
  
### <a name="narrow-string-literals"></a>Literais de cadeia de caracteres estreita  
 Um literal de cadeia estreita é uma matriz de delimitado terminada em nulo, sem prefixo, aspas duplas de tipo `const char[n]`, onde n é o comprimento da matriz em bytes. Um literal de cadeia estreita pode conter qualquer caractere gráfico exceto as aspas duplas (`"`), barra invertida (`\`), ou caractere de nova linha. Um literal de cadeia estreita também pode conter os nomes de caracteres listados acima e universais de sequências de escape que se encaixam em um byte.  
  
```cpp  
const char *narrow = "abcd";  
  
// represents the string: yes\no  
const char *escaped = "yes\\no";  
```  
  
#### <a name="utf-8-encoded-strings"></a>Cadeias de caracteres codificados em UTF-8  
  
 Uma cadeia de caracteres codificada em UTF-8 é uma matriz de delimitado terminada em nulo, prefixado por u8, aspas duplas de tipo `const char[n]`, onde n é o comprimento da matriz codificada em bytes. Um literal de cadeia prefixado por u8 pode conter qualquer caractere gráfico exceto as aspas duplas (`"`), barra invertida (`\`), ou caractere de nova linha. Uma cadeia de caracteres prefixadas por u8 literal também pode conter o escape sequências listadas acima e qualquer nome de caractere universal.  
  
```cpp  
const char* str1 = u8"Hello World";  
const char* str2 = u8"\U0001F607 is O:-)";  
```  
  
### <a name="wide-string-literals"></a>Literais de cadeia de caracteres largos  
 Uma cadeia de caracteres largo literal é uma matriz terminada em nulo da constante **wchar_t** que é prefixada pelo '`L`' e contém qualquer caractere gráfico exceto as aspas duplas ("), barra invertida (\\), ou caractere de nova linha. Uma cadeia de caracteres largo literal pode conter o escape sequências listadas acima e qualquer nome de caractere universal.  
  
```cpp  
const wchar_t* wide = L"zyxw";  
const wchar_t* newline = L"hello\ngoodbye";  
```  
  
#### <a name="char16t-and-char32t-c11"></a>char16_t e char32_t (c++11)  
  
 C++11 introduz o portable `char16_t` (Unicode de 16 bits) e `char32_t` (Unicode de 32 bits) tipos de caracteres:  
  
```cpp  
auto s3 = u"hello"; // const char16_t*  
auto s4 = U"hello"; // const char32_t*  
```  
  
### <a name="raw-string-literals-c11"></a>Literais de cadeia de caracteres bruta (c++11)  
 Uma cadeia de caracteres bruta literal é uma matriz terminada em nulo — de qualquer tipo de caractere, que contém qualquer caractere gráfico, incluindo as aspas duplas ("), barra invertida (\\), ou caractere de nova linha. As literais de cadeias de caracteres brutas costumam ser usadas em expressões regulares que utilizam classes de caracteres, bem como em cadeias de caracteres HTML e XML. Para obter exemplos, consulte o artigo a seguir: [FAQ de Bjarne Stroustrup no c++11](http://go.microsoft.com/fwlink/p/?linkid=401172).  
  
```cpp  
// represents the string: An unescaped \ character  
const char* raw_narrow = R"(An unescaped \ character)";  
const wchar_t* raw_wide = LR"(An unescaped \ character)";  
const char*       raw_utf8  = u8R"(An unescaped \ character)";  
const char16_t* raw_utf16 = uR"(An unescaped \ character)";  
const char32_t* raw_utf32 = UR"(An unescaped \ character)";  
```  
  
 Um delimitador é uma sequência definida pelo usuário, com até 16 caracteres, que vem imediatamente antes do parêntese de abertura e imediatamente depois do parêntese de fechamento de uma literal de cadeia de caracteres bruta.  Por exemplo, na `R"abc(Hello"\()abc"` é a sequência de delimitador `abc` e o conteúdo de cadeia de caracteres é `Hello"\(`. Você pode usar um delimitador para desambiguizar cadeias de caracteres brutas que contêm aspas duplas e parênteses. Isso causa um erro do compilador:  
  
```cpp  
// meant to represent the string: )"  
const char* bad_parens = R"()")";  // error C2059  
```  
  
 Mas um delimitador resolve essa sintaxe:  
  
```cpp  
const char* good_parens = R"xyz()")xyz";  
```  
  
 Você pode construir uma literal de cadeia de caracteres bruta em que há uma nova linha (não o caractere de escape) na origem:  
  
```cpp  
// represents the string: hello  
//goodbye  
const wchar_t* newline = LR"(hello  
goodbye)";  
```  
  
### <a name="stdstring-literals-c14"></a>std:: string literais (c++14)  
 literais de std:: string são implementações da biblioteca padrão de definida pelo usuário literais (veja abaixo) que são representados como "xyx" s (com um `s` sufixo). Esse tipo de cadeia de caracteres literal produz um objeto temporário do tipo std:: String, std:: wstring, std::u32string ou std::u16string dependendo do prefixo especificado. Quando nenhum prefixo é usado, como acima, um std:: string é produzido. L "xyz" s produz um std:: wstring. u "xyz" s produz um [std::u16string](../standard-library/string-typedefs.md#u16string)e "xyz" U s gera um [std::u32string](../standard-library/string-typedefs.md#u32string).  
  
```cpp  
//#include <string>  
//using namespace std::string_literals;  
string str{ "hello"s };  
string str2{ u8"Hello World" };  
wstring str3{ L"hello"s };  
u16string str4{ u"hello"s };  
u32string str5{ U"hello"s };  
```  
  
 O sufixo s também pode ser usado em literais de cadeia de caracteres bruta:  
  
```cpp  
u32string str6{ UR"(She said "hello.")"s };  
```  
  
 literais de std:: string são definidos no namespace `std::literals::string_literals` no \<cadeia de caracteres > arquivo de cabeçalho. Porque `std::literals::string_literals`, e `std::literals` são declarados como [namespaces embutidos](../cpp/namespaces-cpp.md), `std::literals::string_literals` é tratado automaticamente como se ele pertencesse diretamente no namespace `std`.  
  
### <a name="size-of-string-literals"></a>Tamanho das literais de cadeias de caracteres  
 Para o caractere ANSI\* cadeias de caracteres e outras codificações de byte único (não UTF-8), o tamanho (em bytes) de um literal de cadeia de caracteres é o número de caracteres mais 1 para o caractere nulo de terminação. Para todos os outros tipos de cadeia de caracteres, o tamanho não está estritamente relacionado ao número de caracteres. UTF-8 usa até quatro elementos de char para codificar alguns *unidades de código*e char16_t ou wchar_t, codificada como UTF-16 pode usar dois elementos (para um total de quatro bytes) para codificar uma única *unidade de código*.   Este exemplo mostra o tamanho de uma cadeia de caracteres largo literal em bytes:  
  
```cpp  
const wchar_t* str = L"Hello!";  
const size_t byteSize = (wcslen(str) + 1) * sizeof(wchar_t);  
```  
  
 Observe que `strlen()` e `wcslen()` não incluem o tamanho do caractere nulo de terminação, cujo tamanho é igual ao tamanho do elemento do tipo cadeia de caracteres: um byte em um char\* cadeia de caracteres, dois bytes em wchar_t\* ou char16_t\*cadeias de caracteres e quatro bytes no char32_t\* cadeias de caracteres.  
  
 O comprimento máximo de uma literal de cadeia de caracteres é de 65535 bytes. Esse limite se aplica às literais de cadeias de caracteres estreitas e largas.  
  
### <a name="modifying-string-literals"></a>Modificando literais de cadeias de caracteres  
 Como os literais de cadeia de caracteres (não incluindo std:string literais) são constantes, tentar modificá-las — por exemplo, STR[2] = 'A' — faz com que um erro do compilador.  
  
 **Seção específica da Microsoft**  
  
 No Visual C++, você pode usar um literal de cadeia de caracteres para inicializar um ponteiro para não const **char** ou **wchar_t**. Isso é permitido no código C99, mas é preterido no c++98 e removido no c++11. Uma tentativa de modificar a cadeia de caracteres causa uma violação de acesso, como neste exemplo:  
  
```cpp  
wchar_t* str = L"hello";  
str[2] = L'a'; // run-time error: access violation  
```  
  
 Você pode fazer com que o compilador emita um erro quando um literal de cadeia de caracteres é convertida em um ponteiro de caractere non_const ao definir a [/ZC: strictstrings (desabilitar conversão de tipo literal de cadeia de caracteres)](../build/reference/zc-strictstrings-disable-string-literal-type-conversion.md) opção de compilador. É recomendável para código portátil compatível com os padrões. Também é uma boa prática usar a **automática** palavra-chave para declarar ponteiros inicializados por literais, a cadeia de caracteres porque ele resolve para o tipo correto (const). Por exemplo, este exemplo de código mostra uma tentativa de gravar em uma cadeia de caracteres literal no tempo de compilação:  
  
```cpp  
auto str = L"hello";  
str[2] = L'a'; // C3892: you cannot assign to a variable that is const.  
```  
  
 Em alguns casos, literais de cadeias de caracteres idênticas podem ser agrupadas para economizar espaço no arquivo executável. Em pools de literais de cadeias de caracteres, o compilador faz com que todas as referências a uma literal de cadeia de caracteres específica apontem para o mesmo local na memória, em vez de cada referência apontar para uma instância separada da literal. Para habilitar o pooling de cadeia de caracteres, use o [/GF](../build/reference/gf-eliminate-duplicate-strings.md) opção de compilador.  
  
 **Fim da seção específica da Microsoft**  
  
### <a name="concatenating-adjacent-string-literals"></a>Concatenando literais de cadeias de caracteres adjacentes  
 Literais de cadeia de caracteres largos ou estreitos adjacentes são concatenados. Esta declaração:  
  
```cpp  
char str[] = "12" "34";  
```  
  
 é idêntica a esta declaração:  
  
```cpp  
char atr[] = "1234";  
```  
  
 e a esta declaração:  
  
```cpp  
char atr[] =  "12\  
34";  
```  
  
 Usando os códigos de escape hexadecimais inseridos para especificar literais de cadeia de caracteres pode causar resultados inesperados. O exemplo a seguir visa criar uma literal de cadeia de caracteres que contenha o caractere ASCII 5, seguido pelos caracteres "f", "i", "v" e "e":  
  
```cpp  
"\x05five"  
```  
  
 O resultado real é um 5F hexadecimal, que é o código ASCII de um sublinhado, seguido pelos caracteres i, v e e. Para obter o resultado correto, você pode usar uma destas opções:  
  
```cpp  
"\005five"     // Use octal literal.  
"\x05" "five"  // Use string splicing.  
```  
  
 literais de std:: String, porque eles são tipos de std:: String, podem ser concatenados com o operador está definido para + [basic_string](../standard-library/basic-string-class.md) tipos. Eles também podem ser concatenados da mesma forma como os literais de cadeia de caracteres adjacentes. Em ambos os casos, a codificação de cadeia de caracteres e o sufixo devem corresponder ao:  
  
```cpp  
auto x1 = "hello" " " " world"; // OK  
auto x2 = U"hello" " " L"world"; // C2308: disagree on prefix  
auto x3 = u8"hello" " "s u8"world"s; // OK, agree on prefixes and suffixes  
auto x4 = u8"hello" " "s u8"world"z; // C3688, disagree on suffixes  
```  
  
### <a name="string-literals-with-universal-character-names"></a>Literais de cadeia de caracteres com nomes de caracteres universais  
 Literais de cadeia de caracteres nativo (não bruto) podem usar nomes de caracteres universais para representar qualquer caractere, desde que o nome de caractere universal pode ser codificado como um ou mais caracteres no tipo de cadeia de caracteres.  Por exemplo, um nome de caractere universal que representa um caractere estendido não pode ser codificado em uma cadeia de caracteres estreita usando a página de código ANSI, mas ela pode ser codificada em cadeias de caracteres estreitas em algumas páginas de código multibyte em cadeias de caracteres UTF-8 ou em uma cadeia de caracteres largo. No c++11, suporte a Unicode é estendido pelo char16_t\* e char32_t\* tipos de cadeia de caracteres:  
  
```cpp  
// ASCII smiling face  
const char*     s1 = ":-)";    
  
// UTF-16 (on Windows) encoded WINKING FACE (U+1F609)  
const wchar_t*  s2 = L"😉 = \U0001F609 is ;-)";    
  
// UTF-8  encoded SMILING FACE WITH HALO (U+1F607)  
const char*     s3 = u8"😇 = \U0001F607 is O:-)";  
  
// UTF-16 encoded SMILING FACE WITH OPEN MOUTH (U+1F603)  
const char16_t* s4 = u"😃 = \U0001F603 is :-D";  
  
// UTF-32 encoded SMILING FACE WITH SUNGLASSES (U+1F60E)  
const char32_t* s5 = U"😎 = \U0001F60E is B-)";  
```  
  
## <a name="see-also"></a>Consulte também  
 [Conjuntos de caracteres](../cpp/character-sets.md)   
 [Numérico, booliano e literais de ponteiro](../cpp/numeric-boolean-and-pointer-literals-cpp.md)   
 [Literais definidos pelo usuário](../cpp/user-defined-literals-cpp.md)