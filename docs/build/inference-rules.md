---
title: "Regras de infer&#234;ncia | Microsoft Docs"
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
  - "regras de inferência em NMAKE"
  - "programa NMAKE, regras de inferência"
  - "regras, inferência"
ms.assetid: caff320f-fb07-4eea-80c3-a6a2133a8492
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Regras de infer&#234;ncia
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Comandos da fonte das regras de inferência atualizar destinos e inferir dependentes para destinos.  As extensões em uma regra de inferência correspondem a um único destino e dependente que têm o mesmo nome de base.  As regras de inferência são definidos pelo usuário ou predefinidas; as regras predefinidas podem ser redefinido.  
  
 Se uma dependência expirado não tem nenhum comando, e se [.SUFFIXES](../build/dot-directives.md) contém a extensão dependentes, NMAKE usa uma regra cujas extensões correspondem ao destino e um arquivo existente no escopo atual ou no diretório especificado.  Se mais de uma regra corresponde arquivos existentes, a lista de **.SUFFIXES** determina qual usar; a prioridade da lista decrescente da esquerda para a direita.  Se um arquivo dependente não existir e não estiver listado como um destino em outro bloco de descrição, uma regra de inferência é possível criar o dependente ausente de outro arquivo com o mesmo nome de base.  Se o destino de um bloco de descrição não tem nenhum dependente ou comando, uma regra de inferência pode atualizar o destino.  As regras de inferência podem criar um destino de linha de comando mesmo se nenhum pacote de existir descrição.  NMAKE pode invocar uma regra para um dependente inferido mesmo se um dependente explícito for especificado.  
  
## Que você deseja saber mais?  
 [Definindo uma regra](../build/defining-a-rule.md)  
  
 [Regras em grupo](../Topic/Batch-Mode%20Rules.md)  
  
 [Regras predefinidas](../build/predefined-rules.md)  
  
 [Dependentes deduzidos e regras](../build/inferred-dependents-and-rules.md)  
  
 [Precedência em regras de inferência](../build/precedence-in-inference-rules.md)  
  
## Consulte também  
 [Referência de NMAKE](../build/nmake-reference.md)