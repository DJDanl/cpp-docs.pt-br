---
title: virtual (C++)
ms.date: 11/04/2016
f1_keywords:
- virtual_cpp
- virtual
helpviewer_keywords:
- virtual base classes [C++], declaring
- base classes [C++], virtual
- virtual functions [C++], declaring
- virtual keyword [C++]
ms.assetid: c2eb987d-6cf3-43b6-aa0c-29a6f561b1ae
ms.openlocfilehash: f68bd2e500ebe16c43ef6c3d7a5aede26421b27d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62393903"
---
# <a name="virtual-c"></a>virtual (C++)

O **virtual** palavra-chave declara uma função virtual ou uma classe base virtual.

## <a name="syntax"></a>Sintaxe

```
virtual [type-specifiers] member-function-declarator
virtual [access-specifier] base-class-name
```

#### <a name="parameters"></a>Parâmetros

*type-specifiers*<br/>
Especifica o tipo de retorno da função membro virtual.

*member-function-declarator*<br/>
Declara uma função membro.

*access-specifier*<br/>
Define o nível de acesso para a classe base, **pública**, **protegido** ou **privada**. Pode aparecer antes ou após o **virtual** palavra-chave.

*base-class-name*<br/>
Identifica um tipo de classe declarado previamente.

## <a name="remarks"></a>Comentários

Ver [funções virtuais](../cpp/virtual-functions.md) para obter mais informações.

Consulte também as seguintes palavras-chave: [classe](../cpp/class-cpp.md), [privada](../cpp/private-cpp.md), [público](../cpp/public-cpp.md), e [protegido](../cpp/protected-cpp.md).

## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)