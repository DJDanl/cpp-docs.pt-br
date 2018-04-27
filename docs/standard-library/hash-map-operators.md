---
title: Operadores &lt;hash_map&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- hash_map/std::operator!=
- hash_map/std::operator==
dev_langs:
- C++
ms.assetid: 24b9bb9e-e983-4060-bce5-2c7c8161ee61
caps.latest.revision: 13
manager: ghogen
ms.openlocfilehash: 0b4b2a2c98e47752dbfb30afb2a0de522bcbb9f7
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="lthashmapgt-operators"></a>Operadores &lt;hash_map&gt;

|||
|-|-|
|[operator!=](#op_neq)|[operator!= (multimap)](#op_neq_mm)|
|[operator==](#op_eq_eq)|[operator== (multimapa)](#op_eq_eq_mm)|

## <a name="op_neq"></a>  operator!=

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_map](unordered-map-class.md).

Testa se o objeto hash_map no lado esquerdo do operador não é igual ao objeto hash_map no lado direito.

```cpp
bool operator!=(const hash_map <Key, Type, Traits, Allocator>& left, const hash_map <Key, Type, Traits, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

`left` Um objeto do tipo `hash_map`.

`right` Um objeto do tipo `hash_map`.

### <a name="return-value"></a>Valor de retorno

**true** se os hash_maps não forem iguais; **false** se os hash_maps forem iguais.

### <a name="remarks"></a>Comentários

A comparação entre objetos hash_map baseia-se em uma comparação de paridade de seus elementos. Dois hash_maps serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

Membros de [< hash_map >](hash-map.md) e [< hash_set >](hash-set.md) arquivos de cabeçalho no [ stdext Namespace](stdext-namespace.md).

### <a name="example"></a>Exemplo

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

## <a name="op_eq_eq"></a>  operator==

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_map](unordered-map-class.md).

Testa se o objeto hash_map no lado esquerdo do operador é igual ao objeto hash_map no lado direito.

```cpp
bool operator==(const hash_map <Key, Type, Traits, Allocator>& left, const hash_map <Key, Type, Traits, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

`left` Um objeto do tipo `hash_map`.

`right` Um objeto do tipo `hash_map`.

### <a name="return-value"></a>Valor de retorno

**true** se o hash_map no lado esquerdo do operador for igual ao hash_map no lado direito do operador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

A comparação entre objetos hash_map baseia-se em uma comparação de paridade de seus elementos. Dois hash_maps serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

### <a name="example"></a>Exemplo

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

## <a name="op_neq_mm"></a>  operador! = (hash_multimap)

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](unordered-multimap-class.md).

Testa se o objeto hash_multimap no lado esquerdo do operador não é igual ao objeto hash_multimap no lado direito.

```cpp
bool operator!=(const hash_multimap <Key, Type, Traits, Allocator>& left, const hash_multimap <Key, Type, Traits, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

`left` Um objeto do tipo `hash_multimap`.

`right` Um objeto do tipo `hash_multimap`.

### <a name="return-value"></a>Valor de retorno

**true** se os hash_multimaps não forem iguais; **false** se os hash_multimaps forem iguais.

### <a name="remarks"></a>Comentários

A comparação entre os objetos hash_multimap baseia-se em uma comparação de paridade de seus elementos. Dois hash_multimaps serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

### <a name="example"></a>Exemplo

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

## <a name="op_eq_eq_mm"></a>  operador = = (hash_multimap)

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](unordered-multimap-class.md).

Testa se o objeto hash_multimap no lado esquerdo do operador é igual ao objeto hash_multimap no lado direito.

```cpp
bool operator==(const hash_multimap <Key, Type, Traits, Allocator>& left, const hash_multimap <Key, Type, Traits, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

`left` Um objeto do tipo `hash_multimap`.

`right` Um objeto do tipo `hash_multimap`.

### <a name="return-value"></a>Valor de retorno

**true** se o hash_multimap no lado esquerdo do operador for igual ao hash_multimap no lado direito do operador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

A comparação entre os objetos hash_multimap baseia-se em uma comparação de paridade de seus elementos. Dois hash_multimaps serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

### <a name="example"></a>Exemplo

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

[<hash_map>](hash-map.md)<br/>
