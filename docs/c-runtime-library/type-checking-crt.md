---
title: "Verificação de tipo (CRT) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d18ae0818dd839bee0d93bd7194dadcc9abf6627
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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