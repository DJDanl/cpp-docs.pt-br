---
title: Classe time_base
ms.date: 11/04/2016
f1_keywords:
- locale/std::time_base
helpviewer_keywords:
- time_base class
ms.assetid: 9ae37f0b-9a42-496e-9870-3d9b71bab8fb
ms.openlocfilehash: ddaf9905e859c062031940d35adfa2a3393dbb5a
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72685781"
---
# <a name="time_base-class"></a>Classe time_base

A classe serve como uma classe base para facetas do modelo de classe time_get, definindo apenas o tipo enumerado `dateorder` e várias constantes desse tipo.

## <a name="syntax"></a>Sintaxe

```cpp
class time_base : public locale::facet {
public:
    enum dateorder {
        no_order,
        dmy,
        mdy,
        ymd,
        ydm
    };
    time_base(size_t _Refs = 0)
    ~time_base();
};
```

## <a name="remarks"></a>Comentários

Cada constante caracteriza uma maneira diferente de ordenar os componentes de uma data. As constantes são:

- `no_order` não especifica nenhuma ordem específica.

- `dmy` especifica o dia, mês e ano do pedido, como em 2 de dezembro de 1979.

- `mdy` especifica a ordem mês, dia e ano, como em 2 de dezembro de 1979.

- `ymd` especifica o ano, o mês e o dia do pedido, como em 1979/12/2.

- `ydm` especifica o ano, o dia e o mês do pedido, como em 1979:2 Dec.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
