---
title: Função Move
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- internal/Microsoft::WRL::Details::Move
helpviewer_keywords:
- Move function
ms.assetid: c9525426-97e8-4d8c-9877-b689d8a0dc67
ms.openlocfilehash: 1a03216197462090f38d3bc2065fe227f0667919
ms.sourcegitcommit: 360b55e89e5954f494e52b1cf989fbaceda06f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2019
ms.locfileid: "54335636"
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