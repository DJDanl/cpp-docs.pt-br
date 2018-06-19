---
title: Constantes setvbuf | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0d4292ae29602b5890a167a3e2c29e460d65373f
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32407958"
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