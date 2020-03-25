---
title: Função CreateClassFactory
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Details::CreateClassFactory
helpviewer_keywords:
- CreateClassFactory function
ms.assetid: 772d5d1b-8872-4745-81ca-521a39564713
ms.openlocfilehash: 0467a9a1341e29a61a3b32d999769b01385f641f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214052"
---
# <a name="createclassfactory-function"></a>Função CreateClassFactory

Cria uma fábrica que produz instâncias da classe especificada.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename Factory>
inline HRESULT STDMETHODCALLTYPE CreateClassFactory(
   _In_ unsigned int *flags,
   _In_ const CreatorMap* entry,
   REFIID riid,
   _Outptr_ IUnknown **ppFactory
) throw();
```

### <a name="parameters"></a>parâmetros

*sinalizadores*<br/>
Uma combinação de um ou mais valores de enumeração [RuntimeClassType](runtimeclasstype-enumeration.md) .

*entry*<br/>
Ponteiro para um [CreatorMap](creatormap-structure.md) que contém informações de inicialização e de registro sobre o parâmetro *riid*.

*riid*<br/>
Referência a uma ID de interface.

*ppFactory*<br/>
Se essa operação for concluída com êxito, um ponteiro para uma fábrica de classes.

## <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, um HRESULT que indica o erro.

## <a name="remarks"></a>Comentários

Um erro de declaração é emitido se a *fábrica* de parâmetros de modelo não deriva da interface `IClassFactory`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Module. h

**Namespace:** Microsoft:: WRL

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL::Wrappers::Details](microsoft-wrl-wrappers-details-namespace.md)
