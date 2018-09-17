---
title: -IMPORTS (DUMPBIN) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /imports
dev_langs:
- C++
helpviewer_keywords:
- IMPORTS dumpbin option
- /IMPORTS dumpbin option
- -IMPORTS dumpbin option
ms.assetid: 6a296216-2b1b-40f8-8736-cd4553a22456
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c5b3b1e3a74fea278bc142d02f793308b6b0e054
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45713564"
---
# <a name="imports-dumpbin"></a>/IMPORTS (DUMPBIN)

```
/IMPORTS[:file]
```

Essa opção exibe a lista de DLLs (ambos vinculados estaticamente e [atrasar carregada](../../build/reference/linker-support-for-delay-loaded-dlls.md)) que são importadas para um arquivo executável ou DLL e todas as importações individuais de cada uma dessas DLLs.

Opcional `file` especificação permite que você especifique que as importações de DLL só serão exibidas. Por exemplo:

```
dumpbin /IMPORTS:msvcrt.dll
```

## <a name="remarks"></a>Comentários

A saída exibida por essa opção é semelhante para o [/EXPORTA](../../build/reference/dash-exports.md) saída.

Somente o [/HEADERS](../../build/reference/headers.md) opção DUMPBIN está disponível para uso em arquivos produzidos com o [/GL](../../build/reference/gl-whole-program-optimization.md) opção de compilador.

## <a name="see-also"></a>Consulte também

[Opções de DUMPBIN](../../build/reference/dumpbin-options.md)