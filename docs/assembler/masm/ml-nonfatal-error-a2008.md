---
title: ML erro não fatal A2008 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: error-reference
f1_keywords:
- A2008
dev_langs:
- C++
helpviewer_keywords:
- A2008
ms.assetid: ca24157f-c88a-4678-ae06-3bc3cd956001
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 50f7329f698d23f875a29bc316067c39e8d1b8c1
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
ms.locfileid: "32055213"
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