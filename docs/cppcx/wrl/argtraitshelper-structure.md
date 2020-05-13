---
title: Estrutura ArgTraitsHelper
ms.date: 09/21/2018
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::Details::ArgTraitsHelper
- event/Microsoft::WRL::Details::ArgTraitsHelper::args
helpviewer_keywords:
- Microsoft::WRL::Details::ArgTraitsHelper structure
- Microsoft::WRL::Details::ArgTraitsHelper::args constant
ms.assetid: e3f798da-0aef-4a57-95d3-d38c34c47d72
ms.openlocfilehash: 4acbd9fa660f29bbaf209282ff0e90f43621574d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81360780"
---
# <a name="argtraitshelper-structure"></a>Estrutura ArgTraitsHelper

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename TDelegateInterface>
struct ArgTraitsHelper;
```

### <a name="parameters"></a>Parâmetros

*Interface de TDelegate*<br/>
Uma interface de delegado.

## <a name="remarks"></a>Comentários

Ajuda a definir características comuns dos argumentos do delegado.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome         | Descrição
------------ | ------------------------------------------------------
`methodType` | Um sinônimo de `decltype(&TDelegateInterface::Invoke)`.
`Traits`     | Um sinônimo de `ArgTraits<methodType>`.

### <a name="public-constants"></a>Constantes públicas

Nome                           | Descrição
------------------------------ | ---------------------------------------------------------------------------------------------------------------------
[ArgTraitsHelper::args](#args) | Ajuda [ArgTraits::args](#args) manter a contagem `Invoke` do número de parâmetros no método de uma interface de delegado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ArgTraitsHelper`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** event.h

**Espaço de nome:** Microsoft::WRL::Details

## <a name="argtraitshelperargs"></a><a name="args"></a>ArgTraitsHelper::args

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
static const int args = Traits::args;
```

### <a name="remarks"></a>Comentários

Ajuda `ArgTraitsHelper::args` a manter a contagem `Invoke` do número de parâmetros no método de uma interface de delegado.
