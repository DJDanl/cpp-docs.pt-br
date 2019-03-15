---
title: /LINKERMEMBER
ms.date: 11/04/2016
f1_keywords:
- /linkermember
helpviewer_keywords:
- /LINKERMEMBER dumpbin option
- LINKERMEMBER dumpbin option
- -LINKERMEMBER dumpbin option
ms.assetid: c96868c1-d70e-4651-ae36-c55b58b16406
ms.openlocfilehash: a0456fd9ed1729b4a6cfa200a54ba211a64e94ea
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57813273"
---
# <a name="linkermember"></a>/LINKERMEMBER

```
/LINKERMEMBER[:{1|2}]
```

## <a name="remarks"></a>Comentários

Esta opção exibe os símbolos públicos definidos em uma biblioteca. Especifique o 1 argumento para exibir os símbolos em ordem de objeto, juntamente com seus deslocamentos. Especificar o argumento 2 para exibir os deslocamentos e números de índice de objetos e, em seguida, liste os símbolos em ordem alfabética, juntamente com o índice do objeto para cada um. Para obter as duas saídas, especifica /LINKERMEMBER sem o número de argumentos.

Somente o [/HEADERS](headers.md) opção DUMPBIN está disponível para uso em arquivos produzidos com o [/GL](gl-whole-program-optimization.md) opção de compilador.

## <a name="see-also"></a>Consulte também

[Opções de DUMPBIN](dumpbin-options.md)
