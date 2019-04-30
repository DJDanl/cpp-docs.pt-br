---
title: Classe time_base
ms.date: 11/04/2016
f1_keywords:
- locale/std::time_base
helpviewer_keywords:
- time_base class
ms.assetid: 9ae37f0b-9a42-496e-9870-3d9b71bab8fb
ms.openlocfilehash: e790237e506aa32bafdb39938d841307bbc4d9c3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62412014"
---
# <a name="timebase-class"></a>Classe time_base

A classe serve como uma classe base para facetas de modelo classe time_get, definindo apenas o tipo enumerado `dateorder` e várias constantes desse tipo.

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

- `dmy` Especifica a ordem dia, mês e ano, como em 2 de dezembro de 1979.

- `mdy` Especifica o mês do pedido, dia e ano, como em 2 de dezembro de 1979.

- `ymd` Especifica a ordem ano, mês e dia, como em 1979/12/2.

- `ydm` Especifica a ordem ano, dia e mês, como em 1979: 2 de dezembro.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
