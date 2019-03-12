---
title: TZNAME_MAX
ms.date: 10/22/2018
f1_keywords:
- TZNAME_MAX
helpviewer_keywords:
- TZNAME_MAX constant
ms.assetid: e2286cb8-751d-4557-9650-5c4b98a8f7be
ms.openlocfilehash: 71e5becd39f49d86573483c5451a9a2415d84181
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57750930"
---
# <a name="tznamemax"></a>TZNAME_MAX

**Obsoleto**. O comprimento máximo de cadeia de caracteres permitido para uma variável de nome de fuso horário. Essa macro foi definida em \<limits.h> no Visual Studio 2012 e versões anteriores. Ela não está definida no Visual Studio 2013 e versões posteriores. Para obter o tamanho necessário para manter o nome do fuso horário atual, use [_get_tzname](../c-runtime-library/reference/get-tzname.md).

## <a name="syntax"></a>Sintaxe

```
#include <limits.h>
```

## <a name="see-also"></a>Consulte também

[Constantes ambientais](../c-runtime-library/environmental-constants.md)<br/>
[Constantes globais](../c-runtime-library/global-constants.md)<br/>
[_get_tzname](../c-runtime-library/reference/get-tzname.md)
