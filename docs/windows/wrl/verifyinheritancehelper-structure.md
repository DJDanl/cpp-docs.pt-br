---
title: Estrutura VerifyInheritanceHelper
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::VerifyInheritanceHelper
- implements/Microsoft::WRL::Details::VerifyInheritanceHelper::Verify
helpviewer_keywords:
- Microsoft::WRL::Details::VerifyInheritanceHelper structure
- Microsoft::WRL::Details::VerifyInheritanceHelper::Verify method
ms.assetid: 8a48a702-0f71-4807-935b-8311f0a7a8b6
ms.openlocfilehash: c37a0eb74fd65b3d349d5b8b7c792fbaf7d1ac9a
ms.sourcegitcommit: 360b55e89e5954f494e52b1cf989fbaceda06f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2019
ms.locfileid: "54335656"
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

*Base*<br/>
Outro tipo.

## <a name="remarks"></a>Comentários

Testa se uma interface é derivada de outra interface.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

Nome                                       | Descrição
------------------------------------------ | -------------------------------------------------------------------------------------------------------------------------------------
[VerifyInheritanceHelper::Verify](#verify) | Testa as duas interfaces especificadas pelos parâmetros de modelo atual e determina se uma interface é derivada da outra.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`VerifyInheritanceHelper`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="verify"></a>VerifyInheritanceHelper::Verify

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
static void Verify();
```

### <a name="remarks"></a>Comentários

Testa as duas interfaces especificadas pelos parâmetros de modelo atual e determina se uma interface é derivada da outra.

Um erro será emitido se uma interface não é derivada de outro.
