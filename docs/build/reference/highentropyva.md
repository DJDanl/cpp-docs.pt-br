---
title: "/HIGHENTROPYVA | Microsoft Docs"
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
  - "/HIGHENTROPYVA"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "/HIGHENTROPYVA editbin - opção"
  - "HIGHENTROPYVA editbin - opção"
  - "-HIGHENTROPYVA editbin - opção"
ms.assetid: ef4b7c63-440d-40ca-b39d-edefb3217505
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /HIGHENTROPYVA
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica se a imagem executável suporta randomização de layout de espaço de endereço de 64 bits de alta entropia \(ASLR\).  
  
```  
  
/HIGHENTROPYVA[:NO]  
  
```  
  
## Comentários  
 Esta opção modifica o cabeçalho de um arquivo. dll ou .exe para indicar se a ASLR com endereços de 64 bits tem suporte.  Quando essa opção é definida em um arquivo executável e todos os módulos dos quais depende, um sistema operacional que dê suporte a ASLR de 64 bits pode rebasear os segmentos da imagem executável no tempo de carregamento usando endereços aleatórios em um espaço de endereço virtual de 64 bits.  Esse grande espaço de endereço torna mais difícil para um invasor adivinhar a localização de uma região de memória específica.  
  
 Por padrão, o vinculador define esta opção para imagens executáveis de 64 bits.  Para definir essa opção, o [\/DYNAMICBASE](../../build/reference/dynamicbase.md) opção também deve ser definida.  
  
## Consulte também  
 [Opções EDITBIN](../../build/reference/editbin-options.md)   
 [\/DYNAMICBASE](../../build/reference/dynamicbase.md)   
 [defesas de segurança do Windows Software ISV](http://msdn.microsoft.com/library/bb430720.aspx)