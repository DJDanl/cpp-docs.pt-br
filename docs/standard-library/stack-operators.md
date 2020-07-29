---
title: Operadores &lt;stack&gt;
ms.date: 11/04/2016
f1_keywords:
- stack/std::operator!=
- stack/std::operator&gt;
- stack/std::operator&gt;=
- stack/std::operator&lt;
- stack/std::operator&lt;=
- stack/std::operator==
ms.assetid: 9c1fc282-2f61-4727-9e80-84ea5d4934a2
helpviewer_keywords:
- std::operator!= (stack)
- std::operator&gt; (stack)
- std::operator&gt;= (stack)
- std::operator&lt; (stack)
- std::operator&lt;= (stack)
- std::operator== (stack)
ms.openlocfilehash: ac694e517279e43a501bb8289544e5da5ddba72b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217409"
---
# <a name="ltstackgt-operators"></a>Operadores &lt;stack&gt;

## <a name="operator"></a><a name="op_neq"></a>operador! =

Testa se o objeto stack do lado esquerdo do operador não é igual ao objeto stack do lado direito.

```cpp
bool operator!=(const stack <Type, Container>& left, const stack <Type, Container>& right,);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Um objeto do tipo `stack`.

*Certo*\
Um objeto do tipo `stack`.

### <a name="return-value"></a>Valor retornado

**`true`** Se as pilhas ou pilhas não forem iguais; **`false`** se as pilhas ou pilhas forem iguais.

### <a name="remarks"></a>Comentários

A comparação entre os objetos stack baseia-se em uma comparação par de seus elementos. Duas stacks serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

### <a name="example"></a>Exemplo

```cpp
// stack_op_me.cpp
// compile with: /EHsc
#include <stack>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;

   // Declares stacks with vector base containers
   stack <int, vector<int> > s1, s2, s3;

   // The following would have cause an error because stacks with
   // different base containers are not equality comparable
   // stack <int, list<int> >  s3;

   s1.push( 1 );
   s2.push( 2 );
   s3.push( 1 );

   if ( s1 != s2 )
      cout << "The stacks s1 and s2 are not equal." << endl;
   else
      cout << "The stacks s1 and s2 are equal." << endl;

   if ( s1 != s3 )
      cout << "The stacks s1 and s3 are not equal." << endl;
   else
      cout << "The stacks s1 and s3 are equal." << endl;
}
```

```Output
The stacks s1 and s2 are not equal.
The stacks s1 and s3 are equal.
```

## <a name="operatorlt"></a><a name="op_lt"></a>operador&lt;

Testa se o objeto stack do lado esquerdo do operador é menor que o objeto stack do lado direito.

```cpp
bool operator<(const stack <Type, Container>& left, const stack <Type, Container>& right);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Um objeto do tipo `stack`.

*Certo*\
Um objeto do tipo `stack`.

### <a name="return-value"></a>Valor retornado

**`true`** se a pilha no lado esquerdo do operador for menor que e diferente da pilha no lado direito do operador; caso contrário **`false`** .

### <a name="remarks"></a>Comentários

A comparação entre os objetos stack baseia-se em uma comparação par de seus elementos. A relação menor que entre dois objetos stack é baseada em uma comparação do primeiro par de elementos desiguais.

### <a name="example"></a>Exemplo

```cpp
// stack_op_lt.cpp
// compile with: /EHsc
#include <stack>
#include <list>
#include <iostream>

int main( )
{
   using namespace std;

   // Declares stacks with list base container
   stack <int, list<int> > s1, s2, s3;

   s1.push( 2 );
   s1.push( 4 );
   s1.push( 6 );
   s1.push( 8 );
   s2.push( 5 );
   s2.push( 10 );
   s3.push( 2 );
   s3.push( 4 );
   s3.push( 6 );
   s3.push( 8 );

   if ( s1 >= s2 )
      cout << "The stack s1 is greater than or equal to "
           << "the stack s2." << endl;
   else
      cout << "The stack s1 is less than "
           << "the stack s2." << endl;

   if ( s1>= s3 )
      cout << "The stack s1 is greater than or equal to "
           << "the stack s3." << endl;
   else
      cout << "The stack s1 is less than "
           << "the stack s3." << endl;

   // to print out the stack s1 ( by unstacking the elements):
   stack <int>::size_type i_size_s1 = s1.size( );
   cout << "The stack s1 from the top down is: ( ";
   unsigned int i;
   for ( i = 1 ; i <= i_size_s1 ; i++ )
   {
      cout << s1.top( ) << " ";
      s1.pop( );
   }
   cout << ")." << endl;
}
```

```Output
The stack s1 is less than the stack s2.
The stack s1 is greater than or equal to the stack s3.
The stack s1 from the top down is: ( 8 6 4 2 ).
```

## <a name="operatorlt"></a><a name="op_lt_eq"></a>operador&lt;=

Testa se o objeto stack do lado esquerdo do operador é menor ou igual ao objeto stack do lado direito.

```cpp
bool operator<=(const stack <Type, Container>& left, const stack <Type, Container>& right);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Um objeto do tipo `stack`.

*Certo*\
Um objeto do tipo `stack`.

### <a name="return-value"></a>Valor retornado

**`true`** se a pilha no lado esquerdo do operador for menor ou igual à pilha no lado direito do operador; caso contrário **`false`** .

### <a name="remarks"></a>Comentários

A comparação entre os objetos stack baseia-se em uma comparação par de seus elementos. A relação menor que ou igual a entre dois objetos stack é baseada em uma comparação entre o primeiro par de elementos desiguais.

### <a name="example"></a>Exemplo

```cpp
// stack_op_le.cpp
// compile with: /EHsc
#include <stack>
#include <iostream>

int main( )
{
   using namespace std;

   // Declares stacks with default deque base container
   stack <int> s1, s2, s3;

   s1.push( 5 );
   s1.push( 10 );
   s2.push( 1 );
   s2.push( 2 );
   s3.push( 5 );
   s3.push( 10 );

   if ( s1 <= s2 )
      cout << "The stack s1 is less than or equal to "
           << "the stack s2." << endl;
   else
      cout << "The stack s1 is greater than "
           << "the stack s2." << endl;

   if ( s1 <= s3 )
      cout << "The stack s1 is less than or equal to "
           << "the stack s3." << endl;
   else
      cout << "The stack s1 is greater than "
           << "the stack s3." << endl;
}
```

```Output
The stack s1 is greater than the stack s2.
The stack s1 is less than or equal to the stack s3.
```

## <a name="operator"></a><a name="op_eq_eq"></a>operador = =

Testa se o objeto stack do lado esquerdo do operador é igual ao objeto stack do lado direito.

```cpp
bool operator==(const stack <Type, Container>& left, const stack <Type, Container>& right);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Um objeto do tipo `stack`.

*Certo*\
Um objeto do tipo `stack`.

### <a name="return-value"></a>Valor retornado

**`true`** Se as pilhas ou pilhas forem iguais; **`false`** se pilhas ou pilhas não forem iguais.

### <a name="remarks"></a>Comentários

A comparação entre os objetos stack baseia-se em uma comparação par de seus elementos. Duas stacks serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

### <a name="example"></a>Exemplo

```cpp
// stack_op_eq.cpp
// compile with: /EHsc
#include <stack>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;

   // Declares stacks with vector base containers
   stack <int, vector<int> > s1, s2, s3;

   // The following would have cause an error because stacks with
   // different base containers are not equality comparable
   // stack <int, list<int> > s3;

   s1.push( 1 );
   s2.push( 2 );
   s3.push( 1 );

   if ( s1 == s2 )
      cout << "The stacks s1 and s2 are equal." << endl;
   else
      cout << "The stacks s1 and s2 are not equal." << endl;

   if ( s1 == s3 )
      cout << "The stacks s1 and s3 are equal." << endl;
   else
      cout << "The stacks s1 and s3 are not equal." << endl;
}
```

```Output
The stacks s1 and s2 are not equal.
The stacks s1 and s3 are equal.
```

## <a name="operatorgt"></a><a name="op_gt"></a>operador&gt;

Testa se o objeto stack do lado esquerdo do operador é maior que o objeto stack do lado direito.

```cpp
bool operator>(const stack <Type, Container>& left, const stack <Type, Container>& right);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Um objeto do tipo `stack`.

*Certo*\
Um objeto do tipo `stack`.

### <a name="return-value"></a>Valor retornado

**`true`** se a pilha no lado esquerdo do operador for maior que e diferente da pilha no lado direito do operador; caso contrário **`false`** .

### <a name="remarks"></a>Comentários

A comparação entre os objetos stack baseia-se em uma comparação par de seus elementos. A relação maior que entre dois objetos stack é baseada em uma comparação entre o primeiro par de elementos desiguais.

### <a name="example"></a>Exemplo

```cpp
// stack_op_gt.cpp
// compile with: /EHsc
#include <stack>
#include <list>
#include <iostream>

int main( )
{
   using namespace std;

   // Declares stacks with list base container
   stack <int, list<int> > s1, s2, s3;

   s1.push( 1 );
   s1.push( 2 );
   s1.push( 3 );
   s2.push( 5 );
   s2.push( 10 );
   s3.push( 1 );
   s3.push( 2 );

   if ( s1 > s2 )
      cout << "The stack s1 is greater than "
           << "the stack s2." << endl;
   else
      cout << "The stack s1 is not greater than "
           << "the stack s2." << endl;

   if ( s1> s3 )
      cout << "The stack s1 is greater than "
           << "the stack s3." << endl;
   else
      cout << "The stack s1 is not greater than "
           << "the stack s3." << endl;
}
```

```Output
The stack s1 is not greater than the stack s2.
The stack s1 is greater than the stack s3.
```

## <a name="operatorgt"></a><a name="op_gt_eq"></a>operador&gt;=

Testa se o objeto stack do lado esquerdo do operador é maior ou igual ao objeto stack do lado direito.

```cpp
bool operator>=(const stack <Type, Container>& left, const stack <Type, Container>& right);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Um objeto do tipo `stack`.

*Certo*\
Um objeto do tipo `stack`.

### <a name="return-value"></a>Valor retornado

**`true`** se a pilha no lado esquerdo do operador for estritamente menor que a pilha no lado direito do operador; caso contrário **`false`** .

### <a name="remarks"></a>Comentários

A comparação entre os objetos stack baseia-se em uma comparação par de seus elementos. A relação maior que ou igual entre dois objetos stack é baseada em uma comparação entre o primeiro par de elementos diferentes.

### <a name="example"></a>Exemplo

```cpp
// stack_op_ge.cpp
// compile with: /EHsc
#include <stack>
#include <list>
#include <iostream>

int main( )
{
   using namespace std;

   // Declares stacks with list base container
   stack <int, list<int> > s1, s2, s3;

   s1.push( 1 );
   s1.push( 2 );
   s2.push( 5 );
   s2.push( 10 );
   s3.push( 1 );
   s3.push( 2 );

   if ( s1 >= s2 )
      cout << "The stack s1 is greater than or equal to "
           << "the stack s2." << endl;
   else
      cout << "The stack s1 is less than "
           << "the stack s2." << endl;

   if ( s1>= s3 )
      cout << "The stack s1 is greater than or equal to "
           << "the stack s3." << endl;
   else
      cout << "The stack s1 is less than "
           << "the stack s3." << endl;
}
```

```Output
The stack s1 is less than the stack s2.
The stack s1 is greater than or equal to the stack s3.
```
