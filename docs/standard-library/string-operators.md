---
title: Operadores de &lt;cadeia de caracteres&gt;
ms.date: 11/04/2016
f1_keywords:
- string/std::operator!=
- string/std::operator&gt;
- string/std::operator&gt;&gt;
- string/std::operator&gt;=
- string/std::operator&lt;
- string/std::operator&lt;&lt;
- string/std::operator&lt;=
- string/std::operator+
- string/std::operator==
ms.assetid: 33ce8f05-06c7-45d3-a0cb-bcd27cf93910
helpviewer_keywords:
- std::operator!= (string)
- std::operator&gt; (string)
- std::operator&gt;&gt; (string)
- std::operator&gt;= (string)
- std::operator&lt; (string)
- std::operator&lt;&lt; (string)
- std::operator&lt;= (string), std::operator== (string)
ms.openlocfilehash: e031eb4421906e35a96a862855a140218f233778
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88832536"
---
# <a name="ltstringgt-operators"></a>Operadores de &lt;cadeia de caracteres&gt;

[operador! =](#op_neq)\
[operador&gt;](#op_gt)\
[operador&gt;&gt;](#op_gt_gt)\
[operador&gt;=](#op_gt_eq)\
[operador&lt;](#op_lt)\
[operador&lt;&lt;](#op_lt_lt)\
[operador&lt;=](#op_lt_eq)\
[operador +](#op_add)\
[operador = =](#op_eq_eq)

## <a name="operator"></a><a name="op_add"></a> operador +

Concatena dois objetos de cadeia de caracteres.

```cpp
template <class CharType, class Traits, class Allocator>
basic_string<CharType, Traits, Allocator> operator+(
    const basic_string<CharType, Traits, Allocator>& left,
    const basic_string<CharType, Traits, Allocator>& right);

template <class CharType, class Traits, class Allocator>
basic_string<CharType, Traits, Allocator> operator+(
    const basic_string<CharType, Traits, Allocator>& left,
    const CharType* right);

template <class CharType, class Traits, class Allocator>
basic_string<CharType, Traits, Allocator> operator+(
    const basic_string<CharType, Traits, Allocator>& left,
    const CharType right);

template <class CharType, class Traits, class Allocator>
basic_string<CharType, Traits, Allocator> operator+(
    const CharType* left,
    const basic_string<CharType, Traits, Allocator>& right);

template <class CharType, class Traits, class Allocator>
basic_string<CharType, Traits, Allocator> operator+(
    const CharType left,
    const basic_string<CharType, Traits, Allocator>& right);

template <class CharType, class Traits, class Allocator>
basic_string<CharType, Traits, Allocator>&& operator+(
    const basic_string<CharType, Traits, Allocator>& left,
    const basic_string<CharType, Traits, Allocator>&& right);

template <class CharType, class Traits, class Allocator>
basic_string<CharType, Traits, Allocator>&& operator+(
    const basic_string<CharType, Traits, Allocator>&& left,
    const basic_string<CharType, Traits, Allocator>& right);

template <class CharType, class Traits, class Allocator>
basic_string<CharType, Traits, Allocator>&& operator+(
    const basic_string<CharType, Traits, Allocator>&& left,
    const basic_string<CharType, Traits, Allocator>&& right);

template <class CharType, class Traits, class Allocator>
basic_string<CharType, Traits, Allocator>&& operator+(
    const basic_string<CharType, Traits, Allocator>&& left,
    const CharType* right);

template <class CharType, class Traits, class Allocator>
basic_string<CharType, Traits, Allocator>&& operator+(
    const basic_string<CharType, Traits, Allocator>&& left,
    CharType right);

template <class CharType, class Traits, class Allocator>
basic_string<CharType, Traits, Allocator>&& operator+(
    const CharType* left,
    const basic_string<CharType, Traits, Allocator>&& right);

template <class CharType, class Traits, class Allocator>
basic_string<CharType, Traits, Allocator>&& operator+(
    CharType left,
    const basic_string<CharType, Traits, Allocator>&& right);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Uma cadeia de caracteres de estilo C ou um objeto do tipo `basic_string` a ser concatenado.

*Certo*\
Uma cadeia de caracteres de estilo C ou um objeto do tipo `basic_string` a ser concatenado.

### <a name="return-value"></a>Valor Retornado

A cadeia de caracteres que é a concatenação de cadeias de caracteres de entrada.

### <a name="remarks"></a>Comentários

As funções cada sobrecarga `operator+` para concatenar dois objetos do modelo de classe [basic_string classe](../standard-library/basic-string-class.md). Efetivamente retornam `basic_string< CharType, Traits, Allocator>(Left).append(right)` . Para obter mais informações, consulte [Append](../standard-library/basic-string-class.md#append).

### <a name="example"></a>Exemplo

```cpp
// string_op_con.cpp
// compile with: /EHsc
#include <string>
#include <iostream>

int main( )
{
   using namespace std;
   // Declaring an object of type basic_string<char>
   string s1 ( "anti" );
   string s2 ( "gravity" );
   cout << "The basic_string s1 = " << s1 << "." << endl;
   cout << "The basic_string s2 = " << s2 << "." << endl;

   // Declaring a C-style string
   char *s3 = "heroine";
   cout << "The C-style string s3 = " << s3 << "." << endl;

   // Declaring a character constant
   char c1 = '!';
   cout << "The character constant c1 = " << c1 << "." << endl;

   // First member function: concatenates an  object
   // of type basic_string with an object of type basic_string
   string s12 = s1 + s2;
   cout << "The string concatenating s1 & s2 is: " << s12 << endl;

   // Second & fourth member functions: concatenate an object
   // of type basic_string with an object of C-syle string type
   string s1s3 = s1 + s3;
   cout << "The string concatenating s1 & s3 is: " << s1s3 << endl;

   // Third & fifth member functions: concatenate an object
   // of type basic_string with a character constant
   string s1s3c1 = s1s3 + c1;
   cout << "The string concatenating s1 & s3 is: " << s1s3c1 << endl;
}
```

```Output
The basic_string s1 = anti.
The basic_string s2 = gravity.
The C-style string s3 = heroine.
The character constant c1 = !.
The string concatenating s1 & s2 is: antigravity
The string concatenating s1 & s3 is: antiheroine
The string concatenating s1 & s3 is: antiheroine!
```

## <a name="operator"></a><a name="op_neq"></a> operador! =

Testa se o objeto da cadeia de caracteres à esquerda do operador é diferente do objeto da cadeia de caracteres à direita.

```cpp
template <class CharType, class Traits, class Allocator>
bool operator!=(
    const basic_string<CharType, Traits, Allocator>& left,
    const basic_string<CharType, Traits, Allocator>& right);

template <class CharType, class Traits, class Allocator>
bool operator!=(
    const basic_string<CharType, Traits, Allocator>& left,
const CharType* right);

template <class CharType, class Traits, class Allocator>
bool operator!=(
    const CharType* left,
    const basic_string<CharType, Traits, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Uma cadeia de caracteres de estilo C ou um objeto do tipo `basic_string` a ser comparado.

*Certo*\
Uma cadeia de caracteres de estilo C ou um objeto do tipo `basic_string` a ser comparado.

### <a name="return-value"></a>Valor Retornado

**`true`** Se o objeto de cadeia de caracteres no lado esquerdo do operador não for modo lexicográfico igual ao objeto de cadeia de caracteres no lado direito; caso contrário **`false`** .

### <a name="remarks"></a>Comentários

A comparação entre os objetos da cadeia de caracteres baseia-se em uma comparação de pares lexicográficos de seus caracteres. Duas cadeias de caracteres são iguais se tiverem o mesmo número de caracteres e seus valores de caractere respectivos são os mesmos. Caso contrário, são diferentes.

### <a name="example"></a>Exemplo

```cpp
// string_op_ne.cpp
// compile with: /EHsc
#include <string>
#include <iostream>

int main( )
{
   using namespace std;

   // Declaring an objects of type basic_string<char>
   string s1 ( "pluck" );
   string s2 ( "strum" );
   cout << "The basic_string s1 = " << s1 << "." << endl;
   cout << "The basic_string s2 = " << s2 << "." << endl;

   // Declaring a C-style string
   char *s3 = "pluck";
   cout << "The C-style string s3 = " << s3 << "." << endl;

   // First member function: comparison between left-side object
   // of type basic_string & right-side object of type basic_string
   if ( s1 != s2 )
      cout << "The strings s1 & s2 are not equal." << endl;
   else
      cout << "The strings s1 & s2 are equal." << endl;

   // Second member function: comparison between left-side object
   // of type basic_string & right-side object of C-syle string type
   if ( s1 != s3 )
      cout << "The strings s1 & s3 are not equal." << endl;
   else
      cout << "The strings s1 & s3 are equal." << endl;

   // Third member function: comparison between left-side object
   // of C-syle string type & right-side object of type basic_string
   if ( s3 != s2 )
      cout << "The strings s3 & s2 are not equal." << endl;
   else
      cout << "The strings s3 & s2 are equal." << endl;
}
```

```Output
The basic_string s1 = pluck.
The basic_string s2 = strum.
The C-style string s3 = pluck.
The strings s1 & s2 are not equal.
The strings s1 & s3 are equal.
The strings s3 & s2 are not equal.
```

## <a name="operator"></a><a name="op_eq_eq"></a> operador = =

Testa se o objeto da cadeia de caracteres à esquerda do operador é igual ao objeto da cadeia de caracteres à direita.

```cpp
template <class CharType, class Traits, class Allocator>
bool operator==(
    const basic_string<CharType, Traits, Allocator>& left,
    const basic_string<CharType, Traits, Allocator>& right);

template <class CharType, class Traits, class Allocator>
bool operator==(
    const basic_string<CharType, Traits, Allocator>& left,
    const CharType* right);

template <class CharType, class Traits, class Allocator>
bool operator==(
    const CharType* left,
    const basic_string<CharType, Traits, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Uma cadeia de caracteres de estilo C ou um objeto do tipo `basic_string` a ser comparado.

*Certo*\
Uma cadeia de caracteres de estilo C ou um objeto do tipo `basic_string` a ser comparado.

### <a name="return-value"></a>Valor Retornado

**`true`** Se o objeto de cadeia de caracteres no lado esquerdo do operador for modo lexicográfico igual ao objeto de cadeia de caracteres no lado direito; caso contrário **`false`** .

### <a name="remarks"></a>Comentários

A comparação entre os objetos da cadeia de caracteres baseia-se em uma comparação de pares lexicográficos de seus caracteres. Duas cadeias de caracteres são iguais se tiverem o mesmo número de caracteres e seus valores de caractere respectivos são os mesmos. Caso contrário, são diferentes.

### <a name="example"></a>Exemplo

```cpp
// string_op_eq.cpp
// compile with: /EHsc
#include <string>
#include <iostream>

int main( )
{
   using namespace std;

   // Declaring an objects of type basic_string<char>
   string s1 ( "pluck" );
   string s2 ( "strum" );
   cout << "The basic_string s1 = " << s1 << "." << endl;
   cout << "The basic_string s2 = " << s2 << "." << endl;

   // Declaring a C-style string
   char *s3 = "pluck";
   cout << "The C-style string s3 = " << s3 << "." << endl;

   // First member function: comparison between left-side object
   // of type basic_string & right-side object of type basic_string
   if ( s1 == s2 )
      cout << "The strings s1 & s2 are equal." << endl;
   else
      cout << "The strings s1 & s2 are not equal." << endl;

   // Second member function: comparison between left-side object
   // of type basic_string & right-side object of C-syle string type
   if ( s1 == s3 )
      cout << "The strings s1 & s3 are equal." << endl;
   else
      cout << "The strings s1 & s3 are not equal." << endl;

   // Third member function: comparison between left-side object
   // of C-syle string type & right-side object of type basic_string
   if ( s3 == s2 )
      cout << "The strings s3 & s2 are equal." << endl;
   else
      cout << "The strings s3 & s2 are not equal." << endl;
}
```

```Output
The basic_string s1 = pluck.
The basic_string s2 = strum.
The C-style string s3 = pluck.
The strings s1 & s2 are not equal.
The strings s1 & s3 are equal.
The strings s3 & s2 are not equal.
```

## <a name="operatorlt"></a><a name="op_lt"></a> operador&lt;

Testa se o objeto da cadeia de caracteres à esquerda do operador é menor que o objeto da cadeia de caracteres à direita.

```cpp
template <class CharType, class Traits, class Allocator>
bool operator<(
    const basic_string<CharType, Traits, Allocator>& left,
    const basic_string<CharType, Traits, Allocator>& right);

template <class CharType, class Traits, class Allocator>
bool operator<(
    const basic_string<CharType, Traits, Allocator>& left,
    const CharType* right);

template <class CharType, class Traits, class Allocator>
bool operator<(
    const CharType* left,
    const basic_string<CharType, Traits, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Uma cadeia de caracteres de estilo C ou um objeto do tipo `basic_string` a ser comparado.

*Certo*\
Uma cadeia de caracteres de estilo C ou um objeto do tipo `basic_string` a ser comparado.

### <a name="return-value"></a>Valor Retornado

**`true`** Se o objeto de cadeia de caracteres no lado esquerdo do operador for modo lexicográfico menor que o objeto de cadeia de caracteres no lado direito; caso contrário **`false`** .

### <a name="remarks"></a>Comentários

Uma comparação entre cadeias de caracteres lexicográficos compara-as por caractere até:

- Localiza dois elementos correspondentes diferentes e o resultado da comparação entre eles será considerado o resultado da comparação entre as cadeias de caracteres.

- Não encontra nenhuma desigualdade, mas uma cadeia de caracteres tem mais caracteres do que a outra e a cadeia de caracteres mais curta é considerada menor do que a cadeia de caracteres mais longa.

- Não encontra nenhuma desigualdade e percebe que as cadeias de caracteres têm o mesmo número de caracteres e então as cadeias de caracteres são iguais.

### <a name="example"></a>Exemplo

```cpp
// string_op_lt.cpp
// compile with: /EHsc
#include <string>
#include <iostream>

int main( )
{
   using namespace std;
   // Declaring an objects of type basic_string<char>
   string s1 ( "strict" );
   string s2 ( "strum" );
   cout << "The basic_string s1 = " << s1 << "." << endl;
   cout << "The basic_string s2 = " << s2 << "." << endl;

   // Declaring a C-style string
   char *s3 = "strict";
   cout << "The C-style string s3 = " << s3 << "." << endl;

   // First member function: comparison between left-side object
   // of type basic_string & right-side object of type basic_string
   if ( s1 < s2 )
      cout << "The string s1 is less than the string s2." << endl;
   else
      cout << "The string s1 is not less than the string s2." << endl;

   // Second member function: comparison between left-hand object
   // of type basic_string & right-hand object of C-syle string type
   if ( s1 < s3 )
      cout << "The string s1 is less than the string s3." << endl;
   else
      cout << "The string s1 is not less than the string s3." << endl;

   // Third member function: comparison between left-hand object
   // of C-syle string type & right-hand object of type basic_string
   if ( s3 < s2 )
      cout << "The string s3 is less than the string s2." << endl;
   else
      cout << "The string s3 is not less than the string s2." << endl;
}
```

```Output
The basic_string s1 = strict.
The basic_string s2 = strum.
The C-style string s3 = strict.
The string s1 is less than the string s2.
The string s1 is not less than the string s3.
The string s3 is less than the string s2.
```

## <a name="operatorlt"></a><a name="op_lt_eq"></a> operador&lt;=

Testa se o objeto da cadeia de caracteres à esquerda do operador é menor que ou igual ao objeto da cadeia de caracteres à direita.

```cpp
template <class CharType, class Traits, class Allocator>
bool operator<=(
    const basic_string<CharType, Traits, Allocator>& left,
    const basic_string<CharType, Traits, Allocator>& right);

template <class CharType, class Traits, class Allocator>
bool operator<=(
    const basic_string<CharType, Traits, Allocator>& left,
    const CharType* right);

template <class CharType, class Traits, class Allocator>
bool operator<=(
    const CharType* left,
    const basic_string<CharType, Traits, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Uma cadeia de caracteres de estilo C ou um objeto do tipo `basic_string` a ser comparado.

*Certo*\
Uma cadeia de caracteres de estilo C ou um objeto do tipo `basic_string` a ser comparado.

### <a name="return-value"></a>Valor Retornado

**`true`** Se o objeto de cadeia de caracteres no lado esquerdo do operador for modo lexicográfico menor ou igual ao objeto de cadeia de caracteres no lado direito; caso contrário **`false`** .

### <a name="remarks"></a>Comentários

Uma comparação entre cadeias de caracteres lexicográficos compara-as por caractere até:

- Localiza dois elementos correspondentes diferentes e o resultado da comparação entre eles será considerado o resultado da comparação entre as cadeias de caracteres.

- Não encontra nenhuma desigualdade, mas uma cadeia de caracteres tem mais caracteres do que a outra e a cadeia de caracteres mais curta é considerada menor do que a cadeia de caracteres mais longa.

- Não encontra nenhuma desigualdade e percebe que as cadeias de caracteres têm o mesmo número de caracteres, então as cadeias de caracteres são iguais.

### <a name="example"></a>Exemplo

```cpp
// string_op_le.cpp
// compile with: /EHsc
#include <string>
#include <iostream>

int main( )
{
   using namespace std;

   // Declaring an objects of type basic_string<char>
   string s1 ( "strict" );
   string s2 ( "strum" );
   cout << "The basic_string s1 = " << s1 << "." << endl;
   cout << "The basic_string s2 = " << s2 << "." << endl;

   // Declaring a C-style string
   char *s3 = "strict";
   cout << "The C-style string s3 = " << s3 << "." << endl;

   // First member function: comparison between left-side object
   // of type basic_string & right-side object of type basic_string
   if ( s1 <= s2 )
      cout << "The string s1 is less than or equal to "
           << "the string s2." << endl;
   else
      cout << "The string s1 is greater than "
           << "the string s2." << endl;

   // Second member function: comparison between left-side object
   // of type basic_string & right-side object of C-syle string type
   if ( s1 <= s3 )
      cout << "The string s1 is less than or equal to "
           << "the string s3." << endl;
   else
      cout << "The string s1 is greater than "
           << "the string s3." << endl;

   // Third member function: comparison between left-side object
   // of C-syle string type  & right-side object of type basic_string
   if ( s2 <= s3 )
      cout << "The string s2 is less than or equal to "
           << "the string s3." << endl;
   else
      cout << "The string s2 is greater than "
           << "the string s3." << endl;
}
```

```Output
The basic_string s1 = strict.
The basic_string s2 = strum.
The C-style string s3 = strict.
The string s1 is less than or equal to the string s2.
The string s1 is less than or equal to the string s3.
The string s2 is greater than the string s3.
```

## <a name="operatorltlt"></a><a name="op_lt_lt"></a> operador&lt;&lt;

Uma função de modelo que grava uma cadeia de caracteres no fluxo de saída.

```cpp
template <class CharType, class Traits, class Allocator>
basic_ostream<CharType, Traits>& operator<<(
    basic_ostream<CharType, Traits>& _Ostr,
    const basic_string<CharType, Traits, Allocator>& str);
```

### <a name="parameters"></a>parâmetros

*_Ostr*\
O fluxo de saída que está sendo gravado.

*Str*\
A cadeia de caracteres a ser inserida no fluxo de saída.

### <a name="return-value"></a>Valor Retornado

Grava o valor da cadeia de caracteres especificada no fluxo de saída *_Ostr*.

### <a name="remarks"></a>Comentários

A função de modelo sobrecarrega o **operador<<** para inserir um objeto *Str* do modelo de classe [basic_string](../standard-library/basic-string-class.md) no fluxo * \_ OSTR*. A função retorna efetivamente `_Ostr.write( str.c_str, str.size )` .

## <a name="operatorgt"></a><a name="op_gt"></a> operador&gt;

Testa se o objeto da cadeia de caracteres à esquerda do operador é maior que o objeto da cadeia de caracteres à direita.

```cpp
template <class CharType, class Traits, class Allocator>
bool operator>(
    const basic_string<CharType, Traits, Allocator>& left,
    const basic_string<CharType, Traits, Allocator>& right);

template <class CharType, class Traits, class Allocator>
bool operator>(
    const basic_string<CharType, Traits, Allocator>& left,
    const CharType* right);

template <class CharType, class Traits, class Allocator>
bool operator>(
    const CharType* left,
    const basic_string<CharType, Traits, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Uma cadeia de caracteres de estilo C ou um objeto do tipo `basic_string` a ser comparado.

*Certo*\
Uma cadeia de caracteres de estilo C ou um objeto do tipo `basic_string` a ser comparado.

### <a name="return-value"></a>Valor Retornado

**`true`** Se o objeto de cadeia de caracteres no lado esquerdo do operador for modo lexicográfico maior que o objeto de cadeia de caracteres no lado direito; caso contrário **`false`** .

### <a name="remarks"></a>Comentários

Uma comparação entre cadeias de caracteres lexicográficos compara-as por caractere até:

- Localiza dois elementos correspondentes diferentes e o resultado da comparação entre eles será considerado o resultado da comparação entre as cadeias de caracteres.

- Não encontra nenhuma desigualdade, mas uma cadeia de caracteres tem mais caracteres do que a outra e a cadeia de caracteres mais curta é considerada menor do que a cadeia de caracteres mais longa.

- Não encontra nenhuma desigualdade e percebe que as cadeias de caracteres têm o mesmo número de caracteres e então as cadeias de caracteres são iguais.

### <a name="example"></a>Exemplo

```cpp
// string_op_gt.cpp
// compile with: /EHsc
#include <string>
#include <iostream>

int main( )
{
   using namespace std;

   // Declaring an objects of type basic_string<char>
   string s1 ( "strict" );
   string s2 ( "strum" );
   cout << "The basic_string s1 = " << s1 << "." << endl;
   cout << "The basic_string s2 = " << s2 << "." << endl;

   // Declaring a C-style string
   char *s3 = "stricture";
   cout << "The C-style string s3 = " << s3 << "." << endl;

   // First member function: comparison between left-side object
   // of type basic_string & right-side object of type basic_string
   if ( s1 > s2 )
      cout << "The string s1 is greater than "
           << "the string s2." << endl;
   else
      cout << "The string s1 is not greater than "
           << "the string s2." << endl;

   // Second member function: comparison between left-side object
   // of type basic_string & right-side object of C-syle string type
   if ( s3 > s1 )
      cout << "The string s3 is greater than "
           << "the string s1." << endl;
   else
      cout << "The string s3 is not greater than "
           << "the string s1." << endl;

   // Third member function: comparison between left-side object
   // of C-syle string type & right-side object of type basic_string
   if ( s2 > s3 )
      cout << "The string s2 is greater than "
           << "the string s3." << endl;
   else
      cout << "The string s2 is not greater than "
           << "the string s3." << endl;
}
```

```Output
The basic_string s1 = strict.
The basic_string s2 = strum.
The C-style string s3 = stricture.
The string s1 is not greater than the string s2.
The string s3 is greater than the string s1.
The string s2 is greater than the string s3.
```

## <a name="operatorgt"></a><a name="op_gt_eq"></a> operador&gt;=

Testa se o objeto da cadeia de caracteres à esquerda do operador é maior que ou igual ao objeto da cadeia de caracteres à direita.

```cpp
template <class CharType, class Traits, class Allocator>
bool operator>=(
    const basic_string<CharType, Traits, Allocator>& left,
    const basic_string<CharType, Traits, Allocator>& right);

template <class CharType, class Traits, class Allocator>
bool operator>=(
    const basic_string<CharType, Traits, Allocator>& left,
    const CharType* right);

template <class CharType, class Traits, class Allocator>
bool operator>=(
    const CharType* left,
    const basic_string<CharType, Traits, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Uma cadeia de caracteres de estilo C ou um objeto do tipo `basic_string` a ser comparado.

*Certo*\
Uma cadeia de caracteres de estilo C ou um objeto do tipo `basic_string` a ser comparado.

### <a name="return-value"></a>Valor Retornado

**`true`** Se o objeto de cadeia de caracteres no lado esquerdo do operador for modo lexicográfico maior ou igual ao objeto de cadeia de caracteres no lado direito; caso contrário **`false`** .

### <a name="remarks"></a>Comentários

Uma comparação entre cadeias de caracteres lexicográficos compara-as por caractere até:

- Localiza dois elementos correspondentes diferentes e o resultado da comparação entre eles será considerado o resultado da comparação entre as cadeias de caracteres.

- Não encontra nenhuma desigualdade, mas uma cadeia de caracteres tem mais caracteres do que a outra e a cadeia de caracteres mais curta é considerada menor do que a cadeia de caracteres mais longa.

- Não encontra nenhuma desigualdade e percebe que as cadeias de caracteres têm o mesmo número de caracteres e então as cadeias de caracteres são iguais.

### <a name="example"></a>Exemplo

```cpp
// string_op_ge.cpp
// compile with: /EHsc
#include <string>
#include <iostream>

int main( )
{
   using namespace std;

   // Declaring an objects of type basic_string<char>
   string s1 ( "strict" );
   string s2 ( "strum" );
   cout << "The basic_string s1 = " << s1 << "." << endl;
   cout << "The basic_string s2 = " << s2 << "." << endl;

   // Declaring a C-style string
   char *s3 = "stricture";
   cout << "The C-style string s3 = " << s3 << "." << endl;

   // First member function: comparison between left-side object
   // of type basic_string & right-side object of type basic_string
   if ( s1 >= s2 )
      cout << "The string s1 is greater than or equal to "
           << "the string s2." << endl;
   else
      cout << "The string s1 is less than "
           << "the string s2." << endl;

   // Second member function: comparison between left-side object
   // of type basic_string & right-side object of C-syle string type
   if ( s3 >= s1 )
      cout << "The string s3 is greater than or equal to "
           << "the string s1." << endl;
   else
      cout << "The string s3 is less than "
           << "the string s1." << endl;

   // Third member function: comparison between left-side object
   // of C-syle string type & right-side object of type basic_string
   if ( s2 >= s3 )
      cout << "The string s2 is greater than or equal to "
           << "the string s3." << endl;
   else
      cout << "The string s2 is less than "
           << "the string s3." << endl;
}
```

```Output
The basic_string s1 = strict.
The basic_string s2 = strum.
The C-style string s3 = stricture.
The string s1 is less than the string s2.
The string s3 is greater than or equal to the string s1.
The string s2 is greater than or equal to the string s3.
```

## <a name="operatorgtgt"></a><a name="op_gt_gt"></a> operador&gt;&gt;

Uma função de modelo que grava uma cadeia de caracteres de um fluxo de entrada.

```cpp
template <class CharType, class Traits, class Allocator>
basic_istream<CharType, Traits>& operator>>(
    basic_istream<CharType, Traits>& _Istr,
    basic_string<CharType, Traits, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

*_Istr*\
O fluxo de entrada usado para extrair a sequência

*Certo*\
A cadeia de caracteres que está sendo extraída do fluxo de entrada.

### <a name="return-value"></a>Valor Retornado

Lê o valor da cadeia de caracteres especificada de *_Istr* e a retorna à *direita*.

### <a name="remarks"></a>Comentários

O operador ignora os espaços em branco à esquerda, a menos que o sinalizador `skipws` é definido. Ele lê todos os caracteres seguintes até o próximo caractere ser um espaço em branco ou o final do arquivo for atingido.

A função de modelo sobrecarrega o **operador>>** para substituir a sequência controlada pela *direita* por uma sequência de elementos extraídos do fluxo *_Istr*. Extração para:

- Ao final do arquivo.

- Depois que a função extrai `_Istr`. **largura** elementos, se esse valor for diferente de zero.

Depois que a função extrai `_Istr`. [max_size](../standard-library/basic-string-class.md#max_size) elementos.

- Depois que a função extrai um elemento *ch* para o qual [use_facet](../standard-library/basic-filebuf-class.md#open) <  **CType** \< **CharType**> > ( `getloc` ). **is**( **CType** \< **CharType**> :: **Space**, *ch*) é true; nesse caso, o caractere é colocado de volta.

Se a função extrair nenhum elemento, ela chamará [SetState](../standard-library/basic-ios-class.md#setstate)( `ios_base::failbit` ). Em qualquer caso, chama **istr**. **largura**(0) e retorna \* **`this`** .

### <a name="example"></a>Exemplo

```cpp
// string_op_read_.cpp
// compile with: /EHsc
#include <string>
#include <iostream>

int main( )
{
   using namespace std;

   string c0;
   cout << "Input a string c0 ( try: Fibonacci numbers ): ";
   cin >> c0;
   cout << "The string entered is c0 = " << c0 << endl;
}
```

## <a name="see-also"></a>Confira também

[\<string>](../standard-library/string.md)
