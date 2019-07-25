---
title: Classe time_base
ms.date: 11/04/2016
f1_keywords:
- locale/std::time_base
helpviewer_keywords:
- time_base class
ms.assetid: 9ae37f0b-9a42-496e-9870-3d9b71bab8fb
ms.openlocfilehash: 85565dc0c0ec904551eb8dd981cfacc9a2e1f256
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68460032"
---
# <a name="timebase-class"></a>Classe time_base

A classe serve como uma classe base para facetas da classe template time_get, definindo apenas o tipo `dateorder` enumerado e várias constantes desse tipo.

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

- `no_order`especifica nenhuma ordem específica.

- `dmy`Especifica o dia, mês e ano do pedido, como em 2 de dezembro de 1979.

- `mdy`Especifica o mês, o dia e o ano do pedido, como em 2 de dezembro de 1979.

- `ymd`Especifica o ano, o mês e o dia do pedido, como em 1979/12/2.

- `ydm`Especifica o ano, o dia e o mês do pedido, como em 1979: 2 de dezembro.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
