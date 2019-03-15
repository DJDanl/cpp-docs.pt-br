---
title: VERSION (C/C++)
ms.date: 11/04/2016
f1_keywords:
- VERSION
helpviewer_keywords:
- VERSION .def file statement
ms.assetid: 3533b97c-5183-45f9-9ca8-4e63462b5d26
ms.openlocfilehash: abc0b751440d09dcaad7e449d7b151b479c51911
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57815145"
---
# <a name="version-cc"></a>VERSION (C/C++)

Informa ao LINK para colocar um número no cabeçalho do arquivo .exe ou DLL.

```
VERSION major[.minor]
```

## <a name="remarks"></a>Comentários

O *principais* e *secundárias* argumentos são números decimais no intervalo de 0 a 65.535. O padrão é a versão 0.0.

Uma maneira equivalente para especificar um número de versão é com o [informações de versão](version-version-information.md) (/ versão) opção.

## <a name="see-also"></a>Consulte também

[Regras para instruções de definição do módulo](rules-for-module-definition-statements.md)
