---
title: Cadeias de caracteres e literais de caracteres (C++)
description: Como declarar e definir cadeias de caracteres e literais C++de caracteres no.
ms.date: 02/18/2020
f1_keywords:
- R
- L
- u
- u8
- LR
- uR
- u8R
helpviewer_keywords:
- literal strings [C++]
- string literals [C++]
ms.assetid: 61de8f6f-2714-4e7b-86b6-a3f885d3b9df
ms.openlocfilehash: 1b4cfb8059b116b0d91886f5b78b3911e8dc316c
ms.sourcegitcommit: b9aaaebe6e7dc5a18fe26f73cc7cf5fce09262c1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/20/2020
ms.locfileid: "77504473"
---
# <a name="string-and-character-literals-c"></a>Cadeias de caracteres e literais de caracteres (C++)

C++dá suporte a vários tipos de cadeia de caracteres e de caracteres e fornece maneiras de expressar valores literais de cada um desses tipos. No código-fonte, você expressa o conteúdo do seu caractere e os literais de cadeia de caracteres usando um conjunto de caracteres. Os nomes de caracteres universais e os caracteres de escape permitem expressar qualquer cadeia de caracteres usando apenas o conjunto de caracteres de origem básico. Um literal de cadeia de caracteres bruta permite evitar o uso de caracteres de escape e pode ser usado para expressar todos os tipos de literais de cadeia de caracteres. Você também pode criar `std::string` literais sem precisar executar etapas adicionais de construção ou conversão.

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

    // Multicharacter literals
    auto m0 = 'abcd'; // int, value 0x61626364

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

Literais de cadeia de caracteres não podem ter nenhum prefixo, ou `u8`, `L`, `u`e prefixos `U` para denotar caracteres estreitos (de byte único ou múltiplos bytes), UTF-8, caracteres largos (UCS-2 ou UTF-16), UTF-16 e codificações UTF-32, respectivamente. Um literal de cadeia de caracteres bruta pode ter `R`, `u8R`, `LR`, `uR`e prefixos de `UR` para os equivalentes de versão bruto dessas codificações.  Para criar valores de `std::string` temporários ou estáticos, você pode usar literais de cadeia de caracteres ou literais de cadeia de caracteres brutos com um sufixo de `s`. Para obter mais informações, consulte a seção [literais de cadeia de caracteres](#string-literals) abaixo. Para obter mais informações sobre o conjunto de caracteres de origem básico, os nomes de caracteres universais e o uso de caracteres de páginas de código estendidas em seu código-fonte, consulte [conjuntos de caracteres](../cpp/character-sets.md).

## <a name="character-literals"></a>Literais de caracteres

Um *literal de caractere* é composto de um caractere constante. Ele é representado pelo caractere entre aspas simples. Há cinco tipos de literais de caracteres:

- Literais de caracteres comuns do tipo **Char**, por exemplo `'a'`

- Literais de caracteres UTF-8 do tipo **Char** (**char8_t** em c++ 20), por exemplo `u8'a'`

- Literais de caractere largo do tipo `wchar_t`, por exemplo `L'a'`

- Literais de caracteres UTF-16 do tipo `char16_t`, por exemplo `u'a'`

- Literais de caracteres UTF-32 do tipo `char32_t`, por exemplo `U'a'`

O caractere usado para um literal de caractere pode ser qualquer caractere, com exceção da barra invertida de caracteres reservados ('\\'), aspa simples (') ou nova linha. Os caracteres reservados podem ser especificados usando uma sequência de escape. Os caracteres podem ser especificados usando nomes de caracteres universais, desde que o tipo seja grande o suficiente para conter o caractere.

### <a name="encoding"></a>Codificação

Literais de caracteres são codificados de forma diferente com base em seu prefixo.

- Um literal de caractere sem um prefixo é um literal de caractere comum. O valor de um literal de caractere comum contendo um único caractere, sequência de escape ou nome de caractere universal que pode ser representado no conjunto de caracteres de execução tem um valor igual ao valor numérico de sua codificação no conjunto de caracteres de execução. Um literal de caractere comum que contém mais de um caractere, sequência de escape ou nome de caractere universal é um *literal de multicaractere*. Um literal de multicaractere ou um literal de caractere comum que não pode ser representado no conjunto de caracteres de execução tem o tipo **int**e seu valor é definido pela implementação. Para MSVC, consulte a seção **específica da Microsoft** abaixo.

- Um literal de caractere que começa com o prefixo de `L` é um literal de caractere largo. O valor de um literal de caractere largo contendo um único caractere, sequência de escape ou nome de caractere universal tem um valor igual ao valor numérico de sua codificação no conjunto de caracteres de execução largo, a menos que o literal de caractere não tenha nenhuma representação no execução de um conjunto de caracteres largo; nesse caso, o valor é definido pela implementação. O valor de um literal de caractere largo contendo vários caracteres, sequências de escape ou nomes de caracteres universais é definido pela implementação. Para MSVC, consulte a seção **específica da Microsoft** abaixo.

- Um literal de caractere que começa com o prefixo de `u8` é um literal de caractere UTF-8. O valor de um literal de caractere UTF-8 contendo um único caractere, sequência de escape ou nome de caractere universal tem um valor igual ao seu valor de ponto de código ISO 10646 se ele puder ser representado por uma única unidade de código UTF-8 (correspondente aos controles C0 e ao latim básico Bloco Unicode). Se o valor não puder ser representado por uma única unidade de código UTF-8, o programa será mal formado. Um literal de caractere UTF-8 contendo mais de um caractere, sequência de escape ou nome de caractere universal é mal formado.

- Um literal de caractere que começa com o prefixo de `u` é um literal de caractere UTF-16. O valor de um literal de caractere UTF-16 contendo um único caractere, sequência de escape ou nome de caractere universal tem um valor igual ao seu valor de ponto de código ISO 10646 se ele puder ser representado por uma única unidade de código UTF-16 (correspondente ao plano multilíngue básico ). Se o valor não puder ser representado por uma única unidade de código UTF-16, o programa será mal formado. Um literal de caractere UTF-16 contendo mais de um caractere, sequência de escape ou nome de caractere universal é mal formado.

- Um literal de caractere que começa com o prefixo de `U` é um literal de caractere UTF-32. O valor de um literal de caractere UTF-32 contendo um único caractere, sequência de escape ou nome de caractere universal tem um valor igual ao seu valor de ponto de código ISO 10646. Um literal de caractere UTF-32 contendo mais de um caractere, sequência de escape ou nome de caractere universal é mal formado.

### <a name="bkmk_Escape"></a>Sequências de escape

Há três tipos de sequências de escape: simples, octal e hexadecimal. Seqüências de escape podem ser qualquer um dos seguintes valores:

|Valor|Sequência de escape|
|-----------|---------------------|
| nova linha | \\n |
| barra invertida | \\\\ |
| tabulação horizontal | \\t |
| ponto de interrogação | ? ou \\? |
| tabulação vertical | \\v |
| aspas simples | \\' |
| backspace | \\b |
| aspas duplas | \\" |
| retorno de carro | \\r |
| o caractere nulo | \\0 |
| avanço de página | \\f |
| octal | \\OOO |
| alerta (Bell) | \\a |
| hexadecimal | \\xhhh |

Uma sequência de escape octal é uma barra invertida seguida por uma sequência de um a três dígitos octais. Uma sequência de escape octal termina no primeiro caractere que não seja um dígito octal, se encontrado antes do terceiro dígito. O valor octal mais alto possível é `\377`.

Uma sequência de escape hexadecimal é uma barra invertida seguida pelo caractere `x`, seguida por uma sequência de um ou mais dígitos hexadecimais. Os zeros à esquerda são ignorados. Em um literal de caractere U8 ou comum, o valor hexadecimal mais alto é 0xFF. Em um literal de caractere com prefixado L ou u-prefixado, o valor hexadecimal mais alto é 0xFFFF. Em um literal de caractere largo de U-prefixado, o valor hexadecimal mais alto é 0xFFFFFFFF.

Este código de exemplo mostra alguns exemplos de caracteres de escape usando literais de caractere comuns. A mesma sintaxe de sequência de escape é válida para os outros tipos de literal de caractere.

```cpp
#include <iostream>
using namespace std;

int main() {
    char newline = '\n';
    char tab = '\t';
    char backspace = '\b';
    char backslash = '\\';
    char nullChar = '\0';

    cout << "Newline character: " << newline << "ending" << endl;
    cout << "Tab character: " << tab << "ending" << endl;
    cout << "Backspace character: " << backspace << "ending" << endl;
    cout << "Backslash character: " << backslash << "ending" << endl;
    cout << "Null character: " << nullChar << "ending" << endl;
}
/* Output:
Newline character:
ending
Tab character:  ending
Backspace character:ending
Backslash character: \ending
Null character:  ending
*/
```

O caractere de barra invertida (\\) é um caractere de continuação de linha quando é colocado no final de uma linha. Se desejar que um caractere de barra invertida seja exibido como uma literal de caractere, você deve digitar duas barras invertidas em uma linha (`\\`). Para obter mais informações sobre o caractere de continuação de linha, consulte [fases de tradução](../preprocessor/phases-of-translation.md).

#### <a name="microsoft-specific"></a>Específico da Microsoft

Para criar um valor a partir de um literal de multicaractere estreito, o compilador converte o caractere ou a sequência de caracteres entre aspas simples em valores de 8 bits dentro de um inteiro de 32 bits. Vários caracteres no literal preenchem bytes correspondentes conforme necessário de ordem superior para ordem baixa. Em seguida, o compilador converte o inteiro para o tipo de destino seguindo as regras usuais. Por exemplo, para criar um valor **Char** , o compilador usa o byte de ordem inferior. Para criar um valor de **wchar_t** ou `char16_t`, o compilador usa a palavra de ordem inferior. O compilador avisa que o resultado será truncado se algum bit estiver definido acima do byte ou palavra atribuída.

```cpp
char c0    = 'abcd';    // C4305, C4309, truncates to 'd'
wchar_t w0 = 'abcd';    // C4305, C4309, truncates to '\x6364'
int i0     = 'abcd';    // 0x61626364
```

Uma sequência de escape octal que parece conter mais de três dígitos é tratada como uma sequência octal de 3 dígitos, seguida pelos dígitos subsequentes como caracteres em um literal de multicaractere, que pode fornecer resultados surpreendentes. Por exemplo:

```cpp
char c1 = '\100';   // '@'
char c2 = '\1000';  // C4305, C4309, truncates to '0'
```

As sequências de escape que parecem conter caracteres não octais são avaliadas como uma sequência octal até o último caractere octal, seguidos pelos caracteres restantes como os caracteres subsequentes em um literal de caractere. Aviso C4125 será gerado se o primeiro caractere não octal for um dígito decimal. Por exemplo:

```cpp
char c3 = '\009';   // '9'
char c4 = '\089';   // C4305, C4309, truncates to '9'
char c5 = '\qrs';   // C4129, C4305, C4309, truncates to 's'
```

Uma sequência de escape octal que tem um valor mais alto que `\377` causa um erro C2022: '*valor-em-decimal*': muito grande para o caractere.

Uma sequência de escape que parece ter caracteres hexadecimais e não hexadecimais é avaliada como um literal de multicaractere que contém uma sequência de escape hexadecimal até o último caractere hexadecimal, seguido pelos caracteres não hexadecimais. Uma sequência de escape hexadecimal que não contém dígitos hexadecimais causa o erro do compilador C2153: "literais hexadecimais devem ter pelo menos um dígito hexadecimal".

```cpp
char c6 = '\x0050'; // 'P'
char c7 = '\x0pqr'; // C4305, C4309, truncates to 'r'
```

Se um literal de caractere largo prefixado com `L` contiver uma sequência de multicaracteres, o valor será obtido do primeiro caractere e o compilador gerará o aviso C4066. Os caracteres subsequentes são ignorados, diferentemente do comportamento do literal multicaractere comum equivalente.

```cpp
wchar_t w1 = L'\100';   // L'@'
wchar_t w2 = L'\1000';  // C4066 L'@', 0 ignored
wchar_t w3 = L'\009';   // C4066 L'\0', 9 ignored
wchar_t w4 = L'\089';   // C4066 L'\0', 89 ignored
wchar_t w5 = L'\qrs';   // C4129, C4066 L'q' escape, rs ignored
wchar_t w6 = L'\x0050'; // L'P'
wchar_t w7 = L'\x0pqr'; // C4066 L'\0', pqr ignored
```

A seção **específica da Microsoft** termina aqui.

### <a name="bkmk_UCN"></a>Nomes de caracteres universais

Em literais de caracteres e literais de cadeia de caracteres nativos (não brutos), qualquer caractere pode ser representado por um nome de caractere universal.  Os nomes de caracteres universais são formados por um prefixo `\U` seguido por um ponto de código Unicode de oito dígitos ou por um prefixo `\u` seguido por um ponto de código Unicode de quatro dígitos. Todos os oito ou quatro dígitos, respectivamente, devem estar presentes para criar um nome de caractere universal bem formado.

```cpp
char u1 = 'A';          // 'A'
char u2 = '\101';       // octal, 'A'
char u3 = '\x41';       // hexadecimal, 'A'
char u4 = '\u0041';     // \u UCN 'A'
char u5 = '\U00000041'; // \U UCN 'A'
```

#### <a name="surrogate-pairs"></a>Pares substitutos

Os nomes de caracteres universais não podem codificar valores no intervalo de ponto de código substituto D800-DFFF. Para pares de substitutos Unicode, especifique o nome do caractere universal usando `\UNNNNNNNN`, em que NNNNNNNN é o ponto de código de oito dígitos para o caractere. O compilador gera um par substituto, se necessário.

No C++ 03, a linguagem permitia apenas um subconjunto de caracteres a ser representado por seus nomes de caracteres universais e permitia alguns nomes de caracteres universais que realmente não representaram nenhum caractere Unicode válido. Esse erro foi corrigido no padrão C++ 11. No C++ 11, os literais de caractere e de cadeia de caracteres e os identificadores podem usar nomes de caracteres universais.  Para obter mais informações sobre nomes de caracteres universais, consulte [conjuntos de caracteres](../cpp/character-sets.md). Para obter mais informações sobre Unicode, consulte [Unicode](/windows/win32/intl/unicode). Para obter mais informações sobre pares substitutos, consulte [pares substitutos e caracteres suplementares](/windows/win32/Intl/surrogates-and-supplementary-characters).

## <a name="string-literals"></a>Literais de cadeia de caracteres

Uma literal de cadeia de caracteres representa uma sequência de caracteres que, juntos, formam uma cadeia de caracteres terminada em nulo. Os caracteres devem ser incluídos entre aspas duplas. Existem os seguintes tipos de literais de cadeias de caracteres:

### <a name="narrow-string-literals"></a>Literais de cadeia de caracteres estreitas

Um literal de cadeia de caracteres estreito é uma matriz não prefixada, delimitada por aspas duplas e terminada em nulo do tipo `const char[n]`, em que n é o comprimento da matriz em bytes. Um literal de cadeia de caracteres estreito pode conter qualquer caractere gráfico, exceto aspas duplas (`"`), barra invertida (`\`) ou caractere de nova linha. Um literal de cadeia de caracteres estreito também pode conter as sequências de escape listadas acima e os nomes de caracteres universais que se ajustam em um byte.

```cpp
const char *narrow = "abcd";

// represents the string: yes\no
const char *escaped = "yes\\no";
```

#### <a name="utf-8-encoded-strings"></a>Cadeias de caracteres codificadas em UTF-8

Uma cadeia de caracteres codificada em UTF-8 é uma matriz U8, delimitada por aspas duplas e terminada em nulo do tipo `const char[n]`, em que *n* é o comprimento da matriz codificada em bytes. Um literal de cadeia de caracteres prefixado U8 pode conter qualquer caractere gráfico, exceto aspas duplas (`"`), barra invertida (`\`) ou caractere de nova linha. Um literal de cadeia de caracteres U8 também pode conter as sequências de escape listadas acima e qualquer nome de caractere universal.

```cpp
const char* str1 = u8"Hello World";
const char* str2 = u8"\U0001F607 is O:-)";
```

### <a name="wide-string-literals"></a>Literais de cadeia de caracteres largos

Um literal de cadeia de caracteres largo é uma matriz de constante terminada em nulo **wchar_t** que é prefixada por '`L`' e contém qualquer caractere gráfico, exceto aspas duplas ("), barra invertida (\\) ou caractere de nova linha. Um literal de cadeia de caracteres largo pode conter as sequências de escape listadas acima e qualquer nome de caractere universal.

```cpp
const wchar_t* wide = L"zyxw";
const wchar_t* newline = L"hello\ngoodbye";
```

#### <a name="char16_t-and-char32_t-c11"></a>char16_t e char32_t (C++ 11)

O c++ 11 apresenta os tipos de caracteres `char16_t` portáteis (Unicode de 16 bits) e `char32_t` (Unicode de 32 bits):

```cpp
auto s3 = u"hello"; // const char16_t*
auto s4 = U"hello"; // const char32_t*
```

### <a name="raw-string-literals-c11"></a>Literais de cadeia de caracteres brutas (C++ 11)

Um literal de cadeia de caracteres bruta é uma matriz com terminação nula, de qualquer tipo de caractere, que contém qualquer caractere gráfico, incluindo aspas duplas ("), barra invertida (\\) ou caractere de nova linha. As literais de cadeias de caracteres brutas costumam ser usadas em expressões regulares que utilizam classes de caracteres, bem como em cadeias de caracteres HTML e XML. Para obter exemplos, consulte o seguinte artigo: [perguntas frequentes sobre o Bjarne Stroustrup no c++ 11](http://www.stroustrup.com/C++11FAQ.html).

```cpp
// represents the string: An unescaped \ character
const char* raw_narrow = R"(An unescaped \ character)";
const wchar_t* raw_wide = LR"(An unescaped \ character)";
const char*       raw_utf8  = u8R"(An unescaped \ character)";
const char16_t* raw_utf16 = uR"(An unescaped \ character)";
const char32_t* raw_utf32 = UR"(An unescaped \ character)";
```

Um delimitador é uma sequência definida pelo usuário de até 16 caracteres que precede imediatamente o parêntese de abertura de um literal de cadeia de caracteres bruta e imediatamente segue o parêntese de fechamento.  Por exemplo, em `R"abc(Hello"\()abc"` a sequência de delimitador é `abc` e o conteúdo da cadeia de caracteres é `Hello"\(`. Você pode usar um delimitador para eliminar a ambiguidade de cadeias de caracteres brutas que contenham aspas duplas e parênteses. Esse literal de cadeia de caracteres causa um erro de compilador:

```cpp
// meant to represent the string: )"
const char* bad_parens = R"()")";  // error C2059
```

Mas um delimitador resolve essa sintaxe:

```cpp
const char* good_parens = R"xyz()")xyz";
```

Você pode construir um literal de cadeia de caracteres bruta que contenha uma nova linha (não o caractere de escape) na fonte:

```cpp
// represents the string: hello
//goodbye
const wchar_t* newline = LR"(hello
goodbye)";
```

### <a name="stdstring-literals-c14"></a>literais std:: String (C++ 14)

`std::string` literais são implementações de biblioteca padrão de literais definidos pelo usuário (veja abaixo) que são representadas como `"xyz"s` (com um sufixo `s`). Esse tipo de literal de cadeia de caracteres produz um objeto temporário do tipo `std::string`, `std::wstring`, `std::u32string`ou `std::u16string`, dependendo do prefixo especificado. Quando nenhum prefixo é usado, como acima, um `std::string` é produzido. `L"xyz"s` produz um `std::wstring`. `u"xyz"s` produz um [std:: u16string](../standard-library/string-typedefs.md#u16string)e `U"xyz"s` produz um [std:: u32string](../standard-library/string-typedefs.md#u32string).

```cpp
//#include <string>
//using namespace std::string_literals;
string str{ "hello"s };
string str2{ u8"Hello World" };
wstring str3{ L"hello"s };
u16string str4{ u"hello"s };
u32string str5{ U"hello"s };
```

O sufixo de `s` também pode ser usado em literais de cadeia de caracteres brutas:

```cpp
u32string str6{ UR"(She said "hello.")"s };
```

`std::string` literais são definidas no namespace `std::literals::string_literals` no arquivo de cabeçalho > de cadeia de caracteres \<. Como `std::literals::string_literals`e `std::literals` são declarados como [namespaces embutidos](../cpp/namespaces-cpp.md), `std::literals::string_literals` é tratado automaticamente como se ele pertencia diretamente no namespace `std`.

### <a name="size-of-string-literals"></a>Tamanho de literais de cadeia de caracteres

Para cadeias de caracteres ANSI `char*` e outras codificações de byte único (mas não UTF-8), o tamanho (em bytes) de um literal de cadeia de caracteres é o número de caracteres mais 1 para o caractere nulo de terminação. Para todos os outros tipos de cadeia de caracteres, o tamanho não é estritamente relacionado ao número de caracteres. O UTF-8 usa até quatro elementos **Char** para codificar algumas *unidades de código*, e `char16_t` ou `wchar_t` codificados como UTF-16 podem usar dois elementos (para um total de quatro bytes) para codificar uma única *unidade de código*. Este exemplo mostra o tamanho de um literal de cadeia de caracteres largo em bytes:

```cpp
const wchar_t* str = L"Hello!";
const size_t byteSize = (wcslen(str) + 1) * sizeof(wchar_t);
```

Observe que `strlen()` e `wcslen()` não incluem o tamanho do caractere nulo de terminação, cujo tamanho é igual ao tamanho do elemento do tipo de cadeia de caracteres: um byte em uma `char*` ou `char8_t*` cadeia de caracteres, dois bytes nas cadeias de `wchar_t*` ou `char16_t*` e quatro bytes em cadeias de `char32_t*`.

O comprimento máximo de um literal de cadeia de caracteres é 65.535 bytes. Esse limite se aplica às literais de cadeias de caracteres estreitas e largas.

### <a name="modifying-string-literals"></a>Modificando literais de cadeia de caracteres

Como literais de cadeia de caracteres (sem incluir `std::string` literais) são constantes, tentar modificá-las — por exemplo, `str[2] = 'A'`— causa um erro do compilador.

#### <a name="microsoft-specific"></a>Específico da Microsoft

Na Microsoft C++, você pode usar um literal de cadeia de caracteres para inicializar um ponteiro para **caracteres** não const ou **wchar_t**. Essa inicialização não const é permitida no código C99, mas é preterida no C++ 98 e removida no C++ 11. Uma tentativa de modificar a cadeia de caracteres causa uma violação de acesso, como neste exemplo:

```cpp
wchar_t* str = L"hello";
str[2] = L'a'; // run-time error: access violation
```

Você pode fazer com que o compilador emita um erro quando um literal de cadeia de caracteres é convertido em um ponteiro de caractere não const quando você define a opção de compilador [/Zc: strictStrings (desabilitar conversão de tipo literal de cadeia de caracteres)](../build/reference/zc-strictstrings-disable-string-literal-type-conversion.md) . É recomendável para código portátil compatível com padrões. Também é uma boa prática usar a palavra-chave **auto** para declarar ponteiros inicializados literais de cadeia de caracteres, pois ele resolve para o tipo correto (const). Por exemplo, este exemplo de código captura uma tentativa de gravar em um literal de cadeia de caracteres em tempo de compilação:

```cpp
auto str = L"hello";
str[2] = L'a'; // C3892: you cannot assign to a variable that is const.
```

Em alguns casos, literais de cadeias de caracteres idênticas podem ser agrupadas para economizar espaço no arquivo executável. Em pools de literais de cadeias de caracteres, o compilador faz com que todas as referências a uma literal de cadeia de caracteres específica apontem para o mesmo local na memória, em vez de cada referência apontar para uma instância separada da literal. Para habilitar o pool de cadeias de caracteres, use a opção de compilador [/GF](../build/reference/gf-eliminate-duplicate-strings.md) .

A seção **específica da Microsoft** termina aqui.

### <a name="concatenating-adjacent-string-literals"></a>Concatenando literais de cadeias de caracteres adjacentes

Literais de cadeia de caracteres adjacentes ou estreitos são concatenados. Esta declaração:

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

O uso de códigos de escape hexadecimais incorporados para especificar literais de cadeia de caracteres pode causar resultados inesperados. O exemplo a seguir visa criar uma literal de cadeia de caracteres que contenha o caractere ASCII 5, seguido pelos caracteres "f", "i", "v" e "e":

```cpp
"\x05five"
```

O resultado real é um 5F hexadecimal, que é o código ASCII de um sublinhado, seguido pelos caracteres i, v e e. Para obter o resultado correto, você pode usar uma destas sequências de escape:

```cpp
"\005five"     // Use octal literal.
"\x05" "five"  // Use string splicing.
```

`std::string` literais, porque são `std::string` tipos, podem ser concatenados com o operador de `+` que é definido para [basic_string](../standard-library/basic-string-class.md) tipos. Eles também podem ser concatenados da mesma maneira que os literais de cadeia de caracteres adjacentes. Em ambos os casos, a codificação de cadeia de caracteres e o sufixo devem corresponder:

```cpp
auto x1 = "hello" " " " world"; // OK
auto x2 = U"hello" " " L"world"; // C2308: disagree on prefix
auto x3 = u8"hello" " "s u8"world"s; // OK, agree on prefixes and suffixes
auto x4 = u8"hello" " "s u8"world"z; // C3688, disagree on suffixes
```

### <a name="string-literals-with-universal-character-names"></a>Literais de cadeia de caracteres com nomes de caracteres universais

Literais de cadeia de caracteres nativos (não brutos) podem usar nomes de caracteres universais para representar qualquer caractere, desde que o nome do caractere universal possa ser codificado como um ou mais caracteres no tipo de cadeia de caracteres.  Por exemplo, um nome de caractere universal representando um caractere estendido não pode ser codificado em uma cadeia de caracteres estreita usando a página de código ANSI, mas pode ser codificado em cadeias estreitas em algumas páginas de código de vários bytes, ou em cadeias de caracteres UTF-8, ou em uma cadeia extensa. No C++ 11, o suporte a Unicode é estendido pelos tipos de cadeia de caracteres `char16_t*` e `char32_t*`:

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

## <a name="see-also"></a>Confira também

[Conjuntos de caracteres](../cpp/character-sets.md)\
[Literais numéricos, Boolianos e de ponteiro](../cpp/numeric-boolean-and-pointer-literals-cpp.md)\
[Literais definidos pelo usuário](../cpp/user-defined-literals-cpp.md)
