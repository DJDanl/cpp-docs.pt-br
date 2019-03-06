---
title: NAME (C/C++)
ms.date: 11/04/2016
f1_keywords:
- name
helpviewer_keywords:
- NAME .def file statement
ms.assetid: 5c9b6bd8-9275-46a5-afba-f17a5936dc26
ms.openlocfilehash: c4888b8f9b6dba4b826f2ee7dda7529a4bdf1586
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57414493"
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
