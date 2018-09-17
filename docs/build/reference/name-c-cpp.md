---
title: NOME (C/C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- name
dev_langs:
- C++
helpviewer_keywords:
- NAME .def file statement
ms.assetid: 5c9b6bd8-9275-46a5-afba-f17a5936dc26
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bc37a96e50c6cd5bae2cc60661db04f3b92d162b
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45715748"
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