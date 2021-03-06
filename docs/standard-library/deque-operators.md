---
title: Operadores &lt;deque&gt;
ms.date: 11/04/2016
f1_keywords:
- deque/std::operator!=
- deque/std::operator&gt;
- deque/std::operator&gt;=
- deque/std::operator&lt;
- deque/std::operator&lt;=
- deque/std::operator==
ms.assetid: 482d7c92-54c7-493b-99e6-2a73617481a5
helpviewer_keywords:
- std::operator!= (deque)
- std::operator&gt; (deque)
- std::operator&gt;= (deque)
- std::operator&lt; (deque)
- std::operator&lt;= (deque)
- std::operator== (deque)
ms.openlocfilehash: d91fe64e7d06a80402a0a540be8f63d98ea96d37
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222479"
---
# <a name="ltdequegt-operators"></a>Operadores &lt;deque&gt;

## <a name="operator"></a><a name="op_neq"></a>operador! =

Testa se o objeto do deque do lado esquerdo do operador não é igual ao objeto do deque do lado direito.

```cpp
bool operator!=(const deque<Type, Allocator>& left, const deque<Type, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Um objeto do tipo `deque`.

*Certo*\
Um objeto do tipo `deque`.

### <a name="return-value"></a>Valor retornado

**`true`** Se os objetos deque não forem iguais; **`false`** se os objetos deque forem iguais.

### <a name="remarks"></a>Comentários

A comparação entre os objetos de deque baseia-se em uma comparação par de seus elementos. Dois objetos do deque serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

### <a name="example"></a>Exemplo

```cpp
// deque_op_ne.cpp
// compile with: /EHsc
#include <deque>
#include <iostream>

int main( )
{
   using namespace std;
   deque <int> c1, c2;

   c1.push_back( 1 );
   c2.push_back( 2 );

   if ( c1 != c2 )
      cout << "The deques are not equal." << endl;
   else
      cout << "The deques are equal." << endl;
}
```

```Output
The deques are not equal.
```

## <a name="operatorlt"></a><a name="op_lt"></a>operador&lt;

Testa se o objeto do deque do lado esquerdo do operador é menor que o objeto do deque do lado direito.

```cpp
bool operator<(const deque<Type, Allocator>& left, const deque<Type, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Um objeto do tipo `deque`.

*Certo*\
Um objeto do tipo `deque`.

### <a name="return-value"></a>Valor retornado

**`true`** Se o deque no lado esquerdo do operador for menor que e diferente de deque no lado direito do operador; caso contrário **`false`** .

### <a name="remarks"></a>Comentários

A comparação entre os objetos de deque baseia-se em uma comparação par de seus elementos. A relação menor que entre dois objetos é baseada em uma comparação do primeiro par de elementos desiguais.

### <a name="example"></a>Exemplo

```cpp
// deque_op_lt.cpp
// compile with: /EHsc
#include <deque>
#include <iostream>

int main( )
{
   using namespace std;
   deque <int> c1, c2;

   c1.push_back( 1 );
   c1.push_back( 2 );
   c1.push_back( 4 );

   c2.push_back( 1 );
   c2.push_back( 3 );

   if ( c1 < c2 )
      cout << "Deque c1 is less than deque c2." << endl;
   else
      cout << "Deque c1 is not less than deque c2." << endl;
}
```

```Output
Deque c1 is less than deque c2.
```

## <a name="operatorlt"></a><a name="op_lt_eq"></a>operador&lt;=

Testa se o objeto do deque do lado esquerdo do operador é menor ou igual ao objeto do deque do lado direito.

```cpp
bool operator<=(const deque<Type, Allocator>& left, const deque<Type, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Um objeto do tipo `deque`.

*Certo*\
Um objeto do tipo `deque`.

### <a name="return-value"></a>Valor retornado

**`true`** Se o deque no lado esquerdo do operador for menor ou igual ao deque no lado direito do operador; caso contrário **`false`** .

### <a name="remarks"></a>Comentários

A comparação entre os objetos de deque baseia-se em uma comparação par de seus elementos. A relação menor que ou igual a entre dois objetos é baseada em uma comparação entre o primeiro par de elementos desiguais.

### <a name="example"></a>Exemplo

```cpp
// deque_op_le.cpp
// compile with: /EHsc
#include <deque>
#include <iostream>

int main( )
{
   using namespace std;
   deque <int> c1, c2;

   c1.push_back( 1 );
   c1.push_back( 2 );
   c1.push_back( 4 );

   c2.push_back( 1 );
   c2.push_back( 3 );

   if ( c1 <= c2 )
      cout << "Deque c1 is less than or equal to deque c2." << endl;
   else
      cout << "Deque c1 is greater than deque c2." << endl;
}
```

```Output
Deque c1 is less than or equal to deque c2.
```

## <a name="operator"></a><a name="op_eq_eq"></a>operador = =

Testa se o objeto do deque do lado esquerdo do operador é igual ao objeto do deque do lado direito.

```cpp
bool operator==(const deque<Type, Allocator>& left, const deque<Type, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Um objeto do tipo `deque`.

*Certo*\
Um objeto do tipo `deque`.

### <a name="return-value"></a>Valor retornado

**`true`** Se o deque no lado esquerdo do operador for igual ao deque no lado direito do operador; caso contrário **`false`** .

### <a name="remarks"></a>Comentários

A comparação entre os objetos de deque baseia-se em uma comparação par de seus elementos. Dois deques serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

### <a name="example"></a>Exemplo

```cpp
// deque_op_eq.cpp
// compile with: /EHsc
#include <deque>
#include <iostream>

int main( )
{
   using namespace std;
   deque <int> c1, c2;

   c1.push_back( 1 );
   c2.push_back( 1 );

   if ( c1 == c2 )
      cout << "The deques are equal." << endl;
   else
      cout << "The deques are not equal." << endl;

   c1.push_back( 1 );
   if ( c1 == c2 )
      cout << "The deques are equal." << endl;
   else
      cout << "The deques are not equal." << endl;
}
```

```Output
The deques are equal.
The deques are not equal.
```

## <a name="operatorgt"></a><a name="op_gt"></a>operador&gt;

Testa se o objeto do deque do lado esquerdo do operador é maior que o objeto do deque do lado direito.

```cpp
bool operator>(const deque<Type, Allocator>& left, const deque<Type, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Um objeto do tipo `deque`.

*Certo*\
Um objeto do tipo `deque`.

### <a name="return-value"></a>Valor retornado

**`true`** Se o deque no lado esquerdo do operador for maior que o deque no lado direito do operador; caso contrário **`false`** .

### <a name="remarks"></a>Comentários

A comparação entre os objetos de deque baseia-se em uma comparação par de seus elementos. A relação maior que entre dois objetos é baseada em uma comparação entre o primeiro par de elementos desiguais.

### <a name="example"></a>Exemplo

```cpp
// deque_op_gt.cpp
// compile with: /EHsc
#include <deque>
#include <iostream>

int main( )
{
   using namespace std;
   deque <int> c1, c2;

   c1.push_back( 1 );
   c1.push_back( 3 );
   c1.push_back( 1 );

   c2.push_back( 1 );
   c2.push_back( 2 );
   c2.push_back( 2 );

   if ( c1 > c2 )
      cout << "Deque c1 is greater than deque c2." << endl;
   else
      cout << "Deque c1 is not greater than deque c2." << endl;
}
```

```Output
Deque c1 is greater than deque c2.
```

## <a name="operatorgt"></a><a name="op_gt_eq"></a>operador&gt;=

Testa se o objeto do deque do lado esquerdo do operador é maior ou igual ao objeto do deque do lado direito.

```cpp
bool operator>=(const deque<Type, Allocator>& left, const deque<Type, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Um objeto do tipo `deque`.

*Certo*\
Um objeto do tipo `deque`.

### <a name="return-value"></a>Valor retornado

**`true`** Se o deque no lado esquerdo do operador for maior ou igual ao deque no lado direito do operador; caso contrário **`false`** .

### <a name="remarks"></a>Comentários

A comparação entre os objetos de deque baseia-se em uma comparação par de seus elementos. A relação maior que ou igual entre dois objetos é baseada em uma comparação entre o primeiro par de elementos diferentes.

### <a name="example"></a>Exemplo

```cpp
// deque_op_ge.cpp
// compile with: /EHsc
#include <deque>
#include <iostream>

int main( )
{
   using namespace std;
   deque <int> c1, c2;

   c1.push_back( 1 );
   c1.push_back( 3 );
   c1.push_back( 1 );

   c2.push_back( 1 );
   c2.push_back( 2 );
   c2.push_back( 2 );

   if ( c1 >= c2 )
      cout << "Deque c1 is greater than or equal to deque c2." << endl;
   else
      cout << "Deque c1 is less than deque c2." << endl;
}
```

```Output
Deque c1 is greater than or equal to deque c2.
```
