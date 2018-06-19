---
title: HUGE_VAL, _HUGE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
apiname:
- _HUGE
apilocation:
- msvcrt.dll
apitype: DLLExport
f1_keywords:
- _HUGE
- HUGE_VAL
dev_langs:
- C++
helpviewer_keywords:
- _HUGE constant
- HUGE_VAL constant
- double value
ms.assetid: 3f044b45-02cd-46b2-b1de-87fd0441dd6a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c2d763b8c5379223ddacb8077c463efa0b91acfa
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32390499"
---
# <a name="hugeval-huge"></a>HUGE_VAL, _HUGE
## <a name="syntax"></a>Sintaxe  
  
```  
  
#include <math.h>  
  
```  
  
## <a name="remarks"></a>Comentários  
 `HUGE_VAL` é o maior valor duplo representável. Esse valor é retornado por muitas funções matemáticas do tempo de execução quando ocorre um erro. Para algumas funções, é retornado -`HUGE_VAL`. `HUGE_VAL` é definido como `_HUGE`, mas as funções matemáticas do tempo de execução retornam `HUGE_VAL`. Você também deve usar `HUGE_VAL` em seu código para manter a consistência.  
  
## <a name="see-also"></a>Consulte também  
 [Constantes globais](../c-runtime-library/global-constants.md)