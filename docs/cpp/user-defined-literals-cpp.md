---
title: Literais definidos pelo usuário (C++)
description: Descreve a finalidade e o uso de literais definidos pelo usuário no C++Standard.
ms.date: 02/10/2020
ms.assetid: ff4a5bec-f795-4705-a2c0-53788fd57609
ms.openlocfilehash: a6636be414fa4dc199ce10fca1b33f092492575f
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2020
ms.locfileid: "79090561"
---
# <a name="user-defined-literals"></a>Literais definidos pelo usuário

Há seis categorias principais de literais em C++: inteiro, caractere, ponto flutuante, Cadeia de caracteres, booliano e ponteiro. A partir C++ de 11, você pode definir seus próprios literais com base nessas categorias, para fornecer atalhos sintáticos para linguagens comuns e aumentar a segurança do tipo. Por exemplo, digamos que você tenha uma classe de `Distance`. Você pode definir um literal para quilômetros e outro para milhas e encorajar o usuário a ser explícito sobre as unidades de medida escrevendo: `auto d = 42.0_km` ou `auto d = 42.0_mi`. Não há vantagem de desempenho ou desvantagem de literais definidos pelo usuário; Eles são principalmente para conveniência ou para dedução de tipo em tempo de compilação. A biblioteca padrão tem literais definidos pelo usuário para `std::string`, para `std::complex`e para unidades nas operações de tempo e duração no cabeçalho \<Chrono >:

```cpp
Distance d = 36.0_mi + 42.0_km;         // Custom UDL (see below)
std::string str = "hello"s + "World"s;  // Standard Library <string> UDL
complex<double> num =
   (2.0 + 3.01i) * (5.0 + 4.3i);        // Standard Library <complex> UDL
auto duration = 15ms + 42h;             // Standard Library <chrono> UDLs
```

## <a name="user-defined-literal-operator-signatures"></a>Assinaturas de operador literal definidas pelo usuário

Você implementa um literal definido pelo usuário definindo um **operador ""** no escopo de namespace com um dos seguintes formulários:

```cpp
ReturnType operator "" _a(unsigned long long int);   // Literal operator for user-defined INTEGRAL literal
ReturnType operator "" _b(long double);              // Literal operator for user-defined FLOATING literal
ReturnType operator "" _c(char);                     // Literal operator for user-defined CHARACTER literal
ReturnType operator "" _d(wchar_t);                  // Literal operator for user-defined CHARACTER literal
ReturnType operator "" _e(char16_t);                 // Literal operator for user-defined CHARACTER literal
ReturnType operator "" _f(char32_t);                 // Literal operator for user-defined CHARACTER literal
ReturnType operator "" _g(const char*, size_t);      // Literal operator for user-defined STRING literal
ReturnType operator "" _h(const wchar_t*, size_t);   // Literal operator for user-defined STRING literal
ReturnType operator "" _i(const char16_t*, size_t);  // Literal operator for user-defined STRING literal
ReturnType operator "" _g(const char32_t*, size_t);  // Literal operator for user-defined STRING literal
ReturnType operator "" _r(const char*);              // Raw literal operator
template<char...> ReturnType operator "" _t();       // Literal operator template
```

Os nomes de operador no exemplo anterior são espaços reservados para qualquer nome que você fornecer; no entanto, o sublinhado à esquerda é necessário. (Somente a biblioteca padrão tem permissão para definir literais sem o sublinhado.) O tipo de retorno é onde você personaliza a conversão ou outras operações feitas pelo literal. Além disso, qualquer um desses operadores pode ser definido como `constexpr`.

## <a name="cooked-literals"></a>Literais cooked

No código-fonte, qualquer literal, seja definido pelo usuário ou não, é essencialmente uma sequência de caracteres alfanuméricos, como `101`, ou `54.7`, ou `"hello"` ou `true`. O compilador interpreta a sequência como um inteiro, float, const char\* cadeia de caracteres e assim por diante. Um literal definido pelo usuário que aceita como entrada, qualquer tipo que o compilador atribuído ao valor literal é informalmente conhecido como um *literal cooked*. Todos os operadores acima, exceto `_r` e `_t`, são literais cooked. Por exemplo, um `42.0_km` literal seria associado a um operador chamado _km que tinha uma assinatura semelhante a _b e o `42_km` literal seria associado a um operador com uma assinatura semelhante a _a.

O exemplo a seguir mostra como os literais definidos pelo usuário podem encorajar os chamadores a serem explícitos sobre sua entrada. Para construir um `Distance`, o usuário deve especificar explicitamente quilômetros ou milhas usando o literal definido pelo usuário apropriado. Você pode obter o mesmo resultado de outras maneiras, mas os literais definidos pelo usuário são menos detalhados do que as alternativas.

```cpp
// UDL_Distance.cpp

#include <iostream>
#include <string>

struct Distance
{
private:
    explicit Distance(long double val) : kilometers(val)
    {}

    friend Distance operator"" _km(long double val);
    friend Distance operator"" _mi(long double val);

    long double kilometers{ 0 };
public:
    const static long double km_per_mile;
    long double get_kilometers() { return kilometers; }

    Distance operator+(Distance other)
    {
        return Distance(get_kilometers() + other.get_kilometers());
    }
};

const long double Distance::km_per_mile = 1.609344L;

Distance operator"" _km(long double val)
{
    return Distance(val);
}

Distance operator"" _mi(long double val)
{
    return Distance(val * Distance::km_per_mile);
}

int main()
{
    // Must have a decimal point to bind to the operator we defined!
    Distance d{ 402.0_km }; // construct using kilometers
    std::cout << "Kilometers in d: " << d.get_kilometers() << std::endl; // 402

    Distance d2{ 402.0_mi }; // construct using miles
    std::cout << "Kilometers in d2: " << d2.get_kilometers() << std::endl;  //646.956

    // add distances constructed with different units
    Distance d3 = 36.0_mi + 42.0_km;
    std::cout << "d3 value = " << d3.get_kilometers() << std::endl; // 99.9364

    // Distance d4(90.0); // error constructor not accessible

    std::string s;
    std::getline(std::cin, s);
    return 0;
}
```

O número literal deve usar um decimal. Caso contrário, o número seria interpretado como um inteiro e o tipo não seria compatível com o operador. Para entrada de ponto flutuante, o tipo deve ser **longo Duplo**e para tipos integrais, ele deve ser **longo**demais.

## <a name="raw-literals"></a>Literais brutos

Em um literal definido pelo usuário bruto, o operador que você define aceita o literal como uma sequência de valores char. Cabe a você interpretar essa sequência como um número ou uma cadeia de caracteres ou outro tipo. Na lista de operadores mostrados anteriormente nesta página, `_r` e `_t` podem ser usados para definir literais brutos:

```cpp
ReturnType operator "" _r(const char*);              // Raw literal operator
template<char...> ReturnType operator "" _t();       // Literal operator template
```

Você pode usar literais brutos para fornecer uma interpretação personalizada de uma sequência de entrada diferente do comportamento normal do compilador. Por exemplo, você pode definir um literal que converta a sequência `4.75987` em um tipo decimal personalizado em vez de um tipo de ponto flutuante de IEEE 754. Literais brutos, como literais cooked, também podem ser usados para a validação de tempo de compilação de sequências de entrada.

### <a name="example-limitations-of-raw-literals"></a>Exemplo: limitações de literais brutos

O operador literal bruto e o modelo de operador literal só funcionam para literais inteiros e de ponto flutuante definidos pelo usuário, conforme mostrado no exemplo a seguir:

```cpp
#include <cstddef>
#include <cstdio>

// Literal operator for user-defined INTEGRAL literal
void operator "" _dump(unsigned long long int lit)
{
    printf("operator \"\" _dump(unsigned long long int) : ===>%llu<===\n", lit);
};

// Literal operator for user-defined FLOATING literal
void operator "" _dump(long double lit)
{
    printf("operator \"\" _dump(long double)            : ===>%Lf<===\n",  lit);
};

// Literal operator for user-defined CHARACTER literal
void operator "" _dump(char lit)
{
    printf("operator \"\" _dump(char)                   : ===>%c<===\n",   lit);
};

void operator "" _dump(wchar_t lit)
{
    printf("operator \"\" _dump(wchar_t)                : ===>%d<===\n",   lit);
};

void operator "" _dump(char16_t lit)
{
    printf("operator \"\" _dump(char16_t)               : ===>%d<===\n",   lit);
};

void operator "" _dump(char32_t lit)
{
    printf("operator \"\" _dump(char32_t)               : ===>%d<===\n",   lit);
};

// Literal operator for user-defined STRING literal
void operator "" _dump(const     char* lit, size_t)
{
    printf("operator \"\" _dump(const     char*, size_t): ===>%s<===\n",   lit);
};

void operator "" _dump(const  wchar_t* lit, size_t)
{
    printf("operator \"\" _dump(const  wchar_t*, size_t): ===>%ls<===\n",  lit);
};

void operator "" _dump(const char16_t* lit, size_t)
{
    printf("operator \"\" _dump(const char16_t*, size_t):\n"                  );
};

void operator "" _dump(const char32_t* lit, size_t)
{
    printf("operator \"\" _dump(const char32_t*, size_t):\n"                  );
};

// Raw literal operator
void operator "" _dump_raw(const char* lit)
{
    printf("operator \"\" _dump_raw(const char*)        : ===>%s<===\n",   lit);
};

template<char...> void operator "" _dump_template();       // Literal operator template

int main(int argc, const char* argv[])
{
    42_dump;
    3.1415926_dump;
    3.14e+25_dump;
     'A'_dump;
    L'B'_dump;
    u'C'_dump;
    U'D'_dump;
      "Hello World"_dump;
     L"Wide String"_dump;
    u8"UTF-8 String"_dump;
     u"UTF-16 String"_dump;
     U"UTF-32 String"_dump;
    42_dump_raw;
    3.1415926_dump_raw;
    3.14e+25_dump_raw;

    // There is no raw literal operator or literal operator template support on these types:
    //  'A'_dump_raw;
    // L'B'_dump_raw;
    // u'C'_dump_raw;
    // U'D'_dump_raw;
    //   "Hello World"_dump_raw;
    //  L"Wide String"_dump_raw;
    // u8"UTF-8 String"_dump_raw;
    //  u"UTF-16 String"_dump_raw;
    //  U"UTF-32 String"_dump_raw;
}
```

```Output
operator "" _dump(unsigned long long int) : ===>42<===
operator "" _dump(long double)            : ===>3.141593<===
operator "" _dump(long double)            : ===>31399999999999998506827776.000000<===
operator "" _dump(char)                   : ===>A<===
operator "" _dump(wchar_t)                : ===>66<===
operator "" _dump(char16_t)               : ===>67<===
operator "" _dump(char32_t)               : ===>68<===
operator "" _dump(const     char*, size_t): ===>Hello World<===
operator "" _dump(const  wchar_t*, size_t): ===>Wide String<===
operator "" _dump(const     char*, size_t): ===>UTF-8 String<===
operator "" _dump(const char16_t*, size_t):
operator "" _dump(const char32_t*, size_t):
operator "" _dump_raw(const char*)        : ===>42<===
operator "" _dump_raw(const char*)        : ===>3.1415926<===
operator "" _dump_raw(const char*)        : ===>3.14e+25<===
```
