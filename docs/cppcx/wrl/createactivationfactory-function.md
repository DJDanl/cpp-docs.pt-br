---
title: Função CreateActivationFactory
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Details::CreateActivationFactory
helpviewer_keywords:
- CreateActivationFactory function
ms.assetid: a1a53e04-6757-4faf-a4c8-ecf06e43b959
ms.openlocfilehash: ab03b15a968c6aba3fa6df8c975fb98e873f8e23
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214065"
---
# <a name="createactivationfactory-function"></a>Função CreateActivationFactory

Cria uma fábrica que produz instâncias da classe especificada que pode ser ativada pelo Windows Runtime.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename Factory>
   inline HRESULT STDMETHODCALLTYPE CreateActivationFactory(
      _In_ unsigned int *flags,        _In_ const CreatorMap* entry,
      REFIID riid,
   _Outptr_ IUnknown **ppFactory) throw();
```

### <a name="parameters"></a>parâmetros

*sinalizadores*<br/>
Uma combinação de um ou mais valores de enumeração [RuntimeClassType](runtimeclasstype-enumeration.md) .

*entry*<br/>
Ponteiro para um [CreatorMap](creatormap-structure.md) que contém informações de inicialização e de registro sobre o parâmetro *riid*.

*riid*<br/>
Referência a uma ID de interface.

*ppFactory*<br/>
Se essa operação for concluída com êxito, um ponteiro para uma fábrica de ativação.

## <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, um HRESULT que indica o erro.

## <a name="remarks"></a>Comentários

Um erro de declaração é emitido se a *fábrica* de parâmetros de modelo não deriva da interface `IActivationFactory`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Module. h

**Namespace:** Microsoft:: WRL

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL::Wrappers::Details](microsoft-wrl-wrappers-details-namespace.md)
