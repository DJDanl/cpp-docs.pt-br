---
title: "Códigos de saída de NMAKE | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- NMAKE program, exit codes
- exit codes
ms.assetid: 75f6913c-1da5-4572-a2d3-8a4e058bed15
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 13cbe4806d8b3960cbf80df41c7cce6e7657ba7e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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