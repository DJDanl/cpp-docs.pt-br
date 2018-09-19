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
ms.openlocfilehash: 0c48095acceefa4bb4852dab18d35284492e7ba0
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46069387"
---
# <a name="crtdbgmapalloc"></a>_CRTDBG_MAP_ALLOC

Quando o sinalizador **_CRTDBG_MAP_ALLOC** é definido na versão de depuração de um aplicativo, a versão base das funções de heap é mapeada diretamente para suas versões de depuração. O sinalizador é usado em Crtdbg.h para fazer o mapeamento. Esse sinalizador só fica disponível quando o sinalizador [_DEBUG](../c-runtime-library/debug.md) é definido no aplicativo.

Para obter mais informações sobre como usar a versão de depuração em comparação com a versão base de uma função de heap, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).

## <a name="see-also"></a>Consulte também

[Sinalizadores de controle](../c-runtime-library/control-flags.md)