---
title: "Transla&#231;&#227;o: diagn&#243;stico | Microsoft Docs"
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
  - "C"
ms.assetid: 3730ca7c-0147-452d-bd4a-6a1e97e9793e
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Transla&#231;&#227;o: diagn&#243;stico
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**ANSI 2.1.1.3** Como um diagnóstico é identificado  
  
 O Microsoft C gera mensagens de erro no formato:  
  
```  
  
filename( line-number ) : diagnostic Cnumber message  
```  
  
 onde *filename* é o nome do arquivo de origem em que o erro foi encontrado; *line\-number* é o número da linha em que o compilador detectou o erro; `diagnostic` é um "erro" ou um "aviso"; `number` é um número exclusivo de quatro dígitos \(precedido de **C**, conforme observado na sintaxe\) que identifica o erro ou o aviso; `message` é uma mensagem explicativa.  
  
## Consulte também  
 [Comportamento definido por implementação](../c-language/implementation-defined-behavior.md)