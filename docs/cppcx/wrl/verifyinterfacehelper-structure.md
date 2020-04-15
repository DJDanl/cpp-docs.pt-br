---
title: Estrutura VerifyInterfaceHelper
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::VerifyInterfaceHelper
- implements/Microsoft::WRL::Details::VerifyInterfaceHelper::Verify
helpviewer_keywords:
- Microsoft::WRL::Details::VerifyInterfaceHelper structure
- Microsoft::WRL::Details::VerifyInterfaceHelper::Verify method
ms.assetid: ea95b641-199a-4fdf-964b-186b40cb3ba7
ms.openlocfilehash: 09c2cc7e08e2dc0e8df42c64d285c37627c5925a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374241"
---
# <a name="verifyinterfacehelper-structure"></a>Estrutura VerifyInterfaceHelper

Suporta a infra-estrutura da Biblioteca de Modelos C++ do Windows e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <bool isWinRTInterface, typename I>
struct VerifyInterfaceHelper;

template <typename I>
struct VerifyInterfaceHelper<false, I>;
```

### <a name="parameters"></a>Parâmetros

*Eu*<br/>
Uma interface para verificar.

*isWinRTInterface*

## <a name="remarks"></a>Comentários

Verifica se a interface especificada pelo parâmetro do modelo atende a certos requisitos.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

Nome                                            | Descrição
----------------------------------------------- | ---------------------------------------------------------------------------------------------------
[Método VerifyInterfaceHelper::Verify](#verify) | Verifica se a interface especificada pelo parâmetro de modelo atual atende a certos requisitos.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`VerifyInterfaceHelper`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** implements.h

**Espaço de nome:** Microsoft::WRL::Details

## <a name="verifyinterfacehelperverify"></a><a name="verify"></a>VerificarInterfaceHelper::Verificar

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
static void Verify();
```

### <a name="remarks"></a>Comentários

Verifica se a interface especificada pelo parâmetro de modelo atual atende a certos requisitos.
