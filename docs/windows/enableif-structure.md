---
title: Estrutura EnableIf | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- internal/Microsoft::WRL::Details::EnableIf
dev_langs:
- C++
helpviewer_keywords:
- EnableIf structure
ms.assetid: 7825b283-e6b2-4f39-a4b9-c03bcd431b8e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 2cc4e8f272838e5fa1de3eac8bd04a4ec3407dee
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46400660"
---
# <a name="enableif-structure"></a>Estrutura EnableIf

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <
   bool b,
   typename T = void
>

struct EnableIf;
template <
   typename T
>
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

[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)