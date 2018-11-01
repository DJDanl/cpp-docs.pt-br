---
title: ActivatableClass Macros
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- ActivatableClass
- ActivatableClassWithFactory
- ActivatableClassWithFactoryEx
helpviewer_keywords:
- ActivatableClassWithFactory
- ActivatableClass
- ActivatableClassWithFactoryEx
ms.assetid: 9bd64709-ec2c-4678-8c96-ea5982622bdd
ms.openlocfilehash: 1b50d9ba59ef8aebe4eca388ee30449f4ddd53de
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50660662"
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

*nome da classe*<br/>
Nome da classe a ser criada.

*fábrica*<br/>
Fábrica que cria uma instância da classe especificada.

*ServerName*<br/>
Um nome que especifica um subconjunto de fábricas no módulo.

## <a name="remarks"></a>Comentários

Não use essas macros com o COM clássico, a menos que você use o `#undef` diretiva para garantir que o `__WRL_WINRT_STRICT__` definição de macro é removida.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe Module](../windows/module-class.md)