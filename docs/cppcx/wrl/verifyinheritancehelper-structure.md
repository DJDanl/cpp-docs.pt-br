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
ms.openlocfilehash: 3650cfb70ffc12572b3965534eff4e1f2ecb2cf5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374229"
---
# <a name="verifyinheritancehelper-structure"></a>Estrutura VerifyInheritanceHelper

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename I, typename Base>
struct VerifyInheritanceHelper;

template <typename I>
struct VerifyInheritanceHelper<I, Nil>;
```

### <a name="parameters"></a>Parâmetros

*Eu*<br/>
Um tipo.

*Base*<br/>
Outro tipo.

## <a name="remarks"></a>Comentários

Testa se uma interface é derivada de outra interface.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

Nome                                       | Descrição
------------------------------------------ | -------------------------------------------------------------------------------------------------------------------------------------
[VerificarHerherHelper::Verificar](#verify) | Testa as duas interfaces especificadas pelos parâmetros de modelo atuais e determina se uma interface é derivada da outra.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`VerifyInheritanceHelper`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** implements.h

**Espaço de nome:** Microsoft::WRL::Details

## <a name="verifyinheritancehelperverify"></a><a name="verify"></a>VerificarHerherHelper::Verificar

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
static void Verify();
```

### <a name="remarks"></a>Comentários

Testa as duas interfaces especificadas pelos parâmetros de modelo atuais e determina se uma interface é derivada da outra.

Um erro é emitido se uma interface não for derivada da outra.
