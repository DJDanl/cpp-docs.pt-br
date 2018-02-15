---
title: "ML erro não fatal A2050 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- A2050
dev_langs:
- C++
helpviewer_keywords:
- A2050
ms.assetid: 16f3a58f-4bde-48f1-b0e3-2ed9612780a5
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 887a18ee274b3e09624a07e214f235333e2a9665
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="ml-nonfatal-error-a2050"></a>Erro não fatal A2050 (ML)
**real ou número de BCD não permitido**  
  
 Um número (real) de ponto flutuante ou constante binary coded decimal (BCD) foi usada uma diferente de como um inicializador de dados.  
  
 Um dos procedimentos a seguir ocorreu:  
  
-   Um número real ou uma BCD foi usado em uma expressão.  
  
-   Um número real foi usado para inicializar uma diretiva que [DWORD](../../assembler/masm/dword.md), [QWORD](../../assembler/masm/qword.md), ou [TBYTE](../../assembler/masm/tbyte.md).  
  
-   Um BCD foi usado para inicializar uma diretiva que `TBYTE`.  
  
## <a name="see-also"></a>Consulte também  
 [Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)