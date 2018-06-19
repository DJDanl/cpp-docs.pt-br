---
title: NMAKE Erro Fatal U1051 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- U1051
dev_langs:
- C++
helpviewer_keywords:
- U1051
ms.assetid: fede5cd5-dac3-47b7-b86d-e1acfb78699f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 570c7e5d8e6e8250a67e4f032ac26b04388cfd00
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33317408"
---
# <a name="nmake-fatal-error-u1051"></a>Erro fatal U1051 (NMAKE)
Memória insuficiente  
  
 NMAKE ficou sem memória, incluindo a memória virtual, pois o makefile era muito grande ou complexo.  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis  
  
1.  Libere espaço em disco.  
  
2.  Aumente o tamanho do arquivo de paginação do Windows NT ou o arquivo de permuta do Windows.  
  
3.  Se apenas parte do makefile estiver sendo usado, divida o makefile em arquivos separados ou use **! Se** para limitar a quantidade NMAKE deve processar as diretivas de pré-processamento. O **! Se** diretivas incluem **! Se**, `!IFDEF`, **! IFNDEF**, **! ELSE IF**, **! ELSE** `IFDEF`, e **! ELSE** `IFNDEF`.