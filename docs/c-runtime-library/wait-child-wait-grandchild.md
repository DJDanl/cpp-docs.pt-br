---
title: _WAIT_CHILD, _WAIT_GRANDCHILD | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
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
ms.openlocfilehash: ce01fe017a3adaa1a66ccc1789ac6a3aa2c2c14a
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

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
