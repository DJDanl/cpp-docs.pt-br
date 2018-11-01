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
ms.openlocfilehash: a2581fce3c15c96317bf68de0ed918b19edd8b38
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50481699"
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

*fábrica*<br/>
Quando essa operação for concluída, uma referência para o alocador de ativação para o tipo *T*.

## <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um erro HRESULT que indica por que esta operação falhou.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Namespace:** Windows:: Foundation

## <a name="see-also"></a>Consulte também

[Namespace Windows::Foundation](../windows/windows-foundation-namespace.md)