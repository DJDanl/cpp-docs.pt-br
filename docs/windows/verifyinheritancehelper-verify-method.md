---
title: 'Método verifyinheritancehelper:: Verify | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::VerifyInheritanceHelper::Verify
dev_langs:
- C++
helpviewer_keywords:
- Verify method
ms.assetid: 3360082b-81ad-4191-9ec3-b4372f7207d7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8a337dcce390f8dc3b634018af602bc3e62e719b
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46396084"
---
# <a name="verifyinheritancehelperverify-method"></a>Método VerifyInheritanceHelper::Verify

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
static void Verify();
```

## <a name="remarks"></a>Comentários

Testa as duas interfaces especificadas pelos parâmetros de modelo atual e determina se uma interface é derivada da outra.

Um erro será emitido se uma interface não é derivada de outro.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Estrutura VerifyInheritanceHelper](../windows/verifyinheritancehelper-structure.md)<br/>
[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)