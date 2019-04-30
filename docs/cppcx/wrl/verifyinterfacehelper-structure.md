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
ms.openlocfilehash: cdd0272953b2399cd71efe207eb1c56e5de154e6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62398089"
---
# <a name="verifyinterfacehelper-structure"></a>Estrutura VerifyInterfaceHelper

Oferece suporte a infraestrutura de biblioteca de modelos de C++ de tempo de execução do Windows e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <bool isWinRTInterface, typename I>
struct VerifyInterfaceHelper;

template <typename I>
struct VerifyInterfaceHelper<false, I>;
```

### <a name="parameters"></a>Parâmetros

*I*<br/>
Uma interface para verificar.

*isWinRTInterface*

## <a name="remarks"></a>Comentários

Verifica se a interface especificada pelo parâmetro de modelo atende a determinados requisitos.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

Nome                                            | Descrição
----------------------------------------------- | ---------------------------------------------------------------------------------------------------
[Método VerifyInterfaceHelper::Verify](#verify) | Verifica se a interface especificada pelo parâmetro de modelo atual atende a determinados requisitos.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`VerifyInterfaceHelper`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="verify"></a>VerifyInterfaceHelper::Verify

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
static void Verify();
```

### <a name="remarks"></a>Comentários

Verifica se a interface especificada pelo parâmetro de modelo atual atende a determinados requisitos.
