---
title: "Depuração e listagens para Assembly embutido | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- source level debugger
- __asm keyword [C++], debugging
- inline assembly, listings
- bugs, __asm blocks
- debugging [C++], inline assembly code
- inline assembly, debugging
ms.assetid: 69266930-6f9a-433d-b704-f4f44e7b2583
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 532d76f5f7a51e6c84067b442e6469b83994db7d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="debugging-and-listings-for-inline-assembly"></a>Depuração e listagens para assembly embutido
## <a name="microsoft-specific"></a>Específico da Microsoft  
 Programas que contém o código de assembly embutido podem ser depurados com um depurador de nível de origem se você compilar com o [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md) opção.  
  
 No depurador, você pode definir pontos de interrupção nas linhas de C ou C++ e linguagem de assembly. Se você habilitar o assembly misto e modo de origem, você pode exibir a origem e o formulário desmontado do código de assembly.  
  
 Observe que colocar várias instruções ou instruções de linguagem do código-fonte em uma linha pode dificultar a depuração. No modo de origem, você pode usar o depurador para definir pontos de interrupção em uma única linha, mas não em instruções individuais na mesma linha. O mesmo princípio se aplica a um `__asm` bloco definida como uma macro de C, que se expande para uma única linha lógica.  
  
 Se você criar uma fonte de misto e assembly listando com o [/FAs](../../build/reference/fa-fa-listing-file.md) opção de compilador, a listagem contém formas de origem e o assembly de cada linha de linguagem de assembly. Macros não são expandidas nas listagens, mas eles são expandidos durante a compilação.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)