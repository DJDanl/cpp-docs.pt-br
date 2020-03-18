---
title: Operadores &lt;functional&gt;
ms.date: 11/04/2016
f1_keywords:
- functional/std::operator!=
- functional/std::operator==
helpviewer_keywords:
- functional operators
ms.assetid: d4b3c760-f3e2-4b65-bdaa-d42e8dd6f5e1
ms.openlocfilehash: b396e5c692129821c0deb9aef9469a5c54e600b0
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79419052"
---
# <a name="ltfunctionalgt-operators"></a>Operadores &lt;functional&gt;

## <a name="op_eq_eq"></a>operador = =

Testa se o objeto que pode ser chamado está vazio.

```cpp
template <class Fty>
    bool operator==(const function<Fty>& f, null_ptr_type npc);

template <class Fty>
    bool operator==(null_ptr_type npc, const function<Fty>& f);
```

### <a name="parameters"></a>parâmetros

\ *Fty*
O tipo de função a ser encapsulada.

\ de *f*
O objeto de função

\ *NPC*
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

## <a name="op_neq"></a>operador! =

Testa se o objeto que pode ser chamado não está vazio.

```cpp
template <class Fty>
    bool operator!=(const function<Fty>& f, null_ptr_type npc);

template <class Fty>
    bool operator!=(null_ptr_type npc, const function<Fty>& f);
```

### <a name="parameters"></a>parâmetros

\ *Fty*
O tipo de função a ser encapsulada.

\ de *f*
O objeto de função

\ *NPC*
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
