---
title: _CRTDBG_MAP_ALLOC
ms.date: 11/04/2016
f1_keywords:
- CRTDBG_MAP_ALLOC
- _CRTDBG_MAP_ALLOC
helpviewer_keywords:
- _CRTDBG_MAP_ALLOC macro
- memory allocation, in debug builds
- CRTDBG_MAP_ALLOC macro
ms.assetid: 435242b8-caea-4063-b765-4a608200312b
ms.openlocfilehash: 8bcb0f5ea26218b74034eb0a41199a1104ba944d
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57739782"
---
# <a name="crtdbgmapalloc"></a>_CRTDBG_MAP_ALLOC

Quando o sinalizador **_CRTDBG_MAP_ALLOC** é definido na versão de depuração de um aplicativo, a versão base das funções de heap é mapeada diretamente para suas versões de depuração. O sinalizador é usado em Crtdbg.h para fazer o mapeamento. Esse sinalizador só fica disponível quando o sinalizador [_DEBUG](../c-runtime-library/debug.md) é definido no aplicativo.

Para obter mais informações sobre como usar a versão de depuração em comparação com a versão base de uma função de heap, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).

## <a name="see-also"></a>Consulte também

[Sinalizadores de controle](../c-runtime-library/control-flags.md)
