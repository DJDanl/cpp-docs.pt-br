---
title: Função IID_PPV_ARGS_Helper
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- client/IID_PPV_ARGS_Helper
helpviewer_keywords:
- IID_PPV_ARGS_Helper function
ms.assetid: afee9b23-8df1-4575-903f-e9ba748418f0
ms.openlocfilehash: cae29c70c551701a351cdcf404342ed1634a0e3b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50467412"
---
# <a name="iidppvargshelper-function"></a>Função IID_PPV_ARGS_Helper

Verifica se o tipo do argumento especificado deriva o `IUnknown` interface.

> [!IMPORTANT]
> Essa especialização de modelo oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código. Use [IID_PPV_ARGS](https://msdn.microsoft.com/library/windows/desktop/ee330727.aspx) em vez disso.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename T>
void** IID_PPV_ARGS_Helper(
   _Inout_ Microsoft::WRL::Details::ComPtrRef<T> pp
);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo do argumento *pp*.

*PP*<br/>
Um ponteiro duplamente indireta.

## <a name="return-value"></a>Valor de retorno

Argumento *pp* convertido para um ponteiro-para-um-ponteiro à **void**.

## <a name="remarks"></a>Comentários

Um erro de tempo de compilação será gerado se o parâmetro de modelo *T* não deriva de `IUnknown`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

