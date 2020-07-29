---
title: Função IID_PPV_ARGS_Helper
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- client/IID_PPV_ARGS_Helper
helpviewer_keywords:
- IID_PPV_ARGS_Helper function
ms.assetid: afee9b23-8df1-4575-903f-e9ba748418f0
ms.openlocfilehash: 6b1ab2e8e93fda194532fbc8d6f484aaa91249d8
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87212963"
---
# <a name="iid_ppv_args_helper-function"></a>Função IID_PPV_ARGS_Helper

Verifica se o tipo do argumento especificado deriva da `IUnknown` interface.

> [!IMPORTANT]
> Esta especialização de modelo dá suporte à infraestrutura WRL e não se destina a ser usada diretamente do seu código. Em vez disso, use [IID_PPV_ARGS](/windows/win32/api/combaseapi/nf-combaseapi-iid_ppv_args) .

## <a name="syntax"></a>Sintaxe

```cpp
template<typename T>
void** IID_PPV_ARGS_Helper(
   _Inout_ Microsoft::WRL::Details::ComPtrRef<T> pp
);
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo de argumento *PP*.

*PP*<br/>
Um ponteiro de indireto duplo.

## <a name="return-value"></a>Valor retornado

Argumento *PP* convertido para um ponteiro para um ponteiro para **`void`** .

## <a name="remarks"></a>Comentários

Um erro de tempo de compilação será gerado se o parâmetro de modelo *T* não derivar de `IUnknown` .

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Client. h
