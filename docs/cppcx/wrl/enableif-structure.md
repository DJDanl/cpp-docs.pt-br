---
title: Estrutura EnableIf
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- internal/Microsoft::WRL::Details::EnableIf
helpviewer_keywords:
- EnableIf structure
ms.assetid: 7825b283-e6b2-4f39-a4b9-c03bcd431b8e
ms.openlocfilehash: daaba919acaa35615af56831f9458831c3d35427
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59029979"
---
# <a name="enableif-structure"></a>Estrutura EnableIf

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <bool b, typename T = void>
struct EnableIf;

template <typename T>
struct EnableIf<true, T>;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Um tipo.

*b*<br/>
Uma expressão booliana.

## <a name="remarks"></a>Comentários

Define um membro de dados do tipo especificado pelo segundo parâmetro de modelo se o primeiro parâmetro de modelo é avaliado como **verdadeira**.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`type`|Se o parâmetro de modelo *b* é avaliada como **verdadeiro**, a especialização parcial define o membro de dados `type` ser do tipo `T`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`EnableIf`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** internal.h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Details](microsoft-wrl-details-namespace.md)