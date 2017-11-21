---
title: Uso de pilha | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 383f0072-0438-489f-8829-cca89582408c
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: c7a74abff7a2971fe66fa2df878078ac95f58fe8
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="stack-usage"></a>Uso da pilha
Toda a memória além do endereço atual do RSP é considerada volátil: O sistema operacional ou um depurador pode substituir essa memória durante uma sessão de depuração de usuário ou um manipulador de interrupção. Assim, RSP sempre deve ser definido antes de tentar ler ou gravar valores para um quadro de pilha.  
  
 Esta seção discute a alocação de espaço de pilha para variáveis locais e o **alloca** intrínseco.  
  
-   [Alocação da pilha](../build/stack-allocation.md)  
  
-   [Construção da área de pilha de parâmetros dinâmicos](../build/dynamic-parameter-stack-area-construction.md)  
  
-   [Tipos de função](../build/function-types.md)  
  
-   [Alinhamento de malloc](../build/malloc-alignment.md)  
  
-   [alloca](../build/alloca.md)  
  
## <a name="see-also"></a>Consulte também  
 [Convenções de software x64](../build/x64-software-conventions.md)