---
title: Estrutura VerifyInterfaceHelper | Microsoft Docs
ms.custom: ''
ms.date: 10/03/2018
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
ms.openlocfilehash: b70155566695ade6b6778ade3b4758faebb3ea67
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48788859"
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

## <a name="verify"></a>Verifyinterfacehelper:: Verify

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
static void Verify();
```

### <a name="remarks"></a>Comentários

Verifica se a interface especificada pelo parâmetro de modelo atual atende a determinados requisitos.
