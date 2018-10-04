---
title: Estrutura VerifyInheritanceHelper | Microsoft Docs
ms.custom: ''
ms.date: 10/03/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::VerifyInheritanceHelper
- implements/Microsoft::WRL::Details::VerifyInheritanceHelper::Verify
dev_langs:
- C++
helpviewer_keywords:
- Microsoft::WRL::Details::VerifyInheritanceHelper structure
- Microsoft::WRL::Details::VerifyInheritanceHelper::Verify method
ms.assetid: 8a48a702-0f71-4807-935b-8311f0a7a8b6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 2a011b0583d8221ec49d16236add978ac647acc3
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48788923"
---
# <a name="verifyinheritancehelper-structure"></a>Estrutura VerifyInheritanceHelper

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename I, typename Base>
struct VerifyInheritanceHelper;

template <typename I>
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

Nome                                       | Descrição
------------------------------------------ | -------------------------------------------------------------------------------------------------------------------------------------
[Verifyinheritancehelper:: Verify](#verify) | Testa as duas interfaces especificadas pelos parâmetros de modelo atual e determina se uma interface é derivada da outra.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`VerifyInheritanceHelper`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="verify"></a>Verifyinheritancehelper:: Verify

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
static void Verify();
```

### <a name="remarks"></a>Comentários

Testa as duas interfaces especificadas pelos parâmetros de modelo atual e determina se uma interface é derivada da outra.

Um erro será emitido se uma interface não é derivada de outro.
