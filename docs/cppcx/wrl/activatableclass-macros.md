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
ms.openlocfilehash: 7bc3d789d6c0d304aa170d59dff23a97a67061d7
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214249"
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

### <a name="parameters"></a>parâmetros

*className*<br/>
Nome da classe a ser criada.

*padrões*<br/>
Fábrica que criará uma instância da classe especificada.

*serverName*<br/>
Um nome que especifica um subconjunto de fábricas no módulo.

## <a name="remarks"></a>Comentários

Não use essas macros com o COM clássico, a menos que você use a diretiva `#undef` para garantir que a definição de macro `__WRL_WINRT_STRICT__` seja removida.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Module. h

**Namespace:** Microsoft:: WRL

## <a name="see-also"></a>Confira também

[Classe Module](module-class.md)
