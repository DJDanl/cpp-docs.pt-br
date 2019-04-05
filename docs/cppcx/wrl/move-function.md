---
title: Função Move
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- internal/Microsoft::WRL::Details::Move
helpviewer_keywords:
- Move function
ms.assetid: c9525426-97e8-4d8c-9877-b689d8a0dc67
ms.openlocfilehash: 8d7c959ecb2d3c06872871ba062d2be603489141
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59031268"
---
# <a name="move-function"></a>Função Move

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template<class T>
inline typename RemoveReference<T>::Type&& Move(
   _Inout_ T&& arg
);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo do argumento.

*arg*<br/>
Um argumento para mover.

## <a name="return-value"></a>Valor de retorno

Parâmetro *arg* após características de referência ou uma referência de rvalue, se houver, foram removidos.

## <a name="remarks"></a>Comentários

Move o argumento especificado de um local para outro.

Para obter mais informações, consulte o **mover semântica** seção [Declarador de referência Rvalue: & &](../../cpp/rvalue-reference-declarator-amp-amp.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** internal.h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Details](microsoft-wrl-details-namespace.md)