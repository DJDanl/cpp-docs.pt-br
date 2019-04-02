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
ms.openlocfilehash: fbba6d96106cc95910ccd9d0029cb3e9c254d7d3
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58783779"
---
# <a name="argtraitshelper-structure"></a>Estrutura ArgTraitsHelper

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename TDelegateInterface>
struct ArgTraitsHelper;
```

### <a name="parameters"></a>Parâmetros

*TDelegateInterface*<br/>
Uma interface de delegado.

## <a name="remarks"></a>Comentários

Ajuda a definir as características comuns de argumentos do delegado.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome         | Descrição
------------ | ------------------------------------------------------
`methodType` | Um sinônimo de `decltype(&TDelegateInterface::Invoke)`.
`Traits`     | Um sinônimo de `ArgTraits<methodType>`.

### <a name="public-constants"></a>Constantes públicas

Nome                           | Descrição
------------------------------ | ---------------------------------------------------------------------------------------------------------------------
[ArgTraitsHelper::args](#args) | Ajuda [argtraits:: args](#args) manter a contagem do número de parâmetros `Invoke` método da interface de um delegado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ArgTraitsHelper`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Event. h

**Namespace:** Microsoft::WRL::Details

## <a name="args"></a>ArgTraitsHelper::args

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
static const int args = Traits::args;
```

### <a name="remarks"></a>Comentários

Ajuda `ArgTraitsHelper::args` manter a contagem do número de parâmetros `Invoke` método da interface de um delegado.
