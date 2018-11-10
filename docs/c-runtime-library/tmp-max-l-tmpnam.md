---
title: TMP_MAX, L_tmpnam
ms.date: 11/04/2016
f1_keywords:
- TMP_MAX
- L_tmpnam
helpviewer_keywords:
- temporary files, length
- L_tmpnam constant
- TMP_MAX constant
ms.assetid: ab19fd0c-b5b7-49f7-b23d-da9dfbcf0c1f
ms.openlocfilehash: 21b56a05b60067e04d0d3864a135ed5eccacfddc
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50609710"
---
# <a name="tmpmax-ltmpnam"></a>TMP_MAX, L_tmpnam

## <a name="syntax"></a>Sintaxe

```
#include <stdio.h>
```

## <a name="remarks"></a>Comentários

`TMP_MAX` é o número máximo de nomes de arquivo exclusivos que a função `tmpnam` pode gerar. `L_tmpnam` é o comprimento dos nomes de arquivo temporários gerados por `tmpnam`.

## <a name="see-also"></a>Consulte também

[Constantes globais](../c-runtime-library/global-constants.md)