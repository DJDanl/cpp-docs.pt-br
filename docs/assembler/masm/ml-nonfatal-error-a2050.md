---
title: ML erro não fatal A2050 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: error-reference
f1_keywords:
- A2050
dev_langs:
- C++
helpviewer_keywords:
- A2050
ms.assetid: 16f3a58f-4bde-48f1-b0e3-2ed9612780a5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 159ed131c13166435114234b3b16a82cd4d41d1f
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
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