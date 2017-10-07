---
title: Struct char_traits | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- iosfwd/std::char_traits
- iosfwd/std::char_traits::char_type
- iosfwd/std::char_traits::int_type
- iosfwd/std::char_traits::off_type
- iosfwd/std::char_traits::pos_type
- iosfwd/std::char_traits::state_type
- iosfwd/std::char_traits::assign
- iosfwd/std::char_traits::compare
- iosfwd/std::char_traits::copy
- iosfwd/std::char_traits::_Copy_s
- iosfwd/std::char_traits::eof
- iosfwd/std::char_traits::eq
- iosfwd/std::char_traits::eq_int_type
- iosfwd/std::char_traits::find
- iosfwd/std::char_traits::length
- iosfwd/std::char_traits::lt
- iosfwd/std::char_traits::move
- iosfwd/std::char_traits::_Move_s
- iosfwd/std::char_traits::not_eof
- iosfwd/std::char_traits::to_char_type
- iosfwd/std::char_traits::to_int_type
dev_langs:
- C++
helpviewer_keywords:
- char_traits struct
- char_traits class
ms.assetid: 568e59f0-4521-4207-9223-9dcf6a16d620
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 65f4e356ad0d46333b0d443d0fd6ac0b9f2b6f58
ms.openlocfilehash: af8e9c141db96bd0ce5ddd1dbca922799212b401
ms.contentlocale: pt-br
ms.lasthandoff: 10/03/2017

---
# <a name="chartraits-struct"></a>Struct char_traits
A struct char_traits descreve os atributos associados a um caractere.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class CharType>  
struct char_traits;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `CharType`  
 O tipo de dados do elemento.  
  
## <a name="remarks"></a>Comentários  
 A struct de modelo descreve várias características de caractere para o tipo **CharType**. A classe de modelo [basic_string](../standard-library/basic-string-class.md), bem como várias classes de modelo iostream, incluindo [basic_ios](../standard-library/basic-ios-class.md), usam essas informações para manipular elementos do tipo **CharType**. Esse tipo de elemento não deve exigir construção ou destruição explícita. Ele deve fornecer um construtor padrão, um construtor de cópia e um operador de atribuição com a semântica esperada. Uma cópia bit a bit deve ter o mesmo efeito que uma atribuição. Nenhuma das funções membro da struct char_traits pode gerar exceções.  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[char_type](#char_type)|Um tipo de caractere.|  
|[int_type](#int_type)|Um tipo de inteiro que pode representar um caractere do tipo `char_type` ou um caractere de EOF (final de arquivo).|  
|[off_type](#off_type)|Um tipo de inteiro que pode representar compensações entre posições em um fluxo.|  
|[pos_type](#pos_type)|Um tipo de inteiro que pode representar posições em um fluxo.|  
|[state_type](#state_type)|Um tipo que representa o estado de conversão de caracteres multibyte em um fluxo.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[assign](#assign)|Atribui um valor de caractere a outro.|  
|[compare](#compare)|Compara até um número especificado de caracteres em duas cadeias de caracteres.|  
|[copy](#copy)|Copia um número especificado de caracteres de uma cadeia de caracteres para outra. Preterido. Use [char_traits::_Copy_s](#copy_s) em vez disso.|  
|[_Copy_s](#copy_s)|Copia um número especificado de caracteres de uma cadeia de caracteres para outra.|  
|[eof](#eof)|Retorna o caractere de EOF (final de arquivo).|  
|[eq](#eq)|Testa se dois caracteres `char_type` são iguais.|  
|[eq_int_type](#eq_int_type)|Testa se dois caracteres representados como `int_type`s são iguais.|  
|[find](#find)|Pesquisa a primeira ocorrência de um caractere especificado em um intervalo de caracteres.|  
|[length](#length)|Retorna o comprimento de uma cadeia de caracteres.|  
|[lt](#lt)|Testa se um caractere é menor que outro.|  
|[move](#move)|Copia um número especificado de caracteres em uma sequência para outra sequência possivelmente sobreposta. Preterido. Use [char_traits::_Move_s](#move_s) em vez disso.|  
|[_Move_s](#move_s)|Copia um número especificado de caracteres em uma sequência para outra sequência possivelmente sobreposta.|  
|[not_eof](#not_eof)|Testa se um caractere é o caractere EOF (final de arquivo).|  
|[to_char_type](#to_char_type)|Converte um caractere `int_type` para o caractere `char_type` correspondente e retorna o resultado.|  
|[to_int_type](#to_int_type)|Converte um caractere `char_type` para o caractere `int_type` correspondente e retorna o resultado.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<string>  
  
 **Namespace:** std  
  
##  <a name="assign"></a>  char_traits::assign  
 Atribui um valor de caractere a outro ou para um intervalo de elementos em uma cadeia de caracteres.  
  
```  
static void assign(char_type& _CharTo,
    const char_type& _CharFrom);

static char_type *assign(char_type* strTo,
    size_t _Num,
    char_type _CharFrom);
```  
  
### <a name="parameters"></a>Parâmetros  
 **_** *CharFrom*  
 O caractere cujo valor deve ser atribuído.  
  
 *_CharTo*  
 O elemento ao qual deve ser atribuído o valor de caractere.  
  
 * strTo*  
 A matriz de caracteres ou cadeia de caracteres a cujos elementos iniciais devem ser atribuídos valores de caracteres.  
  
 `_Num`  
 O número de elementos aos quais serão atribuídos valores.  
  
### <a name="return-value"></a>Valor retornado  
 A segunda função membro retorna um ponteiro para a cadeia de caracteres a cujos primeiros `_Num` elementos foram atribuídos valores de *_CharFrom*.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// char_traits_assign.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
  
   // The first member function assigning   
   // one character value to another character  
   char ChTo = 't';  
   const char ChFrom = 'f';  
   cout << "The initial characters ( ChTo , ChFrom ) are: ( "  
        << ChTo << " , " << ChFrom << " )." << endl;  
   char_traits<char>::assign ( ChTo , ChFrom );  
   cout << "After assigning, the characters ( ChTo , ChFrom ) are: ( "  
        << ChTo << " , " << ChFrom << " )." << endl << endl;  
  
   // The second member function assigning   
   // character values to initial part of a string  
   char_traits<char>::char_type s1[] = "abcd-1234-abcd";  
   char_traits<char>::char_type* result1;  
   cout << "The target string s1 is: " << s1 << endl;  
   result1 = char_traits<char>::assign ( s1 , 4 , 'f' );  
   cout << "The result1 = assign ( s1 , 4 , 'f' ) is: "  
        << result1 << endl;  
}  
```  
  
```Output  
The initial characters ( ChTo , ChFrom ) are: ( t , f ).  
After assigning, the characters ( ChTo , ChFrom ) are: ( f , f ).  
  
The target string s1 is: abcd-1234-abcd  
The result1 = assign ( s1 , 4 , 'f' ) is: ffff-1234-abcd  
```  
  
##  <a name="char_type"></a>  char_traits::char_type  
 Um tipo de caractere.  
  
```  
typedef CharType char_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo **CharType**.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [copy](#copy) que demonstra como declarar e usar o `char_type`.  
  
##  <a name="compare"></a>  char_traits::compare  
 Compara até um número especificado de caracteres em duas cadeias de caracteres.  
  
```  
static int compare(const char_type* str1,
    const char_type* str2,
    size_t _Num);
```  
  
### <a name="parameters"></a>Parâmetros  
 * str1*  
 A primeira das duas cadeias de caracteres a serem comparadas entre si.  
  
 * str2*  
 A segunda das duas cadeias de caracteres a serem comparadas entre si.  
  
 `_Num`  
 O número de elementos nas cadeias de caracteres a serem comparados.  
  
### <a name="return-value"></a>Valor retornado  
 Um valor negativo se a primeira cadeia de caracteres for menor que a segunda cadeia de caracteres; 0 se as duas cadeias de caracteres forem iguais; ou um valor positivo se a primeira cadeia de caracteres for maior que a segunda cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 A comparação entre as cadeias de caracteres é feita por elemento, primeiro testando a igualdade e então, se um par de elementos na sequência tiver um teste não igual, eles são testados para menor que.  
  
 Se duas cadeias de caracteres comparem-se como iguais em um intervalo, mas uma for mais longa do que a outra, a mais curta das duas será menor que a mais longa.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// char_traits_compare.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main() {  
   using namespace std;  
  
   char_traits<char>::char_type* s1 = "CAB";  
   char_traits<char>::char_type* s2 = "ABC";  
   char_traits<char>::char_type* s3 = "ABC";  
   char_traits<char>::char_type* s4 = "ABCD";  
  
   cout << "The string s1 is: " << s1 << endl;  
   cout << "The string s2 is: " << s2 << endl;  
   cout << "The string s3 is: " << s3 << endl;  
   cout << "The string s4 is: " << s4 << endl;  
  
   int comp1, comp2, comp3, comp4;  
   comp1 = char_traits<char>::compare ( s1 , s2 , 2 );  
   comp2 = char_traits<char>::compare ( s2 , s3 , 3 );  
   comp3 = char_traits<char>::compare ( s3 , s4 , 4 );  
   comp4 = char_traits<char>::compare ( s4 , s3 , 4 );  
   cout << "compare ( s1 , s2 , 2 ) = " << comp1 << endl;  
   cout << "compare ( s2 , s3 , 3 ) = " << comp2 << endl;  
   cout << "compare ( s3 , s4 , 4 ) = " << comp3 << endl;  
   cout << "compare ( s4 , s3 , 4 ) = " << comp4 << endl;  
}  
```  
  
##  <a name="copy"></a>  char_traits::copy  
 Copia um número especificado de caracteres de uma cadeia de caracteres para outra.  
  
 Esse método pode não ser seguro, pois depende do chamador para verificar se os valores passados estão corretos. Considere usar [char_traits::_Copy_s](#copy_s) em vez disso.  
  
```  
static char_type *copy(char_type* _To,
    const char_type* _From,
    size_t _Num);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_To`  
 O elemento no início da matriz de cadeia de caracteres ou caractere direcionado para receber a sequência de caracteres copiada.  
  
 `_From`  
 O elemento no início da matriz de cadeia de caracteres ou caractere de origem a ser copiado.  
  
 `_Num`  
 O número de elementos a serem copiados.  
  
### <a name="return-value"></a>Valor retornado  
 O primeiro elemento copiado para a matriz de caracteres ou cadeia de caracteres destinada a receber a sequência de caracteres copiada.  
  
### <a name="remarks"></a>Comentários  
 As sequências de caracteres de origem e destino não devem se sobrepor.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// char_traits_copy.cpp  
// compile with: /EHsc /W3  
#include <string>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   char_traits<char>::char_type s1[] = "abcd-1234-abcd";  
   char_traits<char>::char_type s2[] = "ABCD-1234";  
   char_traits<char>::char_type* result1;  
   cout << "The source string is: " << s1 << endl;  
   cout << "The destination string is: " << s2 << endl;  
   // Note: char_traits::copy is potentially unsafe, consider  
   // using char_traits::_Copy_s instead.  
   result1 = char_traits<char>::copy ( s1 , s2 , 4 );  // C4996  
   cout << "The result1 = copy ( s1 , s2 , 4 ) is: "  
        << result1 << endl;  
}  
```  
  
```Output  
The source string is: abcd-1234-abcd  
The destination string is: ABCD-1234  
The result1 = copy ( s1 , s2 , 4 ) is: ABCD-1234-abcd  
```  
  
##  <a name="copy_s"></a>  char_traits::_Copy_s  
 Copia um número especificado de caracteres de uma cadeia de caracteres para outra.  
  
```  
static char_type *_Copy_s(
    char_type* dest,  
    size_t dest_size,  
    const char_type* _From,  
    size_t count);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dest`  
 A matriz de caractere ou cadeia de caracteres de destino para receber a sequência de caracteres copiada.  
  
 `dest_size`  
 O tamanho do `dest`. Se `char_type` for `char`, esse tamanho estará em bytes. Se `char_type` for `wchar_t`, esse tamanho estará em palavras.  
  
 `_From`  
 A matriz de caracteres ou cadeia de caracteres de origem a ser copiada.  
  
 `count`  
 O número de elementos a serem copiados.  
  
### <a name="return-value"></a>Valor retornado  
 A matriz de caractere ou cadeia de caracteres de destino para receber a sequência de caracteres copiada.  
  
### <a name="remarks"></a>Comentários  
 As sequências de caracteres de origem e destino não devem se sobrepor.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// char_traits__Copy_s.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )  
{  
    using namespace std;  
  
    char_traits<char>::char_type s1[] = "abcd-1234-abcd";  
    char_traits<char>::char_type s2[] = "ABCD-1234";  
    char_traits<char>::char_type* result1;  
    cout << "The source string is: " << s1 << endl;  
    cout << "The destination string is: " << s2 << endl;  
    result1 = char_traits<char>::_Copy_s(s1,  
        char_traits<char>::length(s1), s2, 4);  
    cout << "The result1 = _Copy_s(s1, "  
         << "char_traits<char>::length(s1), s2, 4) is: "  
         << result1 << endl;  
}  
```  
  
```Output  
The source string is: abcd-1234-abcd  
The destination string is: ABCD-1234  
The result1 = _Copy_s(s1, char_traits<char>::length(s1), s2, 4) is: ABCD-1234-abcd  
```  
  
##  <a name="eof"></a>  char_traits::eof  
 Retorna o caractere de EOF (final de arquivo).  
  
```  
static int_type eof();
```  
  
### <a name="return-value"></a>Valor retornado  
 O caractere EOF.  
  
### <a name="remarks"></a>Comentários  
 Um valor que representa o fim do arquivo (como `EOF` ou `WEOF`).  
  
 Os padrão C++ determina que esse valor não deve corresponder a um valor `char_type` válido. O compilador do Visual C++ impõe essa restrição para o tipo `char`, mas não para o tipo `wchar_t`. O exemplo abaixo demonstra isso.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// char_traits_eof.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main()  
{  
    using namespace std;  
  
    char_traits<char>::char_type ch1 = 'x';  
    char_traits<char>::int_type int1;  
    int1 = char_traits<char>::to_int_type(ch1);  
    cout << "char_type ch1 is '" << ch1 << "' and corresponds to int_type "  
         << int1 << "." << endl << endl;  
  
    char_traits<char>::int_type int2 = char_traits<char>::eof();  
    cout << "The eof marker for char_traits<char> is: " << int2 << endl;  
  
    char_traits<wchar_t>::int_type int3 = char_traits<wchar_t>::eof();  
    cout << "The eof marker for char_traits<wchar_t> is: " << int3 << endl;  
}  
```  
  
```Output  
char_type ch1 is 'x' and corresponds to int_type 120.  
  
The eof marker for char_traits<char> is: -1  
The eof marker for char_traits<wchar_t> is: 65535  
```  
  
##  <a name="eq"></a>  char_traits::eq  
 Testa se dois caracteres `char_type` são iguais.  
  
```  
static bool eq(const char_type& _Ch1, const char_type& _Ch2);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Ch1`  
 O primeiro de dois caracteres a serem testados quanto à igualdade.  
  
 `_Ch2`  
 O segundo de dois caracteres a serem testados quanto à igualdade.  
  
### <a name="return-value"></a>Valor retornado  
 **true** se o primeiro caractere for igual ao segundo caractere; caso contrário **false**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// char_traits_eq.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
  
   char_traits<char>::char_type ch1 =  'x';  
   char_traits<char>::char_type ch2 =  'y';  
   char_traits<char>::char_type ch3 =  'x';  
  
   // Testing for equality  
   bool b1 = char_traits<char>::eq ( ch1 , ch2 );  
   if ( b1 )  
      cout << "The character ch1 is equal "  
           << "to the character ch2." << endl;  
   else  
      cout << "The character ch1 is not equal "  
           << "to the character ch2." << endl;  
  
   // An equivalent and alternatively test procedure  
   if ( ch1 == ch3 )  
      cout << "The character ch1 is equal "  
           << "to the character ch3." << endl;  
   else  
      cout << "The character ch1 is not equal "  
           << "to the character ch3." << endl;  
}  
```  
  
```Output  
The character ch1 is not equal to the character ch2.  
The character ch1 is equal to the character ch3.  
```  
  
##  <a name="eq_int_type"></a>  char_traits::eq_int_type  
 Testa se dois caracteres representados como `int_type`s são iguais ou não.  
  
```  
static bool eq_int_type(const int_type& _Ch1, const int_type& _Ch2);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Ch1`  
 O primeiro dos dois caracteres a serem testados quanto à igualdade como **int_type**s.  
  
 `_Ch2`  
 O segundo de dois caracteres a serem testados quanto à igualdade como `int_type`s.  
  
### <a name="return-value"></a>Valor retornado  
 **true** se o primeiro caractere for igual ao segundo caractere; caso contrário **false**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// char_traits_eq_int_type.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   char_traits<char>::char_type ch1 =  'x';  
   char_traits<char>::char_type ch2 =  'y';  
   char_traits<char>::char_type ch3 =  'x';  
  
   // Converting from char_type to int_type  
   char_traits<char>::int_type int1, int2 , int3;  
   int1 =char_traits<char>:: to_int_type ( ch1 );  
   int2 =char_traits<char>:: to_int_type ( ch2 );  
   int3 =char_traits<char>:: to_int_type ( ch3 );  
  
   cout << "The char_types and corresponding int_types are:"  
        << "\n    ch1 = " << ch1 << " corresponding to int1 = "  
        << int1 << "."  
        << "\n    ch2 = " << ch2 << " corresponding to int1 = "  
        << int2 << "."  
        << "\n    ch3 = " << ch3 << " corresponding to int1 = "  
        << int3 << "." << endl << endl;  
  
   // Testing for equality of int_type representations  
   bool b1 = char_traits<char>::eq_int_type ( int1 , int2 );  
   if ( b1 )  
      cout << "The int_type representation of character ch1\n "  
           << "is equal to the int_type representation of ch2."  
           << endl;  
   else  
      cout << "The int_type representation of character ch1\n is "  
           << "not equal to the int_type representation of ch2."  
           << endl;  
  
   // An equivalent and alternatively test procedure  
   if ( int1 == int3 )  
      cout << "The int_type representation of character ch1\n "  
           << "is equal to the int_type representation of ch3."  
           << endl;  
   else  
      cout << "The int_type representation of character ch1\n is "  
           << "not equal to the int_type representation of ch3."  
           << endl;  
}  
```  
  
```Output  
The char_types and corresponding int_types are:  
    ch1 = x corresponding to int1 = 120.  
    ch2 = y corresponding to int1 = 121.  
    ch3 = x corresponding to int1 = 120.  
  
The int_type representation of character ch1  
 is not equal to the int_type representation of ch2.  
The int_type representation of character ch1  
 is equal to the int_type representation of ch3.  
```  
  
##  <a name="find"></a>  char_traits::find  
 Pesquisa a primeira ocorrência de um caractere especificado em um intervalo de caracteres.  
  
```  
static const char_type* find(const char_type* str,
    size_t _Num,
    const char_type& _Ch);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 O primeiro caractere na cadeia de caracteres a ser pesquisado.  
  
 `_Num`  
 O número de posições, contando da primeira, no intervalo a ser pesquisado.  
  
 `_Ch`  
 O caractere a ser pesquisado no intervalo.  
  
### <a name="return-value"></a>Valor retornado  
 Um ponteiro para a primeira ocorrência do caractere especificado no intervalo se uma correspondência for encontrada; caso contrário, um ponteiro nulo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// char_traits_find.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
  
   const char* s1 = "f2d-1234-abcd";  
   const char* result1;  
   cout << "The string to be searched is: " << s1 << endl;  
  
   // Searching for a 'd' in the first 6 positions of string s1  
   result1 = char_traits<char>::find ( s1 , 6 , 'd');  
   cout << "The character searched for in s1 is: "  
        << *result1 << endl;  
   cout << "The string beginning with the first occurrence\n "  
        << "of the character 'd' is: " << result1 << endl;  
  
   // When no match is found the NULL value is returned  
   const char* result2;  
   result2 = char_traits<char>::find ( s1 , 3 , 'a');  
   if ( result2 == NULL )  
      cout << "The result2 of the search is NULL." << endl;  
   else  
      cout << "The result2 of the search  is: " << result1  
           << endl;  
}  
```  
  
```Output  
The string to be searched is: f2d-1234-abcd  
The character searched for in s1 is: d  
The string beginning with the first occurrence  
 of the character 'd' is: d-1234-abcd  
The result2 of the search is NULL.  
```  
  
##  <a name="int_type"></a>  char_traits::int_type  
 Um tipo de inteiro que pode representar um caractere do tipo `char_type` ou um caractere de EOF (final de arquivo).  
  
```  
typedef long int_type;  
```  
  
### <a name="remarks"></a>Comentários  
 Deve ser possível fazer a conversão de tipo de um valor do tipo **CharType** para `int_type` e, em seguida, de volta para **CharType** sem alterar o valor original.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [eq_int_type](#eq_int_type) para obter um exemplo de como declarar e usar `int_type`.  
  
##  <a name="length"></a>  char_traits::length  
 Retorna o comprimento de uma cadeia de caracteres.  
  
```  
static size_t length(const char_type* str);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 A cadeia de caracteres C cujo tamanho deve ser medido.  
  
### <a name="return-value"></a>Valor retornado  
 O número de elementos na sequência que está sendo medida, não incluindo o terminador nulo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// char_traits_length.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   const char* str1= "Hello";  
   cout << "The C-string str1 is: " << str1 << endl;  
  
   size_t lenStr1;  
   lenStr1 = char_traits<char>::length ( str1 );  
   cout << "The length of C-string str1 is: "   
        << lenStr1 << "." << endl;  
}  
```  
  
```Output  
The C-string str1 is: Hello  
The length of C-string str1 is: 5.  
```  
  
##  <a name="lt"></a>  char_traits::lt  
 Testa se um caractere é menor que outro.  
  
```  
static bool lt(const char_type& _Ch1, const char_type& _Ch2);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Ch1`  
 O primeiro de dois caracteres a serem testados quanto a serem menores que.  
  
 `_Ch2`  
 O segundo de dois caracteres a serem testados quanto a serem menores que.  
  
### <a name="return-value"></a>Valor retornado  
 **true** se o primeiro caractere for menor que o segundo caractere; caso contrário **false**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// char_traits_lt.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   char_traits<char>::char_type ch1 =  'x';  
   char_traits<char>::char_type ch2 =  'y';  
   char_traits<char>::char_type ch3 =  'z';  
  
   // Testing for less than  
   bool b1 = char_traits<char>::lt ( ch1 , ch2 );  
   if ( b1 )  
      cout << "The character ch1 is less than "  
           << "the character ch2." << endl;  
   else  
      cout << "The character ch1 is not less "  
           << "than the character ch2." << endl;  
  
   // An equivalent and alternatively test procedure  
   if ( ch3 <  ch2 )  
      cout << "The character ch3 is less than "  
           << "the character ch2." << endl;  
   else  
      cout << "The character ch3 is not less "  
           << "than the character ch2." << endl;  
}  
```  
  
```Output  
The character ch1 is less than the character ch2.  
The character ch3 is not less than the character ch2.  
```  
  
##  <a name="move"></a>  char_traits::move  
 Copia um número especificado de caracteres em uma sequência para outra sequência possivelmente sobreposta.  
  
 Esse método pode não ser seguro, pois depende do chamador para verificar se os valores passados estão corretos. Considere usar [char_traits::_Move_s](#move_s) em vez disso.  
  
```  
static char_type *move(char_type* _To,
    const char_type* _From,
    size_t _Num);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_To`  
 O elemento no início da matriz de cadeia de caracteres ou caractere direcionado para receber a sequência de caracteres copiada.  
  
 `_From`  
 O elemento no início da matriz de cadeia de caracteres ou caractere de origem a ser copiado.  
  
 `_Num`  
 O número de elementos a serem copiados da cadeia de caracteres de origem.  
  
### <a name="return-value"></a>Valor retornado  
 O primeiro elemento `_To` copiado para a matriz de caracteres ou cadeia de caracteres destinada a receber a sequência de caracteres copiada.  
  
### <a name="remarks"></a>Comentários  
 A origem e o destino podem se sobrepor.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// char_traits_move.cpp  
// compile with: /EHsc /W3  
#include <string>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   char_traits<char>::char_type sFrom1[] =  "abcd-1234-abcd";  
   char_traits<char>::char_type sTo1[] =  "ABCD-1234";  
   char_traits<char>::char_type* result1;  
   cout << "The source string sFrom1 is: " << sFrom1 << endl;  
   cout << "The destination stringsTo1 is: " << sTo1 << endl;  
   // Note: char_traits::move is potentially unsafe, consider  
   // using char_traits::_Move_s instead.  
   result1 = char_traits<char>::move ( sTo1 ,  sFrom1 , 4 );  // C4996  
   cout << "The result1 = move ( sTo1 , sFrom1 , 4 ) is: "  
        << result1 << endl << endl;  
  
   // When source and destination overlap  
   char_traits<char>::char_type sToFrom2[] = "abcd-1234-ABCD";  
   char_traits<char>::char_type* result2;  
   cout << "The source/destination string sToFrom2 is: "  
        << sToFrom2 << endl;  
   const char* findc = char_traits<char>::find ( sToFrom2 , 4 , 'c' );  
   // Note: char_traits::move is potentially unsafe, consider  
   // using char_traits::_Move_s instead.  
   result2 = char_traits<char>::move ( sToFrom2 , findc , 8 );  // C4996  
   cout << "The result2 = move ( sToFrom2 , findc , 8 ) is: "  
        << result2 << endl;  
}  
```  
  
```Output  
The source string sFrom1 is: abcd-1234-abcd  
The destination stringsTo1 is: ABCD-1234  
The result1 = move ( sTo1 , sFrom1 , 4 ) is: abcd-1234  
  
The source/destination string sToFrom2 is: abcd-1234-ABCD  
The result2 = move ( sToFrom2 , findc , 8 ) is: cd-1234-4-ABCD  
```  
  
##  <a name="move_s"></a>  char_traits::_Move_s  
 Copia um número especificado de caracteres em uma sequência para outra sequência possivelmente sobreposta.  
  
```  
static char_type *_Move_s(
    char_type* dest,  
    size_t dest_size,  
    const char_type* _From,  
    size_t count);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dest`  
 O elemento no início da matriz de cadeia de caracteres ou caractere direcionado para receber a sequência de caracteres copiada.  
  
 `dest_size`  
 O tamanho do `dest`. Se `char_type` for `char`, então isso estará em bytes. Se `char_type` for `wchar_t`, então isso estará em palavras.  
  
 `_From`  
 O elemento no início da matriz de cadeia de caracteres ou caractere de origem a ser copiado.  
  
 `count`  
 O número de elementos a serem copiados da cadeia de caracteres de origem.  
  
### <a name="return-value"></a>Valor retornado  
 O primeiro elemento `dest` copiado para a matriz de caracteres ou cadeia de caracteres destinada a receber a sequência de caracteres copiada.  
  
### <a name="remarks"></a>Comentários  
 A origem e o destino podem se sobrepor.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// char_traits__Move_s.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )  
{  
    using namespace std;  
  
    char_traits<char>::char_type sFrom1[] =  "abcd-1234-abcd";  
    char_traits<char>::char_type sTo1[] =  "ABCD-1234";  
    char_traits<char>::char_type* result1;  
    cout << "The source string sFrom1 is: " << sFrom1 << endl;  
    cout << "The destination stringsTo1 is: " << sTo1 << endl;  
    result1 = char_traits<char>::_Move_s(sTo1,  
        char_traits<char>::length(sTo1), sFrom1, 4);  
    cout << "The result1 = _Move_s(sTo1, "  
         << "char_traits<char>::length(sTo1), sFrom1, 4) is: "  
         << result1 << endl << endl;  
  
    // When source and destination overlap  
    char_traits<char>::char_type sToFrom2[] = "abcd-1234-ABCD";  
    char_traits<char>::char_type* result2;  
    cout << "The source/destination string sToFrom2 is: "  
         << sToFrom2 << endl;  
    const char* findc = char_traits<char>::find(sToFrom2, 4, 'c');  
    result2 = char_traits<char>::_Move_s(sToFrom2,  
        char_traits<char>::length(sToFrom2), findc, 8);  
    cout << "The result2 = _Move_s(sToFrom2, "  
        << "char_traits<char>::length(sToFrom2), findc, 8) is: "  
         << result2 << endl;  
}  
```  
  
```Output  
The source string sFrom1 is: abcd-1234-abcd  
The destination stringsTo1 is: ABCD-1234  
The result1 = _Move_s(sTo1, char_traits<char>::length(sTo1), sFrom1, 4) is: abcd-1234  
  
The source/destination string sToFrom2 is: abcd-1234-ABCD  
The result2 = _Move_s(sToFrom2, char_traits<char>::length(sToFrom2), findc, 8) is: cd-1234-4-ABCD  
```  
  
##  <a name="not_eof"></a>  char_traits::not_eof  
 Testa se um caractere não é o caractere EOF (fim de arquivo) ou se é o EOF.  
  
```  
static int_type not_eof(const int_type& _Ch);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Ch`  
 O caractere representado como um `int_type` a ser testado para determinar se ele é o caractere EOF ou não.  
  
### <a name="return-value"></a>Valor retornado  
 A representação `int_type` do caractere testado, se o **int_type** do caractere não for igual ao do caractere EOF.  
  
 Se o valor `int_type` do caractere for igual ao valor do EOF `int_type`, então **false**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// char_traits_not_eof.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( ) {  
   using namespace std;  
  
   char_traits<char>::char_type ch1 =  'x';  
   char_traits<char>::int_type int1;  
   int1 = char_traits<char>:: to_int_type ( ch1 );  
   cout << "The char_type ch1 is " << ch1  
        << " corresponding to int_type: "   
        << int1 << "." << endl;  
  
   // EOF member function  
   char_traits <char>::int_type int2 = char_traits<char>::eof ( );  
   cout << "The eofReturn is: " << int2 << endl;  
  
   // Testing for EOF or another character  
   char_traits <char>::int_type eofTest1, eofTest2;  
   eofTest1 = char_traits<char>::not_eof ( int1 );  
   if ( !eofTest1 )  
      cout << "The eofTest1 indicates ch1 is an EOF character."  
              << endl;  
   else  
      cout << "The eofTest1 returns: " << eofTest1   
           << ", which is the character: "   
           <<  char_traits<char>::to_char_type ( eofTest1 )  
           << "." << endl;  
  
   eofTest2 = char_traits<char>::not_eof ( int2 );  
   if ( !eofTest2 )  
      cout << "The eofTest2 indicates int2 is an EOF character."   
           << endl;  
   else  
      cout << "The eofTest1 returns: " << eofTest2   
           << ", which is the character: "   
           <<  char_traits<char>::to_char_type ( eofTest2 )   
           << "." << endl;  
}  
```  
  
```Output  
The char_type ch1 is x corresponding to int_type: 120.  
The eofReturn is: -1  
The eofTest1 returns: 120, which is the character: x.  
The eofTest2 indicates int2 is an EOF character.  
```  
  
##  <a name="off_type"></a>  char_traits::off_type  
 Um tipo de inteiro que pode representar compensações entre posições em um fluxo.  
  
```  
typedef streamoff off_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um inteiro com sinal que descreve um objeto que pode armazenar um deslocamento de byte envolvido em várias operações de posicionamento de fluxo. Normalmente é um sinônimo de [streamoff](../standard-library/ios-typedefs.md#streamoff), mas tem essencialmente as mesmas propriedades que aquele tipo.  
  
##  <a name="pos_type"></a>  char_traits::pos_type  
 Um tipo de inteiro que pode representar posições em um fluxo.  
  
```  
typedef streampos pos_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto que pode armazenar todas as informações necessárias para restaurar um indicador de posição de arquivo arbitrária dentro de um fluxo. Normalmente é um sinônimo de [streamoff](../standard-library/ios-typedefs.md#streampos), mas em qualquer caso tem essencialmente as mesmas propriedades que aquele tipo.  
  
##  <a name="state_type"></a>  char_traits::state_type  
 Um tipo que representa o estado de conversão para caracteres multibyte em um fluxo.  
  
```  
typedef implementation-defined state_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto que pode representar o estado da conversão. Normalmente é um sinônimo de `mbstate_t`, mas em qualquer caso tem essencialmente as mesmas propriedades que aquele tipo.  
  
##  <a name="to_char_type"></a>  char_traits::to_char_type  
 Converte um caractere `int_type` para o caractere `char_type` correspondente e retorna o resultado.  
  
```  
static char_type to_char_type(const int_type& _Ch);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Ch`  
 O caractere `int_type` a ser representado como um `char_type`.  
  
### <a name="return-value"></a>Valor retornado  
 O caractere `char_type` que corresponde ao caractere `int_type`.  
  
 Um valor de `_Ch` que não pode ser representado como tal produz um resultado não especificado.  
  
### <a name="remarks"></a>Comentários  
 As operações de conversão [to_int_type](#to_int_type) e `to_char_type` são o inverso umas das outras, de modo que:  
  
 `to_int_type` ( `to_char_type` ( *x* ) ) == *x*  
  
 para qualquer `int_type` *x* e  
  
 `to_char_type` ( `to_int_type` ( *x* ) ) == *x*  
  
 para qualquer `char_type` *x*.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// char_traits_to_char_type.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
  
   char_traits<char>::char_type ch1 =  'a';  
   char_traits<char>::char_type ch2 =  'b';  
   char_traits<char>::char_type ch3 =  'a';  
  
   // Converting from char_type to int_type  
   char_traits<char>::int_type int1, int2 , int3;  
   int1 =char_traits<char>:: to_int_type ( ch1 );  
   int2 =char_traits<char>:: to_int_type ( ch2 );  
   int3 =char_traits<char>:: to_int_type ( ch3 );  
  
   cout << "The char_types and corresponding int_types are:"  
        << "\n    ch1 = " << ch1 << " corresponding to int1 = "   
        << int1 << "."  
        << "\n    ch2 = " << ch2 << " corresponding to int1 = "   
        << int2 << "."  
        << "\n    ch3 = " << ch3 << " corresponding to int1 = "   
        << int3 << "." << endl << endl;  
  
   // Converting from int_type back to char_type  
   char_traits<char>::char_type rec_ch1;  
   rec_ch1 = char_traits<char>:: to_char_type ( int1);  
   char_traits<char>::char_type rec_ch2;  
   rec_ch2 = char_traits<char>:: to_char_type ( int2);  
  
   cout << "The recovered char_types and corresponding int_types are:"  
        << "\n    recovered ch1 = " << rec_ch1 << " from int1 = "   
        << int1 << "."  
        << "\n    recovered ch2 = " << rec_ch2 << " from int2 = "   
        << int2 << "." << endl << endl;  
  
   // Testing that the conversions are inverse operations  
   bool b1 = char_traits<char>::eq ( rec_ch1 , ch1 );  
   if ( b1 )  
      cout << "The recovered char_type of ch1"  
           << " is equal to the original ch1." << endl;  
   else  
      cout << "The recovered char_type of ch1"  
           << " is not equal to the original ch1." << endl;  
  
   // An equivalent and alternatively test procedure  
   if ( rec_ch2 == ch2 )  
      cout << "The recovered char_type of ch2"  
           << " is equal to the original ch2." << endl;  
   else  
      cout << "The recovered char_type of ch2"  
           << " is not equal to the original ch2." << endl;  
}  
```  
  
```Output  
The char_types and corresponding int_types are:  
    ch1 = a corresponding to int1 = 97.  
    ch2 = b corresponding to int1 = 98.  
    ch3 = a corresponding to int1 = 97.  
  
The recovered char_types and corresponding int_types are:  
    recovered ch1 = a from int1 = 97.  
    recovered ch2 = b from int2 = 98.  
  
The recovered char_type of ch1 is equal to the original ch1.  
The recovered char_type of ch2 is equal to the original ch2.  
```  
  
##  <a name="to_int_type"></a>  char_traits::to_int_type  
 Converte um caractere `char_type` para o caractere `int_type` correspondente e retorna o resultado.  
  
```  
static int_type to_int_type(const char_type& _Ch);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Ch`  
 O caractere `char_type` a ser representada como um `int_type`.  
  
### <a name="return-value"></a>Valor retornado  
 O caractere `int_type` que corresponde ao caractere `char_type`.  
  
### <a name="remarks"></a>Comentários  
 As operações de conversão `to_int_type` e [to_char_type](#to_char_type) são o inverso umas às outras, de modo que:  
  
 `to_int_type` ( `to_char_type` ( *x* ) ) == *x*  
  
 para qualquer `int_type` *x* e  
  
 `to_char_type` ( `to_int_type` ( *x* ) ) == *x*  
  
 para qualquer `char_type` *x*.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// char_traits_to_int_type.cpp  
// compile with: /EHsc  
#include <string>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   char_traits<char>::char_type ch1 = 'a';  
   char_traits<char>::char_type ch2 = 'b';  
   char_traits<char>::char_type ch3 = 'a';  
  
   // Converting from char_type to int_type  
   char_traits<char>::int_type int1, int2 , int3;  
   int1 =char_traits<char>:: to_int_type ( ch1 );  
   int2 =char_traits<char>:: to_int_type ( ch2 );  
   int3 =char_traits<char>:: to_int_type ( ch3 );  
  
   cout << "The char_types and corresponding int_types are:"  
        << "\n    ch1 = " << ch1 << " corresponding to int1 = "   
        << int1 << "."  
        << "\n    ch2 = " << ch2 << " corresponding to int1 = "   
        << int2 << "."  
        << "\n    ch3 = " << ch3 << " corresponding to int1 = "   
        << int3 << "." << endl << endl;  
  
   // Converting from int_type back to char_type  
   char_traits<char>::char_type rec_ch1;  
   rec_ch1 = char_traits<char>:: to_char_type ( int1);  
   char_traits<char>::char_type rec_ch2;  
   rec_ch2 = char_traits<char>:: to_char_type ( int2);  
  
   cout << "The recovered char_types and corresponding int_types are:"  
        << "\n    recovered ch1 = " << rec_ch1 << " from int1 = "   
        << int1 << "."  
        << "\n    recovered ch2 = " << rec_ch2 << " from int2 = "   
        << int2 << "." << endl << endl;  
  
   // Testing that the conversions are inverse operations  
   bool b1 = char_traits<char>::eq ( rec_ch1 , ch1 );  
   if ( b1 )  
      cout << "The recovered char_type of ch1"  
           << " is equal to the original ch1." << endl;  
   else  
      cout << "The recovered char_type of ch1"  
           << " is not equal to the original ch1." << endl;  
  
   // An equivalent and alternatively test procedure  
   if ( rec_ch2 == ch2 )  
      cout << "The recovered char_type of ch2"  
           << " is equal to the original ch2." << endl;  
   else  
      cout << "The recovered char_type of ch2"  
           << " is not equal to the original ch2." << endl;  
}  
```  
  
```Output  
The char_types and corresponding int_types are:  
    ch1 = a corresponding to int1 = 97.  
    ch2 = b corresponding to int1 = 98.  
    ch3 = a corresponding to int1 = 97.  
  
The recovered char_types and corresponding int_types are:  
    recovered ch1 = a from int1 = 97.  
    recovered ch2 = b from int2 = 98.  
  
The recovered char_type of ch1 is equal to the original ch1.  
The recovered char_type of ch2 is equal to the original ch2.  
```  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)


