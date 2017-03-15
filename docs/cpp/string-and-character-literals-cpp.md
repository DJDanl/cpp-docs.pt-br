---
title: "Cadeia de caracteres e caracteres literais (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "R"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "constante L"
  - "sequências de escape"
  - "Cadeias de caracteres nulas, cadeias de caracteres terminada em nulo"
  - "cadeias de caracteres literal, C++"
  - "Cadeias de caracteres nulas"
  - "literais de cadeia de caracteres, sintaxe"
  - "literais String"
  - "cadeias de caracteres literais"
  - "cadeias de caracteres [C++], literais de cadeia de caracteres"
  - "Constante de caractere nulo,"
  - "caracteres largos, cadeias de caracteres"
ms.assetid: 61de8f6f-2714-4e7b-86b6-a3f885d3b9df
caps.latest.revision: 36
caps.handback.revision: 34
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Cadeia de caracteres e caracteres literais (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

C\+\+ oferece suporte a vários tipos de cadeia de caracteres e caracteres e fornece maneiras para expressar valores literais de cada um desses tipos. No código\-fonte, você expressar o conteúdo de seu literais de caracteres usando um conjunto de caracteres. Nomes de caracteres universais e caracteres de escape permite que você expresse qualquer cadeia de caracteres usando apenas o conjunto de caracteres de origem básico. Um literal de cadeia bruto permite que você evite usar caracteres de escape e pode ser usado para expressar todos os tipos de literais de cadeia de caracteres. Você também pode criar literais STD sem precisar executar etapas de conversão ou construção extra.  
  
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
    auto R1 = u8R"("Hello \ world")"; // const char*, encoded as UTF-8  
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
  
 Literais de cadeia de caracteres não podem ter nenhum prefixo, ou `u8`, `L`, `u`, e  `U` prefixos para denotar restringir caractere \(byte único ou vários byte\), caracteres UTF\-8, largo \(UCS\-2 ou UTF\-16\), UTF\-16 e UTF\-32 codificações, respectivamente. Um literal de cadeia bruto pode ter `R`, `u8R`, `LR`, `uR` e `UR` prefixos para os equivalentes de versão bruta essas codificações.  Para criar valores STD temporária ou estático, você pode usar literais de cadeia de caracteres ou literais de cadeia de caracteres bruta com um `s` sufixo. Para obter mais informações, consulte a seção de literais de cadeia de caracteres abaixo. Para obter mais informações sobre o caractere de origem básico definir nomes de caracteres universais e usando caracteres de páginas de código estendidas em seu código\-fonte, consulte [Conjuntos de caracteres](../cpp/character-sets2.md).  
  
## Literais de caracteres  
 Um *literal de caractere* é composto de uma constante de caractere. Ela é representada pelo caractere entre aspas simples. Há quatro tipos de literais de caracteres:  
  
-   Literais de caractere estreito do tipo `char`, por exemplo `'a'`  
  
-   Literais de caractere largo do tipo `wchar_t`, por exemplo `L'a'`  
  
-   Literais de caractere largo do tipo `char16_t`, por exemplo `u'a'`  
  
-   Literais de caractere largo do tipo `char32_t`, por exemplo `U'a'`  
  
 O caractere usado para um literal de caractere pode ser qualquer caractere, exceto caracteres reservados uma barra invertida \('\\ '\), aspas simples \('\) ou nova linha. Caracteres reservados podem ser especificados usando uma sequência de escape. Caracteres podem ser especificados usando nomes de caracteres universais, desde que o tipo é grande o suficiente para conter o caractere.  
  
###  <a name="bkmk_Escape"></a> Sequências de Escape  
 Há três tipos de seqüências de escape: simples, octais e hexadecimais. Seqüências de escape podem ser qualquer um dos seguintes:  
  
|Valor|Sequência de escape|Valor|Sequência de escape|  
|-----------|-------------------------|-----------|-------------------------|  
|nova linha|\\n|barra invertida|\\\\|  
|tabulação horizontal|\\t|ponto de interrogação|? ou \\?|  
|tabulação vertical|\\v|aspas simples|\\'|  
|tecla BACKSPACE|\\b|aspas duplas|\\"|  
|retorno de carro|\\r|o caractere nulo|\\0|  
|avanço de página|\\f|octal|\\ooo|  
|alerta \(bell\)|\\a|hexadecimal|\\xhhh|  
  
 O código a seguir mostra alguns exemplos de caracteres de escape usando literais de cadeia de caracteres estreita. A mesma sintaxe é válida para os outros tipos de literal de cadeia de caracteres.  
  
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
  
 **Específico da Microsoft**  
  
 Para criar um valor de um caractere sem prefixo literal, o compilador converte o caractere ou uma seqüência de caracteres entre aspas em valores de 8 bits em um inteiro de 32 bits. Vários caracteres no literal preenchem bytes correspondentes conforme necessário, de ordem superior de ordem inferior. Para criar um `char` valor, o compilador usa o byte de ordem inferior. Para criar um `wchar_t` ou `char16_t` valor, o compilador usa a palavra de ordem inferior. O compilador avisa que o resultado será truncado se todos os bits são definidos acima do byte atribuído ou word.  
  
```cpp  
char c0    = 'abcd';    // C4305, C4309, truncates to 'd'  
wchar_t w0 = 'abcd';    // C4305, C4309, truncates to '\x6364'  
```  
  
 Uma sequência de escape octal é uma barra invertida seguida por uma seqüência de até 3 dígitos octais. O comportamento de uma sequência de escape octal parece conter mais de três dígitos é tratado como uma seqüência de 3 dígitos octa seguida por dígitos subseqüentes como caracteres; Isso pode gerar resultados surpreendentes. Por exemplo:  
  
```cpp  
char c1 = '\100';   // '@'  
char c2 = '\1000';  // C4305, C4309, truncates to '0'   
```  
  
 Seqüências de escape que parecem conter caracteres não octais são avaliadas como uma sequência octa até o último caractere octal, seguido pelos caracteres restantes. Por exemplo:  
  
```cpp  
char c3 = '\009';   // '9'  
char c4 = '\089';   // C4305, C4309, truncates to '9'  
char c5 = '\qrs';   // C4129, C4305, C4309, truncates to 's'  
```  
  
 Uma sequência de escape hexadecimal é uma barra invertida seguida pelo caractere `x`, seguido por uma seqüência de dígitos hexadecimais. Uma sequência de escape que contém nenhum dígito hexadecimal causa o erro do compilador C2153: "literais hexadecimais devem ter pelo menos um dígito hex". Zeros à esquerda são ignorados. Uma sequência de escape que parece ter caracteres hexadecimal e não hexadecimais é avaliada como uma seqüência de escape hexadecimal até o último caractere hexadecimal, seguido pelos caracteres não hexadecimal.   Em um sem prefixo ou prefixo u8 estreito caractere literal, o valor hexadecimal mais alto é 0xFF. Em um prefixo L ou o prefixo u amplo caractere literal, o maior valor hexadecimal é 0xFFFF. Em uma prefixo U ampla de caracteres literal, o maior valor hexadecimal é 0xFFFFFFFF.  
  
```cpp  
char c6 = '\x0050'; // 'P'  
char c7 = '\x0pqr'; // C4305, C4309, truncates to 'r'  
```  
  
 Se um literal de caractere largo prefixado com `L` contém mais de um caractere, o valor é obtido a partir do primeiro caractere. Os caracteres subsequentes são ignorados, ao contrário do comportamento do literal de caractere estreito sem prefixo equivalente.  
  
```cpp  
wchar_t w1 = L'\100';   // L'@'  
wchar_t w2 = L'\1000';  // C4066 L'@', 0 ignored   
wchar_t w3 = L'\009';   // C4066 L'\0', 9 ignored  
wchar_t w4 = L'\089';   // C4066 L'\0', 89 ignored  
wchar_t w5 = L'\qrs';   // C4129, C4066 L'q' escape, rs ignored  
wchar_t w6 = L'\x0050'; // L'P'  
wchar_t w7 = L'\x0pqr'; // C4066 L'\0', pqr ignored  
```  
  
 **FIM de específico da Microsoft**  
  
 O caractere de barra invertida \(\\\) é um caractere de continuação de linha quando ele for colocado no final de uma linha. Se você quiser um caractere de barra invertida seja exibido como um caractere literal, você deve digitar duas barras invertidas em uma linha \(`\\`\). Para obter mais informações sobre o caractere de continuação de linha, consulte [Fases de translação](../preprocessor/phases-of-translation.md).  
  
###  <a name="bkmk_UCN"></a> Nomes de caracteres universais  
 Em literais de caracteres e literais de cadeia de caracteres nativo \(não processados\), qualquer caractere pode ser representado por um nome de caracteres universais.  Nomes de caracteres universais são formados por um prefixo que \\u seguido por um ponto de código Unicode oito dígitos, ou por um \\u prefixo seguido por um ponto de código Unicode de quatro dígitos. Todos os quatro ou oito dígitos, respectivamente, devem estar presentes para que um nome de caracteres universais bem formado.  
  
```cpp  
char u1 = 'A';          // 'A'  
char u2 = '\101';       // octal, 'A'   
char u3 = '\x41';       // hexadecimal, 'A'  
char u4 = '\u0041';     // \u UCN 'A'  
char u5 = '\U00000041'; // \U UCN 'A'  
```  
  
 **Pares substitutos**  
  
 Nomes de caracteres universais não é possível codificar valores no intervalo de ponto de código substituto D800 DFFF. Pares substitutos de Unicode, especifique o nome de caractere universais usando `\UNNNNNNNN`, onde NNNNNNNN é o ponto de código de oito dígitos do caractere. O compilador gera um par substituto, se necessário.  
  
 No C\+\+ 03, a linguagem somente permitido um subconjunto de caracteres sejam representados por seus nomes de caracteres universais e permitidos alguns nomes de caracteres universais que realmente não representam caracteres Unicode válidos. Isso foi corrigido no C\+\+ 11 padrão. No C\+\+ 11, identificadores e literais de caracteres e cadeia de caracteres podem usar nomes de caracteres universais.  Para obter mais informações sobre nomes de caracteres universais, consulte [Conjuntos de caracteres](../cpp/character-sets2.md). Para obter mais informações sobre Unicode, consulte [Unicode](http://msdn.microsoft.com/library/dd374081\(v=vs.85\).aspx). Para obter mais informações sobre pares substitutos, consulte [pares substitutos e caracteres suplementares](http://msdn.microsoft.com/library/dd374069\(v=vs.85\).aspx).  
  
## Literais de cadeia de caracteres  
 Um literal de cadeia de caracteres representa uma seqüência de caracteres que juntos formam uma cadeia de caracteres terminada em nulo. Os caracteres devem ser colocados entre aspas duplas. Existem os seguintes tipos de literais de cadeia de caracteres:  
  
### Literais de cadeia de caracteres estreita  
 Uma cadeia de caracteres estreita literal é uma matriz de delimitado terminada em nulo, aspas duplas, sem prefixo de tipo `const` `char`\[`n`\], onde n é o comprimento da matriz de bytes. Um literal de cadeia estreita pode conter qualquer caractere gráfico exceto as aspas duplas \(`"`\), barra invertida \(`\`\), ou caractere de nova linha. Uma cadeia de caracteres estreita literal também pode conter os nomes de caractere listados acima e universal seqüências de escape que se encaixam em um byte.  
  
```cpp  
const char *narrow = "abcd";  
  
// represents the string: yes\no  
const char *escaped = "yes\\no";  
```  
  
 **Cadeias de caracteres codificado em UTF\-8**  
  
 Uma cadeia de caracteres codificados em UTF\-8 é uma matriz de delimitado terminada em nulo, aspas duplas, como prefixo u8 do tipo  `const``char`\[`n`\], onde n é o comprimento da matriz codificado em bytes. Uma cadeia de caracteres prefixadas u8 literal pode conter qualquer caractere gráfico exceto as aspas duplas \(`"`\), barra invertida \(`\`\), ou caractere de nova linha. Uma cadeia de caracteres prefixadas u8 literal também pode conter o escape sequências listadas acima e qualquer nome de caracteres universais.  
  
```cpp  
const char* str1 = u8"Hello World";  
const char* str2 = u8"\U0001F607 is O:-)";  
```  
  
### Literais de cadeia de caracteres larga  
 Uma cadeia de caracteres larga literal é uma matriz terminada em nulo da constante `wchar_t` que é prefixada pelas '`L`' e contém qualquer caractere gráfico exceto as aspas duplas \("\), barra invertida \(\\\) ou caractere de nova linha. Uma cadeia de caracteres larga literal pode conter o escape sequências listadas acima e qualquer nome de caracteres universais.  
  
```cpp  
const wchar_t* wide = L"zyxw";  
const wchar_t* newline = L"hello\ngoodbye";  
```  
  
 **char16\_t e char32\_t \(C \+ \+ 11\)**  
  
 C\+\+ 11 introduz o portable `char16_t` \(Unicode de 16 bits\) e `char32_t` \(32 bits Unicode\) tipos de caracteres:  
  
```cpp  
auto s3 = u"hello"; // const char16_t*  
auto s4 = U"hello"; // const char32_t*  
```  
  
### Literais de cadeia de caracteres bruta \(C \+ \+ 11\)  
 Um literal de cadeia bruto é uma matriz terminada em nulo — de qualquer tipo de caractere — que contém qualquer caractere gráfico, incluindo as aspas duplas \("\), barra invertida \(\\\) ou caractere de nova linha. Literais de cadeia de caracteres bruta geralmente são usadas em expressões regulares que usam classes de caracteres e em cadeias de caracteres HTML e XML. Para obter exemplos, consulte o seguinte artigo: [perguntas Frequentes de Bjarne em C\+\+ 11](http://go.microsoft.com/fwlink/?LinkId=401172).  
  
```cpp  
// represents the string: An unescaped \ character  
const char* raw_narrow = R"(An unescaped \ character)";  
const wchar_t* raw_wide = LR"(An unescaped \ character)";  
const char*       raw_utf8  = u8R"(An unescaped \ character)";  
const char16_t* raw_utf16 = uR"(An unescaped \ character)";  
const char32_t* raw_utf32 = UR"(An unescaped \ character)";  
```  
  
 Um delimitador é uma seqüência de até 16 caracteres definidos pelo usuário que precede o parêntese de abertura de um literal de cadeia bruto e imediatamente após o parêntese de fechamento.  Por exemplo, no `R"abc(Hello"\()abc"` a seqüência de delimitador é `abc` e o conteúdo de cadeia de caracteres é `Hello"\(`. Você pode usar um delimitador para resolver a ambiguidade brutas cadeias de caracteres que contêm aspas duplas e parênteses. Isso causa um erro do compilador:  
  
```cpp  
// meant to represent the string: )”  
const char* bad_parens = R"()")";  // error C2059  
```  
  
 Mas um delimitador resolve essa sintaxe:  
  
```cpp  
const char* good_parens = R"xyz()")xyz";  
```  
  
 Você pode construir uma literal de cadeia bruto em que há uma nova linha \(não o caractere de escape\) na origem:  
  
```cpp  
// represents the string: hello  
//goodbye  
const wchar_t* newline = LR"(hello  
goodbye)";  
```  
  
### STD literais \(C \+ \+ 14\)  
 STD literais são implementações de biblioteca padrão de definidas pelo usuário literais \(veja abaixo\) que são representados como "xyx" s \(com um `s` sufixo\). Esse tipo de cadeia de caracteres literal produz um objeto temporário do tipo STD, wstring, std::u32string ou std::u16string dependendo o prefixo especificado. Quando nenhum prefixo é usado, como acima, um STD é produzida. L "xyz" s produz um wstring. u "xyz" s produz uma [std::u16string](../Topic/u16string.md), e U "xyz" s gera um [std::u32string](../Topic/u32string.md).  
  
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
  
 STD literais são definidos no namespace `std::literals::string_literals` no arquivo de cabeçalho \< string \>. Como `std::literals::string_literals`, e `std::literals` são declaradas como [namespaces embutidos](../cpp/namespaces-cpp.md), `std::literals::string_literals` automaticamente é tratado como se ele pertencesse diretamente no namespace `std`.  
  
### Tamanho de literais de cadeia de caracteres  
 Para cadeias de caracteres char \* ANSI e outras codificações de byte único \(não UTF\-8\), o tamanho \(em bytes\) de um literal de cadeia de caracteres é o número de caracteres mais 1 para o caractere de terminação nula. Para todos os outros tipos de cadeia de caracteres, o tamanho não está estritamente relacionado ao número de caracteres. UTF\-8 usa até quatro elementos de char para codificar alguns *unidades de código*, e char16\_t ou wchar\_t codificado como UTF\-16 pode usar dois elementos \(para um total de quatro bytes\) para codificar um único *unidade de código*.   Este exemplo mostra o tamanho de uma cadeia de caracteres largo literal em bytes:  
  
```cpp  
const wchar_t* str = L"Hello!";  
const size_t byteSize = (wcslen(str) + 1) * sizeof(wchar_t);  
```  
  
 Observe que `strlen()` e `wcslen()` não incluem o tamanho do caractere de terminação nula, cujo tamanho é igual ao tamanho do elemento do tipo cadeia de caracteres: um byte em uma cadeia de caracteres char \*, dois bytes nas cadeias de wchar\_t \* ou char16\_t \* e quatro bytes em cadeias de caracteres char32\_t \*.  
  
 O comprimento máximo de um literal de cadeia de caracteres é 65535 bytes. Esse limite se aplica a literais de cadeia de caracteres estreita e literais de cadeia de caracteres larga.  
  
### Modificando literais de cadeia de caracteres  
 Como literais de cadeia de caracteres \(não incluindo literais std:string\) são constantes, tentar modificá\-los — por exemplo, str \[2\] \= 'A' — causa um erro do compilador.  
  
 **Específico da Microsoft**  
  
 No Visual C\+\+, você pode usar um literal de cadeia de caracteres para inicializar um ponteiro para não const `char` ou `wchar_t`. Isso é permitido no código C99, mas é preterido no C\+\+ 98 e removido no C\+\+ 11. Uma tentativa de modificar a cadeia de caracteres causa uma violação de acesso, como neste exemplo:  
  
```cpp  
wchar_t* str = L"hello";  
str[2] = L'a'; // run-time error: access violation  
```  
  
 Você pode fazer com que o compilador emita um erro quando um literal de cadeia de caracteres é convertida em um ponteiro de caractere non\_const ao definir o [\/Zc:strictStrings \(Desativar conversão de tipo literal de cadeia de caracteres\)](../build/reference/zc-strictstrings-disable-string-literal-type-conversion.md) opção de compilador. É recomendável para código portátil compatível com os padrões. Também é uma boa prática usar o `auto` palavra\-chave para declarar ponteiros inicializados por literais, a cadeia de caracteres porque é resolvida para o tipo correto \(const\). Por exemplo, este exemplo de código mostra uma tentativa de gravar uma cadeia de caracteres literal em tempo de compilação:  
  
```cpp  
auto str = L"hello";  
str[2] = L'a'; // C3892: you cannot assign to a variable that is const.  
```  
  
 Em alguns casos, os literais de cadeia de caracteres idêntica podem ser agrupadas para economizar espaço no arquivo executável. No pool de cadeia de caracteres literal, o compilador faz com que todas as referências a uma determinada cadeia de caracteres literal para apontar para o mesmo local na memória, em vez de cada referência apontar para uma instância separada da cadeia de caracteres literal. Para habilitar o pool de cadeia de caracteres, use o [\/GF](../Topic/-GF%20\(Eliminate%20Duplicate%20Strings\).md) opção de compilador.  
  
 **Fim de específico da Microsoft**  
  
### Concatenando literais de cadeia de caracteres adjacentes  
 Literais de cadeias de caracteres estreitos ou largos adjacentes são concatenadas. Esta declaração:  
  
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
  
 Usando códigos de escape hexadecimais inseridos para especificar literais de cadeia de caracteres pode causar resultados inesperados. O exemplo a seguir tenta criar uma cadeia de caracteres literal que contenha o caractere ASCII 5, seguido por caracteres "f", i, v e e:  
  
```cpp  
"\x05five"  
```  
  
 O resultado real é um 5F hexadecimal, que é o código ASCII de um sublinhado, seguido pelos caracteres i, v e e. Para Para obter o resultado correto, você pode usar uma destas opções:  
  
```cpp  
"\005five"     // Use octal literal.  
"\x05" "five"  // Use string splicing.  
```  
  
 literais de STD, porque eles são tipos STD, podem ser concatenados com o operador está definido para \+ [basic\_string](../standard-library/basic-string-class.md) tipos. Eles também podem ser concatenados da mesma forma como literais de cadeia de caracteres adjacentes. Em ambos os casos, a codificação de cadeia de caracteres e o sufixo devem corresponder:  
  
```cpp  
auto x1 = "hello" " " " world"; // OK  
auto x2 = U"hello" " " L"world"; // C2308: disagree on prefix  
auto x3 = u8"hello" " "s u8"world"s; // OK, agree on prefixes and suffixes  
auto x4 = u8"hello" " "s u8"world"z; // C3688, disagree on suffixes  
```  
  
### Literais de cadeia de caracteres com nomes de caracteres universais  
 Literais de cadeia de caracteres \(não processados\) nativo podem usar nomes de caracteres universais para representar qualquer caractere, como o nome de caracteres universais pode ser codificado como um ou mais caracteres no tipo de cadeia de caracteres.  Por exemplo, um nome universal de caracteres que representa um caractere estendido não pode ser codificado em uma cadeia de caracteres estreita usando a página de código ANSI, mas ela pode ser codificada em cadeias de caracteres estreitas em algumas páginas de código multibyte, em cadeias de caracteres UTF\-8 ou em uma cadeia de caracteres larga. No C\+\+ 11, suporte a Unicode é estendido, os tipos de cadeia de caracteres char16\_t \* e char32\_t \*:  
  
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
  
## Consulte também  
 [Conjuntos de caracteres](../cpp/character-sets2.md)   
 [Literais numéricas, boolianas e de ponteiro](../cpp/numeric-boolean-and-pointer-literals-cpp.md)   
 [Literais definidos pelo usuário](../Topic/User-Defined%20Literals%20%20\(C++\).md)