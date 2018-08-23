---
title: 'Construtor Module:: Module | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::Module
dev_langs:
- C++
helpviewer_keywords:
- Module, constructor
ms.assetid: 5436fc74-61dc-41b6-81af-4f03177159aa
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e0459c729368dc182de955f85afda514b2ff5071
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42591856"
---
# <a name="modulemodule-constructor"></a>Construtor Module::Module

Inicializa uma nova instância dos **módulo** classe.

## <a name="syntax"></a>Sintaxe

```cpp
Module();
```

## <a name="remarks"></a>Comentários

Este construtor é protegido e não pode ser chamado com o **novo** palavra-chave. Em vez disso, chame o [método Module:: getmodule](../windows/module-getmodule-method.md) ou [método Module:: Create](../windows/module-create-method.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também
[Classe Module](../windows/module-class.md)