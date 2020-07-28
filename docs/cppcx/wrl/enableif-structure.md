---
title: Estrutura EnableIf
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- internal/Microsoft::WRL::Details::EnableIf
helpviewer_keywords:
- EnableIf structure
ms.assetid: 7825b283-e6b2-4f39-a4b9-c03bcd431b8e
ms.openlocfilehash: f43166920f3582ab681b67d2c89563dcf78ff0f1
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220490"
---
# <a name="enableif-structure"></a>Estrutura EnableIf

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <bool b, typename T = void>
struct EnableIf;

template <typename T>
struct EnableIf<true, T>;
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Um tipo.

*b*<br/>
Uma expressão booliana.

## <a name="remarks"></a>Comentários

Define um membro de dados do tipo especificado pelo segundo parâmetro de modelo se o primeiro parâmetro de modelo for avaliado como **`true`** .

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`type`|Se o parâmetro de modelo *b* for avaliado como **`true`** , a especialização parcial definirá que o membro `type` de dados seja do tipo `T` .|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`EnableIf`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Internal. h

**Namespace:** Microsoft:: WRL::D etalhes

## <a name="see-also"></a>Confira também

[Namespace Microsoft:: WRL::D etalhes](microsoft-wrl-details-namespace.md)
