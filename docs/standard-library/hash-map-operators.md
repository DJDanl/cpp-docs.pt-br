---
title: Operadores &lt;hash_map&gt;
ms.date: 11/04/2016
f1_keywords:
- hash_map/std::operator!=
- hash_map/std::operator==
ms.assetid: 24b9bb9e-e983-4060-bce5-2c7c8161ee61
ms.openlocfilehash: 50a6c2784b4c861f7cf3bbb4d1e1c8ebd0eea72d
ms.sourcegitcommit: eff68e4e82be292a5664616b16a526df3e9d1cda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80150739"
---
# <a name="lthash_mapgt-operators"></a>Operadores &lt;hash_map&gt;

|||
|-|-|
|[operator!=](#op_neq)|[operator!= (multimap)](#op_neq_mm)|
|[operator==](#op_eq_eq)|[operator== (multimapa)](#op_eq_eq_mm)|

## <a name="operator"></a><a name="op_neq"></a>  operator!=

> [!NOTE]
> {1&gt;Esta API está obsoleta.&lt;1} A alternativa é a [Classe unordered_map](unordered-map-class.md).

Testa se o objeto hash_map no lado esquerdo do operador não é igual ao objeto hash_map no lado direito.

```cpp
bool operator!=(const hash_map <Key, Type, Traits, Allocator>& left, const hash_map <Key, Type, Traits, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

\ *à esquerda*
Um objeto do tipo `hash_map`.

\ *à direita*
Um objeto do tipo `hash_map`.

### <a name="return-value"></a>Valor retornado

**true** se os hash_maps não forem iguais; **false** se os hash_maps forem iguais.

### <a name="remarks"></a>Comentários

A comparação entre objetos hash_map baseia-se em uma comparação de paridade de seus elementos. Dois hash_maps serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

Os membros do [< hash_map >](hash-map.md) e [< hash_set](hash-set.md) > arquivos de cabeçalho no [namespace stdext](stdext-namespace.md).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// hash_map_op_ne.cpp
// compile with: /EHsc
#include <hash_map>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_map <int, int> hm1, hm2, hm3;
   int i;
   typedef pair <int, int> Int_Pair;

   for ( i = 0 ; i < 3 ; i++ )
   {
      hm1.insert ( Int_Pair ( i, i ) );
      hm2.insert ( Int_Pair ( i, i * i ) );
      hm3.insert ( Int_Pair ( i, i ) );
   }

   if ( hm1 != hm2 )
      cout << "The hash_maps hm1 and hm2 are not equal." << endl;
   else
      cout << "The hash_maps hm1 and hm2 are equal." << endl;

   if ( hm1 != hm3 )
      cout << "The hash_maps hm1 and hm3 are not equal." << endl;
   else
      cout << "The hash_maps hm1 and hm3 are equal." << endl;
}
```

```Output
The hash_maps hm1 and hm2 are not equal.
The hash_maps hm1 and hm3 are equal.
```

## <a name="operator"></a><a name="op_eq_eq"></a>  operator==

> [!NOTE]
> {1&gt;Esta API está obsoleta.&lt;1} A alternativa é a [Classe unordered_map](unordered-map-class.md).

Testa se o objeto hash_map no lado esquerdo do operador é igual ao objeto hash_map no lado direito.

```cpp
bool operator==(const hash_map <Key, Type, Traits, Allocator>& left, const hash_map <Key, Type, Traits, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

\ *à esquerda*
Um objeto do tipo `hash_map`.

\ *à direita*
Um objeto do tipo `hash_map`.

### <a name="return-value"></a>Valor retornado

**true** se o hash_map no lado esquerdo do operador for igual ao hash_map no lado direito do operador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

A comparação entre objetos hash_map baseia-se em uma comparação de paridade de seus elementos. Dois hash_maps serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// hash_map_op_eq.cpp
// compile with: /EHsc
#include <hash_map>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_map <int, int> hm1, hm2, hm3;
   int i;
   typedef pair <int, int> Int_Pair;

   for ( i = 0 ; i < 3 ; i++ )
   {
      hm1.insert ( Int_Pair ( i, i ) );
      hm2.insert ( Int_Pair ( i, i * i ) );
      hm3.insert ( Int_Pair ( i, i ) );
   }

   if ( hm1 == hm2 )
      cout << "The hash_maps hm1 and hm2 are equal." << endl;
   else
      cout << "The hash_maps hm1 and hm2 are not equal." << endl;

   if ( hm1 == hm3 )
      cout << "The hash_maps hm1 and hm3 are equal." << endl;
   else
      cout << "The hash_maps hm1 and hm3 are not equal." << endl;
}
```

```Output
The hash_maps hm1 and hm2 are not equal.
The hash_maps hm1 and hm3 are equal.
```

## <a name="operator-hash_multimap"></a><a name="op_neq_mm"></a>operador! = (hash_multimap)

> [!NOTE]
> {1&gt;Esta API está obsoleta.&lt;1} A alternativa é a [Classe unordered_multimap](unordered-multimap-class.md).

Testa se o objeto hash_multimap no lado esquerdo do operador não é igual ao objeto hash_multimap no lado direito.

```cpp
bool operator!=(const hash_multimap <Key, Type, Traits, Allocator>& left, const hash_multimap <Key, Type, Traits, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

\ *à esquerda*
Um objeto do tipo `hash_multimap`.

\ *à direita*
Um objeto do tipo `hash_multimap`.

### <a name="return-value"></a>Valor retornado

**true** se os hash_multimaps não forem iguais; **false** se os hash_multimaps forem iguais.

### <a name="remarks"></a>Comentários

A comparação entre os objetos hash_multimap baseia-se em uma comparação de paridade de seus elementos. Dois hash_multimaps serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// hash_multimap_op_ne.cpp
// compile with: /EHsc
#include <hash_map>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multimap <int, int> hm1, hm2, hm3;
   int i;
   typedef pair <int, int> Int_Pair;

   for ( i = 0 ; i < 3 ; i++ )
   {
      hm1.insert ( Int_Pair ( i, i ) );
      hm2.insert ( Int_Pair ( i, i * i ) );
      hm3.insert ( Int_Pair ( i, i ) );
   }

   if ( hm1 != hm2 )
      cout << "The hash_multimaps hm1 and hm2 are not equal." << endl;
   else
      cout << "The hash_multimaps hm1 and hm2 are equal." << endl;

   if ( hm1 != hm3 )
      cout << "The hash_multimaps hm1 and hm3 are not equal." << endl;
   else
      cout << "The hash_multimaps hm1 and hm3 are equal." << endl;
}
```

```Output
The hash_multimaps hm1 and hm2 are not equal.
The hash_multimaps hm1 and hm3 are equal.
```

## <a name="operator--hash_multimap"></a><a name="op_eq_eq_mm"></a>Operator = = (hash_multimap)

> [!NOTE]
> {1&gt;Esta API está obsoleta.&lt;1} A alternativa é a [Classe unordered_multimap](unordered-multimap-class.md).

Testa se o objeto hash_multimap no lado esquerdo do operador é igual ao objeto hash_multimap no lado direito.

```cpp
bool operator==(const hash_multimap <Key, Type, Traits, Allocator>& left, const hash_multimap <Key, Type, Traits, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

\ *à esquerda*
Um objeto do tipo `hash_multimap`.

\ *à direita*
Um objeto do tipo `hash_multimap`.

### <a name="return-value"></a>Valor retornado

**true** se o hash_multimap no lado esquerdo do operador for igual ao hash_multimap no lado direito do operador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

A comparação entre os objetos hash_multimap baseia-se em uma comparação de paridade de seus elementos. Dois hash_multimaps serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// hash_multimap_op_eq.cpp
// compile with: /EHsc
#include <hash_map>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multimap<int, int> hm1, hm2, hm3;
   int i;
   typedef pair<int, int> Int_Pair;

   for (i = 0; i < 3; i++)
   {
      hm1.insert(Int_Pair(i, i));
      hm2.insert(Int_Pair(i, i*i));
      hm3.insert(Int_Pair(i, i));
   }

   if ( hm1 == hm2 )
      cout << "The hash_multimaps hm1 and hm2 are equal." << endl;
   else
      cout << "The hash_multimaps hm1 and hm2 are not equal." << endl;

   if ( hm1 == hm3 )
      cout << "The hash_multimaps hm1 and hm3 are equal." << endl;
   else
      cout << "The hash_multimaps hm1 and hm3 are not equal." << endl;
}
```

```Output
The hash_multimaps hm1 and hm2 are not equal.
The hash_multimaps hm1 and hm3 are equal.
```

## <a name="see-also"></a>Consulte também

[<hash_map>](hash-map.md)
