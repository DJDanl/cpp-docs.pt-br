---
title: Operadores &lt;vector&gt;
ms.date: 11/04/2016
f1_keywords:
- vector/std::operator!=
- vector/std::operator&gt;
- vector/std::operator&gt;=
- vector/std::operator&lt;
- vector/std::operator&lt;=
- vector/std::operator==
ms.assetid: 1d14f312-6f59-4ec7-88ae-95f89a558823
helpviewer_keywords:
- std::operator!= (vector)
- std::operator&gt; (vector)
- std::operator&gt;= (vector)
- std::operator&lt; (vector)
- std::operator&lt;= (vector)
- std::operator== (vector)
ms.openlocfilehash: f6717add93c489f536bd0c0b0f82b74bbd915985
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79422370"
---
# <a name="ltvectorgt-operators"></a>Operadores &lt;vector&gt;

## <a name="op_neq"></a>operador! =

Testa se o objeto à esquerda do operador é diferente do objeto à direita.

```cpp
bool operator!=(const vector<Type, Allocator>& left, const vector<Type, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

\ *à esquerda*
Um objeto do tipo `vector`.

\ *à direita*
Um objeto do tipo `vector`.

### <a name="return-value"></a>Valor retornado

**true** se os vetores não forem iguais; **false** se os vetores forem iguais.

### <a name="remarks"></a>Comentários

Dois vetores serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

### <a name="example"></a>Exemplo

```cpp
// vector_op_ne.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;

   vector <int> v1, v2;
   v1.push_back( 1 );
     v2.push_back( 2 );

   if ( v1 != v2 )
      cout << "Vectors not equal." << endl;
   else
      cout << "Vectors equal." << endl;
}
```

```Output
Vectors not equal.
```

## <a name="op_lt">Operador </a>&lt;

Testa se o objeto à esquerda do operador é menor do que o objeto à direita.

```cpp
bool operator<(const vector<Type, Allocator>& left, const vector<Type, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

\ *à esquerda*
Um objeto do tipo `vector`.

\ *à direita*
Um objeto do tipo `vector`.

### <a name="return-value"></a>Valor retornado

**true**, se o vetor no lado esquerdo do operador for menor que o vetor à direita do operador; caso contrário, **false**.

### <a name="example"></a>Exemplo

```cpp
// vector_op_lt.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;

   vector <int> v1, v2;
   v1.push_back( 1 );
   v1.push_back( 2 );
   v1.push_back( 4 );

   v2.push_back( 1 );
   v2.push_back( 3 );

   if ( v1 < v2 )
      cout << "Vector v1 is less than vector v2." << endl;
   else
      cout << "Vector v1 is not less than vector v2." << endl;
}
```

```Output
Vector v1 is less than vector v2.
```

## <a name="op_lt_eq"></a>= de&lt;do operador

Testa se o objeto à esquerda do operador é menor que ou igual ao objeto à direita.

```cpp
bool operator<=(const vector<Type, Allocator>& left, const vector<Type, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

\ *à esquerda*
Um objeto do tipo `vector`.

\ *à direita*
Um objeto do tipo `vector`.

### <a name="return-value"></a>Valor retornado

**true** se o vetor à esquerda do operador for menor que ou igual ao vetor à direita do operador; caso contrário, **false**.

### <a name="example"></a>Exemplo

```cpp
// vector_op_le.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;

   vector <int> v1, v2;
   v1.push_back( 1 );
   v1.push_back( 2 );
   v1.push_back( 4 );

   v2.push_back( 1 );
   v2.push_back( 3 );

   if ( v1 <= v2 )
      cout << "Vector v1 is less than or equal to vector v2." << endl;
   else
      cout << "Vector v1 is greater than vector v2." << endl;
}
```

```Output
Vector v1 is less than or equal to vector v2.
```

## <a name="op_eq_eq"></a>operador = =

Testa se o objeto à esquerda do operador é igual ao objeto à direita.

```cpp
bool operator==(const vector<Type, Allocator>& left, const vector<Type, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

\ *à esquerda*
Um objeto do tipo `vector`.

\ *à direita*
Um objeto do tipo `vector`.

### <a name="return-value"></a>Valor retornado

**true** se o vetor à esquerda do operador for igual ao vetor à direita do operador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Dois vetores serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

### <a name="example"></a>Exemplo

```cpp
// vector_op_eq.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;

   vector <int> v1, v2;
   v1.push_back( 1 );
   v2.push_back( 1 );

   if ( v1 == v2 )
      cout << "Vectors equal." << endl;
   else
      cout << "Vectors not equal." << endl;
}
```

```Output
Vectors equal.
```

## <a name="op_gt">Operador </a>&gt;

Testa se o objeto à esquerda do operador é maior do que o objeto à direita.

```cpp
bool operator>(const vector<Type, Allocator>& left, const vector<Type, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

\ *à esquerda*
Um objeto do tipo `vector`.

\ *à direita*
Um objeto do tipo `vector`.

### <a name="return-value"></a>Valor retornado

**true** se o vetor à esquerda do operador for maior que o vetor à direita do operador; caso contrário, **false**.

### <a name="example"></a>Exemplo

```cpp
// vector_op_gt.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;

   vector <int> v1, v2;
   v1.push_back( 1 );
   v1.push_back( 3 );
   v1.push_back( 1 );

   v2.push_back( 1 );
   v2.push_back( 2 );
   v2.push_back( 2 );

   if ( v1 > v2 )
      cout << "Vector v1 is greater than vector v2." << endl;
   else
      cout << "Vector v1 is not greater than vector v2." << endl;
}
```

```Output
Vector v1 is greater than vector v2.
```

## <a name="op_gt_eq"></a>= de&gt;do operador

Testa se o objeto à esquerda do operador é maior que ou igual ao objeto à direita.

```cpp
bool operator>=(const vector<Type, Allocator>& left, const vector<Type, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

\ *à esquerda*
Um objeto do tipo `vector`.

\ *à direita*
Um objeto do tipo `vector`.

### <a name="return-value"></a>Valor retornado

**true** se o vetor à esquerda do operador for maior que ou igual ao vetor à direita do vetor; caso contrário, **false**.

### <a name="example"></a>Exemplo

```cpp
// vector_op_ge.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;

   vector <int> v1, v2;
   v1.push_back( 1 );
   v1.push_back( 3 );
   v1.push_back( 1 );

     v2.push_back( 1 );
   v2.push_back( 2 );
   v2.push_back( 2 );

   if ( v1 >= v2 )
      cout << "Vector v1 is greater than or equal to vector v2." << endl;
   else
      cout << "Vector v1 is less than vector v2." << endl;
}
```

```Output
Vector v1 is greater than or equal to vector v2.
```
