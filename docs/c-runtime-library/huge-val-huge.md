---
title: HUGE_VAL, _HUGE | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 92a05e22265ff5cda0974055a7bff01b88768e52

---
# <a name="hugeval-huge"></a>HUGE_VAL, _HUGE
## <a name="syntax"></a>Sintaxe  
  
```  
  
#include <math.h>  
  
```  
  
## <a name="remarks"></a>Comentários  
 `HUGE_VAL` é o maior valor duplo representável. Esse valor é retornado por muitas funções matemáticas do tempo de execução quando ocorre um erro. Para algumas funções, é retornado –`HUGE_VAL`. `HUGE_VAL` é definido como `_HUGE`, mas as funções matemáticas do tempo de execução retornam `HUGE_VAL`. Você também deve usar `HUGE_VAL` em seu código para manter a consistência.  
  
## <a name="see-also"></a>Consulte também  
 [Constantes globais](../c-runtime-library/global-constants.md)


<!--HONumber=Feb17_HO4-->


