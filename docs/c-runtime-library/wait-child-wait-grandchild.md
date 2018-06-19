---
title: _WAIT_CHILD, _WAIT_GRANDCHILD | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- _WAIT_GRANDCHILD
- WAIT_CHILD
- WAIT_GRANDCHILD
- _WAIT_CHILD
dev_langs:
- C++
helpviewer_keywords:
- WAIT_CHILD constant
- WAIT_GRANDCHILD constant
- _WAIT_CHILD constant
- _WAIT_GRANDCHILD constant
ms.assetid: 7acd96fa-d118-4339-bb00-e5afaf286945
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 84e0f195bebd43ced767f05a7c6073a6d6e9db61
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32408013"
---
# <a name="waitchild-waitgrandchild"></a>_WAIT_CHILD, _WAIT_GRANDCHILD
## <a name="syntax"></a>Sintaxe  
  
```  
  
#include <process.h>  
  
```  
  
## <a name="remarks"></a>Comentários  
 A função `_cwait` pode ser usada por qualquer processo para aguardar algum outro processo (se a ID do processo for conhecida). O argumento de ação pode ser um dos seguintes valores:  
  
|Constante|Significado|  
|--------------|-------------|  
|`_WAIT_CHILD`|O processo de chamada aguarda até que o novo processo especificado seja encerrado.|  
|`_WAIT_GRANDCHILD`|O processo de chamada aguarda até que o novo processo especificado e todos os processos criados pelo novo processo sejam encerrados.|  
  
## <a name="see-also"></a>Consulte também  
 [_cwait](../c-runtime-library/reference/cwait.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)