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
ms.openlocfilehash: 8936789f4e3c9349e9d79616c8506c044dc79f70
ms.sourcegitcommit: a1fad0a266b20b313364a74b16c9ac45d089b1e9
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/11/2019
ms.locfileid: "54220394"
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
