---
title: Operadores &lt;lista&gt;
ms.date: 11/04/2016
f1_keywords:
- list/std::operator!=
- list/std::operator&gt;
- list/std::operator&gt;=
- list/std::operator&lt;
- list/std::operator&lt;=
- list/std::operator==
ms.assetid: 8103d8f2-c30f-49ad-ac50-b3ba6a907ebe
helpviewer_keywords:
- std::operator!= (list)
- std::operator&gt; (list)
- std::operator&gt;= (list)
- std::operator&lt; (list)
- std::operator&lt;= (list)
- std::operator== (list)
ms.openlocfilehash: 7b0b7540c1b9a55140405a55e8e034f9c6ec646c
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68246457"
---
# <a name="ltlistgt-operators"></a>Operadores &lt;lista&gt;

## <a name="op_neq"></a> operador! =

Testa se o objeto da lista à esquerda do operador é diferente do objeto da lista à direita.

```cpp
bool operator!=(
    const list<Type, Allocator>& left,
    const list<Type, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

*À esquerda*\
Um objeto do tipo `list`.

*Certo*\
Um objeto do tipo `list`.

### <a name="return-value"></a>Valor de retorno

**true** se as listas não forem iguais; **false** se as listas forem iguais.

### <a name="remarks"></a>Comentários

A comparação entre os objetos de lista baseia-se em uma comparação par de seus elementos. Duas listas serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

### <a name="example"></a>Exemplo

```cpp
// list_op_ne.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
using namespace std;
list <int> c1, c2;
c1.push_back( 1 );
c2.push_back( 2 );

if ( c1 != c2 )
cout << "Lists not equal." << endl;
else
cout << "Lists equal." << endl;
}
/* Output:
Lists not equal.
*/
```

## <a name="op_lt"></a> Operador&lt;

Testa se o objeto da lista à esquerda do operador é menor que o objeto da lista à direita.

```cpp
bool operator<(
    const list<Type, Allocator>& left,
    const list<Type, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

*À esquerda*\
Um objeto do tipo `list`.

*Certo*\
Um objeto do tipo `list`.

### <a name="return-value"></a>Valor de retorno

**true** se a lista no lado esquerdo do operador for menor que ou diferente da lista à direita do operador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

A comparação entre os objetos de lista baseia-se em uma comparação par de seus elementos. A relação menor que entre dois objetos é baseada em uma comparação do primeiro par de elementos desiguais.

### <a name="example"></a>Exemplo

```cpp
// list_op_lt.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list <int> c1, c2;
   c1.push_back( 1 );
   c1.push_back( 2 );
   c1.push_back( 4 );

   c2.push_back( 1 );
   c2.push_back( 3 );

   if ( c1 < c2 )
      cout << "List c1 is less than list c2." << endl;
   else
      cout << "List c1 is not less than list c2." << endl;
}
/* Output:
List c1 is less than list c2.
*/
```

## <a name="op_lt_eq"></a> operador&lt;=

Testa se o objeto da lista à esquerda do operador é menor que ou igual ao objeto da lista à direita.

```cpp
bool operator<=(
    const list<Type, Allocator>& left,
    const list<Type, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

*À esquerda*\
Um objeto do tipo `list`.

*Certo*\
Um objeto do tipo `list`.

### <a name="return-value"></a>Valor de retorno

**true** se a lista no lado esquerdo do operador for menor que ou igual à lista à direita do operador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

A comparação entre os objetos de lista baseia-se em uma comparação par de seus elementos. A relação menor que ou igual a entre dois objetos é baseada em uma comparação entre o primeiro par de elementos desiguais.

### <a name="example"></a>Exemplo

```cpp
// list_op_le.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list <int> c1, c2;
   c1.push_back( 1 );
   c1.push_back( 2 );
   c1.push_back( 4 );

   c2.push_back( 1 );
   c2.push_back( 3 );

   if ( c1 <= c2 )
      cout << "List c1 is less than or equal to list c2." << endl;
   else
      cout << "List c1 is greater than list c2." << endl;
}
/* Output:
List c1 is less than or equal to list c2.
*/
```

## <a name="op_eq_eq"></a> operador = =

Testa se o objeto da lista à esquerda do operador é igual ao objeto da lista à direita.

```cpp
bool operator==(
    const list<Type, Allocator>& left,
    const list<Type, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

*À esquerda*\
Um objeto do tipo `list`.

*Certo*\
Um objeto do tipo `list`.

### <a name="return-value"></a>Valor de retorno

**true** se a lista no lado esquerdo do operador for igual à lista à direita do operador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

A comparação entre os objetos de lista baseia-se em uma comparação par de seus elementos. Duas listas serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

### <a name="example"></a>Exemplo

```cpp
// list_op_eq.cpp
// compile with: /EHsc
#include <list>
#include <iostream>
int main( )
{
   using namespace std;

   list <int> c1, c2;
   c1.push_back( 1 );
   c2.push_back( 1 );

   if ( c1 == c2 )
      cout << "The lists are equal." << endl;
   else
      cout << "The lists are not equal." << endl;
}
/* Output:
The lists are equal.
*/
```

## <a name="op_gt"></a> Operador&gt;

Testa se o objeto da lista à esquerda do operador é maior que o objeto da lista à direita.

```cpp
bool operator>(
    const list<Type, Allocator>& left,
    const list<Type, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

*À esquerda*\
Um objeto do tipo `list`.

*Certo*\
Um objeto do tipo `list`.

### <a name="return-value"></a>Valor de retorno

**true** se a lista no lado esquerdo do operador for maior que a lista à direita do operador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

A comparação entre os objetos de lista baseia-se em uma comparação par de seus elementos. A relação maior que entre dois objetos é baseada em uma comparação entre o primeiro par de elementos desiguais.

### <a name="example"></a>Exemplo

```cpp
// list_op_gt.cpp
// compile with: /EHsc
#include <list>
#include <iostream>
int main( )
{
   using namespace std;
   list <int> c1, c2;
   c1.push_back( 1 );
   c1.push_back( 3 );
   c1.push_back( 1 );

   c2.push_back( 1 );
   c2.push_back( 2 );
   c2.push_back( 2 );

   if ( c1 > c2 )
      cout << "List c1 is greater than list c2." << endl;
   else
      cout << "List c1 is not greater than list c2." << endl;
}
/* Output:
List c1 is greater than list c2.
*/
```

## <a name="op_gt_eq"></a> operador&gt;=

Testa se o objeto da lista à esquerda do operador é maior que ou igual ao objeto da lista à direita.

```cpp
bool operator>=(
    const list<Type, Allocator>& left,
    const list<Type, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

*À esquerda*\
Um objeto do tipo `list`.

*Certo*\
Um objeto do tipo `list`.

### <a name="return-value"></a>Valor de retorno

**true** se a lista no lado esquerdo do operador for maior que ou igual à lista à direita do operador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

A comparação entre os objetos de lista baseia-se em uma comparação par de seus elementos. A relação maior que ou igual entre dois objetos é baseada em uma comparação entre o primeiro par de elementos diferentes.

### <a name="example"></a>Exemplo

```cpp
// list_op_ge.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list <int> c1, c2;
   c1.push_back( 1 );
   c1.push_back( 3 );
   c1.push_back( 1 );

   c2.push_back( 1 );
   c2.push_back( 2 );
   c2.push_back( 2 );

   if ( c1 >= c2 )
      cout << "List c1 is greater than or equal to list c2." << endl;
   else
      cout << "List c1 is less than list c2." << endl;
}
/* Output:
List c1 is greater than or equal to list c2.
*/
```
