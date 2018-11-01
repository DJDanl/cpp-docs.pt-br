---
title: NAME (C/C++)
ms.date: 11/04/2016
f1_keywords:
- name
helpviewer_keywords:
- NAME .def file statement
ms.assetid: 5c9b6bd8-9275-46a5-afba-f17a5936dc26
ms.openlocfilehash: c05e82409d6b6e48390d54160e8ff23ada788d41
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50646193"
---
# <a name="name-cc"></a>NAME (C/C++)

Especifica um nome para o arquivo de saída principal.

```
NAME [application][BASE=address]
```

## <a name="remarks"></a>Comentários

Uma maneira equivalente para especificar um nome de arquivo de saída é com o [/out](../../build/reference/out-output-file-name.md) é a opção de vinculador e uma maneira equivalente para definir o endereço base com o [/base](../../build/reference/base-base-address.md) a opção de vinculador. Se ambos forem especificados, / OUT substitui **nome**.

Se você compilar uma DLL, o nome afetará apenas o nome da DLL.

## <a name="see-also"></a>Consulte também

[Regras para instruções de definição do módulo](../../build/reference/rules-for-module-definition-statements.md)