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
ms.openlocfilehash: 7d38db9e7d3fa94c89195b6379e14692f26f7ee5
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59037588"
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

*className*<br/>
Nome da classe a ser criada.

*factory*<br/>
Fábrica que cria uma instância da classe especificada.

*serverName*<br/>
Um nome que especifica um subconjunto de fábricas no módulo.

## <a name="remarks"></a>Comentários

Não use essas macros com o COM clássico, a menos que você use o `#undef` diretiva para garantir que o `__WRL_WINRT_STRICT__` definição de macro é removida.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe Module](module-class.md)