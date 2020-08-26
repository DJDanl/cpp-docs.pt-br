---
title: Operadores &lt;hash_set&gt;
ms.date: 03/27/2019
f1_keywords:
- hash_set/std::operator!=
- hash_set/std::operator==
ms.assetid: 403d8e4e-0b3f-43fb-bc5a-8100c4f331c5
ms.openlocfilehash: 04b662ea260ca650fc51b17c804594fe25434f61
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88845779"
---
# <a name="lthash_setgt-operators"></a>Operadores &lt;hash_set&gt;

[operador! =](#op_neq)\
[operador! = (hash_multiset)](#op_neq_hash_multiset)\
[operador = =](#op_eq_eq)\
[Operator = = (hash_multiset)](#op_eq_eq_hash_multiset)

## <a name="operator"></a><a name="op_neq"></a> operador! =

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).

Testa se o objeto hash_set no lado esquerdo do operador não é igual ao objeto hash_set no lado direito.

```cpp
bool operator!=(const hash_set <Key, Traits, Allocator>& left, const hash_set <Key, Traits, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Um objeto do tipo `hash_set`.

*Certo*\
Um objeto do tipo `hash_set`.

### <a name="return-value"></a>Valor Retornado

**`true`** Se os hash_sets não forem iguais; **`false`** se hash_sets forem iguais.

### <a name="remarks"></a>Comentários

A comparação entre os objetos hash_set é baseada em uma comparação de paridade de seus elementos. Dois hash_sets serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

Os membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set ](../standard-library/hash-set.md)>estão no [namespace stdext](../standard-library/stdext-namespace.md).

### <a name="example"></a>Exemplo

```cpp
// hash_set_op_ne.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_set <int> hs1, hs2, hs3;
   int i;

   for ( i = 0 ; i < 3 ; i++ )
   {
      hs1.insert ( i );
      hs2.insert ( i * i );
      hs3.insert ( i );
   }

   if ( hs1 != hs2 )
      cout << "The hash_sets hs1 and hs2 are not equal." << endl;
   else
      cout << "The hash_sets hs1 and hs2 are equal." << endl;

   if ( hs1 != hs3 )
      cout << "The hash_sets hs1 and hs3 are not equal." << endl;
   else
      cout << "The hash_sets hs1 and hs3 are equal." << endl;
}
```

```Output
The hash_sets hs1 and hs2 are not equal.
The hash_sets hs1 and hs3 are equal.
```

## <a name="operator"></a><a name="op_eq_eq"></a> operador = =

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).

Testa se o objeto hash_set no lado esquerdo do operador é igual ao objeto hash_set no lado direito.

```cpp
bool operator!==(const hash_set <Key, Traits, Allocator>& left, const hash_set <Key, Traits, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Um objeto do tipo `hash_set`.

*Certo*\
Um objeto do tipo `hash_set`.

### <a name="return-value"></a>Valor Retornado

**`true`** se a hash_set no lado esquerdo do operador for igual à hash_set no lado direito do operador; caso contrário **`false`** .

### <a name="remarks"></a>Comentários

A comparação entre objetos hash_set é baseada em uma comparação de paridade de seus elementos. Dois hash_sets serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

### <a name="example"></a>Exemplo

```cpp
// hash_set_op_eq.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_set <int> s1, s2, s3;
   int i;

   for ( i = 0 ; i < 3 ; i++ )
   {
      s1.insert ( i );
      s2.insert ( i * i );
      s3.insert ( i );
   }

   if ( s1 == s2 )
      cout << "The hash_sets s1 and s2 are equal." << endl;
   else
      cout << "The hash_sets s1 and s2 are not equal." << endl;

   if ( s1 == s3 )
      cout << "The hash_sets s1 and s3 are equal." << endl;
   else
      cout << "The hash_sets s1 and s3 are not equal." << endl;
}
```

```Output
The hash_sets s1 and s2 are not equal.
The hash_sets s1 and s3 are equal.
```

## <a name="operator-hash_multiset"></a><a name="op_neq_hash_multiset"></a> operador! = (hash_multiset)

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).

Testa se o objeto hash_multiset no lado esquerdo do operador não é igual ao objeto hash_multiset no lado direito.

```cpp
bool operator!=(const hash_multiset <Key, Traits, Allocator>& left, const hash_multiset <Key, Traits, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Um objeto do tipo `hash_multiset`.

*Certo*\
Um objeto do tipo `hash_multiset`.

### <a name="return-value"></a>Valor Retornado

**`true`** Se os hash_multisets não forem iguais; **`false`** se hash_multisets forem iguais.

### <a name="remarks"></a>Comentários

A comparação entre os objetos hash_multiset é baseada em uma comparação de paridade de seus elementos. Dois hash_multisets serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

### <a name="example"></a>Exemplo

```cpp
// hashset_op_ne.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multiset <int> hs1, hs2, hs3;
   int i;

   for ( i = 0 ; i < 3 ; i++ )
   {
      hs1.insert ( i );
      hs2.insert ( i * i );
      hs3.insert ( i );
   }

   if ( hs1 != hs2 )
      cout << "The hash_multisets hs1 and hs2 are not equal." << endl;
   else
      cout << "The hash_multisets hs1 and hs2 are equal." << endl;

   if ( hs1 != hs3 )
      cout << "The hash_multisets hs1 and hs3 are not equal." << endl;
   else
      cout << "The hash_multisets hs1 and hs3 are equal." << endl;
}
```

```Output
The hash_multisets hs1 and hs2 are not equal.
The hash_multisets hs1 and hs3 are equal.
```

## <a name="operator-hash_multiset"></a><a name="op_eq_eq_hash_multiset"></a> Operator = = (hash_multiset)

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).

Testa se o objeto hash_multiset no lado esquerdo do operador é igual ao objeto hash_multiset no lado direito.

```cpp
bool operator!==(const hash_multiset <Key, Traits, Allocator>& left, const hash_multiset <Key, Traits, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Um objeto do tipo `hash_multiset`.

*Certo*\
Um objeto do tipo `hash_multiset`.

### <a name="return-value"></a>Valor Retornado

**`true`** se a hash_multiset no lado esquerdo do operador for igual à hash_multiset no lado direito do operador; caso contrário **`false`** .

### <a name="remarks"></a>Comentários

A comparação entre os objetos hash_multiset é baseada em uma comparação de paridade de seus elementos. Dois hash_multisets serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_op_eq.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multiset <int> s1, s2, s3;
   int i;

   for ( i = 0 ; i < 3 ; i++ )
   {
      s1.insert ( i );
      s2.insert ( i * i );
      s3.insert ( i );
   }

   if ( s1 == s2 )
      cout << "The hash_multisets s1 and s2 are equal." << endl;
   else
      cout << "The hash_multisets s1 and s2 are not equal." << endl;

   if ( s1 == s3 )
      cout << "The hash_multisets s1 and s2 are equal." << endl;
   else
      cout << "The hash_multisets s1 and s2 are not equal." << endl;
}
```

```Output
The hash_multisets s1 and s2 are not equal.
The hash_multisets s1 and s2 are equal.
```

## <a name="see-also"></a>Confira também

[<hash_set>](../standard-library/hash-set.md)
