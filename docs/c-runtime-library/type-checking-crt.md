---
title: "Verificação de tipo (CRT) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- c.types
dev_langs:
- C++
helpviewer_keywords:
- checking type
- variable argument functions
- type checking
ms.assetid: 1ba7590b-d1c0-4636-b6a0-e231395abdad
caps.latest.revision: 7
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
ms.openlocfilehash: afe2d7b1fe00160cb8833c356e323b804dc7cfc7
ms.lasthandoff: 02/25/2017

---
# <a name="type-checking-crt"></a>Verificação de tipo (CRT)
O compilador executa verificação de tipo limitada em funções que podem pegar um número variável de argumentos, como segue:  
  
|Chamada de função|Argumentos com tipo verificado|  
|-------------------|-----------------------------|  
|`_cprintf_s`, `_cscanf_s`, `printf_s`, `scanf_s`|Primeiro argumento (cadeia de caracteres de formato)|  
|`fprintf_s`, `fscanf_s`, `sprintf_s`, `sscanf_s`|Dois primeiros argumentos (arquivo ou buffer e cadeia de caracteres de formato)|  
|`_snprintf_s`|Três primeiros argumentos (arquivo ou buffer, contagem e cadeia de caracteres de formato)|  
|`_open`|Dois primeiros argumentos (caminho e sinalizador `_open`)|  
|`_sopen_s`|Três primeiros argumentos (caminho, sinalizador `_open` e modo de compartilhamento)|  
|`_execl`, `_execle`, `_execlp`, `_execlpe`|Dois primeiros argumentos (caminho e ponteiro do primeiro argumento)|  
|`_spawnl`, `_spawnle`, `_spawnlp`, `_spawnlpe`|Três primeiros argumentos (sinalização do modo, caminho e ponteiro do primeiro argumento)|  
  
 O compilador executa a mesma verificação de tipo limitada nos equivalentes de caractere largo dessas funções.  
  
## <a name="see-also"></a>Consulte também  
 [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)
