---
title: Classe checked_array_iterator
ms.date: 03/27/2019
f1_keywords:
- iterator/checked_array_iterator
- iterator/stdext::checked_array_iterator::difference_type
- iterator/stdext::checked_array_iterator::pointer
- iterator/stdext::checked_array_iterator::reference
- iterator/stdext::checked_array_iterator::base
helpviewer_keywords:
- stdext::checked_array_iterator [C++], difference_type
- stdext::checked_array_iterator [C++], pointer
- stdext::checked_array_iterator [C++], reference
- stdext::checked_array_iterator [C++], base
ms.assetid: 7f07185e-d588-4ae3-9c4f-84ec4aa25a28
ms.openlocfilehash: 467a94212d7b1e9d28a3229660b8a8619993b201
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90684935"
---
# <a name="checked_array_iterator-class"></a>Classe checked_array_iterator

A classe `checked_array_iterator` permite que você transforme uma matriz ou um ponteiro em um iterador verificado. Use essa classe como um wrapper (usando a função [make_checked_array_iterator](../standard-library/iterator-functions.md#make_checked_array_iterator)) para matrizes ou ponteiros brutos como uma maneira direcionada de fornecer verificação e gerenciar avisos de ponteiros não verificados, em vez de silenciar esses avisos globalmente. Se necessário, você pode usar a versão não verificada da classe, [unchecked_array_iterator](../standard-library/unchecked-array-iterator-class.md).

> [!NOTE]
> Essa classe é uma extensão da Microsoft da Biblioteca Padrão C++. O código implementado usando essa função não é portátil para ambientes de criação do C++ Standard que não oferecem suporte a essa extensão da Microsoft. Para ver um exemplo que demonstra como escrever código que não exige uso dessa classe, veja o segundo exemplo abaixo.

## <a name="syntax"></a>Sintaxe

```cpp
template <class _Iterator>
class checked_array_iterator;
```

## <a name="remarks"></a>Comentários

Essa classe é definida no namespace [stdext](../standard-library/stdext-namespace.md).

Para obter mais informações e o código de exemplo sobre o recurso de iterador verificado, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

## <a name="examples"></a>Exemplos

O exemplo a seguir mostra como definir e usar um iterador de matriz verificado.

Se o destino não for grande o suficiente para armazenar todos os elementos que estão sendo copiados, como seria se você tivesse alterado a linha:

```cpp
copy(a, a + 5, checked_array_iterator<int*>(b, 5));
```

como

```cpp
copy(a, a + 5, checked_array_iterator<int*>(b, 4));
```

Ocorrerá um erro de runtime.

```cpp
// compile with: /EHsc /W4 /MTd
#include <algorithm>
#include <iostream>

using namespace std;
using namespace stdext;

int main() {
   int a[]={0, 1, 2, 3, 4};
   int b[5];
   copy(a, a + 5, checked_array_iterator<int*>(b, 5));

   cout << "(";
   for (int i = 0 ; i < 5 ; i++)
      cout << " " << b[i];
   cout << " )" << endl;

   // constructor example
   checked_array_iterator<int*> checked_out_iter(b, 5);
   copy(a, a + 5, checked_out_iter);

   cout << "(";
   for (int i = 0 ; i < 5 ; i++)
      cout << " " << b[i];
   cout << " )" << endl;
}
/* Output:
( 0 1 2 3 4 )
( 0 1 2 3 4 )
*/
```

Para evitar a necessidade da classe `checked_array_iterator` ao usar algoritmos da Biblioteca Padrão C++, pense em usar um `vector`, em vez de uma matriz dinamicamente alocada. O exemplo a seguir demonstra como fazer isso.

```cpp
// compile with: /EHsc /W4 /MTd

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::vector<int> v(10);
    int *arr = new int[10];
    for (int i = 0; i < 10; ++i)
    {
        v[i] = i;
        arr[i] = i;
    }

    // std::copy(v.begin(), v.end(), arr); will result in
    // warning C4996. To avoid this warning while using int *,
    // use the Microsoft extension checked_array_iterator.
    std::copy(v.begin(), v.end(),
              stdext::checked_array_iterator<int *>(arr, 10));

    // Instead of using stdext::checked_array_iterator and int *,
    // consider using std::vector to encapsulate the array. This will
    // result in no warnings, and the code will be portable.
    std::vector<int> arr2(10);    // Similar to int *arr = new int[10];
    std::copy(v.begin(), v.end(), arr2.begin());

    for (int j = 0; j < arr2.size(); ++j)
    {
        cout << " " << arr2[j];
    }
    cout << endl;

    return 0;
}
/* Output:
0 1 2 3 4 5 6 7 8 9
*/
```

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[checked_array_iterator](#checked_array_iterator)|Constrói um `checked_array_iterator` padrão ou um `checked_array_iterator` de um iterador subjacente.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[difference_type](#difference_type)|Um tipo que fornece a diferença entre dois `checked_array_iterator`s que se referem a elementos no mesmo contêiner.|
|[refere](#pointer)|Um tipo que fornece um ponteiro para um elemento tratado por um `checked_array_iterator`.|
|[reference](#reference)|Um tipo que fornece uma referência a um elemento tratado por um `checked_array_iterator`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[base](#base)|Recupera o iterador subjacente de seu `checked_array_iterator`.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operador = =](#op_eq_eq)|Testa a igualdade de dois `checked_array_iterator`s.|
|[operador! =](#op_neq)|Testa a desigualdade de dois `checked_array_iterator`s.|
|[<do operador ](#op_lt)|Testa se o `checked_array_iterator` à esquerda do operador é menor que o `checked_array_iterator` à direita.|
|[>do operador ](#op_gt)|Testa se o `checked_array_iterator` à esquerda do operador é maior que o `checked_array_iterator` à direita.|
|[<do operador =](#op_lt_eq)|Testa se o `checked_array_iterator` à esquerda do operador é menor ou igual ao `checked_array_iterator` à direita.|
|[>do operador =](#op_gt_eq)|Testa se o `checked_array_iterator` à esquerda do operador é maior ou igual ao `checked_array_iterator` à direita.|
|[operador](#op_star)|Retorna o elemento tratado por um `checked_array_iterator`.|
|[operador->](#op_arrow)|Retorna um ponteiro para o elemento tratado pelo `checked_array_iterator`.|
|[operador + +](#op_add_add)|Incrementa o `checked_array_iterator` até o próximo elemento.|
|[operador--](#operator--)|Decrementa o `checked_array_iterator` para o elemento anterior.|
|[operador + =](#op_add_eq)|Adiciona um deslocamento especificado para um `checked_array_iterator`.|
|[operador +](#op_add)|Adiciona um deslocamento a um iterador e retorna o novo `checked_array_iterator` que trata o elemento inserido na nova posição de deslocamento.|
|[operador-=](#operator-_eq)|Decrementa um deslocamento especificado de um `checked_array_iterator`.|
|[operador](#operator-)|Decrementa um deslocamento de um iterador e retorna o novo `checked_array_iterator` que trata o elemento inserido na nova posição de deslocamento.|
|[operator&#91;&#93;](#op_at)|Retorna uma referência a um deslocamento do elemento tratado por um `checked_array_iterator` por um número especificado de posições.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<iterator>

**Namespace:** stdext

## <a name="checked_array_iteratorbase"></a><a name="base"></a> checked_array_iterator:: base

Recupera o iterador subjacente de seu `checked_array_iterator`.

```cpp
_Iterator base() const;
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

### <a name="example"></a>Exemplo

```cpp
// checked_array_iterators_base.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <iostream>

int main() {
   using namespace std;

   int V1[10];

   for (int i = 0; i < 10 ; i++)
      V1[i] = i;

   int* bpos;

   stdext::checked_array_iterator<int*> rpos(V1, 10);
   rpos++;

   bpos = rpos.base ( );
   cout << "The iterator underlying rpos is bpos & it points to: "
        << *bpos << "." << endl;
}
/* Output:
The iterator underlying rpos is bpos & it points to: 1.
*/
```

## <a name="checked_array_iteratorchecked_array_iterator"></a><a name="checked_array_iterator"></a> checked_array_iterator:: checked_array_iterator

Constrói um `checked_array_iterator` padrão ou um `checked_array _iterator` de um iterador subjacente.

```cpp
checked_array_iterator();

checked_array_iterator(
    ITerator ptr,
    size_t size,
    size_t index = 0);
```

### <a name="parameters"></a>Parâmetros

*PTR*\
Um ponteiro para a matriz.

*tamanho*\
O tamanho da matriz.

*index*\
(Opcional) Um elemento na matriz para inicializar o iterador.  Por padrão, o iterador é inicializado para o primeiro elemento na matriz.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

### <a name="example"></a>Exemplo

```cpp
// checked_array_iterators_ctor.cpp
// compile with: /EHsc
#include <iterator>
#include <iostream>

using namespace std;
using namespace stdext;

int main() {
   int a[] = {0, 1, 2, 3, 4};
   int b[5];
   copy(a, a + 5, checked_array_iterator<int*>(b,5));

   for (int i = 0 ; i < 5 ; i++)
      cout << b[i] << " ";
   cout << endl;

   checked_array_iterator<int*> checked_output_iterator(b,5);
   copy (a, a + 5, checked_output_iterator);
   for (int i = 0 ; i < 5 ; i++)
      cout << b[i] << " ";
   cout << endl;

   checked_array_iterator<int*> checked_output_iterator2(b,5,3);
   cout << *checked_output_iterator2 << endl;
}
/* Output:
0 1 2 3 4
0 1 2 3 4
3
*/
```

## <a name="checked_array_iteratordifference_type"></a><a name="difference_type"></a> checked_array_iterator::d ifference_type

Um tipo que fornece a diferença entre dois `checked_array_iterator`s que se referem a elementos no mesmo contêiner.

```cpp
typedef typename iterator_traits<_Iterator>::difference_type difference_type;
```

### <a name="remarks"></a>Comentários

O tipo de diferença `checked_array_iterator` é o mesmo que o tipo de diferença do iterador.

Consulte [checked_array_iterator:: operator []](#op_at) para obter um exemplo de código.

Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

## <a name="checked_array_iteratoroperator"></a><a name="op_eq_eq"></a> checked_array_iterator:: Operator = =

Testa a igualdade de dois `checked_array_iterator`s.

```cpp
bool operator==(const checked_array_iterator<_Iterator>& right) const;
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O `checked_array_iterator` com relação ao qual verificar quanto à igualdade.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

### <a name="example"></a>Exemplo

```cpp
// checked_array_iterators_opeq.cpp
// compile with: /EHsc
#include <iterator>
#include <iostream>

using namespace std;
using namespace stdext;

int main() {
   int a[] = {0, 1, 2, 3, 4};
   int b[5];
   copy(a, a + 5, checked_array_iterator<int*>(b,5));
   copy(a, a + 5, checked_array_iterator<int*>(b,5));

   checked_array_iterator<int*> checked_output_iterator(b,5);
   checked_array_iterator<int*> checked_output_iterator2(b,5);

   if (checked_output_iterator2 == checked_output_iterator)
      cout << "checked_array_iterators are equal" << endl;
   else
      cout << "checked_array_iterators are not equal" << endl;

   copy (a, a + 5, checked_output_iterator);
   checked_output_iterator++;

   if (checked_output_iterator2 == checked_output_iterator)
      cout << "checked_array_iterators are equal" << endl;
   else
      cout << "checked_array_iterators are not equal" << endl;
}
/* Output:
checked_array_iterators are equal
checked_array_iterators are not equal
*/
```

## <a name="checked_array_iteratoroperator"></a><a name="op_neq"></a> checked_array_iterator:: Operator! =

Testa a desigualdade de dois `checked_array_iterator`s.

```cpp
bool operator!=(const checked_array_iterator<_Iterator>& right) const;
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O `checked_array_iterator` com relação ao qual verificar quanto à desigualdade.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

### <a name="example"></a>Exemplo

```cpp
// checked_array_iterators_opneq.cpp
// compile with: /EHsc
#include <iterator>
#include <iostream>

using namespace std;
using namespace stdext;

int main() {
   int a[] = {0, 1, 2, 3, 4};
   int b[5];
   copy(a, a + 5, checked_array_iterator<int*>(b,5));
   copy(a, a + 5, checked_array_iterator<int*>(b,5));

   checked_array_iterator<int*> checked_output_iterator(b,5);
   checked_array_iterator<int*> checked_output_iterator2(b,5);

   if (checked_output_iterator2 != checked_output_iterator)
      cout << "checked_array_iterators are not equal" << endl;
   else
      cout << "checked_array_iterators are equal" << endl;

   copy (a, a + 5, checked_output_iterator);
   checked_output_iterator++;

   if (checked_output_iterator2 != checked_output_iterator)
      cout << "checked_array_iterators are not equal" << endl;
   else
      cout << "checked_array_iterators are equal" << endl;
}
/* Output:
checked_array_iterators are equal
checked_array_iterators are not equal
*/
```

## <a name="checked_array_iteratoroperatorlt"></a><a name="op_lt"></a> operador checked_array_iterator::&lt;

Testa se o `checked_array_iterator` à esquerda do operador é menor que o `checked_array_iterator` à direita.

```cpp
bool operator<(const checked_array_iterator<_Iterator>& right) const;
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O `checked_array_iterator` com relação ao qual verificar quanto à desigualdade.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

### <a name="example"></a>Exemplo

```cpp
// checked_array_iterators_oplt.cpp
// compile with: /EHsc
#include <iterator>
#include <iostream>

using namespace std;
using namespace stdext;

int main() {
   int a[] = {0, 1, 2, 3, 4};
   int b[5];
   copy(a, a + 5, checked_array_iterator<int*>(b,5));
   copy(a, a + 5, checked_array_iterator<int*>(b,5));

   checked_array_iterator<int*> checked_output_iterator(b,5);
   checked_array_iterator<int*> checked_output_iterator2(b,5);

   if (checked_output_iterator2 < checked_output_iterator)
      cout << "checked_output_iterator2 is less than checked_output_iterator" << endl;
   else
      cout << "checked_output_iterator2 is not less than checked_output_iterator" << endl;

   copy (a, a + 5, checked_output_iterator);
   checked_output_iterator++;

   if (checked_output_iterator2 < checked_output_iterator)
      cout << "checked_output_iterator2 is less than checked_output_iterator" << endl;
   else
      cout << "checked_output_iterator2 is not less than checked_output_iterator" << endl;
}
/* Output:
checked_output_iterator2 is not less than checked_output_iterator
checked_output_iterator2 is less than checked_output_iterator
*/
```

## <a name="checked_array_iteratoroperatorgt"></a><a name="op_gt"></a> operador checked_array_iterator::&gt;

Testa se o `checked_array_iterator` à esquerda do operador é maior que o `checked_array_iterator` à direita.

```cpp
bool operator>(const checked_array_iterator<_Iterator>& right) const;
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O `checked_array_iterator` com o qual comparar.

### <a name="remarks"></a>Comentários

Consulte o [operador &lt; checked_array_iterator::](#op_lt) para obter um exemplo de código.

Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

## <a name="checked_array_iteratoroperatorlt"></a><a name="op_lt_eq"></a> operador checked_array_iterator::&lt;=

Testa se o `checked_array_iterator` à esquerda do operador é menor ou igual ao `checked_array_iterator` à direita.

```cpp
bool operator<=(const checked_array_iterator<_Iterator>& right) const;
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O `checked_array_iterator` com o qual comparar.

### <a name="remarks"></a>Comentários

Consulte o [operador &gt; = checked_array_iterator::](#op_gt_eq) para obter um exemplo de código.

Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

## <a name="checked_array_iteratoroperatorgt"></a><a name="op_gt_eq"></a> operador checked_array_iterator::&gt;=

Testa se o `checked_array_iterator` à esquerda do operador é maior ou igual ao `checked_array_iterator` à direita.

```cpp
bool operator>=(const checked_array_iterator<_Iterator>& right) const;
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O `checked_array_iterator` com o qual comparar.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

### <a name="example"></a>Exemplo

```cpp
// checked_array_iterators_opgteq.cpp
// compile with: /EHsc
#include <iterator>
#include <iostream>

using namespace std;
using namespace stdext;

int main() {
   int a[] = {0, 1, 2, 3, 4};
   int b[5];
   copy(a, a + 5, checked_array_iterator<int*>(b,5));
   copy(a, a + 5, checked_array_iterator<int*>(b,5));

   checked_array_iterator<int*> checked_output_iterator(b,5);
   checked_array_iterator<int*> checked_output_iterator2(b,5);

   if (checked_output_iterator2 >= checked_output_iterator)
      cout << "checked_output_iterator2 is greater than or equal to checked_output_iterator" << endl;
   else
      cout << "checked_output_iterator2 is less than checked_output_iterator" << endl;

   copy (a, a + 5, checked_output_iterator);
   checked_output_iterator++;

   if (checked_output_iterator2 >= checked_output_iterator)
      cout << "checked_output_iterator2 is greater than or equal to checked_output_iterator" << endl;
   else
      cout << "checked_output_iterator2 is less than checked_output_iterator" << endl;
}
/* Output:
checked_output_iterator2 is greater than or equal to checked_output_iterator
checked_output_iterator2 is less than checked_output_iterator
*/
```

## <a name="checked_array_iteratoroperator"></a><a name="op_star"></a> checked_array_iterator:: Operator *

Retorna o elemento tratado por um `checked_array_iterator`.

```cpp
reference operator*() const;
```

### <a name="return-value"></a>Valor Retornado

O valor do elemento abordado por `checked_array_iterator`.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

### <a name="example"></a>Exemplo

```cpp
// checked_array_iterator_pointer.cpp
// compile with: /EHsc
#include <iterator>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;
using namespace stdext;

int main() {
   int a[] = {0, 1, 2, 3, 4};
   int b[5];
   pair<int, int> c[1];
   copy(a, a + 5, checked_array_iterator<int*>(b,5));

   for (int i = 0 ; i < 5 ; i++)
      cout << b[i] << endl;

    c[0].first = 10;
    c[0].second = 20;

   checked_array_iterator<int*> checked_output_iterator(b,5);
   checked_array_iterator<int*>::pointer p = &(*checked_output_iterator);
   checked_array_iterator<pair<int, int>*> chk_c(c, 1);
   checked_array_iterator<pair<int, int>*>::pointer p_c = &(*chk_c);

   cout << "b[0] = " << *p << endl;
   cout << "c[0].first = " << p_c->first << endl;
}
/* Output:
0
1
2
3
4
b[0] = 0
c[0].first = 10
*/
```

## <a name="checked_array_iteratoroperator-gt"></a><a name="op_arrow"></a> operador checked_array_iterator::&gt;

Retorna um ponteiro para o elemento tratado pelo `checked_array_iterator`.

```cpp
pointer operator->() const;
```

### <a name="return-value"></a>Valor Retornado

Um ponteiro para o elemento tratado pelo `checked_array_iterator`.

### <a name="remarks"></a>Comentários

Consulte [checked_array_iterator::pointer](#pointer) para obter um exemplo de código.

Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

## <a name="checked_array_iteratoroperator"></a><a name="op_add_add"></a> checked_array_iterator:: operador + +

Incrementa o `checked_array_iterator` até o próximo elemento.

```cpp
checked_array_iterator& operator++();

checked_array_iterator<_Iterator> operator++(int);
```

### <a name="return-value"></a>Valor Retornado

O primeiro operador retorna o `checked_array_iterator` pré-incrementado e o segundo, o operador pós-incrementado, retorna uma cópia do `checked_array_iterator` incrementado.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

### <a name="example"></a>Exemplo

```cpp
// checked_array_iterators_op_plus_plus.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main() {
   using namespace stdext;
   using namespace std;
   int a[] = {6, 3, 77, 199, 222};
   int b[5];
   copy(a, a + 5, checked_array_iterator<int*>(b,5));

   checked_array_iterator<int*> checked_output_iterator(b,5);

   cout << *checked_output_iterator << endl;
   ++checked_output_iterator;
   cout << *checked_output_iterator << endl;
   checked_output_iterator++;
   cout << *checked_output_iterator << endl;
}
/* Output:
6
3
77
*/
```

## <a name="checked_array_iteratoroperator--"></a><a name="operator--"></a> checked_array_iterator:: Operator--

Decrementa o `checked_array_iterator` para o elemento anterior.

```cpp
checked_array_iterator<_Iterator>& operator--();

checked_array_iterator<_Iterator> operator--(int);
```

### <a name="return-value"></a>Valor Retornado

O primeiro operador retorna o `checked_array_iterator` pré-decrementado e o segundo, o operador pós-decrementado, retorna uma cópia do `checked_array_iterator` decrementado.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

### <a name="example"></a>Exemplo

```cpp
// checked_array_iterators_op_minus_minus.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main() {
   using namespace stdext;
   using namespace std;
   int a[] = {6, 3, 77, 199, 222};
   int b[5];
   copy(a, a + 5, checked_array_iterator<int*>(b,5));

   checked_array_iterator<int*> checked_output_iterator(b,5);

   cout << *checked_output_iterator << endl;
   checked_output_iterator++;
   cout << *checked_output_iterator << endl;
   checked_output_iterator--;
   cout << *checked_output_iterator << endl;
}
/* Output:
6
3
6
*/
```

## <a name="checked_array_iteratoroperator"></a><a name="op_add_eq"></a> checked_array_iterator:: Operator + =

Adiciona um deslocamento especificado para um `checked_array_iterator`.

```cpp
checked_array_iterator<_Iterator>& operator+=(difference_type _Off);
```

### <a name="parameters"></a>Parâmetros

*_Off*\
O deslocamento pelo qual incrementar o iterador.

### <a name="return-value"></a>Valor Retornado

Uma referência ao elemento tratado pelo `checked_array_iterator`.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

### <a name="example"></a>Exemplo

```cpp
// checked_array_iterators_op_plus_eq.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main() {
   using namespace stdext;
   using namespace std;
   int a[] = {6, 3, 77, 199, 222};
   int b[5];
   copy(a, a + 5, checked_array_iterator<int*>(b,5));

   checked_array_iterator<int*> checked_output_iterator(b,5);

   cout << *checked_output_iterator << endl;
   checked_output_iterator += 3;
   cout << *checked_output_iterator << endl;
}
/* Output:
6
199
*/
```

## <a name="checked_array_iteratoroperator"></a><a name="op_add"></a> checked_array_iterator:: Operator +

Adiciona um deslocamento a um iterador e retorna o novo `checked_array_iterator` que trata o elemento inserido na nova posição de deslocamento.

```cpp
checked_array_iterator<_Iterator> operator+(difference_type _Off) const;
```

### <a name="parameters"></a>Parâmetros

*_Off*\
O deslocamento a ser adicionado a `checked_array_iterator`.

### <a name="return-value"></a>Valor Retornado

Um `checked_array_iterator` que trata o elemento de deslocamento.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

### <a name="example"></a>Exemplo

```cpp
// checked_array_iterators_op_plus.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main() {
   using namespace stdext;
   using namespace std;
   int a[] = {6, 3, 77, 199, 222};
   int b[5];
   copy(a, a + 5, checked_array_iterator<int*>(b,5));

   checked_array_iterator<int*> checked_output_iterator(b,5);

   cout << *checked_output_iterator << endl;
   checked_output_iterator = checked_output_iterator + 3;
   cout << *checked_output_iterator << endl;
}
/* Output:
6
199
*/
```

## <a name="checked_array_iteratoroperator-"></a><a name="operator-_eq"></a> checked_array_iterator:: Operator-=

Decrementa um deslocamento especificado de um `checked_array_iterator`.

```cpp
checked_array_iterator<_Iterator>& operator-=(difference_type _Off);
```

### <a name="parameters"></a>Parâmetros

*_Off*\
O deslocamento pelo qual incrementar o iterador.

### <a name="return-value"></a>Valor Retornado

Uma referência ao elemento tratado pelo `checked_array_iterator`.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

### <a name="example"></a>Exemplo

```cpp
// checked_array_iterators_op_minus_eq.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main() {
   using namespace stdext;
   using namespace std;
   int a[] = {6, 3, 77, 199, 222};
   int b[5];
   copy(a, a + 5, checked_array_iterator<int*>(b,5));

   checked_array_iterator<int*> checked_output_iterator(b,5);

   checked_output_iterator += 3;
   cout << *checked_output_iterator << endl;
   checked_output_iterator -= 2;
   cout << *checked_output_iterator << endl;
}
/* Output:
199
3
*/
```

## <a name="checked_array_iteratoroperator-"></a><a name="operator-"></a> operador checked_array_iterator::

Decrementa um deslocamento de um iterador e retorna o novo `checked_array_iterator` que trata o elemento inserido na nova posição de deslocamento.

```cpp
checked_array_iterator<_Iterator> operator-(difference_type _Off) const;

difference_type operator-(const checked_array_iterator& right) const;
```

### <a name="parameters"></a>Parâmetros

*_Off*\
O deslocamento a ser decrementado do `checked_array_iterator`.

### <a name="return-value"></a>Valor Retornado

Um `checked_array_iterator` que trata o elemento de deslocamento.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

## <a name="checked_array_iteratoroperator"></a><a name="op_at"></a> checked_array_iterator:: operator []

Retorna uma referência a um deslocamento do elemento tratado por um `checked_array_iterator` por um número especificado de posições.

```cpp
reference operator[](difference_type _Off) const;
```

### <a name="parameters"></a>Parâmetros

*_Off*\
O deslocamento do endereço `checked_array_iterator`.

### <a name="return-value"></a>Valor Retornado

A referência ao deslocamento de elemento.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

### <a name="example"></a>Exemplo

```cpp
// checked_array_iterators_op_diff.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main() {
   using namespace std;
   int V1[10];

   for (int i = 0; i < 10 ; i++)
      V1[i] = i;

   // Declare a difference type for a parameter
   stdext::checked_array_iterator<int*>::difference_type diff = 2;

   stdext::checked_array_iterator<int*> VChkIter(V1, 10);

   stdext::checked_array_iterator<int*>::reference refrpos = VChkIter [diff];

   cout << refrpos + 1 << endl;
}
/* Output:
3
*/
```

## <a name="checked_array_iteratorpointer"></a><a name="pointer"></a> checked_array_iterator::p ointer

Um tipo que fornece um ponteiro para um elemento tratado por um `checked_array_iterator`.

```cpp
typedef typename iterator_traits<_Iterator>::pointer pointer;
```

### <a name="remarks"></a>Comentários

Consulte [checked_array_iterator:: Operator *](#op_star) para obter um exemplo de código.

Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

## <a name="checked_array_iteratorreference"></a><a name="reference"></a> checked_array_iterator:: referência

Um tipo que fornece uma referência a um elemento tratado por um `checked_array_iterator`.

```cpp
typedef typename iterator_traits<_Iterator>::reference reference;
```

### <a name="remarks"></a>Comentários

Consulte [checked_array_iterator:: operator []](#op_at) para obter um exemplo de código.

Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

## <a name="see-also"></a>Confira também

[\<iterator>](../standard-library/iterator.md)\
[Referência da biblioteca padrão do C++](../standard-library/cpp-standard-library-reference.md)
