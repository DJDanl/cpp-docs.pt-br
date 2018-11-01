---
title: Função back_inserter
ms.date: 12/30/2016
f1_keywords:
- collection/Windows::Foundation::Collections::back_inserter
helpviewer_keywords:
- back_inserter Function
ms.assetid: 91476338-5548-44b7-bc7e-2150f4fbe31a
ms.openlocfilehash: 7939f82431c93dd447debf50af30f8e9aa3f06ba
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50430518"
---
# <a name="backinserter-function"></a>Função back_inserter

Retorna um iterador que é usado para inserir elementos no final da coleção especificada.

## <a name="syntax"></a>Sintaxe

```

template <typename T>
Platform::BackInsertIterator<T>
    back_inserter(IVector<T>^ v);

template<typename T>
Platform::BackInsertIterator<T>
   back_inserter(IObservableVector<T>^ v);
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Um parâmetro de tipo de modelo.

*v*<br/>
Um ponteiro de interface que fornece acesso à coleção subjacente.

### <a name="return-value"></a>Valor de retorno

Um iterador.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Windows::Foundation::Collections

## <a name="see-also"></a>Consulte também

[Namespace Collections](../cppcx/windows-foundation-collections-namespace-c-cx.md)