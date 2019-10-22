---
title: Classe binder1st
ms.date: 02/21/2019
f1_keywords:
- functional/std::binder1st
helpviewer_keywords:
- binder1st class
ms.assetid: 6b8ee343-c82f-48f8-867d-06f9d1d324c0
ms.openlocfilehash: 15b704134d47b7bf7d8857bf380c756b0b03a1b0
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72688383"
---
# <a name="binder1st-class"></a>Classe binder1st

Um modelo de classe que fornece um construtor que converte um objeto de função binária em um objeto de função unário associando o primeiro argumento da função Binary a um valor especificado. Preterido em C++ 11 em favor da [ligação](functional-functions.md#bind)e removido no c++ 17.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Operation>
class binder1st
    : public unaryFunction <typename Operation::second_argument_type,
                             typename Operation::result_type>
{
public:
    typedef typename Operation::argument_type argument_type;
    typedef typename Operation::result_type result_type;
    binder1st(
        const Operation& binary_fn,
        const typename Operation::first_argument_type& left);

    result_type operator()(const argument_type& right) const;
    result_type operator()(const argument_type& right) const;

protected:
    Operation op;
    typename Operation::first_argument_type value;
};
```

### <a name="parameters"></a>Parâmetros

\ *binary_fn*
O objeto de função binária a ser convertido em um objeto de função unária.

\ *à esquerda*
O valor ao qual o primeiro argumento do objeto de função binária deve ser associado.

\ *à direita*
O valor do argumento que o objeto binário adaptado compara ao valor fixo do segundo argumento.

## <a name="return-value"></a>Valor retornado

O objeto de função unário que resulta da associação do primeiro argumento do objeto de função binária ao valor *restante*.

## <a name="remarks"></a>Comentários

O modelo de classe armazena uma cópia de um objeto de função binária *binary_fn* em `op` e uma cópia da *esquerda* no `value`. Ele define sua função membro `operator()` como retorno `op(value, right)`.

Se *binary_fn* for um objeto do tipo `Operation` e `c` for uma constante, `bind1st(binary_fn, c)` será um equivalente mais conveniente a `binder1st<Operation>(binary_fn, c)`. Para obter mais informações, consulte [bind1st](../standard-library/functional-functions.md#bind1st).

## <a name="example"></a>Exemplo

```cpp
// functional_binder1st.cpp
// compile with: /EHsc
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    vector<int> v1;
    vector<int>::iterator Iter;

    int i;
    for (i = 0; i <= 5; i++)
    {
        v1.push_back(5 * i);
    }

    cout << "The vector v1 = ( ";
    for (Iter = v1.begin(); Iter != v1.end(); Iter++)
        cout << *Iter << " ";
    cout << ")" << endl;

    // Count the number of integers > 10 in the vector
    vector<int>::iterator::difference_type result1;
    result1 = count_if(v1.begin(), v1.end(),
        binder1st<less<int> >(less<int>(), 10));
    cout << "The number of elements in v1 greater than 10 is: "
         << result1 << "." << endl;

    // Compare use of binder2nd fixing 2nd argument:
    // count the number of integers < 10 in the vector
    vector<int>::iterator::difference_type result2;
    result2 = count_if(v1.begin(), v1.end(),
        binder2nd<less<int> >(less<int>(), 10));
    cout << "The number of elements in v1 less than 10 is: "
         << result2 << "." << endl;
}
```

```Output
The vector v1 = ( 0 5 10 15 20 25 )
The number of elements in v1 greater than 10 is: 3.
The number of elements in v1 less than 10 is: 2.
```
