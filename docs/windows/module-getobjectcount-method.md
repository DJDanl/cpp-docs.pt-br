---
title: 'Método Module:: getobjectcount | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::GetObjectCount
dev_langs:
- C++
helpviewer_keywords:
- GetObjectCount method
ms.assetid: 9fe29747-7e7f-40f2-9f6b-9a206b17fa8e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 2be87f336adeb156789bb8c0ae7c8d05c8de39a4
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42608631"
---
# <a name="modulegetobjectcount-method"></a>Método Module::GetObjectCount

Recupera o número de objetos gerenciados por esse módulo.

## <a name="syntax"></a>Sintaxe

```cpp
virtual long GetObjectCount() const;
```

## <a name="return-value"></a>Valor de retorno

O número atual de objetos gerenciados por esse módulo.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe Module](../windows/module-class.md)