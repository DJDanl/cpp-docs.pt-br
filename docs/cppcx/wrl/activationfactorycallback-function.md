---
title: Função ActivationFactoryCallback
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Details::ActivationFactoryCallback
helpviewer_keywords:
- ActivationFactoryCallback function
ms.assetid: dd40c79b-1273-4f2a-8c24-ae9926fb4fd9
ms.openlocfilehash: 0be4bebcc561cdf1df3f2502c8cc1927bdc65564
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214208"
---
# <a name="activationfactorycallback-function"></a>Função ActivationFactoryCallback

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
inline HRESULT STDAPICALLTYPE ActivationFactoryCallback(
   HSTRING activationId,
   IActivationFactory **ppFactory
);
```

### <a name="parameters"></a>parâmetros

*ActivationID*<br/>
Identificador para uma cadeia de caracteres que especifica um nome de classe de tempo de execução.

*ppFactory*<br/>
Quando essa operação for concluída, uma fábrica de ativação que corresponde ao parâmetro *ActivationID*.

## <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, um HRESULT que descreve a falha. Prováveis HRESULTs de falha são CLASS_E_CLASSNOTAVAILABLE e E_INVALIDARG.

## <a name="remarks"></a>Comentários

Obtém o alocador de ativação para a ID de ativação especificada.

O Windows Runtime chama essa função de retorno de chamada para solicitar um objeto especificado por seu nome de classe de tempo de execução.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Module. h

**Namespace:** Microsoft:: WRL::D etalhes

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL::Details](microsoft-wrl-details-namespace.md)
