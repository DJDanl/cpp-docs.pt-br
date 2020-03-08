---
title: Operadores &lt;hash_set&gt;
ms.date: 03/27/2019
f1_keywords:
- hash_set/std::operator!=
- hash_set/std::operator==
ms.assetid: 403d8e4e-0b3f-43fb-bc5a-8100c4f331c5
ms.openlocfilehash: 3900e9c6e4fb7f5a163279165a51b440d138a8e5
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78883832"
---
# <a name="lthash_setgt-operators"></a>Operadores &lt;hash_set&gt;

||||
|-|-|-|
|[operator!=](#op_neq)|[operator!= (hash_multiset)](#op_neq_hash_multiset)|[operator==](#op_eq_eq)|
|[operator== (hash_multiset)](#op_eq_eq_hash_multiset)|

## <a name="op_neq"></a>  operator!=

> [!NOTE]
> {1&gt;Esta API está obsoleta.&lt;1} A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).

Testa se o objeto hash_set no lado esquerdo do operador não é igual ao objeto hash_set no lado direito.

```cpp
bool operator!=(const hash_set <Key, Traits, Allocator>& left, const hash_set <Key, Traits, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

\ *à esquerda*
Um objeto do tipo `hash_set`.

\ *à direita*
Um objeto do tipo `hash_set`.

### <a name="return-value"></a>Valor retornado

**true** se os hash_sets não forem iguais; **false** se os hash_sets forem iguais.

### <a name="remarks"></a>Comentários

A comparação entre os objetos hash_set é baseada em uma comparação de paridade de seus elementos. Dois hash_sets serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

Os membros dos arquivos de cabeçalho [< hash_map >](../standard-library/hash-map.md) e [< hash_set](../standard-library/hash-set.md) > estão no [namespace stdext](../standard-library/stdext-namespace.md).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

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

## <a name="op_eq_eq"></a>  operator==

> [!NOTE]
> {1&gt;Esta API está obsoleta.&lt;1} A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).

Testa se o objeto hash_set no lado esquerdo do operador é igual ao objeto hash_set no lado direito.

```cpp
bool operator!==(const hash_set <Key, Traits, Allocator>& left, const hash_set <Key, Traits, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

\ *à esquerda*
Um objeto do tipo `hash_set`.

\ *à direita*
Um objeto do tipo `hash_set`.

### <a name="return-value"></a>Valor retornado

**true** se o hash_set no lado esquerdo do operador for igual ao hash_set no lado direito do operador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

A comparação entre objetos hash_set é baseada em uma comparação de paridade de seus elementos. Dois hash_sets serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

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

## <a name="op_neq_hash_multiset"></a>  operator!= (hash_multiset)

> [!NOTE]
> {1&gt;Esta API está obsoleta.&lt;1} A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).

Testa se o objeto hash_multiset no lado esquerdo do operador não é igual ao objeto hash_multiset no lado direito.

```cpp
bool operator!=(const hash_multiset <Key, Traits, Allocator>& left, const hash_multiset <Key, Traits, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

\ *à esquerda*
Um objeto do tipo `hash_multiset`.

\ *à direita*
Um objeto do tipo `hash_multiset`.

### <a name="return-value"></a>Valor retornado

**true** se os hash_multisets não forem iguais; **false** se os hash_multisets forem iguais.

### <a name="remarks"></a>Comentários

A comparação entre os objetos hash_multiset é baseada em uma comparação de paridade de seus elementos. Dois hash_multisets serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

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

## <a name="op_eq_eq_hash_multiset"></a>  operator== (hash_multiset)

> [!NOTE]
> {1&gt;Esta API está obsoleta.&lt;1} A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).

Testa se o objeto hash_multiset no lado esquerdo do operador é igual ao objeto hash_multiset no lado direito.

```cpp
bool operator!==(const hash_multiset <Key, Traits, Allocator>& left, const hash_multiset <Key, Traits, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

\ *à esquerda*
Um objeto do tipo `hash_multiset`.

\ *à direita*
Um objeto do tipo `hash_multiset`.

### <a name="return-value"></a>Valor retornado

**true** se o hash_multiset no lado esquerdo do operador for igual ao hash_multiset no lado direito do operador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

A comparação entre os objetos hash_multiset é baseada em uma comparação de paridade de seus elementos. Dois hash_multisets serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

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

## <a name="see-also"></a>Consulte também

[<hash_set>](../standard-library/hash-set.md)
