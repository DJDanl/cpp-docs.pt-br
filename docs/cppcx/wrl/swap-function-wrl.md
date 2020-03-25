---
title: Função swap (WRL)
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- internal/Microsoft::WRL::Details::Swap
ms.assetid: ed134a08-ceb7-4279-aa02-a183c3a426ea
ms.openlocfilehash: e665dbca025da56ba81c3fdf1749b2d653b78c00
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213558"
---
# <a name="swap-function-wrl"></a>Função swap (WRL)

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
WRL_NOTHROW inline void Swap(
   _Inout_ T& left,
   _Inout_ T& right
);
```

### <a name="parameters"></a>parâmetros

*left*<br/>
O primeiro argumento.

*right*<br/>
O segundo argumento.

## <a name="return-value"></a>Valor retornado

## <a name="remarks"></a>Comentários

Troca os valores dos dois argumentos especificados.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Internal. h

**Namespace:** Microsoft:: WRL::D etalhes

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL::Details](microsoft-wrl-details-namespace.md)
