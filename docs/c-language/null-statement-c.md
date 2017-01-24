---
title: "Instru&#231;&#227;o nula (C) | Microsoft Docs"
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
  - "expressões [C++], nulo"
  - "instrução nula"
  - "valores nulos, expressões"
  - "ponto e vírgula, instrução nula C"
ms.assetid: 72576ce6-26d0-4379-be65-fee522088790
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#227;o nula (C)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma "instrução nula" é uma instrução que contém apenas um ponto e vírgula; ela pode aparecer onde quer que uma instrução seja esperada.  Nada acontece quando uma instrução nula é executada.  A forma correta de codificar uma instrução nula é:  
  
## Sintaxe  
  
```  
  
;  
  
```  
  
## Comentários  
 Instruções como **do**, **for**, **if** e `while` requerem que uma instrução executável apareça como o corpo da instrução.  A instrução nula satisfaz o requisito de sintaxe nos casos que não precisam de um corpo de instrução substantivo.  
  
 Como acontece com qualquer outra instrução do C, você pode incluir um rótulo antes de uma instrução nula.  Para rotular um item que não é uma instrução, como a chave de fechamento de uma instrução composta, você pode rotular uma instrução nula e inseri\-la imediatamente antes do item para obter o mesmo efeito.  
  
 Este exemplo ilustra a instrução nula:  
  
```  
for ( i = 0; i < 10; line[i++] = 0 )  
     ;  
```  
  
 Nesse exemplo, a expressão de loop da instrução **for** `line[i++] = 0` inicializa os 10 primeiros elementos de `line` como 0.  O corpo da instrução é uma instrução nula, já que nenhuma instrução adicional é necessária.  
  
## Consulte também  
 [Instruções](../c-language/statements-c.md)