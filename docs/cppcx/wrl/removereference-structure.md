---
title: Estrutura RemoveReference
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- internal/Microsoft::WRL::Details::RemoveReference
helpviewer_keywords:
- RemoveReference structure
ms.assetid: 43ff91bb-815a-440e-b9fb-7dcbb7c863af
ms.openlocfilehash: 7753c1ad41f12fa8c14d2f10c9e2f91e043a5846
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213597"
---
# <a name="removereference-structure"></a>Estrutura RemoveReference

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template<class T>
struct RemoveReference;

template<class T>
struct RemoveReference<T&>;

template<class T>
struct RemoveReference<T&&>;
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Uma classe.

## <a name="remarks"></a>Comentários

Remove a característica de referência ou de referência rvalue do parâmetro de modelo de classe especificado.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|`Type`|Sinônimo do parâmetro de modelo de classe.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`RemoveReference`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Internal. h

**Namespace:** Microsoft:: WRL::D etalhes

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL::Details](microsoft-wrl-details-namespace.md)
