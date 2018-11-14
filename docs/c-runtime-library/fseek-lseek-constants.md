---
title: Constantes fseek, _lseek
ms.date: 11/04/2016
f1_keywords:
- SEEK_END
- SEEK_SET
- SEEK_CUR
helpviewer_keywords:
- SEEK_SET constant
- SEEK_END constant
- SEEK_CUR constant
ms.assetid: 9deeb13e-5aa3-4c33-80d8-721c80a4de9d
ms.openlocfilehash: 67599ced3ee775d9e6d702a9fb9e66e0580240e4
ms.sourcegitcommit: afd6fac7c519dbc47a4befaece14a919d4e0a8a2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2018
ms.locfileid: "51519146"
---
# <a name="fseek-lseek-constants"></a>Constantes fseek, _lseek

## <a name="syntax"></a>Sintaxe

```

#include <stdio.h>
```

## <a name="remarks"></a>Comentários

O argumento *origem* especifica a posição inicial e pode ser uma das seguintes constantes de manifesto:

|Constante|Significado|
|--------------|-------------|
|`SEEK_END`|Final do arquivo|
|`SEEK_CUR`|Posição atual do ponteiro de arquivo|
|`SEEK_SET`|Início do arquivo|

## <a name="see-also"></a>Consulte também

[fseek, _fseeki64](../c-runtime-library/reference/fseek-fseeki64.md)<br/>
[_lseek, _lseeki64](../c-runtime-library/reference/lseek-lseeki64.md)<br/>
[Constantes globais](../c-runtime-library/global-constants.md)