---
title: Classe binder1st
ms.date: 11/04/2016
f1_keywords:
- xfunctional/std::binder1st
helpviewer_keywords:
- binder1st class
ms.assetid: 6b8ee343-c82f-48f8-867d-06f9d1d324c0
ms.openlocfilehash: a8e962e118d162e46e2edfca3ce11e7cbf322e10
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50439621"
---
# <a name="binder1st-class"></a>Classe binder1st

Uma classe de modelo que fornece um construtor que converte um objeto de função binária em um objeto de função unária, associando o primeiro argumento da função binária a um valor especificado.

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
        const Operation& Func,
        const typename Operation::first_argument_type& left);

    result_type operator()(const argument_type& right) const;
    result_type operator()(const argument_type& right) const;

protected:
    Operation op;
    typename Operation::first_argument_type value;
};
```

### <a name="parameters"></a>Parâmetros

*Func*<br/>
O objeto de função binária a ser convertido em um objeto de função unária.

*left*<br/>
O valor ao qual o primeiro argumento do objeto de função binária deve ser associado.

*right*<br/>
O valor do argumento que o objeto binário adaptado compara ao valor fixo do segundo argumento.

## <a name="return-value"></a>Valor de retorno

O objeto de função unária que resulta da associação o primeiro argumento do objeto de função binária ao valor *esquerdo*.

## <a name="remarks"></a>Comentários

A classe de modelo armazena uma cópia de um objeto de função binária *Func* na `op`e uma cópia de *esquerdo* em `value`. Define sua função membro `operator()` como **op**(**value**, `right`) de retorno.

Se *Func* é um objeto do tipo `Operation` e `c` é uma constante, então [bind1st](../standard-library/functional-functions.md#bind1st) ( `Func`, `c` ) é equivalente ao `binder1st` construtor de classe `binder1st` \< **Operação**> ( `Func`, `c` ) e mais conveniente.

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
/* Output:
The vector v1 = ( 0 5 10 15 20 25 )
The number of elements in v1 greater than 10 is: 3.
The number of elements in v1 less than 10 is: 2.
*/
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<functional>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
