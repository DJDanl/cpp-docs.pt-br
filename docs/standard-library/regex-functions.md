---
title: "Funções &lt;regex&gt; | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- regex/std::regex_match
- regex/std::regex_replace
- regex/std::regex_search
- regex/std::swap
dev_langs: C++
ms.assetid: 91a8314b-6f7c-4e33-b7d6-d8583dd75585
caps.latest.revision: "12"
manager: ghogen
helpviewer_keywords:
- std::regex_match [C++]
- std::regex_replace [C++]
- std::regex_search [C++]
- std::swap [C++]
- std::swap [C++]
ms.openlocfilehash: f9ac58b6022d1497f0f06ff08edd29f2e012000f
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="ltregexgt-functions"></a>Funções &lt;regex&gt;
||||  
|-|-|-|  
|[regex_match](#regex_match)|[regex_replace](#regex_replace)|[regex_search](#regex_search)|  
|[swap](#swap)|  
  
##  <a name="regex_match"></a>regex_match
 Testa se uma expressão regular corresponde a toda a cadeia de caracteres de destino.  
  
```  
 
// (1)   
template <class BidIt, class Alloc, class Elem, class RXtraits, class Alloc2>  
bool regex_match(
    BidIt first, 
    Bidit last,  
    match_results<BidIt, Alloc>& match,  
    const basic_regex<Elem, RXtraits, Alloc2>& re,   
    match_flag_type flags = match_default);

 
// (2)   
template <class BidIt, class Elem, class RXtraits, class Alloc2>  
bool regex_match(
    BidIt first, 
    Bidit last,  
    const basic_regex<Elem, RXtraits, Alloc2>& re,  
    match_flag_type flags = match_default);

 
// (3)  
template <class Elem, class Alloc, class RXtraits, class Alloc2>  
bool regex_match(
    const Elem *ptr,  
    match_results<const Elem*, Alloc>& match,  
    const basic_regex<Elem, RXtraits, Alloc2>& re,  
    match_flag_type flags = match_default);

 
// (4)   
template <class Elem, class RXtraits, class Alloc2>  
bool regex_match(
    const Elem *ptr,  
    const basic_regex<Elem, RXtraits, Alloc2>& re,  
    match_flag_type flags = match_default);

 
// (5)  
template <class IOtraits, class IOalloc, class Alloc, class Elem, class RXtraits, class Alloc2>  
bool regex_match(
    const basic_string<Elem, IOtraits, IOalloc>& str,  
    match_results<typename basic_string<Elem, IOtraits, IOalloc>::const_iterator, Alloc>& match,  
    const basic_regex<Elem, RXtraits, Alloc2>& re, 
    match_flag_type flags = match_default);
 
// (6)  
template <class IOtraits, class IOalloc, class Elem, class RXtraits, class Alloc2>  
bool regex_match(
    const basic_string<Elem, IOtraits, IOalloc>& str,  
    const basic_regex<Elem, RXtraits, Alloc2>& re,  
    match_flag_type flags = match_default);
```  
  
### <a name="parameters"></a>Parâmetros  
 `BidIt`  
 O tipo de iterador para subcorrespondências. Para casos comuns, isso é um dos string::const_iterator, wstring::const_iterator, const char* ou const wchar_t\*.  
  
 `Alloc`  
 A classe alocadora de resultados de correspondência.  
  
 `Elem`  
 O tipo de elemento a ser correspondido. Para casos comuns, será string, wstring, char* ou wchar_t\*.  
  
 `RXtraits`  
 Classe de características para elementos.  
  
 `Alloc2`  
 A classe alocadora de expressão regular.  
  
 `IOtraits`  
 A classe de característica da cadeia de caracteres.  
  
 `IOalloc`  
 A classe alocadora da cadeia de caracteres.  
  
 `flags`  
 Sinalizadores de correspondências.  
  
 `first`  
 Início da sequência de correspondência.  
  
 `last`  
 Fim da sequência de correspondência.  
  
 `match`  
 Os resultados da correspondência. Corresponde ao tipo Elem: [smatch](../standard-library/regex-typedefs.md#smatch) para string, [wsmatch](../standard-library/regex-typedefs.md#wsmatch) para wstring, [cmatch](../standard-library/regex-typedefs.md#cmatch) para char* ou [wcmatch](../standard-library/regex-typedefs.md#wcmatch) para wchar_t\*.  
  
 `ptr`  
 Ponteiro para o início da sequência de correspondência. Se ptr for char*, use cmatch e regex. Se ptr for wchar_t\*, use wcmatch e wregex.  
  
 `re`  
 A expressão regular de correspondência. Digite `regex` para string e char* ou `wregex` para wstring e wchar_t\*.  
  
 `str`  
 Cadeia de caracteres de correspondência. Corresponde ao tipo de Elem.  
  
### <a name="remarks"></a>Comentários  
 Cada função de modelo só retornará verdadeiro se toda a sequência de operando `str` corresponder exatamente ao argumento da expressão regular `re`. Use [regex_search](../standard-library/regex-functions.md#regex_search) para corresponder uma subcadeia de caracteres dentro de uma sequência de destino e regex_iterator para encontrar várias correspondências. As funções que utilizam um objeto `match_results` definem seus membros para refletir se a correspondência foi bem-sucedida e, em caso afirmativo, quais são os diversos grupos de capturas na expressão regular capturada.  
  
 As funções que utilizam um objeto `match_results` definem seus membros para refletir se a correspondência foi bem-sucedida e, em caso afirmativo, quais são os diversos grupos de capturas na expressão regular capturada.  
  
 **(1):**  
  
### <a name="example"></a>Exemplo  
  
```cpp  
#include "stdafx.h"  
#include <regex>   
#include <iostream>   
  
using namespace std;  
  
int _tmain(int argc, _TCHAR* argv[])  
{  
  
    // (1) with char*  
    // Note how const char* requires cmatch and regex  
    const char *first = "abc";  
    const char *last = first + strlen(first);  
    cmatch narrowMatch;  
    regex rx("a(b)c");  
  
    bool found = regex_match(first, last, narrowMatch, rx);  
  
    // (1) with std::wstring  
    // Note how wstring requires wsmatch and wregex.  
    // Note use of const iterators cbegin() and cend().  
    wstring target(L"Hello");  
    wsmatch wideMatch;  
    wregex wrx(L"He(l+)o");  
  
    if (regex_match(target.cbegin(), target.cend(), wideMatch, wrx))  
        wcout << L"The matching text is:" << wideMatch.str() << endl;   
  
    // (2) with std::string  
    string target2("Drizzle");  
    regex rx2(R"(D\w+e)"); // no double backslashes with raw string literal  
    found = regex_match(target2.cbegin(), target2.cend(), rx2);  
  
    // (3) with wchar_t*  
    const wchar_t* target3 = L"2014-04-02";  
    wcmatch wideMatch2;  
  
    // LR"(...)" is a  raw wide-string literal. Open and close parens  
    // are delimiters, not string elements.  
    wregex wrx2(LR"(\d{4}(-|/)\d{2}(-|/)\d{2})");   
    if (regex_match(target3, wideMatch2, wrx2))  
    {  
        wcout << L"Matching text: " << wideMatch2.str() << endl;  
    }  
  
     return 0;  
}  
  
```  
  
##  <a name="regex_replace"></a>regex_replace
 Substitui expressões regulares correspondentes.  
  
```  
template <class OutIt, class BidIt, class RXtraits, class Alloc, class Elem>  
OutIt regex_replace(
    OutIt out,  
    BidIt first, 
    BidIt last,  
    const basic_regex<Elem, RXtraits, Alloc>& re,  
    const basic_string<Elem>& fmt,  
    match_flag_type flags = match_default);

template <class RXtraits, class Alloc, class Elem>  
basic_string<Elem> regex_replace(
    const basic_string<Elem>& str,  
    const basic_regex<Elem, RXtraits, Alloc>& re,  
    const basic_string<Elem>& fmt,  
    match_flag_type flags = match_default);
```  
  
### <a name="parameters"></a>Parâmetros  
 `OutIt`  
 O tipo de iterador para substituições.  
  
 `BidIt`  
 O tipo de iterador para subcorrespondências.  
  
 `RXtraits`  
 Classe de características para elementos.  
  
 `Alloc`  
 A classe alocadora de expressão regular.  
  
 `Elem`  
 O tipo de elemento a ser correspondido.  
  
 `flags`  
 Sinalizadores de correspondências.  
  
 `first`  
 Início da sequência de correspondência.  
  
 `fmt`  
 O formato das substituições.  
  
 `last`  
 Fim da sequência de correspondência.  
  
 `out`  
 O iterador de saída.  
  
 `re`  
 A expressão regular de correspondência.  
  
 `str`  
 Cadeia de caracteres de correspondência.  
  
### <a name="remarks"></a>Comentários  
 A primeira função constrói um objeto [Classe regex_iterator](../standard-library/regex-iterator-class.md) `iter(first, last, re, flags)` e o utiliza para dividir seu intervalo de entrada `[first, last)` em uma série de subsequências `T0M0T1M1...TN-1MN-1TN`, em que `Mn` é a correspondência `nth` detectada pelo iterador. Se nenhuma correspondência for encontrada, `T0` é todo o intervalo de entrada e `N` é zero. Se apenas a primeira correspondência `(flags & format_first_only) != 0` for usada, `T1` é todo o texto de entrada após a correspondência e `N` é 1. Para cada `i` no intervalo `[0, N)`, se `(flags & format_no_copy) == 0`, ele copia o texto no intervalo `Ti` para o iterador `out`. Depois, ele chama `m.format(out, fmt, flags)`, em que `m` é o objeto `match_results` retornado pelo objeto do iterador `iter` para a subsequência `Mi`. Por fim, se `(flags & format_no_copy) == 0`, ele copia o texto no intervalo `TN` para o iterador `out`. A função retorna `out`.  
  
 A segunda função constrói uma variável local `result` do tipo `basic_string<charT>` e chama `regex_replace(back_inserter(result), str.begin(), str.end(), re, fmt, flags)`. Ele retorna `result`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__regex__regex_replace.cpp   
// compile with: /EHsc   
#include <regex>   
#include <iostream>   
  
int main()   
    {   
    char buf[20];   
    const char *first = "axayaz";   
    const char *last = first + strlen(first);   
    std::regex rx("a");   
    std::string fmt("A");   
    std::regex_constants::match_flag_type fonly =   
        std::regex_constants::format_first_only;   
  
 *std::regex_replace(&buf[0], first, last, rx, fmt) = '\0';   
    std::cout << "replacement == " << &buf[0] << std::endl;   
  
 *std::regex_replace(&buf[0], first, last, rx, fmt, fonly) = '\0';   
    std::cout << "replacement == " << &buf[0] << std::endl;   
  
    std::string str("adaeaf");   
    std::cout << "replacement == "   
        << std::regex_replace(str, rx, fmt) << std::endl;   
  
    std::cout << "replacement == "   
        << std::regex_replace(str, rx, fmt, fonly) << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
replacement == AxAyAz  
replacement == Axayaz  
replacement == AdAeAf  
replacement == Adaeaf  
```  
  
##  <a name="regex_search"></a>regex_search
 Pesquisa por uma correspondência de expressão regular.  
  
```  
template <class BidIt, class Alloc, class Elem, class RXtraits, class Alloc2>  
bool regex_search(
    BidIt first, 
    Bidit last,  
    match_results<BidIt, Alloc>& match,  
    const basic_regex<Elem, RXtraits, Alloc2>& re,  
    match_flag_type flags = match_default);

template <class BidIt, class Elem, class RXtraits, class Alloc2>  
bool regex_search(
    BidIt first, 
    Bidit last,  
    const basic_regex<Elem, RXtraits, Alloc2>& re,  
    match_flag_type flags = match_default);

template <class Elem, class Alloc, class RXtraits, class Alloc2>  
bool regex_search(
    const Elem* ptr,  
    match_results<const Elem*, Alloc>& match,  
    const basic_regex<Elem, RXtraits, Alloc2>& re,  
    match_flag_type flags = match_default);

template <class Elem, class RXtraits, class Alloc2>  
bool regex_search(
    const Elem* ptr,  
    const basic_regex<Elem, RXtraits, Alloc2>& re,  
    match_flag_type flags = match_default);

template <class IOtraits, class IOalloc, class Alloc, class Elem, class RXtraits, class Alloc2>  
bool regex_search(
    const basic_string<Elem, IOtraits, IOalloc>& str,  
    match_results<typename basic_string<Elem, IOtraits, IOalloc>::const_iterator, Alloc>& match,  
    const basic_regex<Elem, RXtraits, Alloc2>& re,  
    match_flag_type flags = match_default);

template <class IOtraits, class IOalloc, class Elem, class RXtraits, class Alloc2>  
bool regex_search(
    const basic_string<Elem, IOtraits, IOalloc>& str,  
    const basic_regex<Elem, RXtraits, Alloc2>& re,  
    match_flag_type flags = match_default);
```  
  
### <a name="parameters"></a>Parâmetros  
 `BidIt`  
 O tipo de iterador para subcorrespondências.  
  
 `Alloc`  
 A classe alocadora de resultados de correspondência.  
  
 `Elem`  
 O tipo de elemento a ser correspondido.  
  
 `RXtraits`  
 Classe de características para elementos.  
  
 `Alloc2`  
 A classe alocadora de expressão regular.  
  
 `IOtraits`  
 A classe de característica da cadeia de caracteres.  
  
 `IOalloc`  
 A classe alocadora da cadeia de caracteres.  
  
 `flags`  
 Sinalizadores de correspondências.  
  
 `first`  
 Início da sequência de correspondência.  
  
 `last`  
 Fim da sequência de correspondência.  
  
 `match`  
 Os resultados da correspondência.  
  
 `ptr`  
 Ponteiro para o início da sequência de correspondência.  
  
 `re`  
 A expressão regular de correspondência.  
  
 `str`  
 Cadeia de caracteres de correspondência.  
  
### <a name="remarks"></a>Comentários  
 Cada função de modelo só retornará verdadeiro se uma pesquisa pelo argumento de expressão regular `re` em sua sequência de operando tiver êxito. As funções que utilizam um objeto `match_results` definem seus membros para refletir se a pesquisa foi bem-sucedida e, em caso afirmativo, quais são os diversos grupos de captura na expressão regular capturada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__regex__regex_search.cpp   
// compile with: /EHsc   
#include <regex>   
#include <iostream>   
  
int main()   
    {   
    const char *first = "abcd";   
    const char *last = first + strlen(first);   
    std::cmatch mr;   
    std::regex rx("abc");   
    std::regex_constants::match_flag_type fl =   
        std::regex_constants::match_default;   
  
    std::cout << "search(f, f+1, \"abc\") == " << std::boolalpha   
        << regex_search(first, first + 1, rx, fl) << std::endl;   
  
    std::cout << "search(f, l, \"abc\") == " << std::boolalpha   
        << regex_search(first, last, mr, rx) << std::endl;   
    std::cout << "  matched: \"" << mr.str() << "\"" << std::endl;   
  
    std::cout << "search(\"a\", \"abc\") == " << std::boolalpha   
        << regex_search("a", rx) << std::endl;   
  
    std::cout << "search(\"xabcd\", \"abc\") == " << std::boolalpha   
        << regex_search("xabcd", mr, rx) << std::endl;   
    std::cout << "  matched: \"" << mr.str() << "\"" << std::endl;   
  
    std::cout << "search(string, \"abc\") == " << std::boolalpha   
        << regex_search(std::string("a"), rx) << std::endl;   
  
    std::string str("abcabc");   
    std::match_results<std::string::const_iterator> mr2;   
    std::cout << "search(string, \"abc\") == " << std::boolalpha   
        << regex_search(str, mr2, rx) << std::endl;   
    std::cout << "  matched: \"" << mr2.str() << "\"" << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
search(f, f+1, "abc") == false  
search(f, l, "abc") == true  
  matched: "abc"  
search("a", "abc") == false  
search("xabcd", "abc") == true  
  matched: "abc"  
search(string, "abc") == false  
search(string, "abc") == true  
  matched: "abc"  
```  
  
##  <a name="swap"></a>  swap
 Troca dois objetos basic_regex ou match_results.  
  
```  
template <class Elem, class RXtraits>  
void swap(
    basic_regex<Elem, RXtraits, Alloc>& left,  
    basic_regex<Elem, RXtraits>& right) throw();

template <class Elem, class IOtraits, class BidIt, class Alloc>  
void swap(
    match_results<BidIt, Alloc>& left,  
    match_results<BidIt, Alloc>& right) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `Elem`  
 O tipo de elemento a ser correspondido.  
  
 `RXtraits`  
 Classe de características para elementos.  
  
### <a name="remarks"></a>Comentários  
 As funções de modelo trocam o conteúdo de seus respectivos argumentos constantemente em tempo constante e não geram exceções.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__regex__swap.cpp   
// compile with: /EHsc   
#include <regex>   
#include <iostream>   
  
int main()   
    {   
    std::regex rx0("c(a*)|(b)");   
    std::regex rx1;   
    std::cmatch mr0;   
    std::cmatch mr1;   
  
    swap(rx0, rx1);   
    std::regex_search("xcaaay", mr1, rx1);   
    swap(mr0, mr1);   
  
    std::csub_match sub = mr0[1];   
    std::cout << "matched == " << std::boolalpha   
        << sub.matched << std::endl;   
    std::cout << "length == " << sub.length() << std::endl;   
    std::cout << "string == " << sub << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
matched == true  
length == 3  
string == aaa  
```  
  
## <a name="see-also"></a>Consulte também  
[\<regex>](../standard-library/regex.md)  
[Classe regex_constants](../standard-library/regex-constants-class.md)  
[Classe regex_error](../standard-library/regex-error-class.md)  
[Classe regex_iterator](../standard-library/regex-iterator-class.md)  
[\<Operadores regex>](../standard-library/regex-operators.md)  
[Classe regex_token_iterator](../standard-library/regex-token-iterator-class.md)  
[Classe regex_traits](../standard-library/regex-traits-class.md)  
[\<Typedef regex>](../standard-library/regex-typedefs.md)  

