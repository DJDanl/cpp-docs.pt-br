---
title: _FREEENTRY, _USEDENTRY | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- USEDENTRY
- _USEDENTRY
- _FREEENTRY
- FREEENTRY
dev_langs:
- C++
helpviewer_keywords:
- _USEDENTRY constant
- _FREEENTRY constant
- FREEENTRY constant
- USEDENTRY constant
ms.assetid: 26f658e6-6846-4a4e-9984-262cfe392770
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 60487a502fd304be39f973659cb5fd3432ec7a1d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46096789"
---
# <a name="freeentry-usedentry"></a>_FREEENTRY, _USEDENTRY

## <a name="syntax"></a>Sintaxe

```
#include <malloc.h>
```

## <a name="remarks"></a>Comentários

Essas constantes representam valores atribuídos pelas rotinas `_heapwalk` ao elemento **_useflag** da estrutura **_HEAPINFO**. Eles indicam o status da entrada de heap.

## <a name="see-also"></a>Consulte também

[_heapwalk](../c-runtime-library/reference/heapwalk.md)<br/>
[Constantes globais](../c-runtime-library/global-constants.md)