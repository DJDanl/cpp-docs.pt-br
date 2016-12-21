---
title: "Classe de Cont&#234;iner::erase | Microsoft Docs"
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
  - "Método erase"
ms.assetid: abc091c5-5a80-4bd8-93a8-a2d9bde2efec
caps.latest.revision: 8
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe de Cont&#234;iner::erase
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  Este tópico está na documentação do Visual C\+\+ como um exemplo nonfunctional contêineres usados na biblioteca padrão C\+\+.  Para obter mais informações, consulte [Contêineres STL](../standard-library/stl-containers.md).  
  
 Apaga um elemento.  
  
## Sintaxe  
  
```  
  
      iterator erase(  
   iterator _Where   
);  
iterator erase(  
   iterator _First,  
   iterator _Last   
);  
```  
  
## Comentários  
 A primeira função de membro remove o elemento de sequência controlada apontada por \_*Where***.** A segunda função de membro remove os elementos de sequência controlada no intervalo \[`_First`, `_Last`\).  Ambos retornam um iterador que designa o primeiro elemento que permanece além de todos os elementos removidos, ou [extremidade](../Topic/Container%20Class::end.md) se tal elemento existe.  
  
 As funções de membro lança uma exceção apenas se uma operação de cópia gerencie uma exceção.  
  
## Consulte também  
 [Exemplo de Classe de Contêiner](../Topic/Sample%20Container%20Class.md)