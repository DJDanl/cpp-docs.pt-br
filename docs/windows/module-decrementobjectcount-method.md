---
title: 'Método Module:: decrementobjectcount | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::DecrementObjectCount
dev_langs:
- C++
helpviewer_keywords:
- DecrementObjectCount method
ms.assetid: 6a06d1f9-7881-4f0e-891f-46b0e5c4f604
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5a672ce0d3397e4f69a44d7a888cdacaa467dd49
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42610480"
---
# <a name="moduledecrementobjectcount-method"></a>Método Module::DecrementObjectCount

Diminui o número de objetos rastreados pelo módulo.

## <a name="syntax"></a>Sintaxe

```cpp
virtual long DecrementObjectCount();
```

## <a name="return-value"></a>Valor de retorno

A contagem de antes da operação de decremento.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe Module](../windows/module-class.md)