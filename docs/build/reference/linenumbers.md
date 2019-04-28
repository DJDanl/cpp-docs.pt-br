---
title: /LINENUMBERS
ms.date: 11/04/2016
f1_keywords:
- /linenumbers
helpviewer_keywords:
- LINENUMBERS dumpbin option
- line numbers
- -LINENUMBERS dumpbin option
- /LINENUMBERS dumpbin option
ms.assetid: 1681d582-2c2f-484e-9920-109959549055
ms.openlocfilehash: ea4c3ac2ad582e0fe364f2da26511a66e9dc376c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62269235"
---
# <a name="linenumbers"></a>/LINENUMBERS

```
/LINENUMBERS
```

## <a name="remarks"></a>Comentários

Esta opção exibe números de linha COFF. Números de linha existem em um arquivo de objeto se ele tiver sido compilado com o banco de dados programa (/Zi) compatível com C7 (/ Z7), ou números apenas a linha (/Zd). Um arquivo executável ou DLL contém os números de linha COFF se ele foi vinculado com gerar informações de depuração (/debug).

Somente o [/HEADERS](headers.md) opção DUMPBIN está disponível para uso em arquivos produzidos com o [/GL](gl-whole-program-optimization.md) opção de compilador.

## <a name="see-also"></a>Consulte também

[Opções de DUMPBIN](dumpbin-options.md)
