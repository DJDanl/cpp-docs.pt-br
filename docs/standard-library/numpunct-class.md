---
title: Classe numpunct
ms.date: 11/04/2016
f1_keywords:
- xlocnum/std::numpunct
- xlocnum/std::numpunct::char_type
- xlocnum/std::numpunct::string_type
- xlocnum/std::numpunct::decimal_point
- xlocnum/std::numpunct::do_decimal_point
- xlocnum/std::numpunct::do_falsename
- xlocnum/std::numpunct::do_grouping
- xlocnum/std::numpunct::do_thousands_sep
- xlocnum/std::numpunct::do_truename
- xlocnum/std::numpunct::falsename
- xlocnum/std::numpunct::grouping
- xlocnum/std::numpunct::thousands_sep
- xlocnum/std::numpunct::truename
helpviewer_keywords:
- std::numpunct [C++]
- std::numpunct [C++], char_type
- std::numpunct [C++], string_type
- std::numpunct [C++], decimal_point
- std::numpunct [C++], do_decimal_point
- std::numpunct [C++], do_falsename
- std::numpunct [C++], do_grouping
- std::numpunct [C++], do_thousands_sep
- std::numpunct [C++], do_truename
- std::numpunct [C++], falsename
- std::numpunct [C++], grouping
- std::numpunct [C++], thousands_sep
- std::numpunct [C++], truename
ms.assetid: 73fb93cc-ac11-4c98-987c-bfa6267df596
ms.openlocfilehash: 602d8edef80f0e4d4abe4cb6773b774d174e1cbe
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87202812"
---
# <a name="numpunct-class"></a>Classe numpunct

Um modelo de classe que descreve um objeto que pode servir como uma faceta local para descrever as sequências do tipo `CharType` usado para representar informações sobre a formatação e a pontuação de expressões numéricas e booleanas.

## <a name="syntax"></a>Sintaxe

```cpp
template <class CharType>
class numpunct : public locale::facet;
```

### <a name="parameters"></a>parâmetros

*CharType*\
O tipo usado em um programa para codificar caracteres em uma localidade.

## <a name="remarks"></a>Comentários

Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo na **id.**

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[numpunct](#numpunct)|O construtor para objetos do tipo `numpunct`.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[char_type](#char_type)|Um tipo que é usado para descrever um caractere usado por uma localidade.|
|[string_type](#string_type)|Um tipo que descreve uma cadeia de caracteres que contém caracteres do tipo `CharType`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[decimal_point](#decimal_point)|Retorna um elemento específico de localidade a ser usado como uma vírgula decimal.|
|[do_decimal_point](#do_decimal_point)|Uma função membro virtual protegida que é chamada para retornar um elemento específico de localidade a ser usado como uma vírgula decimal.|
|[do_falsename](#do_falsename)|Uma função de membro virtual protegida que é chamada para retornar uma cadeia de caracteres a ser usada como uma representação de texto do valor **`false`** .|
|[do_grouping](#do_grouping)|Uma função membro virtual protegida que é chamada para retornar uma regra específica de localidade para determinar como os dígitos são agrupados à esquerda de qualquer vírgula decimal.|
|[do_thousands_sep](#do_thousands_sep)|Uma função membro virtual protegida que é chamada para retornar um elemento específico de localidade a ser usado como um separador de milhares.|
|[do_truename](#do_truename)|Uma função de membro virtual protegida que é chamada para retornar uma cadeia de caracteres a ser usada como uma representação de texto do valor **`true`** .|
|[falsename](#falsename)|Retorna uma cadeia de caracteres a ser usada como uma representação de texto do valor **`false`** .|
|[Agrupamento](#grouping)|Retorna uma regra específica de localidade para determinar como os dígitos são agrupados à esquerda de qualquer vírgula decimal.|
|[thousands_sep](#thousands_sep)|Retorna um elemento específico de localidade a ser usado como um separador de milhares.|
|[truename](#truename)|Retorna uma cadeia de caracteres a ser usada como uma representação de texto do valor **`true`** .|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<locale>

**Namespace:** std

## <a name="numpunctchar_type"></a><a name="char_type"></a>numpunct:: char_type

Um tipo que é usado para descrever um caractere usado por uma localidade.

```cpp
typedef CharType char_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o parâmetro de modelo **CharType.**

## <a name="numpunctdecimal_point"></a><a name="decimal_point"></a>numpunct::d ecimal_point

Retorna um elemento específico de localidade a ser usado como uma vírgula decimal.

```cpp
CharType decimal_point() const;
```

### <a name="return-value"></a>Valor retornado

Um elemento específico de localidade a ser usado como uma vírgula decimal.

### <a name="remarks"></a>Comentários

A função membro retorna [do_decimal_point](#do_decimal_point).

### <a name="example"></a>Exemplo

```cpp
// numpunct_decimal_point.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <sstream>
using namespace std;
int main( )
{
   locale loc( "german_germany" );

   const numpunct <char> &npunct =
   use_facet <numpunct <char> >( loc);
   cout << loc.name( ) << " decimal point "<<
   npunct.decimal_point( ) << endl;
   cout << loc.name( ) << " thousands separator "
   << npunct.thousands_sep( ) << endl;
};
```

```Output
German_Germany.1252 decimal point ,
German_Germany.1252 thousands separator .
```

## <a name="numpunctdo_decimal_point"></a><a name="do_decimal_point"></a>numpunct::d o_decimal_point

Uma função membro virtual protegida que é chamada para retornar um elemento específico de localidade a ser usado como uma vírgula decimal.

```cpp
virtual CharType do_decimal_point() const;
```

### <a name="return-value"></a>Valor retornado

Um elemento específico de localidade a ser usado como uma vírgula decimal.

### <a name="example"></a>Exemplo

Veja o exemplo de [decimal_point](#decimal_point), em que a função membro virtual é chamada por `decimal_point`.

## <a name="numpunctdo_falsename"></a><a name="do_falsename"></a>numpunct::d o_falsename

A função de membro virtual protegido retorna uma sequência a ser usada como uma representação de texto do valor **`false`** .

```cpp
virtual string_type do_falsename() const;
```

### <a name="return-value"></a>Valor retornado

Uma cadeia de caracteres que contém uma sequência a ser usada como uma representação de texto do valor **`false`** .

### <a name="remarks"></a>Comentários

A função member retorna a cadeia de caracteres "false" para representar o valor **`false`** em todas as localidades.

### <a name="example"></a>Exemplo

Veja o exemplo de [falsename](#falsename), em que a função membro virtual é chamada por `falsename`.

## <a name="numpunctdo_grouping"></a><a name="do_grouping"></a>numpunct::d o_grouping

Uma função membro virtual protegida que é chamada para retornar uma regra específica de localidade para determinar como os dígitos são agrupados à esquerda de qualquer vírgula decimal.

```cpp
virtual string do_grouping() const;
```

### <a name="return-value"></a>Valor retornado

Uma regra específica de localidade para determinar como os dígitos são agrupados à esquerda de qualquer vírgula decimal.

### <a name="remarks"></a>Comentários

A função membro virtual protegida retorna uma regra específica de localidade para determinar como os dígitos são agrupados à esquerda de qualquer vírgula decimal. A codificação é a mesma usada para **lconv::grouping**.

### <a name="example"></a>Exemplo

Consulte o exemplo de [agrupamento](#grouping), onde a função membro virtual é chamada por `grouping` .

## <a name="numpunctdo_thousands_sep"></a><a name="do_thousands_sep"></a>numpunct::d o_thousands_sep

Uma função membro virtual protegida que é chamada para retornar um elemento específico de localidade a ser usado como um separador de milhares.

```cpp
virtual CharType do_thousands_sep() const;
```

### <a name="return-value"></a>Valor retornado

Retorna um elemento específico de localidade a ser usado como um separador de milhares.

### <a name="remarks"></a>Comentários

A função de membro virtual protegido retorna um elemento específico de localidade do tipo `CharType` a ser usado como um separador de grupo à esquerda de qualquer ponto decimal.

### <a name="example"></a>Exemplo

Veja o exemplo de [thousands_sep](#thousands_sep), em que a função membro virtual é chamada por `thousands_sep`.

## <a name="numpunctdo_truename"></a><a name="do_truename"></a>numpunct::d o_truename

Uma função de membro virtual protegida que é chamada para retornar uma cadeia de caracteres a ser usada como uma representação de texto do valor **`true`** .

```cpp
virtual string_type do_truename() const;
```

### <a name="remarks"></a>Comentários

Uma cadeia de caracteres a ser usada como uma representação de texto do valor **`true`** .

Todas as localidades retornam uma cadeia de caracteres "true" para representar o valor **`true`** .

### <a name="example"></a>Exemplo

Veja o exemplo de [truename](#truename), em que a função membro virtual é chamada por `truename`.

## <a name="numpunctfalsename"></a><a name="falsename"></a>numpunct:: falsename

Retorna uma cadeia de caracteres a ser usada como uma representação de texto do valor **`false`** .

```cpp
string_type falsename() const;
```

### <a name="return-value"></a>Valor retornado

Uma cadeia de caracteres que contém uma sequência de `CharType` s para usar como uma representação de texto do valor **`false`** .

### <a name="remarks"></a>Comentários

A função member retorna a cadeia de caracteres "false" para representar o valor **`false`** em todas as localidades.

A função de membro retorna [do_falsename](#do_falsename).

### <a name="example"></a>Exemplo

```cpp
// numpunct_falsename.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <sstream>
using namespace std;
int main( )
{
   locale loc( "English" );

   const numpunct <char> &npunct = use_facet <numpunct <char> >( loc );
   cout << loc.name( ) << " truename "<< npunct.truename( ) << endl;
   cout << loc.name( ) << " falsename "<< npunct.falsename( ) << endl;

   locale loc2( "French" );
   const numpunct <char> &npunct2 = use_facet <numpunct <char> >(loc2);
   cout << loc2.name( ) << " truename "<< npunct2.truename( ) << endl;
   cout << loc2.name( ) << " falsename "<< npunct2.falsename( ) << endl;
}
```

```Output
English_United States.1252 truename true
English_United States.1252 falsename false
French_France.1252 truename true
French_France.1252 falsename false
```

## <a name="numpunctgrouping"></a><a name="grouping"></a>numpunct:: GROUPING

Retorna uma regra específica de localidade para determinar como os dígitos são agrupados à esquerda de qualquer vírgula decimal.

```cpp
string grouping() const;
```

### <a name="return-value"></a>Valor retornado

Uma regra específica de localidade para determinar como os dígitos são agrupados à esquerda de qualquer vírgula decimal.

### <a name="remarks"></a>Comentários

A função membro retorna [do_grouping](#do_grouping).

### <a name="example"></a>Exemplo

```cpp
// numpunct_grouping.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <sstream>
using namespace std;
int main( )
{
   locale loc( "german_germany");

   const numpunct <char> &npunct =
       use_facet < numpunct <char> >( loc );
   for (unsigned int i = 0; i < npunct.grouping( ).length( ); i++)
   {
      cout << loc.name( ) << " international grouping:\n the "
           << i <<"th group to the left of the radix character "
           << "is of size " << (int)(npunct.grouping ( )[i])
           << endl;
   }
}
```

```Output
German_Germany.1252 international grouping:
the 0th group to the left of the radix character is of size 3
```

## <a name="numpunctnumpunct"></a><a name="numpunct"></a>numpunct::numpunct

O construtor para objetos do tipo `numpunct`.

```cpp
explicit numpunct(size_t _Refs = 0);
```

### <a name="parameters"></a>parâmetros

*_Refs*\
Valor inteiro usado para especificar o tipo de gerenciamento de memória do objeto.

### <a name="remarks"></a>Comentários

Os valores possíveis para o parâmetro *_Refs* e seu significado são:

- 0: o tempo de vida do objeto é gerenciado pelas localidades que o contêm.

- 1: o tempo de vida do objeto deve ser gerenciado manualmente.

- \>1: esses valores não estão definidos.

Nenhum exemplo direto é possível, pois o destruidor está protegido.

O construtor inicializa seu objeto base com **locale::**[faceta](../standard-library/locale-class.md#facet_class)( `_Refs` ).

## <a name="numpunctstring_type"></a><a name="string_type"></a>numpunct:: string_type

Um tipo que descreve uma cadeia de caracteres que contém caracteres do tipo **CharType**.

```cpp
typedef basic_string<CharType, Traits, Allocator> string_type;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma especialização do modelo de classe [basic_string](../standard-library/basic-string-class.md) cujos objetos podem armazenar cópias das sequências de pontuação.

## <a name="numpunctthousands_sep"></a><a name="thousands_sep"></a>numpunct:: thousands_sep

Retorna um elemento específico de localidade a ser usado como um separador de milhares.

```cpp
CharType thousands_sep() const;
```

### <a name="return-value"></a>Valor retornado

Um elemento específico de localidade a ser usado como um separador de milhares.

### <a name="remarks"></a>Comentários

A função membro retorna [do_thousands_sep](#do_thousands_sep).

### <a name="example"></a>Exemplo

```cpp
// numpunct_thou_sep.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <sstream>
using namespace std;
int main( )
{
   locale loc( "german_germany" );

   const numpunct <char> &npunct =
   use_facet < numpunct < char > >( loc );
   cout << loc.name( ) << " decimal point "<<
   npunct.decimal_point( ) << endl;
   cout << loc.name( ) << " thousands separator "
   << npunct.thousands_sep( ) << endl;
};
```

```Output
German_Germany.1252 decimal point ,
German_Germany.1252 thousands separator .
```

## <a name="numpuncttruename"></a><a name="truename"></a>numpunct:: TrueName

Retorna uma cadeia de caracteres a ser usada como uma representação de texto do valor **`true`** .

```cpp
string_type falsename() const;
```

### <a name="return-value"></a>Valor retornado

Uma cadeia de caracteres a ser usada como uma representação de texto do valor **`true`** .

### <a name="remarks"></a>Comentários

A função de membro retorna [do_truename](#do_truename).

Todas as localidades retornam uma cadeia de caracteres "true" para representar o valor **`true`** .

### <a name="example"></a>Exemplo

```cpp
// numpunct_truename.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <sstream>
using namespace std;
int main( )
{
   locale loc( "English" );

   const numpunct < char> &npunct = use_facet <numpunct <char> >( loc );
   cout << loc.name( ) << " truename "<< npunct.truename( ) << endl;
   cout << loc.name( ) << " falsename "<< npunct.falsename( ) << endl;

   locale loc2("French");
   const numpunct <char> &npunct2 = use_facet <numpunct <char> >( loc2 );
   cout << loc2.name( ) << " truename "<< npunct2.truename( ) << endl;
   cout << loc2.name( ) << " falsename "<< npunct2.falsename( ) << endl;
}
```

```Output
English_United States.1252 truename true
English_United States.1252 falsename false
French_France.1252 truename true
French_France.1252 falsename false
```

## <a name="see-also"></a>Confira também

[\<locale>](../standard-library/locale.md)\
[Classe de faceta](../standard-library/locale-class.md#facet_class)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
