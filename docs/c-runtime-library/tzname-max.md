---
title: TZNAME_MAX | Microsoft Docs
ms.custom: ''
ms.date: 10/22/2018
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- TZNAME_MAX
dev_langs:
- C++
helpviewer_keywords:
- TZNAME_MAX constant
ms.assetid: e2286cb8-751d-4557-9650-5c4b98a8f7be
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dc44ff3178493132c1b8d5dc168cee6be4c5bc56
ms.sourcegitcommit: c045c3a7e9f2c7e3e0de5b7f9513e41d8b6d19b2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2018
ms.locfileid: "49990146"
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
