---
title: Estrutura VerifyInheritanceHelper | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::VerifyInheritanceHelper
dev_langs:
- C++
helpviewer_keywords:
- VerifyInheritanceHelper structure
ms.assetid: 8a48a702-0f71-4807-935b-8311f0a7a8b6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ddd358c3eb20439f87de8614d80af01537ae31e6
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46396565"
---
# <a name="verifyinheritancehelper-structure"></a>Estrutura VerifyInheritanceHelper

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <
   typename I,
   typename Base
>
struct VerifyInheritanceHelper;
template <
   typename I
>
struct VerifyInheritanceHelper<I, Nil>;
```

### <a name="parameters"></a>Parâmetros

*I*<br/>
Um tipo.

*Base de dados de*<br/>
Outro tipo.

## <a name="remarks"></a>Comentários

Testa se uma interface é derivada de outra interface.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[Método VerifyInheritanceHelper::Verify](../windows/verifyinheritancehelper-verify-method.md)|Testa as duas interfaces especificadas pelos parâmetros de modelo atual e determina se uma interface é derivada da outra.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`VerifyInheritanceHelper`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)