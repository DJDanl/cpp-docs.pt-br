---
title: NMAKE Erro Fatal U1051 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: U1051
dev_langs: C++
helpviewer_keywords: U1051
ms.assetid: fede5cd5-dac3-47b7-b86d-e1acfb78699f
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 93c109bf723b3c4cf08e998a715fe8f6f33be466
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="nmake-fatal-error-u1051"></a>Erro fatal U1051 (NMAKE)
Memória insuficiente  
  
 NMAKE ficou sem memória, incluindo a memória virtual, pois o makefile era muito grande ou complexo.  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis  
  
1.  Libere espaço em disco.  
  
2.  Aumente o tamanho do arquivo de paginação do Windows NT ou o arquivo de permuta do Windows.  
  
3.  Se apenas parte do makefile estiver sendo usado, divida o makefile em arquivos separados ou use **! Se** para limitar a quantidade NMAKE deve processar as diretivas de pré-processamento. O **! Se** diretivas incluem **! Se**, `!IFDEF`, **! IFNDEF**, **! ELSE IF**, **! ELSE** `IFDEF`, e **! ELSE** `IFNDEF`.