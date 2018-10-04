---
title: Estrutura EnableIf | Microsoft Docs
ms.custom: ''
ms.date: 10/03/2018
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
ms.openlocfilehash: 2512c9b8b552027f4a0b4d72788e19d77a35d92e
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48789183"
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

[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)