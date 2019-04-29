---
title: NAME (C/C++)
ms.date: 11/04/2016
f1_keywords:
- name
helpviewer_keywords:
- NAME .def file statement
ms.assetid: 5c9b6bd8-9275-46a5-afba-f17a5936dc26
ms.openlocfilehash: d0813befc622db72e095c449794405fc5d58465b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62320572"
---
# <a name="name-cc"></a>NAME (C/C++)

Especifica um nome para o arquivo de saída principal.

```
NAME [application][BASE=address]
```

## <a name="remarks"></a>Comentários

Uma maneira equivalente para especificar um nome de arquivo de saída é com o [/out](out-output-file-name.md) é a opção de vinculador e uma maneira equivalente para definir o endereço base com o [/base](base-base-address.md) a opção de vinculador. Se ambos forem especificados, / OUT substitui **nome**.

Se você compilar uma DLL, o nome afetará apenas o nome da DLL.

## <a name="see-also"></a>Consulte também

[Regras para instruções de definição do módulo](rules-for-module-definition-statements.md)
