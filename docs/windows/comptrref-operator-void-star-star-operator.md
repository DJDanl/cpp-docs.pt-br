---
title: 'Comptrref:: Operator void * operador | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::Details::ComPtrRef::operator void**
dev_langs:
- C++
helpviewer_keywords:
- operator void** operator
ms.assetid: f020045c-9de4-4392-8783-73f0fc0761c6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 977e04b923a99cab3eb42544de99c4fcee974e82
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46408863"
---
# <a name="comptrrefoperator-void-operator"></a>Comptrref:: Operator void\* \* operador

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
operator void**() const;
```

## <a name="remarks"></a>Comentários

Exclui o atual **ComPtrRef** do objeto, converte o ponteiro para a interface que foi representado pela **ComPtrRef** objeto como um ponteiro-para-ponteiro-para **void**e, em seguida, Retorna o ponteiro de conversão.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Classe ComPtrRef](../windows/comptrref-class.md)<br/>
[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)