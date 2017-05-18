---
title: Classe basic_string | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- basic_string
- xstring/std::basic_string
- string/std::basic_string::allocator_type
- string/std::basic_string::const_iterator
- string/std::basic_string::const_pointer
- string/std::basic_string::const_reference
- string/std::basic_string::const_reverse_iterator
- string/std::basic_string::difference_type
- string/std::basic_string::iterator
- string/std::basic_string::npos
- string/std::basic_string::pointer
- string/std::basic_string::reference
- string/std::basic_string::reverse_iterator
- string/std::basic_string::size_type
- string/std::basic_string::traits_type
- string/std::basic_string::value_type
- string/std::basic_string::append
- string/std::basic_string::assign
- string/std::basic_string::at
- string/std::basic_string::back
- string/std::basic_string::begin
- string/std::basic_string::c_str
- string/std::basic_string::capacity
- string/std::basic_string::cbegin
- string/std::basic_string::cend
- string/std::basic_string::clear
- string/std::basic_string::compare
- string/std::basic_string::copy
- string/std::basic_string::crbegin
- string/std::basic_string::crend
- string/std::basic_string::_Copy_s
- string/std::basic_string::data
- string/std::basic_string::empty
- string/std::basic_string::end
- string/std::basic_string::erase
- string/std::basic_string::find
- string/std::basic_string::find_first_not_of
- string/std::basic_string::find_first_of
- string/std::basic_string::find_last_not_of
- string/std::basic_string::find_last_of
- string/std::basic_string::front
- string/std::basic_string::get_allocator
- string/std::basic_string::insert
- string/std::basic_string::length
- string/std::basic_string::max_size
- string/std::basic_string::pop_back
- string/std::basic_string::push_back
- string/std::basic_string::rbegin
- string/std::basic_string::rend
- string/std::basic_string::replace
- string/std::basic_string::reserve
- string/std::basic_string::resize
- string/std::basic_string::rfind
- string/std::basic_string::shrink_to_fit
- string/std::basic_string::size
- string/std::basic_string::substr
- string/std::basic_string::swap
dev_langs:
- C++
helpviewer_keywords:
- basic_string class
ms.assetid: a9c3e0a2-39bf-4c8a-b093-9abe30839591
caps.latest.revision: 19
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 66798adc96121837b4ac2dd238b9887d3c5b7eef
ms.openlocfilehash: 062f7fdf2d3d57dc08a0e632326ccbc228eb7df6
ms.contentlocale: pt-br
ms.lasthandoff: 04/29/2017

---
# <a name="basicstring-class"></a>Classe basic_string
As sequências controladas por um objeto da classe de modelo `basic_string` são a classe de cadeia de caracteres do C++ Padrão e, geralmente, são chamadas de cadeias de caracteres, mas não devem ser confundidas com as cadeias de caracteres do estilo C terminadas em nulo, usadas em toda a Biblioteca Padrão C++. A cadeia de caracteres do C++ Padrão é um contêiner que permite o uso de cadeias de caracteres como tipos normais, como operações de comparação e concatenação, iteradores, algoritmos da Biblioteca Padrão C++, além de cópia e atribuição com memória gerenciada pela classe de alocador. Se você precisar converter uma cadeia de caracteres do C++ Padrão em uma cadeia de caracteres do estilo C terminada em nulo, use o membro [basic_string::c_str](#c_str).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class CharType, class Traits = char_traits<CharType>, class Allocator = allocator<CharType>>  
class basic_string;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `CharType`  
 O tipo de dados de um único caractere a ser armazenado na cadeia de caracteres. A Biblioteca Padrão C++ oferece especializações desta classe de modelo, com as definições de tipo [string](../standard-library/string-typedefs.md#string) para elementos do tipo `char`, [wstring](../standard-library/string-typedefs.md#wstring) para `wchar_t`, [u16string](../standard-library/string-typedefs.md#u16string) para `char16_t` e [u32string](../standard-library/string-typedefs.md#u32string) para `char32_t`.  
  
 `Traits`  
 Várias propriedades importantes dos elementos **CharType** em uma especialização basic_string são descritos pela classe **Traits**. O valor padrão é `char_traits`< `CharType`>.  
  
 `Allocator`  
 O tipo que representa o objeto alocador armazenado que encapsula detalhes sobre a alocação e desalocação de memória da cadeia de caracteres. O valor padrão é **allocator**< `CharType`>.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[basic_string](#basic_string)|Cria uma cadeia de caracteres vazia ou iniciada por caracteres específicos ou que seja uma cópia de todos ou parte de algum outro objeto da cadeia de caracteres ou da cadeia de caracteres C.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[allocator_type](#allocator_type)|Um tipo que representa a classe `allocator` para um objeto da cadeia de caracteres.|  
|[const_iterator](#const_iterator)|Um tipo que fornece um iterador de acesso aleatório que pode acessar e ler um elemento `const` na cadeia de caracteres.|  
|[const_pointer](#const_pointer)|Um tipo que fornece um ponteiro para um elemento `const` em uma cadeia de caracteres.|  
|[const_reference](#const_reference)|Um tipo que fornece uma referência para um elemento `const` armazenado em um cadeia para leitura e execução de operações `const`.|  
|[const_reverse_iterator](#const_reverse_iterator)|Um tipo que fornece um iterador de acesso aleatório que pode ler qualquer elemento `const` na cadeia de caracteres.|  
|[difference_type](#difference_type)|Um tipo que fornece a diferença entre dois iteradores que se referem a elementos na mesma cadeia.|  
|[iterator](#iterator)|Um tipo que fornece um iterador de acesso aleatório que pode ler ou modificar qualquer elemento em uma cadeia de caracteres.|  
|[npos](#npos)|Um valor inteiro sem sinal inicializado como -1 que indica "não foi encontrado" ou "todos os caracteres restantes" quando uma função de pesquisa falha.|  
|[pointer](#pointer)|Um tipo que fornece um ponteiro para um elemento de caracteres em uma matriz de cadeia de caracteres ou caractere.|  
|[reference](#reference)|Um tipo que fornece uma referência a um elemento armazenado em uma cadeia de caracteres.|  
|[reverse_iterator](#reverse_iterator)|Um tipo que fornece um iterador de acesso aleatório que pode ler ou modificar qualquer elemento em uma cadeia de caracteres invertida.|  
|[size_type](#size_type)|Um tipo integral não assinado para o número de elementos em uma cadeia.|  
|[traits_type](#traits_type)|Um tipo para as características dos elementos armazenados em uma cadeia de caracteres.|  
|[value_type](#value_type)|Um tipo que representa o tipo de caracteres armazenados em uma cadeia de caracteres.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[append](#append)|Acrescenta caracteres ao final de uma cadeia de caracteres.|  
|[assign](#assign)|Atribui novos valores de caracteres ao conteúdo de uma cadeia de caracteres.|  
|[at](#at)|Retorna uma referência ao elemento em um local especificado na cadeia de caracteres.|  
|[back](#back)||  
|[begin](#begin)|Retorna um iterador que trata o primeiro elemento na cadeia de caracteres.|  
|[c_str](#c_str)|Converte o conteúdo de uma cadeia de caracteres em uma cadeia de estilo C, com terminação nula.|  
|[capacity](#capacity)|Retorna o maior número de elementos que podem ser armazenados em uma cadeia de caracteres sem aumentar a alocação de memória da cadeia.|  
|[cbegin](#cbegin)|Retorna um iterador const que trata o primeiro elemento na cadeia.|  
|[cend](#cend)|Retorna um iterador const que trata o local após o último elemento em uma cadeia.|  
|[clear](#clear)|Apaga todos os elementos de uma cadeia de caracteres.|  
|[compare](#compare)|Compara uma cadeia de caracteres com uma cadeia especificada para determinar se duas cadeias são iguais ou se uma é lexicograficamente menor do que a outra.|  
|[copy](#copy)|Copia, no máximo, um número específico de caracteres de uma posição indexada em uma cadeia de caracteres de origem em um conjunto de caracteres de destino. Preterido. Use [basic_string::_Copy_s](#copy_s) no lugar.|  
|[crbegin](#crbegin)|Retorna um iterador const que trata o primeiro elemento em uma cadeia de caracteres invertida.|  
|[crend](#crend)|Retorna um iterador const que trata o local após o último elemento em uma cadeia invertida.|  
|[_Copy_s](#copy_s)|Copia, no máximo, um número específico de caracteres de uma posição indexada em uma cadeia de caracteres de origem em um conjunto de caracteres de destino.|  
|[data](#data)|Converte o conteúdo de uma cadeia de caracteres em uma matriz de caracteres.|  
|[empty](#empty)|Testa se a cadeia de caracteres contém caracteres.|  
|[end](#end)|Retorna um iterador que trata o local após o último elemento em uma cadeia de caracteres.|  
|[erase](#erase)|Remove um elemento ou um intervalo de elementos em uma cadeia de caracteres de uma posição especificada.|  
|[find](#find)|Pesquisa, para frente, em uma cadeia de caracteres, a primeira ocorrência de uma subcadeia que corresponde a uma sequência de caracteres especificada.|  
|[find_first_not_of](#find_first_not_of)|Pesquisa, em uma cadeia de caracteres, o primeiro caractere que não seja um elemento de uma cadeia de caracteres especificada.|  
|[find_first_of](#find_first_of)|Pesquisa, em uma cadeia de caracteres, o primeiro caractere que corresponda a qualquer elemento de uma cadeia de caracteres especificada.|  
|[find_last_not_of](#find_last_not_of)|Pesquisa, em uma cadeia de caracteres, o último caractere que não seja um elemento de uma cadeia de caracteres especificada.|  
|[find_last_of](#find_last_of)|Pesquisa, em uma cadeia de caracteres, o último caractere que seja um elemento de uma cadeia de caracteres especificada.|  
|[front](#front)|Retorna uma referência ao primeiro elemento em uma cadeia de caracteres.|  
|[get_allocator](#get_allocator)|Retorna uma cópia do objeto `allocator` usado para construir a cadeia.|  
|[insert](#insert)|Insere um elemento ou um número de elementos ou um intervalo de elementos na cadeia de caracteres na posição especificada.|  
|[length](#length)|Retorna o número de elementos em uma cadeia de caracteres.|  
|[max_size](#max_size)|Retorna o número máximo de caracteres que uma cadeia de caracteres pode conter.|  
|[pop_back](#pop_back)|Apaga o último elemento da cadeia de caracteres.|  
|[push_back](#push_back)|Adiciona um elemento ao final de uma cadeia de caracteres.|  
|[rbegin](#rbegin)|Retorna um iterador ao primeiro elemento em uma cadeia invertida.|  
|[rend](#rend)|Retorna um iterador que aponta além do último elemento em uma cadeia de caracteres invertida.|  
|[replace](#replace)|Substitui elementos em uma cadeia de caractere em uma posição especificada por caracteres especificados ou copiados de outros intervalos de cadeia de caracteres ou cadeias C.|  
|[reserve](#reserve)|Define a capacidade da cadeia de caracteres para um número pelo menos tão grande quanto um número especificado.|  
|[resize](#resize)|Especifica um novo tamanho para uma cadeia de caracteres, acrescentando ou apagando elementos conforme necessário.|  
|[rfind](#rfind)|Pesquisa, para trás, em uma cadeia de caracteres, a primeira ocorrência de uma subcadeia que corresponde a uma sequência de caracteres especificada.|  
|[shrink_to_fit](#shrink_to_fit)|Descarta a capacidade excedente da cadeia de caracteres.|  
|[size](#size)|Retorna o número de elementos em uma cadeia de caracteres.|  
|[substr](#substr)|Copia uma subcadeia de, no máximo, um número de caracteres, de uma cadeia com início em uma posição especificada.|  
|[swap](#swap)|Troca o conteúdo das duas cadeias de caracteres.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operator+=](#op_add_eq)|Acrescenta caracteres a uma cadeia de caracteres.|  
|[operator=](#op_eq)|Atribui novos valores de caracteres ao conteúdo de uma cadeia de caracteres.|  
|[operator&#91;&#93;](#op_at)|Fornece uma referência ao caractere com um índice especificado em uma cadeia de caracteres.|  
  
## <a name="remarks"></a>Comentários  
 Se for solicitado que uma função gere uma sequência mais longa que os elementos [max_size](#max_size), a função relatará um erro de comprimento, gerando um objeto do tipo [length_error](../standard-library/length-error-class.md).  
  
 As referências, os ponteiros e os iteradores que designam elementos da sequência controlada podem tornar-se inválidos após qualquer chamada para uma função que altere a sequência controlada ou após a primeira chamada para uma função membro que não seja **const**.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<string>  
  
 **Namespace:** std  
  
##  <a name="allocator_type"></a>  basic_string::allocator_type  
 Um tipo que representa a classe de alocador de um objeto de cadeia de caracteres.  
  
```  
typedef Allocator allocator_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo **Allocator**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_allocator_type.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   // The following lines declare objects  
   // that use the default allocator.  
   string s1;  
   basic_string <char>::allocator_type xchar = s1.get_allocator( );  
   // You can now call functions on the allocator class xchar used by s1  
}  
```  
  
##  <a name="append"></a>  basic_string::append  
 Acrescenta caracteres ao final de uma cadeia de caracteres.  
  
```  
basic_string<CharType, Traits, Allocator>& append(
    const value_type* ptr);

basic_string<CharType, Traits, Allocator>& append(
    const value_type* ptr,  
    size_type count);

basic_string<CharType, Traits, Allocator>& append(
    const basic_string<CharType, Traits, Allocator>& str,  
    size_type _Off,  
    size_type count);

basic_string<CharType, Traits, Allocator>& append(
    const basic_string<CharType, Traits, Allocator>& str);

basic_string<CharType, Traits, Allocator>& append(
    size_type count,   
    value_type _Ch);

template <class InputIterator>  
basic_string<CharType, Traits, Allocator>& append(
    InputIterator first,   
    InputIterator last);

basic_string<CharType, Traits, Allocator>& append(
    const_pointer first,  
    const_pointer last);

basic_string<CharType, Traits, Allocator>& append(
    const_iterator first,  
    const_iterator last);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ptr`  
 A cadeia de caracteres do C a ser acrescentada.  
  
 `str`  
 A cadeia de caracteres cujos caracteres devem ser acrescentados.  
  
 `_Off`  
 O índice da parte da cadeia de caracteres de origem que fornece os caracteres a serem acrescentados.  
  
 `count`  
 O número máximo de caracteres a serem acrescentados da cadeia de caracteres de origem.  
  
 `_Ch`  
 O valor de caractere a ser acrescentados.  
  
 `first`  
 Um iterador de entrada que trata do primeiro elemento no intervalo a ser acrescentados.  
  
 `last`  
 Um iterador de entrada, const_pointer ou const_iterator, que trata da posição logo após o último elemento no intervalo a ser acrescentados.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto de cadeia de caracteres que está sendo acrescentado com os caracteres passados pela função membro.  
  
### <a name="remarks"></a>Comentários  
 Caracteres podem ser acrescentados a uma cadeia de caracteres usando o [operator+=](#op_add_eq) ou as funções membro **append** ou [push_back](#push_back). `operator+=` acrescenta valores de argumento único enquanto a função membro **append** de múltiplos argumentos permite que uma parte específica de uma cadeia de caracteres seja especificada para a adição.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_append.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
  
   // The first member function  
   // appending a C-string to a string  
   string str1a ( "Hello " );  
   cout << "The original string str1 is: " << str1a << endl;  
   const char *cstr1a = "Out There ";  
   cout << "The C-string cstr1a is: " << cstr1a << endl;  
   str1a.append ( cstr1a );  
   cout << "Appending the C-string cstr1a to string str1 gives: "   
        << str1a << "." << endl << endl;  
  
   // The second member function  
   // appending part of a C-string to a string  
   string str1b ( "Hello " );  
   cout << "The string str1b is: " << str1b << endl;  
   const char *cstr1b = "Out There ";  
   cout << "The C-string cstr1b is: " << cstr1b << endl;  
   str1b.append ( cstr1b , 3 );  
   cout << "Appending the 1st part of the C-string cstr1b "  
        << "to string str1 gives: " << str1b << "."   
        << endl << endl;  
  
   // The third member function  
   // appending part of one string to another  
   string str1c ( "Hello " ), str2c ( "Wide World " );  
   cout << "The string str2c is: " << str2c << endl;  
   str1c.append ( str2c , 5 , 5 );  
   cout << "The appended string str1 is: "   
        << str1c << "." << endl << endl;  
  
   // The fourth member function  
   // appending one string to another in two ways,  
   // comparing append and operator [ ]  
   string str1d ( "Hello " ), str2d ( "Wide " ), str3d ( "World " );  
   cout << "The  string str2d is: " << str2d << endl;  
   str1d.append ( str2d );  
   cout << "The appended string str1d is: "   
        << str1d << "." << endl;  
   str1d += str3d;  
   cout << "The doubly appended strig str1 is: "   
        << str1d << "." << endl << endl;  
  
   // The fifth member function  
   // appending characters to a string  
   string str1e ( "Hello " );  
   str1e.append ( 4 , '!' );  
   cout << "The string str1 appended with exclamations is: "   
        << str1e << endl << endl;  
  
   // The sixth member function  
   // appending a range of one string to another  
   string str1f ( "Hello " ), str2f ( "Wide World " );  
   cout << "The string str2f is: " << str2f << endl;  
   str1f.append ( str2f.begin ( ) + 5 , str2f.end ( ) - 1 );  
   cout << "The appended string str1 is: "   
        << str1f << "." << endl << endl;  
}  
```  
  
```Output  
The original string str1 is: Hello   
The C-string cstr1a is: Out There   
Appending the C-string cstr1a to string str1 gives: Hello Out There .  
  
The string str1b is: Hello   
The C-string cstr1b is: Out There   
Appending the 1st part of the C-string cstr1b to string str1 gives: Hello Out.  
  
The string str2c is: Wide World   
The appended string str1 is: Hello World.  
  
The  string str2d is: Wide   
The appended string str1d is: Hello Wide .  
The doubly appended strig str1 is: Hello Wide World .  
  
The string str1 appended with exclamations is: Hello !!!!  
  
The string str2f is: Wide World   
The appended string str1 is: Hello World.  
```  
  
##  <a name="assign"></a>  basic_string::assign  
 Atribui novos valores de caracteres ao conteúdo de uma cadeia de caracteres.  
  
```  
basic_string<CharType, Traits, Allocator>& assign(
    const value_type* ptr);

basic_string<CharType, Traits, Allocator>& assign(
    const value_type* ptr,  
    size_type count);

basic_string<CharType, Traits, Allocator>& assign(
    const basic_string<CharType, Traits, Allocator>& str,  
    size_type off,   
    size_type count);

basic_string<CharType, Traits, Allocator>& assign(
    const basic_string<CharType, Traits, Allocator>& str);

basic_string<CharType, Traits, Allocator>& assign(
    size_type count,   
    value_type _Ch);

template <class InIt>  
basic_string<CharType, Traits, Allocator>& assign(
    InputIterator first,   
    InputIterator last);

basic_string<CharType, Traits, Allocator>& assign(
    const_pointer first,  
    const_pointer last);

basic_string<CharType, Traits, Allocator>& assign(
    const_iterator first,  
    const_iterator last);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ptr`  
 Um ponteiro para os caracteres da cadeia de caracteres do C a serem atribuídos à cadeia de caracteres de destino.  
  
 `count`  
 O número máximo de caracteres a serem acrescentados da cadeia de caracteres de origem.  
  
 `str`  
 A cadeia de caracteres de origem cujos caracteres devem ser atribuídos à cadeia de caracteres de destino.  
  
 `_Ch`  
 O valor do caractere a ser atribuído.  
  
 `first`  
 Um iterador de entrada, const_pointer ou const_iterator, que trata do primeiro caractere no intervalo da cadeia de caracteres de origem a ser atribuído ao intervalo de destino.  
  
 `last`  
 Um iterador de entrada, const_pointer ou const_iterator, que trata do caractere logo após o último caractere no intervalo da cadeia de caracteres de origem a ser atribuído ao intervalo de destino.  
  
 `off`  
 A posição em que novos caracteres começarão a ser atribuídos.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto de cadeia de caracteres ao qual estão sendo atribuídos novos caracteres pela função membro.  
  
### <a name="remarks"></a>Comentários  
 Podem ser atribuídos novos valores de caractere às cadeias de caracteres. O novo valor pode ser uma cadeia de caracteres e uma cadeia de caracteres do C ou um único caractere. O [operator=](#op_eq) poderá ser usado se o novo valor puder ser descrito por um único parâmetro, caso contrário, a função membro **assign**, que tem vários parâmetros, poderá ser usada para especificar qual parte da cadeia de caracteres deverá ser atribuída a uma cadeia de caracteres de destino.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_assign.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
  
   // The first member function assigning the  
   // characters of a C-string to a string  
   string str1a;  
   const char *cstr1a = "Out There";  
   cout << "The C-string cstr1a is: " << cstr1a <<  "." << endl;  
   str1a.assign ( cstr1a );  
   cout << "Assigning the C-string cstr1a to string str1 gives: "   
        << str1a << "." << endl << endl;  
  
   // The second member function assigning a specific  
   // number of the of characters a C-string to a string  
   string  str1b;  
   const char *cstr1b = "Out There";  
   cout << "The C-string cstr1b is: " << cstr1b << endl;  
   str1b.assign ( cstr1b , 3 );  
   cout << "Assigning the 1st part of the C-string cstr1b "  
        << "to string str1 gives: " << str1b << "."   
        << endl << endl;  
  
   // The third member function assigning a specific number  
   // of the characters from one string to another string   
   string str1c ( "Hello " ), str2c ( "Wide World " );  
   cout << "The string str2c is: " << str2c << endl;  
   str1c.assign ( str2c , 5 , 5 );  
   cout << "The newly assigned string str1 is: "   
        << str1c << "." << endl << endl;  
  
   // The fourth member function assigning the characters  
   // from one string to another string in two equivalent  
   // ways, comparing the assign and operator =  
   string str1d ( "Hello" ), str2d ( "Wide" ), str3d ( "World" );  
   cout << "The original string str1 is: " << str1d << "." << endl;  
   cout << "The string str2d is: " << str2d << endl;  
   str1d.assign ( str2d );  
   cout << "The string str1 newly assigned with string str2d is: "   
        << str1d << "." << endl;  
   cout << "The string str3d is: " << str3d << "." << endl;  
   str1d = str3d;  
   cout << "The string str1 reassigned with string str3d is: "   
        << str1d << "." << endl << endl;  
  
   // The fifth member function assigning a specific   
   // number of characters of a certain value to a string  
   string str1e ( "Hello " );  
   str1e.assign ( 4 , '!' );  
   cout << "The string str1 assigned with eclamations is: "   
        << str1e << endl << endl;  
  
   // The sixth member function assigning the value from  
   // the range of one string to another string  
   string str1f ( "Hello " ), str2f ( "Wide World " );  
   cout << "The string str2f is: " << str2f << endl;  
   str1f.assign ( str2f.begin ( ) + 5 , str2f.end ( ) - 1 );  
   cout << "The string str1 assigned a range of string str2f is: "   
        << str1f << "." << endl << endl;  
}  
```  
  
```Output  
The C-string cstr1a is: Out There.  
Assigning the C-string cstr1a to string str1 gives: Out There.  
  
The C-string cstr1b is: Out There  
Assigning the 1st part of the C-string cstr1b to string str1 gives: Out.  
  
The string str2c is: Wide World   
The newly assigned string str1 is: World.  
  
The original string str1 is: Hello.  
The string str2d is: Wide  
The string str1 newly assigned with string str2d is: Wide.  
The string str3d is: World.  
The string str1 reassigned with string str3d is: World.  
  
The string str1 assigned with eclamations is: !!!!  
  
The string str2f is: Wide World   
The string str1 assigned a range of string str2f is: World.  
```  
  
##  <a name="at"></a>  basic_string::at  
 Fornece uma referência ao caractere com um índice especificado em uma cadeia de caracteres.  
  
```  
const_reference at(size_type _Off) const;

 
reference at(size_type _Off);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Off`  
 O índice da posição do elemento a ser referenciado.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao caractere da cadeia de caracteres na posição especificada pelo índice de parâmetro.  
  
### <a name="remarks"></a>Comentários  
 O primeiro elemento da cadeia de caracteres tem um índice de zero e os seguintes elementos são indexados consecutivamente por números inteiros positivos, para que uma cadeia de caracteres de comprimento *n* tem um *n*elemento th indexado pelo número *n -* 1.  
  
 O membro [operator&#91;&#93;](#op_at) é mais rápido que a função membro **at** para fornecer acesso de leitura e gravação aos elementos de uma cadeia de caracteres.  
  
 O membro `operator[]` não verifica se o índice passado como um parâmetro é válido, mas a função membro **at** verifica e, portanto, ela deverá ser usada se a validade não for garantida. Um índice inválido, que é um índice menor que zero ou maior ou igual ao tamanho da cadeia de caracteres, passado para a função membro **at** gera uma exceção da [Classe out_of_range](../standard-library/out-of-range-class.md). Um índice inválido passado para o `operator[]` resulta em um comportamento indefinido, mas o índice igual ao comprimento da cadeia de caracteres é um índice válido para cadeias de caracteres const e o operador retorna o caractere nulo quando esse índice é passado.  
  
 A referência retornada pode ser invalidada por realocações ou modificações das cadeias de caracteres que não são **const**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_at.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   string str1 ( "Hello world" ), str2 ( "Goodbye world" );  
   const string  cstr1 ( "Hello there" ), cstr2 ( "Goodbye now" );  
   cout << "The original string str1 is: " << str1 << endl;  
   cout << "The original string str2 is: " << str2 << endl;  
  
   // Element access to the non const strings  
   basic_string <char>::reference refStr1 = str1 [6];  
   basic_string <char>::reference refStr2 = str2.at ( 3 );  
  
   cout << "The character with an index of 6 in string str1 is: "  
        << refStr1 << "." << endl;  
   cout << "The character with an index of 3 in string str2 is: "  
        << refStr2 << "." << endl;  
  
   // Element access to the const strings  
   basic_string <char>::const_reference crefStr1 = cstr1 [ cstr1.length ( ) ];  
   basic_string <char>::const_reference crefStr2 = cstr2.at ( 8 );  
  
   if ( crefStr1 == '\0' )  
      cout << "The null character is returned as a valid reference."  
           << endl;  
   else  
      cout << "The null character is not returned." << endl;  
   cout << "The character with index 8 in the const string cstr2 is: "  
        << crefStr2 << "." << endl;  
}  
```  
  
##  <a name="back"></a>  basic_string::back  
 Retorna uma referência ao último elemento na cadeia de caracteres.  
  
```  
const_reference back() const;

 
reference back();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao último elemento da cadeia de caracteres, que não deve ser vazio.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="basic_string"></a>  basic_string::basic_string  
 Constrói uma cadeia de caracteres que é vazia, inicializada por caracteres específicos ou uma cópia total ou parcial de outro objeto de cadeia de caracteres ou de cadeia de caracteres do estilo C (terminadas em nulo).  
  
```  
basic_string();

explicit basic_string(
    const allocator_type& _Al);

basic_string(
    const basic_string& right);

basic_string(
    basic_string&& right);

basic_string(
    const basic_string& right,   
    size_type _Roff,  
    size_type count = npos);

basic_string(
    const basic_string& right,   
    size_type _Roff,  
    size_type count,   
    const allocator_type& _Al);

basic_string(
    const value_type* ptr,   
    size_type count);

basic_string(
    const value_type* ptr,   
    size_type count,  
    const allocator_type& _Al);

basic_string(
    const value_type* ptr);

basic_string(
    const value_type* ptr,  
    const allocator_type& _Al);

basic_string(
    size_type count,   
    value_type _Ch);

basic_string(
    size_type count,   
    value_type _Ch,  
    const allocator_type& _Al);

template <class InputIterator>  
basic_string(
 InputIterator first,   
    InputIterator last);

template <class InputIterator>  
basic_string(
 InputIterator first,   
    InputIterator last,   
    const allocator_type& _Al);

basic_string(
    const_pointer first,  
    const_pointer last);

basic_string(
    const_iterator first,  
    const_iterator last);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ptr`  
 A cadeia de caracteres do C cujos caracteres devem ser usados para inicializar a `string` que está sendo construída. Esse valor não pode ser um ponteiro nulo.  
  
 `_Al`  
 A classe do alocador de armazenamento para o objeto de cadeia de caracteres que está sendo criado.  
  
 `count`  
 O número de caracteres a serem inicializados.  
  
 `right`  
 A cadeia de caracteres para inicializar a cadeia de caracteres que está sendo construída.  
  
 `_Roff`  
 O índice de um caractere em uma cadeia de caracteres que será o primeiro a ser usado para inicializar os valores de caracteres para a cadeia de caracteres que está sendo construída.  
  
 `_Ch`  
 O valor de caractere a ser copiado para a cadeia de caracteres que está sendo construída.  
  
 `first`  
 Um iterador de entrada, const_pointer ou const_iterator, que trata do primeiro elemento no intervalo de origem a ser inserido.  
  
 `last`  
 Um iterador de entrada, const_pointer ou const_iterator, que trata da posição logo após o último elemento no intervalo de origem a ser inserido.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto de cadeia de caracteres que está sendo construído pelos construtores.  
  
### <a name="remarks"></a>Comentários  
 Todos os construtores armazenam um [basic_string::allocator_type](#allocator_type) e inicializam a sequência controlada. O objeto alocador será o argumento `al`, se estiver presente. Para o construtor de cópia, ele é `right.`[basic_string::get_allocator](#get_allocator)`()`. Caso contrário, será `Alloc()`.  
  
 A sequência controlada é inicializada para uma cópia da sequência de operandos especificada pelos operandos restantes. Um construtor sem uma sequência de operandos especifica uma sequência controlada inicial vazia. Se `InputIterator` for um tipo inteiro em um construtor de modelo, a sequência de operandos _F `irst,  last` se comportará como `(size_type) first, (value_type) last`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_ctor.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   // The first member function initializing with a C-string  
   const char *cstr1a = "Hello Out There.";  
   basic_string <char> str1a ( cstr1a , 5);  
   cout << "The string initialized by C-string cstr1a is: "  
        << str1a << "." << endl;  
  
   // The second member function initializing with a string  
   string  str2a ( "How Do You Do" );  
   basic_string <char> str2b ( str2a , 7 , 7 );  
   cout << "The string initialized by part of the string cstr2a is: "  
        << str2b << "." << endl;  
  
   // The third member function initializing a string  
   // with a number of characters of a specific value  
   basic_string <char> str3a ( 5, '9' );  
   cout << "The string initialized by five number 9s is: "  
        << str3a << endl;  
  
   // The fourth member function creates an empty string  
   // and string with a specified allocator  
   basic_string <char> str4a;  
   string str4b;  
   basic_string <char> str4c ( str4b.get_allocator( ) );  
   if (str4c.empty ( ) )  
      cout << "The string str4c is empty." << endl;  
   else  
      cout << "The string str4c is not empty." << endl;  
  
   // The fifth member function initializes a string from  
   // another range of characters  
   string str5a ( "Hello World" );  
   basic_string <char> str5b ( str5a.begin ( ) + 5 , str5a.end ( ) );  
   cout << "The string initialized by another range is: "  
        << str5b << "." << endl;  
}  
```  
  
##  <a name="begin"></a>  basic_string::begin  
 Retorna um iterador que trata o primeiro elemento na cadeia de caracteres.  
  
```  
const_iterator begin() const;

 
iterator begin();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório que trata do primeiro elemento da sequência ou logo após o fim de uma sequência vazia.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_begin.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( ) {  
   using namespace std;  
   string str1 ( "No way out." ), str2;  
   basic_string <char>::iterator strp_Iter, str1_Iter, str2_Iter;  
   basic_string <char>::const_iterator str1_cIter;  
  
   str1_Iter = str1.begin ( );  
   cout << "The first character of the string str1 is: "   
        << *str1_Iter << endl;  
   cout << "The full original string str1 is: " << str1 << endl;  
  
   // The dereferenced iterator can be used to modify a character  
 *str1_Iter = 'G';  
   cout << "The first character of the modified str1 is now: "   
        << *str1_Iter << endl;  
   cout << "The full modified string str1 is now: " << str1 << endl;  
  
   // The following line would be an error because iterator is const  
   // *str1_cIter = 'g';  
  
   // For an empty string, begin is equivalent to end  
   if (  str2.begin ( ) == str2.end ( ) )  
      cout << "The string str2 is empty." << endl;  
   else  
      cout << "The string str2 is not empty." << endl;  
}  
```  
  
##  <a name="c_str"></a>  basic_string::c_str  
 Converte o conteúdo de uma cadeia de caracteres em uma cadeia de caracteres do estilo C, terminada em nulo.  
  
```  
const value_type *c_str() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a versão do estilo C da cadeia de caracteres de invocação.  O valor do ponteiro não é válido depois de chamar uma função não const, incluindo o destruidor, na classe basic_string no objeto.  
  
### <a name="remarks"></a>Comentários  
 Os objetos do tipo cadeia de caracteres que pertencem à classe de modelo basic_string\<char> do C++ não são necessariamente terminados em nulo. O caractere nulo '\0' é usado como um caractere especial em uma cadeia de caracteres do C para marcar o fim da cadeia de caracteres, mas não tem nenhum significado especial em um objeto do tipo cadeia de caracteres e pode ser uma parte da cadeia de caracteres, assim como qualquer outro caractere. Há uma conversão automática de **char\*** const em cadeias de caracteres, mas a classe de cadeia de caracteres não fornece conversões automáticas de cadeias de caracteres do estilo C em objetos do tipo **basic_string\<char>**.  
  
 A cadeia de caracteres do estilo C retornada não deve ser modificada, pois isso poderia invalidar o ponteiro para a cadeia de caracteres, nem excluída, pois a cadeia de caracteres tem um tempo de vida limitado e pertence à classe de cadeia de caracteres.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_c_str.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
  
   string  str1 ( "Hello world" );  
   cout << "The original string object str1 is: "   
        << str1 << endl;  
   cout << "The length of the string object str1 = "   
        << str1.length ( ) << endl << endl;  
  
   // Converting a string to an array of characters  
   const char *ptr1 = 0;  
   ptr1= str1.data ( );  
   cout << "The modified string object ptr1 is: " << ptr1   
        << endl;  
   cout << "The length of character array str1 = "   
        << strlen ( ptr1) << endl << endl;  
  
   // Converting a string to a C-style string  
   const char *c_str1 = str1.c_str ( );  
   cout << "The C-style string c_str1 is: " << c_str1   
        << endl;  
   cout << "The length of C-style string str1 = "   
        << strlen ( c_str1) << endl << endl;  
}  
```  
  
```Output  
The original string object str1 is: Hello world  
The length of the string object str1 = 11  
  
The modified string object ptr1 is: Hello world  
The length of character array str1 = 11  
  
The C-style string c_str1 is: Hello world  
The length of C-style string str1 = 11  
```  
  
##  <a name="capacity"></a>  basic_string::capacity  
 Retorna o maior número de elementos que podem ser armazenados em uma cadeia de caracteres sem aumentar a alocação de memória da cadeia.  
  
```  
size_type capacity() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho de armazenamento alocado atualmente na memória para manter a cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o armazenamento alocado no momento para manter a sequência controlada, um valor pelo menos do tamanho de [size](#size).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_capacity.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   string  str1 ("Hello world");  
   cout << "The original string str1 is: " << str1 << endl;  
  
   // The size and length member functions differ in name only  
   basic_string <char>::size_type sizeStr1, lenStr1;  
   sizeStr1 = str1.size ( );  
   lenStr1 = str1.length ( );  
  
   basic_string <char>::size_type capStr1, max_sizeStr1;  
   capStr1 = str1.capacity ( );  
   max_sizeStr1 = str1.max_size ( );  
  
   // Compare size, length, capacity & max_size of a string  
   cout << "The current size of original string str1 is: "   
        << sizeStr1 << "." << endl;  
   cout << "The current length of original string str1 is: "   
        << lenStr1 << "." << endl;  
   cout << "The capacity of original string str1 is: "  
        << capStr1 << "." << endl;  
   cout << "The max_size of original string str1 is: "   
        << max_sizeStr1 << "." << endl << endl;  
  
   str1.erase ( 6, 5 );  
   cout << "The modified string str1 is: " << str1 << endl;  
  
   sizeStr1 = str1.size (  );  
   lenStr1 = str1.length (  );  
   capStr1 = str1.capacity (  );  
   max_sizeStr1 = str1.max_size (  );  
  
   // Compare size, length, capacity & max_size of a string  
   // after erasing part of the original string  
   cout << "The current size of modified string str1 is: "   
        << sizeStr1 << "." << endl;  
   cout << "The current length of modified string str1 is: "   
        << lenStr1 << "." << endl;  
   cout << "The capacity of modified string str1 is: "  
        << capStr1 << "." << endl;  
   cout << "The max_size of modified string str1 is: "   
        << max_sizeStr1 << "." << endl;  
}  
```  
  
##  <a name="cbegin"></a>  basic_string::cbegin  
 Retorna um iterador `const` que trata o primeiro elemento no intervalo.  
  
```  
const_iterator cbegin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório `const` que aponta o primeiro elemento do intervalo ou o local logo após o fim de um intervalo vazio (para um intervalo vazio, `cbegin() == cend()`).  
  
### <a name="remarks"></a>Comentários  
 Com o valor de retorno `cbegin`, os elementos do intervalo não podem ser modificados.  
  
 Você pode usar essa função membro no lugar da função membro `begin()`, de modo a garantir que o valor de retorno seja `const_iterator`. Normalmente, é usada juntamente com a palavra-chave de dedução de tipo [auto](../cpp/auto-cpp.md), conforme mostrado no exemplo a seguir. No exemplo, considere `Container` como um contêiner modificável (não `const`) de qualquer tipo, que dá suporte para `begin()` e `cbegin()`.  
  
```cpp  
auto i1 = Container.begin();
// i1 is Container<T>::iterator   
auto i2 = Container.cbegin();

// i2 is Container<T>::const_iterator  
```  
  
##  <a name="cend"></a>  basic_string::cend  
 Retorna um iterador `const` que trata o local logo após o último elemento em um intervalo.  
  
```  
const_iterator cend() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório `const` que aponta para além do fim do intervalo.  
  
### <a name="remarks"></a>Comentários  
 `cend` é usado para testar se um iterador passou do fim de seu intervalo.  
  
 Você pode usar essa função membro no lugar da função membro `end()`, de modo a garantir que o valor de retorno seja `const_iterator`. Normalmente, é usada juntamente com a palavra-chave de dedução de tipo [auto](../cpp/auto-cpp.md), conforme mostrado no exemplo a seguir. No exemplo, considere `Container` como um contêiner modificável (não `const`) de qualquer tipo, que dá suporte para `end()` e `cend()`.  
  
```cpp  
auto i1 = Container.end();
// i1 is Container<T>::iterator   
auto i2 = Container.cend();

// i2 is Container<T>::const_iterator  
```  
  
 O valor retornado por `cend` não deve ser desreferenciado.  
  
##  <a name="clear"></a>  basic_string::clear  
 Apaga todos os elementos de uma cadeia de caracteres.  
  
```  
void clear();
```  
  
### <a name="remarks"></a>Comentários  
 A cadeia de caracteres na qual a função membro é chamada estará vazia.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_clear.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   string  str1 ("Hello world"), str2;  
   basic_string <char>::iterator str_Iter;  
   cout << "The original string str1 is: ";  
   for ( str_Iter = str1.begin( ); str_Iter != str1.end( ); str_Iter++ )  
      cout << *str_Iter;  
   cout << endl;  
  
   str1.clear ( );  
   cout << "The modified string str1 is: ";  
   for ( str_Iter = str1.begin( ); str_Iter != str1.end( ); str_Iter++ )  
      cout << *str_Iter;  
   cout << endl;  
  
   //For an empty string, begin is equivalent to end  
   if ( str1.begin ( ) == str1.end ( ) )  
      cout << "Nothing printed above because "  
           << "the string str1 is empty." << endl;  
   else  
      cout << "The string str1 is not empty." << endl;  
}  
```  
  
```Output  
The original string str1 is: Hello world  
The modified string str1 is:   
Nothing printed above because the string str1 is empty.  
```  
  
##  <a name="compare"></a>  basic_string::compare  
 Executa uma comparação que diferencia maiúsculas de minúsculas com uma cadeia de caracteres especificada para determinar se as duas cadeias de caracteres são iguais ou se uma é lexicograficamente menor que a outra.  
  
```  
int compare(
    const basic_string<CharType, Traits, Allocator>& str) const;

 
int compare(
    size_type _Pos1,   
    size_type _Num1,  
    const basic_string<CharType, Traits, Allocator>& str) const;

 
int compare(
    size_type _Pos1,  
    size_type _Num1,  
    const basic_string<CharType, Traits, Allocator>& str,   
    size_type _Off,   
    size_type count) const;

 
int compare(
    const value_type* ptr) const;

 
int compare(
    size_type _Pos1,  
    size_type _Num1,  
    const value_type* ptr) const;

 
int compare(
    size_type _Pos1,  
    size_type _Num1,  
    const value_type* ptr  
    size_type _Num2) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 A cadeia de caracteres que deve ser comparada com a cadeia de caracteres do operando.  
  
 `_Pos1`  
 O índice da cadeia de caracteres do operando na qual a comparação começa.  
  
 `_Num1`  
 O número máximo de caracteres da cadeia de caracteres do operando a serem comparados.  
  
 `_Num2`  
 O número máximo de caracteres da cadeia de caracteres do parâmetro a serem comparados.  
  
 `_Off`  
 O índice da cadeia de caracteres do parâmetro na qual a comparação começa.  
  
 `count`  
 O número máximo de caracteres da cadeia de caracteres do parâmetro a serem comparados.  
  
 `ptr`  
 A cadeia de caracteres do C a ser comparada com a cadeia de caracteres do operando.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor negativo, se a cadeia de caracteres do operando for menor que a cadeia de caracteres do parâmetro, zero, se as duas cadeias de caracteres forem iguais ou um valor positivo se a cadeia de caracteres do operando for maior que a cadeia de caracteres do parâmetro.  
  
### <a name="remarks"></a>Comentários  
 As funções membro **compare** fazem uma comparação total ou parcial das cadeias de caracteres do parâmetro e do operando, dependendo de qual é usado.  
  
 A comparação executada diferencia maiúsculas de minúsculas.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_compare.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
  
   // The first member function compares  
   // an operand string to a parameter string  
   int comp1;  
   string s1o ( "CAB" );  
   string s1p ( "CAB" );  
   cout << "The operand string is: " << s1o << endl;  
   cout << "The parameter string is: " << s1p << endl;  
   comp1 = s1o.compare ( s1p );  
   if ( comp1 < 0 )  
      cout << "The operand string is less than "  
           << "the parameter string." << endl;  
   else if ( comp1 == 0 )  
      cout << "The operand string is equal to "  
           << "the parameter string." << endl;  
   else  
      cout << "The operand string is greater than "  
           << "the parameter string." << endl;  
   cout << endl;  
  
   // The second member function compares part of  
   // an operand string to a parameter string  
   int comp2a, comp2b;  
   string s2o ( "AACAB" );  
   string s2p ( "CAB" );  
   cout << "The operand string is: " << s2o << endl;  
   cout << "The parameter string is: " << s2p << endl;  
   comp2a = s2o.compare (  2 , 3 , s2p );  
   if ( comp2a < 0 )  
      cout << "The last three characters of "  
           << "the operand string\n are less than "  
           << "the parameter string." << endl;  
   else if ( comp2a == 0 )  
      cout << "The last three characters of "  
           << "the operand string\n are equal to "  
           << "the parameter string." << endl;  
   else  
      cout << "The last three characters of "  
           << "the operand string\n is greater than "  
           << "the parameter string." << endl;  
  
   comp2b = s2o.compare (  0 , 3 , s2p );  
   if ( comp2b < 0 )  
      cout << "The first three characters of "  
           << "the operand string\n are less than "  
           << "the parameter string." << endl;  
   else if ( comp2b == 0 )  
      cout << "The first three characters of "  
           << "the operand string\n are equal to "  
           << "the parameter string." << endl;  
   else  
      cout << "The first three characters of "  
           << "the operand string\n is greater than "  
           << "the parameter string." << endl;  
   cout << endl;  
  
   // The third member function compares part of  
   // an operand string to part of a parameter string  
   int comp3a;  
   string s3o ( "AACAB" );  
   string s3p ( "DCABD" );  
   cout << "The operand string is: " << s3o << endl;  
   cout << "The parameter string is: " << s3p << endl;  
   comp3a = s3o.compare (  2 , 3 , s3p , 1 , 3 );  
   if ( comp3a < 0 )  
      cout << "The three characters from position 2 of "  
           << "the operand string are less than\n "  
           << "the 3 characters parameter string "   
           << "from position 1." << endl;  
   else if ( comp3a == 0 )  
      cout << "The three characters from position 2 of "  
           << "the operand string are equal to\n "  
           << "the 3 characters parameter string "   
           << "from position 1." << endl;  
   else  
      cout << "The three characters from position 2 of "  
           << "the operand string is greater than\n "  
           << "the 3 characters parameter string "   
           << "from position 1." << endl;  
   cout << endl;  
  
   // The fourth member function compares  
   // an operand string to a parameter C-string  
   int comp4a;  
   string s4o ( "ABC" );  
   const char* cs4p = "DEF";  
   cout << "The operand string is: " << s4o << endl;  
   cout << "The parameter C-string is: " << cs4p << endl;  
   comp4a = s4o.compare ( cs4p );  
   if ( comp4a < 0 )  
      cout << "The operand string is less than "  
           << "the parameter C-string." << endl;  
   else if ( comp4a == 0 )  
      cout << "The operand string is equal to "  
           << "the parameter C-string." << endl;  
   else  
      cout << "The operand string is greater than "  
           << "the parameter C-string." << endl;  
   cout << endl;  
  
   // The fifth member function compares part of  
   // an operand string to a parameter C-string  
   int comp5a;  
   string s5o ( "AACAB" );  
   const char* cs5p = "CAB";  
   cout << "The operand string is: " << s5o << endl;  
   cout << "The parameter string is: " << cs5p << endl;  
   comp5a = s5o.compare (  2 , 3 , s2p );  
   if ( comp5a < 0 )  
      cout << "The last three characters of "  
           << "the operand string\n are less than "  
           << "the parameter C-string." << endl;  
   else if ( comp5a == 0 )  
      cout << "The last three characters of "  
           << "the operand string\n are equal to "  
           << "the parameter C-string." << endl;  
   else  
      cout << "The last three characters of "  
           << "the operand string\n is greater than "  
           << "the parameter C-string." << endl;  
   cout << endl;  
  
   // The sixth member function compares part of  
   // an operand string to part of an equal length of  
   // a parameter C-string  
   int comp6a;  
   string s6o ( "AACAB" );  
   const char* cs6p = "ACAB";  
   cout << "The operand string is: " << s6o << endl;  
   cout << "The parameter C-string is: " << cs6p << endl;  
   comp6a = s6o.compare (  1 , 3 , cs6p , 3 );  
   if ( comp6a < 0 )  
      cout << "The 3 characters from position 1 of "  
           << "the operand string are less than\n "  
           << "the first 3 characters of the parameter C-string."   
           << endl;  
   else if ( comp6a == 0 )  
      cout << "The 3 characters from position 2 of "  
           << "the operand string are equal to\n "  
           << "the first 3 characters of the parameter C-string."   
           <<  endl;  
   else  
      cout << "The 3 characters from position 2 of "  
           << "the operand string is greater than\n "  
           << "the first 3 characters of the parameter C-string."   
           << endl;  
   cout << endl;  
}  
```  
  
```Output  
The operand string is: CAB  
The parameter string is: CAB  
The operand string is equal to the parameter string.  
  
The operand string is: AACAB  
The parameter string is: CAB  
The last three characters of the operand string  
 are equal to the parameter string.  
The first three characters of the operand string  
 are less than the parameter string.  
  
The operand string is: AACAB  
The parameter string is: DCABD  
The three characters from position 2 of the operand string are equal to  
 the 3 characters parameter string from position 1.  
  
The operand string is: ABC  
The parameter C-string is: DEF  
The operand string is less than the parameter C-string.  
  
The operand string is: AACAB  
The parameter string is: CAB  
The last three characters of the operand string  
 are equal to the parameter C-string.  
  
The operand string is: AACAB  
The parameter C-string is: ACAB  
The 3 characters from position 2 of the operand string are equal to  
 the first 3 characters of the parameter C-string.  
```  
  
##  <a name="const_iterator"></a>  basic_string::const_iterator  
 Um tipo que fornece um iterador de acesso aleatório que pode acessar e ler um elemento **const** na cadeia de caracteres.  
  
```  
typedef implementation-defined const_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo `const_iterator` não pode ser usado para modificar o valor de um caractere e é usado para iterar em uma cadeia de caracteres em uma direção progressiva.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [begin](#begin) para obter um exemplo de como declarar e usar `const_iterator`.  
  
##  <a name="const_pointer"></a>  basic_string::const_pointer  
 Um tipo que fornece um ponteiro para um elemento **const** em uma cadeia de caracteres.  
  
```  
typedef typename allocator_type::const_pointer const_pointer;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo de **allocator_type::const_pointer**.  
  
 Para o tipo **string**, é equivalente a `char`*.  
  
 Os ponteiros declarados como const devem ser inicializados quando são declarados. Os Ponteiros const sempre apontam para o mesmo local da memória e podem apontar para dados constantes ou não constantes.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_const_ptr.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   basic_string<char>::const_pointer pstr1a = "In Here";  
   const char *cstr1c = "Out There";  
  
   cout << "The string pstr1a is: " << pstr1a <<  "." << endl;  
   cout << "The C-string cstr1c is: " << cstr1c << "." << endl;  
}  
```  
  
```Output  
The string pstr1a is: In Here.  
The C-string cstr1c is: Out There.  
```  
  
##  <a name="const_reference"></a>  basic_string::const_reference  
 Um tipo que fornece uma referência a um elemento **const** armazenado em uma cadeia de caracteres para leitura e execução de operações **const**.  
  
```  
typedef typename allocator_type::const_reference const_reference;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo de `const_reference` não pode ser usado para modificar o valor de um elemento.  
  
 O tipo é um sinônimo de **allocator_type::const_reference**. Para a cadeia de caracteres **type**, é equivalente a **char&** const.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [at](#at) que demonstra como declarar e usar `const_reference`.  
  
##  <a name="const_reverse_iterator"></a>  basic_string::const_reverse_iterator  
 Um tipo que fornece um iterador de acesso aleatório que pode ler qualquer elemento **const** na cadeia de caracteres.  
  
```  
typedef std::reverse_iterator<const_iterator> const_reverse_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo `const_reverse_iterator` não pode modificar o valor de um caractere e é usado para iterar em uma cadeia de caracteres na ordem inversa.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [rbegin](#rbegin) que demonstra como declarar e usar `const_reverse_iterator`.  
  
##  <a name="copy"></a>  basic_string::copy  
 Copia, no máximo, um número específico de caracteres de uma posição indexada em uma cadeia de caracteres de origem em um conjunto de caracteres de destino.  
  
 Esse método pode não ser seguro, pois depende do chamador para verificar se os valores passados estão corretos. Considere o uso de [basic_string::_Copy_s](#copy_s) em seu lugar.  
  
```  
size_type copy(
    value_type* ptr,   
    size_type count,  
    size_type _Off = 0) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `ptr`  
 A matriz de caracteres de destino à qual os elementos devem ser copiados.  
  
 _ `Count`  
 O número máximo de caracteres a serem copiados da cadeia de caracteres de origem.  
  
 `_Off`  
 A posição inicial na cadeia de caracteres de origem da qual as cópias devem ser feitas.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de caracteres realmente copiados.  
  
### <a name="remarks"></a>Comentários  
 Um caractere nulo não é acrescentado ao final da cópia.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_copy.cpp  
// compile with: /EHsc /W3  
#include <string>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   string str1 ( "Hello World" );  
   basic_string <char>::iterator str_Iter;  
   char array1 [ 20 ] = { 0 };  
   char array2 [ 10 ] = { 0 };  
   basic_string <char>:: pointer array1Ptr = array1;  
   basic_string <char>:: value_type *array2Ptr = array2;  
  
   cout << "The original string str1 is: ";  
   for ( str_Iter = str1.begin( ); str_Iter != str1.end( ); str_Iter++ )  
      cout << *str_Iter;  
   cout << endl;  
  
   basic_string <char>:: size_type nArray1;  
   // Note: string::copy is potentially unsafe, consider  
   // using string::_Copy_s instead.  
   nArray1 = str1.copy ( array1Ptr , 12 );  // C4996  
   cout << "The number of copied characters in array1 is: "  
        << nArray1 << endl;  
   cout << "The copied characters array1 is: " << array1 << endl;  
  
   basic_string <char>:: size_type nArray2;  
   // Note: string::copy is potentially unsafe, consider  
   // using string::_Copy_s instead.  
   nArray2 = str1.copy ( array2Ptr , 5 , 6  );  // C4996  
   cout << "The number of copied characters in array2 is: "  
           << nArray2 << endl;  
   cout << "The copied characters array2 is: " << array2Ptr << endl;  
}  
```  
  
```Output  
The original string str1 is: Hello World  
The number of copied characters in array1 is: 11  
The copied characters array1 is: Hello World  
The number of copied characters in array2 is: 5  
The copied characters array2 is: World  
```  
  
##  <a name="crbegin"></a>  basic_string::crbegin  
 Retorna um iterador const que trata o primeiro elemento em uma cadeia de caracteres invertida.  
  
```  
const_reverse_iterator crbegin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador inverso que aponta para logo após o fim da cadeia de caracteres. A posição designa o início da cadeia de caracteres inversa.  
  
##  <a name="crend"></a>  basic_string::crend  
 Retorna um iterador const que trata o local após o último elemento em uma cadeia invertida.  
  
```  
const_reverse_iterator crend() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador const inverso que trata do local logo após o último elemento em uma cadeia de caracteres invertida (o local que precedia o primeiro elemento na cadeia de caracteres não invertida).  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="copy_s"></a>  basic_string::_Copy_s  
 Copia, no máximo, um número específico de caracteres de uma posição indexada em uma cadeia de caracteres de origem em um conjunto de caracteres de destino.  
  
```  
size_type _Copy_s(
    value_type* dest,  
    size_type dest_size,  
    size_type count,  
    size_type _Off = 0) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `dest`  
 A matriz de caracteres de destino à qual os elementos devem ser copiados.  
  
 `dest_size`  
 O tamanho do `dest`.  
  
 _ `Count`  
 O número máximo de caracteres a serem copiados da cadeia de caracteres de origem.  
  
 `_Off`  
 A posição inicial na cadeia de caracteres de origem da qual as cópias devem ser feitas.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de caracteres realmente copiados.  
  
### <a name="remarks"></a>Comentários  
 Um caractere nulo não é acrescentado ao final da cópia.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string__Copy_s.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )  
{  
    using namespace std;  
    string str1("Hello World");  
    basic_string<char>::iterator str_Iter;  
    const int array1_size = 20;  
    char array1[array1_size] = { 0 };  
    const int array2_size = 10;  
    char array2[array2_size] = { 0 };  
    basic_string<char>:: pointer array1Ptr = array1;  
    basic_string<char>:: value_type *array2Ptr = array2;  
  
    cout << "The original string str1 is: ";  
    for (str_Iter = str1.begin(); str_Iter != str1.end(); str_Iter++)  
        cout << *str_Iter;  
    cout << endl;  
  
    basic_string<char>::size_type nArray1;  
    nArray1 = str1._Copy_s(array1Ptr, array1_size, 12);  
    cout << "The number of copied characters in array1 is: "  
         << nArray1 << endl;  
    cout << "The copied characters array1 is: " << array1 << endl;  
  
    basic_string<char>:: size_type nArray2;  
    nArray2 = str1._Copy_s(array2Ptr, array2_size, 5, 6);  
    cout << "The number of copied characters in array2 is: "  
         << nArray2 << endl;  
    cout << "The copied characters array2 is: " << array2Ptr << endl;  
}  
```  
  
```Output  
The original string str1 is: Hello World  
The number of copied characters in array1 is: 11  
The copied characters array1 is: Hello World  
The number of copied characters in array2 is: 5  
The copied characters array2 is: World  
```  
  
##  <a name="data"></a>  basic_string::data  
 Converte o conteúdo de uma cadeia de caracteres em uma matriz de caracteres.  
  
```  
const value_type *data() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o primeiro elemento da matriz que contém o conteúdo da cadeia de caracteres ou, para uma matriz vazia, um ponteiro não nulo que não pode ser desreferenciado.  
  
### <a name="remarks"></a>Comentários  
 Os objetos do tipo cadeia de caracteres que pertencem à classe de modelo basic_string \<char> do C++ não são necessariamente terminados em nulo. O tipo de retorno de **data** não é uma cadeia de caracteres do C válida, porque nenhum caractere nulo é acrescentado. O caractere nulo '\0' é usado como um caractere especial em uma cadeia de caracteres do C para marcar o fim da cadeia de caracteres, mas não tem nenhum significado especial em um objeto do tipo cadeia de caracteres e pode ser uma parte do objeto de cadeia de caracteres, assim como qualquer outro caractere.  
  
 Há uma conversão automática de **char\*** const em cadeias de caracteres, mas a classe de cadeia de caracteres não fornece conversões automáticas de cadeias de caracteres de estilo C em objetos do tipo **basic_string \<char>**.  
  
 A cadeia de caracteres retornada não deve ser modificada, pois isso poderia invalidar o ponteiro para a cadeia de caracteres, nem excluída, pois a cadeia de caracteres tem um tempo de vida limitado e pertence à classe de cadeia de caracteres.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_data.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
  
   string str1 ( "Hello world" );  
   cout << "The original string object str1 is: "   
        << str1 << endl;  
   cout << "The length of the string object str1 = "   
        << str1.length ( ) << endl << endl;  
  
   // Converting a string to an array of characters  
   const char *ptr1 = 0;  
   ptr1= str1.data ( );  
   cout << "The modified string object ptr1 is: " << ptr1   
        << endl;  
   cout << "The length of character array str1 = "   
        << strlen ( ptr1) << endl << endl;  
  
   // Converting a string to a C-style string  
   const char *c_str1 = str1.c_str ( );  
   cout << "The C-style string c_str1 is: " << c_str1   
        << endl;  
   cout << "The length of C-style string str1 = "   
        << strlen ( c_str1) << endl << endl;  
}  
```  
  
```Output  
The original string object str1 is: Hello world  
The length of the string object str1 = 11  
  
The modified string object ptr1 is: Hello world  
The length of character array str1 = 11  
  
The C-style string c_str1 is: Hello world  
The length of C-style string str1 = 11  
```  
  
##  <a name="difference_type"></a>  basic_string::difference_type  
 Um tipo que fornece a diferença entre dois iteradores que se referem a elementos na mesma cadeia.  
  
```  
typedef typename allocator_type::difference_type difference_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo inteiro com sinal descreve um objeto que pode representar a diferença entre os endereços de dois elementos quaisquer na sequência controlada.  
  
 Para o tipo **string**, é equivalente a **ptrdiff_t**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_diff_type.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   string str1 ( "quintillion" );  
   cout << "The original string str1 is: " << str1 << endl;  
   basic_string <char>::size_type indexChFi, indexChLi;  
  
   indexChFi = str1.find_first_of ( "i" );  
   indexChLi = str1.find_last_of ( "i" );  
   basic_string<char>::difference_type diffi = indexChLi - indexChFi;  
  
   cout << "The first character i is at position: "  
        << indexChFi << "." << endl;  
   cout << "The last character i is at position: "  
        << indexChLi << "." << endl;  
   cout << "The difference is: " << diffi << "." << endl;  
}  
```  
  
```Output  
The original string str1 is: quintillion  
The first character i is at position: 2.  
The last character i is at position: 8.  
The difference is: 6.  
```  
  
##  <a name="empty"></a>  basic_string::empty  
 Testa se a cadeia de caracteres contém caracteres ou não.  
  
```  
bool empty() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o objeto de cadeia de caracteres não contiver nenhum caractere, **false** se ele tiver pelo menos um caractere.  
  
### <a name="remarks"></a>Comentários  
 A função membro é equivalente a [size](#size) == 0.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_empty.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main() {  
   using namespace std;  
  
   bool b1, b2;  
  
   string str1 ("Hello world");  
   cout << "The original string object str1 is: " << str1 << endl;  
   b1 = str1.empty();  
   if (b1)  
      cout << "The string object str1 is empty." << endl;  
   else  
      cout << "The string object str1 is not empty." << endl;  
   cout << endl;  
  
   // An example of an empty string object  
   string str2;  
   b2 = str2.empty();  
   if (b2)  
      cout << "The string object str2 is empty." << endl;  
   else  
      cout << "The string object str2 is not empty." << endl;  
}  
```  
  
##  <a name="end"></a>  basic_string::end  
 Retorna um iterador que trata o local após o último elemento em uma cadeia de caracteres.  
  
```  
const_iterator end() const;

 
iterator end();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um iterador de acesso aleatório que trata do local após o último elemento em uma cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 **end** geralmente é usado para testar se um iterador atingiu o fim de sua cadeia de caracteres. O valor retornado por **end** não deve ser desreferenciado.  
  
 Se o valor retornado de **end** for atribuído a `const_iterator`, o objeto de cadeia de caracteres não poderá ser modificado. Se o valor retornado **end** for atribuído a um **iterator**, o objeto de cadeia de caracteres poderá ser modificado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_end.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   string str1 ( "No way out." ), str2;  
   basic_string <char>::iterator str_Iter, str1_Iter, str2_Iter;  
   basic_string <char>::const_iterator str1_cIter;  
  
   str1_Iter = str1.end ( );  
   str1_Iter--;  
   str1_Iter--;  
   cout << "The last character-letter of the string str1 is: " << *str1_Iter << endl;  
   cout << "The full orginal string str1 is: " << str1 << endl;  
  
   // end used to test when an iterator has reached the end of its string  
   cout << "The string is now: ";  
   for ( str_Iter = str1.begin( ); str_Iter != str1.end( ); str_Iter++ )  
      cout << *str_Iter;  
   cout << endl;  
  
   // The dereferenced iterator can be used to modify a character  
 *str1_Iter = 'T';  
   cout << "The last character-letter of the modified str1 is now: "  
        << *str1_Iter << endl;  
   cout << "The modified string str1 is now: " << str1 << endl;  
  
   // The following line would be an error because iterator is const  
   // *str1_cIter = 'T';  
  
   // For an empty string, end is equivalent to begin  
   if ( str2.begin( ) == str2.end ( ) )  
      cout << "The string str2 is empty." << endl;  
   else  
      cout << "The stringstr2  is not empty." << endl;  
}  
```  
  
```Output  
The last character-letter of the string str1 is: t  
The full orginal string str1 is: No way out.  
The string is now: No way out.  
The last character-letter of the modified str1 is now: T  
The modified string str1 is now: No way ouT.  
The string str2 is empty.  
```  
  
##  <a name="erase"></a>  basic_string::erase  
 Remove um elemento ou um intervalo de elementos em uma cadeia de caracteres de uma posição especificada.  
  
```  
iterator erase(
    iterator first,   
    iterator last);

iterator erase(
    iterator _It);

basic_string<CharType, Traits, Allocator>& erase(
    size_type _Pos = 0,  
    size_type count = npos);
```  
  
### <a name="parameters"></a>Parâmetros  
 `first`  
 Um iterador que trata da posição do primeiro elemento no intervalo a ser apagado.  
  
 `last`  
 Um iterador que trata da posição logo após o último elemento no intervalo a ser apagado.  
  
 `_It`  
 Um iterador que trata da posição do elemento na cadeia de caracteres a ser apagado.  
  
 `_Pos`  
 O índice do primeiro caractere na cadeia de caracteres a ser removido.  
  
 `count`  
 O número de elementos que serão removidos se houver tantos no intervalo da cadeia de caracteres que comecem com *_Pos*.  
  
### <a name="return-value"></a>Valor de retorno  
 Para as duas primeiras funções membro, um iterador que trata do primeiro caractere após o último caractere removido pela função membro. Para a terceira função membro, uma referência ao objeto de cadeia de caracteres do qual os elementos foram apagados.  
  
### <a name="remarks"></a>Comentários  
 A terceira função membro retorna **\*this**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_erase.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
  
   // The 1st member function using a range demarcated  
   // by iterators  
   string str1 ( "Hello world" );  
   basic_string <char>::iterator str1_Iter;  
   cout << "The original string object str1 is: "   
        << str1 << "." << endl;  
   str1_Iter = str1.erase ( str1.begin ( ) + 3 , str1.end ( ) - 1 );  
   cout << "The first element after those removed is: "  
        << *str1_Iter << "." << endl;  
   cout << "The modified string object str1 is: " << str1   
           << "." << endl << endl;  
  
   // The 2nd member function erasing a char pointed to   
   // by an iterator  
   string str2 ( "Hello World" );  
   basic_string <char>::iterator str2_Iter;  
   cout << "The original string object str2 is: " << str2  
        << "." << endl;  
   str2_Iter = str2.erase ( str2.begin ( ) + 5 );  
   cout << "The first element after those removed is: "  
        << *str2_Iter << "." << endl;  
   cout << "The modified string object str2 is: " << str2   
        << "." << endl << endl;  
  
   // The 3rd member function erasing a number of chars   
   // after a char  
   string str3 ( "Hello computer" ), str3m;  
   basic_string <char>::iterator str3_Iter;  
   cout << "The original string object str3 is: "   
        << str3 << "." << endl;  
   str3m = str3.erase ( 6 , 8 );  
   cout << "The modified string object str3m is: "   
        << str3m << "." << endl;  
}  
```  
  
```Output  
The original string object str1 is: Hello world.  
The first element after those removed is: d.  
The modified string object str1 is: Held.  
  
The original string object str2 is: Hello World.  
The first element after those removed is: W.  
The modified string object str2 is: HelloWorld.  
  
The original string object str3 is: Hello computer.  
The modified string object str3m is: Hello .  
```  
  
##  <a name="find"></a>  basic_string::find  
 Pesquisa, para frente, em uma cadeia de caracteres, a primeira ocorrência de uma subcadeia que corresponde a uma sequência de caracteres especificada.  
  
```  
size_type find(
    value_type _Ch,   
    size_type _Off = 0) const;

 
size_type find(
    const value_type* ptr,  
    size_type _Off = 0) const;

 
size_type find(
    const value_type* ptr,   
    size_type _Off,  
    size_type count) const;

 
size_type find(
    const basic_string<CharType, Traits, Allocator>& str,  
    size_type _Off = 0) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Ch`  
 O valor de caractere que a função membro deve pesquisar.  
  
 `_Off`  
 Índice da posição em que a pesquisa deve começar.  
  
 `ptr`  
 A cadeia de caracteres do C que a função membro deve pesquisar.  
  
 `count`  
 O número de caracteres, contando a partir do primeiro caractere, na cadeia de caracteres do C que a função membro deve pesquisar.  
  
 `str`  
 A cadeia de caracteres que a função membro deve pesquisar.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do primeiro caractere da subsequência pesquisada quando for houver êxito, caso contrário, `npos`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_find.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   // The first member function  
   // searches for a single character in a string  
   string str1 ( "Hello Everyone" );  
   cout << "The original string str1 is: " << str1 << endl;  
   basic_string <char>::size_type indexCh1a, indexCh1b;  
  
   indexCh1a = str1.find ( "e" , 3 );  
   if (indexCh1a != string::npos )  
      cout << "The index of the 1st 'e' found after the 3rd"  
           << " position in str1 is: " << indexCh1a << endl;  
   else  
      cout << "The character 'e' was not found in str1 ." << endl;  
  
   indexCh1b = str1.find ( "x" );  
   if (indexCh1b != string::npos )  
      cout << "The index of the 'x' found in str1 is: "  
           << indexCh1b << endl << endl;  
   else  
      cout << "The Character 'x' was not found in str1."  
           << endl << endl;  
  
   // The second member function searches a string  
   // for a substring as specified by a C-string  
   string str2 ( "Let me make this perfectly clear." );  
   cout << "The original string str2 is: " << str2 << endl;  
   basic_string <char>::size_type indexCh2a, indexCh2b;  
  
   const char *cstr2 = "perfect";  
   indexCh2a = str2.find ( cstr2 , 5 );  
   if ( indexCh2a != string::npos )  
      cout << "The index of the 1st element of 'perfect' "  
           << "after\n the 5th position in str2 is: "  
           << indexCh2a << endl;  
   else  
      cout << "The substring 'perfect' was not found in str2 ."  
           << endl;  
  
   const char *cstr2b = "imperfectly";  
   indexCh2b = str2.find ( cstr2b , 0 );  
   if (indexCh2b != string::npos )  
      cout << "The index of the 1st element of 'imperfect' "  
           << "after\n the 5th position in str3 is: "  
           << indexCh2b << endl;  
   else  
      cout << "The substring 'imperfect' was not found in str2 ."  
           << endl << endl;  
  
   // The third member function searches a string  
   // for a substring as specified by a C-string  
   string str3 ( "This is a sample string for this program" );  
   cout << "The original string str3 is: " << str3 << endl;  
   basic_string <char>::size_type indexCh3a, indexCh3b;  
  
   const char *cstr3a = "sample";  
   indexCh3a = str3.find ( cstr3a );  
   if ( indexCh3a != string::npos )  
      cout << "The index of the 1st element of sample "  
           << "in str3 is: " << indexCh3a << endl;  
   else  
      cout << "The substring 'perfect' was not found in str3 ."  
           << endl;  
  
   const char *cstr3b = "for";  
   indexCh3b = str3.find ( cstr3b , indexCh3a + 1 , 2 );  
   if (indexCh3b != string::npos )  
      cout << "The index of the next occurrence of 'for' is in "  
           << "str3 begins at: " << indexCh3b << endl << endl;  
   else  
      cout << "There is no next occurrence of 'for' in str3 ."  
           << endl << endl;  
  
   // The fourth member function searches a string  
   // for a substring as specified by a string  
   string str4 ( "clearly this perfectly unclear." );  
   cout << "The original string str4 is: " << str4 << endl;  
   basic_string <char>::size_type indexCh4a, indexCh4b;  
  
   string str4a ( "clear" );  
   indexCh4a = str4.find ( str4a , 5 );  
   if ( indexCh4a != string::npos )  
      cout << "The index of the 1st element of 'clear' "  
           << "after\n the 5th position in str4 is: "  
           << indexCh4a << endl;  
   else  
      cout << "The substring 'clear' was not found in str4 ."  
           << endl;  
  
   string str4b ( "clear" );  
   indexCh4b = str4.find ( str4b );  
   if (indexCh4b != string::npos )  
      cout << "The index of the 1st element of 'clear' "  
           << "in str4 is: "  
           << indexCh4b << endl;  
   else  
      cout << "The substring 'clear' was not found in str4 ."  
           << endl << endl;  
}  
```  
  
```Output  
The original string str1 is: Hello Everyone  
The index of the 1st 'e' found after the 3rd position in str1 is: 8  
The Character 'x' was not found in str1.  
  
The original string str2 is: Let me make this perfectly clear.  
The index of the 1st element of 'perfect' after  
 the 5th position in str2 is: 17  
The substring 'imperfect' was not found in str2 .  
  
The original string str3 is: This is a sample string for this program  
The index of the 1st element of sample in str3 is: 10  
The index of the next occurrence of 'for' is in str3 begins at: 24  
  
The original string str4 is: clearly this perfectly unclear.  
The index of the 1st element of 'clear' after  
 the 5th position in str4 is: 25  
The index of the 1st element of 'clear' in str4 is: 0  
```  
  
##  <a name="find_first_not_of"></a>  basic_string::find_first_not_of  
 Pesquisa em uma cadeia de caracteres o primeiro caractere que não é um elemento de uma cadeia de caracteres especificada.  
  
```  
size_type find_first_not_of(
    value_type _Ch,   
    size_type _Off = 0) const;

 
size_type find_first_not_of(
    const value_type* ptr,  
    size_type _Off = 0) const;

 
size_type find_first_not_of(
    const value_type* ptr,   
    size_type _Off,  
    size_type count) const;

 
size_type find_first_not_of(
    const basic_string<CharType, Traits, Allocator>& str,  
    size_type _Off = 0) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Ch`  
 O valor de caractere que a função membro deve pesquisar.  
  
 `_Off`  
 Índice da posição em que a pesquisa deve começar.  
  
 `ptr`  
 A cadeia de caracteres do C que a função membro deve pesquisar.  
  
 `count`  
 O número de caracteres, contando a partir do primeiro caractere, na cadeia de caracteres do C que a função membro deve pesquisar.  
  
 `str`  
 A cadeia de caracteres que a função membro deve pesquisar.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do primeiro caractere da subsequência pesquisada quando for houver êxito, caso contrário, `npos`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_find_first_not_of.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
  
   // The first member function  
   // searches for a single character in a string  
   string str1 ( "xddd-1234-abcd" );  
   cout << "The original string str1 is: " << str1 << endl;  
   basic_string <char>::size_type indexCh1a, indexCh1b;  
   static const basic_string <char>::size_type npos = -1;  
  
   indexCh1a = str1.find_first_not_of ( "d" , 2 );  
   if ( indexCh1a != npos )  
      cout << "The index of the 1st 'd' found after the 3rd"  
           << " position in str1 is: " << indexCh1a << endl;  
   else  
      cout << "The character 'd' was not found in str1 ." << endl;  
  
   indexCh1b = str1.find_first_not_of  ( "x" );  
   if (indexCh1b != npos )  
      cout << "The index of the 'non x' found in str1 is: "   
           << indexCh1b << endl << endl;  
   else  
      cout << "The character 'non x' was not found in str1."  
           << endl << endl;  
  
   // The second member function searches a string  
   // for a substring as specified by a C-string  
   string str2 ( "BBB-1111" );  
   cout << "The original string str2 is: " << str2 << endl;  
   basic_string <char>::size_type indexCh2a, indexCh2b;  
  
   const char *cstr2 = "B1";  
   indexCh2a = str2.find_first_not_of ( cstr2 , 6 );  
   if ( indexCh2a != npos )  
      cout << "The index of the 1st occurrence of an "  
           << "element of 'B1' in str2 after\n the 6th "  
           << "position is: " << indexCh2a << endl;  
   else  
      cout << "Elements of the substring 'B1' were not"  
           << "\n found in str2 after the 6th position."  
           << endl;  
  
   const char *cstr2b = "B2";  
   indexCh2b = str2.find_first_not_of ( cstr2b );  
   if ( indexCh2b != npos )  
      cout << "The index of the 1st element of 'B2' "  
           << "after\n the 0th position in str2 is: "  
           << indexCh2b << endl << endl;  
   else  
      cout << "The substring 'B2' was not found in str2 ."   
           << endl << endl << endl;  
  
   // The third member function searches a string  
   // for a substring as specified by a C-string  
   string str3 ( "444-555-GGG" );  
   cout << "The original string str3 is: " << str3 << endl;  
   basic_string <char>::size_type indexCh3a, indexCh3b;  
  
   const char *cstr3a = "45G";  
   indexCh3a = str3.find_first_not_of ( cstr3a );  
   if ( indexCh3a != npos )  
      cout << "The index of the 1st occurrence of an "  
           << "element in str3\n other than one of the "  
           << "characters in '45G' is: " << indexCh3a   
           << endl;  
   else  
      cout << "Elements in str3 contain only characters "  
           << " in the string '45G'. "  
           << endl;  
  
   const char *cstr3b = "45G";  
   indexCh3b = str3.find_first_not_of ( cstr3b , indexCh3a + 1 , 2 );  
   if ( indexCh3b != npos )  
      cout << "The index of the second occurrence of an "  
           << "element of '45G' in str3\n after the 0th "  
           << "position is: " << indexCh3b << endl << endl;  
   else  
      cout << "Elements in str3 contain only characters "  
           << " in the string  '45G'. "  
           << endl  << endl;  
  
   // The fourth member function searches a string  
   // for a substring as specified by a string  
   string str4 ( "12-ab-12-ab" );  
   cout << "The original string str4 is: " << str4 << endl;  
   basic_string <char>::size_type indexCh4a, indexCh4b;  
  
   string str4a ( "ba3" );  
   indexCh4a = str4.find_first_not_of ( str4a , 5 );  
   if (indexCh4a != npos )  
      cout << "The index of the 1st non occurrence of an "  
           << "element of 'ba3' in str4 after\n the 5th "  
           << "position is: " << indexCh4a << endl;  
   else  
      cout << "Elements other than those in the substring"  
           << " 'ba3' were not found in the string str4."  
           << endl;  
  
   string str4b ( "12" );  
   indexCh4b = str4.find_first_not_of ( str4b  );  
   if (indexCh4b != npos )  
      cout << "The index of the 1st non occurrence of an "  
           << "element of '12' in str4 after\n the 0th "  
           << "position is: " << indexCh4b << endl;  
   else  
      cout << "Elements other than those in the substring"  
           << " '12' were not found in the string str4."  
           << endl;  
}  
```  
  
```Output  
The original string str1 is: xddd-1234-abcd  
The index of the 1st 'd' found after the 3rd position in str1 is: 4  
The index of the 'non x' found in str1 is: 1  
  
The original string str2 is: BBB-1111  
Elements of the substring 'B1' were not  
 found in str2 after the 6th position.  
The index of the 1st element of 'B2' after  
 the 0th position in str2 is: 3  
  
The original string str3 is: 444-555-GGG  
The index of the 1st occurrence of an element in str3  
 other than one of the characters in '45G' is: 3  
The index of the second occurrence of an element of '45G' in str3  
 after the 0th position is: 7  
  
The original string str4 is: 12-ab-12-ab  
The index of the 1st non occurrence of an element of 'ba3' in str4 after  
 the 5th position is: 5  
The index of the 1st non occurrence of an element of '12' in str4 after  
 the 0th position is: 2  
```  
  
##  <a name="find_first_of"></a>  basic_string::find_first_of  
 Pesquisa, em uma cadeia de caracteres, o primeiro caractere que corresponda a qualquer elemento de uma cadeia de caracteres especificada.  
  
```  
size_type find_first_of(
    value_type _Ch,   
    size_type _Off = 0) const;

 
size_type find_first_of(
    const value_type* ptr,  
    size_type _Off = 0) const;

 
size_type find_first_of(
    const value_type* ptr,   
    size_type _Off,  
    size_type count) const;

 
size_type find_first_of(
    const basic_string<CharType, Traits, Allocator>& str,  
    size_type _Off = 0) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Ch`  
 O valor de caractere que a função membro deve pesquisar.  
  
 `_Off`  
 Índice da posição em que a pesquisa deve começar.  
  
 `ptr`  
 A cadeia de caracteres do C que a função membro deve pesquisar.  
  
 `count`  
 O número de caracteres, contando a partir do primeiro caractere, na cadeia de caracteres do C que a função membro deve pesquisar.  
  
 `str`  
 A cadeia de caracteres que a função membro deve pesquisar.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do primeiro caractere da subsequência pesquisada quando for houver êxito, caso contrário, `npos`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_find_first_of.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
  
   // The first member function  
   // searches for a single character in a string  
   string str1 ( "abcd-1234-abcd-1234" );  
   cout << "The original string str1 is: " << str1 << endl;  
   basic_string <char>::size_type indexCh1a, indexCh1b;  
   static const basic_string <char>::size_type npos = -1;  
  
   indexCh1a = str1.find_first_of ( "d" , 5 );  
   if ( indexCh1a != npos )  
      cout << "The index of the 1st 'd' found after the 5th"  
           << " position in str1 is: " << indexCh1a << endl;  
   else  
      cout << "The character 'd' was not found in str1 ." << endl;  
  
   indexCh1b = str1.find_first_of ( "x" );  
   if ( indexCh1b != npos )  
      cout << "The index of the 'x' found in str1 is: "   
           << indexCh1b << endl << endl;  
   else  
      cout << "The character 'x' was not found in str1."  
           << endl << endl;  
  
   // The second member function searches a string  
   // for any element of a substring as specified by a C-string  
   string str2 ( "ABCD-1234-ABCD-1234" );  
   cout << "The original string str2 is: " << str2 << endl;  
   basic_string <char>::size_type indexCh2a, indexCh2b;  
  
   const char *cstr2 = "B1";  
   indexCh2a = str2.find_first_of ( cstr2 , 6 );  
   if ( indexCh2a != npos )  
      cout << "The index of the 1st occurrence of an "  
           << "element of 'B1' in str2 after\n the 6th "  
           << "position is: " << indexCh2a << endl;  
   else  
      cout << "Elements of the substring 'B1' were not "  
           << "found in str2 after the 10th position."  
           << endl;  
  
   const char *cstr2b = "D2";  
   indexCh2b = str2.find_first_of ( cstr2b );  
   if ( indexCh2b != npos )  
      cout << "The index of the 1st element of 'D2' "  
           << "after\n the 0th position in str2 is: "  
           << indexCh2b << endl << endl;  
   else  
      cout << "The substring 'D2' was not found in str2 ."   
           << endl << endl << endl;  
  
   // The third member function searches a string  
   // for any element of a substring as specified by a C-string  
   string str3 ( "123-abc-123-abc-456-EFG-456-EFG" );  
   cout << "The original string str3 is: " << str3 << endl;  
   basic_string <char>::size_type indexCh3a, indexCh3b;  
  
   const char *cstr3a = "5G";  
   indexCh3a = str3.find_first_of ( cstr3a );  
   if ( indexCh3a != npos )  
      cout << "The index of the 1st occurrence of an "  
           << "element of '5G' in str3 after\n the 0th "  
           << "position is: " << indexCh3a << endl;  
   else  
      cout << "Elements of the substring '5G' were not "  
           << "found in str3\n after the 0th position."  
           << endl;  
  
   const char *cstr3b = "5GF";  
   indexCh3b = str3.find_first_of  ( cstr3b , indexCh3a + 1 , 2 );  
   if (indexCh3b != npos )  
      cout << "The index of the second occurrence of an "  
           << "element of '5G' in str3\n after the 0th "  
           << "position is: " << indexCh3b << endl << endl;  
   else  
      cout << "Elements of the substring '5G' were not "  
           << "found in str3\n after the first occurrrence."  
           << endl << endl;  
  
   // The fourth member function searches a string  
   // for any element of a substring as specified by a string  
   string str4 ( "12-ab-12-ab" );  
   cout << "The original string str4 is: " << str4 << endl;  
   basic_string <char>::size_type indexCh4a, indexCh4b;  
  
   string str4a ( "ba3" );  
   indexCh4a = str4.find_first_of ( str4a , 5 );  
   if ( indexCh4a != npos )  
      cout << "The index of the 1st occurrence of an "  
           << "element of 'ba3' in str4 after\n the 5th "  
           << "position is: " << indexCh4a << endl;  
   else  
      cout << "Elements of the substring 'ba3' were not "  
           << "found in str4\n after the 0th position."  
           << endl;  
  
   string str4b ( "a2" );  
   indexCh4b = str4.find_first_of ( str4b );  
   if ( indexCh4b != npos )  
      cout << "The index of the 1st occurrence of an "  
           << "element of 'a2' in str4 after\n the 0th "  
           << "position is: " << indexCh4b << endl;  
   else  
      cout << "Elements of the substring 'a2' were not "  
           << "found in str4\n after the 0th position."  
           << endl;  
}  
```  
  
```Output  
The original string str1 is: abcd-1234-abcd-1234  
The index of the 1st 'd' found after the 5th position in str1 is: 13  
The character 'x' was not found in str1.  
  
The original string str2 is: ABCD-1234-ABCD-1234  
The index of the 1st occurrence of an element of 'B1' in str2 after  
 the 6th position is: 11  
The index of the 1st element of 'D2' after  
 the 0th position in str2 is: 3  
  
The original string str3 is: 123-abc-123-abc-456-EFG-456-EFG  
The index of the 1st occurrence of an element of '5G' in str3 after  
 the 0th position is: 17  
The index of the second occurrence of an element of '5G' in str3  
 after the 0th position is: 22  
  
The original string str4 is: 12-ab-12-ab  
The index of the 1st occurrence of an element of 'ba3' in str4 after  
 the 5th position is: 9  
The index of the 1st occurrence of an element of 'a2' in str4 after  
 the 0th position is: 1  
```  
  
##  <a name="find_last_not_of"></a>  basic_string::find_last_not_of  
 Pesquisa, em uma cadeia de caracteres, o último caractere que não seja um elemento de uma cadeia de caracteres especificada.  
  
```  
size_type find_last_not_of(
    value_type _Ch,   
    size_type _Off = npos) const;

 
size_type find_last_not_of(
    const value_type* ptr,  
    size_type _Off = npos) const;

 
size_type find_last_not_of(
    const value_type* ptr,   
    size_type _Off,  
    size_type count) const;

 
size_type find_last_not_of(
    const basic_string<CharType, Traits, Allocator>& str,  
    size_type _Off = npos) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Ch`  
 O valor de caractere que a função membro deve pesquisar.  
  
 `_Off`  
 Índice da posição em que a pesquisa deve terminar.  
  
 `ptr`  
 A cadeia de caracteres do C que a função membro deve pesquisar.  
  
 `count`  
 O número de caracteres, contando a partir do primeiro caractere, na cadeia de caracteres do C que a função membro deve pesquisar.  
  
 `str`  
 A cadeia de caracteres que a função membro deve pesquisar.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do primeiro caractere da subsequência pesquisada quando for houver êxito, caso contrário, `npos`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_find_last_not_of.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
  
   // The first member function  
   // searches for a single character in a string  
   string str1 ( "dddd-1dd4-abdd" );  
   cout << "The original string str1 is: " << str1 << endl;  
   basic_string <char>::size_type indexCh1a, indexCh1b;  
   static const basic_string <char>::size_type npos = -1;  
  
   indexCh1a = str1.find_last_not_of ( "d" , 7 );  
   if ( indexCh1a != npos )  
      cout << "The index of the last non 'd'\n found before the "  
           << "7th position in str1 is: " << indexCh1a << endl;  
   else  
      cout << "The non 'd' character was not found ." << endl;  
  
   indexCh1b = str1.find_last_not_of  ( "d" );  
   if ( indexCh1b != npos )  
      cout << "The index of the non 'd' found in str1 is: "   
           << indexCh1b << endl << endl;  
   else  
      cout << "The Character 'non x' was not found in str1."  
           << endl << endl;  
  
   // The second member function searches a string  
   // for a substring as specified by a C-string  
   string str2 ( "BBB-1111" );  
   cout << "The original string str2 is: " << str2 << endl;  
   basic_string <char>::size_type indexCh2a, indexCh2b;  
  
   const char *cstr2 = "B1";  
   indexCh2a = str2.find_last_not_of  ( cstr2 , 6 );  
   if ( indexCh2a != npos )  
      cout << "The index of the last occurrence of a "  
           << "element\n not of 'B1' in str2 before the 6th "  
           << "position is: " << indexCh2a << endl;  
   else  
      cout << "Elements not of the substring 'B1' were not "  
           << "\n found in str2 before the 6th position."  
           << endl;  
  
   const char *cstr2b = "B-1";  
   indexCh2b = str2.find_last_not_of  ( cstr2b );  
   if ( indexCh2b != npos )  
      cout << "The index of the last element not "  
           << "in 'B-1'\n is: "  
           << indexCh2b << endl << endl;  
   else  
      cout << "The elements of the substring 'B-1' were "  
           << "not found in str2 ."   
           << endl << endl;  
  
   // The third member function searches a string  
   // for a substring as specified by a C-string  
   string str3 ( "444-555-GGG" );  
   cout << "The original string str3 is: " << str3 << endl;  
   basic_string <char>::size_type indexCh3a, indexCh3b;  
  
   const char *cstr3a = "45G";  
   indexCh3a = str3.find_last_not_of ( cstr3a );  
   if ( indexCh3a != npos )  
      cout << "The index of the last occurrence of an "  
           << "element in str3\n other than one of the "  
           << "characters in '45G' is: " << indexCh3a   
           << endl;  
   else  
      cout << "Elements in str3 contain only characters "  
           << " in the string  '45G'. "  
           << endl;  
  
   const char *cstr3b = "45G";  
   indexCh3b = str3.find_last_not_of ( cstr3b , 6 , indexCh3a - 1 );  
   if (indexCh3b != npos )  
      cout << "The index of the penultimate occurrence of an "  
           << "element\n not in '45G' in str3 is: "  
           << indexCh3b << endl << endl;  
   else  
      cout << "Elements in str3 contain only characters "  
           << " in the string '45G'. "  
           << endl  << endl;  
  
   // The fourth member function searches a string  
   // for a substring as specified by a string  
   string str4 ( "12-ab-12-ab" );  
   cout << "The original string str4 is: " << str4 << endl;  
   basic_string <char>::size_type indexCh4a, indexCh4b;  
  
   string str4a ( "b-a" );  
   indexCh4a = str4.find_last_not_of  ( str4a , 5 );  
   if ( indexCh4a != npos )  
      cout << "The index of the last occurrence of an "  
           << "element not\n in 'b-a' in str4 before the 5th "  
           << "position is: " << indexCh4a << endl;  
   else  
      cout << "Elements other than those in the substring"  
           << " 'b-a' were not found in the string str4."  
           << endl;  
  
   string str4b ( "12" );  
   indexCh4b = str4.find_last_not_of ( str4b  );  
   if ( indexCh4b != npos )  
      cout << "The index of the last occurrence of an "  
           << "element not in '12'\n in str4 before the end "  
           << "position is: " << indexCh4b << endl;  
   else  
      cout << "Elements other than those in the substring"  
           << " '12'\n were not found in the string str4."  
           << endl;  
}  
```  
  
```Output  
The original string str1 is: dddd-1dd4-abdd  
The index of the last non 'd'  
 found before the 7th position in str1 is: 5  
The index of the non 'd' found in str1 is: 11  
  
The original string str2 is: BBB-1111  
The index of the last occurrence of a element  
 not of 'B1' in str2 before the 6th position is: 3  
The elements of the substring 'B-1' were not found in str2 .  
  
The original string str3 is: 444-555-GGG  
The index of the last occurrence of an element in str3  
 other than one of the characters in '45G' is: 7  
The index of the penultimate occurrence of an element  
 not in '45G' in str3 is: 3  
  
The original string str4 is: 12-ab-12-ab  
The index of the last occurrence of an element not  
 in 'b-a' in str4 before the 5th position is: 1  
The index of the last occurrence of an element not in '12'  
 in str4 before the end position is: 10  
```  
  
##  <a name="find_last_of"></a>  basic_string::find_last_of  
 Pesquisa em uma cadeia de caracteres o último caractere que corresponde a qualquer elemento de uma cadeia de caracteres especificada.  
  
```  
size_type find_last_of(
    value_type _Ch,   
    size_type _Off = npos) const;

 
 
size_type find_last_of(
    const value_type* ptr,  
    size_type _Off = npos) const;

 
 
size_type find_last_of(
    const value_type* ptr,   
    size_type _Off,  
    size_type count) const;

 
 
size_type find_last_of(
    const basic_string<CharType, Traits, Allocator>& str,  
    size_type _Off = npos) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Ch`  
 O valor de caractere que a função membro deve pesquisar.  
  
 `_Off`  
 Índice da posição em que a pesquisa deve terminar.  
  
 `ptr`  
 A cadeia de caracteres do C que a função membro deve pesquisar.  
  
 `count`  
 O número de caracteres, contando a partir do primeiro caractere, na cadeia de caracteres do C que a função membro deve pesquisar.  
  
 `str`  
 A cadeia de caracteres que a função membro deve pesquisar.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do último caractere da subsequência pesquisada quando houver êxito, caso contrário, `npos`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_find_last_of.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   // The first member function  
   // searches for a single character in a string  
   string str1 ( "abcd-1234-abcd-1234" );  
   cout << "The original string str1 is: " << str1 << endl;  
   basic_string <char>::size_type indexCh1a, indexCh1b;  
   static const basic_string <char>::size_type npos = -1;  
  
   indexCh1a = str1.find_last_of ( "d" , 14 );  
   if ( indexCh1a != npos )  
      cout << "The index of the last 'd' found before the 14th"  
           << " position in str1 is: " << indexCh1a << endl;  
   else  
      cout << "The character 'd' was not found in str1 ." << endl;  
  
   indexCh1b = str1.find_first_of ( "x" );  
   if ( indexCh1b != npos )  
      cout << "The index of the 'x' found in str1 is: "  
           << indexCh1b << endl << endl;  
   else  
      cout << "The character 'x' was not found in str1."  
           << endl << endl;  
  
   // The second member function searches a string  
   // for a substring as specified by a C-string  
   string str2 ( "ABCD-1234-ABCD-1234" );  
   cout << "The original string str2 is: " << str2 << endl;  
   basic_string <char>::size_type indexCh2a, indexCh2b;  
  
   const char *cstr2 = "B1";  
   indexCh2a = str2.find_last_of  ( cstr2 , 12 );  
   if (indexCh2a != npos )  
      cout << "The index of the last occurrence of an "  
           << "element of 'B1' in str2 before\n the 12th "  
           << "position is: " << indexCh2a << endl;  
   else  
      cout << "Elements of the substring 'B1' were not "  
           << "found in str2 before the 12th position."  
           << endl;  
  
   const char *cstr2b = "D2";  
   indexCh2b = str2.find_last_of  ( cstr2b );  
   if ( indexCh2b != npos )  
      cout << "The index of the last element of 'D2' "  
           << "after\n the 0th position in str2 is: "  
           << indexCh2b << endl << endl;  
   else  
      cout << "The substring 'D2' was not found in str2 ."  
           << endl << endl << endl;  
  
   // The third member function searches a string  
   // for a substring as specified by a C-string  
   string str3 ( "456-EFG-456-EFG" );  
   cout << "The original string str3 is: " << str3 << endl;  
   basic_string <char>::size_type indexCh3a;  
  
   const char *cstr3a = "5E";  
   indexCh3a = str3.find_last_of ( cstr3a , 8 , 8 );  
   if ( indexCh3a != npos )  
      cout << "The index of the last occurrence of an "  
           << "element of '5E' in str3 before\n the 8th "  
           << "position is: " << indexCh3a << endl << endl;  
   else  
      cout << "Elements of the substring '5G' were not "  
           << "found in str3\n before the 8th position."  
           << endl << endl;  
  
   // The fourth member function searches a string  
   // for a substring as specified by a string  
   string str4 ( "12-ab-12-ab" );  
   cout << "The original string str4 is: " << str4 << endl;  
   basic_string <char>::size_type indexCh4a, indexCh4b;  
  
   string str4a ( "ba3" );  
   indexCh4a = str4.find_last_of  ( str4a , 8 );  
   if ( indexCh4a != npos )  
      cout << "The index of the last occurrence of an "  
           << "element of 'ba3' in str4 before\n the 8th "  
           << "position is: " << indexCh4a << endl;  
   else  
      cout << "Elements of the substring 'ba3' were not "  
           << "found in str4\n after the 0th position."  
           << endl;  
  
   string str4b ( "a2" );  
   indexCh4b = str4.find_last_of ( str4b  );  
   if ( indexCh4b != npos )  
      cout << "The index of the last occurrence of an "  
           << "element of 'a2' in str4 before\n the 0th "  
           << "position is: " << indexCh4b << endl;  
   else  
      cout << "Elements of the substring 'a2' were not "  
           << "found in str4\n after the 0th position."  
           << endl;  
}  
```  
  
```Output  
The original string str1 is: abcd-1234-abcd-1234  
The index of the last 'd' found before the 14th position in str1 is: 13  
The character 'x' was not found in str1.  
  
The original string str2 is: ABCD-1234-ABCD-1234  
The index of the last occurrence of an element of 'B1' in str2 before  
 the 12th position is: 11  
The index of the last element of 'D2' after  
 the 0th position in str2 is: 16  
  
The original string str3 is: 456-EFG-456-EFG  
The index of the last occurrence of an element of '5E' in str3 before  
 the 8th position is: 4  
  
The original string str4 is: 12-ab-12-ab  
The index of the last occurrence of an element of 'ba3' in str4 before  
 the 8th position is: 4  
The index of the last occurrence of an element of 'a2' in str4 before  
 the 0th position is: 9  
```  
  
##  <a name="front"></a>  basic_string::front  
 Retorna uma referência ao primeiro elemento em uma cadeia de caracteres.  
  
```  
const_reference front() const;

 
reference front();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao primeiro elemento da cadeia de caracteres, que não deve ser vazio.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="get_allocator"></a>  basic_string::get_allocator  
 Retorna uma cópia do objeto alocador usado para construir a cadeia de caracteres.  
  
```  
allocator_type get_allocator() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O alocador usado pela cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o objeto alocador armazenado.  
  
 Os alocadores da classe de cadeia de caracteres especificam como a classe gerencia o armazenamento. Os alocadores padrão fornecidos com as classes de contêiner são suficientes para a maioria das necessidades de programação. Gravando e usando sua própria classe de alocador é um tópico avançado do C++.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_get_allocator.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   // The following lines declare objects  
   // that use the default allocator.  
   string s1;  
   basic_string <char> s2;  
   basic_string <char, char_traits< char >, allocator< char > > s3;  
  
   // s4 will use the same allocator class as s1  
   basic_string <char> s4( s1.get_allocator ( ) );  
  
   basic_string <char>::allocator_type xchar = s1.get_allocator( );  
   // You can now call functions on the allocator class xchar used by s1  
}  
```  
  
##  <a name="insert"></a>  basic_string::insert  
 Insere um elemento ou um número de elementos ou um intervalo de elementos na cadeia de caracteres na posição especificada.  
  
```  
basic_string<CharType, Traits, Allocator>& insert(
    size_type _P0,   
    const value_type* ptr);

basic_string<CharType, Traits, Allocator>& insert(
    size_type _P0,   
    const value_type* ptr,  
    size_type count);

basic_string<CharType, Traits, Allocator>& insert(
    size_type _P0,  
    const basic_string<CharType, Traits, Allocator>& str);

basic_string<CharType, Traits, Allocator>& insert(
    size_type _P0,  
    const basic_string<CharType, Traits, Allocator>& str,   
    size_type _Off,   
    size_type count);

basic_string<CharType, Traits, Allocator>& insert(
    size_type _P0,  
    size_type count,   
    value_type _Ch);

iterator insert(
    iterator _It);

iterator insert(
    iterator _It,  
    value_type _Ch)l  
template <class InputIterator>  
void insert(
    iterator _It,   
    InputIterator first,   
    InputIterator last);

void insert(
    iterator _It,   
    size_type count,   
    value_type _Ch);

void insert(
    iterator _It,  
    const_pointer first,  
    const_pointer last);

void insert(
    iterator _It,  
    const_iterator first,  
    const_iterator last);
```  
  
### <a name="parameters"></a>Parâmetros  
 *_P0*  
 O índice da posição atrás do ponto de inserção de novos caracteres.  
  
 `ptr`  
 A cadeia de caracteres do C a ser totalmente ou parcialmente inserida na cadeia de caracteres.  
  
 `count`  
 O número de caracteres a serem inseridos.  
  
 `str`  
 A cadeia de caracteres a ser totalmente ou parcialmente inserida na cadeia de caracteres de destino.  
  
 `_Off`  
 O índice da parte da cadeia de caracteres de origem que fornece os caracteres a serem acrescentados.  
  
 `_Ch`  
 O valor de caractere dos elementos a serem inseridos.  
  
 `_It`  
 Um iterador que trata da posição atrás da qual um caractere deve ser inserido.  
  
 `first`  
 Um iterador de entrada, const_pointer ou const_iterator, que trata do primeiro elemento no intervalo de origem a ser inserido.  
  
 `last`  
 Um iterador de entrada, const_pointer ou const_iterator, que trata da posição logo após o último elemento no intervalo de origem a ser inserido.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto de cadeia de caracteres ao qual estão sendo atribuídos novos caracteres pela função membro ou, no caso de inserções de caractere individual, um iterador que trata da posição do caractere inserido ou nenhum, dependendo da função membro específica.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_insert.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   // The first member function inserting a C-string  
   // at a given position  
   basic_string <char> str1a ( "way" );  
   const char *cstr1a = "a";  
   str1a.insert ( 0, cstr1a );  
   cout << "The string with a C-string inserted at position 0 is: "  
        << str1a << "." << endl;  
  
   // The second member function inserting a C-string  
   // at a given position for a specified number of elements  
   basic_string <char> str2a ( "Good" );  
   const char *cstr2a = "Bye Bye Baby";  
   str2a.insert ( 4, cstr2a ,3 );  
   cout << "The string with a C-string inserted at the end is: "  
        << str2a << "." << endl;  
  
   // The third member function inserting a string  
   // at a given position  
   basic_string <char> str3a ( "Bye" );  
   string str3b ( "Good" );  
   str3a.insert ( 0, str3b );  
   cout << "The string with a string inserted at position 0 is: "  
        << str3a << "." << endl;  
  
   // The fourth member function inserting part of  
   // a string at a given position  
   basic_string <char> str4a ( "Good " );  
   string str4b ( "Bye Bye Baby" );  
   str4a.insert ( 5, str4b , 8 , 4 );  
   cout << "The string with part of a string inserted at position 4 is: "  
        << str4a << "." << endl;  
  
   // The fifth member function inserts a number of characters  
   // at a specified position in the string  
   string str5 ( "The number is: ." );  
   str5.insert ( 15 , 3 , '3' );  
   cout << "The string with characters inserted is: "  
        << str5 << endl;  
  
   // The sixth member function inserts a character  
   // at a specified position in the string  
   string str6 ( "ABCDFG" );  
   basic_string <char>::iterator str6_Iter = ( str6.begin ( ) + 4 );  
   str6.insert ( str6_Iter , 'e' );  
   cout << "The string with a character inserted is: "  
        << str6 << endl;  
  
   // The seventh member function inserts a range  
   // at a specified position in the string  
   string str7a ( "ABCDHIJ" );  
   string str7b ( "abcdefgh" );  
   basic_string <char>::iterator str7a_Iter = (str7a.begin ( ) + 4 );  
   str7a.insert ( str7a_Iter , str7b.begin ( ) + 4 , str7b.end ( ) -1 );  
   cout << "The string with a character inserted from a range is: "  
        << str7a << endl;  
  
   // The eigth member function inserts a number of  
   // characters at a specified position in the string  
   string str8 ( "ABCDHIJ" );  
   basic_string <char>::iterator str8_Iter = ( str8.begin ( ) + 4 );  
   str8.insert ( str8_Iter , 3 , 'e' );  
   cout << "The string with a character inserted from a range is: "  
        << str8 << endl;  
}  
```  
  
```Output  
The string with a C-string inserted at position 0 is: away.  
The string with a C-string inserted at the end is: GoodBye.  
The string with a string inserted at position 0 is: GoodBye.  
The string with part of a string inserted at position 4 is: Good Baby.  
The string with characters inserted is: The number is: 333.  
The string with a character inserted is: ABCDeFG  
The string with a character inserted from a range is: ABCDefgHIJ  
The string with a character inserted from a range is: ABCDeeeHIJ  
```  
  
##  <a name="iterator"></a>  basic_string::iterator  
 Um tipo que fornece um iterador de acesso aleatório que pode acessar e ler um elemento **const** na cadeia de caracteres.  
  
```  
typedef implementation-defined iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo **iterator** pode ser usado para modificar o valor de um caractere e é usado para iterar em uma cadeia de caracteres em uma direção progressiva.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [begin](#begin) que demonstra como declarar e usar o **iterator**.  
  
##  <a name="length"></a>  basic_string::length  
 Retorna o número de elementos em uma cadeia de caracteres.  
  
```  
size_type length() const;
```  
  
### <a name="remarks"></a>Comentários  
 A função membro é igual a [size](#size).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_length.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   string str1 ("Hello world");  
   cout << "The original string str1 is: " << str1 << endl;  
  
   // The size and length member functions differ in name only  
   basic_string <char>::size_type sizeStr1, lenStr1;  
   sizeStr1 = str1.size ( );  
   lenStr1 = str1.length ( );  
  
   basic_string <char>::size_type capStr1, max_sizeStr1;  
   capStr1 = str1.capacity ( );  
   max_sizeStr1 = str1.max_size ( );  
  
   // Compare size, length, capacity & max_size of a string  
   cout << "The current size of original string str1 is: "   
        << sizeStr1 << "." << endl;  
   cout << "The current length of original string str1 is: "   
        << lenStr1 << "." << endl;  
   cout << "The capacity of original string str1 is: "  
        << capStr1 << "." << endl;  
   cout << "The max_size of original string str1 is: "   
        << max_sizeStr1 << "." << endl << endl;  
  
   str1.erase ( 6, 5 );  
   cout << "The modified string str1 is: " << str1 << endl;  
  
   sizeStr1 = str1.size ( );  
   lenStr1 = str1.length ( );  
   capStr1 = str1.capacity ( );  
   max_sizeStr1 = str1.max_size ( );  
  
   // Compare size, length, capacity & max_size of a string  
   // after erasing part of the original string  
   cout << "The current size of modified string str1 is: "   
        << sizeStr1 << "." << endl;  
   cout << "The current length of modified string str1 is: "   
        << lenStr1 << "." << endl;  
   cout << "The capacity of modified string str1 is: "  
        << capStr1 << "." << endl;  
   cout << "The max_size of modified string str1 is: "   
        << max_sizeStr1 << "." << endl;  
}  
```  
  
##  <a name="max_size"></a>  basic_string::max_size  
 Retorna o número máximo de caracteres que uma cadeia de caracteres pode conter.  
  
```  
size_type max_size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número máximo de caracteres que uma cadeia de caracteres pode conter.  
  
### <a name="remarks"></a>Comentários  
 Uma exceção do tipo [Classe length_error](../standard-library/length-error-class.md) é gerada quando uma operação produz uma cadeia de caracteres com comprimento maior que o tamanho máximo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_max_size.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   string str1 ("Hello world");  
   cout << "The original string str1 is: " << str1 << endl;  
  
   // The size and length member functions differ in name only  
   basic_string <char>::size_type sizeStr1, lenStr1;  
   sizeStr1 = str1.size ( );  
   lenStr1 = str1.length ( );  
  
   basic_string <char>::size_type capStr1, max_sizeStr1;  
   capStr1 = str1.capacity ( );  
   max_sizeStr1 = str1.max_size ( );  
  
   // Compare size, length, capacity & max_size of a string  
   cout << "The current size of original string str1 is: "   
        << sizeStr1 << "." << endl;  
   cout << "The current length of original string str1 is: "   
        << lenStr1 << "." << endl;  
   cout << "The capacity of original string str1 is: "  
        << capStr1 << "." << endl;  
   cout << "The max_size of original string str1 is: "   
        << max_sizeStr1 << "." << endl << endl;  
  
   str1.erase ( 6, 5 );  
   cout << "The modified string str1 is: " << str1 << endl;  
  
   sizeStr1 = str1.size ( );  
   lenStr1 = str1.length ( );  
   capStr1 = str1.capacity ( );  
   max_sizeStr1 = str1.max_size ( );  
  
   // Compare size, length, capacity & max_size of a string  
   // after erasing part of the original string  
   cout << "The current size of modified string str1 is: "   
        << sizeStr1 << "." << endl;  
   cout << "The current length of modified string str1 is: "   
        << lenStr1 << "." << endl;  
   cout << "The capacity of modified string str1 is: "  
        << capStr1 << "." << endl;  
   cout << "The max_size of modified string str1 is: "   
        << max_sizeStr1 << "." << endl;  
}  
```  
  
##  <a name="npos"></a>  basic_string::npos  
 Um valor inteiro sem sinal inicializado como -1 que indica "não foi encontrado" ou "todos os caracteres restantes" quando uma função de pesquisa falha.  
  
```  
static const size_type npos = -1;  
```  
  
### <a name="remarks"></a>Comentários  
 Quando o valor retornado deve ser verificado quanto ao valor de `npos`, ele pode não funcionar, a não ser que o valor retornado seja do tipo [size_type](#size_type) e não `int` nem `unsigned`.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [find](#find) que demonstra como declarar e usar `npos`.  
  
##  <a name="op_add_eq"></a>  basic_string::operator+=  
 Acrescenta caracteres a uma cadeia de caracteres.  
  
```  
basic_string<CharType, Traits, Allocator>& operator+=(
    value_type _Ch);

basic_string<CharType, Traits, Allocator>& operator+=(
    const value_type* ptr);

basic_string<CharType, Traits, Allocator>& operator+=(
    const basic_string<CharType, Traits, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Ch`  
 O caractere a ser acrescentado.  
  
 `ptr`  
 Os caracteres da cadeia de caracteres do C a serem acrescentados.  
  
 `right`  
 Os caracteres da cadeia de caracteres a serem acrescentados.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto de cadeia de caracteres que está sendo acrescentado com os caracteres passados pela função membro.  
  
### <a name="remarks"></a>Comentários  
 Os caracteres podem ser acrescentados a uma cadeia de caracteres usando o `operator+=` ou as funções membro [append](#append) ou [push_back](#push_back). O `operator+=` acrescenta valores de argumento único enquanto a função membro append de múltiplos argumentos permite que uma parte específica de uma cadeia de caracteres seja especificada para adição.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_op_app.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
  
   // The first member function  
   // appending a single character to a string  
   string str1a ( "Hello" );  
   cout << "The original string str1 is: " << str1a << endl;  
   str1a +=  '!' ;  
   cout << "The string str1 appended with an exclamation is: "   
        << str1a << endl << endl;  
  
   // The second member function  
   // appending a C-string to a string  
   string  str1b ( "Hello " );  
   const char *cstr1b = "Out There";  
   cout << "The C-string cstr1b is: " << cstr1b << endl;  
   str1b +=  cstr1b;  
   cout << "Appending the C-string cstr1b to string str1 gives: "   
        << str1b << "." << endl << endl;  
  
   // The third member function  
   // appending one string to another in two ways,  
   // comparing append and operator [ ]  
   string str1d ( "Hello " ), str2d ( "Wide " ), str3d ( "World" );  
   cout << "The string str2d is: " << str2d << endl;  
   str1d.append ( str2d );  
   cout << "The appended string str1d is: "   
        << str1d << "." << endl;  
   str1d += str3d;  
   cout << "The doubly appended strig str1 is: "   
        << str1d << "." << endl << endl;  
}  
```  
  
```Output  
The original string str1 is: Hello  
The string str1 appended with an exclamation is: Hello!  
  
The C-string cstr1b is: Out There  
Appending the C-string cstr1b to string str1 gives: Hello Out There.  
  
The string str2d is: Wide   
The appended string str1d is: Hello Wide .  
The doubly appended strig str1 is: Hello Wide World.  
```  
  
##  <a name="op_eq"></a>  basic_string::operator=  
 Atribui novos valores de caracteres ao conteúdo de uma cadeia de caracteres.  
  
```  
basic_string<CharType, Traits, Allocator>& operator=(
    value_type _Ch);

basic_string<CharType, Traits, Allocator>& operator=(
    const value_type* ptr);

basic_string<CharType, Traits, Allocator>& operator=(
    const basic_string<CharType, Traits, Allocator>& right);

basic_string<CharType, Traits, Allocator>& operator=(
    const basic_string<CharType, Traits, Allocator>&& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Ch`  
 O valor do caractere a ser atribuído.  
  
 `ptr`  
 Um ponteiro para os caracteres da cadeia de caracteres do C a serem atribuídos à cadeia de caracteres de destino.  
  
 `right`  
 A cadeia de caracteres de origem cujos caracteres devem ser atribuídos à cadeia de caracteres de destino.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto de cadeia de caracteres ao qual estão sendo atribuídos novos caracteres pela função membro.  
  
### <a name="remarks"></a>Comentários  
 Novos valores de caractere podem ser atribuídos às cadeias de caracteres. O novo valor pode ser uma cadeia de caracteres e uma cadeia de caracteres do C ou um único caractere. O `operator=` poderá ser usado se o novo valor puder ser descrito por um único parâmetro, caso contrário, a função membro [assign](#assign), que tem vários parâmetros, poderá ser usada para especificar qual parte da cadeia de caracteres deverá ser atribuída a uma cadeia de caracteres de destino.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_op_assign.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
  
   // The first member function assigning a  
   // character of a certain value to a string  
   string str1a ( "Hello " );  
   str1a = '0';  
   cout << "The string str1 assigned with the zero character is: "   
        << str1a << endl << endl;  
  
   // The second member function assigning the  
   // characters of a C-string to a string  
   string  str1b;  
   const char *cstr1b = "Out There";  
   cout << "The C-string cstr1b is: " << cstr1b <<  "." << endl;  
   str1b = cstr1b;  
   cout << "Assigning the C-string cstr1a to string str1 gives: "   
        << str1b << "." << endl << endl;  
  
   // The third member function assigning the characters  
   // from one string to another string in two equivalent  
   // ways, comparing the assign and operator =  
   string str1c ( "Hello" ), str2c ( "Wide" ), str3c ( "World" );  
   cout << "The original string str1 is: " << str1c << "." << endl;  
   cout << "The string str2c is: " << str2c << "." << endl;  
   str1c.assign ( str2c );  
   cout << "The string str1 newly assigned with string str2c is: "   
        << str1c << "." << endl;  
   cout << "The string str3c is: " << str3c << "." << endl;  
   str1c = str3c;  
   cout << "The string str1 reassigned with string str3c is: "   
        << str1c << "." << endl << endl;  
}  
```  
  
```Output  
The string str1 assigned with the zero character is: 0  
  
The C-string cstr1b is: Out There.  
Assigning the C-string cstr1a to string str1 gives: Out There.  
  
The original string str1 is: Hello.  
The string str2c is: Wide.  
The string str1 newly assigned with string str2c is: Wide.  
The string str3c is: World.  
The string str1 reassigned with string str3c is: World.  
```  
  
##  <a name="op_at"></a>  basic_string::operator[]  
 Fornece uma referência ao caractere com um índice especificado em uma cadeia de caracteres.  
  
```  
const_reference operator[](size_type _Off) const;  
reference operator[](size_type _Off);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Off`  
 O índice da posição do elemento a ser referenciado.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao caractere da cadeia de caracteres na posição especificada pelo índice de parâmetro.  
  
### <a name="remarks"></a>Comentários  
 O primeiro elemento da cadeia de caracteres tem um índice igual a zero e os elementos seguintes são indexados consecutivamente por inteiros positivos, para que uma cadeia de caracteres de comprimento *n* tenha um *n*º elemento indexado pelo número *n* - 1.  
  
 `operator[]` é mais rápido que a função membro [at](#at) para fornecer acesso de leitura e gravação aos elementos de uma cadeia de caracteres.  
  
 `operator[]` não verifica se o índice passado como um parâmetro é válido, mas a função membro **at** verifica e, portanto, ela deverá ser usada quando a validade não for garantida. Um índice inválido (um índice menor que zero ou maior ou igual ao tamanho da cadeia de caracteres) passado para a função membro **at** gera uma exceção da [Classe out_of_range](../standard-library/out-of-range-class.md). Um índice inválido passado para `operator[]` resulta em um comportamento indefinido, mas o índice igual ao comprimento da cadeia de caracteres é um índice válido para cadeias de caracteres const e o operador retorna o caractere nulo quando esse índice é passado.  
  
 A referência retornada pode ser invalidada por realocações ou modificações das cadeias de caracteres que não são **const**.  
  
 Ao compilar com [\_ITERATOR\_DEBUG\_LEVEL](../standard-library/iterator-debug-level.md) definido como 1 ou 2, um erro de tempo de execução ocorrerá se você tentar acessar um elemento fora dos limites da cadeia de caracteres. Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_op_ref.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   string str1 ( "Hello world" ), str2 ( "Goodbye world" );  
   const string cstr1 ( "Hello there" ), cstr2 ( "Goodbye now" );  
   cout << "The original string str1 is: " << str1 << endl;  
   cout << "The original string str2 is: " << str2 << endl;  
  
   // Element access to the non-const strings  
   basic_string <char>::reference refStr1 = str1 [6];  
   basic_string <char>::reference refStr2 = str2.at ( 3 );  
  
   cout << "The character with an index of 6 in string str1 is: "  
        << refStr1 << "." << endl;  
   cout << "The character with an index of 3 in string str2 is: "  
        << refStr2 << "." << endl;  
  
   // Element access to the const strings  
   basic_string <char>::const_reference crefStr1 = cstr1 [ cstr1.length ( ) ];  
   basic_string <char>::const_reference crefStr2 = cstr2.at ( 8 );  
  
   if ( crefStr1 == '\0' )  
      cout << "The null character is returned as a valid reference."  
           << endl;  
   else  
      cout << "The null character is not returned." << endl;  
   cout << "The character with index of 8 in the const string cstr2 is: "  
        << crefStr2 << "." << endl;  
}  
```  
  
##  <a name="pointer"></a>  basic_string::pointer  
 Um tipo que fornece um ponteiro para um elemento de caracteres em uma matriz de cadeia de caracteres ou caractere.  
  
```  
typedef typename allocator_type::pointer pointer;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo de **allocator_type::pointer**.  
  
 Para o tipo **string**, é equivalente a **char\***.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_pointer.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   basic_string<char>::pointer pstr1a = "In Here";  
   char *cstr1b = "Out There";  
   cout << "The string pstr1a is: " << pstr1a <<  "." << endl;  
   cout << "The C-string cstr1b is: " << cstr1b << "." << endl;  
}  
```  
  
```Output  
The string pstr1a is: In Here.  
The C-string cstr1b is: Out There.  
```  
  
##  <a name="pop_back"></a>  basic_string::pop_back  
 Apaga o último elemento da cadeia de caracteres.  
  
```  
void pop_back();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função membro chama `erase(size() - 1)` efetivamente para apagar o último elemento da sequência, que não deve ser vazio.  
  
##  <a name="push_back"></a>  basic_string::push_back  
 Adiciona um elemento ao final de uma cadeia de caracteres.  
  
```  
void push_back(value_type _Ch);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Ch`  
 O caractere a ser adicionado ao final da cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 A função membro chama efetivamente [insert](#insert)( [end](#end), _ *Ch* ).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_push_back.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   string str1 ( "abc" );  
   basic_string <char>::iterator str_Iter, str1_Iter;  
  
   cout << "The original string str1 is: ";  
   for ( str_Iter = str1.begin( ); str_Iter != str1.end( ); str_Iter++ )  
      cout << *str_Iter;  
   cout << endl;  
  
   // str1.push_back ( 'd' );  
   str1_Iter = str1.end ( );  
   str1_Iter--;  
   cout << "The last character-letter of the modified str1 is now: "  
        << *str1_Iter << endl;  
  
   cout << "The modified string str1 is: ";  
   for ( str_Iter = str1.begin( ); str_Iter != str1.end( ); str_Iter++ )  
      cout << *str_Iter;  
   cout << endl;  
}  
```  
  
```Output  
The original string str1 is: abc  
The last character-letter of the modified str1 is now: c  
The modified string str1 is: abc  
```  
  
##  <a name="rbegin"></a>  basic_string::rbegin  
 Retorna um iterador ao primeiro elemento em uma cadeia invertida.  
  
```  
const_reverse_iterator rbegin() const;

 
reverse_iterator rbegin();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um iterador de acesso aleatório para o primeiro elemento em uma cadeia de caracteres invertida, indicando qual seria o último elemento na cadeia de caracteres não invertida correspondente.  
  
### <a name="remarks"></a>Comentários  
 `rbegin` é usado com uma cadeia de caracteres invertida assim como [begin](#begin) é usado com uma cadeia de caracteres.  
  
 Se o valor retornado de `rbegin` é atribuído a um `const_reverse_iterator`, o objeto de cadeia de caracteres não pode ser modificado. Se o valor retornado de `rbegin` é atribuído a um `reverse_iterator`, o objeto de cadeia de caracteres pode ser modificado.  
  
 `rbegin` pode ser usado para inicializar uma iteração em uma cadeia de caracteres no sentido inverso.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_rbegin.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   string str1 ( "Able was I ere I saw Elba" ), str2;  
   basic_string <char>::reverse_iterator str_rIter, str1_rIter, str2_rIter;  
   basic_string <char>::const_reverse_iterator str1_rcIter;  
  
   str1_rIter = str1.rbegin ( );  
   // str1_rIter--;  
   cout << "The first character-letter of the reversed string str1 is: "  
        << *str1_rIter << endl;  
   cout << "The full reversed string str1 is:\n ";  
   for ( str_rIter = str1.rbegin( ); str_rIter != str1.rend( ); str_rIter++ )  
      cout << *str_rIter;  
   cout << endl;  
  
   // The dereferenced iterator can be used to modify a character  
 *str1_rIter = 'A';  
   cout << "The first character-letter of the modified str1 is now: "  
        << *str1_rIter << endl;  
   cout << "The full modified reversed string str1 is now:\n ";  
   for ( str_rIter = str1.rbegin( ); str_rIter != str1.rend( ); str_rIter++ )  
      cout << *str_rIter;  
   cout << endl;  
  
   // The following line would be an error because iterator is const  
   // *str1_rcIter = 'A';  
  
   // For an empty string, begin is equivalent to end  
   if ( str2.rbegin( ) == str2.rend ( ) )  
      cout << "The string str2 is empty." << endl;  
   else  
      cout << "The stringstr2  is not empty." << endl;  
}  
```  
  
```Output  
The first character-letter of the reversed string str1 is: a  
The full reversed string str1 is:  
 ablE was I ere I saw elbA  
The first character-letter of the modified str1 is now: A  
The full modified reversed string str1 is now:  
 AblE was I ere I saw elbA  
The string str2 is empty.  
```  
  
##  <a name="reference"></a>  basic_string::reference  
 Um tipo que fornece uma referência a um elemento armazenado em uma cadeia de caracteres.  
  
```  
typedef typename allocator_type::reference reference;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo **reference** pode ser usado para modificar o valor de um elemento.  
  
 O tipo é sinônimo de **allocator_type::reference**.  
  
 Para o tipo **string**, é equivalente a **chr&**.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [at](#at) que demonstra como declarar e usar **reference**.  
  
##  <a name="rend"></a>  basic_string::rend  
 Retorna um iterador que trata do local após o último elemento em uma cadeia de caracteres invertida.  
  
```  
const_reverse_iterator rend() const;

 
reverse_iterator rend();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório inverso que trata do local após o último elemento em uma cadeia de caracteres invertida.  
  
### <a name="remarks"></a>Comentários  
 `rend` é usado com uma cadeia de caracteres invertida assim como [end](#end) é usado com uma cadeia de caracteres.  
  
 Se o valor retornado de `rend` é atribuído a um `const_reverse_iterator`, o objeto de cadeia de caracteres não pode ser modificado. Se o valor retornado de `rend` é atribuído a um `reverse_iterator`, o objeto de cadeia de caracteres pode ser modificado.  
  
 `rend` pode ser usado para testar se um iterador inverso alcançou o fim da sua cadeia de caracteres.  
  
 O valor retornado por `rend` não deve ser desreferenciado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_rend.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   string str1 ("Able was I ere I saw Elba"), str2;  
   basic_string <char>::reverse_iterator str_rIter, str1_rIter, str2_rIter;  
   basic_string <char>::const_reverse_iterator str1_rcIter;  
  
   str1_rIter = str1.rend ( );  
   str1_rIter--;  
   cout << "The last character-letter of the reversed string str1 is: "  
        << *str1_rIter << endl;  
   cout << "The full reversed string str1 is:\n ";  
   for ( str_rIter = str1.rbegin( ); str_rIter != str1.rend( ); str_rIter++ )  
      cout << *str_rIter;  
   cout << endl;  
  
   // The dereferenced iterator can be used to modify a character  
 *str1_rIter = 'o';  
   cout << "The last character-letter of the modified str1 is now: "  
        << *str1_rIter << endl;  
   cout << "The full modified reversed string str1 is now:\n ";  
   for ( str_rIter = str1.rbegin( ); str_rIter != str1.rend( ); str_rIter++ )  
      cout << *str_rIter;  
   cout << endl;  
  
   // The following line would be an error because iterator is const  
   // *str1_rcIter = 'T';  
  
   // For an empty string, end is equivalent to begin  
   if ( str2.rbegin( ) == str2.rend ( ) )  
      cout << "The string str2 is empty." << endl;  
   else  
      cout << "The stringstr2  is not empty." << endl;  
}  
```  
  
```Output  
The last character-letter of the reversed string str1 is: A  
The full reversed string str1 is:  
 ablE was I ere I saw elbA  
The last character-letter of the modified str1 is now: o  
The full modified reversed string str1 is now:  
 ablE was I ere I saw elbo  
The string str2 is empty.  
```  
  
##  <a name="replace"></a>  basic_string::replace  
 Substitui elementos em uma cadeia de caractere em uma posição especificada por caracteres especificados ou copiados de outros intervalos de cadeia de caracteres ou cadeias C.  
  
```  
basic_string<CharType, Traits, Allocator>& replace(
    size_type _Pos1,   
    size_type _Num1,  
    const value_type* ptr);

basic_string<CharType, Traits, Allocator>& replace(
    size_type _Pos1,   
    size_type _Num1,  
    const basic_string<CharType, Traits, Allocator>& str);

basic_string<CharType, Traits, Allocator>& replace(
    size_type _Pos1,   
    size_type _Num1,  
    const value_type* ptr,   
    size_type _Num2);

basic_string<CharType, Traits, Allocator>& replace(
    size_type _Pos1,   
    size_type _Num1,  
    const basic_string<CharType, Traits, Allocator>& str,   
    size_type _Pos2,   
    size_type _Num2);

basic_string<CharType, Traits, Allocator>& replace(
    size_type _Pos1,   
    size_type _Num1,  
    size_type count,   
    value_type _Ch);

basic_string<CharType, Traits, Allocator>& replace(
    iterator first0,   
    iterator last0,  
    const value_type* ptr);

basic_string<CharType, Traits, Allocator>& replace(
    iterator first0,   
    iterator last0,  
    const basic_string<CharType, Traits, Allocator>& str);

basic_string<CharType, Traits, Allocator>& replace(
    iterator first0,  
    iterator last0,  
    const value_type* ptr,   
    size_type _Num2);

basic_string<CharType, Traits, Allocator>& replace(
    iterator first0,   
    iterator last0,  
    size_type _Num2,   
    value_type _Ch);

template <class InputIterator>  
basic_string<CharType, Traits, Allocator>& replace(
    iterator first0,   
    iterator last0,  
    InputIterator first,   
    InputIterator last);

basic_string<CharType, Traits, Allocator>& replace(
    iterator first0,  
    iterator last0,  
    const_pointer first,  
    const_pointer last);

basic_string<CharType, Traits, Allocator>& replace(
    iterator first0,  
    iterator last0,  
    const_iterator first,  
    const_iterator last);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 A cadeia de caracteres que deve ser uma fonte de caracteres para a cadeia de caracteres do operando.  
  
 `_Pos1`  
 O índice da cadeia de caracteres do operando na qual a substituição começa.  
  
 `_Num1`  
 O número máximo de caracteres a serem substituídos na cadeia de caracteres do operando.  
  
 *_Pos2*  
 O índice da cadeia de caracteres do parâmetro na qual a cópia começa.  
  
 `_Num2`  
 O número máximo de caracteres a serem usados da cadeia de caracteres do C do parâmetro.  
  
 `ptr`  
 A cadeia de caracteres do C que deve ser uma fonte de caracteres para a cadeia de caracteres do operando.  
  
 `_Ch`  
 O caractere a ser copiado para a cadeia de caracteres do operando.  
  
 * first0*  
 Um iterador que trata do primeiro caractere a ser removido na cadeia de caracteres do operando.  
  
 * last0*  
 Um iterador que trata do último caractere a ser removido na cadeia de caracteres do operando.  
  
 `first`  
 Um iterador, const_pointer ou const_iterator, que trata do primeiro caractere a ser copiado na cadeia de caracteres do parâmetro.  
  
 `last`  
 Um iterador, const_pointer ou const_iterator, que trata do último caractere a ser copiado na cadeia de caracteres do parâmetro.  
  
 `count`  
 O número de vezes que `_Ch` é copiado para a cadeia de caracteres do operando.  
  
### <a name="return-value"></a>Valor de retorno  
 A cadeia de caracteres do operando com a substituição feita.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_replace.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
  
   // The first two member functions replace  
   // part of the operand string with  
   // characters from a parameter string or C-string  
   string result1a, result1b;  
   string s1o ( "AAAAAAAA" );  
   string s1p ( "BBB" );  
   const char* cs1p = "CCC";  
   cout << "The operand string s1o is: " << s1o << endl;  
   cout << "The parameter string s1p is: " << s1p << endl;  
   cout << "The parameter C-string cs1p is: " << cs1p << endl;  
   result1a = s1o.replace ( 1 , 3 , s1p );  
   cout << "The result of s1o.replace ( 1 , 3 , s1p )\n is "   
        << "the string: " << result1a << "." << endl;  
   result1b = s1o.replace ( 5 , 3 , cs1p );  
   cout << "The result of s1o.replace ( 5 , 3 , cs1p )\n is "   
        << "the string: " << result1b << "." << endl;  
   cout << endl;  
  
   // The third & fourth member function replace  
   // part of the operand string with characters  
   // form part of a parameter string or C-string  
   string result2a, result2b;  
   string s2o ( "AAAAAAAA" );  
   string s2p ( "BBB" );  
   const char* cs2p = "CCC";  
   cout << "The operand string s2o is: " << s2o << endl;  
   cout << "The parameter string s1p is: " << s2p << endl;  
   cout << "The parameter C-string cs2p is: " << cs2p << endl;  
   result2a = s2o.replace ( 1 , 3 , s2p , 1 , 2 );  
   cout << "The result of s2o.replace (1, 3, s2p, 1, 2)\n is "   
        << "the string: " << result2a << "." << endl;  
   result2b = s2o.replace ( 4 , 3 , cs2p , 1 );  
   cout << "The result of s2o.replace (4 ,3 ,cs2p)\n is "   
        << "the string: " << result2b << "." << endl;  
   cout << endl;  
  
   // The fifth member function replaces  
   // part of the operand string with characters  
   string result3a;  
   string s3o ( "AAAAAAAA" );  
   char ch3p = 'C';  
   cout << "The operand string s3o is: " << s3o << endl;  
   cout << "The parameter character c1p is: " << ch3p << endl;  
   result3a = s3o.replace ( 1 , 3 , 4 , ch3p );  
   cout << "The result of s3o.replace(1, 3, 4, ch3p)\n is "   
        << "the string: " << result3a << "." << endl;  
   cout << endl;  
  
   // The sixth & seventh member functions replace  
   // part of the operand string, delineated with iterators,  
   // with a parameter string or C-string  
   string s4o ( "AAAAAAAA" );  
   string s4p ( "BBB" );  
   const char* cs4p = "CCC";  
   cout << "The operand string s4o is: " << s4o << endl;  
   cout << "The parameter string s4p is: " << s4p << endl;  
   cout << "The parameter C-string cs4p is: " << cs4p << endl;  
   basic_string<char>::iterator IterF0, IterL0;  
   IterF0 = s4o.begin ( );  
   IterL0 = s4o.begin ( ) + 3;  
   string result4a, result4b;  
   result4a = s4o.replace ( IterF0 , IterL0 , s4p );  
   cout << "The result of s1o.replace (IterF0, IterL0, s4p)\n is "   
        << "the string: " << result4a << "." << endl;  
   result4b = s4o.replace ( IterF0 , IterL0 , cs4p );  
   cout << "The result of s4o.replace (IterF0, IterL0, cs4p)\n is "   
        << "the string: " << result4b << "." << endl;  
   cout << endl;  
  
   // The 8th member function replaces  
   // part of the operand string delineated with iterators  
   // with a number of characters from a parameter C-string  
   string s5o ( "AAAAAAAF" );  
   const char* cs5p = "CCCBB";  
   cout << "The operand string s5o is: " << s5o << endl;  
   cout << "The parameter C-string cs5p is: " << cs5p << endl;  
   basic_string<char>::iterator IterF1, IterL1;  
   IterF1 = s5o.begin ( );  
   IterL1 = s5o.begin ( ) + 4;  
   string result5a;  
   result5a = s5o.replace ( IterF1 , IterL1 , cs5p , 4 );  
   cout << "The result of s5o.replace (IterF1, IterL1, cs4p ,4)\n is "   
        << "the string: " << result5a << "." << endl;  
   cout << endl;  
  
   // The 9th member function replaces  
   // part of the operand string delineated with iterators  
   // with specified characters  
   string s6o ( "AAAAAAAG" );  
   char ch6p = 'q';  
   cout << "The operand string s6o is: " << s6o << endl;  
   cout << "The parameter character ch6p is: " << ch6p << endl;  
   basic_string<char>::iterator IterF2, IterL2;  
   IterF2 = s6o.begin ( );  
   IterL2 = s6o.begin ( ) + 3;  
   string result6a;  
   result6a = s6o.replace ( IterF2 , IterL2 , 4 , ch6p );  
   cout << "The result of s6o.replace (IterF1, IterL1, 4, ch6p)\n is "   
        << "the string: " << result6a << "." << endl;  
   cout << endl;  
  
   // The 10th member function replaces  
   // part of the operand string delineated with iterators  
   // with part of a parameter string delineated with iterators  
   string s7o ( "OOOOOOO" );  
   string s7p ( "PPPP" );  
   cout << "The operand string s7o is: " << s7o << endl;  
   cout << "The parameter string s7p is: " << s7p << endl;  
   basic_string<char>::iterator IterF3, IterL3, IterF4, IterL4;  
   IterF3 = s7o.begin ( ) + 1;  
   IterL3 = s7o.begin ( ) + 3;  
   IterF4 = s7p.begin ( );  
   IterL4 = s7p.begin ( ) + 2;  
   string result7a;  
   result7a = s7o.replace ( IterF3 , IterL3 , IterF4 , IterL4 );  
   cout << "The result of s7o.replace (IterF3 ,IterL3 ,IterF4 ,IterL4)\n is "   
        << "the string: " << result7a << "." << endl;  
   cout << endl;  
}  
```  
  
```Output  
The operand string s1o is: AAAAAAAA  
The parameter string s1p is: BBB  
The parameter C-string cs1p is: CCC  
The result of s1o.replace ( 1 , 3 , s1p )  
 is the string: ABBBAAAA.  
The result of s1o.replace ( 5 , 3 , cs1p )  
 is the string: ABBBACCC.  
  
The operand string s2o is: AAAAAAAA  
The parameter string s1p is: BBB  
The parameter C-string cs2p is: CCC  
The result of s2o.replace (1, 3, s2p, 1, 2)  
 is the string: ABBAAAA.  
The result of s2o.replace (4 ,3 ,cs2p)  
 is the string: ABBAC.  
  
The operand string s3o is: AAAAAAAA  
The parameter character c1p is: C  
The result of s3o.replace(1, 3, 4, ch3p)  
 is the string: ACCCCAAAA.  
  
The operand string s4o is: AAAAAAAA  
The parameter string s4p is: BBB  
The parameter C-string cs4p is: CCC  
The result of s1o.replace (IterF0, IterL0, s4p)  
 is the string: BBBAAAAA.  
The result of s4o.replace (IterF0, IterL0, cs4p)  
 is the string: CCCAAAAA.  
  
The operand string s5o is: AAAAAAAF  
The parameter C-string cs5p is: CCCBB  
The result of s5o.replace (IterF1, IterL1, cs4p ,4)  
 is the string: CCCBAAAF.  
  
The operand string s6o is: AAAAAAAG  
The parameter character ch6p is: q  
The result of s6o.replace (IterF1, IterL1, 4, ch6p)  
 is the string: qqqqAAAAG.  
  
The operand string s7o is: OOOOOOO  
The parameter string s7p is: PPPP  
The result of s7o.replace (IterF3 ,IterL3 ,IterF4 ,IterL4)  
 is the string: OPPOOOO.  
```  
  
##  <a name="reserve"></a>  basic_string::reserve  
 Define a capacidade da cadeia de caracteres para um número pelo menos tão grande quanto um número especificado.  
  
```  
void reserve(size_type count = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `count`  
 O número de caracteres para os quais a memória está sendo reservada.  
  
### <a name="remarks"></a>Comentários  
 Ter capacidade suficiente é importante porque as realocações são um processo demorado e invalidam todas as referências, os ponteiros e os iteradores que se referem aos caracteres em uma cadeia de caracteres.  
  
 O conceito de capacidade para objetos do tipo cadeias de caracteres é igual ao conceito de objetos do tipo vetor. Ao contrário de vetor, a função membro **reserve** pode ser chamada para reduzir a capacidade de um objeto. A solicitação é de não associação e pode ocorrer ou não. Como o valor padrão do parâmetro é zero, uma chamada para **reserve** é uma solicitação de não associação para reduzir a capacidade da cadeia de caracteres a fim de ajustar o número de caracteres presentes atualmente na cadeia de caracteres. A capacidade nunca é reduzida abaixo do número atual de caracteres.  
  
 Chamar `reserve` é a única maneira possível de reduzir a capacidade de uma cadeia de caracteres. No entanto, conforme observado acima, essa solicitação é de não associação e pode ocorrer ou não.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_reserve.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   string str1 ("Hello world");  
   cout << "The original string str1 is: " << str1 << endl;  
  
   basic_string <char>::size_type sizeStr1, sizerStr1;  
   sizeStr1 = str1.size ( );  
   basic_string <char>::size_type capStr1, caprStr1;  
   capStr1 = str1.capacity ( );  
  
   // Compare size & capacity of the original string  
   cout << "The current size of original string str1 is: "   
        << sizeStr1 << "." << endl;  
   cout << "The capacity of original string str1 is: "  
        << capStr1 << "." << endl << endl;  
  
   // Compare size & capacity of the string  
   // with added capacity  
   str1.reserve ( 40 );  
   sizerStr1 = str1.size ( );  
   caprStr1 = str1.capacity ( );  
  
   cout << "The string str1with augmented capacity is: "  
        << str1 << endl;  
   cout << "The current size of string str1 is: "   
        << sizerStr1 << "." << endl;  
   cout << "The new capacity of string str1 is: "  
        << caprStr1 << "." << endl << endl;  
  
   // Compare size & capacity of the string  
   // with downsized capacity  
   str1.reserve ( );  
   basic_string <char>::size_type sizedStr1;  
   basic_string <char>::size_type capdStr1;  
   sizedStr1 = str1.size ( );  
   capdStr1 = str1.capacity ( );  
  
   cout << "The string str1 with downsized capacity is: "  
        << str1 << endl;  
   cout << "The current size of string str1 is: "   
        << sizedStr1 << "." << endl;  
   cout << "The reduced capacity of string str1 is: "  
        << capdStr1 << "." << endl << endl;  
}  
```  
  
```Output  
The original string str1 is: Hello world  
The current size of original string str1 is: 11.  
The capacity of original string str1 is: 15.  
  
The string str1with augmented capacity is: Hello world  
The current size of string str1 is: 11.  
The new capacity of string str1 is: 47.  
  
The string str1 with downsized capacity is: Hello world  
The current size of string str1 is: 11.  
The reduced capacity of string str1 is: 47.  
```  
  
##  <a name="resize"></a>  basic_string::resize  
 Especifica um novo tamanho para uma cadeia de caracteres, acrescentando ou apagando elementos conforme necessário.  
  
```  
void resize(
    size_type count,);

void resize(
    size_type count,  
    _Elem _Ch);
```  
  
### <a name="parameters"></a>Parâmetros  
 `count`  
 O novo tamanho da cadeia de caracteres.  
  
 `_Ch`  
 O valor com o qual os caracteres acrescentados serão inicializados se forem necessários elementos adicionais.  
  
### <a name="remarks"></a>Comentários  
 Se o tamanho resultante exceder o número máximo de caracteres, o formulário gerará `length_error`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_resize.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   string  str1 ( "Hello world" );  
   cout << "The original string str1 is: " << str1 << endl;  
  
   basic_string <char>::size_type sizeStr1;  
   sizeStr1 = str1.size ( );  
   basic_string <char>::size_type capStr1;  
   capStr1 = str1.capacity ( );  
  
   // Compare size & capacity of the original string  
   cout << "The current size of original string str1 is: "   
        << sizeStr1 << "." << endl;  
   cout << "The capacity of original string str1 is: "  
        << capStr1 << "." << endl << endl;  
  
   // Use resize to increase size by 2 elements: exclamations  
   str1.resize ( str1.size ( ) + 2 , '!' );  
   cout << "The resized string str1 is: " << str1 << endl;  
  
   sizeStr1 = str1.size ( );  
   capStr1 = str1.capacity ( );  
  
   // Compare size & capacity of a string after resizing  
   cout << "The current size of resized string str1 is: "   
        << sizeStr1 << "." << endl;  
   cout << "The capacity of resized string str1 is: "  
        << capStr1 << "." << endl << endl;  
  
   // Use resize to increase size by 20 elements:  
   str1.resize ( str1.size ( ) + 20 );  
   cout << "The resized string str1 is: " << str1 << endl;  
  
   sizeStr1 = str1.size ( );  
   capStr1 = str1.capacity ( );  
  
   // Compare size & capacity of a string after resizing  
   // note capacity increases automatically as required  
   cout << "The current size of modified string str1 is: "   
        << sizeStr1 << "." << endl;  
   cout << "The capacity of modified string str1 is: "  
        << capStr1 << "." << endl << endl;  
  
   // Use resize to downsize by 28 elements:  
   str1.resize ( str1.size ( ) - 28 );  
   cout << "The downsized string str1 is: " << str1 << endl;  
  
   sizeStr1 = str1.size (  );  
   capStr1 = str1.capacity (  );  
  
   // Compare size & capacity of a string after downsizing  
   cout << "The current size of downsized string str1 is: "   
        << sizeStr1 << "." << endl;  
   cout << "The capacity of downsized string str1 is: "  
        << capStr1 << "." << endl;  
}  
```  
  
```Output  
The original string str1 is: Hello world  
The current size of original string str1 is: 11.  
The capacity of original string str1 is: 15.  
  
The resized string str1 is: Hello world!!  
The current size of resized string str1 is: 13.  
The capacity of resized string str1 is: 15.  
  
The resized string str1 is: Hello world!!                      
The current size of modified string str1 is: 33.  
The capacity of modified string str1 is: 47.  
  
The downsized string str1 is: Hello  
The current size of downsized string str1 is: 5.  
The capacity of downsized string str1 is: 47.  
```  
  
##  <a name="reverse_iterator"></a>  basic_string::reverse_iterator  
 Um tipo que fornece uma referência a um elemento armazenado em uma cadeia de caracteres.  
  
```  
typedef std::reverse_iterator<iterator> reverse_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo `reverse_iterator` pode ser usado para modificar o valor de um caractere e é usado para iterar em uma cadeia de caracteres na ordem inversa.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [rbegin](#rbegin) que demonstra como declarar e usar `reverse_iterator`.  
  
##  <a name="rfind"></a>  basic_string::rfind  
 Pesquisa, para trás, em uma cadeia de caracteres, a primeira ocorrência de uma subcadeia que corresponde a uma sequência de caracteres especificada.  
  
```  
size_type rfind(
    value_type _Ch,   
    size_type _Off = npos) const;

 
size_type rfind(
    const value_type* ptr,  
    size_type _Off = npos) const;

 
size_type rfind(
    const value_type* ptr,   
    size_type _Off,  
    size_type count) const;

 
size_type rfind(
    const basic_string<CharType, Traits, Allocator>& str,  
    size_type _Off = npos) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Ch`  
 O valor de caractere que a função membro deve pesquisar.  
  
 `_Off`  
 Índice da posição em que a pesquisa deve começar.  
  
 `ptr`  
 A cadeia de caracteres do C que a função membro deve pesquisar.  
  
 `count`  
 O número de caracteres, contando a partir do primeiro caractere, na cadeia de caracteres do C que a função membro deve pesquisar.  
  
 `str`  
 A cadeia de caracteres que a função membro deve pesquisar.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice da última ocorrência, quando pesquisado no sentido inverso, do primeiro caractere da subsequência quando houver êxito, caso contrário, `npos`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_rfind.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   // The first member function  
   // searches for a single character in a string  
   string str1 ( "Hello Everyone" );  
   cout << "The original string str1 is: " << str1 << endl;  
   basic_string <char>::size_type indexCh1a, indexCh1b;  
   static const basic_string <char>::size_type npos = -1;  
  
   indexCh1a = str1.rfind ( "e" , 9 );  
   if ( indexCh1a != npos )  
      cout << "The index of the 1st 'e' found before the 9th"  
           << " position in str1 is: " << indexCh1a << endl;  
   else  
      cout << "The character 'e' was not found in str1 ." << endl;  
  
   indexCh1b = str1.rfind ( "x" );  
   if ( indexCh1b != npos )  
      cout << "The index of the 'x' found in str1 is: "  
           << indexCh1b << endl << endl;  
   else  
      cout << "The character 'x' was not found in str1."  
           << endl << endl;  
  
   // The second member function searches a string  
   // for a substring as specified by a C-string  
   string str2 ( "Let me make this perfectly clear." );  
   cout << "The original string str2 is: " << str2 << endl;  
   basic_string <char>::size_type indexCh2a, indexCh2b;  
  
   const char *cstr2 = "perfect";  
   indexCh2a = str2.rfind ( cstr2 , 30 );  
   if ( indexCh2a != npos )  
      cout << "The index of the 1st element of 'perfect' "  
           << "before\n the 30th position in str2 is: "  
           << indexCh2a << endl;  
   else  
      cout << "The substring 'perfect' was not found in str2 ."  
           << endl;  
  
   const char *cstr2b = "imperfectly";  
   indexCh2b = str2.rfind ( cstr2b , 30 );  
   if ( indexCh2b != npos )  
      cout << "The index of the 1st element of 'imperfect' "  
           << "before\n the 5th position in str3 is: "  
           << indexCh2b << endl;  
   else  
      cout << "The substring 'imperfect' was not found in str2 ."  
           << endl << endl;  
  
   // The third member function searches a string  
   // for a substring as specified by a C-string  
   string str3 ( "It is a nice day. I am happy." );  
   cout << "The original string str3 is: " << str3 << endl;  
   basic_string <char>::size_type indexCh3a, indexCh3b;  
  
   const char *cstr3a = "nice";  
   indexCh3a = str3.rfind ( cstr3a );  
   if ( indexCh3a != npos )  
      cout << "The index of the 1st element of 'nice' "  
           << "in str3 is: " << indexCh3a << endl;  
   else  
      cout << "The substring 'nice' was not found in str3 ."  
           << endl;  
  
   const char *cstr3b = "am";  
   indexCh3b = str3.rfind ( cstr3b , indexCh3a + 25 , 2 );  
   if ( indexCh3b != npos )  
      cout << "The index of the next occurrance of 'am' in "  
           << "str3 begins at: " << indexCh3b << endl << endl;  
   else  
      cout << "There is no next occurrence of 'am' in str3 ."  
           << endl << endl;  
  
   // The fourth member function searches a string  
   // for a substring as specified by a string  
   string str4 ( "This perfectly unclear." );  
   cout << "The original string str4 is: " << str4 << endl;  
   basic_string <char>::size_type indexCh4a, indexCh4b;  
  
   string str4a ( "clear" );  
   indexCh4a = str4.rfind ( str4a , 15 );  
   if (indexCh4a != npos )  
      cout << "The index of the 1st element of 'clear' "  
           << "before\n the 15th position in str4 is: "  
           << indexCh4a << endl;  
   else  
      cout << "The substring 'clear' was not found in str4 "  
           << "before the 15th position." << endl;  
  
   string str4b ( "clear" );  
   indexCh4b = str4.rfind ( str4b );  
   if ( indexCh4b != npos )  
      cout << "The index of the 1st element of 'clear' "  
           << "in str4 is: "  
           << indexCh4b << endl;  
   else  
      cout << "The substring 'clear' was not found in str4 ."  
           << endl << endl;  
}  
```  
  
```Output  
The original string str1 is: Hello Everyone  
The index of the 1st 'e' found before the 9th position in str1 is: 8  
The character 'x' was not found in str1.  
  
The original string str2 is: Let me make this perfectly clear.  
The index of the 1st element of 'perfect' before  
 the 30th position in str2 is: 17  
The substring 'imperfect' was not found in str2 .  
  
The original string str3 is: It is a nice day. I am happy.  
The index of the 1st element of 'nice' in str3 is: 8  
The index of the next occurrance of 'am' in str3 begins at: 20  
  
The original string str4 is: This perfectly unclear.  
The substring 'clear' was not found in str4 before the 15th position.  
The index of the 1st element of 'clear' in str4 is: 17  
```  
  
##  <a name="shrink_to_fit"></a>  basic_string::shrink_to_fit  
 Descarta a capacidade excedente da cadeia de caracteres.  
  
```  
void shrink_to_fit();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função membro elimina qualquer armazenamento desnecessário no contêiner.  
  
##  <a name="size"></a>  basic_string::size  
 Retorna o número de elementos em uma cadeia de caracteres.  
  
```  
size_type size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento da cadeia de caracteres.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_size.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   string str1 ("Hello world");  
   cout << "The original string str1 is: " << str1 << endl;  
  
   // The size and length member functions differ in name only  
   basic_string <char>::size_type sizeStr1, lenStr1;  
   sizeStr1 = str1.size (  );  
   lenStr1 = str1.length (  );  
  
   basic_string <char>::size_type capStr1, max_sizeStr1;  
   capStr1 = str1.capacity (  );  
   max_sizeStr1 = str1.max_size (  );  
  
   // Compare size, length, capacity & max_size of a string  
   cout << "The current size of original string str1 is: "   
        << sizeStr1 << "." << endl;  
   cout << "The current length of original string str1 is: "   
        << lenStr1 << "." << endl;  
   cout << "The capacity of original string str1 is: "  
        << capStr1 << "." << endl;  
   cout << "The max_size of original string str1 is: "   
        << max_sizeStr1 << "." << endl << endl;  
  
   str1.erase ( 6, 5 );  
   cout << "The modified string str1 is: " << str1 << endl;  
  
   sizeStr1 = str1.size ( );  
   lenStr1 = str1.length ( );  
   capStr1 = str1.capacity ( );  
   max_sizeStr1 = str1.max_size ( );  
  
   // Compare size, length, capacity & max_size of a string  
   // after erasing part of the original string  
   cout << "The current size of modified string str1 is: "   
        << sizeStr1 << "." << endl;  
   cout << "The current length of modified string str1 is: "   
        << lenStr1 << "." << endl;  
   cout << "The capacity of modified string str1 is: "  
        << capStr1 << "." << endl;  
   cout << "The max_size of modified string str1 is: "   
        << max_sizeStr1 << "." << endl;  
}  
```  
  
##  <a name="size_type"></a>  basic_string::size_type  
 Um tipo de inteiro sem sinal que pode representar o número de elementos e os índices em uma cadeia de caracteres.  
  
```  
typedef typename allocator_type::size_type size_type;  
```  
  
### <a name="remarks"></a>Comentários  
 É equivalente a **allocator_type::size_type**.  
  
 Para o tipo **string**, é equivalente a **size_t**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_size_type.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   string str1 ( "Hello world" );  
  
   basic_string <char>::size_type sizeStr1, capStr1;  
   sizeStr1 = str1.size (  );  
   capStr1 = str1.capacity (  );  
  
   cout << "The current size of string str1 is: "   
        << sizeStr1 << "." << endl;  
   cout << "The capacity of string str1 is: " << capStr1   
         << "." << endl;  
}  
```  
  
```Output  
The current size of string str1 is: 11.  
The capacity of string str1 is: 15.  
```  
  
##  <a name="substr"></a>  basic_string::substr  
 Copia uma subcadeia de, no máximo, um número de caracteres, de uma cadeia com início em uma posição especificada.  
  
```  
basic_string<CharType, Traits, Allocator> substr(
    size_type _Off = 0,  
    size_type count = npos) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Off`  
 Um índice que localiza o elemento na posição da qual é feita a cópia da cadeia de caracteres, com um valor padrão igual a 0.  
  
 `count`  
 O número de caracteres que devem ser copiados se estiverem presentes.  
  
### <a name="return-value"></a>Valor de retorno  
 Um objeto de subcadeia de caracteres que é uma cópia dos elementos do operando da cadeia de caracteres, começando na posição especificada pelo primeiro argumento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_substr.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
  
   string  str1 ("Heterological paradoxes are persistent.");  
   cout << "The original string str1 is: \n " << str1  
        << endl << endl;  
  
   basic_string <char> str2 = str1.substr ( 6 , 7 );  
   cout << "The substring str1 copied is: " << str2  
        << endl << endl;  
  
   basic_string <char> str3 = str1.substr (  );  
   cout << "The default substring str3 is: \n " << str3  
        <<  "\n which is the entire original string." << endl;  
}  
```  
  
```Output  
The original string str1 is:   
 Heterological paradoxes are persistent.  
  
The substring str1 copied is: logical  
  
The default substring str3 is:   
 Heterological paradoxes are persistent.  
 which is the entire original string.  
```  
  
##  <a name="swap"></a>  basic_string::swap  
 Troca o conteúdo das duas cadeias de caracteres.  
  
```  
void swap(
    basic_string<CharType, Traits, Allocator>& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 A cadeia de caracteres de origem cujos elementos devem ser trocados com os da cadeia de caracteres de destino.  
  
### <a name="remarks"></a>Comentários  
 Se as cadeias de caracteres que estão sendo trocadas tiverem o mesmo objeto alocador, a função membro `swap`:  
  
-   Ocorrerá em tempo constante.  
  
-   Não gerará exceções.  
  
-   Não invalidará referências, ponteiros ou iteradores que designam elementos nas duas cadeias de caracteres.  
  
 Caso contrário, executará uma série de atribuições de elemento e de chamadas do construtor proporcional ao número de elementos nas duas sequências controladas.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_swap.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
  
   // Declaring an objects of type basic_string<char>  
   string s1 ( "Tweedledee" );  
   string s2 ( "Tweedledum" );  
   cout << "Before swapping string s1 and s2:" << endl;  
   cout << " The basic_string s1 = " << s1 << "." << endl;  
   cout << " The basic_string s2 = " << s2 << "." << endl;  
  
   s1.swap ( s2 );  
   cout << "After swapping string s1 and s2:" << endl;  
   cout << " The basic_string s1 = " << s1 << "." << endl;  
   cout << " The basic_string s2 = " << s2 << "." << endl;  
}  
```  
  
```Output  
Before swapping string s1 and s2:  
 The basic_string s1 = Tweedledee.  
 The basic_string s2 = Tweedledum.  
After swapping string s1 and s2:  
 The basic_string s1 = Tweedledum.  
 The basic_string s2 = Tweedledee.  
```  
  
##  <a name="traits_type"></a>  basic_string::traits_type  
 Um tipo para as características dos elementos armazenados em uma cadeia de caracteres.  
  
```  
typedef Traits traits_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do segundo parâmetro de modelo **Traits**.  
  
 Para o tipo **string**, é equivalente a **char_traits\<char>**.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [copy](../standard-library/char-traits-struct.md#copy) que demonstra como declarar e usar o `traits_type`.  
  
##  <a name="value_type"></a>  basic_string::value_type  
 Um tipo que representa o tipo de caracteres armazenados em uma cadeia de caracteres.  
  
```  
typedef typename allocator_type::value_type value_type;  
```  
  
### <a name="remarks"></a>Comentários  
 É equivalente a **traits_type::char_type** e é equivalente a `char` para objetos do tipo **string**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_string_value_type.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
  
   basic_string<char>::value_type ch1 = 'G';  
  
   char ch2 = 'H';  
  
   cout << "The character ch1 is: " << ch1 << "." << endl;  
   cout << "The character ch2 is: " << ch2 << "." << endl;  
}  
```  
  
```Output  
The character ch1 is: G.  
The character ch2 is: H.  
```  
  
## <a name="see-also"></a>Consulte também  
 [\<string>](../standard-library/string.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)


