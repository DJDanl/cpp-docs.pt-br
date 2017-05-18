---
title: Constantes setvbuf | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- _IOFBF
- _IONBF
- _IOLBF
dev_langs:
- C++
helpviewer_keywords:
- _IOFBF constant
- IOFBF constant
- IONBF constant
- _IOLBF constant
- IOLBF constant
- _IONBF constant
ms.assetid: a6ec4dd5-1f24-498c-871a-e874cd28d33c
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 17b914a593122bb11d62af2ba9c2ba9e32e6bb7c
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

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
