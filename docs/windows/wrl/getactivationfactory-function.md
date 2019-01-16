---
title: Função GetActivationFactory
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Details::GetActivationFactory
- client/ABI::Windows::Foundation::GetActivationFactory
- client/Windows::Foundation::GetActivationFactory
helpviewer_keywords:
- GetActivationFactory function
ms.assetid: 5736d285-6beb-42aa-8788-e261c0010afe
ms.openlocfilehash: 82c83e95648eeb0fc8985777156659a2ffb876a8
ms.sourcegitcommit: 360b55e89e5954f494e52b1cf989fbaceda06f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2019
ms.locfileid: "54335439"
---
# <a name="getactivationfactory-function"></a>Função GetActivationFactory

Recupera um alocador de ativação para o tipo especificado pelo parâmetro de modelo.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename T>
inline HRESULT GetActivationFactory(
   _In_ HSTRING activatableClassId,
   _Out_ Microsoft::WRL::Details::ComPtrRef<T> factory
);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Um parâmetro de modelo que especifica o tipo de alocador de ativação.

*activatableClassId*<br/>
O nome da classe que o alocador de ativação pode produzir.

*factory*<br/>
Quando essa operação for concluída, uma referência para o alocador de ativação para o tipo *T*.

## <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um erro HRESULT que indica por que esta operação falhou.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Namespace:** Windows::Foundation

## <a name="see-also"></a>Consulte também

[Namespace Windows::Foundation](windows-foundation-namespace.md)