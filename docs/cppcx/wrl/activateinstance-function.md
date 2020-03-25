---
title: Função ActivateInstance
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- client/Windows::Foundation::ActivateInstance
- client/ABI::Windows::Foundation::ActivateInstance
helpviewer_keywords:
- ActivateInstance function
ms.assetid: 8cfd1dd9-5fda-4cc2-acf8-d40e783b3875
ms.openlocfilehash: d1109e769352d412df8348822e05b66063159ee8
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214221"
---
# <a name="activateinstance-function"></a>Função ActivateInstance

Registra e recupera uma instância de um tipo especificado definido em uma ID de classe especificada.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename T>
inline HRESULT ActivateInstance(
   _In_ HSTRING activatableClassId,
   _Out_ Microsoft::WRL::Details::ComPtrRef<T> instance
);
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Um tipo a ser ativado.

*activatableClassId*<br/>
O nome da ID de classe que define o parâmetro *T*.

*instância*<br/>
Quando essa operação é concluída, uma referência a uma instância de *T*.

## <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, um erro HRESULT indica a causa do erro.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Client. h

**Namespace:** Windows:: Foundation

## <a name="see-also"></a>Confira também

[Namespace Windows::Foundation](windows-foundation-namespace.md)
