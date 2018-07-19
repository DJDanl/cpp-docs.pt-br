---
title: Operadores &lt;queue&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- queue/std::operator!=
- queue/std::operator&gt;
- queue/std::operator&gt;=
- queue/std::operator&lt;
- queue/std::operator&lt;=
- queue/std::operator==
dev_langs:
- C++
ms.assetid: 7c435b48-175c-45b0-88eb-24561044019c
helpviewer_keywords:
- std::operator!= (queue)
- std::operator&gt; (queue)
- std::operator&gt;= (queue)
- std::operator&lt; (queue)
- std::operator&lt;= (queue)
- std::operator== (queue)
ms.openlocfilehash: 138eddc6704b5e12798ccceacc5b3f37b3df1d96
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38958286"
---
# <a name="ltqueuegt-operators"></a>Operadores &lt;queue&gt;

||||
|-|-|-|
|[operator!=](#op_neq)|[operator&gt;](#op_gt)|[operator&gt;=](#op_gt_eq)|
|[operator&lt;](#op_lt)|[operator&lt;=](#op_lt_eq)|[operator==](#op_eq_eq)|

## <a name="op_neq"></a>  operator!=

Testa se o objeto da fila do lado esquerdo do operador não é igual ao do lado direito.

```cpp
bool operator!=(const queue <Type, Container>& left, const queue <Type, Container>& right,);
```

### <a name="parameters"></a>Parâmetros

*à esquerda* um objeto do tipo `queue`.

*à direita* um objeto do tipo `queue`.

### <a name="return-value"></a>Valor de retorno

**true** se as filas não forem iguais; **false** se forem iguais.

### <a name="remarks"></a>Comentários

A comparação entre os objetos de fila baseia-se em uma comparação par de seus elementos. Duas filas serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

### <a name="example"></a>Exemplo

```cpp
// queue_op_ne.cpp
// compile with: /EHsc
#include <queue>
#include <list>
#include <iostream>

int main( )
{
   using namespace std;

   // Declares queues with list base containers
   queue <int, list<int> > q1, q2, q3;

   // The following line would have caused an error because vector
   // does not support pop_front( ) and so cannot be adapted
   // by queue as a base container
   // queue <int, vector<int> > q1, q2, q3;

   q1.push( 1 );
   q2.push( 1 );
   q2.push( 2 );
   q3.push( 1 );

   if ( q1 != q2 )
      cout << "The queues q1 and q2 are not equal." << endl;
   else
      cout << "The queues q1 and q2 are equal." << endl;

   if ( q1 != q3 )
      cout << "The queues q1 and q3 are not equal." << endl;
   else
      cout << "The queues q1 and q3 are equal." << endl;
}
```

```Output
The queues q1 and q2 are not equal.
The queues q1 and q3 are equal.
```

## <a name="op_lt"></a>  operator&lt;

Testa se o objeto da fila do lado esquerdo do operador é menor que o do lado direito.

```cpp
bool operator<(const queue <Type, Container>& left, const queue <Type, Container>& right,);
```

### <a name="parameters"></a>Parâmetros

*à esquerda* um objeto do tipo `queue`.

*à direita* um objeto do tipo `queue`.

### <a name="return-value"></a>Valor de retorno

**true** se a fila do lado esquerdo do operador for menor ou não for igual a do lado direito do operador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

A comparação entre os objetos de fila baseia-se em uma comparação par de seus elementos. A relação menor que entre dois objetos de fila é baseada em uma comparação do primeiro par de elementos desiguais.

### <a name="example"></a>Exemplo

```cpp
// queue_op_lt.cpp
// compile with: /EHsc
#include <queue>
#include <iostream>

int main( )
{
   using namespace std;

   // Declares queues with default deque base container
   queue <int> q1, q2, q3;

   q1.push( 1 );
   q1.push( 2 );
   q2.push( 5 );
   q2.push( 10 );
   q3.push( 1 );
   q3.push( 2 );

   if ( q1 < q2 )
      cout << "The queue q1 is less than the queue q2." << endl;
   else
      cout << "The queue q1 is not less than the queue q2." << endl;

   if ( q1 < q3 )
      cout << "The queue q1 is less than the queue q3." << endl;
   else
      cout << "The queue q1 is not less than the queue q3." << endl;
}
```

```Output
The queue q1 is less than the queue q2.
The queue q1 is not less than the queue q3.
```

## <a name="op_lt_eq"></a>  operator&lt;=

Testa se o objeto da fila do lado esquerdo do operador é menor ou igual ao do lado direito.

```cpp
bool operator<=(const queue <Type, Container>& left, const queue <Type, Container>& right,);
```

### <a name="parameters"></a>Parâmetros

*à esquerda* um objeto do tipo `queue`.

*à direita* um objeto do tipo `queue`.

### <a name="return-value"></a>Valor de retorno

**verdadeiro**, se a fila no lado esquerdo do operador for estritamente menor que o aquela à direita do operador; caso contrário, **falso**.

### <a name="remarks"></a>Comentários

A comparação entre os objetos de fila baseia-se em uma comparação par de seus elementos. A relação menor ou igual a entre dois objetos de fila é baseado em uma comparação entre o primeiro par de elementos desiguais.

### <a name="example"></a>Exemplo

```cpp
// queue_op_le.cpp
// compile with: /EHsc
#include <queue>
#include <iostream>

int main( )
{
   using namespace std;
   queue <int> q1, q2, q3;

   q1.push( 5 );
   q1.push( 10 );
   q2.push( 1 );
   q2.push( 2 );
   q3.push( 5 );
   q3.push( 10 );

   if ( q1 <= q2 )
      cout << "The queue q1 is less than or equal to "
           << "the queue q2." << endl;
   else
      cout << "The queue q1 is greater than "
           << "the queue q2." << endl;

   if ( q1 <= q3 )
      cout << "The queue q1 is less than or equal to "
           << "the queue q3." << endl;
   else
      cout << "The queue q1 is greater than "
           << "the queue q3." << endl;
}
```

```Output
The queue q1 is greater than the queue q2.
The queue q1 is less than or equal to the queue q3.
```

## <a name="op_eq_eq"></a>  operator==

Testa se o objeto da fila do lado esquerdo do operador é igual ao do lado direito.

```cpp
bool operator==(const queue <Type, Container>& left, const queue <Type, Container>& right,);
```

### <a name="parameters"></a>Parâmetros

*à esquerda* um objeto do tipo `queue`.

*à direita* um objeto do tipo `queue`.

### <a name="return-value"></a>Valor de retorno

**true** se as filas não forem iguais; **false** se forem iguais.

### <a name="remarks"></a>Comentários

A comparação entre os objetos de fila baseia-se em uma comparação par de seus elementos. Duas filas serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

### <a name="example"></a>Exemplo

```cpp
// queue_op_eq.cpp
// compile with: /EHsc
#include <queue>
#include <list>
#include <iostream>

int main( )
{
   using namespace std;

   // Declares queues with list base containers
   queue <int, list<int> > q1, q2, q3;

   // The following line would have caused an error because vector
   // does not support pop_front( ) and so cannot be adapted
   // by queue as a base container
   // queue <int, vector<int> > q1, q2, q3;

   q1.push( 1 );
   q2.push( 2 );
   q3.push( 1 );

   if ( q1 != q2 )
      cout << "The queues q1 and q2 are not equal." << endl;
   else
      cout << "The queues q1 and q2 are equal." << endl;

   if ( q1 != q3 )
      cout << "The queues q1 and q3 are not equal." << endl;
   else
      cout << "The queues q1 and q3 are equal." << endl;
}
```

```Output
The queues q1 and q2 are not equal.
The queues q1 and q3 are equal.
```

## <a name="op_gt"></a>  operator&gt;

Testa se o objeto da fila do lado esquerdo do operador é maior que o do lado direito.

```cpp
bool operator>(const queue <Type, Container>& left, const queue <Type, Container>& right,);
```

### <a name="parameters"></a>Parâmetros

*à esquerda* um objeto do tipo `queue`.

*à direita* um objeto do tipo `queue`.

### <a name="return-value"></a>Valor de retorno

**verdadeiro**, se a fila no lado esquerdo do operador for estritamente menor que o aquela à direita do operador; caso contrário, **falso**.

### <a name="remarks"></a>Comentários

A comparação entre os objetos de fila baseia-se em uma comparação par de seus elementos. A relação maior que entre dois objetos de fila é baseada em uma comparação entre o primeiro par de elementos desiguais.

### <a name="example"></a>Exemplo

```cpp
// queue_op_gt.cpp
// compile with: /EHsc
#include <queue>
#include <iostream>

int main( )
{
   using namespace std;
   queue <int> q1, q2, q3;

   q1.push( 1 );
   q1.push( 2 );
   q1.push( 3 );
   q2.push( 5 );
   q2.push( 10 );
   q3.push( 1 );
   q3.push( 2 );

   if ( q1 > q2 )
      cout << "The queue q1 is greater than "
           << "the queue q2." << endl;
   else
      cout << "The queue q1 is not greater than "
           << "the queue q2." << endl;

   if ( q1> q3 )
      cout << "The queue q1 is greater than "
           << "the queue q3." << endl;
   else
      cout << "The queue q1 is not greater than "
           << "the queue q3." << endl;
}
```

```Output
The queue q1 is not greater than the queue q2.
The queue q1 is greater than the queue q3.
```

## <a name="op_gt_eq"></a>  operator&gt;=

Testa se o objeto de fila do lado esquerdo do operador é maior ou igual ao do lado direito.

```cpp
bool operator>=(const queue <Type, Container>& left, const queue <Type, Container>& right,);
```

### <a name="parameters"></a>Parâmetros

*à esquerda* um objeto do tipo `queue`.

*à direita* um objeto do tipo `queue`.

### <a name="return-value"></a>Valor de retorno

**verdadeiro**, se a fila no lado esquerdo do operador for estritamente menor que o aquela à direita do operador; caso contrário, **falso**.

### <a name="remarks"></a>Comentários

A comparação entre os objetos de fila baseia-se em uma comparação par de seus elementos. Duas filas serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

### <a name="example"></a>Exemplo

```cpp
// queue_op_ge.cpp
// compile with: /EHsc
#include <queue>
#include <iostream>

int main( )
{
   using namespace std;
   queue <int> q1, q2, q3;

   q1.push( 1 );
   q1.push( 2 );
   q2.push( 5 );
   q2.push( 10 );
   q3.push( 1 );
   q3.push( 2 );

   if ( q1 >= q2 )
      cout << "The queue q1 is greater than or equal to "
           << "the queue q2." << endl;
   else
      cout << "The queue q1 is less than "
           << "the queue q2." << endl;

   if ( q1>= q3 )
      cout << "The queue q1 is greater than or equal to "
           << "the queue q3." << endl;
   else
      cout << "The queue q1 is less than "
           << "the queue q3." << endl;
}
```

```Output
The queue q1 is less than the queue q2.
The queue q1 is greater than or equal to the queue q3.
```

## <a name="see-also"></a>Consulte também

[\<queue>](../standard-library/queue.md)<br/>
