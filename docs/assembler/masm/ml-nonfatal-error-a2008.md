---
title: "ML erro não fatal A2008 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: A2008
dev_langs: C++
helpviewer_keywords: A2008
ms.assetid: ca24157f-c88a-4678-ae06-3bc3cd956001
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a268fd3f82b96698d8e200486c2091cabfad95ec
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ml-nonfatal-error-a2008"></a>Erro não fatal A2008 (ML)
**Erro de sintaxe:**  
  
 Um token no local atual causou um erro de sintaxe.  
  
 Pode ter ocorrido um dos seguintes:  
  
-   Um prefixo dot foi adicionado ao ou omitido de uma diretiva.  
  
-   Uma palavra reservada (como **C** ou **tamanho**) foi usado como um identificador.  
  
-   Uma instrução que não estava disponível com a seleção atual do processador ou coprocessador foi usada.  
  
-   Um operador de tempo de execução de comparação (como `==`) foi usado em uma instrução condicional assembly em vez de um operador relacional (como [EQ](../../assembler/masm/operator-eq.md)).  
  
-   Uma instrução ou uma diretiva recebeu poucos operandos.  
  
-   Uma diretiva obsoleta foi usada.  
  
## <a name="see-also"></a>Consulte também  
 [Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)