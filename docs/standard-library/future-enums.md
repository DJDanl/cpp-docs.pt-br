---
title: Enumerações &lt;future&gt;
ms.date: 11/04/2016
f1_keywords:
- future/std::future_errc
- future/std::future_status
- future/std::launch
ms.assetid: 8c675645-db47-4cab-bc0e-7b87f8a302df
ms.openlocfilehash: 45dc3277b3f14b7f9dbb043cf9db1f1865d4e4c9
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88838016"
---
# <a name="ltfuturegt-enums"></a>Enumerações &lt;future&gt;

[future_errc](#future_errc)\
[future_status](#future_status)\
[inicialização](#launch)

## <a name="future_errc-enumeration"></a><a name="future_errc"></a> Enumeração de future_errc

Fornece nomes simbólicos para todos os erros relatados pela classe [future_error](../standard-library/future-error-class.md).

```cpp
class future_errc {
   broken_promise,
   future_already_retrieved,
   promise_already_satisfied,
   no_state
   };
```

## <a name="future_status-enumeration"></a><a name="future_status"></a> Enumeração de future_status

Fornece nomes simbólicos para os motivos que uma função de espera temporizada pode retornar.

```cpp
enum future_status{
    ready,
    timeout,
    deferred
};
```

## <a name="launch-enumeration"></a><a name="launch"></a> Enumeração de inicialização

Representa um tipo de bitmask que descreve os modos possíveis para a função de modelo [async](../standard-library/future-functions.md#async).

```cpp
class launch{
   async,
   deferred
   };
```

## <a name="see-also"></a>Confira também

[\<future>](../standard-library/future.md)
