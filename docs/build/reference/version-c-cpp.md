---
title: VERSION (C/C++)
ms.date: 11/04/2016
f1_keywords:
- VERSION
helpviewer_keywords:
- VERSION .def file statement
ms.assetid: 3533b97c-5183-45f9-9ca8-4e63462b5d26
ms.openlocfilehash: 6d275e1e191e0550143dd5e7a828b734bba0fc96
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57414051"
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
