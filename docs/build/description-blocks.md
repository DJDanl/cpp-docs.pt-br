---
title: "Blocos de descri&#231;&#227;o | Microsoft Docs"
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
  - "blocos, descrição"
  - "blocos de descrição"
  - "programa NMAKE, blocos de descrição"
ms.assetid: 1321f228-d389-40ac-b0cd-4f6e9293602b
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Blocos de descri&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um bloco de descrição é uma linha de dependência opcionalmente seguida por um bloco de comandos:  
  
```  
targets... : dependents...  
    commands...  
```  
  
 Uma linha de dependência especifica um ou mais destinos e zero ou mais dependentes.  Um destino deve estar no início da linha.  Separar destinos os dependentes por dois\-pontos \(:\); espaços ou guias são permitidos.  Para dividir a linha, use uma barra invertida \(\\\) depois de um destino ou um dependente.  Se um destino não existir, tem um carimbo de data\/hora anterior de um dependente, ou é [pseudotarget](../build/pseudotargets.md), NMAKE executa comandos.  Se um dependente é um destino em outro lugar e não existe ou estiver expirado em relação aos seus próprios dependentes, NMAKE atualiza o dependente antes de atualizar a dependência atual.  
  
## Que você deseja saber mais?  
 [Destinos](../build/targets.md)  
  
 [Dependentes](../build/dependents.md)  
  
## Consulte também  
 [Referência de NMAKE](../build/nmake-reference.md)