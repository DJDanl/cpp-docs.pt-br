---
title: Enumerações &lt;future&gt;
ms.date: 11/04/2016
f1_keywords:
- future/std::future_errc
- future/std::future_status
- future/std::launch
ms.assetid: 8c675645-db47-4cab-bc0e-7b87f8a302df
ms.openlocfilehash: a5bcebd80b296a0b8416580aa03acc59ce3750cd
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79421761"
---
# <a name="ltfuturegt-enums"></a>Enumerações &lt;future&gt;

||||
|-|-|-|
|[future_errc](#future_errc)|[future_status](#future_status)|[iniciar](#launch)|

## <a name="future_errc"></a>  Enumeração future_errc

Fornece nomes simbólicos para todos os erros relatados pela classe [future_error](../standard-library/future-error-class.md).

```cpp
class future_errc {
   broken_promise,
   future_already_retrieved,
   promise_already_satisfied,
   no_state
   };
```

## <a name="future_status"></a> Enumeração future_status

Fornece nomes simbólicos para os motivos que uma função de espera temporizada pode retornar.

```cpp
enum future_status{
    ready,
    timeout,
    deferred
};
```

## <a name="launch"></a>  Enumeração launch

Representa um tipo de bitmask que descreve os modos possíveis para a função de modelo [async](../standard-library/future-functions.md#async).

```cpp
class launch{
   async,
   deferred
   };
```

## <a name="see-also"></a>Confira também

[\<future>](../standard-library/future.md)
