---
title: "/STACK | Microsoft Docs"
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
  - "/stack"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção /STACK (editbin)"
  - "opção editbin STACK"
  - "opção editbin -STACK"
  - "stack, definindo tamanho"
ms.assetid: a39bcff0-c945-4355-80cc-8e4f24a5f142
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /STACK
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/STACK:reserve[,commit]  
```  
  
## Comentários  
 Essa opção define o tamanho da pilha em bytes e os argumentos de executadas em notação decimal do ou do C \- idioma.  A opção \/STACK só se aplica a um arquivo executável.  
  
 O argumento *de reserva* especifica a alocação de pilha total na memória virtual.  EDITBIN acima arredonda o valor especificado para o mais próximo de 4 bytes.  
  
 O argumento opcional de `commit` está sujeito a interpretação pelo sistema operacional.  No Windows NT, Windows 95, e o Windows 98, `commit` especificam a quantidade de memória física para alocar em cada vez.  O espaço confirmada as causas de memória virtual a ser reservada no arquivo de paginação.  Um valor mais alto de `commit` economiza tempo em que o aplicativo precisar de mais espaço mas aumenta a pilha os requisitos e possivelmente o tempo de inicialização de memória.  
  
## Consulte também  
 [Opções EDITBIN](../../build/reference/editbin-options.md)