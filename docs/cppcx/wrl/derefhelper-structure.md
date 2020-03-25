---
title: Estrutura DerefHelper
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::Details::DerefHelper
helpviewer_keywords:
- DerefHelper structure
ms.assetid: 86ded58b-c3ee-4a4f-bb86-4f67b895d427
ms.openlocfilehash: 43453d3162de697fa1cfcf0581953c91bbe3934f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214039"
---
# <a name="derefhelper-structure"></a>Estrutura DerefHelper

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename T>
struct DerefHelper;

template <typename T>
struct DerefHelper<T*>;
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Um parâmetro de modelo.

## <a name="remarks"></a>Comentários

Representa um ponteiro de referência para o parâmetro de modelo `T*`.

**DerefHelper** é usado em uma expressão como: `ComPtr<Details::DerefHelper<ProgressTraits::Arg1Type>::DerefType> operationInterface;`.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|`DerefType`|Identificador para o parâmetro de modelo desreferenciado `T*`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`DerefHelper`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Async. h

**Namespace:** Microsoft:: WRL::D etalhes

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL::Details](microsoft-wrl-details-namespace.md)
