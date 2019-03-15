---
title: /IMPORTS (DUMPBIN)
ms.date: 11/04/2016
f1_keywords:
- /imports
helpviewer_keywords:
- IMPORTS dumpbin option
- /IMPORTS dumpbin option
- -IMPORTS dumpbin option
ms.assetid: 6a296216-2b1b-40f8-8736-cd4553a22456
ms.openlocfilehash: c8b0f88b38eb657fe4d3916ef0df13972e985cbe
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57810335"
---
# <a name="imports-dumpbin"></a>/IMPORTS (DUMPBIN)

```
/IMPORTS[:file]
```

Essa opção exibe a lista de DLLs (ambos vinculados estaticamente e [atrasar carregada](linker-support-for-delay-loaded-dlls.md)) que são importadas para um arquivo executável ou DLL e todas as importações individuais de cada uma dessas DLLs.

Opcional `file` especificação permite que você especifique que as importações de DLL só serão exibidas. Por exemplo:

```
dumpbin /IMPORTS:msvcrt.dll
```

## <a name="remarks"></a>Comentários

A saída exibida por essa opção é semelhante para o [/EXPORTA](dash-exports.md) saída.

Somente o [/HEADERS](headers.md) opção DUMPBIN está disponível para uso em arquivos produzidos com o [/GL](gl-whole-program-optimization.md) opção de compilador.

## <a name="see-also"></a>Consulte também

[Opções de DUMPBIN](dumpbin-options.md)
