---
title: Função ActivationFactoryCallback
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Details::ActivationFactoryCallback
helpviewer_keywords:
- ActivationFactoryCallback function
ms.assetid: dd40c79b-1273-4f2a-8c24-ae9926fb4fd9
ms.openlocfilehash: 93db10e19cce0658bf731c14e7ac76b575841bf3
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58783788"
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

[Namespace Microsoft::WRL::Details](microsoft-wrl-details-namespace.md)