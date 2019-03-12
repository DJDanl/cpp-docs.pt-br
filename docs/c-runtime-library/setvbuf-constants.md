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
ms.openlocfilehash: 28c9debf7e51d06cb9a625bb0a52d578ce3142c6
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57742647"
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
|`_IOFBF`|Buffer cheio: o buffer especificado na chamada para `setvbuf` está sendo usado e seu tamanho é o especificado na chamada `setvbuf`. Se o ponteiro do buffer for **NULO**, é usado o buffer de tamanho especificado alocado automaticamente.|
|`_IOLBF`|Mesmo que `_IOFBF`.|
|`_IONBF`|Nenhum buffer é usado, independentemente de argumentos na chamada para `setvbuf`.|

## <a name="see-also"></a>Consulte também

[setbuf](../c-runtime-library/reference/setbuf.md)<br/>
[Constantes globais](../c-runtime-library/global-constants.md)
