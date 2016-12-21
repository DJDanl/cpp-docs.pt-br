---
title: "/DYNAMICBASE | Microsoft Docs"
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
  - "/dynamicbase"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção /DYNAMICBASE (editbin)"
  - "opção editbin DYNAMICBASE"
  - "opção editbin -DYNAMICBASE"
ms.assetid: edb3df90-7b07-42fb-a94a-f5a4c1d325d6
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /DYNAMICBASE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica se uma imagem executável possa ter REBASE aleatória no tempo de carregamento usando randomização de layout de espaço de endereço \(ASLR\).  
  
## Sintaxe  
  
```  
  
/DYNAMICBASE[:NO]  
```  
  
## Comentários  
 Por padrão, o vinculador define o **\/DYNAMICBASE** opção.  
  
 Esta opção modifica o cabeçalho de uma imagem executável para indicar se o carregador pode rebase aleatoriamente a imagem no tempo de carregamento.  
  
 O ASLR é suportado no Windows Vista, Windows Server 2008, Windows 7, Windows 8 e Windows Server 2012.  
  
## Consulte também  
 [Opções EDITBIN](../../build/reference/editbin-options.md)   
 [defesas de segurança do Windows Software ISV](http://msdn.microsoft.com/library/bb430720.aspx)