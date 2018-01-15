---
title: Vantagens do Assembly embutido | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- assembler [C++], advantages
- inline assembly [C++], about inline assembly
- inline assembly [C++], using
ms.assetid: 94364d97-faa7-4bdf-8473-570956986c51
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 60b8d458212cd2175f2460c1382ed7f8c2c269bb
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="advantages-of-inline-assembly"></a>Vantagens do assembly embutido
## <a name="microsoft-specific"></a>Específico da Microsoft  
 Como o assembler integrado não requer etapas de link e do assembly separado, é mais conveniente que um assembler separado. O código do assembly integrado pode usar qualquer nome de variável ou de função C que esteja no escopo. Portanto, ele é de fácil integração com código C do programa. Porque o código de assembly pode ser mesclado embutido com instruções C ou C++, ele pode realizar tarefas que são difícil ou impossível em C ou C++.  
  
 Os usos dos assembly embutido incluem:  
  
-   Gravando funções em linguagem de assembly.  
  
-   Otimizando o ponto crítico de velocidade de seções de código.  
  
-   Tornando o acesso direto de hardware para drivers de dispositivo.  
  
-   Escrevendo código de prólogo e epílogo para chamadas de "naked".  
  
 Assembly embutido é uma ferramenta de finalidade especial. Se você pretende transferir um aplicativo para computadores diferentes, você provavelmente desejará colocar código específico do computador em um módulo separado. Como o assembler embutido não oferece suporte a todos os da Microsoft Macro Assembler (MASM) diretivas de macro e os dados, você pode achar mais conveniente usar MASM para esses módulos.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Assembler embutido](../../assembler/inline/inline-assembler.md)