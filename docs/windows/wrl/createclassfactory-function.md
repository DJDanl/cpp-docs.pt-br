---
title: Função CreateClassFactory
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Details::CreateClassFactory
helpviewer_keywords:
- CreateClassFactory function
ms.assetid: 772d5d1b-8872-4745-81ca-521a39564713
ms.openlocfilehash: e7e213d1b0679f17ce070de85ee9410ff9546716
ms.sourcegitcommit: 360b55e89e5954f494e52b1cf989fbaceda06f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2019
ms.locfileid: "54335508"
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

### <a name="parameters"></a>Parâmetros

*flags*<br/>
Uma combinação de um ou mais [RuntimeClassType](runtimeclasstype-enumeration.md) valores de enumeração.

*entry*<br/>
Ponteiro para um [CreatorMap](creatormap-structure.md) que contém informações de registro e inicialização sobre o parâmetro *riid*.

*riid*<br/>
Referência a uma ID de interface.

*ppFactory*<br/>
Se essa operação for concluída com êxito, um ponteiro para uma fábrica de classes.

## <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.

## <a name="remarks"></a>Comentários

Um erro de asserção será emitido se o parâmetro de modelo *fábrica* não deriva da interface `IClassFactory`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Wrappers::Details](microsoft-wrl-wrappers-details-namespace.md)