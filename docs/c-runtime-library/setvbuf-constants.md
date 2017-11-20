---
title: Constantes setvbuf | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- _IOFBF
- _IONBF
- _IOLBF
dev_langs: C++
helpviewer_keywords:
- _IOFBF constant
- IOFBF constant
- IONBF constant
- _IOLBF constant
- IOLBF constant
- _IONBF constant
ms.assetid: a6ec4dd5-1f24-498c-871a-e874cd28d33c
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 16a5a215657a6d447c43c7ba327ef0d5f31d4abb
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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
 [setbuf](../c-runtime-library/reference/setbuf.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)