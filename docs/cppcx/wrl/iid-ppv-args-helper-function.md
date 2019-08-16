---
title: Função IID_PPV_ARGS_Helper
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- client/IID_PPV_ARGS_Helper
helpviewer_keywords:
- IID_PPV_ARGS_Helper function
ms.assetid: afee9b23-8df1-4575-903f-e9ba748418f0
ms.openlocfilehash: e7733ae6084b64c20dff5a2c35d7a31c614d6e44
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69500500"
---
# <a name="iid_ppv_args_helper-function"></a>Função IID_PPV_ARGS_Helper

Verifica se o tipo do argumento especificado deriva da `IUnknown` interface.

> [!IMPORTANT]
> Esta especialização de modelo dá suporte à infraestrutura WRL e não se destina a ser usada diretamente do seu código. Use [IID_PPV_ARGS](/windows/win32/api/combaseapi/nf-combaseapi-iid_ppv_args) em vez disso.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename T>
void** IID_PPV_ARGS_Helper(
   _Inout_ Microsoft::WRL::Details::ComPtrRef<T> pp
);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de argumento *PP*.

*pp*<br/>
Um ponteiro de indireto duplo.

## <a name="return-value"></a>Valor de retorno

Argumento *PP* convertido para um ponteiro para ponteiro para **void**.

## <a name="remarks"></a>Comentários

Um erro de tempo de compilação será gerado se o parâmetro de modelo *T* não `IUnknown`derivar de.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Client. h

