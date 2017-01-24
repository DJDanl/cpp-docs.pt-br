---
title: "/HEAP | Microsoft Docs"
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
  - "/heap"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "alocação de heap, definindo o tamanho de heap"
  - "opção editbin HEAP"
  - "opção editbin -HEAP"
  - "Opção /HEAP (editbin)"
ms.assetid: 6ce759b5-75b7-44ff-a5fd-3a83a0ba9a48
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /HEAP
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define o tamanho do heap em bytes.  Essa opção se aplica apenas aos arquivos executáveis.  
  
```  
  
/HEAP:  
reserve[,commit]  
  
```  
  
## Comentários  
 O argumento de `reserve` especifica a alocação inicial total de heap na memória virtual.  Por padrão, o tamanho do heap é 1 MB.  [Referência de EDITBIN](../Topic/EDITBIN%20Reference.md) acima arredonda o valor especificado para o múltiplo mais próximo de 4 bytes.  
  
 O argumento opcional de `commit` está sujeito a interpretação pelo sistema operacional.  Em um sistema operacional Windows, especifica a quantidade inicial de memória física para atribuir, e a quantidade de memória adicional para alocar quando o heap deve ser expandido.  O espaço confirmada as causas de memória virtual a ser reservada no arquivo de paginação.  Um valor mais alto de `commit` permite que o sistema aloca memória menor frequência quando o aplicativo precisar de mais espaço mas aumenta de heap os requisitos de memória e possivelmente a duração de inicialização do aplicativo.  O valor de `commit` deve ser menor ou igual ao valor de `reserve` .  
  
 Especificar os valores de `reserve` e de `commit` em notação hexadecimal ou decimal octal do ou do C \- idioma.  Por exemplo, um valor de 1 MB pode ser especificado como 1048576 em decimal, ou como 0x100000 em hexadecimal, ou como 04000000 em octal.  
  
## Consulte também  
 [Opções EDITBIN](../../build/reference/editbin-options.md)