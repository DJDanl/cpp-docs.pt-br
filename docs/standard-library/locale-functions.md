---
title: Funções &lt;locale&gt;
ms.date: 11/04/2016
f1_keywords:
- locale/std::has_facet
- locale/std::isalnum
- locale/std::isalpha
- locale/std::iscntrl
- locale/std::isdigit
- locale/std::isgraph
- locale/std::islower
- locale/std::isprint
- locale/std::ispunct
- locale/std::isspace
- locale/std::isupper
- locale/std::isxdigit
- locale/std::tolower
- locale/std::toupper
- locale/std::use_facet
ms.assetid: b06c1ceb-33a7-48d3-8d4b-2714bbb27f14
helpviewer_keywords:
- std::has_facet [C++]
- std::isalnum [C++]
- std::isalpha [C++]
- std::iscntrl [C++]
- std::isdigit [C++]
- std::isgraph [C++]
- std::islower [C++]
- std::isprint [C++]
- std::ispunct [C++]
- std::isspace [C++]
- std::isupper [C++]
- std::isxdigit [C++]
- std::tolower [C++]
- std::toupper [C++]
- std::use_facet [C++]
ms.openlocfilehash: 3c5d81aecb5e78a8fd3c3f32da82f6048ae4fac8
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78856461"
---
# <a name="ltlocalegt-functions"></a>Funções &lt;locale&gt;

||||
|-|-|-|
|[has_facet](#has_facet)|[isalnum](#isalnum)|[isalpha](#isalpha)|
|[iscntrl](#iscntrl)|[isdigit](#isdigit)|[isgraph](#isgraph)|
|[islower](#islower)|[isprint](#isprint)|[ispunct](#ispunct)|
|[isspace](#isspace)|[isupper](#isupper)|[isxdigit](#isxdigit)|
|[tolower](#tolower)|[toupper](#toupper)|[use_facet](#use_facet)|

## <a name="has_facet"></a>  has_facet

Testa se uma determinada faceta é armazenada em uma localidade especificada.

```cpp
template <class Facet>
bool has_facet(const locale& Loc);
```

### <a name="parameters"></a>Parâmetros

\ de *Loc*
A localidade a ser testada para a presença de uma faceta.

### <a name="return-value"></a>Valor retornado

**true** se a localidade tiver a faceta testada; **false** se não.

### <a name="remarks"></a>Comentários

A função de modelo é útil para verificar se as facetas não obrigatórias estão listadas em uma localidade antes de `use_facet` ser chamado para evitar a exceção que seria gerada se elas não estiverem presentes.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// locale_has_facet.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
using namespace std;

int main( )
{
   locale loc ( "German_Germany" );
   bool result = has_facet <ctype<char> > ( loc );
   cout << result << endl;
}
```

```Output
1
```

## <a name="isalnum"></a>  isalnum

Testa se um elemento em uma localidade é um caractere alfabético ou numérico.

```cpp
template <class CharType>
bool isalnum(CharType Ch, const locale& Loc)
```

### <a name="parameters"></a>Parâmetros

*Ch*\
O elemento alfanumérico a ser testado.

\ de *Loc*
A localidade que contém o elemento alfanumérico a ser testado.

### <a name="return-value"></a>Valor retornado

**true** se o elemento testado for alfanumérico; **false** se não.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// locale_isalnum.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>

using namespace std;

int main( )
{
   locale loc ( "German_Germany" );
   bool result1 = isalnum ( 'L', loc);
   bool result2 = isalnum ( '@', loc);
   bool result3 = isalnum ( '3', loc);

   if ( result1 )
      cout << "The character 'L' in the locale is "
           << "alphanumeric." << endl;
   else
      cout << "The character 'L' in the locale is "
           << " not alphanumeric." << endl;

   if ( result2 )
      cout << "The character '@' in the locale is "
           << "alphanumeric." << endl;
   else
      cout << "The character '@' in the locale is "
           << " not alphanumeric." << endl;

   if ( result3 )
      cout << "The character '3' in the locale is "
           << "alphanumeric." << endl;
   else
      cout << "The character '3' in the locale is "
           << " not alphanumeric." << endl;
}
```

```Output
The character 'L' in the locale is alphanumeric.
The character '@' in the locale is  not alphanumeric.
The character '3' in the locale is alphanumeric.
```

## <a name="isalpha"></a>  isalpha

Testa se um elemento em uma localidade é um caractere alfabético.

```cpp
template <class CharType>
bool isalpha(CharType Ch, const locale& Loc)
```

### <a name="parameters"></a>Parâmetros

*Ch*\
O elemento a ser testado.

\ de *Loc*
A localidade que contém o elemento alfabético a ser testado.

### <a name="return-value"></a>Valor retornado

**true** se o elemento testado for alfabético; **false** se não.

### <a name="remarks"></a>Comentários

A função de modelo retorna [use_facet](../standard-library/locale-functions.md#use_facet)< [CType](../standard-library/ctype-class.md)\< **chartype**> > (`Loc`). [é](../standard-library/ctype-class.md#is)( **CType**\< **CharType**>:: **Alpha**, `Ch`).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// locale_isalpha.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>

using namespace std;

int main( )
{
   locale loc ( "German_Germany" );
   bool result1 = isalpha ( 'L', loc);
   bool result2 = isalpha ( '@', loc);
   bool result3 = isalpha ( '3', loc);

   if ( result1 )
      cout << "The character 'L' in the locale is "
           << "alphabetic." << endl;
   else
      cout << "The character 'L' in the locale is "
           << " not alphabetic." << endl;

   if ( result2 )
      cout << "The character '@' in the locale is "
           << "alphabetic." << endl;
   else
      cout << "The character '@' in the locale is "
           << " not alphabetic." << endl;

   if ( result3 )
      cout << "The character '3' in the locale is "
           << "alphabetic." << endl;
   else
      cout << "The character '3' in the locale is "
           << " not alphabetic." << endl;
}
```

## <a name="iscntrl"></a>  iscntrl

Testa se um elemento em uma localidade é um caractere de controle.

```cpp
template <class CharType>
bool iscntrl(CharType Ch, const locale& Loc)
```

### <a name="parameters"></a>Parâmetros

*Ch*\
O elemento a ser testado.

\ de *Loc*
A localidade que contém o elemento a ser testado.

### <a name="return-value"></a>Valor retornado

**true** se o elemento testado for um caractere de controle; **false** se não.

### <a name="remarks"></a>Comentários

A função de modelo retorna [use_facet](../standard-library/locale-functions.md#use_facet)< [CType](../standard-library/ctype-class.md)\< **chartype**> > (`Loc`). [é](../standard-library/ctype-class.md#is)( **CType**\< **CharType**>:: **Tab**, `Ch`).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// locale_iscntrl.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>

using namespace std;

int main( )
{
   locale loc ( "German_Germany" );
   bool result1 = iscntrl ( 'L', loc );
   bool result2 = iscntrl ( '\n', loc );
   bool result3 = iscntrl ( '\t', loc );

   if ( result1 )
      cout << "The character 'L' in the locale is "
           << "a control character." << endl;
   else
      cout << "The character 'L' in the locale is "
           << " not a control character." << endl;

   if ( result2 )
      cout << "The character-set 'backslash-n' in the locale\n is "
           << "a control character." << endl;
   else
      cout << "The character-set 'backslash-n' in the locale\n is "
           << " not a control character." << endl;

   if ( result3 )
      cout << "The character-set 'backslash-t' in the locale\n is "
           << "a control character." << endl;
   else
      cout << "The character-set 'backslash-n' in the locale \n is "
           << " not a control character." << endl;
}
```

## <a name="isdigit"></a>  isdigit

Testa se um elemento em uma localidade é um caractere numérico.

```cpp
template <class CharType>
bool isdigit(CharType Ch, const locale& Loc)
```

### <a name="parameters"></a>Parâmetros

*Ch*\
O elemento a ser testado.

\ de *Loc*
A localidade que contém o elemento a ser testado.

### <a name="return-value"></a>Valor retornado

**true** se o elemento testado for um caractere numérico; **false** se não.

### <a name="remarks"></a>Comentários

A função de modelo retorna [use_facet](../standard-library/locale-functions.md#use_facet)< [CType](../standard-library/ctype-class.md)\< **chartype**> > (`Loc`). [é](../standard-library/ctype-class.md#is)( **CType**\< **CharType**>:: **digit**, `Ch`).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// locale_is_digit.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>

using namespace std;

int main( )
{
   locale loc ( "German_Germany" );
   bool result1 = isdigit ( 'L', loc );
   bool result2 = isdigit ( '@', loc );
   bool result3 = isdigit ( '3', loc );

   if ( result1 )
      cout << "The character 'L' in the locale is "
           << "a numeric character." << endl;
   else
      cout << "The character 'L' in the locale is "
           << " not a numeric character." << endl;

   if ( result2 )
      cout << "The character '@' in the locale is "
           << "a numeric character." << endl;
   else
      cout << "The character '@' in the locale is "
           << " not a numeric character." << endl;

   if ( result3 )
      cout << "The character '3' in the locale is "
           << "a numeric character." << endl;
   else
      cout << "The character '3' in the locale is "
           << " not a numeric character." << endl;
}
```

## <a name="isgraph"></a>  isgraph

Testa se um elemento em uma localidade é um caractere alfanumérico ou de pontuação.

```cpp
template <class CharType>
bool isgraph(CharType Ch, const locale& Loc)
```

### <a name="parameters"></a>Parâmetros

*Ch*\
O elemento a ser testado.

\ de *Loc*
A localidade que contém o elemento a ser testado.

### <a name="return-value"></a>Valor retornado

**true** se o elemento testado for um caractere alfanumérico ou de pontuação; **false** se não.

### <a name="remarks"></a>Comentários

A função de modelo retorna [use_facet](../standard-library/locale-functions.md#use_facet)< [CType](../standard-library/ctype-class.md)\< **chartype**> > (`Loc`). [é](../standard-library/ctype-class.md#is)( **CType**\< **CharType**>:: **Graph**, `Ch`).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// locale_is_graph.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>

using namespace std;

int main( )
{
   locale loc ( "German_Germany" );
   bool result1 = isgraph ( 'L', loc );
   bool result2 = isgraph ( '\t', loc );
   bool result3 = isgraph ( '.', loc );

   if ( result1 )
      cout << "The character 'L' in the locale is\n "
           << "an alphanumeric or punctuation character." << endl;
   else
      cout << "The character 'L' in the locale is\n "
           << " not an alphanumeric or punctuation character." << endl;

   if ( result2 )
      cout << "The character 'backslash-t' in the locale is\n "
           << "an alphanumeric or punctuation character." << endl;
   else
      cout << "The character 'backslash-t' in the locale is\n "
           << "not an alphanumeric or punctuation character." << endl;

   if ( result3 )
      cout << "The character '.' in the locale is\n "
           << "an alphanumeric or punctuation character." << endl;
   else
      cout << "The character '.' in the locale is\n "
           << " not an alphanumeric or punctuation character." << endl;
}
```

## <a name="islower"></a>  islower

Testa se um elemento em uma localidade está em letras minúsculas.

```cpp
template <class CharType>
bool islower(CharType Ch, const locale& Loc)
```

### <a name="parameters"></a>Parâmetros

*Ch*\
O elemento a ser testado.

\ de *Loc*
A localidade que contém o elemento a ser testado.

### <a name="return-value"></a>Valor retornado

**true** se o elemento testado for um caractere em minúsculas; **false** se não.

### <a name="remarks"></a>Comentários

A função de modelo retorna [use_facet](../standard-library/locale-functions.md#use_facet)< [CType](../standard-library/ctype-class.md)\< **chartype**> > (`Loc`). [é](../standard-library/ctype-class.md#is)( **CType**\< **CharType**>:: **Low**, `Ch`).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// locale_islower.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>

using namespace std;

int main( )
{
   locale loc ( "German_Germany" );
   bool result1 = islower ( 'L', loc );
   bool result2 = islower ( 'n', loc );
   bool result3 = islower ( '3', loc );

   if ( result1 )
      cout << "The character 'L' in the locale is "
           << "a lowercase character." << endl;
   else
      cout << "The character 'L' in the locale is "
           << " not a lowercase character." << endl;

   if ( result2 )
      cout << "The character 'n' in the locale is "
           << "a lowercase character." << endl;
   else
      cout << "The character 'n' in the locale is "
           << " not a lowercase character." << endl;

   if ( result3 )
      cout << "The character '3' in the locale is "
           << "a lowercase character." << endl;
   else
      cout << "The character '3' in the locale is "
           << " not a lowercase character." << endl;
}
```

## <a name="isprint"></a>  isprint

Testa se um elemento em uma localidade é um caractere imprimível.

```cpp
template <class CharType>
bool isprint(CharType Ch, const locale& Loc)
```

### <a name="parameters"></a>Parâmetros

*Ch*\
O elemento a ser testado.

\ de *Loc*
A localidade que contém o elemento a ser testado.

### <a name="return-value"></a>Valor retornado

**true** se o elemento testado for um imprimível; **false** se não.

### <a name="remarks"></a>Comentários

A função de modelo retorna [use_facet](../standard-library/locale-functions.md#use_facet)< [CType](../standard-library/ctype-class.md)\< **chartype**> > (`Loc`). [é](../standard-library/ctype-class.md#is)( **CType**\< **CharType**>:: **Print**, `Ch`).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// locale_isprint.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
using namespace std;

int main( )
{
   locale loc ( "German_Germany" );

   bool result1 = isprint ( 'L', loc );
   if ( result1 )
      cout << "The character 'L' in the locale is "
           << "a printable character." << endl;
   else
      cout << "The character 'L' in the locale is "
           << " not a printable character." << endl;

   bool result2 = isprint( '\t', loc );
   if ( result2 )
      cout << "The character 'backslash-t' in the locale is "
           << "a printable character." << endl;
   else
      cout << "The character 'backslash-t' in the locale is "
           << " not a printable character." << endl;

   bool result3 = isprint( '\n', loc );
   if ( result3 )
      cout << "The character 'backslash-n' in the locale is "
           << "a printable character." << endl;
   else
      cout << "The character 'backslash-n' in the locale is "
           << " not a printable character." << endl;
}
```

## <a name="ispunct"></a>  ispunct

Testa se um elemento em uma localidade é um caractere de pontuação.

```cpp
template <class CharType>
bool ispunct(CharType Ch, const locale& Loc)
```

### <a name="parameters"></a>Parâmetros

*Ch*\
O elemento a ser testado.

\ de *Loc*
A localidade que contém o elemento a ser testado.

### <a name="return-value"></a>Valor retornado

**true** se o elemento testado for um caractere de pontuação; **false** se não.

### <a name="remarks"></a>Comentários

A função de modelo retorna [use_facet](../standard-library/locale-functions.md#use_facet)`<`[CType](../standard-library/ctype-class.md)\< **chartype**> > (`Loc`). [é](../standard-library/ctype-class.md#is)( **CType**\< **CharType**>:: **punct**, `Ch`).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// locale_ispunct.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>

using namespace std;

int main( )
{
   locale loc ( "German_Germany" );
   bool result1 = ispunct ( 'L', loc );
   bool result2 = ispunct ( ';', loc );
   bool result3 = ispunct ( '*', loc );

   if ( result1 )
      cout << "The character 'L' in the locale is "
           << "a punctuation character." << endl;
   else
      cout << "The character 'L' in the locale is "
           << " not a punctuation character." << endl;

   if ( result2 )
      cout << "The character ';' in the locale is "
           << "a punctuation character." << endl;
   else
      cout << "The character ';' in the locale is "
           << " not a punctuation character." << endl;

   if ( result3 )
      cout << "The character '*' in the locale is "
           << "a punctuation character." << endl;
   else
      cout << "The character '*' in the locale is "
           << " not a punctuation character." << endl;
}
```

## <a name="isspace"></a>  isspace

Testa se um elemento em uma localidade é um caractere de espaço em branco.

```cpp
template <class CharType>
bool isspace(CharType Ch, const locale& Loc)
```

### <a name="parameters"></a>Parâmetros

*Ch*\
O elemento a ser testado.

\ de *Loc*
A localidade que contém o elemento a ser testado.

### <a name="return-value"></a>Valor retornado

**true** se o elemento testado for um caractere de espaço em branco; **false** se não.

### <a name="remarks"></a>Comentários

A função de modelo retorna [use_facet](../standard-library/locale-functions.md#use_facet)< [CType](../standard-library/ctype-class.md)\< **chartype**> > (`Loc`). [é](../standard-library/ctype-class.md#is)( **CType**\< **CharType**>:: **Space**, `Ch`).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// locale_isspace.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>

using namespace std;

int main( )
{
   locale loc ( "German_Germany" );
   bool result1 = isspace ( 'L', loc );
   bool result2 = isspace ( '\n', loc );
   bool result3 = isspace ( ' ', loc );

   if ( result1 )
      cout << "The character 'L' in the locale is "
           << "a whitespace character." << endl;
   else
      cout << "The character 'L' in the locale is "
           << " not a whitespace character." << endl;

   if ( result2 )
      cout << "The character 'backslash-n' in the locale is "
           << "a whitespace character." << endl;
   else
      cout << "The character 'backslash-n' in the locale is "
           << " not a whitespace character." << endl;

   if ( result3 )
      cout << "The character ' ' in the locale is "
           << "a whitespace character." << endl;
   else
      cout << "The character ' ' in the locale is "
           << " not a whitespace character." << endl;
}
```

## <a name="isupper"></a>  isupper

Testa se um elemento em uma localidade está em letras maiúsculas.

```cpp
template <class CharType>
bool isupper(CharType Ch, const locale& Loc)
```

### <a name="parameters"></a>Parâmetros

*Ch*\
O elemento a ser testado.

\ de *Loc*
A localidade que contém o elemento a ser testado.

### <a name="return-value"></a>Valor retornado

**true** se o elemento testado for um caractere em maiúsculas; **false** se não.

### <a name="remarks"></a>Comentários

A função de modelo retorna [use_facet](../standard-library/locale-functions.md#use_facet)< [CType](../standard-library/ctype-class.md)\< **chartype**> > (`Loc`). [é](../standard-library/ctype-class.md#is)( **CType**\< **CharType**>:: **Upper**, `Ch`).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// locale_isupper.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>

using namespace std;

int main( )
{
   locale loc ( "German_Germany" );
   bool result1 = isupper ( 'L', loc );
   bool result2 = isupper ( 'n', loc );
   bool result3 = isupper ( '3', loc );

   if ( result1 )
      cout << "The character 'L' in the locale is "
           << "a uppercase character." << endl;
   else
      cout << "The character 'L' in the locale is "
           << " not a uppercase character." << endl;

   if ( result2 )
      cout << "The character 'n' in the locale is "
           << "a uppercase character." << endl;
   else
      cout << "The character 'n' in the locale is "
           << " not a uppercase character." << endl;

   if ( result3 )
      cout << "The character '3' in the locale is "
           << "a uppercase character." << endl;
   else
      cout << "The character '3' in the locale is "
           << " not a uppercase character." << endl;
}
```

## <a name="isxdigit"></a>  isxdigit

Testa se um elemento em uma localidade é um caractere usado para representar um número hexadecimal.

```cpp
template <class CharType>
bool isxdigit(CharType Ch, const locale& Loc)
```

### <a name="parameters"></a>Parâmetros

*Ch*\
O elemento a ser testado.

\ de *Loc*
A localidade que contém o elemento a ser testado.

### <a name="return-value"></a>Valor retornado

**true** se o elemento testado for um caractere usado para representar um número hexadecimal; **false** se não.

### <a name="remarks"></a>Comentários

A função de modelo retorna [use_facet](../standard-library/locale-functions.md#use_facet)< [CType](../standard-library/ctype-class.md)\< **chartype**> > (`Loc`). [é](../standard-library/ctype-class.md#is)( **CType**\< **CharType**>:: **xdigit**, `Ch`).

Dígitos hexadecimais usam base 16 para representar números, usando os números de 0 a 9 e letras de A a F, sem diferenciar maiúsculas e minúsculas, para representar os números decimais de 0 a 15.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// locale_isxdigit.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>

using namespace std;

int main( )
{
   locale loc ( "German_Germany" );
   bool result1 = isxdigit ( '5', loc );
   bool result2 = isxdigit ( 'd', loc );
   bool result3 = isxdigit ( 'q', loc );

   if ( result1 )
      cout << "The character '5' in the locale is "
           << "a hexidecimal digit-character." << endl;
   else
      cout << "The character '5' in the locale is "
           << " not a hexidecimal digit-character." << endl;

   if ( result2 )
      cout << "The character 'd' in the locale is "
           << "a hexidecimal digit-character." << endl;
   else
      cout << "The character 'd' in the locale is "
           << " not a hexidecimal digit-character." << endl;

   if ( result3 )
      cout << "The character 'q' in the locale is "
           << "a hexidecimal digit-character." << endl;
   else
      cout << "The character 'q' in the locale is "
           << " not a hexidecimal digit-character." << endl;
}
```

## <a name="tolower"></a>  tolower

Converte um caractere em letra minúscula.

```cpp
template <class CharType>
CharType tolower(CharType Ch, const locale& Loc)
```

### <a name="parameters"></a>Parâmetros

*Ch*\
O caractere a ser convertido em letras minúsculas.

\ de *Loc*
A localidade que contém o caractere a ser convertido.

### <a name="return-value"></a>Valor retornado

O caractere convertido em letras minúsculas.

### <a name="remarks"></a>Comentários

A função de modelo retorna [use_facet](../standard-library/locale-functions.md#use_facet)< [CType](../standard-library/ctype-class.md)\< **chartype**> > (`Loc`). [tolower](../standard-library/ctype-class.md#tolower)( `Ch`).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// locale_tolower.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
using namespace std;

int main( )
{
   locale loc ( "German_Germany" );
   char result1 = tolower ( 'H', loc );
   cout << "The lower case of 'H' in the locale is: "
        << result1 << "." << endl;
   char result2 = tolower ( 'h', loc );
   cout << "The lower case of 'h' in the locale is: "
        << result2 << "." << endl;
   char result3 = tolower ( '$', loc );
   cout << "The lower case of '$' in the locale is: "
        << result3 << "." << endl;
}
```

## <a name="toupper"></a>  toupper

Converte um caractere em letra maiúscula.

```cpp
template <class CharType>
CharType toupper(CharType Ch, const locale& Loc)
```

### <a name="parameters"></a>Parâmetros

*Ch*\
O caractere a ser convertido em maiúsculas.

\ de *Loc*
A localidade que contém o caractere a ser convertido.

### <a name="return-value"></a>Valor retornado

O caractere convertido em maiúsculas.

### <a name="remarks"></a>Comentários

A função de modelo retorna [use_facet](../standard-library/locale-functions.md#use_facet)< [CType](../standard-library/ctype-class.md)\< **chartype**> > (`Loc`). [toupper](../standard-library/ctype-class.md#toupper)( `Ch`).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// locale_toupper.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
using namespace std;

int main( )
{
   locale loc ( "German_Germany" );
   char result1 = toupper ( 'h', loc );
   cout << "The upper case of 'h' in the locale is: "
        << result1 << "." << endl;
   char result2 = toupper ( 'H', loc );
   cout << "The upper case of 'H' in the locale is: "
        << result2 << "." << endl;
   char result3 = toupper ( '$', loc );
   cout << "The upper case of '$' in the locale is: "
        << result3 << "." << endl;
}
```

## <a name="use_facet"></a>  use_facet

Retorna uma referência para uma faceta de um tipo especificado armazenada em uma localidade.

```cpp
template <class Facet>
const Facet& use_facet(const locale& Loc);
```

### <a name="parameters"></a>Parâmetros

\ de *Loc*
A localidade const que contém o tipo de faceta que está sendo referenciado.

### <a name="return-value"></a>Valor retornado

Uma referência à faceta da classe `Facet` contida na localidade do argumento.

### <a name="remarks"></a>Comentários

A referência à faceta retornada pela função de modelo permanece válida, desde que exista qualquer cópia da localidade que a contém. Se nenhum objeto de faceta da classe `Facet` estiver listado na localidade do argumento, a função gerará uma exceção `bad_cast`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// locale_use_facet.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
using namespace std;

int main( )
{
   locale loc1 ( "German_Germany" ), loc2 ( "English_Australia" );
   bool result1 = use_facet<ctype<char> > ( loc1 ).is(
   ctype_base::alpha, 'a'
);
   bool result2 = use_facet<ctype<char> > ( loc2 ).is( ctype_base::alpha, '!'
   );

   if ( result1 )
      cout << "The character 'a' in locale loc1 is alphabetic."
           << endl;
   else
      cout << "The character 'a' in locale loc1 is not alphabetic."
           << endl;

   if ( result2 )
      cout << "The character '!' in locale loc2 is alphabetic."
           << endl;
   else
      cout << "The character '!' in locale loc2 is not alphabetic."
           << endl;
}
```

```Output
The character 'a' in locale loc1 is alphabetic.
The character '!' in locale loc2 is not alphabetic.
```

## <a name="see-also"></a>Consulte também

[\<locale>](../standard-library/locale.md)
