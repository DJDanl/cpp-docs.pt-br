---
title: Struct random_access_iterator_tag
ms.date: 11/04/2016
f1_keywords:
- xutility/std::random_access_iterator_tag
helpviewer_keywords:
- random_access_iterator_tag class
- random_access_iterator_tag struct
ms.assetid: 59f5b741-c5b4-459c-ad0a-3b67cddeea23
ms.openlocfilehash: 81e958750ab13c12e92b61e6971c40f3362ba22d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50562793"
---
# <a name="randomaccessiteratortag-struct"></a>Struct random_access_iterator_tag

Uma classe que fornece um tipo de retorno para `iterator_category` função que representa um iterador de acesso aleatório.

## <a name="syntax"></a>Sintaxe

```cpp
struct random_access_iterator_tag    : public bidirectional_iterator_tag {};
```

## <a name="remarks"></a>Comentários

As classes de marca de categoria são usadas como marcas de compilação para seleção de algoritmos. A função de modelo precisa encontrar a categoria mais específica do argumento iterador para que ela possa usar o algoritmo mais eficiente em tempo de compilação. Para cada iterador do tipo `Iterator`, `iterator_traits`< `Iterator`> **::iterator_category** deve ser definido para ser a marca de categoria mais específica que descreve o comportamento do iterador.

O tipo é o mesmo que **iterador** \< **Iter**> **:: iterator_category** quando `Iter` descreve um objeto que pode servir como um iterador de acesso aleatório.

## <a name="example"></a>Exemplo

```cpp
// iterator_rait.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <iostream>
#include <list>

using namespace std;

int main( )
{
   vector<int> vi;
   vector<char> vc;
   list<char> lc;
   iterator_traits<vector<int>:: iterator>::iterator_category cati;
   iterator_traits<vector<char>:: iterator>::iterator_category catc;
   iterator_traits<list<char>:: iterator>::iterator_category catlc;

   // These are both random-access iterators
   cout << "The type of iterator for vector<int> is "
       << "identified by the tag:\n "
       << typeid ( cati ).name( ) << endl;
   cout << "The type of iterator for vector<char> is "
       << "identified by the tag:\n "
       << typeid ( catc ).name( ) << endl;
   if ( typeid ( cati ) == typeid( catc ) )
      cout << "The iterators are the same." << endl << endl;
   else
      cout << "The iterators are not the same." << endl << endl;

   // But the list iterator is bidirectinal, not random access
   cout << "The type of iterator for list<char> is "
       << "identified by the tag:\n "
       << typeid (catlc).name( ) << endl;

   // cout << ( typeid ( vi.begin( ) ) == typeid( vc.begin( ) ) ) << endl;
   if ( typeid ( vi.begin( ) ) == typeid( vc.begin( ) ) )
      cout << "The iterators are the same." << endl;
   else
      cout << "The iterators are not the same." << endl;
   // A random-access iterator is a bidirectional iterator.
   cout << ( void* ) dynamic_cast< iterator_traits<list<char>:: iterator>
          ::iterator_category* > ( &catc ) << endl;
}
```

## <a name="sample-output"></a>Saída de Exemplo

A saída a seguir destina-se ao x86.

```Output
The type of iterator for vector<int> is identified by the tag:
    struct std::random_access_iterator_tag
The type of iterator for vector<char> is identified by the tag:
    struct std::random_access_iterator_tag
The iterators are the same.

The type of iterator for list<char> is identified by the tag:
    struct std::bidirectional_iterator_tag
The iterators are not the same.
0012FF3B
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<iterator>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Struct bidirectional_iterator_tag](../standard-library/bidirectional-iterator-tag-struct.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
