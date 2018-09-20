---
title: Estrutura ArgTraitsHelper | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::Details::ArgTraitsHelper
dev_langs:
- C++
helpviewer_keywords:
- ArgTraitsHelper structure
ms.assetid: e3f798da-0aef-4a57-95d3-d38c34c47d72
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 314853b103d74bd7907fb665b806f386ed7bd44e
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46397462"
---
# <a name="argtraitshelper-structure"></a>Estrutura ArgTraitsHelper

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename TDelegateInterface>
struct ArgTraitsHelper;
```

### <a name="parameters"></a>Parâmetros

*TDelegateInterface*<br/>
Uma interface de delegado.

## <a name="remarks"></a>Comentários

Ajuda a definir as características comuns de argumentos do delegado.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`methodType`|Um sinônimo de `decltype(&TDelegateInterface::Invoke)`.|
|`Traits`|Um sinônimo de `ArgTraits<methodType>`.|

### <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|[Constante ArgTraitsHelper::args](../windows/argtraitshelper-args-constant.md)|Ajuda [argtraits:: args](../windows/argtraits-args-constant.md) manter a contagem do número de parâmetros `Invoke` método da interface de um delegado.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ArgTraitsHelper`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Event. h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)