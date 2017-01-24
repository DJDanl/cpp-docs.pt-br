---
title: "Preciso derivar novas classes de CObject? | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CObject"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CObject, quando usar"
  - "classes derivadas, de CObject"
ms.assetid: 26021031-feaf-424c-80d1-9547c4409d6a
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Preciso derivar novas classes de CObject?
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Contrário, você não.  
  
 Derivar uma classe de [CObject](../Topic/CObject%20Class.md) quando você precisa das instalações que fornece, como a serialização ou o creatability dinâmico.  Muitas classes de dados precisam ser serializados em arquivos, o que geralmente é uma boa ideia derivá\-los de `CObject`.  Para obter um exemplo de uma classe derivada de `CObject`, consulte [Exemplo de garrancho](../top/visual-cpp-samples.md).  
  
## Consulte também  
 [Classe CObject: perguntas frequentes](../mfc/cobject-class-frequently-asked-questions.md)