---
title: Estrutura RemoveReference | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- internal/Microsoft::WRL::Details::RemoveReference
dev_langs:
- C++
helpviewer_keywords:
- RemoveReference structure
ms.assetid: 43ff91bb-815a-440e-b9fb-7dcbb7c863af
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f6ab085e1bed3909090990cfa8e265bea792a483
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46447018"
---
# <a name="removereference-structure"></a>Estrutura RemoveReference

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template<class T>
struct RemoveReference;
template<class T>
struct RemoveReference<T&>;
template<class T>
struct RemoveReference<T&&>;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Uma classe.

## <a name="remarks"></a>Comentários

Retira a característica de referência ou uma referência de rvalue do parâmetro de modelo de classe especificada.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`Type`|Sinônimo do parâmetro de modelo de classe.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`RemoveReference`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** internal.h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)