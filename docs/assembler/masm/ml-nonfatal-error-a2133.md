---
title: "ML erro não fatal A2133 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: A2133
dev_langs: C++
helpviewer_keywords: A2133
ms.assetid: 5ba50911-22c8-43b7-90e2-946fc612e05f
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 64619e6e14ce0268516c6c688c9a2bdeb5ea7a11
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ml-nonfatal-error-a2133"></a>Erro não fatal A2133 (ML)
**Registre o valor substituído por INVOKE**  
  
 Um registro foi passado como um argumento para um procedimento, mas o código gerado pelo [INVOKE](../../assembler/masm/invoke.md) passar outros argumentos destruído o conteúdo do registro.  
  
 Registra as AX, AL, AH, EAX, DX, DL, DH e EDX pode ser usadas pelo assembler para executar a conversão de dados.  
  
 Use um registro diferente.  
  
## <a name="see-also"></a>Consulte também  
 [Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)