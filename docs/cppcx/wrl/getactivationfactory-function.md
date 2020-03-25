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
ms.openlocfilehash: 430b4ed3f6a02fd3db2bcab05fbb7f21f5367b5c
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213974"
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

### <a name="parameters"></a>parâmetros

*T*<br/>
Um parâmetro de modelo que especifica o tipo da fábrica de ativação.

*activatableClassId*<br/>
O nome da classe que a fábrica de ativação pode produzir.

*padrões*<br/>
Quando essa operação for concluída, uma referência ao alocador de ativação para o tipo *T*.

## <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, um erro HRESULT indica por que essa operação falhou.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Client. h

**Namespace:** Windows:: Foundation

## <a name="see-also"></a>Confira também

[Namespace Windows::Foundation](windows-foundation-namespace.md)
