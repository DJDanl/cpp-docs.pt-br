---
title: Função ActivationFactoryCallback
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Details::ActivationFactoryCallback
helpviewer_keywords:
- ActivationFactoryCallback function
ms.assetid: dd40c79b-1273-4f2a-8c24-ae9926fb4fd9
ms.openlocfilehash: 8da0f3f54e142673a44909f3fe2141b09a71d388
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50586440"
---
# <a name="activationfactorycallback-function"></a>Função ActivationFactoryCallback

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
inline HRESULT STDAPICALLTYPE ActivationFactoryCallback(
   HSTRING activationId,
   IActivationFactory **ppFactory
);
```

### <a name="parameters"></a>Parâmetros

*activationId*<br/>
Identificador para uma cadeia de caracteres que especifica um nome de classe de tempo de execução.

*ppFactory*<br/>
Quando essa operação for concluída, um alocador de ativação que corresponde ao parâmetro *activationId*.

## <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que descreve a falha. HRESULTs de falha provavelmente são CLASS_E_CLASSNOTAVAILABLE e E_INVALIDARG.

## <a name="remarks"></a>Comentários

Obtém o alocador de ativação para a ID de ativação especificado.

O tempo de execução do Windows chama essa função de retorno de chamada para solicitar um objeto especificado pelo seu nome de classe de tempo de execução.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)