---
title: Estrutura DerefHelper | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::Details::DerefHelper
dev_langs:
- C++
helpviewer_keywords:
- DerefHelper structure
ms.assetid: 86ded58b-c3ee-4a4f-bb86-4f67b895d427
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 016f6c5effeb964d5682f0a83ef63a4884b324c6
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46388492"
---
# <a name="derefhelper-structure"></a>Estrutura DerefHelper

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <
   typename T
>
struct DerefHelper;

template <
   typename T
>
struct DerefHelper<T*>;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Um parâmetro de modelo.

## <a name="remarks"></a>Comentários

Representar um ponteiro cancelado para o `T*` parâmetro de modelo.

**DerefHelper** é usado em uma expressão, como: `ComPtr<Details::DerefHelper<ProgressTraits::Arg1Type>::DerefType> operationInterface;`.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`DerefType`|Identificador para o parâmetro de modelo cancelada `T*`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`DerefHelper`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** async.h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)