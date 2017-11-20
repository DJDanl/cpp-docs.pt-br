---
title: "Códigos de saída de NMAKE | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- NMAKE program, exit codes
- exit codes
ms.assetid: 75f6913c-1da5-4572-a2d3-8a4e058bed15
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: bb5548d74544ba4277fa1d901ffa9f0b91b83f2e
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="exit-codes-from-nmake"></a>Códigos de saída de NMAKE
NMAKE retorna os seguintes códigos de saída:  
  
|Código|Significado|  
|----------|-------------|  
|0|Nenhum erro (possivelmente um aviso)|  
|1|Compilação incompleta (emitida apenas quando /K é usado)|  
|2|Erro de programa, possivelmente devido a um dos seguintes:|  
||-Um erro de sintaxe no makefile|  
||-Um código de erro ou de saída de um comando|  
||-Uma interrupção pelo usuário|  
|4|Erro do sistema, memória insuficiente|  
|255|O destino não é atualizado (emitido apenas quando /Q é usado)|  
  
## <a name="see-also"></a>Consulte também  
 [Executando NMAKE](../build/running-nmake.md)