---
title: Função IID_PPV_ARGS_Helper
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- client/IID_PPV_ARGS_Helper
helpviewer_keywords:
- IID_PPV_ARGS_Helper function
ms.assetid: afee9b23-8df1-4575-903f-e9ba748418f0
ms.openlocfilehash: 68dbd0b5b2e9d4fc04821a7e7e0193840b55e312
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80077136"
---
# <a name="iid_ppv_args_helper-function"></a>Função IID_PPV_ARGS_Helper

Verifica se o tipo do argumento especificado deriva da interface `IUnknown`.

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

Argumento *PP* convertido para um ponteiro para ponteiro para **void**.

## <a name="remarks"></a>Comentários

Um erro de tempo de compilação será gerado se o parâmetro de modelo *T* não derivar de `IUnknown`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Client. h
