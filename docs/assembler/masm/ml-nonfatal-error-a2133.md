---
title: "ML erro não fatal A2133 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- A2133
dev_langs:
- C++
helpviewer_keywords:
- A2133
ms.assetid: 5ba50911-22c8-43b7-90e2-946fc612e05f
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: adc1929f14b5264717936f1a4aebb8dabd2e439d
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="ml-nonfatal-error-a2133"></a>Erro não fatal A2133 (ML)
**Registre o valor substituído por INVOKE**  
  
 Um registro foi passado como um argumento para um procedimento, mas o código gerado pelo [INVOKE](../../assembler/masm/invoke.md) passar outros argumentos destruído o conteúdo do registro.  
  
 Registra as AX, AL, AH, EAX, DX, DL, DH e EDX pode ser usadas pelo assembler para executar a conversão de dados.  
  
 Use um registro diferente.  
  
## <a name="see-also"></a>Consulte também  
 [Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)