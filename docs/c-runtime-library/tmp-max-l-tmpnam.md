---
title: TMP_MAX, L_tmpnam | Documentos do Microsoft
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- TMP_MAX
- L_tmpnam
dev_langs:
- C++
helpviewer_keywords:
- temporary files, length
- L_tmpnam constant
- TMP_MAX constant
ms.assetid: ab19fd0c-b5b7-49f7-b23d-da9dfbcf0c1f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: cee175eb7f12952dfe7e30ef79842ee03a96fbb1
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46019673"
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