---
title: "Especificador de classe de armazenamento est&#225;tico | Microsoft Docs"
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
helpviewer_keywords: 
  - "especificadores de classe de armazenamento estático"
  - "variáveis estáticas, especificador"
  - "classes de armazenamento, estático"
ms.assetid: 9bce361e-919b-46b9-8148-40d7ab0eb024
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Especificador de classe de armazenamento est&#225;tico
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma variável declarada no nível interno com o especificador de classe de armazenamento **static** tem um tempo de vida global, mas pode ser visto somente dentro do bloco em que é declarado.  Para cadeias de caracteres constantes, usar **static** é útil porque reduz a sobrecarga de inicializações frequentes nas funções chamadas com frequência.  
  
## Comentários  
 Se você não inicializar explicitamente uma variável **static**, ela será inicializada como 0 por padrão.  Dentro de uma função, **static** faz com que o armazenamento seja alocado e sirva como uma definição.  As variáveis estáticas internas fornecem armazenamento particular e permanente que só pode ser visto por uma única função.  
  
## Consulte também  
 [Estático](../misc/static-cpp.md)