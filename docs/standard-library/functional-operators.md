---
title: Operadores &lt;functional&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- functional/std::operator!=
- functional/std::operator==
dev_langs:
- C++
helpviewer_keywords:
- functional operators
ms.assetid: d4b3c760-f3e2-4b65-bdaa-d42e8dd6f5e1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dd9d4dfa7c10d19112cd8154ddcf3b7a70bf3034
ms.sourcegitcommit: 761c5f7c506915f5a62ef3847714f43e9b815352
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/07/2018
ms.locfileid: "44103886"
---
# <a name="ltfunctionalgt-operators"></a>Operadores &lt;functional&gt;

|||
|-|-|
|[operator!=](#op_neq)|[operator==](#op_eq_eq)|

## <a name="op_eq_eq"></a>  operator==

Testa se o objeto que pode ser chamado está vazio.

```cpp
template <class Fty>
bool operator==(const function<Fty>& f, null_ptr_type npc);

template <class Fty>
bool operator==(null_ptr_type npc, const function<Fty>& f);
```

### <a name="parameters"></a>Parâmetros

*Fty*<br/>
O tipo de função a ser encapsulada.

*f*<br/>
O objeto de função

*npc*<br/>
Um ponteiro nulo.

### <a name="remarks"></a>Comentários

Os operadores usam um argumento que é uma referência a um objeto `function` e um argumento que é uma constante de ponteiro nulo. Ambos retornam true somente se o objeto `function` estiver vazio.

### <a name="example"></a>Exemplo

```cpp
// std__functional__operator_eq.cpp
// compile with: /EHsc
#include <functional>
#include <iostream>

int neg(int val)
{
    return (-val);
}

int main()
{
    std::function<int(int)> fn0;
    std::cout << std::boolalpha << "empty == "
        << (fn0 == 0) << std::endl;

    std::function<int(int)> fn1(neg);
    std::cout << std::boolalpha << "empty == "
        << (fn1 == 0) << std::endl;

    return (0);
}

```

```Output
empty == true
empty == false
```

## <a name="op_neq"></a>  operator!=

Testa se o objeto que pode ser chamado não está vazio.

```cpp
template <class Fty>
bool operator!=(const function<Fty>& f, null_ptr_type npc);

template <class Fty>
bool operator!=(null_ptr_type npc, const function<Fty>& f);
```

### <a name="parameters"></a>Parâmetros

*Fty*<br/>
O tipo de função a ser encapsulada.

*f*<br/>
O objeto de função

*npc*<br/>
Um ponteiro nulo.

### <a name="remarks"></a>Comentários

Os operadores usam um argumento que é uma referência a um objeto `function` e um argumento que é uma constante de ponteiro nulo. Ambos retornam true somente se o objeto `function` não estiver vazio.

### <a name="example"></a>Exemplo

```cpp
// std__functional__operator_ne.cpp
// compile with: /EHsc
#include <functional>
#include <iostream>

int neg(int val)
    {
    return (-val);
    }

int main()
    {
    std::function<int (int)> fn0;
    std::cout << std::boolalpha << "not empty == "
        << (fn0 != 0) << std::endl;

    std::function<int (int)> fn1(neg);
    std::cout << std::boolalpha << "not empty == "
        << (fn1 != 0) << std::endl;

    return (0);
    }

```

```Output
not empty == false
not empty == true
```

## <a name="see-also"></a>Consulte também

[\<functional>](../standard-library/functional.md)<br/>
