---
title: _CRTDBG_MAP_ALLOC | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: a2b61b315baa337675147ded1232a943e82b24ec
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="crtdbgmapalloc"></a>_CRTDBG_MAP_ALLOC
Quando o sinalizador **_CRTDBG_MAP_ALLOC** é definido na versão de depuração de um aplicativo, a versão base das funções de heap é mapeada diretamente para suas versões de depuração. O sinalizador é usado em Crtdbg.h para fazer o mapeamento. Esse sinalizador só fica disponível quando o sinalizador [_DEBUG](../c-runtime-library/debug.md) é definido no aplicativo.  
  
 Para obter mais informações sobre como usar a versão de depuração em comparação com a versão base de uma função de heap, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).  
  
## <a name="see-also"></a>Consulte também  
 [Sinalizadores de controle](../c-runtime-library/control-flags.md)
