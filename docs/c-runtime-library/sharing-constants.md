---
title: Compartilhando constantes | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- _SH_DENYNO
- _SH_DENYRD
- _SH_DENYRW
- _SH_DENYWR
- _SH_COMPAT
dev_langs:
- C++
helpviewer_keywords:
- _SH_DENYRW constant
- SH_DENYRD constant
- _SH_COMPAT constant
- _SH_DENYRD constant
- SH_DENYRW constant
- sharing constants
- SH_DENYNO constant
- _SH_DENYWR constant
- SH_DENYWR constant
- _SH_DENYNO constant
- SH_COMPAT constant
ms.assetid: 95fadc3a-55dc-473d-98b5-e8211900465d
caps.latest.revision: 8
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
translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: cc2c383ac3d163987cd63db2dbea2f7be8d3afeb
ms.lasthandoff: 02/25/2017

---
# <a name="sharing-constants"></a>Compartilhando constantes
Constantes para modos de compartilhamento de arquivos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
#include <share.h>  
  
```  
  
## <a name="remarks"></a>Comentários  
 O argumento *shflag* determina o modo de compartilhamento, que consiste em uma ou mais constantes de manifesto. Elas podem ser combinadas com os argumentos *oflag* (consulte [Constantes de arquivo](../c-runtime-library/file-constants.md)).  
  
 A tabela a seguir lista as constantes e seus significados:  
  
|Constante|Significado|  
|--------------|-------------|  
|`_SH_DENYRW`|Nega acesso de leitura e gravação a um arquivo|  
|`_SH_DENYWR`|Nega acesso de gravação a um arquivo|  
|`_SH_DENYRD`|Nega acesso de leitura a um arquivo|  
|`_SH_DENYNO`|Permite acesso de leitura e gravação|  
|`_SH_SECURE`|Define o modo seguro (leitura compartilhada, acesso de gravação exclusivo).|  
  
## <a name="see-also"></a>Consulte também  
 [_sopen, _wsopen](../c-runtime-library/reference/sopen-wsopen.md)   
 [_fsopen, _wfsopen](../c-runtime-library/reference/fsopen-wfsopen.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)
