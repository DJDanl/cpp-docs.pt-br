---
title: NMAKE Erro Fatal U1051 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- U1051
dev_langs:
- C++
helpviewer_keywords:
- U1051
ms.assetid: fede5cd5-dac3-47b7-b86d-e1acfb78699f
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: ce96c9eedac8aaac9d138197f8323c6228f287e4
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="nmake-fatal-error-u1051"></a>Erro fatal U1051 (NMAKE)
memória insuficiente  
  
 NMAKE ficou sem memória, incluindo a memória virtual, pois o makefile era muito grande ou complexo.  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir, usando as seguintes soluções possíveis  
  
1.  Libere espaço em disco.  
  
2.  Aumente o tamanho do arquivo de paginação do Windows NT ou o arquivo de permuta do Windows.  
  
3.  Se apenas parte do makefile estiver sendo usado, divida o makefile em arquivos separados ou use **! Se** para limitar a quantidade NMAKE deve processar as diretivas de pré-processamento. The **! Se** incluem diretivas **! IF**, `!IFDEF`, **! IFNDEF**, **! ELSE IF**, **! ELSE** `IFDEF`, and **! ELSE** `IFNDEF`.
