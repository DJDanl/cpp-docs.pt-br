---
title: virtual (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- virtual_cpp
- virtual
dev_langs:
- C++
helpviewer_keywords:
- virtual base classes [C++], declaring
- base classes [C++], virtual
- virtual functions [C++], declaring
- virtual keyword [C++]
ms.assetid: c2eb987d-6cf3-43b6-aa0c-29a6f561b1ae
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2471dac12db574aa045142a654effafadbabd732
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46092238"
---
# <a name="virtual-c"></a>virtual (C++)

O **virtual** palavra-chave declara uma função virtual ou uma classe base virtual.

## <a name="syntax"></a>Sintaxe

```
virtual [type-specifiers] member-function-declarator
virtual [access-specifier] base-class-name
```

#### <a name="parameters"></a>Parâmetros

*especificadores de tipo*<br/>
Especifica o tipo de retorno da função membro virtual.

*Declarador de função de membro*<br/>
Declara uma função membro.

*especificador de acesso*<br/>
Define o nível de acesso para a classe base, **pública**, **protegido** ou **privada**. Pode aparecer antes ou após o **virtual** palavra-chave.

*nome da classe base*<br/>
Identifica um tipo de classe declarado previamente.

## <a name="remarks"></a>Comentários

Ver [funções virtuais](../cpp/virtual-functions.md) para obter mais informações.

Consulte também as seguintes palavras-chave: [classe](../cpp/class-cpp.md), [privada](../cpp/private-cpp.md), [público](../cpp/public-cpp.md), e [protegido](../cpp/protected-cpp.md).

## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)