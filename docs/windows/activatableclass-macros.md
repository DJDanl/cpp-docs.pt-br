---
title: ActivatableClass Macros | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- ActivatableClass
- ActivatableClassWithFactory
- ActivatableClassWithFactoryEx
dev_langs:
- C++
helpviewer_keywords:
- ActivatableClassWithFactory
- ActivatableClass
- ActivatableClassWithFactoryEx
ms.assetid: 9bd64709-ec2c-4678-8c96-ea5982622bdd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: aa178126b3a749e3af67b9dae3711c0a5cf9f408
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39645780"
---
# <a name="activatableclass-macros"></a>ActivatableClass Macros

Popula um cache interno que contém uma fábrica que pode criar uma instância da classe especificada.

## <a name="syntax"></a>Sintaxe

```cpp
ActivatableClass(
   className
);

ActivatableClassWithFactory(
   className,
   factory
);

ActivatableClassWithFactoryEx(
   className,
   factory,
   serverName
);
```

### <a name="parameters"></a>Parâmetros

*nome da classe*  
Nome da classe a ser criada.  

*fábrica*  
Fábrica que cria uma instância da classe especificada.

*ServerName*  
Um nome que especifica um subconjunto de fábricas no módulo.

## <a name="remarks"></a>Comentários

Não use essas macros com o COM clássico, a menos que você use o `#undef` diretiva para garantir que o `__WRL_WINRT_STRICT__` definição de macro é removida.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também
[Classe Module](../windows/module-class.md)