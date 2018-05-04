---
title: Códigos de saída de NMAKE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- NMAKE program, exit codes
- exit codes
ms.assetid: 75f6913c-1da5-4572-a2d3-8a4e058bed15
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4e71442e1e36dbd69afa65051cbf08f403bf8b31
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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