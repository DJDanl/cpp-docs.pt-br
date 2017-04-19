---
title: Operadores &lt;regex&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- regex/std::operator!=
- regex/std::operator>
- regex/std::operator>=
- regex/std::operator<
- regex/std::operator<=
- regex/std::operator==
- regex/std::operator<<
dev_langs:
- C++
ms.assetid: ec623e65-c186-491f-aa18-6b12b47e1127
caps.latest.revision: 12
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 41b445ceeeb1f37ee9873cb55f62d30d480d8718
ms.openlocfilehash: 254eee6065dfc4b11c6eadf82d07fcfb5a7cf4e3
ms.lasthandoff: 02/25/2017

---
# <a name="ltregexgt-operators"></a>Operadores &lt;regex&gt;
||||  
|-|-|-|  
|[operator!=](#operator_neq)|[operator&gt;](#operator_gt_)|[operator&gt;=](#operator_gt__eq)|  
|[operator&lt;](#operator_lt_)|[operator&lt;&lt;](#operator_lt__lt_)|[operator&lt;=](#operator_lt__eq)|  
|[operator==](#operator_eq_eq)|  
  
##  <a name="operator_neq"></a>  operator!=  
 Comparação de diferença para vários objetos.  
  
```  
template <class BidIt>  
bool operator!=(const sub_match<BidIt>& left,  
    const sub_match<BidIt>& right);

template <class BidIt, class IOtraits, class Alloc>  
bool operator!=(
    const basic_string<typename iterator_traits<BidIt>::value_type, IOtraits, Alloc>& left,  
    const sub_match<BidIt>& right);

template <class BidIt, class IOtraits, class Alloc>  
bool operator!=(const sub_match<BidIt>& left,  
    const basic_string<typename iterator_traits<BidIt>::value_type, IOtraits, Alloc>& right);

template <class BidIt>  
bool operator!=(const typename iterator_traits<BidIt>::value_type *left,  
    const sub_match<BidIt>& right);

template <class BidIt>  
bool operator!=(const sub_match<BidIt>& left,  
    const typename iterator_traits<BidIt>::value_type *right);

template <class BidIt>  
bool operator!=(const typename iterator_traits<BidIt>::value_type& left,  
    const sub_match<BidIt>& right);

template <class BidIt>  
bool operator!=(const sub_match<BidIt>& left,  
    const typename iterator_traits<BidIt>::value_type& right);

template <class BidIt, class Alloc>  
bool operator!=(const match_results<BidIt, Alloc>& left,  
    const match_results<BidIt, Alloc>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `BidIt`  
 O tipo de iterador.  
  
 `IOtraits`  
 A classe de característica da cadeia de caracteres.  
  
 `Alloc`  
 A classe do alocador.  
  
 `left`  
 O objeto à esquerda a ser comparado.  
  
 `right`  
 O objeto à direita a ser comparado.  
  
### <a name="remarks"></a>Comentários  
 Cada operador de modelo retorna `!(left == right)`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__regex__operator_ne.cpp   
// compile with: /EHsc   
#include <regex>   
#include <iostream>   
  
typedef std::cmatch::string_type Mystr;   
int main()   
    {   
    std::regex rx("c(a*)|(b)");   
    std::cmatch mr;   
  
    std::regex_search("xcaaay", mr, rx);   
  
    std::csub_match sub = mr[1];   
    std::cout << "match == " << mr.str() << std::endl;   
    std::cout << "sub == " << sub << std::endl;   
    std::cout << std::endl;   
  
    std::cout << "match != match == " << std::boolalpha   
        << (mr != mr) << std::endl;   
    std::cout << "sub != sub == " << std::boolalpha   
        << (sub != sub) << std::endl;   
  
    std::cout << "string(\"aab\") != sub == " << std::boolalpha   
        << (Mystr("aab") != sub) << std::endl;   
    std::cout << "sub != string(\"aab\") == " << std::boolalpha   
        << (sub != Mystr("aab")) << std::endl;   
  
    std::cout << "\"aab\" != sub == " << std::boolalpha   
        << ("aab" != sub) << std::endl;   
    std::cout << "sub != \"aab\" == " << std::boolalpha   
        << (sub != "aab") << std::endl;   
  
    std::cout << "'a' != sub == " << std::boolalpha   
        << ('a' != sub) << std::endl;   
    std::cout << "sub != 'a' == " << std::boolalpha   
        << (sub != 'a') << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
match == caaa  
sub == aaa  
  
match != match == false  
sub != sub == false  
string("aab") != sub == true  
sub != string("aab") == true  
"aab" != sub == true  
sub != "aab" == true  
'a' != sub == true  
sub != 'a' == true  
```  
  
##  <a name="operator_lt_"></a>  operator&lt;  
 Comparação de menor que para vários objetos.  
  
```  
template <class BidIt>  
bool operator<(const sub_match<BidIt>& left,  
    const sub_match<BidIt>& right);

template <class BidIt, class IOtraits, class Alloc>  
bool operator<(
    const basic_string<typename iterator_traits<BidIt>::value_type, IOtraits, Alloc>& left,  
    const sub_match<BidIt>& right);

template <class BidIt, class IOtraits, class Alloc>  
bool operator<(const sub_match<BidIt>& left,  
    const basic_string<typename iterator_traits<BidIt>::value_type, IOtraits, Alloc>& right);

template <class BidIt>  
bool operator<(const typename iterator_traits<BidIt>::value_type *left,  
    const sub_match<BidIt>& right);

template <class BidIt>  
bool operator<(const sub_match<BidIt>& left,  
    const typename iterator_traits<BidIt>::value_type *right);

template <class BidIt>  
bool operator<(const typename iterator_traits<BidIt>::value_type& left,  
    const sub_match<BidIt>& right);

template <class BidIt>  
bool operator<(const sub_match<BidIt>& left,  
    const typename iterator_traits<BidIt>::value_type& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `BidIt`  
 O tipo de iterador.  
  
 `IOtraits`  
 A classe de característica da cadeia de caracteres.  
  
 `Alloc`  
 A classe do alocador.  
  
 `left`  
 O objeto à esquerda a ser comparado.  
  
 `right`  
 O objeto à direita a ser comparado.  
  
### <a name="remarks"></a>Comentários  
 Cada operador de modelo converte seu argumento em um tipo de cadeia de caracteres e retorna true somente se o valor convertido do `left` for menor em comparação ao valor convertido de `right`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__regex__operator_lt.cpp   
// compile with: /EHsc   
#include <regex>   
#include <iostream>   
  
typedef std::cmatch::string_type Mystr;   
int main()   
    {   
    std::regex rx("c(a*)|(b)");   
    std::cmatch mr;   
  
    std::regex_search("xcaaay", mr, rx);   
  
    std::csub_match sub = mr[1];   
    std::cout << "sub == " << sub << std::endl;   
    std::cout << std::endl;   
  
    std::cout << "sub < sub == " << std::boolalpha   
        << (sub < sub) << std::endl;   
  
    std::cout << "string(\"aab\") < sub == " << std::boolalpha   
        << (Mystr("aab") < sub) << std::endl;   
    std::cout << "sub < string(\"aab\") == " << std::boolalpha   
        << (sub < Mystr("aab")) << std::endl;   
  
    std::cout << "\"aab\" < sub == " << std::boolalpha   
        << ("aab" < sub) << std::endl;   
    std::cout << "sub < \"aab\" == " << std::boolalpha   
        << (sub < "aab") << std::endl;   
  
    std::cout << "'a' < sub == " << std::boolalpha   
        << ('a' < sub) << std::endl;   
    std::cout << "sub < 'a' == " << std::boolalpha   
        << (sub < 'a') << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
sub == aaa  
  
sub < sub == false  
string("aab") < sub == false  
sub < string("aab") == true  
"aab" < sub == false  
sub < "aab" == true  
'a' < sub == true  
sub < 'a' == false  
```  
  
##  <a name="operator_lt__lt_"></a>  operator&lt;&lt;  
 Insere um sub_match em um fluxo.  
  
```  
template <class Elem, class IOtraits, class Alloc, class BidIt>  
basic_ostream<Elem, IOtraits>& operator<<(basic_ostream<Elem, IOtraits>& os,  
    const sub_match<BidIt>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Elem`  
 O tipo de elemento.  
  
 `IOtraits`  
 A classe de característica da cadeia de caracteres.  
  
 `Alloc`  
 A classe do alocador.  
  
 `BidIt`  
 O tipo de iterador.  
  
 `os`  
 O fluxo de saída.  
  
 `right`  
 O objeto a ser inserido.  
  
### <a name="remarks"></a>Comentários  
 O operador de modelo retorna `os << right.str()`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__regex__operator_ins.cpp   
// compile with: /EHsc   
#include <regex>   
#include <iostream>   
  
int main()   
    {   
    std::regex rx("c(a*)|(b)");   
    std::cmatch mr;   
  
    std::regex_search("xcaaay", mr, rx);   
  
    std::csub_match sub = mr[0];   
    std::cout << "whole match: " << sub << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
whole match: caaa  
```  
  
##  <a name="operator_lt__eq"></a>  operator&lt;=  
 Comparação de menor ou igual para vários objetos.  
  
```  
template <class BidIt>  
bool operator<=(const sub_match<BidIt>& left,  
    const sub_match<BidIt>& right);

template <class BidIt, class IOtraits, class Alloc>  
bool operator<=(
    const basic_string<typename iterator_traits<BidIt>::value_type, IOtraits, Alloc>& left,  
    const sub_match<BidIt>& right);

template <class BidIt, class IOtraits, class Alloc>  
bool operator<=(const sub_match<BidIt>& left,  
    const basic_string<typename iterator_traits<BidIt>::value_type, IOtraits, Alloc>& right);

template <class BidIt>  
bool operator<=(const typename iterator_traits<BidIt>::value_type *left,  
    const sub_match<BidIt>& right);

template <class BidIt>  
bool operator<=(const sub_match<BidIt>& left,  
    const typename iterator_traits<BidIt>::value_type *right);

template <class BidIt>  
bool operator<=(const typename iterator_traits<BidIt>::value_type& left,  
    const sub_match<BidIt>& right);

template <class BidIt>  
bool operator<=(const sub_match<BidIt>& left,  
    const typename iterator_traits<BidIt>::value_type& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `BidIt`  
 O tipo de iterador.  
  
 `IOtraits`  
 A classe de característica da cadeia de caracteres.  
  
 `Alloc`  
 A classe do alocador.  
  
 `left`  
 O objeto à esquerda a ser comparado.  
  
 `right`  
 O objeto à direita a ser comparado.  
  
### <a name="remarks"></a>Comentários  
 Cada operador de modelo retorna `!(right < left)`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__regex__operator_le.cpp   
// compile with: /EHsc   
#include <regex>   
#include <iostream>   
  
typedef std::cmatch::string_type Mystr;   
int main()   
    {   
    std::regex rx("c(a*)|(b)");   
    std::cmatch mr;   
  
    std::regex_search("xcaaay", mr, rx);   
  
    std::csub_match sub = mr[1];   
    std::cout << "sub == " << sub << std::endl;   
    std::cout << std::endl;   
  
    std::cout << "sub <= sub == " << std::boolalpha   
        << (sub <= sub) << std::endl;   
  
    std::cout << "string(\"aab\") <= sub == " << std::boolalpha   
        << (Mystr("aab") <= sub) << std::endl;   
    std::cout << "sub <= string(\"aab\") == " << std::boolalpha   
        << (sub <= Mystr("aab")) << std::endl;   
  
    std::cout << "\"aab\" <= sub == " << std::boolalpha   
        << ("aab" <= sub) << std::endl;   
    std::cout << "sub <= \"aab\" == " << std::boolalpha   
        << (sub <= "aab") << std::endl;   
  
    std::cout << "'a' <= sub == " << std::boolalpha   
        << ('a' <= sub) << std::endl;   
    std::cout << "sub <= 'a' == " << std::boolalpha   
        << (sub <= 'a') << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
sub == aaa  
  
sub <= sub == true  
string("aab") <= sub == false  
sub <= string("aab") == true  
"aab" <= sub == false  
sub <= "aab" == true  
'a' <= sub == true  
sub <= 'a' == false  
```  
  
##  <a name="operator_eq_eq"></a>  operator==  
 Comparação de igualdade para vários objetos.  
  
```  
template <class BidIt>  
bool operator==(const sub_match<BidIt>& left,  
    const sub_match<BidIt>& right);

template <class BidIt, class IOtraits, class Alloc>  
bool operator==(
    const basic_string<typename iterator_traits<BidIt>::value_type, IOtraits, Alloc>& left,  
    const sub_match<BidIt>& right);

template <class BidIt, class IOtraits, class Alloc>  
bool operator==(const sub_match<BidIt>& left,  
    const basic_string<typename iterator_traits<BidIt>::value_type, IOtraits, Alloc>& right);

template <class BidIt>  
bool operator==(const typename iterator_traits<BidIt>::value_type* left,  
    const sub_match<BidIt>& right);

template <class BidIt>  
bool operator==(const sub_match<BidIt>& left,  
    const typename iterator_traits<BidIt>::value_type* right);

template <class BidIt>  
bool operator==(const typename iterator_traits<BidIt>::value_type& left,  
    const sub_match<BidIt>& right);

template <class BidIt>  
bool operator==(const sub_match<BidIt>& left,  
    const typename iterator_traits<BidIt>::value_type& right);

template <class BidIt, class Alloc>  
bool operator==(const match_results<BidIt, Alloc>& left,  
    const match_results<BidIt, Alloc>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `BidIt`  
 O tipo de iterador.  
  
 `IOtraits`  
 A classe de característica da cadeia de caracteres.  
  
 `Alloc`  
 A classe do alocador.  
  
 `left`  
 O objeto à esquerda a ser comparado.  
  
 `right`  
 O objeto à direita a ser comparado.  
  
### <a name="remarks"></a>Comentários  
 Cada operador de modelo converte cada um de seus argumentos em um tipo de cadeia de caracteres e retorna o resultado da comparação da igualdade dos objetos convertidos.  
  
 Quando um operador de modelo converte seus argumentos em um tipo de cadeia de caracteres, ele usa a primeira das seguintes transformações aplicáveis:  
  
 argumentos cujos tipos são uma especialização da classe de modelo `match_results` ou `sub_match` são convertidos chamando a função membro `str`;  
  
 argumentos cujos tipos são uma especialização da classe modelo `basic_string` permanecem inalterados;  
  
 todos os outros tipos de argumento são convertidos passando o valor do argumento para o construtor para uma especialização apropriada da classe de modelo `basic_string`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__regex__operator_eq.cpp   
// compile with: /EHsc   
#include <regex>   
#include <iostream>   
  
typedef std::cmatch::string_type Mystr;   
int main()   
    {   
    std::regex rx("c(a*)|(b)");   
    std::cmatch mr;   
  
    std::regex_search("xcaaay", mr, rx);   
  
    std::csub_match sub = mr[1];   
    std::cout << "match == " << mr.str() << std::endl;   
    std::cout << "sub == " << sub << std::endl;   
    std::cout << std::endl;   
  
    std::cout << "match == match == " << std::boolalpha   
        << (mr == mr) << std::endl;   
    std::cout << "sub == sub == " << std::boolalpha   
        << (sub == sub) << std::endl;   
  
    std::cout << "string(\"aab\") == sub == " << std::boolalpha   
        << (Mystr("aab") == sub) << std::endl;   
    std::cout << "sub == string(\"aab\") == " << std::boolalpha   
        << (sub == Mystr("aab")) << std::endl;   
  
    std::cout << "\"aab\" == sub == " << std::boolalpha   
        << ("aab" == sub) << std::endl;   
    std::cout << "sub == \"aab\" == " << std::boolalpha   
        << (sub == "aab") << std::endl;   
  
    std::cout << "'a' == sub == " << std::boolalpha   
        << ('a' == sub) << std::endl;   
    std::cout << "sub == 'a' == " << std::boolalpha   
        << (sub == 'a') << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
match == caaa  
sub == aaa  
  
match == match == true  
sub == sub == true  
string("aab") == sub == false  
sub == string("aab") == false  
"aab" == sub == false  
sub == "aab" == false  
'a' == sub == false  
sub == 'a' == false  
```  
  
##  <a name="operator_gt_"></a>  operator&gt;  
 Comparação de maior que para vários objetos.  
  
```  
template <class BidIt>  
bool operator>(const sub_match<BidIt>& left,  
    const sub_match<BidIt>& right);

template <class BidIt, class IOtraits, class Alloc>  
bool operator>(
    const basic_string<typename iterator_traits<BidIt>::value_type, IOtraits, Alloc>& left,  
    const sub_match<BidIt>& right);

template <class BidIt, class IOtraits, class Alloc>  
bool operator>(const sub_match<BidIt>& left,  
    const basic_string<typename iterator_traits<BidIt>::value_type, IOtraits, Alloc>& right);

template <class BidIt>  
bool operator>(const typename iterator_traits<BidIt>::value_type *left,  
    const sub_match<BidIt>& right);

template <class BidIt>  
bool operator>(const sub_match<BidIt>& left,  
    const typename iterator_traits<BidIt>::value_type *right);

template <class BidIt>  
bool operator>(const typename iterator_traits<BidIt>::value_type& left,  
    const sub_match<BidIt>& right);

template <class BidIt>  
bool operator>(const sub_match<BidIt>& left,  
    const typename iterator_traits<BidIt>::value_type& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `BidIt`  
 O tipo de iterador.  
  
 `IOtraits`  
 A classe de característica da cadeia de caracteres.  
  
 `Alloc`  
 A classe do alocador.  
  
 `left`  
 O objeto à esquerda a ser comparado.  
  
 `right`  
 O objeto à direita a ser comparado.  
  
### <a name="remarks"></a>Comentários  
 Cada operador de modelo retorna `right < left`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__regex__operator_gt.cpp   
// compile with: /EHsc   
#include <regex>   
#include <iostream>   
  
typedef std::cmatch::string_type Mystr;   
int main()   
    {   
    std::regex rx("c(a*)|(b)");   
    std::cmatch mr;   
  
    std::regex_search("xcaaay", mr, rx);   
  
    std::csub_match sub = mr[1];   
    std::cout << "sub == " << sub << std::endl;   
    std::cout << std::endl;   
  
    std::cout << "sub > sub == " << std::boolalpha   
        << (sub > sub) << std::endl;   
  
    std::cout << "string(\"aab\") > sub == " << std::boolalpha   
        << (Mystr("aab") > sub) << std::endl;   
    std::cout << "sub > string(\"aab\") == " << std::boolalpha   
        << (sub > Mystr("aab")) << std::endl;   
  
    std::cout << "\"aab\" > sub == " << std::boolalpha   
        << ("aab" > sub) << std::endl;   
    std::cout << "sub > \"aab\" == " << std::boolalpha   
        << (sub > "aab") << std::endl;   
  
    std::cout << "'a' > sub == " << std::boolalpha   
        << ('a' > sub) << std::endl;   
    std::cout << "sub > 'a' == " << std::boolalpha   
        << (sub > 'a') << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
sub == aaa  
  
sub > sub == false  
string("aab") > sub == true  
sub > string("aab") == false  
"aab" > sub == true  
sub > "aab" == false  
'a' > sub == false  
sub > 'a' == true  
```  
  
##  <a name="operator_gt__eq"></a>  operator&gt;=  
 Comparação de maior ou igual para vários objetos.  
  
```  
template <class BidIt>  
bool operator>=(const sub_match<BidIt>& left,  
    const sub_match<BidIt>& right);

template <class BidIt, class IOtraits, class Alloc>  
bool operator>=(
    const basic_string<typename iterator_traits<BidIt>::value_type, IOtraits, Alloc>& left,  
    const sub_match<BidIt>& right);

template <class BidIt, class IOtraits, class Alloc>  
bool operator>=(const sub_match<BidIt>& left,  
    const basic_string<typename iterator_traits<BidIt>::value_type, IOtraits, Alloc>& right);

template <class BidIt>  
bool operator>=(const typename iterator_traits<BidIt>::value_type *left,  
    const sub_match<BidIt>& right);

template <class BidIt>  
bool operator>=(const sub_match<BidIt>& left,  
    const typename iterator_traits<BidIt>::value_type *right);

template <class BidIt>  
bool operator>=(const typename iterator_traits<BidIt>::value_type& left,  
    const sub_match<BidIt>& right);

template <class BidIt>  
bool operator>=(const sub_match<BidIt>& left,  
    const typename iterator_traits<BidIt>::value_type& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `BidIt`  
 O tipo de iterador.  
  
 `IOtraits`  
 A classe de característica da cadeia de caracteres.  
  
 `Alloc`  
 A classe do alocador.  
  
 `left`  
 O objeto à esquerda a ser comparado.  
  
 `right`  
 O objeto à direita a ser comparado.  
  
### <a name="remarks"></a>Comentários  
 Cada operador de modelo retorna `!(left < right)`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__regex__operator_ge.cpp   
// compile with: /EHsc   
#include <regex>   
#include <iostream>   
  
typedef std::cmatch::string_type Mystr;   
int main()   
    {   
    std::regex rx("c(a*)|(b)");   
    std::cmatch mr;   
  
    std::regex_search("xcaaay", mr, rx);   
  
    std::csub_match sub = mr[1];   
    std::cout << "sub == " << sub << std::endl;   
    std::cout << std::endl;   
  
    std::cout << "sub >= sub == " << std::boolalpha   
        << (sub >= sub) << std::endl;   
  
    std::cout << "string(\"aab\") >= sub == " << std::boolalpha   
        << (Mystr("aab") >= sub) << std::endl;   
    std::cout << "sub >= string(\"aab\") == " << std::boolalpha   
        << (sub >= Mystr("aab")) << std::endl;   
  
    std::cout << "\"aab\" >= sub == " << std::boolalpha   
        << ("aab" >= sub) << std::endl;   
    std::cout << "sub >= \"aab\" == " << std::boolalpha   
        << (sub >= "aab") << std::endl;   
  
    std::cout << "'a' >= sub == " << std::boolalpha   
        << ('a' >= sub) << std::endl;   
    std::cout << "sub >= 'a' == " << std::boolalpha   
        << (sub >= 'a') << std::endl;   
  
    return (0);   
    }  
```  
  
```Output  
sub == aaa  
  
sub >= sub == true  
string("aab") >= sub == true  
sub >= string("aab") == false  
"aab" >= sub == true  
sub >= "aab" == false  
'a' >= sub == false  
sub >= 'a' == true  
```  
  
## <a name="see-also"></a>Consulte também  
[\<regex>](../standard-library/regex.md)  
[Classe regex_constants](../standard-library/regex-constants-class.md)  
[Classe regex_error](../standard-library/regex-error-class.md)  
[\<Funções regex>](../standard-library/regex-functions.md)  
[Classe regex_iterator](../standard-library/regex-iterator-class.md)  
[Classe regex_token_iterator](../standard-library/regex-token-iterator-class.md)  
[Classe regex_traits](../standard-library/regex-traits-class.md)  
[\<Typedef regex>](../standard-library/regex-typedefs.md)  



