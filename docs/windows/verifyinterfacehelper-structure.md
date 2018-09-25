---
title: Estrutura VerifyInterfaceHelper | Microsoft Docs
ms.custom: ''
ms.date: 09/24/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::VerifyInterfaceHelper
- implements/Microsoft::WRL::Details::VerifyInterfaceHelper::Verify
dev_langs:
- C++
helpviewer_keywords:
- Microsoft::WRL::Details::VerifyInterfaceHelper structure
- Microsoft::WRL::Details::VerifyInterfaceHelper::Verify method
ms.assetid: ea95b641-199a-4fdf-964b-186b40cb3ba7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e7aa7d796fb30a30a100f5f914feec57909407e5
ms.sourcegitcommit: edb46b0239a0e616af4ec58906e12338c3e8d2c6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2018
ms.locfileid: "47169756"
---
# <a name="verifyinterfacehelper-structure"></a>Estrutura VerifyInterfaceHelper

Oferece suporte a infraestrutura de biblioteca de modelos de C++ de tempo de execução do Windows e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <
   bool isWinRTInterface,
   typename I
>
struct VerifyInterfaceHelper;

template <
   typename I
>
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

## <a name="verify"></a>Verifyinterfacehelper:: Verify

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
static void Verify();
```

### <a name="remarks"></a>Comentários

Verifica se a interface especificada pelo parâmetro de modelo atual atende a determinados requisitos.
