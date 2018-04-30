---
title: ML erro não fatal A2133 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: error-reference
f1_keywords:
- A2133
dev_langs:
- C++
helpviewer_keywords:
- A2133
ms.assetid: 5ba50911-22c8-43b7-90e2-946fc612e05f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f240ed6f2e8330017e56334dfcc41be478537c7b
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
---
# <a name="ml-nonfatal-error-a2133"></a>Erro não fatal A2133 (ML)
**Registre o valor substituído por INVOKE**  
  
 Um registro foi passado como um argumento para um procedimento, mas o código gerado pelo [INVOKE](../../assembler/masm/invoke.md) passar outros argumentos destruído o conteúdo do registro.  
  
 Registra as AX, AL, AH, EAX, DX, DL, DH e EDX pode ser usadas pelo assembler para executar a conversão de dados.  
  
 Use um registro diferente.  
  
## <a name="see-also"></a>Consulte também  
 [Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)