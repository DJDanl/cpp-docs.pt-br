---
title: "Usando uma biblioteca de modelo | Microsoft Docs"
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
  - "bibliotecas de modelo"
ms.assetid: 5e80ec6e-a61c-41ce-b34b-9a6252c46265
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando uma biblioteca de modelo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um modelo é um pouco como uma macro.  Como com uma macro, chamar um modelo faz com que expande \(com a substituição de parâmetro apropriado\) que você escreveu.  Em o entanto, um modelo vai mais do que este permitir a criação de novas classes baseadas em tipos que você passar como parâmetros.  Essas formas com segurança do novo implementar das classes de executar a operação expressa no código do modelo.  
  
 As bibliotecas de modelo como ATL diferem das bibliotecas de classe tradicionais C\+\+ que normalmente são fornecidos apenas como código\-fonte \(ou como código\-fonte com um pouco, tempo de execução de suporte\) e não são inerentemente hierárquicos ou necessariamente sobre a natureza.  Em vez de derivando de uma classe para obter a funcionalidade você desejar, você cria uma classe de um modelo.  
  
## Consulte também  
 [Introdução a ATL](../Topic/Introduction%20to%20ATL.md)