---
title: 'Método modulebase:: Incrementobjectcount | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::ModuleBase::IncrementObjectCount
dev_langs:
- C++
helpviewer_keywords:
- IncrementObjectCount method
ms.assetid: 2d70b472-684c-4bb7-8bab-09505cfcaf28
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b8ac3bcb256c4a54f3b967405e7f2c0699e715d1
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46377147"
---
# <a name="modulebaseincrementobjectcount-method"></a>Método ModuleBase::IncrementObjectCount

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
virtual long IncrementObjectCount() = 0;
```

## <a name="return-value"></a>Valor de retorno

A contagem de antes da operação de incremento.

## <a name="remarks"></a>Comentários

Quando implementado, incrementa o número de objetos controlados pelo módulo.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Classe ModuleBase](../windows/modulebase-class.md)<br/>
[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)