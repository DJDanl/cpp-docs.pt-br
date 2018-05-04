---
title: Uso de pilha | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 383f0072-0438-489f-8829-cca89582408c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b6f711636089a6f2966002002220aac88cebe17a
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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