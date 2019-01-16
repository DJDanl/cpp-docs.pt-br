---
title: Função swap (WRL)
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- internal/Microsoft::WRL::Details::Swap
ms.assetid: ed134a08-ceb7-4279-aa02-a183c3a426ea
ms.openlocfilehash: cdac008bb352bfdb7689ed7a90a5f5c522e75c88
ms.sourcegitcommit: 360b55e89e5954f494e52b1cf989fbaceda06f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2019
ms.locfileid: "54335437"
---
# <a name="swap-function-wrl"></a>Função swap (WRL)

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
WRL_NOTHROW inline void Swap(
   _Inout_ T& left,
   _Inout_ T& right
);
```

### <a name="parameters"></a>Parâmetros

*left*<br/>
O primeiro argumento.

*right*<br/>
O segundo argumento.

## <a name="return-value"></a>Valor de retorno

## <a name="remarks"></a>Comentários

Troca os valores dos dois argumentos especificados.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** internal.h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Details](microsoft-wrl-details-namespace.md)