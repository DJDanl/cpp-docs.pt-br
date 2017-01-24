---
title: "Compilador C4985 de aviso (n&#237;vel 4) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4985"
ms.assetid: 832f001c-afe7-403d-a8b4-02334724c79e
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4985 de aviso (n&#237;vel 4)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'nome do símbolo': atributos não está presente na declaração anterior.  
  
 As anotações de linguagem \(SAL\) de anotação do origem código na declaração do método atual ou definição diferem das anotações em uma declaração anterior. As anotações de SAL mesmo devem ser usadas na definição e declarações de um método.  
  
 O SAL fornece um conjunto de anotações que você pode usar para descrever como uma função usa seus parâmetros, as suposições faz sobre eles e as garantias faz em Concluir. As anotações são definidas no arquivo de cabeçalho sal.h.  
  
 Observe que as macros SAL não expandirá a menos que o projeto tem o [\/Analyze](../../build/reference/analyze-code-analysis.md) sinalizador especificado. Quando você especificar **\/analyze**, o compilador pode gerar C4985, mesmo que nenhum aviso ou erro apareceu sem **\/analyze**.  
  
### Para corrigir este erro  
  
1.  Use as anotações de SAL mesmo na definição de um método e todas as suas declarações.  
  
## Consulte também  
 [Anotações de SAL](../../c-runtime-library/sal-annotations.md)