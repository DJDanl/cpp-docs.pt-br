---
title: Constantes setvbuf
ms.date: 11/04/2016
f1_keywords:
- _IOFBF
- _IONBF
- _IOLBF
helpviewer_keywords:
- _IOFBF constant
- IOFBF constant
- IONBF constant
- _IOLBF constant
- IOLBF constant
- _IONBF constant
ms.assetid: a6ec4dd5-1f24-498c-871a-e874cd28d33c
ms.openlocfilehash: 25c25741f54c1383a5bad9038b5b5d761dacdd89
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50458039"
---
# <a name="setvbuf-constants"></a>Constantes setvbuf

## <a name="syntax"></a>Sintaxe

```

#include <stdio.h>

```

## <a name="remarks"></a>Comentários

Essas constantes representam o tipo de buffer para `setvbuf`.

Os valores possíveis são fornecidos pelas constantes de manifesto a seguir:

|Constante|Significado|
|--------------|-------------|
|`_IOFBF`|Buffer cheio: O buffer especificado na chamada para `setvbuf` está sendo usado e seu tamanho é como especificado na chamada `setvbuf`. Se o ponteiro do buffer for **NULO**, é usado o buffer de tamanho especificado alocado automaticamente.|
|`_IOLBF`|Mesmo que `_IOFBF`.|
|`_IONBF`|Nenhum buffer é usado, independentemente de argumentos na chamada para `setvbuf`.|

## <a name="see-also"></a>Consulte também

[setbuf](../c-runtime-library/reference/setbuf.md)<br/>
[Constantes globais](../c-runtime-library/global-constants.md)