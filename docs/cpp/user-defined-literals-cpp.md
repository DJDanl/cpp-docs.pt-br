---
title: Literais (C++) definido pelo usuário | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-language
ms.tgt_pltfrm: ''
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: ff4a5bec-f795-4705-a2c0-53788fd57609
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a461f4ca384585008ccf47fa2bfda91d36e724ab
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="user-defined-literals--c"></a>Literais definidos pelo usuário (C++)
Há cinco categorias principais de literais: inteiro, cadeia de caracteres, ponto flutuante, boolean e ponteiro.  Começando no C++ 11, você pode definir seus próprios literais com base nessas categorias para fornecer os atalhos sintáticos para linguagens comuns e aumentar a segurança de tipo. Por exemplo, digamos que você tem uma classe de distância. Você pode definir um valor literal para quilômetros e outra para milhas e estimular o usuário a ser explícito sobre as unidades de medida, simplesmente escrevendo: auto d = d 42.0_km ou auto = 42.0_mi. Não há nenhuma vantagem de desempenho ou desvantagem literais definidos pelo usuário; eles são principalmente para conveniência ou para dedução de tipo de tempo de compilação. A biblioteca padrão tem literais definidos pelo usuário para std:string, std::complex e unidades em operações de tempo e a duração no \<chrono > cabeçalho:  
  
```  
Distance d = 36.0_mi + 42.0_km;         // Custom UDL (see below)  
    std::string str = "hello"s + "World"s;  // Standard Library <string> UDL  
    complex<double> num =   
        (2.0 + 3.01i) * (5.0 + 4.3i);       // Standard Library <complex> UDL  
    auto duration = 15ms + 42h;             // Standard Library <chrono> UDLs  
```  
  
## <a name="user-defined-literal-operator-signatures"></a>Assinaturas de operador literal definido pelo usuário  
 Implementar um literal definido pelo usuário definindo um `operator""` no escopo do namespace com uma das seguintes formas:  
  
```  
ReturnType operator "" _a(unsigned long long int);   // Literal operator for user-defined INTEGRAL literal  
ReturnType operator "" _b(long double);              // Literal operator for user-defined FLOATING literal  
ReturnType operator "" _c(char);                     // Literal operator for user-defined CHARACTER literal  
ReturnType operator "" _d(wchar_t);                  // Literal operator for user-defined CHARACTER literal  
ReturnType operator "" _e(char16_t);                 // Literal operator for user-defined CHARACTER literal  
ReturnType operator "" _f(char32_t);                 // Literal operator for user-defined CHARACTER literal  
ReturnType operator "" _g(const     char*, size_t);  // Literal operator for user-defined STRING literal  
ReturnType operator "" _h(const  wchar_t*, size_t);  // Literal operator for user-defined STRING literal  
ReturnType operator "" _i(const char16_t*, size_t);  // Literal operator for user-defined STRING literal  
ReturnType operator "" _g(const char32_t*, size_t);  // Literal operator for user-defined STRING literal  
ReturnType operator "" _r(const char*);              // Raw literal operator  
template<char...> ReturnType operator "" _t();       // Literal operator template  
```  
  
 Os nomes de operador no exemplo anterior são espaços reservados para o nome que você fornecer; No entanto, o sublinhado à esquerda é necessário. (Somente a biblioteca padrão é permitida definir literais sem o caractere de sublinhado). O tipo de retorno é onde você personaliza a conversão ou outra operação que executa o literal. Além disso, qualquer um destes operadores podem ser definidos como `constexpr`.  
  
## <a name="cooked-literals"></a>Literais cooked  
 Na fonte de código qualquer literal definido pelo usuário ou não é essencialmente uma sequência de caracteres alfanuméricos, como `101`, ou `54.7`, ou `"hello"` ou `true`. O compilador interpreta a sequência como um inteiro, float, char const\* cadeia de caracteres e assim por diante. Um literal definido pelo usuário que aceita como entrada qualquer tipo de compilador atribuído ao valor literal informalmente é conhecido como um *literal cooked*. Todos os operadores acima exceto `_r` e `_t` são algo literais. Por exemplo, um literal `42.0_km` deve vincular a um operador chamado _km que tinha uma assinatura semelhante a _b e o literal `42_km` deve vincular a um operador com uma assinatura semelhante a _a.  
  
 O exemplo a seguir mostra como definido pelo usuário literais pode encorajar os chamadores para ser explícito sobre sua entrada. Para construir um `Distance`, o usuário deve especificar explicitamente quilômetros ou milhas usando apropriado literal definido pelo usuário. Obviamente você também pode obter o mesmo resultado de outras maneiras, mas literais definidos pelo usuário são menos detalhadas que as alternativas.  
  
```  
struct Distance  
{  
private:  
    explicit Distance(long double val) : kilometers(val)  
    {}  
  
    friend Distance operator"" _km(long double  val);  
    friend Distance operator"" _mi(long double val);  
    long double kilometers{ 0 };  
public:  
    long double get_kilometers() { return kilometers; }  
    Distance operator+(Distance& other)  
    {  
        return Distance(get_kilometers() + other.get_kilometers());  
    }  
};  
  
Distance operator"" _km(long double  val)  
{  
    return Distance(val);  
}  
  
Distance operator"" _mi(long double val)  
{  
    return Distance(val * 1.6);  
}  
int main(int argc, char* argv[])  
{  
    // Must have a decimal point to bind to the operator we defined!  
    Distance d{ 402.0_km }; // construct using kilometers  
    cout << "Kilometers in d: " << d.get_kilometers() << endl; // 402  
  
    Distance d2{ 402.0_mi }; // construct using miles  
    cout << "Kilometers in d2: " << d2.get_kilometers() << endl;  //643.2  
  
    // add distances constructed with different units  
    Distance d3 = 36.0_mi + 42.0_km;  
    cout << "d3 value = " << d3.get_kilometers() << endl; // 99.6  
  
   // Distance d4(90.0); // error constructor not accessible  
  
    string s;  
    getline(cin, s);  
    return 0;  
}  
```  
  
 Observe que o número de literal deve usar um número decimal, caso contrário, o número será interpretado como um número inteiro e o tipo não seria compatível com o operador. Observe também que, para entrada de ponto flutuante, o tipo deve ser `long double`e para tipos integrais deve ser `long long`.  
  
## <a name="raw-literals"></a>Literais brutos  
 Em um literal bruto definida pelo usuário, o operador que você definir aceita o literal como uma sequência de valores char e cabe a você interpretar essa sequência como um número ou cadeia de caracteres ou outro tipo. Na lista de operadores mostrado anteriormente nesta página, `_r` e `_t` podem ser usadas para definir brutos literais:  
  
```  
ReturnType operator "" _r(const char*);              // Raw literal operator  
template<char...> ReturnType operator "" _t();       // Literal operator template  
```  
  
 Você pode usar literais brutos para fornecer uma interpretação personalizada de uma sequência de entrada que é diferente do que o compilador deve executar. Por exemplo, você pode definir um literal que converte a sequência `4.75987` em um tipo Decimal personalizado em vez de um IEEE 754 flutuante tipo de ponto. Literais brutos, como algo literais, também pode ser usado para executar a validação de tempo de compilação de sequências de entrada.  
  
### <a name="example"></a>Exemplo  
  
### <a name="limitations-of-raw-literals"></a>Limitações de literais brutos  
 O operador literal bruto e o modelo de operador literal só funcionam para literais definidos pelo usuário integrais e de ponto flutuantes, conforme mostrado pelo exemplo a seguir:  
  
```  
#include <cstddef>  
#include <cstdio>  
  
void operator "" _dump(unsigned long long int lit)  { printf("operator \"\" _dump(unsigned long long int) : ===>%llu<===\n", lit); };  // Literal operator for user-defined INTEGRAL literal  
void operator "" _dump(long double lit)             { printf("operator \"\" _dump(long double)            : ===>%Lf<===\n",  lit); };  // Literal operator for user-defined FLOATING literal  
void operator "" _dump(char lit)                    { printf("operator \"\" _dump(char)                   : ===>%c<===\n",   lit); };  // Literal operator for user-defined CHARACTER literal  
void operator "" _dump(wchar_t lit)                 { printf("operator \"\" _dump(wchar_t)                : ===>%d<===\n",   lit); };  // Literal operator for user-defined CHARACTER literal  
void operator "" _dump(char16_t lit)                { printf("operator \"\" _dump(char16_t)               : ===>%d<===\n",   lit); };  // Literal operator for user-defined CHARACTER literal  
void operator "" _dump(char32_t lit)                { printf("operator \"\" _dump(char32_t)               : ===>%d<===\n",   lit); };  // Literal operator for user-defined CHARACTER literal  
void operator "" _dump(const     char* lit, size_t) { printf("operator \"\" _dump(const     char*, size_t): ===>%s<===\n",   lit); };  // Literal operator for user-defined STRING literal  
void operator "" _dump(const  wchar_t* lit, size_t) { printf("operator \"\" _dump(const  wchar_t*, size_t): ===>%ls<===\n",  lit); };  // Literal operator for user-defined STRING literal  
void operator "" _dump(const char16_t* lit, size_t) { printf("operator \"\" _dump(const char16_t*, size_t):\n"                  ); };  // Literal operator for user-defined STRING literal  
void operator "" _dump(const char32_t* lit, size_t) { printf("operator \"\" _dump(const char32_t*, size_t):\n"                  ); };  // Literal operator for user-defined STRING literal  
void operator "" _dump_raw(const char* lit)         { printf("operator \"\" _dump_raw(const char*)        : ===>%s<===\n",   lit); };  // Raw literal operator  
  
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
    // 'A'_dump_raw;               // There is no raw literal operator or literal operator template support on this type  
    //L'B'_dump_raw;              // There is no raw literal operator or literal operator template support on this type  
    //u'C'_dump_raw;              // There is no raw literal operator or literal operator template support on this type  
    //U'D'_dump_raw;              // There is no raw literal operator or literal operator template support on this type  
    //  "Hello World"_dump_raw;   // There is no raw literal operator or literal operator template support on this type  
    // L"Wide String"_dump_raw;   // There is no raw literal operator or literal operator template support on this type  
    //u8"UTF-8 String"_dump_raw;   // There is no raw literal operator or literal operator template support on this type  
    // u"UTF-16 String"_dump_raw;  // There is no raw literal operator or literal operator template support on this type  
    // U"UTF-32 String"_dump_raw;  // There is no raw literal operator or literal operator template support on this type  
}  
/*****  
Output:  
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
*****/  
  
```