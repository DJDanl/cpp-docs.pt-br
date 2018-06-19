---
title: _CRTDBG_MAP_ALLOC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- CRTDBG_MAP_ALLOC
- _CRTDBG_MAP_ALLOC
dev_langs:
- C++
helpviewer_keywords:
- _CRTDBG_MAP_ALLOC macro
- memory allocation, in debug builds
- CRTDBG_MAP_ALLOC macro
ms.assetid: 435242b8-caea-4063-b765-4a608200312b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 855b057223d7bdd69d7275e8c2acc0dd72bc256c
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32386473"
---
# <a name="crtdbgmapalloc"></a>_CRTDBG_MAP_ALLOC
Quando o sinalizador **_CRTDBG_MAP_ALLOC** é definido na versão de depuração de um aplicativo, a versão base das funções de heap é mapeada diretamente para suas versões de depuração. O sinalizador é usado em Crtdbg.h para fazer o mapeamento. Esse sinalizador só fica disponível quando o sinalizador [_DEBUG](../c-runtime-library/debug.md) é definido no aplicativo.  
  
 Para obter mais informações sobre como usar a versão de depuração em comparação com a versão base de uma função de heap, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).  
  
## <a name="see-also"></a>Consulte também  
 [Sinalizadores de controle](../c-runtime-library/control-flags.md)