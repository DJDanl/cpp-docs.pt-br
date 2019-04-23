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
ms.openlocfilehash: 3e138eee9e5bc02971cd1eb34c78f2be4ad5c9a0
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59033937"
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