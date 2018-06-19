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
ms.openlocfilehash: af3b9a1bbcf1769e87715e46566dee9c53a96747
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32373433"
---
# <a name="imports-dumpbin"></a>/IMPORTS (DUMPBIN)
```  
/IMPORTS[:file]  
```  
  
 Essa opção exibe a lista de DLLs (ambos estaticamente vinculada e [atraso carregado](../../build/reference/linker-support-for-delay-loaded-dlls.md)) que são importados para um arquivo executável ou DLL e todas as importações individuais de cada um desses DLLs.  
  
 Opcional `file` especificação permite que você especifique que o importa somente dessa dll será exibido. Por exemplo:  
  
```  
dumpbin /IMPORTS:msvcrt.dll  
```  
  
## <a name="remarks"></a>Comentários  
 A saída exibida por essa opção é semelhante de [/EXPORTA](../../build/reference/dash-exports.md) saída.  
  
 Somente o [/HEADERS](../../build/reference/headers.md) opção DUMPBIN está disponível para uso em arquivos produzidos com o [/GL](../../build/reference/gl-whole-program-optimization.md) opção de compilador.  
  
## <a name="see-also"></a>Consulte também  
 [Opções de DUMPBIN](../../build/reference/dumpbin-options.md)