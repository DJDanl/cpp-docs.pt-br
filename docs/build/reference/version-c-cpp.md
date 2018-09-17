---
title: VERSÃO (C/C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VERSION
dev_langs:
- C++
helpviewer_keywords:
- VERSION .def file statement
ms.assetid: 3533b97c-5183-45f9-9ca8-4e63462b5d26
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7330d979e841d952f7e800e52ae762256ede6808
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45718296"
---
# <a name="version-cc"></a>VERSION (C/C++)

Informa ao LINK para colocar um número no cabeçalho do arquivo .exe ou DLL.

```
VERSION major[.minor]
```

## <a name="remarks"></a>Comentários

O *principais* e *secundárias* argumentos são números decimais no intervalo de 0 a 65.535. O padrão é a versão 0.0.

Uma maneira equivalente para especificar um número de versão é com o [informações de versão](../../build/reference/version-version-information.md) (/ versão) opção.

## <a name="see-also"></a>Consulte também

[Regras para instruções de definição do módulo](../../build/reference/rules-for-module-definition-statements.md)