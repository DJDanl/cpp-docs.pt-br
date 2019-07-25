---
title: Struct iterator_traits
ms.date: 11/04/2016
f1_keywords:
- xutility/std::iterator_traits
helpviewer_keywords:
- iterator_traits struct
- iterator_traits class
ms.assetid: 8b92c2c5-f658-402f-8ca1-e7ae301b8514
ms.openlocfilehash: 9d2f9d79d200579f539f7d9edc49d4a907e6cdb2
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68455575"
---
# <a name="iteratortraits-struct"></a>Struct iterator_traits

Um struct auxiliar de modelo usado para especificar todas as definições de tipo crítico que um iterador deve ter.

## <a name="syntax"></a>Sintaxe

```cpp
struct iterator_traits {
   typedef typename Iterator::iterator_category iterator_category;
   typedef typename Iterator::value_type value_type;
   typedef typename Iterator::difference_type difference_type;
   typedef difference_type distance_type;
   typedef typename Iterator::pointer pointer;
   typedef typename Iterator::reference reference;
   };
```

## <a name="remarks"></a>Comentários

O struct de modelo define os tipos membro

- `iterator_category`: um sinônimo para `Iterator::iterator_category`.

- `value_type`: um sinônimo para `Iterator::value_type`.

- `difference_type`: um sinônimo para `Iterator::difference_type`.

- `distance_type`: um sinônimo para`Iterator::difference_type.`

- `pointer`: um sinônimo para `Iterator::pointer`.

- `reference`: um sinônimo para `Iterator::reference`.

As especializações parciais determinam os tipos críticos associados a um ponteiro de  <strong>\*</strong> objeto do tipo Type ou **const** <strong>\*</strong>.

Nesta implementação, também é possível usar várias funções de modelo que não usam especialização parcial:

```cpp
template <class Category, class Type, class Diff>
C _Iter_cat(const iterator<Category, Ty, Diff>&);

template <class Ty>
random_access_iterator_tag _Iter_cat(const Ty *);

template <class Category, class Ty, class Diff>
Ty *val_type(const iterator<Category, Ty, Diff>&);

template <class Ty>
Ty *val_type(const Ty *);

template <class Category, class Ty, class Diff>
Diff *_Dist_type(const iterator<Category, Ty, Diff>&);

template <class Ty>
ptrdiff_t *_Dist_type(const Ty *);
```

que determinam vários dos mesmos tipos mais indiretamente. Use essas funções como argumentos em uma chamada de função. Sua única finalidade é fornecer um parâmetro de classe de modelo útil para a função chamada.

## <a name="example"></a>Exemplo

```cpp
// iterator_traits.cpp
// compile with: /EHsc
#include <iostream>
#include <iterator>
#include <vector>
#include <list>

using namespace std;

template< class it >
void
function( it i1, it i2 )
{
   iterator_traits<it>::iterator_category cat;
   cout << typeid( cat ).name( ) << endl;
   while ( i1 != i2 )
   {
      iterator_traits<it>::value_type x;
      x = *i1;
      cout << x << " ";
      i1++;
   };
   cout << endl;
};

int main( )
{
   vector<char> vc( 10,'a' );
   list<int> li( 10 );
   function( vc.begin( ), vc.end( ) );
   function( li.begin( ), li.end( ) );
}
/* Output:
struct std::random_access_iterator_tag
a a a a a a a a a a
struct std::bidirectional_iterator_tag
0 0 0 0 0 0 0 0 0 0
*/
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<iterator>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[\<iterator>](../standard-library/iterator.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
