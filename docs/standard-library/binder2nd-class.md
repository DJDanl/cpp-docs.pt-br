---
title: Classe binder2nd
ms.date: 02/21/2019
f1_keywords:
- functional/std::binder2nd
helpviewer_keywords:
- binder2nd class
ms.assetid: b2a9c1d1-dfc4-4ca9-a10e-ae84e195a62d
ms.openlocfilehash: 8c1ed74da939c5f5cc83a2a109d32b43b5ac7f41
ms.sourcegitcommit: 4299caac2dc9e806c74ac833d856a3838b0f52a1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/28/2019
ms.locfileid: "57006481"
---
# <a name="binder2nd-class"></a>Classe binder2nd

Uma classe de modelo que fornece um construtor que converte um objeto de função binária em um objeto de função unária associando o segundo argumento da função binária a um valor especificado. Preterido no c++11, removido do c++17.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Operation>
class binder2nd
    : public unaryFunction <typename Operation::first_argument_type,
    typename Operation::result_type>
{
public:
    typedef typename Operation::argument_type argument_type;
    typedef typename Operation::result_type result_type;
    binder2nd(
        const Operation& Func,
        const typename Operation::second_argument_type& right);

    result_type operator()(const argument_type& left) const;
    result_type operator()(argument_type& left) const;

protected:
    Operation op;
    typename Operation::second_argument_type value;
};
```

### <a name="parameters"></a>Parâmetros

*Func*<br/>
O objeto de função binária a ser convertido em um objeto de função unária.

*right*<br/>
O valor ao qual o segundo argumento do objeto de função binária deve ser associado.

*left*<br/>
O valor do argumento que o objeto binário adaptado compara ao valor fixo do segundo argumento.

## <a name="return-value"></a>Valor de retorno

O objeto de função unária que resulta da associação do segundo argumento do objeto de função binária ao valor *certa*.

## <a name="remarks"></a>Comentários

A classe de modelo armazena uma cópia de um objeto de função binária _ *Func* na `op`e uma cópia de *direita* em `value`. Define sua função membro `operator()` como **op**( `left`, **value**) de retorno.

Se `Func` é um objeto do tipo `Operation` e c é uma constante, então [bind2nd](../standard-library/functional-functions.md#bind2nd) ( `Func`, `c` ) é equivalente ao `binder2nd` construtor da classe `binder2nd` \<  **Operação**> ( `Func`, `c` ) e mais conveniente.

## <a name="example"></a>Exemplo

```cpp
// functional_binder2nd.cpp
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
        binder2nd<greater<int> >(greater<int>(), 10));
    cout << "The number of elements in v1 greater than 10 is: "
         << result1 << "." << endl;

    // Compare using binder1st fixing 1st argument:
    // count the number of integers < 10 in the vector
    vector<int>::iterator::difference_type result2;
    result2 = count_if(v1.begin(), v1.end(),
        binder1st<greater<int> >(greater<int>(), 10));
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
