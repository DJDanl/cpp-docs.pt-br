---
title: "Vantagens do assembly embutido | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "assembler [C++], vantagens"
  - "assembly embutido [C++], sobre assembly embutido"
  - "assembly embutido [C++], usando"
ms.assetid: 94364d97-faa7-4bdf-8473-570956986c51
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Vantagens do assembly embutido
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 Como o assembler embutido não requer etapas do assembly separado e link, é mais conveniente que um assembler separado.  O código do assembly embutido pode usar qualquer nome de variável ou de função C que está no escopo, o que é fácil de integração com código C do programa.  Como o código do assembly pode ser embutidos misturada com instruções de 2.0 C ou C\+\+, poderá realizar as tarefas que são incômodas ou impossíveis em 2.0 C ou C\+\+.  
  
 O assembly embutido incluem:  
  
-   Funções de gravação na linguagem assembly.  
  
-   Point\-in\-time otimizando seções velocidade\- críticos de código.  
  
-   Fazendo o acesso direto de hardware para drivers de dispositivo.  
  
-   Prólogo de escrita e código de epílogo para chamadas “despidos”.  
  
 O assembly embutido é uma ferramenta do objetivo especial.  Se você planeja mover um aplicativo em computadores diferentes, você provavelmente vai colocar o código computador específico em um módulo separado.  Como o assembler embutido não oferece suporte a todas as políticas de macro e de dados do Microsoft macro assembler \(MASM\), pode ser mais conveniente usar MASM para esses módulos.  
  
 **FINALIZAR Específico da Microsoft**  
  
## Consulte também  
 [Assembler embutido](../../assembler/inline/inline-assembler.md)